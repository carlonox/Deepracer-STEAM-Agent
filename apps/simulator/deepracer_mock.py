#!/usr/bin/env python3
"""
DeepRacer STEAM Agent — Simulador del DeepRacer (mock de la API web).

Emula el contrato de la API web del AWS DeepRacer documentada en:
- apps/backend/vehicleControl.js (cliente real que lo consume)
- docs/operations/GUIA_SETUP.md (sección 6: API Web Directa)
- docs/operations/HANDOFF.md (movimiento REST)
- hermes/skills/robotics/deepracer-control/SKILL.md (login CSRF, watchdog,
  calibraciones, mediciones en vivo 2026-07-31)
- docs/archive/SpeedRacerv.2 (iteración anterior: CSRF también en cookie
  de sesión, POST /api/* con body drive_control)

Lo que emula (fidelidad al hardware real):
- Login CSRF: GET /login (token en HTML y en cookie de sesión base64url),
  POST /login valida password + csrf_token, Set-Cookie de sesión autenticada.
- Endpoints PUT y POST: /api/drive_mode, /api/start_stop, /api/manual_drive,
  /api/set_led_color, /api/get_led_color. Respuestas {"success": true}.
- Watchdog de ~200 ms: sin comando nuevo en la ventana, los motores se
  apagan (igual que el robot real — el loop síncrono muere de hambre).
- Dead zone del throttle ~0.5 (|t| < DZ no mueve; el backend real estira
  el rango [-1,1] a [DZ,1] antes de enviar).
- Velocidades reales medidas: ~0.87 m/s al mínimo que mueve (~0.55 real),
  máx ~2 m/s al máximo; curva aproximada lineal entre puntos medidos.
- Servo ultra sensible: yaw_rate ≈ angle * 380 °/s (giro de 90° en ~2.2 s
  con angle=0.11 medido en el robot real).
- Convención de throttle configurable: SIM_THROTTLE_SIGN=-1 (negativo =
  adelante, verificado 2026-07-31) y puede voltearse para simular el
  "cambia entre reboots" del hardware.
- Batería: decae con el uso; la dead zone efectiva crece con batería baja
  (como se observó en el robot).
- Streams: GET /route?topic=... en HTTPS :5001 (lo que usa el backend),
  stream_viewer/snapshot en HTTP :8080 (web_video_server). Los frames se
  generan con OpenCV si está disponible; si no, con un generador PNG puro
  de la stdlib (cero dependencias).
- Login y dashboard HTML en HTTPS :5001 (login + home con cámara integrada).

Lo que NO emula (documentado en README.md):
- ROS2, nginx, SSH, ESP32/UDP, LiDAR, IMU (no existe en el hardware).

Uso:
    python3 deepracer_mock.py                 # HTTPS :5001 + HTTP :8080
    # Variables (todas opcionales):
    #   DEEPRACER_API_PASSWORD (por defecto "deepracer")
    #   DEEPRACER_API_PORT (5001), MOCK_HTTP_PORT (8080)
    #   THROTTLE_DEAD_ZONE (0.5), STRAIGHT_ANGLE_OFFSET (0)
    #   SIM_THROTTLE_SIGN (-1), SIM_WATCHDOG_MS (200), SIM_BATTERY_DRAIN (0.5 %/min)
    #   SIM_CERT_DIR (certs/ junto al script)
"""

import base64
import json
import math
import os
import re
import secrets
import ssl
import struct
import subprocess
import sys
import threading
import time
import urllib.parse
import zlib
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

# --------------------------------------------------------------------------
# Configuración
# --------------------------------------------------------------------------
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

API_PASSWORD = os.environ.get("DEEPRACER_API_PASSWORD", "deepracer")
HTTPS_PORT = int(os.environ.get("DEEPRACER_API_PORT", "5001"))
HTTP_PORT = int(os.environ.get("MOCK_HTTP_PORT", "8080"))
DEAD_ZONE = max(0.0, min(0.95, float(os.environ.get("THROTTLE_DEAD_ZONE", "0.5"))))
ANGLE_OFFSET = max(-1.0, min(1.0, float(os.environ.get("STRAIGHT_ANGLE_OFFSET", "0"))))
THROTTLE_SIGN = int(os.environ.get("SIM_THROTTLE_SIGN", "-1"))  # -1: negativo=adelante
WATCHDOG_MS = int(os.environ.get("SIM_WATCHDOG_MS", "200"))
BATTERY_DRAIN_PER_MIN = float(os.environ.get("SIM_BATTERY_DRAIN", "0.5"))
CERT_DIR = os.environ.get("SIM_CERT_DIR", os.path.join(SCRIPT_DIR, "certs"))
CERT_FILE = os.path.join(CERT_DIR, "server.crt")
KEY_FILE = os.path.join(CERT_DIR, "server.key")

