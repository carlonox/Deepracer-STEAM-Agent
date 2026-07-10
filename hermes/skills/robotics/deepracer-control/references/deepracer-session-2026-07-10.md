# Session 2026-07-10 — DeepRacer Complete Session Log

## Duration
~4 hours. Robot battery died twice (LiPo + compute USB).

## Physical Events
- Robot placed on floor with obstacles: blue suitcase (right), box (left), chairs, wall ahead
- Robot got stuck between two chair legs (physically wedged, wheels spinning)
- Robot pushed blue suitcase repeatedly (camera didn't detect blue early enough)
- LiPo disconnected/reconnected twice to recover from I2C bus hang
- Physical motor enable button pressed multiple times

## Major Fixes Applied

### Throttle Convention
- **Confirmed: negative = forward** on this robot (web API)
- Convention can flip after reboot — ALWAYS test
- Updated all scripts: `drive_daemon.py`, `explorer_v4.py`, `brake_led_node.py`

### Brake LED Node (v8)
- Switched from file-based to topic subscription (`/webserver_pkg/manual_drive`)
- ROS2 CLI daemon reports 0 publishers but DDS works
- Fire-and-forget `call_async()` at 100Hz
- `spin_once(0.05)` for DDS delivery
- MAX_PWM = 9999825

### ESP32
- Port changed to `/dev/ttyUSB0` after reboot
- DTR/RTS=False required
- Motor noise generates `clap` events (17-47s) — ignore during movement
- Only react to `collision` events for navigation

### Camera
- OpenCV 4.13.0 installed
- HSV blue detection: wider range [80,20,20]-[145,255,255], sat>60 avoids gray
- Edge density + brightness + color = obstacle triage
- Fast snapshot (timeout=0.1s) for stuck detection during movement

### Explorer (v1→v4)
- v4: smart escape algorithm - backup 1.5s, look left, look right, choose best path
- Stuck detection via frame comparison (diff < 3)
- Camera timeout bug fixed (was 2s, blocking 0.5s movement)
- State overwrite bug fixed (check_stuck vs forward else block)
- 0.4s segments at throttle -0.30 (slow and steady)

## Files to Check Next Session
- `/tmp/explorer_v4.py` — latest explorer
- `/tmp/brake_led_node.py` — latest LED node
- `/tmp/drive_daemon.py` — drive daemon
- `/tmp/esp_monitor.py` — ESP32 logger
- `/opt/data/home/session_2026-07-10.md` — this log
