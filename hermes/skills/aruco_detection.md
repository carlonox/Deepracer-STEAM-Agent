# ArUco Marker Detection for AWS DeepRacer

## Resumen

Sistema de detección de marcadores ArUco para navegación por visión del DeepRacker, usando la cámara existente (web_video_server puerto 8080) y OpenCV con el módulo ArUco.

## Pre-requisitos

- OpenCV con módulo ArUco: `opencv-contrib-python==4.13.0.92` (instalado en DeepRacer)
- `numpy==1.19.5` (ya instalado)
- `ffmpeg` (ya instalado en DeepRacer)
- `web_video_server` corriendo en puerto 8080 del DeepRacer

## Verificación de dependencias

```bash
curl -s -X POST http://host.docker.internal:5002/api/exec \
  -H "Content-Type: application/json" \
  -d '{"command": "python3 -c \"import cv2; print(cv2.__version__); print(cv2.aruco.DICT_4X4_50)\""}'
```

Resultado esperado: `4.13.0` y `0`.

## Herramienta principal

### `/home/deepracer/aruco_detect.py` (en el DeepRacer)

Script Python que:
1. Captura un frame del stream MJPEG (`ffmpeg`)
2. Detecta marcadores ArUco (diccionario DICT_4X4_50)
3. Calcula distancia estimada (si hay focal length calibrado)

```bash
# Detección básica
curl -s -X POST http://host.docker.docker.internal:5002/api/exec \
  -H "Content-Type: application/json" \
  -d '{"command": "python3 /home/deepracer/aruco_detect.py"}'

# Con focal length calibrado
curl -s -X POST http://host.docker.internal:5002/api/exec \
  -H "Content-Type: application/json" \
  -d '{"command": "python3 /home/deepracer/aruco_detect.py --focal-length 500 --marker-size 10"}'
```

### Ejemplo de salida (sin marcadores):
```json
{
  "markers_found": 0,
  "markers": [],
  "status": "sin marcadores visibles"
}
```

### Ejemplo de salida (con marcadores):
```json
{
  "markers_found": 2,
  "markers": [
    {
      "id": 0,
      "avg_side_px": 120.5,
      "distance_cm": 41.5
    },
    {
      "id": 5,
      "avg_side_px": 80.2,
      "distance_cm": 62.3
    }
  ],
  "status": "marcadores detectados"
}
```

## Calibración del focal length

Para que el cálculo de distancia funcione, necesitas calibrar la cámara:

1. Coloca un marcador ArUco a una **distancia conocida** (ej: 50 cm)
2. Captura un frame y mide el tamaño del marcador en píxeles
3. Calcula: `focal_length = (marker_size_px * known_distance_cm) / marker_size_cm`

### Método práctico:
```bash
# 1. Genera un marcador ArUco (en local):
python3 -c "
import cv2
dict = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
img = cv2.aruco.generateImageMarker(dict, 0, 200)
cv2.imwrite('/tmp/aruco_marker_id0.png', img)
print('Marker saved: /tmp/aruco_marker_id0.png')
"

# 2. Imprímelo en papel (tamaño recomendado: 10cm x 10cm)

# 3. Colócalo a distancia conocida (ej: 50cm) frente a la cámara

# 4. Edita el script y agrega estos valores, o usa el cálculo manual:
# focal_length_px = (marker_px_at_50cm * 50) / marker_size_cm
```

### Valores de referencia para la cámara del DeepRacer:
- Resolución típica: 640x480
- Focal length estimada: ~500-600 px (requiere calibración real)
- Distancia mínima de detección: ~15 cm
- Distancia máxima de detección: ~200 cm (depende del tamaño del marcador)

## Diccionario ArUco usado

- `DICT_4X4_50`: Marcadores de 4x4 bits, 50 IDs posibles (0-49)
- Tamaño recomendado para impresión: 5-15 cm por lado
- Genera marcadores con:
  ```python
  import cv2
  dict = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
  img = cv2.aruco.generateImageMarker(dict, marker_id, side_pixels)
  ```

## Cálculo de distancia

```
distancia_cm = (tamaño_real_marker_cm * focal_length_px) / tamaño_en_pixeles
```

Donde:
- `tamaño_real_marker_cm`: tamaño del marcador impreso en cm (ej: 10 cm)
- `focal_length_px`: distancia focal de la cámara en píxeles (calibración)
- `tamaño_en_pixeles`: lado promedio del marcador detectado en px

## Integración con el backend

Desde el backend Node.js se puede invocar asíncronamente:

```javascript
// En vehicleControl.js o similar
const { exec } = require('child_process');

async function detectMarkers() {
  const { stdout } = await execPromise(
    'python3 /home/deepracer/aruco_detect.py --focal-length 540 --marker-size 10'
  );
  return JSON.parse(stdout);
}
```

## Solución de problemas

| Problema | Causa | Solución |
|----------|-------|----------|
| `sin marcadores visibles` | No hay marcadores en vista | Coloca marcadores ArUco en el campo de visión |
| `capture failed` | ffmpeg no puede conectar | Verifica `web_video_server` en puerto 8080 |
| `ImportError: aruco` | OpenCV sin contrib | `pip install opencv-contrib-python` |
| Distancias incorrectas | Focal length no calibrado | Calibrar con marcador a distancia conocida |
| Marcadores borrosos | Demasiado lejos/cerca | Ajusta distancia al rango 20-150 cm |

## Próximos pasos

1. Imprimir marcadores ArUco (IDs 0-9, tamaño 10cm)
2. Calibrar focal length con marcador a 50cm
3. Colocar marcadores en la pista del DeepRacer
4. Implementar lógica de navegación basada en posición/distance de marcadores
5. Crear endpoint HTTP en el backend para detección en tiempo real

## Notas técnicas

- El script usa la API nueva de OpenCV 4.13+ (`cv2.aruco.ArucoDetector`)
- Para OpenCV 4.5 y anteriores, la API es diferente (`cv2.aruco.detectMarkers()` directa)
- El stream MJPEG en `/camera_pkg/display_mjpeg` es el topic correcto para la cámara del DeepRacer
- La detección funciona mejor con buena iluminación y marcadores perpendicular a la cámara
