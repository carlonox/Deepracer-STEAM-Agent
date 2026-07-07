# 🚗 DeepRacer STEAM Agent — Handoff Document

> Generado: 2026-07-07 | Sesión completa de exploración y configuración
> Propósito: Guía de inicio rápido para nueva sesión del agente Hermes

---

## 📡 Acceso al Robot

| Servicio | Detalle |
|----------|---------|
| **IP LAN** | `10.203.150.56` |
| **IP Tailscale** | `100.117.192.31` |
| **SSH** | `deepracer` / `Steambog1$` |
| **Sudo** | Misma contraseña que SSH |
| **API Web** | `http://10.203.150.56:5001/login` — pass: `48AW5fAB` |
| **Dashboard DeepRacer** | `http://10.203.150.56:5001/login` |
| **Camara stream** | `http://10.203.150.56:8080/stream_viewer?topic=/camera_pkg/display_mjpeg` |
| **Hermes Dashboard** | `http://localhost:9999/login` — admin/steambogadm |

### ⚠️ Problemas de conexión conocidos
- SSH es **intermitente** — a veces conecta, a veces timeout. Persistir.
- Firewall del robot: `iptables policy DROP`. Solución: `sudo iptables -I INPUT 1 -s 10.0.0.0/8 -j ACCEPT`
- Container Docker NO tiene acceso a Tailscale. Usar IP LAN.
- Backend Node.js proxy en Windows host:5002 si Docker no alcanza al robot.

---

## 🔧 Sistema del Robot

- **OS:** Ubuntu 20.04.1 LTS, Kernel 4.15.0-1005-deeplens
- **ROS2:** Foxy Fitzroy
- **Python:** 3.8.5
- **Arquitectura:** x86_64 (Intel Atom)
- **Disco:** 29GB (15GB libres)
- **RAM:** ~4GB (2GB usada idle)

---

## 📡 Sensores — Realidad vs Documentación

| Sensor | Estado | Detalle |
|--------|--------|---------|
| 📸 **Camara frontal** | ✅ Activa | `/dev/video0/1`, MJPEG via web_video_server en puerto 8080 |
| 🧭 **IMU BMI160** | ❌ No presente | AWS quitó el chip en revisiones posteriores, no soldado |
| ⚙️ **Servo/Motor** | ✅ OK | Controlado por I2C bus 1, address `0x44` (PWM controller) |
| 🔋 **Batería LiPo** | ✅ Monitoreada | ADC en `0x5E` (bus 1), servicio `/i2c_pkg/battery_level` |
| 🔋 **Batería cómputo** | ❌ No monitoreada | Power Bank USB, sin pines de datos |
| 📡 **LiDAR RPLIDAR** | ⏳ Software instalado | Hardware no conectado. Binarios en `/opt/aws/deepracer/lib/rplidar_ros/` |

---

## 🔌 I2C Buses (scaneados con `sudo i2cdetect -y N`)

| Bus | Dispositivos | Función |
|:---:|:-------------|:--------|
| **0** | `0x55` (UU) | Kernel driver (RTC/timing) |
| **1** | `0x08`, `0x44`, `0x5E` | **Chasis core** — PWM motor/servo (0x44), batería ADC (0x5E) |
| **5** | `0x37`, `0x3a`, `0x49`, `0x50`, `0x54`, `0x59` | Puente expansión Intel Atom |
| 2-4, 6-7 | Vacíos | Disponibles para expandir |

---

## 🚗 Movimiento — API REST (puerto 5001)

**Flujo obligatorio** (sin pausa entre comandos):
```
POST /login (CSRF + cookie)
  → PUT /api/drive_mode {"drive_mode":"manual"}
  → PUT /api/start_stop {"start_stop":"start"}
  → LOOP PUT /api/manual_drive {"angle":X,"throttle":Y,"max_speed":Z}
  → PUT /api/start_stop {"start_stop":"stop"}
```

**Reglas:**
- Watchdog 200ms — loop sin pausa, mínimo 50-100 Hz
- Throttle invertido: negativo = avanza
- Valores recomendados: throttle=0.7, max_speed=1.0, angle de -1 a +1

**Headers necesarios:**
```
Content-Type: application/json
X-Requested-With: XMLHttpRequest
X-CSRFToken: <token del login>
Cookie: session=<cookie del login>
```

---

## 💡 LEDs Traseros

