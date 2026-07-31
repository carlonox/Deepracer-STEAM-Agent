# Speech to Text

Reconocimiento de voz local en tiempo real con Faster Whisper.

## Responsabilidad
Capturar micrófono, detectar pausas de silencio y transcribir tramos de voz.
No controla el vehículo ni acepta peticiones HTTP todavía.

## Entradas y salidas
- Entrada: micrófono local a 16 kHz mono (PCM int16).
- Salida: transcripciones por consola.

## Estructura
| Ruta | Propósito |
|---|---|
| `src/server.py` | Bucle de captura y transcripción. |
| `tests/` | Pruebas de humo sin GPU ni micrófono. |
| `requirements.txt` | Dependencias reproducibles. |

## Dependencias
`faster-whisper` (modelo `large-v3`), `sounddevice`, `numpy`. Requiere GPU
CUDA para el modo por defecto (`DEVICE = "cuda"`, `float16`).

## Configuración
Parámetros en `src/server.py`: `MODEL_SIZE`, `DEVICE`, `COMPUTE_TYPE`,
`ENERGY_THRESHOLD`, `SILENCE_DURATION_SEC`.

## Ejecución
```bash
python apps/speech-to-text/src/server.py
```

## Pruebas
Sin micrófono ni GPU: solo estructura.

```bash
python -m pytest apps/speech-to-text/tests
```

## Datos generados
Ninguno persistente; la transcripción se imprime en consola.

## Mantenimiento
El log de ejecución (`realtimesst.log`) es generado y no debe versionarse.
Para exponer HTTP, añadir un servidor en `src/` reutilizando
`procesar_y_transcribir`.
