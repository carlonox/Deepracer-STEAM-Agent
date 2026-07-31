# Text to Speech

Genera audio compatible con el servidor de voz usando edge-tts y lo convierte
a PCM 16 kHz mono 16-bit.

## Responsabilidad
Sintetizar texto a voz. No recibe peticiones HTTP: es un generador de archivos
de audio para pruebas e integración futura.

## Entradas y salidas
- Entrada: texto fijo en `src/server.py` (`TEXTO`, `VOZ`).
- Salida: `audio_prueba.mp3` (WAV PCM 16 kHz mono) en el directorio de trabajo.

## Estructura
| Ruta | Propósito |
|---|---|
| `src/server.py` | Generador de audio. |
| `tests/` | Pruebas de humo sin dependencias pesadas. |
| `requirements.txt` | Dependencias reproducibles. |

## Dependencias
`edge-tts` y `pydub` (Python 3.8+). Instalación:

```bash
python -m venv .venv && source .venv/bin/activate
pip install -r requirements.txt
```

## Configuración
Sin variables de entorno. `VOZ = "es-CO-SalomeNeural"` está en el código.

## Ejecución
Desde la raíz del repositorio:

```bash
python apps/text-to-speech/src/server.py
```

## Pruebas
```bash
python -m pytest apps/text-to-speech/tests
```

## Datos generados
`audio_prueba.mp3` y `temp_edge.mp3` (temporal, se elimina solo).

## Mantenimiento
Para servir peticiones HTTP, añadir un servidor (p. ej. FastAPI) en `src/` sin
cambiar el contrato de audio.
