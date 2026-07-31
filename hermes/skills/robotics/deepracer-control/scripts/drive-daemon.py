#!/usr/bin/env python3
"""
drive-daemon.py — Real-time drive control for DeepRacer.

Reads commands from /tmp/drive_cmd and continuously sends drive
commands at 30Hz to beat the 200ms watchdog.

⚠️ THROTTLE CONVENTION: This skill's daemon uses POSITIVE = forward
as default, but convention can vary between units and even between
reboots on the same robot (due to motor calibration polarity).
The robot tested in 2026-07 sessions uses NEGATIVE = forward.
ALWAYS test direction before assuming.
If the robot goes backward on 'forward', swap all signs in COMMANDS.

Usage on robot:
  nohup python3 /tmp/drive-daemon.py > /tmp/drive_daemon.log 2>&1 &
  echo "forward" > /tmp/drive_cmd    # Advance
  echo "stop"    > /tmp/drive_cmd    # Stop
"""

import requests
import re
import time
import sys
import signal

ROBOT_URL = "http://localhost:5001"
PASSWORD = __import__("os").environ["DEEPRACER_API_PASSWORD"]
CMD_FILE = "/tmp/drive_cmd"
HZ = 30

COMMANDS = {
    # ⚠️ THROTTLE NORMALIZADO (calibración 2026-07-31): los valores aquí son
    # [0..1] normalizados; cal() los estira al rango real [0.5, 1] del robot
    # (zona muerta ~0.5: 0.45 no mueve, 0.50 sí). 0 sigue siendo parada.
    # ⚠️ Convention varies per robot/reboot. This robot (2026-07): negative=forward
    # If robot goes backward on 'forward', negate ALL throttle signs below.
    # Quick test: echo 'forward' > /tmp/drive_cmd, observe direction.
    "forward": (0.0,  0.30, 1.0),   # real ~0.65
    "fast":    (0.0,  0.70, 1.0),   # real ~0.85
    "back":    (0.0, -0.20, 0.7),   # real ~-0.60
    "left":    (-0.5,  0.30, 1.0),
    "right":   (0.5,  0.30, 1.0),
    "fleft":   (-0.7,  0.30, 1.0),
    "fright":  (0.7,  0.30, 1.0),
    "bleft":   (-0.5, -0.20, 0.7),
    "bright":  (0.5, -0.20, 0.7),
    "brake":   (0.0,  0.0, 0.0),
    "stop":    (0.0,  0.0, 0.0),
}


def cal(t):
    """Calibración de zona muerta: (0, 1] normalizado -> [0.5, 1] real (mismo signo)."""
    if abs(t) < 1e-6:
        return 0.0
    return (1.0 if t > 0 else -1.0) * min(1.0, 0.5 + 0.5 * abs(t))


def login():
    session = requests.Session()
    r = session.get(f"{ROBOT_URL}/login", timeout=10)
    csrf_match = re.search(r'csrf-token" content="([^"]+)"', r.text)
    if not csrf_match:
        csrf_match = re.search(r'name="csrf_token" value="([^"]+)"', r.text)
    csrf = csrf_match.group(1) if csrf_match else None
    cookie_match = re.search(r'session=([^;]+)', r.headers.get("Set-Cookie", ""))
    cookie = cookie_match.group(1) if cookie_match else None
    if not csrf or not cookie:
        print("Login failed: no CSRF/cookie", flush=True)
        sys.exit(1)
    headers = {
        "X-CSRFToken": csrf,
        "Content-Type": "application/x-www-form-urlencoded",
        "Cookie": f"session={cookie}"
    }
    r = session.post(f"{ROBOT_URL}/login",
                     data={"csrf_token": csrf, "password": PASSWORD},
                     headers=headers, timeout=10)
    print(f"Login: {r.status_code}", flush=True)
    return session, csrf, cookie


def api_headers(csrf, cookie):
    return {
        "Content-Type": "application/json",
        "X-Requested-With": "XMLHttpRequest",
        "X-CSRFToken": csrf,
        "Cookie": f"session={cookie}"
    }


def send_drive(session, csrf, cookie, angle, throttle, max_speed):
    try:
        r = session.put(f"{ROBOT_URL}/api/manual_drive",
                        json={"angle": angle, "throttle": cal(throttle), "max_speed": max_speed},
                        headers=api_headers(csrf, cookie),
                        timeout=1)
        return r.status_code == 200
    except Exception:
        return False


def main():
    with open(CMD_FILE, "w") as f:
        f.write("stop")

    session, csrf, cookie = login()
    session.put(f"{ROBOT_URL}/api/drive_mode",
                json={"drive_mode": "manual"},
                headers=api_headers(csrf, cookie), timeout=5)
    print("Manual mode ON", flush=True)
    session.put(f"{ROBOT_URL}/api/start_stop",
                json={"start_stop": "start"},
                headers=api_headers(csrf, cookie), timeout=5)
    print("Motors ON", flush=True)
    print(f"Drive daemon running — echo commands to {CMD_FILE}", flush=True)

    current_cmd = "stop"
    running = True
    interval = 1.0 / HZ

    def shutdown(sig, frame):
        nonlocal running
        running = False

    signal.signal(signal.SIGINT, shutdown)
    signal.signal(signal.SIGTERM, shutdown)

    try:
        while running:
            try:
                with open(CMD_FILE, "r") as f:
                    cmd = f.read().strip()
            except Exception:
                cmd = "stop"

            if cmd != current_cmd:
                print(f"Command: {cmd}", flush=True)
                current_cmd = cmd

            if cmd in COMMANDS:
                angle, throttle, max_speed = COMMANDS[cmd]
                send_drive(session, csrf, cookie, angle, throttle, max_speed)
            else:
                send_drive(session, csrf, cookie, 0.0, 0.0, 0.0)

            time.sleep(interval)
    finally:
        send_drive(session, csrf, cookie, 0.0, 0.0, 0.0)
        time.sleep(0.1)
        session.put(f"{ROBOT_URL}/api/start_stop",
                    json={"start_stop": "stop"},
                    headers=api_headers(csrf, cookie), timeout=5)
        print("\nMotors STOPPED", flush=True)


if __name__ == "__main__":
    main()