# Constantes medidas en el robot real (2026-07-31)
MIN_MOVING_THROTTLE = 0.55       # real mínimo que mueve
MIN_SPEED_MS = 0.87              # m/s al mínimo que mueve
MAX_SPEED_MS = 2.0               # m/s estimado al máximo
SERVO_GAIN_DEG_PER_S = 380.0     # °/s de giro por unidad de angle

# --------------------------------------------------------------------------
# Estado simulado
# --------------------------------------------------------------------------
class SimState:
    def __init__(self):
        self.lock = threading.Lock()
        self.drive_mode = "manual"     # /api/drive_mode
        self.start_stop = "stop"       # /api/start_stop
        self.motors_on = False         # estado físico derivado (watchdog)
        self.angle = 0.0
        self.throttle = 0.0
        self.max_speed = 0.0
        self.last_cmd_at = 0.0         # time.monotonic() del último comando
        self.cmd_count = 0             # comandos manual_drive recibidos
        self.battery = 100.0           # %
        self.led = {"red": 255, "green": 0, "blue": 255}  # púrpura default
        # pose en el mundo simulado (metros, radianes)
        self.x = 0.0
        self.y = 0.0
        self.heading = 0.0
        # telemetría
        self.speed_ms = 0.0
        self.cmd_hz = 0.0
        self._cmd_window = []          # timestamps para medir Hz
        self.reset_reason = ""

    # -- helpers --
    def effective_dead_zone(self):
        """La dead zone crece con batería baja (observado en el robot real)."""
        return DEAD_ZONE * (1.0 + (1.0 - self.battery / 100.0) * 0.25)

    def motor_should_be_on(self):
        if self.start_stop != "start":
            return False
        if time.monotonic() - self.last_cmd_at > WATCHDOG_MS / 1000.0:
            return False
        return True

    def apply_command(self, angle, throttle, max_speed):
        with self.lock:
            self.angle = max(-1.0, min(1.0, float(angle)))
            self.throttle = max(-1.0, min(1.0, float(throttle)))
            self.max_speed = max(0.0, min(1.0, float(max_speed)))
            self.last_cmd_at = time.monotonic()
            self.cmd_count += 1
            now = time.monotonic()
            self._cmd_window.append(now)
            self._cmd_window = [t for t in self._cmd_window if now - t < 2.0]
            self.cmd_hz = len(self._cmd_window) / 2.0

    def compute_speed(self):
        """Velocidad real (m/s) con la curva aproximada del robot medido."""
        t = abs(self.throttle)
        dz = self.effective_dead_zone()
        if t < dz or not self.motors_on:
            return 0.0
        if t <= MIN_MOVING_THROTTLE:
            v = MIN_SPEED_MS * (t / MIN_MOVING_THROTTLE)
        else:
            frac = (t - MIN_MOVING_THROTTLE) / (1.0 - MIN_MOVING_THROTTLE)
            v = MIN_SPEED_MS + frac * (MAX_SPEED_MS - MIN_SPEED_MS)
        return v * self.max_speed

    def state_snapshot(self):
        with self.lock:
            return {
                "drive_mode": self.drive_mode,
                "start_stop": self.start_stop,
                "motors_on": self.motors_on,
                "angle": self.angle,
                "throttle": self.throttle,
                "max_speed": self.max_speed,
                "cmd_count": self.cmd_count,
                "cmd_hz": round(self.cmd_hz, 1),
                "battery": round(self.battery, 1),
                "dead_zone_effective": round(self.effective_dead_zone(), 3),
                "led": dict(self.led),
                "x": round(self.x, 3),
                "y": round(self.y, 3),
                "heading_deg": round(math.degrees(self.heading) % 360.0, 1),
                "speed_ms": round(self.speed_ms, 3),
                "watchdog_ms": WATCHDOG_MS,
                "throttle_sign": THROTTLE_SIGN,
                "reset_reason": self.reset_reason,
                "last_cmd_age_ms": int((time.monotonic() - self.last_cmd_at) * 1000)
                if self.last_cmd_at else 0,
            }


STATE = SimState()

# --------------------------------------------------------------------------
# CSRF y sesiones (fiel al contrato: csrf en HTML y en cookie base64url)
# --------------------------------------------------------------------------
def b64url(data: bytes) -> str:
    return base64.urlsafe_b64encode(data).rstrip(b"=").decode()


def b64url_decode(s: str) -> bytes:
    pad = "=" * (-len(s) % 4)
    return base64.urlsafe_b64decode(s + pad)


def make_session_cookie(csrf: str, authed: bool) -> str:
    payload = {"csrf_token": csrf, "authed": authed}
    return b64url(json.dumps(payload).encode())


