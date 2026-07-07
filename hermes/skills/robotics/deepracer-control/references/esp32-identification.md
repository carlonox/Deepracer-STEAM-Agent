# ESP32/ESP8266 Identification on DeepRacer

> Session reference: 2026-07-07 — identifying two ESP-family devices connected to the robot via USB

## Scenario

The DeepRacer had **two serial devices** connected. The user had assumed both were ESP32s but one turned out to be an **ESP8266** (older, less capable chip).

## Detection Commands (run via SSH paramiko)

```python
import paramiko
ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect('10.203.150.56', username='deepracer', password='Steambog1$', timeout=15)

# 1. List USB devices — shows USB-UART bridge chips
stdin, stdout, stderr = ssh.exec_command('lsusb', timeout=10)
print(stdout.read().decode())

# 2. List serial ports
stdin, stdout, stderr = ssh.exec_command('ls -la /dev/ttyUSB* /dev/ttyACM*', timeout=10)
print(stdout.read().decode())

# 3. Kernel messages for driver info
stdin, stdout, stderr = ssh.exec_command('dmesg | grep -iE "tty|usb|ch34|cp210|ftdi" | tail -20', timeout=10)
print(stdout.read().decode())

ssh.close()
```

## Actual Discovery

### Device A — On CH340 adapter (assumed to be ESP32)
| Property | Value |
|----------|-------|
| USB VID:PID | `1a86:7523` (QinHeng HL-340) |
| Port | `/dev/ttyUSB0` |
| Driver | `ch341-uart` |
| **Actual chip** | **ESP8266EX** (not ESP32!) |
| Features | WiFi only, no Bluetooth, single-core |
| Crystal | 26 MHz |
| MAC | `f4:cf:a2:6a:ae:eb` |
| Flash | 4 MB |

### Device B — On CP2102 adapter (newly connected)
| Property | Value |
|----------|-------|
| USB VID:PID | `10c4:ea60` (Silicon Labs CP2102) |
| Port | `/dev/ttyUSB1` |
| Driver | `cp210x` |
| **Actual chip** | **ESP32-D0WD-V3** ✅ |
| Features | WiFi + BT Classic + BLE, dual-core 240 MHz |
| Crystal | 40 MHz |
| MAC | `e0:5a:1b:9d:a5:ac` |
| Flash | 4 MB |

## Key Lessons

1. **CH340 ≠ ESP32** — The CH340 USB adapter is cheap and ubiquitous on ESP8266 boards. If you see CH340, suspect ESP8266 until proven otherwise.
2. **CP2102 usually means proper ESP32** — Silicon Labs CP2102 is a higher-quality bridge, standard on official Espressif dev boards.
3. **Always run `esptool chip_id`** before assuming a device is what it claims to be — it takes 10 seconds and saves confusion.
4. **When both are present, the ESP32 should be the primary** — it has 2× the cores, 3× the speed, Bluetooth, and more I/O.

## esptool Installation on DeepRacer

```python
# Via SSH paramiko
stdin, stdout, stderr = ssh.exec_command(
    'pip3 install esptool --user 2>&1 | tail -5', timeout=60)
print(stdout.read().decode())
```

The binary is installed at `~/.local/bin/esptool.py`. Add to PATH:
```bash
export PATH=$HOME/.local/bin:$PATH
```

## Chip Identification Commands

```bash
# Identify chip on ttyUSB0
python3 -m esptool --port /dev/ttyUSB0 --baud 115200 chip_id

# Read flash size
python3 -m esptool --port /dev/ttyUSB0 --baud 115200 flash_id

# For a second device on ttyUSB1:
python3 -m esptool --port /dev/ttyUSB1 --baud 115200 chip_id
python3 -m esptool --port /dev/ttyUSB1 --baud 115200 flash_id
```

## Recommendation for the STEAM Agent Project