Controlados por I2C PWM. El web server (~1 Hz) sobreescribe cualquier cambio.

**Solución:** Bucle ROS2 de alta frecuencia (50+ Hz) para vencer al web server.

```python
import rclpy, time
from rclpy.node import Node
from deepracer_interfaces_pkg.srv import SetLedCtrlSrv

rclpy.init(); n = Node("led")
c1 = n.create_client(SetLedCtrlSrv, "/ctrl_pkg/set_car_led")
c2 = n.create_client(SetLedCtrlSrv, "/servo_pkg/set_led_state")
c1.wait_for_service(3); c2.wait_for_service(3)
r = SetLedCtrlSrv.Request()

def led(red, green, blue, sec=5, hz=50):
    r.red, r.green, r.blue = red, green, blue
    start = time.time()
    while time.time() - start < sec:
        c1.call_async(r); c2.call_async(r)
        time.sleep(1.0/hz)
```

**Valores:** RGB de 0-255, o hasta 9999825 para full PWM brightness.
**Servicios:** `/ctrl_pkg/set_car_led`, `/servo_pkg/set_led_state`, `/ctrl_pkg/get_car_led`, `/servo_pkg/get_led_state`

---

## 📡 ROS2 — Topics (7)

| Topic | Descripción |
|-------|-------------|
| `/ctrl_pkg/raw_pwm` | PWM motor |
| `/ctrl_pkg/servo_msg` | Dirección servo |
| `/deepracer_navigation_pkg/auto_drive` | Auto drive |
| `/webserver_pkg/manual_drive` | Comandos manuales |
| `/webserver_pkg/calibration_drive` | Calibración |
| `/parameter_events` | Eventos ROS2 |
| `/rosout` | Logs ROS2 |

La cámara NO publica topic ROS2 — usa `web_video_server` en puerto 8080.

---

## 🔐 Archivos clave en el robot

| Ruta | Propósito |
|------|-----------|
| `/opt/aws/deepracer/password.txt` | Hash contraseña API web |
| `/opt/aws/deepracer/token.txt` | UUID dispositivo |
| `/opt/aws/deepracer/calibration.json` | Calibración motor/servo |
| `/opt/aws/deepracer/sensor_configuration.json` | Config LiDAR (software only) |
| `/opt/aws/deepracer/led_values.json` | Estado persistente LEDs |
| `/opt/aws/deepracer/start_ros.sh` | Script de inicio ROS2 |
| `/opt/aws/deepracer/lib/deepracer_launcher/` | Launch principal |
| `/opt/aws/deepracer/lib/device_console/` | Web UI del robot |
| `/opt/aws/deepracer/lib/deepracer_interfaces_pkg/` | Definiciones servicios ROS2 |
| `/opt/aws/deepracer/lib/rplidar_ros/` | Paquete LiDAR (solo software) |

---

## 🔌 ESP32 Conectado

- **Dispositivo:** ESP32 con CH340 (QinHeng HL-340)
- **Puerto:** `/dev/ttyUSB0`
- **Usuario en grupo `dialout`** ✅
- **Estado:** Conectado físicamente, sin firmware cargado
- **Pendiente:** Instalar `esptool` y subir firmware

---

## 🛠️ Para nueva sesión — Checklist rápido

- [ ] SSH al robot: `ssh deepracer@10.203.150.56`
- [ ] Si falla: pedir al usuario verificar robot encendido
- [ ] Si timeout pero ping funciona: firewall. Ejecutar regla iptables
- [ ] Verificar ROS2: `source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash`
- [ ] LEDs con bucle de alta frecuencia
- [ ] Mover robot con API REST (loop sin pausa, throttle negativo)
- [ ] ESP32: instalar esptool y subir firmware
- [ ] Consultar skills: `deepracer-control`
- [ ] Consultar referencias: `deepracer-hardware-inventory.md`, `deepracer-led-control.md`
- [ ] Skills guardados en: `/opt/data/skills/robotics/deepracer-control/`

---

## 📁 Skills y Referencias

| Archivo | Ruta |
|---------|------|
| Skill principal | `deepracer-control` (skill view) |
| Inventario hardware | `skill_view("deepracer-control", "references/deepracer-hardware-inventory.md")` |
| Guía LEDs | `skill_view("deepracer-control", "references/deepracer-led-control.md")` |
| Handoff actual | `/workspace/HANDOFF.md` |


