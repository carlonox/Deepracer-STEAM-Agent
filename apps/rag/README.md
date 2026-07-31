# RAG del aula STEAM

Base de conocimiento para responder preguntas sobre los equipos del aula.

## Responsabilidad
Indexar manuales del aula y responder consultas semánticas. No controla
hardware ni expone servicios de red propios.

## Entradas y salidas
- Entrada: manuales Markdown en `knowledge/` y preguntas de texto.
- Salida: índice FAISS en `faiss_index/` (generado, ignorado por Git) y
  respuestas con fuentes vía Ollama.

## Estructura
| Ruta | Propósito |
|---|---|
| `src/indexador.py` | Construcción o actualización del índice vectorial. |
| `src/agente.py` | Consulta interactiva de la base de conocimiento. |
| `knowledge/` | Fuentes documentales (manuales y guías). |
| `requirements.txt` | Dependencias Python reproducibles. |
| `.env.example` | Plantilla de configuración sin secretos. |
| `tests/` | Pruebas de descubrimiento de fuentes sin modelos. |

## Dependencias
Ver `requirements.txt` (langchain, sentence-transformers, faiss-cpu, openai).
Ollama debe estar disponible para generar respuestas.

## Configuración
Copiar `.env.example` como `.env` local; variables `OLLAMA_MODEL`,
`OLLAMA_BASE_URL`, `RAG_API_KEY`.

## Ejecución
```bash
python apps/rag/src/indexador.py        # construye apps/rag/faiss_index/
python apps/rag/src/agente.py --pregunta "¿Cómo calibrar el escáner 3D?"
```

## Pruebas
```bash
python -m pytest apps/rag/tests
```

## Datos generados
`faiss_index/` es regenerable y no se versiona. Los manuales de `knowledge/`
son la fuente; cualquier edición de guías debe hacerse sobre ellos.

## Mantenimiento
Para añadir un equipo: agregar su manual a `knowledge/` y reindexar. Para
retirar uno: eliminarlo y reindexar (la cantidad de fuentes cambia
intencionalmente).
