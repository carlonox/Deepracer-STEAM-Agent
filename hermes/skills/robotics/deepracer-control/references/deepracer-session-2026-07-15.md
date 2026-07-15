# Session 2026-07-15 — DeepRacer: Explorer v5, Persistent Firewall, Camera Debug, No Wiggles

## Duration
~3 hours. Multiple robot reboots.

## Key Achievements

### 1. Post-Reboot Checklist (Firewall + Time)
- Tailscale SSH+API fails after reboot because: (1) clock resets (no RTC battery), breaking Tailscale mTLS, (2) iptables DROP policy blocks Tailscale subnet
- **Fix**: `sudo iptables -I INPUT 1 -s 100.0.0.0/8 -j ACCEPT` + `sudo iptables-save | sudo tee /etc/iptables/rules.v4`
- **Fix**: `sudo ntpdate -u pool.ntp.org` for time sync, added `@reboot` cron for auto-sync
- **Both must be done every reboot** — documented as the "Post-Reboot Checklist"

### 2. Explorer v5 — Simplified, No Wiggles, Long Strokes
- **No more "look left"/"look right" phases**: previous v4 had backup→look_left(1s, steer only)→look_right(1s, steer only)→escape, which wiggled wheels without moving the robot
- **Unified backup-turn**: backup reverse 1.5s (throttle +0.40) → reverse-turn 1.5s (angle ±0.8, throttle -0.30) → escape
- **6s forward segments** at throttle -0.55 (replace 1.5s segments which felt like "tiny steps")
- **8s forced advance** after escape (ignore camera for 8s to ensure robot clears the obstacle area)
- **Random turn direction** on each escape

### 3. Gray Floor Fix (HSV Saturation > 50)
- **Root cause of "Obstaculo centro!" on empty floor**: HSV range [80,20,20]-[145,255,255] with S>=20 detected gray floor at 29% blue coverage
- **Fix**: require S>=50 (`np.array([80,50,30])`). Gray floors now measure 0-2% blue
- **Diagnostic**: run `cam_debug.py` on robot to see actual blue%, bright, std, edges

### 4. Camera Debug Logging
- Explorer now logs: `[CAM] b=139 s=19 e=6% blue=0% obs=False` every cycle
- User can view camera stream at `http://<TailscaleIP>:8080/stream_viewer?topic=/camera_pkg/display_mjpeg`
- Combined camera stream + logs enables user-described debugging

### 5. Tailscale Boot Persistence
- Installed `iptables-persistent` so firewall rules survive reboot
- Added cron `@reboot sleep 30 && sudo ntpdate -u pool.ntp.org` for time sync
- Both run automatically on boot after 30s delay

## Files Created/Updated
- `/opt/data/home/explorer.py` — v6 explorer with skip counter (v5→v6 during session)
- `/opt/data/home/cam_debug.py` — camera diagnostics script
- `/opt/data/skills/robotics/deepracer-control/scripts/explorer.py` — saved to skill
- `/opt/data/skills/robotics/deepracer-control/references/deepracer-session-2026-07-15.md` — this file

## Critical Incidents (2026-07-15)

### Wall Crash (throttle=-0.75)
The agent set throttle=-0.75 in the explorer (v6 experiment) and the robot accelerated into a wall at full speed. The 160x120 camera could not detect the wall in time. This was a preventable accident caused by:
- Increasing throttle without considering the camera's limited range
- Using 10s forward segments at high speed (no time to react)
- No supervision requirement baked into the throttle change

**Lesson:** Autonomous throttle must never exceed -0.50 without explicit user request and supervision. Default is -0.35. Added as a dedicated SAFETY section in the skill.

### Daemon/Explorer Conflict (Robot Convulsing)
The robot appeared to convulse instead of driving smoothly. The cause was running the drive daemon AND the explorer simultaneously. The daemon sent "stop" commands (from empty command file) at 30Hz while the explorer sent "forward" at 20Hz, causing motors to oscillate between forward and stop.

**Lesson:** Never run daemon + explorer at same time. Kill all processes before starting either. Added as a pitfall in Common Issues.
