#!/usr/bin/env python3
"""
Agente RAG para consultas semánticas sobre los manuales del aula STEAM.
Carga el índice FAISS y consulta Ollama para respuestas en español.
"""

import os
import sys
import re
import argparse
import logging
from pathlib import Path

from langchain_community.embeddings import HuggingFaceEmbeddings
from langchain_community.vectorstores import FAISS
from openai import OpenAI
from dotenv import load_dotenv

# Configuración de logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)

# Cargar variables de entorno
load_dotenv()


def cargar_vectorstore(ruta_indice: str):
    """
    Carga el índice FAISS previamente guardado.
    
    Args:
        ruta_indice: Ruta del índice FAISS
        
    Returns:
        Vectorstore FAISS cargado
    """
    embeddings = HuggingFaceEmbeddings(
        model_name="sentence-transformers/all-MiniLM-L6-v2",
        model_kwargs={"device": "cpu"},
        encode_kwargs={"normalize_embeddings": True}
    )
    
    vectorstore = FAISS.load_local(
        ruta_indice,
        embeddings,
        allow_dangerous_deserialization=True
    )
    logger.info(f"Índice FAISS cargado desde {ruta_indice}")
    return vectorstore


def recuperar_contexto(vectorstore, pregunta: str, k: int = 5):
    """
    Recupera los k chunks más similares a la pregunta.
    
    Args:
        vectorstore: Vectorstore FAISS
        pregunta: Pregunta del usuario
        k: Número de chunks a recuperar
        
    Returns:
        Lista de documentos recuperados
    """
    documentos = vectorstore.similarity_search(pregunta, k=k)
    logger.info(f"Recuperados {len(documentos)} documentos relevantes")
    return documentos


def construir_prompt(pregunta: str, contexto: list) -> list[dict]:
    """
    Construye el prompt para el modelo de lenguaje.
    
    Args:
        pregunta: Pregunta del usuario
        contexto: Lista de documentos recuperados
        
    Returns:
        Lista de mensajes para chat
    """
    # Formatear contexto
    contexto_formateado = "\n\n---\n\n".join([
        f"Fuente: {doc.metadata.get('source', 'Desconocido')}\n{doc.page_content}"
        for doc in contexto
    ])
    
    messages = [
        {
            "role": "system",
            "content": """Eres un asistente experto del aula STEAM. Tu función es ayudar a estudiantes y docentes a usar correctamente los dispositivos y equipos del aula. Responde basándote ÚNICAMENTE en el contexto proporcionado a continuación. Si la respuesta no se encuentra en el contexto, responde: 'No tengo información suficiente en los manuales disponibles para responder esa pregunta. Te sugiero contactar a un asesor humano del aula STEAM para obtener ayuda.' Sé claro, preciso y útil. Usa un tono amable y educativo."""
        },
        {
            "role": "user",
            "content": f"Contexto:\n{contexto_formateado}\n\n---\n\nPregunta: {pregunta}"
        }
    ]
    
    return messages


def consultar_ollama(messages: list[dict], model: str, base_url: str) -> str:
    """
    Consulta el modelo Ollama vía API compatible con OpenAI.
    
    Args:
        messages: Lista de mensajes para chat
        model: Nombre del modelo Ollama
        base_url: URL base de la API Ollama
        
    Returns:
        Respuesta generada por el modelo
    """
    # Sanitizar URL: eliminar trailing colon y normalizar
    base_url = base_url.rstrip('/:')
    if not base_url.endswith('/v1'):
        base_url = base_url + '/v1'
    
    logger.info(f"Conectando a Ollama: {base_url} modelo={model}")
    
    client = OpenAI(
        base_url=base_url,
        api_key=os.getenv("RAG_API_KEY", "ollama-local")
    )
    
    extra_kwargs = {}
    try:
        extra_kwargs["extra_body"] = {
            "enable_thinking": False,
            "reasoning_effort": 0
        }
    except Exception:
        pass
    
    response = client.chat.completions.create(
        model=model,
        messages=messages,
        temperature=0.1,
        max_tokens=1024,
        **extra_kwargs
    )
    
    msg = response.choices[0].message
    content = msg.content
    
    # Si content viene vacío pero hay reasoning, extraer la respuesta del razonamiento
    if (not content or content.strip() == "") and hasattr(msg, 'reasoning') and msg.reasoning:
        reasoning = msg.reasoning
        logger.info("Content vacío, extrayendo respuesta desde reasoning...")
        parsed = _extraer_respuesta_de_reasoning(reasoning)
        if parsed:
            return parsed
        # Fallback: devolver el razonamiento completo como diagnóstico
        logger.warning("No se pudo extraer respuesta del reasoning")
        return reasoning
    
    # Manejar respuesta vacía sin reasoning
    if not content or content.strip() == "":
        logger.warning("Ollama devolvió respuesta vacía (sin reasoning)")
        return ("El modelo devolvió una respuesta vacía. "
                "Esto puede ocurrir si el modelo no está correctamente descargado "
                "o si el prompt supera el contexto máximo del modelo. "
                "Verifica: 1) 'ollama list' muestra el modelo, "
                "2) 'ollama pull {model}' para descargarlo, "
                "3) El modelo es compatible con chat.")
    
    return content


