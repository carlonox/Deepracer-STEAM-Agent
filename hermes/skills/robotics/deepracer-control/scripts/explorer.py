#!/usr/bin/env python3
"""explorer.py — Navegación autónoma v4: retrocede, mira izquierda/derecha, elige mejor ruta"""
import serial, requests, re, time, threading, json, urllib.request, cv2, numpy as np, random

ROBOT_URL = "http://localhost:5001"
PASSWORD = "48AW5fAB"
ESP_PORT = "/dev/ttyUSB0"
CAM_URL = "http://localhost:8080/snapshot?topic=/camera_pkg/display_mjpeg"

state = "idle"; timer = 0; dir_choice = 0; collision_flag = False

def esp_loop():
    global collision_flag
    ser = serial.Serial(ESP_PORT, 115200, timeout=1)
    ser.dtr = False; time.sleep(0.1); ser.rts = False; time.sleep(0.5)
    ser.reset_input_buffer()
    print("[ESP] OK", flush=True)
    while True:
        line = ser.readline()
        if line:
            text = line.decode(errors="replace").strip()
            if "event" in text and '"collision"' in text:
                print(f"[ESP] COLISION! {text}", flush=True)
                if state == "forward": collision_flag = True

threading.Thread(target=esp_loop, daemon=True).start()
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
print("[EXPLORADOR v4] Pausado!", flush=True)

def go(a, t):
    try: session.put(f"{ROBOT_URL}/api/manual_drive", json={"angle":a,"throttle":t,"max_speed":1.0}, headers=h(), timeout=1)
    except: pass

def analyze_view(img):
    h, w = img.shape[:2]; third = w // 3
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    results = {}
    for name, x_start in [("izq",0),("cen",third),("der",2*third)]:
        region = gray[:, x_start:x_start+third]
        m=np.mean(region); s=np.std(region)
        edges=cv2.Canny(region,50,150)
        ed=np.count_nonzero(edges)/(region.shape[0]*region.shape[1])
        blue=cv2.inRange(hsv[:,x_start:x_start+third],np.array([80,20,20]),np.array([145,255,255]))
        bp=np.count_nonzero(blue)/(region.shape[0]*region.shape[1])
        obs = bp > 0.15 or (m < 80 and s < 25) or (s < 30 and m < 140) or ed > 0.20
        results[name] = {"obs": obs, "bright": m}
    return results

def get_camera_view():
    try:
        resp = urllib.request.urlopen(CAM_URL, timeout=1)
        img = cv2.imdecode(np.frombuffer(resp.read(), np.uint8), cv2.IMREAD_COLOR)
        return img if img is not None else None
    except: return None

try:
    while True:
        now = time.time()
        if state == "idle":
            go(0.0, 0.0)
            img = get_camera_view()
            if img is None: state = "forward"; timer = now; continue
            zones = analyze_view(img)
            if zones["cen"]["obs"]:
                print(f"[CAM] Obstaculo centro! Busco salida...", flush=True)
                state = "backup"; timer = now
            elif zones["izq"]["obs"] and not zones["der"]["obs"]:
                state = "forward"; timer = now; dir_choice = 0.3
            elif zones["der"]["obs"] and not zones["izq"]["obs"]:
                state = "forward"; timer = now; dir_choice = -0.3
            else:
                state = "forward"; timer = now; dir_choice = 0.0
        elif state == "forward":
            if now - timer < 0.4: go(dir_choice, -0.30)
            else:
                go(0.0, 0.0); state = "idle"; timer = now
        elif state == "backup":
            if now - timer < 1.5: go(0.0, 0.35)
            elif now - timer < 2.5:
                go(-0.8, 0.0)
                if int((now - timer) * 5) % 3 == 0:
                    img = get_camera_view()
                    if img is not None:
                        z = analyze_view(img)
                        if not z["izq"]["obs"] and not z["cen"]["obs"]:
                            print(f"[NAV] Izquierda libre! Escapo...", flush=True)
                            state = "forward"; timer = now; dir_choice = -0.3
            elif now - timer < 3.5:
                go(0.8, 0.0)
                if int((now - timer) * 5) % 3 == 0:
                    img = get_camera_view()
                    if img is not None:
                        z = analyze_view(img)
                        if not z["der"]["obs"] and not z["cen"]["obs"]:
                            print(f"[NAV] Derecha libre! Escapo...", flush=True)
                            state = "forward"; timer = now; dir_choice = 0.3
            else:
                img = get_camera_view()
                if img is not None:
                    z = analyze_view(img)
                    best = min(z.keys(), key=lambda k: z[k]["obs"])
                    print(f"[NAV] Mejor opcion: {best}", flush=True)
                    dir_choice = -0.3 if best == "izq" else 0.3 if best == "der" else 0.0
                state = "forward"; timer = now
        time.sleep(0.05)
except KeyboardInterrupt:
    pass
finally:
    go(0.0, 0.0)
    session.put(f"{ROBOT_URL}/api/start_stop", json={"start_stop":"stop"}, headers=h())
    print("[EXPLORADOR] Detenido", flush=True)