def parse_session(cookie_header: str):
    """Devuelve (csrf, authed) desde la cookie session, o (None, False).

    NOTA: algunos clientes (vehicleControl.js) combinan las cookies del
    GET /login y del POST /login en un solo header ("session=A; session=B").
    El robot real usa la cookie actualizada (la última). Tomamos la última
    aparición, igual que hace el servidor Flask real.
    """
    matches = re.findall(r"session=([^;]+)", cookie_header or "")
    if not matches:
        return None, False
    for raw in reversed(matches):
        try:
            payload = json.loads(b64url_decode(raw).decode())
            return payload.get("csrf_token"), bool(payload.get("authed"))
        except Exception:
            continue
    return None, False


CSRF_TOKENS = {}     # token -> expiry monotonic
CSRF_TTL = 600.0

def new_csrf() -> str:
    token = secrets.token_urlsafe(24)
    CSRF_TOKENS[token] = time.monotonic() + CSRF_TTL
    return token


def csrf_valid(token) -> bool:
    if not token or token not in CSRF_TOKENS:
        return False
    if time.monotonic() > CSRF_TOKENS[token]:
        CSRF_TOKENS.pop(token, None)
        return False
    return True

# --------------------------------------------------------------------------
# Física del mundo simulado (thread)
# --------------------------------------------------------------------------
def physics_loop():
    tick = 0.05  # 20 Hz
    while True:
        time.sleep(tick)
        with STATE.lock:
            now = time.monotonic()
            # Watchdog: cortar motores si no llegan comandos
            if STATE.motors_on and STATE.start_stop == "start":
                if now - STATE.last_cmd_at > WATCHDOG_MS / 1000.0:
                    STATE.motors_on = False
                    STATE.reset_reason = "watchdog"
            # Arranque de motores (aparece tras drive_mode+start+comando)
            if STATE.start_stop == "start" and now - STATE.last_cmd_at <= WATCHDOG_MS / 1000.0:
                STATE.motors_on = True
            # Integración de la pose
            v = STATE.compute_speed()
            STATE.speed_ms = v
            if v != 0.0:
                if THROTTLE_SIGN == -1:
                    direction = 1.0 if STATE.throttle < 0 else -1.0
                else:
                    direction = 1.0 if STATE.throttle > 0 else -1.0
                effective_angle = STATE.angle + ANGLE_OFFSET
                yaw_rate = math.radians(effective_angle * SERVO_GAIN_DEG_PER_S)
                dt = tick
                STATE.heading += yaw_rate * dt
                STATE.x += v * direction * math.cos(STATE.heading) * dt
                STATE.y += v * direction * math.sin(STATE.heading) * dt
                # batería (solo con motores activos)
                STATE.battery = max(0.0, STATE.battery - BATTERY_DRAIN_PER_MIN * (dt / 60.0))
                if STATE.battery <= 0.0:
                    STATE.motors_on = False
                    STATE.reset_reason = "battery"

# --------------------------------------------------------------------------
# Generación de frames: OpenCV si está, PNG puro de la stdlib si no.
# --------------------------------------------------------------------------
try:
    import cv2
    import numpy as np
    HAVE_CV = True
except ImportError:
    HAVE_CV = False

CURRENT_FRAME = None          # bytes del último frame (JPEG con cv2, PNG sin cv2)
CURRENT_MIME = "image/jpeg"
FRAME_LOCK = threading.Lock()


# --- pequeño renderer PNG sin dependencias (solo stdlib) ---
_GLYPHS = {
    '0': ("###", "#.#", "#.#", "#.#", "###"),
    '1': ("..#", "..#", "..#", "..#", "..#"),
    '2': ("###", "..#", "###", "#..", "###"),
    '3': ("###", "..#", "###", "..#", "###"),
    '4': ("#.#", "#.#", "###", "..#", "..#"),
    '5': ("###", "#..", "###", "..#", "###"),
    '6': ("###", "#..", "###", "#.#", "###"),
    '7': ("###", "..#", "..#", "..#", "..#"),
    '8': ("###", "#.#", "###", "#.#", "###"),
    '9': ("###", "#.#", "###", "..#", "###"),
    'A': ("###", "#.#", "###", "#.#", "#.#"),
    'B': ("##.", "#.#", "##.", "#.#", "##."),
    'C': ("###", "#..", "#..", "#..", "###"),
    'D': ("##.", "#.#", "#.#", "#.#", "##."),
    'F': ("###", "#..", "##.", "#..", "#.."),
    'H': ("#.#", "#.#", "###", "#.#", "#.#"),
    'I': ("###", "..#", "..#", "..#", "###"),
    'L': ("#..", "#..", "#..", "#..", "###"),
    'M': ("#.#", "###", "###", "#.#", "#.#"),
    'N': ("#.#", "##.", "#.#", "#.#", "#.#"),
    'O': ("###", "#.#", "#.#", "#.#", "###"),
    'P': ("###", "#.#", "###", "#..", "#.."),
    'R': ("###", "#.#", "##.", "#.#", "#.#"),
    'S': ("###", "#..", "###", "..#", "###"),
    'T': ("###", "..#", "..#", "..#", "..#"),
    'U': ("#.#", "#.#", "#.#", "#.#", "###"),
    'X': ("#.#", "#.#", "###", "#.#", "#.#"),
    'Y': ("#.#", "#.#", "###", "..#", "..#"),
    ' ': ("...", "...", "...", "...", "..."),
    '.': ("...", "...", "...", "...", "..#"),
    '-': ("...", "...", "###", "...", "..."),
    '=': ("...", "###", "...", "###", "..."),
    '%': ("#.#", "..#", ".#.", "#..", "#.#"),
    '/': ("..#", "..#", ".#.", "#..", "#.."),
}


