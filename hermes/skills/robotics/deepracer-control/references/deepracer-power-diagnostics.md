# ⚡ DeepRacer Power Architecture & I2C Diagnostics

## Two Power Systems (CRITICAL — Not Obvious)

The DeepRacer has **two independent power systems** that must both be active for movement:

| System | Powers | Connector | Monitored? |
|--------|--------|-----------|:----------:|
| 💻 **Compute** | Ubuntu, ROS2, WiFi, camera, LEDs | USB-C (power bank or wall charger) | ❌ Not monitored (standard USB, no data pins) |
| ⚡ **Motors** | Drive motor + steering servo | White 2-pin connector (LiPo battery) | ✅ I2C bus 1, address `0x5E` (`/i2c_pkg/battery_level`) |

**Common misconception:** The purple LED being on means power is OK. It only means the compute module is running. The motors can be completely unpowered while the purple LED glows and the web API returns `{"success": true}`.

## Physical Motor Enable Button

On the main circuit board (near the battery connector) there's a **small tactile push button** that acts as a hardware safety interlock. It must be pressed after every boot for the motors to receive power.

**Without pressing this button:**
- `PUT /api/drive_mode` → `{"success": true}` ✅
- `PUT /api/start_stop` → `{"success": true}` ✅  
- `PUT /api/manual_drive` → `{"success": true}` ✅
- Physical motors → **nothing** ❌

## I2C Bus as a Diagnostic Tool

The I2C bus 1 is the **primary diagnostic interface** for motor power. All peripheral chips live on this bus:

| Address | Component | What it means if missing |
|:-------:|:----------|:------------------------|
| `0x08` | System controller | Core board communication |
| `0x44` | PWM motor controller | **Motors won't move** — this chip converts ROS2 commands to PWM signals |
| `0x5E` | Battery ADC | Battery monitoring unavailable |

### Healthy bus (expected):
```
$ sudo i2cdetect -y 1
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- 08 -- -- -- -- -- -- -- 
...
40: -- -- -- -- 44 -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- 5e --
```

### Dead bus (diagnostic — all devices missing):
```
$ sudo i2cdetect -y 1
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:                                                 
...
40:                                                 
...
70:                                                 
```

**If the bus is empty, reboot is the fix.** This is not a kernel panic or driver error — the I2C bus controller on the Intel Atom board enters a state where it can't enumerate the peripherals. This can happen after repeated ROS2 launcher restarts or after power-cycling the compute module without proper shutdown.

### Diagnostic script (run via SSH):

```bash
sudo i2cdetect -y 1
```

If bus 1 shows no devices and `ls /dev/i2c-*` shows the device nodes exist, the bus is hung. Reboot the robot:

```bash
sudo reboot
```

The robot takes ~2 minutes to boot. After reboot, re-check `sudo i2cdetect -y 1` to confirm the peripherals are back.

## Quick Diagnostic Flowchart

```
Robot doesn't move?

1. Does the web API return {"success": true}?
   ├── No → Debug CSRF login, network, firewall
   └── Yes → Continue

2. Is the LiPo battery connected (white 2-pin)?
   ├── No → Connect LiPo battery  
   └── Yes → Continue

3. Is the motor enable button pressed (on main board)?
   ├── No → Press it
   └── Yes → Continue

4. Check I2C bus 1: sudo i2cdetect -y 1
   ├── Shows 0x44 and 0x5E → Hardware OK, check throttle convention
   │   (Web API: positive = forward. See deepracer-control SKILL.md)
   └── Empty bus → Reboot robot (sudo reboot)
```

## Robot Web Dashboard Access

The dashboard has a two-tier architecture that confuses first-time users:

```
Browser → http://<IP>/ → nginx port 80
                            └─ redirect to port 443 (HTTPS)
Browser → https://<IP>/ → nginx port 443
                            ├─ serves CSS/JS/images from disk
                            └─ proxies API to Flask on port 5001
```

**Correct URL:** `https://10.203.150.56/` (accept self-signed cert warning)
**Wrong URL:** `http://10.203.150.56:5001/` (loads HTML but all CSS/JS return 404)

The stock React dashboard (`bundle.js`, 4.5MB) often crashes in offline mode — it's compiled for AWS cloud. If it shows a blank page at `/home`, don't debug it. Use the SSH-based drive daemon instead (see `scripts/drive-daemon.py`).