Use the **ESP32-D0WD-V3 on `/dev/ttyUSB1`** (CP2102 adapter) as the primary microcontroller. It offers:
- Dual-core 240 MHz vs single-core 80 MHz
- Bluetooth Classic + BLE for wireless remote control
- More SRAM (520 KB vs ~80 KB)
- Reliable 921600 baud serial for fast firmware flashing

The ESP8266 was **removed** from the robot — only the ESP32 remains.

---

## Firmware: MicroPython (recomendado)

### ¿Por qué MicroPython y no Arduino C++?

La toolchain de compilación C++ para ESP32 presentó múltiples fallos en este entorno:
- `arduino-cli` se cuelga sin producir salida
- PlatformIO tiene un toolchain `xtensa-esp32-elf` v8.4.0 incompleto (falta `stdint.h` del sysroot)
- La librería `BluetoothSerial` requiere `sdkconfig.h` que no se genera automáticamente
- `MissingPackageManifestError` recurrente con `tool-esptoolpy`

**MicroPython funciona perfectamente** y permite iterar rápido sin toolchain.

### Flasheo de MicroPython

```bash
# En el robot DeepRacer (vía SSH)
pip3 install esptool --user
export PATH=$HOME/.local/bin:$PATH

# 1. Descargar firmware
# https://micropython.org/download/ESP32_GENERIC/
# Firmware: ESP32_GENERIC-20260406-v1.28.0.bin

# 2. Borrar flash
python3 -m esptool --port /dev/ttyUSB1 --baud 921600 erase_flash

# 3. Flashear MicroPython
python3 -m esptool --port /dev/ttyUSB1 --baud 921600 --chip esp32 write_flash -z 0x1000 micropython.bin

# 4. Verificar
python3 -m esptool --port /dev/ttyUSB1 --baud 115200 verify_flash --flash_size 4MB 0x1000 micropython.bin
```

### Subir main.py al ESP32

```python
import serial, time, binascii

ser = serial.Serial("/dev/ttyUSB1", 115200, timeout=5)
ser.dtr = False           # ¡CRÍTICO! No resetear al conectar
ser.rts = False
time.sleep(0.5)
ser.reset_input_buffer()

# Entrar a raw REPL
for _ in range(3):
    ser.write(b"\x03")
    time.sleep(0.15)
ser.write(b"\x01")
time.sleep(0.5)
ser.read(1024)

# Subir archivo usando binascii.unhexlify (MicroPython NO tiene base64)
with open("main.py", "rb") as f:
    content = f.read()
hex_data = binascii.hexlify(content).decode()

code = f'import binascii as _b\nwith open("main.py","wb") as _f:\n _f.write(_b.unhexlify("{hex_data}"))\nprint("OK")\n'
ser.write(code.encode() + b"\x04")

# Reset para ejecutar
ser.write(b"\x04")
```

### ⚠️ Trampas conocidas de MicroPython

| Error | Causa | Solución |
|-------|-------|----------|
| `TypeError: extra keyword arguments given` | `**kwargs` no existe en MicroPython | Usar parámetro posicional `extra=None` |
| `ImportError: no module named 'base64'` | MicroPython no incluye base64 | Usar `binascii.unhexlify()` o `bytes.fromhex()` |
| Conexión serial sin datos | DTR/RTS causan reset al abrir puerto | `ser.dtr = False; ser.rts = False` |
| `AttributeError: no attribute 'path'` | `os.path` no existe en MicroPython | Usar `os.stat('file')` y leer `f[6]` para tamaño |

### Herramientas útiles en el robot

```bash
pip3 install adafruit-ampy --user   # MicroPython file tool
pip3 install rshell --user          # Remote shell para MicroPython

# Listar archivos en ESP32
ampy --port /dev/ttyUSB1 --baud 115200 ls

# Subir archivo
ampy --port /dev/ttyUSB1 --baud 115200 put main.py

# ¡PERO! Ampy/rshell pueden fallar por DTR/RTS.
# Usar el método raw REPL manual (arriba) como respaldo.
```

