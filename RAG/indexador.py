#!/usr/bin/env python3
"""
Script de indexación RAG para el aula STEAM.
Lee todos los manuales .md, genera embeddings y crea un índice FAISS.
"""

import os
import glob
import logging
from pathlib import Path

from langchain_community.document_loaders import TextLoader
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_community.embeddings import HuggingFaceEmbeddings
from langchain_community.vectorstores import FAISS

# Configuración de logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


def cargar_documentos(ruta: str) -> list[dict]:
    """
    Lee todos los .md de RAG/ y retorna lista de dicts con contenido y metadata.
    
    Args:
        ruta: Directorio donde buscar archivos .md
        
    Returns:
        Lista de diccionarios con 'page_content' y 'metadata'
    """
    documentos = []
    patron = os.path.join(ruta, "*.md")
    archivos_md = glob.glob(patron)
    
    if not archivos_md:
        logger.warning(f"No se encontraron archivos .md en {ruta}")
        return documentos
    
    for archivo in archivos_md:
        try:
            loader = TextLoader(archivo, encoding='utf-8')
            docs = loader.load()
            for doc in docs:
                nombre_archivo = os.path.basename(archivo)
                doc.metadata['source'] = nombre_archivo
                documentos.append(doc)
                logger.info(f"Cargado: {nombre_archivo}")
        except Exception as e:
            logger.error(f"Error al cargar {archivo}: {e}")
    
    return documentos


def dividir_en_chunks(documentos: list) -> list:
    """
    Divide documentos en chunks usando RecursiveCharacterTextSplitter.
    
    Args:
        documentos: Lista de documentos con page_content y metadata
        
    Returns:
        Lista de chunks con metadata preservada
    """
    splitter = RecursiveCharacterTextSplitter(
        chunk_size=500,
        chunk_overlap=50,
        separators=["\n## ", "\n### ", "\n", ". ", " "]
    )
    
    chunks = splitter.split_documents(documentos)
    
    # Extraer H1 y H2 de cada chunk para metadata adicional
    for chunk in chunks:
        contenido = chunk.page_content
        # Extraer H1 (primer encabezado # )
        lineas = contenido.split('\n')
        h1 = ""
        h2 = ""
        
        for linea in lineas[:10]:  # Buscar en primeras 10 líneas
            if linea.startswith('# ') and not h1:
                h1 = linea[2:].strip()
            elif linea.startswith('## ') and not h2:
                h2 = linea[3:].strip()
        
        chunk.metadata['h1'] = h1
        chunk.metadata['h2'] = h2
        logger.debug(f"Chunk creado: {chunk.metadata.get('source', 'unknown')}, H1: {h1[:50] if h1 else 'N/A'}...")
    
    return chunks


def crear_vectorstore(chunks, ruta_indice: str):
    """
    Crea y guarda un índice FAISS con embeddings.
    
    Args:
        chunks: Lista de chunks divididos
        ruta_indice: Ruta donde guardar el índice FAISS
    """
    embeddings = HuggingFaceEmbeddings(
        model_name="sentence-transformers/all-MiniLM-L6-v2",
        model_kwargs={"device": "cpu"},
        encode_kwargs={"normalize_embeddings": True}
    )
    
    vectorstore = FAISS.from_documents(chunks, embeddings)
    vectorstore.save_local(ruta_indice)
    logger.info(f"Índice FAISS guardado en {ruta_indice}")
    
    return vectorstore


def main():
    """Orquesta el proceso de indexación."""
    ruta_rag = Path(__file__).parent
    ruta_indice = ruta_rag / "faiss_index"
    
    logger.info("Iniciando indexación RAG del aula STEAM...")
    
    # Verificar que existen archivos .md
    rutas_md = glob.glob(str(ruta_rag / "*.md"))
    if not rutas_md:
        logger.error("No se encontraron archivos .md para indexar")
        return
    
    # Cargar documentos
    logger.info("Cargando documentos...")
    documentos = cargar_documentos(str(ruta_rag))
    
    if not documentos:
        logger.error("No se cargaron documentos")
        return
    
    logger.info(f"Documentos cargados: {len(documentos)}")
    
    # Dividir en chunks
    logger.info("Dividiendo en chunks...")
    chunks = dividir_en_chunks(documentos)
    logger.info(f"Total de chunks creados: {len(chunks)}")
    
    # Crear y guardar vectorstore
    logger.info("Creando índice FAISS...")
    crear_vectorstore(chunks, str(ruta_indice))
    
    # Estadísticas finales
    fuentes_unicas = set(doc.metadata.get('source', 'unknown') for doc in documentos)
    logger.info(f"Procesamiento completado: {len(documentos)} docs, {len(chunks)} chunks de {len(fuentes_unicas)} fuentes")


if __name__ == "__main__":
    main()