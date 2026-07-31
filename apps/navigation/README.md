# Navegación ArUco

Navegador por waypoints ArUco del AWS DeepRacer: detecta marcadores, infiere la
ubicación, calcula la ruta más corta (BFS) y envía comandos de manejo al
backend local.

## Responsabilidad
Percepción y navegación del vehículo. **Mueve el vehículo**: toda ejecución
requiere autorización explícita, zona despejada y operador presente.

## Entradas y salidas
- Entrada: cámara USB local o video UDP de la ESP32-S3; instrucciones de texto
  (`ve a salida`, `parate`); backend local `127.0.0.1:5002` (HTTP) y `:5003`
  (canal TCP de manejo).
- Salida: comandos `angle`/`throttle`/`max_speed` hacia el backend.

## Estructura
| Ruta | Propósito |
|---|---|
| `src/controlcamara.py` | Implementación completa (1013 líneas). |
| `requirements.txt` | Dependencias reproducibles (opencv-contrib, numpy, requests). |
| `tests/` | Pruebas sin hardware (BFS, SafetyGate, reensamblaje UDP, texto). |
| `config/` | Configuración futura separada del código. |

El lanzador compatible `controlcamara.py` en la raíz delega en
`src/controlcamara.py` para no romper comandos históricos.

## Dependencias
Python 3.8+ (el robot usa 3.8). `opencv-contrib-python==5.0.0.93`,
`numpy==2.5.1`, `requests==2.34.2` (ver `requirements.txt`).

## Configuración
Las constantes del módulo (`BACKEND_URL`, `CAMERA_SOURCE`, `ESP32_*`,
`ARUCO_PLACES`, `ARUCO_ROUTES`, umbrales de seguridad) se ajustan en
`src/controlcamara.py`. Los `*_THROTTLE` son **normalizados** `[0,1]`: el backend
los calibra a la zona muerta real del robot (`THROTTLE_DEAD_ZONE=0.5`).

## Ejecución
```bash
python apps/navigation/src/controlcamara.py   # o el lanzador compatible en la raíz
```

## Pruebas
Seguras, sin hardware:
```bash
python -m pytest apps/navigation/tests
```

Pruebas con hardware (solo autorizadas): vehículo elevado o ruedas libres,
parada de emergencia disponible, primero video → percepción → throttle cero →
movimiento limitado.

## Datos generados
Ninguno persistente.

## Mantenimiento
Cambiar el mapa en `ARUCO_PLACES`/`ARUCO_ROUTES` y actualizar sus tests.
Separar percepción/simulación de conducción antes de automatizar pruebas.
