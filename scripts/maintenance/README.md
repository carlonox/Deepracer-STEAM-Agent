# Mantenimiento

Tareas explícitas de mantenimiento. Nada aquí se ejecuta automáticamente.

- Reindexar RAG: `python apps/rag/src/indexador.py`
- Reconstruir frontend: `npm ci && npm run build` en `apps/frontend/`
- Verificar integridad de `tools/arduino/arduino-cli`: `sha256sum` (ver `tools/arduino/README.md`)
