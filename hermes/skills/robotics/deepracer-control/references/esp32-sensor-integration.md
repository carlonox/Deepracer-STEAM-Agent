# ESP32 Sensor Integration — KY-037 Sound Sensor

> Session: 2026-07-07 — Flashing MicroPython firmware and integrating a KY-037 sound sensor
> Robot: DeepRacer STEAM Agent (`10.203.150.56`)
> ESP32: ESP32-D0WD-V3 on CP2102 (`/dev/ttyUSB1`)

## Overview

The ESP32 connects to the DeepRacer via USB (CP2102 bridge) and communicates over serial at 115200 baud using newline-delimited JSON. External sensors (like the KY-037) are wired directly to ESP32 GPIO pins.

## Wiring

```
KY-037 (3 pins: VCC, GND, OUT)
  VCC → ESP32 3.3V
  GND → ESP32 GND
  OUT → GPIO 4
```

The KY-037 has an onboard potentiometer to adjust the sound threshold. The OUT pin goes HIGH when sound exceeds the threshold.

**Pin note**: GPIO 4 is a safe choice, but any GPIO can work. Avoid pins that are strapping pins during boot (GPIO 0, 2, 5, 12, 15) unless necessary.

## Flashing MicroPython

### Prerequisites (on the DeepRacer via SSH)

```bash
# Install esptool (once)
pip3 install esptool --user
export PATH=$HOME/.local/bin:$PATH
```

### Download and Flash

```bash
# Get MicroPython firmware (~1.7 MB)
wget https://micropython.org/resources/firmware/ESP32_GENERIC-20260406-v1.28.0.bin \
  -O /tmp/micropython.bin

# Erase existing flash
python3 -m esptool --port /dev/ttyUSB1 --baud 921600 erase_flash

# Write MicroPython
python3 -m esptool --port /dev/ttyUSB1 --baud 921600 \
  write_flash -z 0x1000 /tmp/micropython.bin
```

### ⚠️ DTR/RTS Pitfall — ESP32 Resets on Serial Open

When opening the ESP32 serial port from a Python script on the DeepRacer, **DTR must be set to `False` before or immediately after opening** the port. The CP2102 bridge routes DTR to the ESP32's EN pin, so the default pyserial behavior (DTR=True) resets the chip and you get no REPL output.

```python
# WRONG — ESP32 resets immediately
ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=2)
# ser.dtr defaults to True → resets ESP32 → no output

# RIGHT — ESP32 stays running
ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=2)
ser.dtr = False          # <-- CRITICAL: prevent reset
time.sleep(0.1)
ser.rts = False
time.sleep(0.5)
ser.reset_input_buffer()
```

Same fix applies to terminal programs: `screen` may assert DTR by default. Use `picocom` for explicit control:

```bash
picocom -b 115200 --dtr 0 --rts 0 /dev/ttyUSB1
# Now you'll see the >>> prompt
```

### Verify MicroPython

After flashing, connect with DTR/RTS disabled. You should see the MicroPython REPL (`>>>`):

```bash
picocom -b 115200 --dtr 0 --rts 0 /dev/ttyUSB1
# Press Enter — you should see >>>
```

Or from Python (with the DTR fix):
```python
import serial, time
ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=2)
ser.dtr = False          # <-- CRITICAL
time.sleep(0.1)
ser.rts = False
time.sleep(0.5)
ser.reset_input_buffer()
ser.write(b'\r\n')
time.sleep(0.5)
print(ser.read(200).decode())
ser.close()
```

### Upload the Script

Save a `main.py` on the robot, then paste it into the REPL:

**Method 1 — Paste mode (recommended):**
1. `screen /dev/ttyUSB1 115200`
2. Press `Ctrl+E` (enters paste mode)
3. Paste the MicroPython code
4. Press `Ctrl+D` (executes)
5. Type `import machine; machine.reset()` or press `Ctrl+D` again to soft-reboot

**Method 2 — ampy:**
```bash
pip3 install adafruit-ampy --user
ampy --port /dev/ttyUSB1 --baud 115200 put main.py
```

## MicroPython Firmware — KY-037 Logic

### Sound Event Detection

