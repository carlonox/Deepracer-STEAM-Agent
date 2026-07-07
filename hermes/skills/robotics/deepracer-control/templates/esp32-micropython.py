"""
DeepRacer ESP32 Bridge — MicroPython starter template
=====================================================
Copy this file to main.py, adjust the pin numbers,
then upload to the ESP32 via ampy or paste mode.

Conexiones:
  KY-037 VCC → ESP32 3.3V
  KY-037 GND → ESP32 GND
  KY-037 OUT → GPIO 4 (change SOUND_PIN as needed)

Ver el pinout de la placa en: `references/esp32-devkit-pinout.md`
(D4 está en la fila derecha, entre D16 y D0)

Protocolo: newline-delimited JSON sobre Serial (115200 baud)

⚠️  MicroPython limitations:
  - No `**kwargs` in function definitions → use `extra` string param
  - No `base64` module → use `binascii.hexlify`/`unhexlify` for binary data
  - No `os.path.getsize()` → use `os.stat(name)[6]`
"""

import select
import sys
import time
from machine import Pin

# ===== CONFIGURATION =====
SOUND_PIN = 4             # KY-037 digital output
COLLISION_COOLDOWN_MS = 500
MIN_SOUND_MS = 30

# ===== HARDWARE SETUP =====
sound_sensor = Pin(SOUND_PIN, Pin.IN)

# ===== STATE =====
last_sound_time = 0
last_sound_state = 0
sound_start_time = 0


def send_json(event, extra=None):
    """Send a JSON event over serial to the DeepRacer.

    MicroPython does NOT support **kwargs. Pass extra fields as a
    preformatted JSON fragment string:
        send_json("boot", extra='"msg":"started"')
        send_json("collision", extra='"duration_ms":45')
    """
    payload = '{"event":"' + event + '"'
    if extra is not None:
        payload += ',' + extra
    payload += '}'
    print(payload)


def read_command():
    """Read one command line from the DeepRacer (non-blocking)."""
    if sys.stdin in select.select([sys.stdin], [], [], 0)[0]:
        return sys.stdin.readline().strip()
    return None


# ===== MAIN LOOP =====
send_json("boot", extra='"msg":"ESP32 MicroPython iniciado"')

while True:
    sound_value = sound_sensor.value()
    now = time.ticks_ms()

    # Rising edge: sound starts
    if sound_value == 1 and last_sound_state == 0:
        sound_start_time = now

    # Falling edge: sound ends
    if sound_value == 0 and last_sound_state == 1:
        duration = time.ticks_diff(now, sound_start_time)
        cooldown_ok = time.ticks_diff(now, last_sound_time) > COLLISION_COOLDOWN_MS

        if duration >= MIN_SOUND_MS and cooldown_ok:
            last_sound_time = now
            if duration > 200:
                send_json("clap", extra='"duration_ms":' + str(duration))
            else:
                send_json("collision", extra='"duration_ms":' + str(duration))

    last_sound_state = sound_value

    # Handle commands from DeepRacer
    cmd = read_command()
    if cmd:
        if cmd == "ping":
            send_json("pong")
        elif cmd == "status":
            send_json("status", extra='"sound_pin":' + str(sound_value))

    time.sleep_ms(5)