---

## KY-037 Sound Sensor Integration

### Pinout (ESP32 DevKit V1 — 30 pines)

```
  ┌──────────────────────────────────┐
  │ USB (CP2102)                     │
┌─┤                                  ├─┐
│ EN  │                          D23 │ │
│ VP  │                          D22 │ │
│ VN  │                          TX0 │ │
│ D34 │                          RX0 │ │
│ D35 │                          D21 │ │
│ D32 │                          D19 │ │
│ D33 │                          D18 │ │
│ D25 │                          D5  │ │
│ D26 │                          D17 │ │
│ D27 │                          D16 │ │
│ D14 │                          D4  │←OUT KY-037
│ D12 │                          D0  │ │
│ D13 │                          D2  │ │
│ GND │  ←── GND KY-037          D15 │ │
│ VIN │                          D8  │ │
│ 3V3 │  ←── VCC KY-037          D7  │ │
│ 3V3 │                          D6  │ │
│ GND │                          D9  │ │
│ GND │                          D10 │ │
│ GND │                          D11 │ │
└─────┴──────────────────────────────┘─┘
```

Conexión: `KY-037 VCC→3V3, GND→GND, OUT→D4(GPIO4)`

### Firmware (fragmento clave)

```python
from machine import Pin
import time

KY037_PIN = 4
sound_sensor = Pin(KY037_PIN, Pin.IN)
COLLISION_COOLDOWN_MS = 500
MIN_SOUND_MS = 30

def send_json(event, extra=None):
    payload = '{"event":"' + event + '"'
    if extra: payload += ',' + extra
    payload += '}'
    print(payload)

while True:
    value = sound_sensor.value()
    if value == 1 and last_state == 0:
        sound_start = time.ticks_ms()
    if value == 0 and last_state == 1:
        duration = time.ticks_diff(time.ticks_ms(), sound_start)
        if duration >= MIN_SOUND_MS and cooldown_ok:
            if duration > 200:
                send_json("clap", '"duration_ms":' + str(duration))
            else:
                send_json("collision", '"duration_ms":' + str(duration))
    last_state = value
    time.sleep_ms(10)
```

### Eventos que envía el ESP32

```json
{"event":"boot","msg":"ESP32 iniciado"}
{"event":"collision","duration_ms":45}
{"event":"clap","duration_ms":650}
{"event":"pong"}
```

Comandos que acepta: `ping` → responde `pong`

---

## Bluetooth — Estado y Alternativas

### Intento fallido: BluetoothSerial C++

El compilador `xtensa-esp32-elf-gcc` v8.4.0 de PlatformIO está incompleto (falta `stdint.h` del sysroot). La librería `BluetoothSerial` del Arduino ESP32 core no compila.

### Alternativa A: BLE nativo en MicroPython (recomendada)

MicroPython v1.28.0 en ESP32 incluye el módulo `bluetooth` con soporte BLE. Se puede implementar un UART BLE Service (Nordic UART Service — NUS) que es compatible con apps como "Serial Bluetooth Terminal" o "nRF Connect".

Código listo: `/opt/data/home/esp32_pio/src/main.py` (rama ky037-ble, pendiente de subir al ESP32 cuando SSH funcione).

### Alternativa B: HC-05 Bluetooth Module (el usuario lo tiene)

El HC-05 es un módulo Bluetooth Classic SPP serial. Se conecta al ESP32 por UART:

```
HC-05      ESP32 DevKit V1
VCC   →    3.3V
GND   →    GND
TX    →    RX0 (GPIO 3)
RX    →    TX0 (GPIO 1)  # Con divisor de voltaje! HC-05 es 5V, ESP32 es 3.3V
```

Ventaja: No requiere compilación. El ESP32 solo forwardea datos entre HC-05 (UART) y DeepRacer (USB Serial).