```python
from machine import Pin
import time

KY037_PIN = 4
COOLDOWN_MS = 500
MIN_SOUND_MS = 30

sensor = Pin(KY037_PIN, Pin.IN)
last_sound = 0
last_state = 0
start_time = 0

while True:
    val = sensor.value()
    now = time.ticks_ms()

    # Rising edge: sound starts
    if val == 1 and last_state == 0:
        start_time = now

    # Falling edge: sound ends
    if val == 0 and last_state == 1:
        dur = time.ticks_diff(now, start_time)
        if dur >= MIN_SOUND_MS and time.ticks_diff(now, last_sound) > COOLDOWN_MS:
            last_sound = now
            event = "clap" if dur > 200 else "collision"
            print(f'{{"event":"{event}","duration_ms":{dur}}}', flush=True)

    last_state = val
    time.sleep_ms(5)
```

### JSON Protocol Reference

The ESP32 prints one JSON object per line. The DeepRacer reads from `/dev/ttyUSB1` and parses each line.

**ESP32 → DeepRacer (events):**

| Event | Trigger | Payload |
|-------|---------|---------|
| `boot` | Power-on / reset | `{"msg":"..."}` |
| `collision` | KY-037 short sound (<200ms) | `{"duration_ms":45}` |
| `clap` | KY-037 long sound (>200ms) | `{"duration_ms":350}` |
| `heartbeat` | Every ~10 seconds | `{"uptime":30}` |
| `bt_connected` | Bluetooth client connected | — |
| `bt_disconnected` | Bluetooth client disconnected | — |
| `pong` | Response to `ping` command | — |
| `status` | Response to `status` command | `{"sound_pin":0}` |

**DeepRacer → ESP32 (commands, one per line):**

| Command | Response |
|---------|----------|
| `ping` | `{"event":"pong"}` |
| `status` | `{"event":"status","sound_pin":0}` |

### Reading on the DeepRacer side

Python script on the DeepRacer to consume ESP32 events:

```python
import serial, json

ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=1)

while True:
    line = ser.readline()
    if line:
        try:
            data = json.loads(line.decode().strip())
            event = data.get("event")
            if event == "collision":
                print("⚠️  Collision detected! Duration:", data["duration_ms"], "ms")
                # Send stop command to DeepRacer API
            elif event == "clap":
                print("👏 Clap detected — toggling")
            elif event == "boot":
                print("ESP32 booted:", data.get("msg"))
        except json.JSONDecodeError:
            pass  # Partial line, ignore
```

## Adding Bluetooth (Future)

The ESP32-D0WD-V3 supports Bluetooth Classic (SPP) and BLE. To add Bluetooth control:

1. Use ESP-IDF directly instead of Arduino/PlatformIO if using C++
2. Or use MicroPython's `bluetooth` module (limited but functional for BLE)
3. Or flash the firmware via ESP-IDF with BluetoothSerial enabled

The simplest path for BLE gamepad control is writing a MicroPython BLE UART peripheral that advertises as "DeepRacer-ESP32" and forwards received commands over serial.

## Troubleshooting

| Problem | Likely Cause | Fix |
|---------|-------------|-----|
| `esptool` can't connect | Wrong port or baud rate | Check `ls /dev/ttyUSB*`; try 115200 instead of 921600 |
| Serial garbage | Baud rate mismatch | Both sides must use the same baud (115200) |
| No `>>>` prompt after flash | DTR reset on serial open | Set `ser.dtr = False` in Python or use `picocom --dtr 0` |
| `ampy` / `rshell` fails | REPL not ready or DTR resetting chip | Check with `picocom --dtr 0` first; reset ESP32 (cycle power or press EN button) |
| `TypeError: extra keyword arguments given` | `**kwargs` in MicroPython function | MicroPython does NOT support `**kwargs`. Use a plain `extra` string param instead |
| `ImportError: no module named 'base64'` | `base64` not in MicroPython stdlib | Use `binascii.hexlify`/`unhexlify` for binary data uploads |
| `AttributeError: 'module' object has no attribute 'path'` | `os.path` not in MicroPython | Use `os.stat(name)[6]` instead of `os.path.getsize(name)` |
| KY-037 always HIGH/LOW | Threshold not adjusted | Turn the potentiometer with a screwdriver while making noise |
| ESP32 not detected | USB cable is power-only | Use a data-capable USB cable |
