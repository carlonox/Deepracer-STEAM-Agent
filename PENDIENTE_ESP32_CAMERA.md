# Continuacion: camara ESP32-S3 por UDP

Estado al pausar: se preparo el proyecto y el receptor Python, pero el firmware
todavia no se ha compilado ni cargado en la ESP32.

## Hardware detectado

- Puerto de la placa: `COM8`.
- Adaptador USB: `USB-Enhanced-SERIAL CH343`.
- Placa asumida: ESP32-S3-WROOM N16R8 con camara OV3660, 16 MB de flash y
  8 MB de PSRAM.
- No se modificaron motores ni sus GPIO. El firmware creado solo usa camara y
  Wi-Fi, por lo que no mueve el vehiculo.

## Cambios ya hechos

- [controlcamara.py](controlcamara.py) ahora tiene `CAMERA_SOURCE = "esp32_udp"`.
- Python abre UDP `0.0.0.0:5000` y cada 0.5 s envia el texto
  `DEEPRACER_DISCOVER 5000` a `192.168.4.1:5001`.
- El firmware esta en [esp32_camera_udp](esp32_camera_udp):
  - crea la red Wi-Fi `DeepRacer-Camera`;
  - clave `${ESP32_CAMERA_WIFI_PASSWORD}`;
  - IP de la ESP `192.168.4.1`;
  - recibe el descubrimiento en UDP `5001`;
  - transmite JPEG HVGA (480x320), calidad 16, a maximo 25 FPS por UDP `5000`;
  - fragmenta cada JPEG con el encabezado de 14 bytes que espera Python;
  - deja de enviar video luego de 3 segundos sin mensajes de Python.
- La documentacion de protocolo se actualizo en
  [ESP32_CAMERA_UDP.md](ESP32_CAMERA_UDP.md).

## Herramientas instaladas

Se instalo PlatformIO en el perfil de Windows. El ejecutable no esta en el
`PATH`; usar esta ruta:

```powershell
& "$env:APPDATA\Python\Python313\Scripts\pio.exe"
```

La descarga del entorno de Espressif quedo a 60% del paquete
`framework-arduinoespressif32`. El compilador Xtensa y la plataforma
`espressif32` ya terminaron de descargarse. El proceso de descarga fue detenido
intencionalmente al pausar.

## Pasos para terminar

1. Con la ESP conectada en `COM8`, reanudar la compilacion:

   ```powershell
   & "$env:APPDATA\Python\Python313\Scripts\pio.exe" run
   ```

   Ejecutar dentro de `C:\Users\UNAL\Deepracer-STEAM-Agent\esp32_camera_udp`.
   La descarga deberia continuar desde la cache. Corregir cualquier error de
   compilacion antes de cargar.

2. Cargar el firmware:

   ```powershell
   & "$env:APPDATA\Python\Python313\Scripts\pio.exe" run --target upload
   ```

   Si no entra al cargador automaticamente, mantener presionado `BOOT`, pulsar
   `RESET`, soltar `RESET` y luego soltar `BOOT` cuando PlatformIO intente
   conectarse.

3. Abrir el monitor serie y confirmar mensajes como `CAMERA_OK` y
   `WIFI SSID=DeepRacer-Camera`:

   ```powershell
   & "$env:APPDATA\Python\Python313\Scripts\pio.exe" device monitor
   ```

4. Conectar este computador a la red Wi-Fi `DeepRacer-Camera` con la clave
   `${ESP32_CAMERA_WIFI_PASSWORD}`. Windows puede advertir que no tiene Internet; conservar la
   conexion.

5. Ejecutar `py controlcamara.py`. La ventana debe pasar de esperar video a
   mostrar `UDP FPS`. Durante esta prueba, dejar activo el freno de manos con
   espacio o cambiar temporalmente `ENABLE_VEHICLE_CONTROL = False` para validar
   solo la camara.

## Si falla la camara

El firmware usa el mapa de pines de la variante N16R8 CAM:

```text
SDA=4 SCL=5 XCLK=15 PCLK=13 VSYNC=6 HREF=7
D0=11 D1=9 D2=8 D3=10 D4=12 D5=18 D6=17 D7=16
```

Si el monitor muestra `CAMERA_ERROR`, verificar serigrafia, referencia del
vendedor o foto de ambos lados de la placa. No cambiar los pines a ciegas.

## Archivos ajenos

El repositorio ya tenia cambios no relacionados en `backend/`, `frontend/` y
otros directorios. No se deben revertir al continuar.
