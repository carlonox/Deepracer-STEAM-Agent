# 📋 Hardware Inventory + I2C Bus Analysis

> **Robot:** SpeedRacer (AWS DeepRacer Standard, non-Evo)
> **Last updated:** 2026-07-07
> **IP:** LAN 10.203.150.56 | Tailscale 100.117.192.31

---

## System Specs (Verified via SSH)

| Component | Detail |
|-----------|--------|
| **Model** | AWS DeepRacer Standard (post-2020 hardware revision) |
| **OS** | Ubuntu 20.04.1 LTS (Focal Fossa) |
| **Kernel** | 4.15.0-1005-deeplens |
| **ROS2** | Foxy Fitzroy |
| **Python** | 3.8.5 |
| **Arch** | x86_64 (Intel Atom) |
| **Storage** | 29GB total, 15GB free |
| **RAM** | ~4GB (2GB used at idle) |
| **Sudo password** | Same as SSH: `${DEEPRACER_SSH_PASSWORD}` |

---

## ⚡ Power Architecture — Two Independent Systems

**The #1 hardware cause of "robot doesn't move":** the DeepRacer has two completely separate power paths, and the motors need their own dedicated battery.

| System | Powers | Connector | Monitored? |
|--------|--------|-----------|:----------:|
| 💻 **Compute** | Ubuntu, ROS2, WiFi, LED strip, web server | USB-C (power bank or 5V/2A wall charger) | ❌ No (standard USB, no data pins) |
| ⚡ **Motors** | Drive motor + steering servo | **White 2-pin JST** on main PCB (7.4V LiPo) | ✅ Via I2C (`/i2c_pkg/battery_level`) |

### Key facts

- **The compute system can run on a USB power bank alone.** The purple LED turns on, Wi-Fi connects, the web API responds, the camera streams. But **the motors have zero power** without the LiPo chassis battery.
- **The AC adapter (12V barrel jack) powers BOTH systems** simultaneously — it runs the compute board AND charges the LiPo battery (if connected).
- **Physical motor enable button**: A small tactile switch on the main circuit board (near the battery connector) must be pressed after boot. This is a hardware safety interlock — the web API returns `{"success": true}` even when this button is NOT pressed.
- **Disconnecting AC while the LiPo battery is discharged or absent** causes the robot to shut down immediately.

### Quick diagnostic

If the robot responds to SSH, the camera works, and the web API returns OK for all commands but **nothing physically moves**:
1. ✅ LiPo battery connected? (white 2-pin plug, not just USB power bank)
2. ✅ Motor enable button pressed? (small tactile switch on main board)
3. ✅ Then check software (throttle convention: web API uses positive=forward; watchdog loop at 30Hz)

---

## Sensors — Verified Reality vs Documentation

| Sensor | Doc Says | Reality | Status |
|--------|----------|---------|:------:|
| 📸 **Camera** | 4MP front monocular | `/dev/video0/1`, MJPEG via `:8080` | ✅ |
| 🧭 **IMU (BMI160)** | Bosch BMI160 on I2C | **NOT soldered** on this revision | ❌ |
| ⚙️ **Servo position** | Internal feedback | Topic `/ctrl_pkg/servo_msg` available | ✅ |
| ⚡ **Motor PWM** | Internal | Topic `/ctrl_pkg/raw_pwm` available | ✅ |
| 🔋 **Battery (LiPo)** | Chassis battery monitor | Service `/i2c_pkg/battery_level` | ✅ |
| 🔋 **Battery (compute)** | Power bank | **Not monitored** (USB, no data pins) | ❌ |
| 📡 **LiDAR** | RPLIDAR optional | Software installed, HW not connected | ⏳ |

---

## I2C Bus Architecture (Scanned with `sudo i2cdetect`)

### Bus 1 — Chasis Core (`/dev/i2c-1`)

```
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- 08 -- -- -- -- -- -- -- 
...
40: -- -- -- -- 44 -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- 5e -- 
```