---

## 🧩 Sesión 2026-07-07: ESP32 Firmware + KY-037 + Bluetooth

### 🎯 Objetivos
- Identificar y seleccionar el mejor microcontrolador entre dos dispositivos conectados
- Cargar firmware al ESP32-D0WD-V3
- Integrar sensor KY-037 (sonido/golpes)
- Probar Bluetooth para control remoto

---

### 🔬 Descubrimientos Clave

| Hallazgo | Detalle |
|----------|---------|
| **El "ESP32" original era un ESP8266** | El dispositivo conectado a CH340/HL-340 resultó ser un ESP8266EX (no ESP32) |
| **El nuevo ESP32 es legítimo** | ESP32-D0WD-V3 rev3.0, CP2102, dual-core 240MHz, WiFi+BT, 4MB flash |
| **ESP32 retirado, ESP32 nuevo seleccionado** | El viejo ESP8266 se removió, solo queda el ESP32 en `/dev/ttyUSB1` |

### 🔧 Firmware — MicroPython

**Decisión:** Se descartó Arduino C++ por problemas graves de toolchain. Se optó por **MicroPython v1.28.0**.

**Proceso de flasheo exitoso:**
1. `pip3 install esptool --user` en el robot
2. `esptool --port /dev/ttyUSB1 --baud 921600 erase_flash`
3. `esptool --port /dev/ttyUSB1 --baud 921600 --chip esp32 write_flash -z 0x1000 micropython.bin`
4. Subir `main.py` vía raw REPL usando `binascii.unhexlify` (MicroPython NO tiene módulo `base64`)

**Conexión físico (ESP32 DevKit V1 — 30 pines):**
```
KY-037        ESP32 DevKit V1
VCC    ───→   3V3 (fila izquierda)
GND    ───→   GND (fila derecha)
OUT    ───→   D4  (GPIO 4)
```

**Protocolo serial (115200 baud):**
- ESP32 envía JSON por USB al DeepRacer
- Mensajes: `boot`, `collision`, `clap`, `pong`, `heartbeat`
- Responde a comandos: `ping` → `{"event":"pong"}`

**Pruebas REALIZADAS con éxito:**
- ✅ Boot message: `{"event":"boot","msg":"ESP32 iniciado"}`
- ✅ Ping/Pong: `ping` → `{"event":"pong"}`
- ✅ KY-037 detectó 14 eventos `clap` en 15 segundos

### ⚠️ Problemas y Soluciones

| Problema | Causa | Solución |
|----------|-------|----------|
| SSH Intermitente | Firewall iptables + fail2ban | Usar IP LAN (10.x.x.x) en lugar de Tailscale (100.x.x.x). La regla `iptables -I INPUT 1 -s 10.0.0.0/8 -j ACCEPT` solo cubre tráfico 10.x.x.x |
| `arduino-cli` cuelga | No se determinó — posiblemente red o permisos | Abandonado, migrar a PlatformIO |
| PlatformIO: `MissingPackageManifestError` | tool-esptoolpy sin `package.json` | Crear `package.json` manual en `~/.platformio/packages/tool-esptoolpy/` |
| PlatformIO: `sdkconfig.h` no encontrado | BluetoothSerial necesita sdkconfig.h | Usar `-include /ruta/al/sdkconfig.h` en build_flags |
| PlatformIO: `stdint.h` no encontrado | Toolchain xtensa-esp32-elf 8.4.0 corrupto | Se reinstaló pero el problema persistió con versiones recientes del platform |
| MicroPython: `**kwargs` no soportado | MicroPython no implementa kwargs | Usar argumento posicional `extra=None` |
| MicroPython: `base64` no existe | MicroPython no incluye base64 | Usar `binascii.unhexlify()` o `bytes.fromhex()` |
| Serial ESP32: datos vacíos | DTR/RTS resetean el chip al abrir puerto | `ser.dtr = False; ser.rts = False` antes de leer |
| Conexión SSH perdida | SSH daemon caído o firewall | Usar web API (puerto 5001) como fallback, o pedir al usuario reiniciar sshd |

### 📡 Bluetooth — Estado Actual

**NO se logró compilar BluetoothSerial (C++)** por toolchain corrupto.

