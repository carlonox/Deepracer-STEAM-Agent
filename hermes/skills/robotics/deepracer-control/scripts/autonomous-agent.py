#!/usr/bin/env python3
"""autonomous-agent.py — Clap-controlled autonomous driving for DeepRacer.

Behaviour:
- IDLE: waits for clap patterns via ESP32 + KY-037 sound sensor
- 1 clap (within 0.8s gap)  → forward 1s
- 2 claps (within 0.8s)     → turn right 0.8s
- 3 claps (within 0.8s)     → turn left 0.8s
- collision while moving    → stop, reverse, turn, return to IDLE

⚠️ Throttle convention: negative=forward on this robot (polarity: -1).
Test with throttle=+0.3 / -0.3 if unsure.

Start on robot:
  nohup python3 /tmp/autonomous-agent.py > /tmp/agent.log 2>&1 &

Pair with brake LED:
  source /opt/ros/foxy/setup.bash; source /opt/aws/deepracer/lib/setup.bash
  nohup python3 /tmp/brake-led.py > /tmp/brake_led.log 2>&1 &
"""
import serial, requests, re, time, threading

ROBOT_URL = "http://localhost:5001"
PASSWORD = "48AW5fAB"
ESP_PORT = "/dev/ttyUSB0"
PATTERN_GAP = 0.8  # max seconds between claps for multi-clap pattern

state = "idle"
clap_count = 0
last_clap = 0

def esp():
    global clap_count, last_clap
    ser = serial.Serial(ESP_PORT, 115200, timeout=1)
    ser.dtr = False; time.sleep(0.1); ser.rts = False; time.sleep(0.5)
    ser.reset_input_buffer()
    print("[ESP] OK", flush=True)
    while True:
        line = ser.readline()
        if line:
            text = line.decode(errors="replace").strip()
            if "event" in text and '"clap"' in text:
                now = time.time()
                if now - last_clap > PATTERN_GAP:
                    clap_count = 1  # new pattern
                else:
                    clap_count += 1  # same pattern
                last_clap = now
                print(f"[SENSOR] clap #{clap_count}", flush=True)

threading.Thread(target=esp, daemon=True).start()
time.sleep(2)

session = requests.Session()
r = session.get(f"{ROBOT_URL}/login", timeout=10)
csrf = re.search(r'csrf-token" content="([^"]+)"', r.text).group(1)
ck = re.search(r'session=([^;]+)', r.headers.get("Set-Cookie", "")).group(1)
session.post(f"{ROBOT_URL}/login",
    data={"csrf_token": csrf, "password": PASSWORD},
    headers={"X-CSRFToken": csrf, "Content-Type": "application/x-www-form-urlencoded", "Cookie": f"session={ck}"})

h = lambda: {"Content-Type":"application/json","X-Requested-With":"XMLHttpRequest","X-CSRFToken":csrf,"Cookie":f"session={ck}"}
session.put(f"{ROBOT_URL}/api/drive_mode", json={"drive_mode":"manual"}, headers=h())
session.put(f"{ROBOT_URL}/api/start_stop", json={"start_stop":"start"}, headers=h())
print("[AGENTE] 1👏=ade 2👏=der 3👏=izq", flush=True)

def go(a, t):
    try: session.put(f"{ROBOT_URL}/api/manual_drive", json={"angle":a,"throttle":t,"max_speed":1.0}, headers=h(), timeout=1)
    except: pass

timer = 0
processed = 0
try:
    while True:
        now = time.time()
        # Detect completed clap pattern: no new clap for >PATTERN_GAP+0.3s
        if state == "idle" and clap_count > 0 and now - last_clap > PATTERN_GAP + 0.3:
            if clap_count != processed:
                processed = clap_count
                if clap_count == 1: state = "forward"; timer = 0; print("[AGENTE] 👏 Adelante!", flush=True)
                elif clap_count == 2: state = "turn_right"; timer = 0; print("[AGENTE] 👏👏 Derecha!", flush=True)
                elif clap_count >= 3: state = "turn_left"; timer = 0; print("[AGENTE] 👏👏👏 Izquierda!", flush=True)
                clap_count = 0
        if state == "forward":
            if timer == 0: timer = now
            if now - timer > 1.0: state = "idle"; timer = 0; processed = 0; print("[AGENTE] Listo!", flush=True)
            else: go(0.0, -0.35)  # negative = forward
        elif state == "turn_right":
            if timer == 0: timer = now
            if now - timer > 0.8: state = "idle"; timer = 0; processed = 0; print("[AGENTE] Listo!", flush=True)
            else: go(0.6, -0.3)
        elif state == "turn_left":
            if timer == 0: timer = now
            if now - timer > 0.8: state = "idle"; timer = 0; processed = 0; print("[AGENTE] Listo!", flush=True)
            else: go(-0.6, -0.3)
        else: go(0.0, 0.0)
        time.sleep(0.05)
except KeyboardInterrupt:
    pass
finally:
    go(0.0, 0.0)
    session.put(f"{ROBOT_URL}/api/start_stop", json={"start_stop":"stop"}, headers=h())
