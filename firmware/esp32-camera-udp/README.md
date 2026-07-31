# Firmware de cámara ESP32 por UDP

Proyecto PlatformIO que captura JPEG desde una cámara ESP32-S3 y transmite los
frames por UDP al controlador de navegación.

| Ruta | Propósito |
|---|---|
| `platformio.ini` | Placa, framework y opciones de compilación. |
| `src/main.cpp` | Firmware principal. |
| `include/secrets.example.h` | Plantilla pública de credenciales Wi-Fi. |
| `include/secrets.h` | Credenciales locales; está ignorado por Git. |
| `.pio/` | Dependencias y resultados generados por PlatformIO. |
| `pio-build.*.log` | Logs temporales de compilación. |

Antes de compilar, copia `include/secrets.example.h` como `include/secrets.h` y
configura allí el mismo SSID y contraseña definidos en el `.env` de la raíz.
El firmware nunca imprime la contraseña por el puerto serie.

El protocolo está documentado en `../../docs/architecture/protocolo-camara-esp32-udp.md`
y el estado pendiente en `../../docs/plans/camara-esp32-pendiente.md`.