| Address | Component | Function |
|:-------:|:----------|:---------|
| **0x08** | System controller | Reserved / boot management |
| **0x44** | PWM controller (PCA9685-like) | Receives ROS2 commands → motor PWM + servo angle |
| **0x5e** | Battery ADC | Reads LiPo voltage for `/i2c_pkg/battery_level` |

### Bus 5 — Expansion Bridge (`/dev/i2c-5`)

```
30: -- -- -- -- -- -- -- 37 -- -- 3a -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- 49 -- -- -- -- -- --
50: 50 -- -- -- 54 -- -- -- -- 59 -- -- -- -- -- --
```

Multiple Intel Atom platform interconnect devices (USB controllers, power management, GPIO expanders).

### Bus 0 — Kernel Reserved

`0x55` shown as `UU` (kernel driver active) — possibly RTC or timing.

### Buses 2, 3, 4, 6, 7

Empty / unused.

---

## IMU (Bosch BMI160) — Definitively NOT Present

Scanned all 8 I2C buses for `0x68` and `0x69` (BMI160 addresses):

| Bus | 0x68 | 0x69 |
|:---:|:----:|:----:|
| 0 | -- | -- |
| 1 | -- | -- |
| 2 | -- | -- |
| 3 | -- | -- |
| 4 | -- | -- |
| 5 | -- | -- |
| 6 | -- | -- |
| 7 | -- | -- |

**Conclusion:** AWS removed the IMU from later production runs of the standard DeepRacer to reduce costs. This robot is **purely vision-based** — only the front camera for perception. No inertial sensors available.

---

## ROS2 Architecture

### Topics (7 total — all control, no sensor data)

| Topic | Type | Description |
|-------|------|-------------|
| `/ctrl_pkg/raw_pwm` | ServoCtrlMsg | Motor PWM signal |
| `/ctrl_pkg/servo_msg` | ServoCtrlMsg | Steering servo angle |
| `/deepracer_navigation_pkg/auto_drive` | ServoCtrlMsg | Autonomous driving |
| `/webserver_pkg/manual_drive` | ServoCtrlMsg | Manual drive commands |
| `/webserver_pkg/calibration_drive` | ServoCtrlMsg | Calibration |
| `/parameter_events` | ParameterEvent | ROS2 standard |
| `/rosout` | Log | ROS2 logging |

### Active Nodes

| Node | Package | CPU | Function |
|------|---------|:---:|----------|
| `camera_node` | camera_pkg | 23.8% | Camera capture → MJPEG stream |
| `sensor_fusion_node` | sensor_fusion_pkg | 4.4% | LiDAR overlay (if connected) |
| `web_video_server` | web_video_server | 0.2% | HTTP MJPEG stream on `:8080` |
| `inference_node` | inference_pkg | 0.1% | ML inference |
| `webserver_publisher_node` | webserver_pkg | 0.3% | REST API on `:5001` |
| `ctrl_node` | ctrl_pkg | — | Motor & steering |
| `battery_node` | i2c_pkg | — | Battery monitoring |
| `servo_node` | servo_pkg | — | Servo control |

### Camera Note
The camera does NOT publish a ROS2 topic. It streams MJPEG via HTTP on port 8080 through `web_video_server`. This avoids saturating the ROS2 bus with video data during ML inference.

### No YAML Config Files
Unlike older documentation suggests, there are no `.yaml` config files in `/opt/aws/deepracer/`. Parameters are compiled into nodes or set via the Python launcher (`deepracer_launcher.py`).

---

## LED Control — Rear Strip (Transparent Plate)

The rear LED strip is controlled by a persistent I2C driver. The web server's main loop (~1 Hz) continuously overrides the LED state to show vehicle status (purple = ready/race mode).

### Working Method: High-Frequency ROS2 Loop

Send `SetLedCtrlSrv` commands at 50+ Hz to beat the web server's 1 Hz override loop.

