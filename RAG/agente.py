#!/usr/bin/env python3
"""
Agente RAG para consultas semánticas sobre los manuales del aula STEAM.
Carga el índice FAISS y consulta Ollama para respuestas en español.
"""

import os
import sys
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
    client = OpenAI(
        base_url=base_url,
        api_key="ollama"
    )
    
    response = client.chat.completions.create(
        model=model,
        messages=messages,
        temperature=0.1,
        max_tokens=1024
    )
    
    return response.choices[0].message.content


def main():
    """Función principal del agente RAG."""
    parser = argparse.ArgumentParser(description="Agente RAG para consultas del aula STEAM")
    parser.add_argument("--pregunta", "-p", type=str, help="Pregunta a realizar")
    parser.add_argument("--k", "-k", type=int, default=5, help="Número de chunks a recuperar (default: 5)")
    args = parser.parse_args()
    
    # Configuración
    ruta_rag = Path(__file__).parent
    ruta_indice = ruta_rag / "faiss_index"
    model = os.getenv("OLLAMA_MODEL", "qwen3.5:9b")
    base_url = os.getenv("OLLAMA_BASE_URL", "http://localhost:11434/v1")
    
    # Verificar que el índice existe
    if not os.path.exists(ruta_indice):
        print("❌ Error: El índice FAISS no existe.")
        print("   Ejecuta primero: python RAG/indexador.py")
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