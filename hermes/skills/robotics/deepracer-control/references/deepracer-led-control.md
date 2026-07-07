# 💡 DeepRacer LED Control

## Architecture

The DeepRacer has a **rear LED strip** (the transparent plate at the back with purple LEDs) that is controlled by a persistent I2C driver.

### The Priority Conflict Problem (Why `success: true` doesn't change the color)

The rear LEDs have a **control loop conflict**:

| System | Frequency | Behavior |
|--------|-----------|----------|
| **Web server main loop** | ~1 Hz | Continuously overwrites LEDs to purple ("race mode") |
| **Your ROS2/API command** | One-shot | Hardware changes briefly, then web server reverts it |

This is why `{"success": true}` is returned but no visible change — the web server's loop beats a single command.

### The Solution: High-Frequency Loop

Beat the web server by sending commands at **50-100 Hz**. Your commands arrive more frequently and "win" on the I2C bus.

## Rainbow Animation

A rainbow effect uses three sine waves offset by 120° (2.094 radians). Use the max PWM value (~9999825) for full brightness — the default 255 is very dim.

```python
import math, time

MAX = 9999825  # Full brightness (255 = dim)
t = 0.0
while True:
    req.red   = int(MAX * (math.sin(t)           * 0.5 + 0.5))
    req.green = int(MAX * (math.sin(t + 2.094)    * 0.5 + 0.5))
    req.blue  = int(MAX * (math.sin(t + 4.189)    * 0.5 + 0.5))
    cli.call_async(req); cli2.call_async(req)
    t += 0.15
    time.sleep(0.01)  # ~100 Hz
```

A reusable script is available: `scripts/led-rainbow.sh` (run from SSH: `bash led-rainbow.sh [seconds]`)

## Methods

### Method 1: ROS2 High-Frequency Loop (Recommended)

Using Python with rclpy on the robot:

```python
import rclpy
from rclpy.node import Node
from deepracer_interfaces_pkg.srv import SetLedCtrlSrv
import time

rclpy.init()
node = Node("led_control")
cli = node.create_client(SetLedCtrlSrv, "/ctrl_pkg/set_car_led")
cli2 = node.create_client(SetLedCtrlSrv, "/servo_pkg/set_led_state")
cli.wait_for_service(3)
cli2.wait_for_service(3)

req = SetLedCtrlSrv.Request()

def set_led(red, green, blue, duration=5, hz=50):
    """Set LED color with high-frequency override.
    
    Args:
        red, green, blue: 0-255 (or higher PWM values up to ~9999825)
        duration: seconds to keep the color
        hz: frequency in Hz (50+ recommended to beat the 1 Hz web loop)
    """
    req.red = red
    req.green = green
    req.blue = blue
    
    start = time.time()
    count = 0
    while time.time() - start < duration:
        cli.call_async(req)
        cli2.call_async(req)
        time.sleep(1.0 / hz)
        count += 1
    
    print(f"Sent {count} commands in {duration}s ({count/duration:.0f} Hz)")

# Examples:
set_led(0, 255, 0, 10)        # Green, 10 seconds
set_led(255, 0, 0, 5)         # Red, 5 seconds
set_led(0, 0, 255, 5)         # Blue, 5 seconds
set_led(255, 255, 255, 5)     # White, 5 seconds
set_led(0, 255, 0, float('inf'))  # Keep green forever (loop until interrupted)

node.destroy_node()
rclpy.shutdown()
```

### Method 2: Web API REST

The robot's web UI exposes LED endpoints:

```bash
# Get current LED color
curl -s -b "session=<COOKIE>" http://localhost:5001/api/get_led_color \
  -H "X-Requested-With: XMLHttpRequest" -H "X-CSRFToken: <CSRF>"

# Set LED color (must be called in a high-frequency loop too)
curl -s -b "session=<COOKIE>" -X POST http://localhost:5001/api/set_led_color \
  -H "Content-Type: application/json" \
  -H "X-Requested-With: XMLHttpRequest" \
  -H "X-CSRFToken: <CSRF>" \
  -d '{"red":0,"green":255,"blue":0}'
```

### Method 3: Edit led_values.json (Permanent, needs sudo)

```bash
# Edit the persistent config file
sudo nano /opt/aws/deepracer/led_values.json

# Format:
{
   "Led Values" : {
      "blue_pwm" : 0,
      "green_pwm" : 255,
      "red_pwm" : 0
   }
}

# Restart core service to apply
sudo systemctl restart aws-deepracer-core
```

### Method 4: Stop deepracer-core (Disables web server override)

```bash
sudo systemctl stop deepracer-core.service
# LEDs will stay at whatever you set via ROS2
# Note: Web console will stop working
```

## ROS2 Services for LED Control

| Service | Type | Notes |
|---------|------|-------|
| `/ctrl_pkg/set_car_led` | `SetLedCtrlSrv` | Primary control — works! |
| `/ctrl_pkg/get_car_led` | `GetLedCtrlSrv` | Returns current state |
| `/servo_pkg/set_led_state` | `SetLedCtrlSrv` | Same type, same effect |
| `/servo_pkg/get_led_state` | `GetLedCtrlSrv` | Returns current state |

Request fields: `red`, `green`, `blue` (integers, 0-255 standard range)

Common PWM values from `led_values.json`:
- Purple: red=9999825, green=0, blue=9999825
- These values are hardware-specific PWM register values

## Colors and Values

| Color | Red | Green | Blue |
|-------|-----|-------|------|
| Red | 255 | 0 | 0 |
| Green | 0 | 255 | 0 |
| Blue | 0 | 0 | 255 |
| Yellow | 255 | 255 | 0 |
| Cyan | 0 | 255 | 255 |
| Purple/Magenta | 255 | 0 | 255 |
| White | 255 | 255 | 255 |
| Off | 0 | 0 | 0 |

## Requirements

Run from SSH on the robot, with ROS2 environment sourced:
```bash
source /opt/ros/foxy/setup.bash
source /opt/aws/deepracer/lib/setup.bash
```