**Alternativas viables:**
1. **HC-05 (el usuario ya lo tiene)** — Conectar por UART al ESP32. No requiere compilación.
2. **BLE nativo en MicroPython** — El `bluetooth` module de MicroPython v1.28.0 soporta BLE en ESP32. Requiere actualizar `main.py` (código listo en `/opt/data/home/esp32_pio/src/main.py` — versión BLE).
3. **Arreglar toolchain C++** — Pendiente, requiere reinstalar `espressif32` platform correctamente.

### 📁 Archivos Generados

| Archivo | Propósito |
|---------|-----------|
| `/workspace/HANDOFF.md` | Este documento |
| `/opt/data/home/esp32_pio/src/main.py` | Firmware MicroPython actual (KY-037 + serial) |
| `/opt/data/home/esp32_pio/src/main.cpp` | Versión C++ con Bluetooth (no compila aún) |
| `/opt/data/home/esp32_firmware/esp32_bt.ino` | Firmware Arduino con Bluetooth (no compila) |
| `/opt/data/home/upload4.py` | Script para subir main.py al ESP32 vía raw REPL |
| `/opt/data/home/verify_esp32.py` | Script de verificación |
| `/tmp/micropython.bin` | MicroPython v1.28.0 firmware (1.7MB) |

### 📚 Referencias

- Skill: `deepracer-control` → `skill_view("deepracer-control")`
- Referencia ESP32: `skill_view("deepracer-control", "references/esp32-identification.md")`
- Inventario hardware: `skill_view("deepracer-control", "references/deepracer-hardware-inventory.md")`
- Script lectura ESP32: `skill_view("deepracer-control", "scripts/read-esp32.py")`

### 🛠️ Recomendaciones para próxima sesión

- [ ] Restaurar SSH en el robot (pedir al usuario verificar `sshd` con monitor+teclado)
- [ ] Subir firmware BLE a ESP32 (código ya listo en `main.py` v2 con Bluetooth)
- [ ] Probar conexión Bluetooth desde app móvil ("Serial Bluetooth Terminal")
- [ ] Conectar KY-037 al ESP32 según pinout de DevKit V1
- [ ] Escribir script en DeepRacer para leer `/dev/ttyUSB1` y reaccionar a eventos
- [ ] El HC-05 puede conectarse al ESP32 por UART (TX/RX) para Bluetooth Classic si se prefiere sobre BLE
- [ ] Probar respuesta del robot a eventos: `collision` → stop, `clap` → toggle modo
- [ ] Las herramientas de compilación C++ (arduino-cli, PlatformIO) están instaladas pero requieren reparación del toolchain

### 🔌 Nota sobre conectividad

- **LAN IP:** `10.203.150.56` — SSH intermitente, web API (puerto 5001) estable
- **Tailscale IP:** `100.117.192.31` — Ping funciona, SSH también intermitente
- **Solución SSH:** La regla `iptables -I INPUT 1 -s 10.0.0.0/8 -j ACCEPT` abre SSH desde cualquier IP 10.x.x.x
- **Al connectar desde Docker:** Nuestra IP es `172.18.0.2`, no 10.x.x.x — la regla iptables no cubre. Usar Tailscale.

### 🛠️ Checklist actualizado (2026-07-07)

- [x] SSH al robot: `ssh deepracer@10.203.150.56` (usa LAN, no Tailscale)
- [ ] Si SSH falla: web API en puerto 5001 funciona, pedir usuario reiniciar sshd
- [x] Identificar ESP32 vs ESP8266 con `esptool chip_id`
- [x] Remover ESP8266 (CH340), conservar ESP32 (CP2102)
- [x] Flashear MicroPython v1.28.0 al ESP32
- [x] Subir firmware con KY-037 (main.py)
- [x] Probar KY-037: detecta sonidos/golpes ✅
- [ ] Subir firmware con BLE (código listo, pendiente de subir)
- [ ] Probar Bluetooth desde app móvil
- [ ] Escribir script en DeepRacer para leer `/dev/ttyUSB1`
- [ ] Conectar HC-05 si se prefiere Bluetooth Classic
- [ ] Consultar skills: `deepracer-control`
- [ ] Consultar referencias: `esp32-identification.md`, `deepracer-hardware-inventory.md`
- [ ] Skills guardados en: `/opt/data/skills/robotics/deepracer-control/`
- [ ] Firmware actual: `/opt/data/home/esp32_pio/src/main.py`
