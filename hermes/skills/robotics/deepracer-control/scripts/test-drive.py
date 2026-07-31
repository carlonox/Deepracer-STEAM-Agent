#!/usr/bin/env python3
"""
test-drive.py — DeepRacer test drive sequence.
API convention: POSITIVE throttle = forward.

Run on robot: python3 /tmp/test-drive.py
Tests: forward → brake → reverse → turn left → turn right → stop
"""

import requests, re, time, sys

ROBOT_URL = "http://localhost:5001"
PASSWORD = __import__("os").environ["DEEPRACER_API_PASSWORD"]
session = requests.Session()


def login():
    r = session.get(f"{ROBOT_URL}/login", timeout=10)
    csrf_match = re.search(r'csrf-token" content="([^"]+)"', r.text)
    if not csrf_match:
        csrf_match = re.search(r'name="csrf_token" value="([^"]+)"', r.text)
    csrf = csrf_match.group(1) if csrf_match else None
    cookie_match = re.search(r'session=([^;]+)', r.headers.get("Set-Cookie", ""))
    cookie = cookie_match.group(1) if cookie_match else None
    print(f"CSRF: {csrf[:20] if csrf else 'None'}...")
    session.post(f"{ROBOT_URL}/login",
                 data={"csrf_token": csrf, "password": PASSWORD},
                 headers={"X-CSRFToken": csrf, "Content-Type": "application/x-www-form-urlencoded",
                          "Cookie": f"session={cookie}"}, timeout=10)
    return csrf, cookie


def headers(csrf, cookie):
    return {"Content-Type": "application/json", "X-Requested-With": "XMLHttpRequest",
            "X-CSRFToken": csrf, "Cookie": f"session={cookie}"}


def drive(angle, throttle, max_speed=1.0):
    session.put(f"{ROBOT_URL}/api/manual_drive",
                json={"angle": angle, "throttle": throttle, "max_speed": max_speed},
                headers=headers(csrf, cookie), timeout=3)


def drive_for(angle, throttle, duration, max_speed=1.0, hz=30):
    label = {True: "FORWARD" if throttle > 0 else "REVERSE"}.get(throttle != 0, "BRAKE/STOP")
    if throttle > 0.01: label = "FORWARD"
    elif throttle < -0.01: label = "REVERSE"
    else: label = "BRAKE/STOP"
    print(f"  [{label}] angle={angle:+0.2f} throttle={throttle:+0.2f} {duration}s...", end=" ", flush=True)
    start, count = time.time(), 0
    while time.time() - start < duration:
        drive(angle, throttle, max_speed)
        time.sleep(1.0 / hz)
        count += 1
    print(f"({count} commands)")


print("=" * 50)
print("🤖 DEEPRACER TEST DRIVE")
print("=" * 50)

csrf, cookie = login()
session.put(f"{ROBOT_URL}/api/drive_mode", json={"drive_mode": "manual"}, headers=headers(csrf, cookie), timeout=5)
session.put(f"{ROBOT_URL}/api/start_stop", json={"start_stop": "start"}, headers=headers(csrf, cookie), timeout=5)

try:
    print("\n🏁 FORWARD (GREEN LED)")
    drive_for(0.0, 0.5, 2.0)
    print("\n✋ BRAKE (ORANGE LED)")
    drive_for(0.0, 0.0, 1.5)
    print("\n⬅️ REVERSE (RED LED)")
    drive_for(0.0, -0.4, 2.0)
    print("\n↩️ FORWARD + LEFT")
    drive_for(-0.5, 0.5, 2.0)
    print("\n↪️ FORWARD + RIGHT")
    drive_for(0.5, 0.5, 2.0)
    print("\n🛑 FULL STOP")
    drive_for(0.0, 0.0, 1.0)
finally:
    session.put(f"{ROBOT_URL}/api/start_stop", json={"start_stop": "stop"}, headers=headers(csrf, cookie), timeout=5)

print("\n✅ Test complete! LED colors: 🟢 Forward | 🔴 Reverse | 🟠 Brake | 🟣 Stopped")