def _png_encode(w, h, rgb):
    """Codifica RGB (bytearray w*h*3) a PNG (filtro 0, color type 2)."""
    stride = w * 3
    raw = bytearray()
    for y in range(h):
        raw.append(0)  # filter type 0
        raw += rgb[y * stride:(y + 1) * stride]

    def chunk(tag, data):
        c = struct.pack(">I", len(data)) + tag + data
        c += struct.pack(">I", zlib.crc32(tag + data) & 0xffffffff)
        return c

    ihdr = struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)
    return (b"\x89PNG\r\n\x1a\n"
            + chunk(b"IHDR", ihdr)
            + chunk(b"IDAT", zlib.compress(bytes(raw), 6))
            + chunk(b"IEND", b""))


def _make_frame_png():
    """Frame PNG puro (sin opencv): piso gris, cuadrícula, robot orientado, HUD."""
    w, h = 480, 360
    rgb = bytearray(b"\x78\x78\x78") * (w * h)  # piso gris

    def px(x, y, color):
        if 0 <= x < w and 0 <= y < h:
            i = (y * w + x) * 3
            rgb[i] = color[0]; rgb[i + 1] = color[1]; rgb[i + 2] = color[2]

    def rect(x0, y0, x1, y1, color):
        for y in range(max(0, y0), min(h, y1)):
            for x in range(max(0, x0), min(w, x1)):
                px(x, y, color)

    def line(x0, y0, x1, y1, color):
        dx, dy = abs(x1 - x0), abs(y1 - y0)
        sx = 1 if x0 < x1 else -1
        sy = 1 if y0 < y1 else -1
        err = dx - dy
        while True:
            px(x0, y0, color)
            if x0 == x1 and y0 == y1:
                break
            e2 = 2 * err
            if e2 > -dy:
                err -= dy; x0 += sx
            if e2 < dx:
                err += dx; y0 += sy

    def poly(points, color):
        xs = [p[0] for p in points]; ys = [p[1] for p in points]
        x0, x1 = max(0, int(min(xs))), min(w, int(max(xs)))
        y0, y1 = max(0, int(min(ys))), min(h, int(max(ys)))
        for y in range(y0, y1):
            for x in range(x0, x1):
                inside = False
                j = len(points) - 1
                for i in range(len(points)):
                    xi, yi = points[i]; xj, yj = points[j]
                    if (yi > y) != (yj > y) and x < (xj - xi) * (y - yi) / (yj - yi + 1e-9) + xi:
                        inside = not inside
                    j = i
                if inside:
                    px(x, y, color)

    def text(txt, x0, y0, color, scale=2):
        cx = x0
        for ch in txt.upper():
            glyph = _GLYPHS.get(ch, _GLYPHS[' '])
            for gy in range(5):
                for gx in range(3):
                    if glyph[gy][gx] == '#':
                        rect(cx + gx * scale, y0 + gy * scale,
                             cx + (gx + 1) * scale, y0 + (gy + 1) * scale, color)
            cx += 4 * scale

    # cuadrícula del piso
    for x in range(0, w, 40):
        for y in range(h):
            px(x, y, (0x66, 0x66, 0x66))
    for y in range(0, h, 40):
        for x in range(w):
            px(x, y, (0x66, 0x66, 0x66))

    with STATE.lock:
        sx = STATE.x; sy = STATE.y; heading = STATE.heading
        motors = STATE.motors_on; batt = STATE.battery
        speed = STATE.speed_ms; angle = STATE.angle
        start = STATE.start_stop

    pxc = int(240 + sx * 40)
    pyc = int(180 - sy * 40)  # y invertida (arriba = +y)
    ex, ey = math.cos(heading), math.sin(heading)
    nx, ny = -ey, ex
    hl, hw = 14.0, 8.0
    corners = [
        (pxc + hl * ex + hw * nx, pyc + hl * ey + hw * ny),
        (pxc + hl * ex - hw * nx, pyc + hl * ey - hw * ny),
        (pxc - hl * ex - hw * nx, pyc - hl * ey - hw * ny),
        (pxc - hl * ex + hw * nx, pyc - hl * ey + hw * ny),
    ]
    color = (0, 200, 0) if motors else (200, 0, 0)
    poly(corners, color)
    line(int(pxc), int(pyc), int(pxc + 20 * ex), int(pyc + 20 * ey), (255, 255, 0))
    px(pxc, pyc, (255, 255, 255))

    text("SIMULADOR", 10, 8, (255, 255, 255))
    text(f"x={sx:.1f} y={sy:.1f} h={math.degrees(heading) % 360:.0f}", 10, 28, (255, 255, 255))
    text(f"MOT={'ON' if motors else 'OFF'} START={start}", 10, 48,
         (0, 255, 0) if motors else (255, 80, 80))
    text(f"BATT={batt:.0f}% SPD={speed:.2f} ANG={angle:+.2f}", 10, 68, (255, 255, 255))
    return _png_encode(w, h, rgb)