```python
import rclpy, time
from rclpy.node import Node
from deepracer_interfaces_pkg.srv import SetLedCtrlSrv

rclpy.init()
node = Node("led_ctrl")
c1 = node.create_client(SetLedCtrlSrv, "/ctrl_pkg/set_car_led")
c2 = node.create_client(SetLedCtrlSrv, "/servo_pkg/set_led_state")
c1.wait_for_service(3); c2.wait_for_service(3)
r = SetLedCtrlSrv.Request()

def led(red, green, blue, seconds=5, hz=50):
    r.red, r.green, r.blue = red, green, blue
    start = time.time()
    while time.time() - start < seconds:
        c1.call_async(r); c2.call_async(r)
        time.sleep(1.0/hz)
```

### Rainbow Effect
```python
import math
MAX_VAL = 9999825  # Full brightness from led_values.json
t = 0.0
while True:
    red = int(MAX_VAL * (math.sin(t) * 0.5 + 0.5))
    grn = int(MAX_VAL * (math.sin(t + 2.094) * 0.5 + 0.5))
    blu = int(MAX_VAL * (math.sin(t + 4.189) * 0.5 + 0.5))
    r.red, r.green, r.blue = red, grn, blu
    c1.call_async(r); c2.call_async(r)
    t += 0.15; time.sleep(0.01)
```

### Services

| Service | Type | Status |
|---------|------|:------:|
| `/ctrl_pkg/set_car_led` | `SetLedCtrlSrv` | ✅ Works |
| `/ctrl_pkg/get_car_led` | `GetLedCtrlSrv` | ✅ Works |
| `/servo_pkg/set_led_state` | `SetLedCtrlSrv` | ✅ Works |
| `/servo_pkg/get_led_state` | `GetLedCtrlSrv` | ✅ Works |

`SetLedCtrlSrv.Request()` fields: `red`, `green`, `blue` (integers, 0-255 standard but up to 9999825 for full PWM brightness)

---

## Network Ports

| Port | Service | Notes |
|:----:|:--------|:------|
| 22 | SSH | OpenSSH |
| 80 | HTTP | nginx |
| 443 | HTTPS | nginx |
| 5001 | REST API | Flask/Werkzeug (DeepRacer dashboard) |
| 8080 | MJPEG Stream | web_video_server (camera + LiDAR overlay) |
| 8081 | Web aux | — |
| 43282 | Tailscale | `100.117.192.31` |

---

## Access

| Service | Credential |
|---------|-----------|
| **SSH** | `deepracer` / `${DEEPRACER_SSH_PASSWORD}` |
| **Web API** | Password: `${DEEPRACER_API_PASSWORD}` |
| **Hermes Dashboard** | `admin` / `${HERMES_DASHBOARD_BASIC_AUTH_PASSWORD}` on `localhost:9999` |
| **DeepRacer Dashboard** | `http://10.203.150.56:5001/login` |
| **Camera Stream** | `http://10.203.150.56:8080/stream_viewer?topic=/camera_pkg/display_mjpeg` |
| **Camera Snapshot** | `http://10.203.150.56:8080/snapshot?topic=/camera_pkg/display_mjpeg` |

---

## External Hardware (USB/Serial)

Two ESP-family devices were identified. After evaluation, the ESP8266 was removed and only the ESP32 remains.

### Current: ESP32-D0WD-V3 (DevKit V1)

| Detail | Value |
|--------|-------|
| Chip | ESP32-D0WD-V3 rev3.0 |
| USB Bridge | Silicon Labs CP2102 (`10c4:ea60`) |
| Port | `/dev/ttyUSB1` |
| Driver | `cp210x` |
| Features | WiFi + BT Classic + BLE, dual-core 240MHz |
| Flash | 4MB |
| Firmware | **MicroPython v1.28.0** |
| Baud | 115200 |
| Protocol | JSON over serial (`{"event":"..."}`) |
| Sensor | KY-037 sound sensor on GPIO 4 (D4) |

### Removed: ESP8266EX

| Detail | Value |
|--------|-------|
| Chip | ESP8266EX |
| USB Bridge | QinHeng CH340/HL-340 (`1a86:7523`) |
| Port | ~~`/dev/ttyUSB0`~~ (removed) |
| Features | WiFi only, no BT, single-core 80MHz |
| Flash | 4MB |
| Reason removed | Inferior to ESP32 in every way |

