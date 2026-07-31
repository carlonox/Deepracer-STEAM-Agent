# Camara ESP32-S3 por UDP

`apps/navigation/src/controlcamara.py` ahora puede usar dos fuentes de video:

- `CAMERA_SOURCE = "usb"`: camara local por OpenCV.
- `CAMERA_SOURCE = "esp32_udp"`: video JPEG enviado por la ESP32-S3 por UDP.

La fuente ESP32 ya esta activada en `apps/navigation/src/controlcamara.py`:

```python
CAMERA_SOURCE = "esp32_udp"
```

El computador escucha en:

```text
IP: 0.0.0.0
Puerto UDP: 5000
```

La ESP32 crea esta red Wi-Fi:

```text
SSID: DeepRacer-Camera
Clave: ${ESP32_CAMERA_WIFI_PASSWORD}
IP de la ESP32: 192.168.4.1
```

Al iniciar, Python envia `DEEPRACER_DISCOVER 5000` al puerto UDP `5001`.
La ESP aprende automaticamente la IP del computador y comienza a transmitir.

## Formato de paquetes

La ESP debe enviar cada JPEG completo en uno o varios paquetes UDP.

Cada paquete fragmentado debe tener este encabezado big-endian de 14 bytes:

```text
frame_id       uint32  identificador creciente del cuadro
chunk_index    uint16  indice del fragmento, iniciando en 0
chunk_count    uint16  cantidad total de fragmentos del JPEG
payload_size   uint16  bytes validos del payload en este paquete
timestamp_ms   uint32  opcional; usar 0 si no hay reloj sincronizado
payload        bytes   fragmento JPEG
```

En Python el formato equivalente es:

```python
struct.pack("!IHHHI", frame_id, chunk_index, chunk_count, payload_size, timestamp_ms)
```

Recomendaciones iniciales:

- Fragmentos de `1200` a `1400` bytes.
- Resolucion `480x320`.
- JPEG quality inicial `16`.
- Enviar solo el cuadro mas reciente.
- No retransmitir fragmentos perdidos.

## Modo simple para primera prueba

El receptor tambien acepta un JPEG completo en un solo datagrama UDP si el paquete empieza con los bytes JPEG `FF D8`.

Esto sirve para validar la conexion rapidamente, pero no es ideal para video estable porque un JPEG suele superar el tamano seguro de un datagrama UDP.

## Metricas en pantalla

Cuando `CAMERA_SOURCE = "esp32_udp"`, la ventana muestra:

```text
UDP FPS:<fps> drop:<cuadros descartados> lat:<latencia ms>
```

La latencia solo aparece si `timestamp_ms` es tiempo Unix en milisegundos sincronizado con el computador. Si la ESP manda `millis()` desde arranque, el receptor deja la latencia en `0ms`.