def _extraer_respuesta_de_reasoning(reasoning: str) -> str:
    """
    Extrae la respuesta final del campo 'reasoning' de modelos Qwen3.
    
    Qwen3 pone todo el thinking process en 'reasoning' y deja 'content' vacío.
    La respuesta final suele aparecer después del paso "Refine the Response".
    """
    lineas = reasoning.split('\n')
    lineas_respuesta = []
    capturando = False
    
    patron_inicio = re.compile(r'^\s*\d+\.\s*\*\*Refine the Response')
    patron_fin = re.compile(r'^\s*\d+\.\s*\*\*Final Review')
    
    for linea in lineas:
        if not capturando:
            if patron_inicio.match(linea):
                capturando = True
                # saltar la línea del encabezado
                continue
            else:
                continue  # seguir buscando
        
        if capturando:
            if patron_fin.match(linea):
                break
            # Quitar bullet points markdown
            linea_limpia = re.sub(r'^\s*\*\s+', '', linea)
            lineas_respuesta.append(linea_limpia)
    
    if lineas_respuesta:
        resultado = '\n'.join(lineas_respuesta).strip()
        if resultado:
            return resultado
    
    # Fallback: último bloque sustancial de texto
    bloques = re.split(r'\n\s*\n', reasoning)
    bloques_sustanciales = [b.strip() for b in bloques if len(b.strip()) > 100]
    if bloques_sustanciales:
        return bloques_sustanciales[-1]
    
    return reasoning  # último recurso: devolver el reasoning completo


def main():
    """Función principal del agente RAG."""
    parser = argparse.ArgumentParser(description="Agente RAG para consultas del aula STEAM")
    parser.add_argument("--pregunta", "-p", type=str, help="Pregunta a realizar")
    parser.add_argument("--k", "-k", type=int, default=5, help="Número de chunks a recuperar (default: 5)")
    args = parser.parse_args()
    
    # Configuración
    # Ruta resuelta desde el archivo, no desde el CWD
    ruta_rag = Path(__file__).resolve().parent.parent
    ruta_indice = ruta_rag / "faiss_index"
    model = os.getenv("OLLAMA_MODEL", "qwen3.5:9b")
    base_url = os.getenv("OLLAMA_BASE_URL", "http://localhost:11434/v1")
    
    # Verificar que el índice existe
    if not os.path.exists(ruta_indice):
        print("❌ Error: El índice FAISS no existe.")
        print("   Ejecuta primero: python apps/rag/src/indexador.py")
        sys.exit(1)
    
    # Obtener pregunta
    if args.pregunta:
        pregunta = args.pregunta
    else:
        pregunta = input("🤖 Pregunta: ")
    
    # Cargar vectorstore
    try:
        vectorstore = cargar_vectorstore(str(ruta_indice))
    except Exception as e:
        logger.error(f"Error al cargar el índice: {e}")
        print("❌ Error al cargar el índice FAISS. Verifica que exista y esté corrupto.")
        sys.exit(1)
    
    # Recuperar contexto
    documentos = recuperar_contexto(vectorstore, pregunta, k=args.k)
    
    if not documentos:
        print("⚠️  No se encontró información relevante en los manuales.")
        sys.exit(0)
    
    # Construir prompt y consultar
    messages = construir_prompt(pregunta, documentos)
    
    try:
        respuesta = consultar_ollama(messages, model, base_url)
        print(f"\n🤖 Respuesta:\n{respuesta}\n")
        
        # Mostrar fuentes
        fuentes = sorted(set(
            doc.metadata.get('source', 'Desconocido') for doc in documentos
        ))
        print(f"📚 Fuentes: {', '.join(fuentes)}")
        
    except Exception as e:
        logger.error(f"Error al consultar Ollama: {e}")
        print(f"❌ Error: No se pudo conectar con Ollama en {base_url}")
        print("   Verifica que Ollama esté corriendo: ollama serve")


if __name__ == "__main__":
    main()