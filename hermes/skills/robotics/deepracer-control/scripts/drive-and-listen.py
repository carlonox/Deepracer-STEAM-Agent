#!/usr/bin/env python3
"""
drive_and_listen.py - Drives DeepRacer while reading ESP32 KY-037 sound sensor.
Monitors motor noise / collision events during movement.

Usage: python3 drive_and_listen.py  (run on the robot)
"""

import serial, requests, re, time, sys, threading

ROBOT_URL = "http://localhost:5001"
PASSWORD = __import__("os").environ["DEEPRACER_API_PASSWORD"]
ESP_PORT = "/dev/ttyUSB0"
BAUD = 115200

esp_data = []
esp_lock = threading.Lock()

def read_esp():
    try:
        ser = serial.Serial(ESP_PORT, BAUD, timeout=1)
        ser.dtr = False; time.sleep(0.1); ser.rts = False; time.sleep(0.5)
        ser.reset_input_buffer()
        print("[ESP32] Connected", flush=True)
        while True:
            line = ser.readline()
            if line:
                text = line.decode(errors="replace").strip()
                if text:
                    with esp_lock:
                        esp_data.append((time.time(), text))
                    print(f"[ESP] {text}", flush=True)
    except Exception as e:
        print(f"[ESP] Error: {e}", flush=True)

threading.Thread(target=read_esp, daemon=True).start()
time.sleep(1)

# Login
s = requests.Session()
r = s.get(f"{ROBOT_URL}/login", timeout=10)
csrf = re.search(r'csrf-token" content="([^"]+)"', r.text).group(1)
cookie = re.search(r'session=([^;]+)', r.headers.get("Set-Cookie", "")).group(1)
s.post(f"{ROBOT_URL}/login",
    data={"csrf_token": csrf, "password": PASSWORD},
    headers={"X-CSRFToken": csrf, "Content-Type": "application/x-www-form-urlencoded",
             "Cookie": f"session={cookie}"}, timeout=10)

def h():
    return {"Content-Type": "application/json", "X-Requested-With": "XMLHttpRequest",
            "X-CSRFToken": csrf, "Cookie": f"session={cookie}"}

s.put(f"{ROBOT_URL}/api/drive_mode", json={"drive_mode": "manual"}, headers=h(), timeout=5)
s.put(f"{ROBOT_URL}/api/start_stop", json={"start_stop": "start"}, headers=h(), timeout=5)

def drive(angle, throttle, ms=1.0):
    s.put(f"{ROBOT_URL}/api/manual_drive", json={"angle": angle, "throttle": throttle, "max_speed": ms}, headers=h(), timeout=2)

def drive_for(angle, throttle, duration, hz=20):
    label = "FORWARD" if throttle > 0.01 else ("REVERSE" if throttle < -0.01 else "BRAKE")
    print(f"\n[{label}] thr={throttle} {duration}s...", flush=True)
    start = time.time()
    while time.time() - start < duration:
        drive(angle, throttle)
        time.sleep(1.0 / hz)

try:
    drive_for(0.0, 0.3, 3.0)     # Slow forward
    drive_for(0.0, 0.0, 2.0)     # Stop
    drive_for(-0.3, 0.3, 2.0)    # Left
    drive_for(0.3, 0.3, 2.0)     # Right
    drive_for(0.0, 0.0, 1.0)     # Stop
    drive_for(0.0, -0.2, 2.0)    # Reverse
    drive_for(0.0, 0.0, 1.0)     # Stop
finally:
    s.put(f"{ROBOT_URL}/api/start_stop", json={"start_stop": "stop"}, headers=h(), timeout=5)

print("\n=== ESP32 EVENTS ===")
with esp_lock:
    for ts, line in esp_data:
        print(f"  [{time.strftime('%H:%M:%S', time.localtime(ts))}] {line}")
print(f"Total: {len(esp_data)} events")