### Connection method (DTR/RTS critical!)

```python
import serial
ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=3)
ser.dtr = False    # CRITICAL: DTR causes reset on connect
ser.rts = False    # CRITICAL: RTS causes reset on connect
time.sleep(0.5)
ser.reset_input_buffer()
```

### Flashing firmware

```bash
# esptool must be installed
pip3 install esptool --user
export PATH=$HOME/.local/bin:$PATH

# Erase
python3 -m esptool --port /dev/ttyUSB1 --baud 921600 erase_flash

# Flash MicroPython
python3 -m esptool --port /dev/ttyUSB1 --baud 921600 --chip esp32 write_flash -z 0x1000 firmware.bin
```

## File Locations on Robot

| Path | Purpose |
|------|---------|
| `/opt/aws/deepracer/password.txt` | Web API password hash |
| `/opt/aws/deepracer/token.txt` | UUID device token |
| `/opt/aws/deepracer/calibration.json` | Motor + servo PWM calibration |
| `/opt/aws/deepracer/sensor_configuration.json` | LiDAR config |
| `/opt/aws/deepracer/led_values.json` | RGB LED PWM values (persistent) |
| `/opt/aws/deepracer/start_ros.sh` | ROS2 launch script |
| `/opt/aws/deepracer/lib/deepracer_launcher/` | Main launch configuration |
| `/opt/aws/deepracer/lib/device_console/` | Web UI (HTML/JS/CSS) |
| `/opt/aws/deepracer/lib/deepracer_interfaces_pkg/` | ROS2 service definitions |
| `/opt/aws/deepracer/lib/rplidar_ros/` | LiDAR package (software only) |
| `/opt/aws/deepracer/artifacts/Sample_lidar_stereo_cam/` | Sample ML model (LiDAR + camera) |

---

## Architecture Diagram

```
┌─────────────────────────────────────────────┐
│           DeepRacer Robot                    │
│  ┌───────────────────────────────────────┐   │
│  │        Ubuntu 20.04 / ROS2 Foxy       │   │
│  │                                        │   │
│  │  ┌─────────┐  ┌──────────┐            │   │
│  │  │ camera  │  │ web_video│──:8080──▶ MJPEG │
│  │  │ _node   │  │ _server  │            │   │
│  │  └────▲────┘  └──────────┘            │   │
│  │       │USB                             │   │
│  │  ┌────┴────┐                           │   │
│  │  │ Camera  │  (4MP, /dev/video0/1)     │   │
│  │  └─────────┘                           │   │
│  │                                        │   │
│  │  ┌──────────┐  ┌───────────────┐       │   │
│  │  │ ctrl_pkg │──▶ I2C Bus 1     │       │   │
│  │  │ (ROS2)   │    0x44 → Motor  │       │   │
│  │  │          │    0x44 → Servo  │       │   │
│  │  │          │    0x5E → Bat ADC│       │   │
│  │  └──────────┘  └───────────────┘       │   │
│  │                                        │   │
│  │  ┌──────────┐  ┌───────────────┐       │   │
│  │  │ webserver│──▶ nginx :5001   │       │   │
│  │  │ _publisher│  │ REST API     │       │   │
│  │  └──────────┘  └───────────────┘       │   │
│  │                                        │   │
│  │  ┌─────┐  ┌──────────────┐             │   │
│  │  │i2c  │──▶ Battery LiPo │             │   │
│  │  │_node│  └──────────────┘             │   │
│  │  └─────┘                               │   │
│  │                                        │   │
│  │  ❌ No IMU (BMI160 not soldered)        │   │
│  │  ❌ No LiDAR (HW not connected)         │   │
│  └───────────────────────────────────────┘   │
│                                              │
│  🔋 Power Bank (compute) — NOT monitored     │
│  🔋 LiPo (chassis) — monitored via 0x5E      │
│  💡 Rear LEDs — I2C PWM (purple default)     │
└─────────────────────────────────────────────┘
```