def _make_frame():
    """Devuelve (bytes, mime) del último frame. JPEG con cv2, PNG puro sin cv2."""
    if HAVE_CV:
        img = np.full((360, 480, 3), (120, 120, 120), dtype=np.uint8)
        for x in range(0, 480, 40):
            cv2.line(img, (x, 0), (x, 360), (100, 100, 100), 1)
        for y in range(0, 360, 40):
            cv2.line(img, (0, y), (480, y), (100, 100, 100), 1)
        with STATE.lock:
            sx, sy, heading = STATE.x, STATE.y, STATE.heading
            motors = STATE.motors_on; batt = STATE.battery
            speed = STATE.speed_ms; angle = STATE.angle
            start = STATE.start_stop
        pxc = int(240 + sx * 40); pyc = int(180 - sy * 40)
        ex, ey = math.cos(heading), math.sin(heading)
        nx, ny = -ey, ex
        hl, hw = 14.0, 8.0
        corners = np.array([
            (pxc + hl * ex + hw * nx, pyc + hl * ey + hw * ny),
            (pxc + hl * ex - hw * nx, pyc + hl * ey - hw * ny),
            (pxc - hl * ex - hw * nx, pyc - hl * ey - hw * ny),
            (pxc - hl * ex + hw * nx, pyc - hl * ey + hw * ny),
        ], dtype=np.int32)
        color = (0, 200, 0) if motors else (200, 0, 0)
        cv2.fillConvexPoly(img, corners, color)
        cv2.line(img, (pxc, pyc), (int(pxc + 20 * ex), int(pyc + 20 * ey)), (255, 255, 0), 2)
        cv2.putText(img, f"SIMULADOR x={sx:.1f} y={sy:.1f} h={math.degrees(heading) % 360:.0f}",
                    (8, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
        cv2.putText(img, f"MOT={'ON' if motors else 'OFF'} START={start} BATT={batt:.0f}%",
                    (8, 40), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
        cv2.putText(img, f"ANG={angle:+.2f} SPD={speed:.2f} m/s",
                    (8, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
        ok, buf = cv2.imencode(".jpg", img, [cv2.IMWRITE_JPEG_QUALITY, 70])
        return (buf.tobytes(), "image/jpeg") if ok else (None, "image/jpeg")
    return (_make_frame_png(), "image/png")


def camera_loop():
    global CURRENT_FRAME, CURRENT_MIME
    while True:
        frame, mime = _make_frame()
        if frame:
            with FRAME_LOCK:
                CURRENT_FRAME = frame
                CURRENT_MIME = mime
        time.sleep(0.1)  # ~10 fps

# --------------------------------------------------------------------------
# HTML
# --------------------------------------------------------------------------
BOUNDARY = "boundarydonotcross"
LOGIN_HTML = """<!DOCTYPE html>
<html><head><title>AWS DeepRacer (simulado)</title>
<meta charset="utf-8">
<meta name="csrf-token" content="{csrf}"></head>
<body style="font-family:sans-serif;background:#222;color:#eee">
<h2>AWS DeepRacer — Simulador</h2>
<form id="loginForm" method="POST" action="/login">
<input type="hidden" name="csrf_token" value="{csrf}">
<label>Password: <input type="password" name="password"></label>
<input type="submit" value="Login">
</form>
<p style="color:#888">Contraseña: {pw_hint}</p>
<script>
const params = new URLSearchParams(location.search);
const next = params.get('next') || '/home';
document.getElementById('loginForm').addEventListener('submit', async (ev) => {{
  ev.preventDefault();
  const resp = await fetch('/login', {{method: 'POST', body: new URLSearchParams(new FormData(ev.target))}});
  if (resp.ok) {{ location.href = next; }}
  else {{ alert('Login falló: HTTP ' + resp.status); }}
}});
</script>
</body></html>"""

HOME_HTML = """<!DOCTYPE html>
<html><head><meta charset="utf-8">
<title>DeepRacer Simulador — Control</title>
<style>
body{font-family:sans-serif;background:#111;color:#ddd;margin:20px}
table{border-collapse:collapse} td{padding:4px 10px}
.big{font-size:2em} .on{color:#0f0} .off{color:#f33}
#cmd{font-family:monospace;background:#000;padding:10px}
</style></head>
<body>
<h2>🚗 DeepRacer Simulador — Estado y control</h2>
<div id="cmd"></div>
<div style="margin:10px 0">
<img id="cam" src="/route?topic=/camera_pkg/display_mjpeg&width=480&height=360"
     style="border:2px solid #444;border-radius:6px;max-width:640px;width:100%"
     alt="Cámara simulada — el robotcito sobre el piso">
</div>
<table>
<tr><td>drive_mode</td><td id="drive_mode">-</td></tr>
<tr><td>start_stop</td><td id="start_stop">-</td></tr>
<tr><td>motores</td><td id="motors" class="off">-</td></tr>
<tr><td>batería</td><td id="battery">-</td></tr>
<tr><td>dead zone efectiva</td><td id="dz">-</td></tr>
<tr><td>cmd_hz</td><td id="cmd_hz">-</td></tr>
<tr><td>pose</td><td id="pose">-</td></tr>
<tr><td>velocidad</td><td id="speed">-</td></tr>
<tr><td>LED</td><td id="led">-</td></tr>
</table>
<hr>
<h3>Controles</h3>
<button onclick="api('drive_mode',{'drive_mode':'manual'})">Modo manual</button>
<button onclick="api('start_stop',{'start_stop':'start'})">START</button>
<button onclick="api('start_stop',{'start_stop':'stop'})">STOP</button>
<br><br>
angle: <input id="angle" type="range" min="-1" max="1" step="0.01" value="0">
throttle: <input id="throttle" type="range" min="-1" max="1" step="0.01" value="0">
max_speed: <input id="max_speed" type="range" min="0" max="1" step="0.05" value="1">
<br>
<button onclick="sendCmd()">Enviar comando</button>
<button onclick="sendLoop()">▶ Enviar en loop (watchdog-safe)</button>
<button onclick="stopLoop()">■ Parar loop</button>
<script>
let loopId=null;
function api(path,body){fetch('/api/'+path,{method:'PUT',headers:{'Content-Type':'application/json','X-Requested-With':'XMLHttpRequest'},body:JSON.stringify(body)}).then(r=>r.json()).then(j=>log('PUT /api/'+path+' -> '+JSON.stringify(j)))}
function sendCmd(){const a=+document.getElementById('angle').value,t=+document.getElementById('throttle').value,m=+document.getElementById('max_speed').value;api('manual_drive',{angle:a,throttle:t,max_speed:m})}
function sendLoop(){stopLoop();loopId=setInterval(sendCmd,80)}
function stopLoop(){if(loopId)clearInterval(loopId);loopId=null}
function log(t){const d=document.getElementById('cmd');d.textContent=t+'\\n'+d.textContent}
setInterval(()=>{fetch('/mock/state').then(r=>r.json()).then(s=>{
document.getElementById('drive_mode').textContent=s.drive_mode;
document.getElementById('start_stop').textContent=s.start_stop;
const m=document.getElementById('motors');m.textContent=s.motors_on?'ON':'OFF';m.className=s.motors_on?'on':'off';
document.getElementById('battery').textContent=s.battery+'%';
document.getElementById('dz').textContent=s.dead_zone_effective;
document.getElementById('cmd_hz').textContent=s.cmd_hz+' Hz';
document.getElementById('pose').textContent=`x=${s.x} y=${s.y} heading=${s.heading_deg}°`;
document.getElementById('speed').textContent=s.speed_ms+' m/s';
document.getElementById('led').textContent=JSON.stringify(s.led);
})},300);
</script>
</body></html>"""


def send_json(handler, obj, status=200):
    body = json.dumps(obj).encode()
    handler.send_response(status)
    handler.send_header("Content-Type", "application/json")
    handler.send_header("Content-Length", str(len(body)))
    handler.end_headers()
    handler.wfile.write(body)


def send_401(handler):
    send_json(handler, {"success": False, "error": "unauthorized"}, status=401)


class MockHandler(BaseHTTPRequestHandler):
    protocol_version = "HTTP/1.1"

    def log_message(self, fmt, *args):
        sys.stderr.write("[mock] %s\n" % (fmt % args))

    # -- helpers --
    def _read_body(self):
        length = int(self.headers.get("Content-Length") or 0)
        if length == 0:
            return b""
        return self.rfile.read(length)

    def _authed(self):
        """Requiere cookie de sesión autenticada (el CSRF via header es bonus)."""
        _, authed = parse_session(self.headers.get("Cookie"))
        return authed

    # -- rutas --
    def do_GET(self):
        path = urllib.parse.urlparse(self.path).path
        if path == "/login":
            csrf = new_csrf()
            cookie = make_session_cookie(csrf, False)
            body = LOGIN_HTML.format(csrf=csrf, pw_hint=API_PASSWORD).encode()
            self.send_response(200)
            self.send_header("Content-Type", "text/html; charset=utf-8")
            self.send_header("Content-Length", str(len(body)))
            self.send_header("Set-Cookie", f"session={cookie}; Path=/; HttpOnly")
            self.end_headers()
            self.wfile.write(body)
        elif path == "/home":
            _, authed = parse_session(self.headers.get("Cookie"))
            if not authed:
                self.send_response(302)
                self.send_header("Location", "/login?next=/home")
                self.end_headers()
                return
            body = HOME_HTML.encode()
            self.send_response(200)
            self.send_header("Content-Type", "text/html; charset=utf-8")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
        elif path == "/mock/state":
            send_json(self, STATE.state_snapshot())
        elif path == "/api/get_led_color":
            if not self._authed():
                send_401(self)
                return
            send_json(self, {"success": True, **STATE.led})
        elif path == "/route" or path == "/stream_viewer" or path == "/snapshot":
            self._serve_mjpeg_or_snapshot()
        elif path == "/":
            self.send_response(302)
            self.send_header("Location", "/login")
            self.end_headers()
        elif path == "/favicon.ico":
            self.send_response(204)
            self.end_headers()
        else:
            send_json(self, {"success": False, "error": f"not found: {path}"}, 404)

    def do_POST(self):
        self._handle_api("POST")

    def do_PUT(self):
        self._handle_api("PUT")

    def _handle_api(self, method):
        path = urllib.parse.urlparse(self.path).path

        if path == "/login":
            self._do_login()
            return

        if path in ("/api/drive_mode", "/api/start_stop", "/api/manual_drive",
                    "/api/set_led_color", "/api/get_led_color"):
            if not self._authed():
                self._read_body()  # drenar para no corromper el keep-alive
                send_401(self)
                return
            self._do_vehicle_api(method, path)
            return

        self._read_body()  # drenar para no corromper el keep-alive
        send_json(self, {"success": False, "error": f"not found: {path}"}, 404)

    def _do_login(self):
        length = int(self.headers.get("Content-Length") or 0)
        raw = self.rfile.read(length) if length else b""
        form = urllib.parse.parse_qs(raw.decode())
        password = (form.get("password") or [""])[0]
        csrf = (form.get("csrf_token") or [""])[0]
        if not csrf_valid(csrf):
            send_json(self, {"success": False, "error": "invalid csrf"}, 403)
            return
        if password != API_PASSWORD:
            send_json(self, {"success": False, "error": "invalid credentials"}, 401)
            return
        cookie = make_session_cookie(csrf, True)
        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        body = json.dumps({"success": True}).encode()
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Set-Cookie", f"session={cookie}; Path=/; HttpOnly")
        self.end_headers()
        self.wfile.write(body)

    def _do_vehicle_api(self, method, path):
        raw = self._read_body()
        try:
            data = json.loads(raw) if raw else {}
        except json.JSONDecodeError:
            send_json(self, {"success": False, "error": "invalid json"}, 400)
            return

        if path == "/api/drive_mode":
            mode = data.get("drive_mode")
            if mode not in ("manual", "autonomous"):
                send_json(self, {"success": False, "error": "invalid drive_mode"}, 400)
                return
            STATE.drive_mode = mode
            if mode != "manual":
                STATE.start_stop = "stop"
                STATE.motors_on = False
        elif path == "/api/start_stop":
            cmd = data.get("start_stop")
            if cmd not in ("start", "stop"):
                send_json(self, {"success": False, "error": "invalid start_stop"}, 400)
                return
            STATE.start_stop = cmd
            if cmd == "stop":
                STATE.motors_on = False
                STATE.throttle = 0.0
        elif path == "/api/manual_drive":
            if "angle" not in data and "throttle" not in data and "drive_control" not in data:
                send_json(self, {"success": False, "error": "missing fields"}, 400)
                return
            if "drive_control" in data:
                # Contrato viejo (iteración anterior)
                dc = data["drive_control"]
                angle = float(dc.get("steering_angle", 0.0)) / 45.0
                throttle = float(dc.get("throttle", 0.0)) / 100.0
                max_speed = 1.0
            else:
                angle = float(data.get("angle", 0.0))
                throttle = float(data.get("throttle", 0.0))
                max_speed = float(data.get("max_speed", 1.0))
            STATE.apply_command(angle, throttle, max_speed)
        elif path == "/api/set_led_color":
            r = int(data.get("red", 0)); g = int(data.get("green", 0)); b = int(data.get("blue", 0))
            STATE.led = {"red": max(0, min(9999825, r)), "green": max(0, min(9999825, g)),
                         "blue": max(0, min(9999825, b))}
        elif path == "/api/get_led_color":
            send_json(self, {"success": True, **STATE.led})
            return

        send_json(self, {"success": True})

    def _serve_mjpeg_or_snapshot(self):
        qs = urllib.parse.parse_qs(urllib.parse.urlparse(self.path).query)
        topic = (qs.get("topic") or [""])[0]
        if not topic:
            topic = "/camera_pkg/display_mjpeg"
        path = urllib.parse.urlparse(self.path).path

        if path == "/snapshot":
            with FRAME_LOCK:
                frame = CURRENT_FRAME
                mime = CURRENT_MIME
            if not frame:
                send_json(self, {"success": False, "error": "no frame"}, 503)
                return
            self.send_response(200)
            self.send_header("Content-Type", mime)
            self.send_header("Content-Length", str(len(frame)))
            self.end_headers()
            self.wfile.write(frame)
            return

        # MJPEG multipart (igual que web_video_server real)
        self.send_response(200)
        self.send_header("Content-Type",
                         f"multipart/x-mixed-replace;boundary={BOUNDARY}")
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        try:
            last = None
            while True:
                with FRAME_LOCK:
                    frame = CURRENT_FRAME
                    mime = CURRENT_MIME
                if frame is not None and frame is not last:
                    last = frame
                    self.wfile.write(b"--" + BOUNDARY.encode() + b"\r\n")
                    self.wfile.write(b"Content-Type: " + mime.encode() + b"\r\n")
                    self.wfile.write(b"Content-Length: " + str(len(frame)).encode() + b"\r\n\r\n")
                    self.wfile.write(frame)
                    self.wfile.write(b"\r\n")
                    self.wfile.flush()
                time.sleep(0.1)
                if self.wfile is None:
                    break
        except (BrokenPipeError, ConnectionResetError, OSError):
            pass


# --------------------------------------------------------------------------
# Certificado autofirmado
# --------------------------------------------------------------------------
def ensure_cert():
    if os.path.exists(CERT_FILE) and os.path.exists(KEY_FILE):
        return
    os.makedirs(CERT_DIR, exist_ok=True)
    subprocess.run([
        "openssl", "req", "-x509", "-newkey", "rsa:2048", "-nodes",
        "-keyout", KEY_FILE, "-out", CERT_FILE, "-days", "3650",
        "-subj", "/CN=deepracer-simulator.local",
    ], check=True, capture_output=True)


def main():
    ensure_cert()

    context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    context.load_cert_chain(CERT_FILE, KEY_FILE)

    https_server = ThreadingHTTPServer(("0.0.0.0", HTTPS_PORT), MockHandler)
    https_server.socket = context.wrap_socket(https_server.socket, server_side=True)

    http_server = ThreadingHTTPServer(("0.0.0.0", HTTP_PORT), MockHandler)

    threading.Thread(target=physics_loop, daemon=True).start()
    threading.Thread(target=camera_loop, daemon=True).start()

    print("🧪 DeepRacer Simulador (mock)")
    print(f"   API HTTPS   : https://127.0.0.1:{HTTPS_PORT}/login  (password: {API_PASSWORD})")
    print(f"   Dashboard   : https://127.0.0.1:{HTTPS_PORT}/home")
    print(f"   MJPEG HTTP  : http://127.0.0.1:{HTTP_PORT}/stream_viewer?topic=/camera_pkg/display_mjpeg")
    print(f"   Estado      : https://127.0.0.1:{HTTPS_PORT}/mock/state")
    print(f"   Watchdog    : {WATCHDOG_MS} ms | dead zone: {DEAD_ZONE} | sign: {THROTTLE_SIGN} (neg=adelante)")
    print(f"   opencv/cv2  : {'OK — frames sintéticos con HUD' if HAVE_CV else 'NO — PNG puro (sin HUD de cv2)'}")
    print("   Ctrl+C para salir.")
    try:
        threading.Thread(target=https_server.serve_forever, daemon=True).start()
        http_server.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()