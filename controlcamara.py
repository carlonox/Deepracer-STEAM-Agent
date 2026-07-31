#!/usr/bin/env python3
"""
DeepRacer ArUco waypoint navigator.

Objetivo:
- Detectar codigos ArUco.
- Inferir la ubicacion actual por el ArUco mas cercano.
- Seguir rutas predefinidas entre lugares.
- Acercarse a cada waypoint y pasar al siguiente.

Controles:
- ESPACIO: quitar/poner freno de mano.
- En terminal: escribe "ve a salida", "ve a impresora", etc.
- q: salir y detener.
"""

import cv2
import cv2.aruco as aruco
import numpy as np
import time
import math
import sys
import os
import json
import queue
import socket
import struct
import threading
import requests


# ==================== CONFIG RED / BACKEND ====================
BACKEND_URL = "http://127.0.0.1:5002"
BACKEND_DRIVE_HOST = "127.0.0.1"
BACKEND_DRIVE_PORT = 5003
ENABLE_VEHICLE_CONTROL = True


# ==================== CONFIG CAMARA ====================
CAMERA_SOURCE = "esp32_udp"  # "usb" o "esp32_udp"
CAMERA_INDEX = 0
CAMERA_WIDTH = 640
CAMERA_HEIGHT = 480

# Video UDP desde ESP32-S3. La ESP debe enviar paquetes JPEG fragmentados:
# header big-endian: frame_id:uint32, chunk_index:uint16, chunk_count:uint16,
# payload_size:uint16, timestamp_ms:uint32, seguido por payload JPEG.
ESP32_VIDEO_HOST = "0.0.0.0"
ESP32_VIDEO_PORT = 5000
ESP32_DEVICE_HOST = "192.168.4.1"
ESP32_DISCOVERY_PORT = 5001
ESP32_DISCOVERY_INTERVAL = 0.5
ESP32_FRAME_TIMEOUT = 0.10
ESP32_MAX_FRAME_BYTES = 180_000
ESP32_UDP_HEADER = "!IHHHI"
ESP32_UDP_HEADER_SIZE = 14


# ==================== CONFIG ARUCO ====================
ARUCO_DICT_TYPE = aruco.DICT_ARUCO_ORIGINAL
ARUCO_DICT_NAME = "DICT_ARUCO_ORIGINAL"
ARUCO_DIAGNOSTIC_DICTS = [
    ("DICT_4X4_50", aruco.DICT_4X4_50),
    ("DICT_4X4_100", aruco.DICT_4X4_100),
    ("DICT_5X5_100", aruco.DICT_5X5_100),
    ("DICT_5X5_250", aruco.DICT_5X5_250),
    ("DICT_6X6_250", aruco.DICT_6X6_250),
    ("DICT_7X7_1000", aruco.DICT_7X7_1000),
]
MARKER_SIZE = 0.125  # metros; marcador fisico 12.5 cm x 12.5 cm
MIN_MARKER_SIDE_RATIO = 0.08

# Distancia deseada al waypoint.
TARGET_DISTANCE = 0.50
DISTANCE_DEADZONE = 0.08
ARUCO_HARD_CLOSE_DISTANCE = 0.42
ARUCO_CLOSE_SIDE_RATIO = 0.55
ARUCO_CENTER_DEADZONE = 0.12  # radianes

# Por el peso del celular, evitar magnitudes menores a 0.6.
FORWARD_THROTTLE_SIGN = 1.0
ARUCO_FAST_THROTTLE = 0.70
ARUCO_MIN_THROTTLE = 0.60
ARUCO_REVERSE_THROTTLE = 0.60
MAX_SPEED_LIMIT = 0.70
KP_STEER = 1.3
STEER_CLAMP = 1.0
LOST_TARGET_TIMEOUT_FRAMES = 2
SAFETY_FRONT_DISTANCE_CM = 35.0
SAFETY_PAUSE_SECONDS_AFTER_CLEAR = 0.4


# ==================== MAPA / RUTAS ====================
# Cambia estos IDs por los codigos reales del aula.
ARUCO_PLACES = {
    50: {"name": "mesa", "aliases": ["mesa"]},
    100: {"name": "impresora", "aliases": ["impresora"]},
    150: {"name": "salida", "aliases": ["salida", "puerta"]},
}

# Grafo de rutas. Si estas en mesa y quieres salida:
# mesa -> impresora -> salida
ARUCO_ROUTES = {
    "mesa": ["impresora"],
    "impresora": ["mesa", "salida"],
    "salida": ["impresora"],
}


STOP_WORDS = ["para", "parate", "párate", "detente", "quieto", "stop", "alto"]
MOVE_WORDS = ["ve", "ir", "anda", "dirigete", "dirígete", "llevame", "llévame"]


# ==================== BACKEND CLIENT ====================
class DeepRacerAPIClient:
    """Cliente de control: TCP persistente con fallback HTTP."""

    def __init__(self, base_url, drive_host=BACKEND_DRIVE_HOST, drive_port=BACKEND_DRIVE_PORT):
        self.base_url = base_url
        self.drive_host = drive_host
        self.drive_port = drive_port
        self.session = requests.Session()
        self.sock = None
        self.sock_file = None
        self.sock_lock = threading.Lock()
        self.next_tcp_retry = 0.0
        self.tcp_available = True
        print(f"[*] Backend HTTP: {self.base_url} | TCP: {self.drive_host}:{self.drive_port}")

    def _close_tcp(self):
        try:
            if self.sock_file is not None:
                self.sock_file.close()
        except Exception:
            pass
        try:
            if self.sock is not None:
                self.sock.close()
        except Exception:
            pass
        self.sock = None
        self.sock_file = None

    def _ensure_tcp(self):
        if self.sock is not None:
            return
        self.sock = socket.create_connection((self.drive_host, self.drive_port), timeout=0.5)
        self.sock.settimeout(2.0)
        self.sock_file = self.sock.makefile("r", encoding="utf-8", newline="\n")

    def _tcp_command(self, payload):
        if time.time() < self.next_tcp_retry:
            return False
        with self.sock_lock:
            if time.time() < self.next_tcp_retry:
                return False
            try:
                self._ensure_tcp()
                self.sock.sendall((json.dumps(payload, separators=(",", ":")) + "\n").encode("utf-8"))
                response_line = self.sock_file.readline()
                if not response_line:
                    raise ConnectionError("canal TCP cerrado")
                response = json.loads(response_line)
                if not response.get("ok"):
                    raise RuntimeError(response.get("error", "error TCP desconocido"))
                return True
            except Exception as e:
                self._close_tcp()
                self.next_tcp_retry = time.time() + 5.0
                if self.tcp_available:
                    print(f"[!] TCP no disponible; usando HTTP fallback: {e}")
                    self.tcp_available = False
                return False

    def prepare_manual(self):
        if self._tcp_command({"init": True}):
            print("[+] Modo manual preparado por TCP.")
            return True
        try:
            r = self.session.post(f"{self.base_url}/api/manual_drive", json={"init": True}, timeout=2)
            ok = r.status_code == 200
            print("[+] Modo manual preparado por HTTP." if ok else f"[-] Init HTTP {r.status_code}")
            return ok
        except Exception as e:
            print(f"[-] Error preparando modo manual: {e}")
            return False

    def send_drive(self, angle, throttle, max_speed):
        payload = {
            "angle": float(angle),
            "throttle": float(throttle),
            "max_speed": float(max_speed),
        }
        if self._tcp_command(payload):
            return True
        try:
            r = self.session.post(f"{self.base_url}/api/manual_drive", json=payload, timeout=1)
            return r.status_code == 200
        except Exception as e:
            print(f"[-] Error enviando drive: {e}")
            return False

    def stop_vehicle(self):
        if self._tcp_command({"stop": True}):
            print("[+] Vehiculo detenido por TCP.")
            return True
        try:
            r = self.session.post(f"{self.base_url}/api/stop", json={}, timeout=2)
            ok = r.status_code == 200
            print("[+] Vehiculo detenido por HTTP." if ok else f"[-] Stop HTTP {r.status_code}")
            return ok
        except Exception as e:
            print(f"[-] Error deteniendo vehiculo: {e}")
            return False


class AsyncDriveSender:
    """Envia solo el comando mas reciente sin bloquear la camara."""

    def __init__(self, api, interval=0.10):
        self.api = api
        self.interval = interval
        self.queue = queue.Queue(maxsize=1)
        self.stop_event = threading.Event()
        self.thread = threading.Thread(target=self._worker, daemon=True)
        self.thread.start()

    def send(self, angle, throttle, max_speed):
        command = (float(angle), float(throttle), float(max_speed))
        try:
            while True:
                self.queue.get_nowait()
        except queue.Empty:
            pass
        try:
            self.queue.put_nowait(command)
        except queue.Full:
            pass

    def _worker(self):
        last_sent = 0.0
        while not self.stop_event.is_set():
            try:
                angle, throttle, max_speed = self.queue.get(timeout=0.1)
            except queue.Empty:
                continue
            elapsed = time.time() - last_sent
            if elapsed < self.interval:
                time.sleep(self.interval - elapsed)
            self.api.send_drive(angle, throttle, max_speed)
            last_sent = time.time()

    def stop(self):
        self.stop_event.set()
        self.thread.join(timeout=1.0)


# ==================== SEGURIDAD / SENSORES ====================
class SafetyGate:
    """
    Filtro de seguridad entre navegacion y motores.

    Hoy solo aplica freno manual y estado de sensores simulado. Cuando conectes
    ESP32, actualiza self.front_distance_cm desde serial/TCP/HTTP y esta capa
    pausara automaticamente el avance.
    """

    def __init__(self, front_threshold_cm=SAFETY_FRONT_DISTANCE_CM):
        self.front_threshold_cm = front_threshold_cm
        self.front_distance_cm = None
        self.blocked_until = 0.0
        self.manual_pause = True

    def set_manual_pause(self, paused):
        self.manual_pause = bool(paused)

    def update_front_distance_cm(self, distance_cm):
        self.front_distance_cm = None if distance_cm is None else float(distance_cm)
        if self.front_blocked():
            self.blocked_until = time.time() + SAFETY_PAUSE_SECONDS_AFTER_CLEAR

    def front_blocked(self):
        return self.front_distance_cm is not None and self.front_distance_cm < self.front_threshold_cm

    def paused(self):
        return self.manual_pause or self.front_blocked() or time.time() < self.blocked_until

    def filter_command(self, steer, throttle):
        if self.manual_pause:
            return 0.0, 0.0, "manual"
        if self.front_blocked() and throttle == FORWARD_THROTTLE_SIGN * abs(throttle):
            return 0.0, 0.0, "obstaculo"
        if time.time() < self.blocked_until and throttle == FORWARD_THROTTLE_SIGN * abs(throttle):
            return 0.0, 0.0, "esperando despeje"
        return steer, throttle, ""

    def status_text(self):
        if self.manual_pause:
            return "FRENO"
        if self.front_blocked():
            return f"OBSTACULO {self.front_distance_cm:.0f}cm"
        if time.time() < self.blocked_until:
            return "DESPEJE"
        return "ACTIVO"


def update_safety_from_esp32_placeholder(safety):
    """
    Punto de integracion futuro para ESP32.

    Cuando tengas el ESP32 enviando distancia frontal, esta funcion deberia llamar:
        safety.update_front_distance_cm(distancia_cm)

    Puede implementarse leyendo serial, TCP, UDP o HTTP. Por ahora no hace nada.
    """
    return


# ==================== CAMARA ====================
class LatestFrameCamera:
    def __init__(self, camera_index, width, height):
        self.cap = cv2.VideoCapture(camera_index, cv2.CAP_DSHOW)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, width)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
        self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)
        self.lock = threading.Lock()
        self.frame = None
        self.timestamp = 0.0
        self.running = False
        self.thread = None

    def is_opened(self):
        return self.cap.isOpened()

    def start(self):
        self.running = True
        self.thread = threading.Thread(target=self._reader, daemon=True)
        self.thread.start()

    def _reader(self):
        while self.running:
            ret, frame = self.cap.read()
            if ret:
                with self.lock:
                    self.frame = frame
                    self.timestamp = time.time()
            else:
                time.sleep(0.01)

    def read(self):
        with self.lock:
            if self.frame is None:
                return False, None, 0.0
            return True, self.frame.copy(), self.timestamp

    def release(self):
        self.running = False
        if self.thread is not None:
            self.thread.join(timeout=1.0)
        self.cap.release()


class ESP32UdpJpegCamera:
    def __init__(self, host, port, frame_timeout=ESP32_FRAME_TIMEOUT):
        self.host = host
        self.port = port
        self.frame_timeout = frame_timeout
        self.sock = None
        self.lock = threading.Lock()
        self.frame = None
        self.timestamp = 0.0
        self.running = False
        self.thread = None
        self.current_frame_id = -1
        self.pending = None
        self.frames_decoded = 0
        self.frames_dropped = 0
        self.packets_received = 0
        self.last_fps_time = time.time()
        self.fps = 0.0
        self.last_latency_ms = 0.0
        self.last_discovery_time = 0.0

    def is_opened(self):
        if self.sock is not None:
            return True
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.sock.bind((self.host, self.port))
            self.sock.settimeout(0.02)
            return True
        except OSError as e:
            print(f"[-] No se pudo abrir UDP {self.host}:{self.port}: {e}")
            self.sock = None
            return False

    def start(self):
        if self.sock is None and not self.is_opened():
            return
        self.running = True
        self.thread = threading.Thread(target=self._reader, daemon=True)
        self.thread.start()

    def _reader(self):
        while self.running:
            self._send_discovery_if_needed()
            try:
                packet, _ = self.sock.recvfrom(2048)
                self.packets_received += 1
                self._handle_packet(packet)
                self._drop_expired_pending()
            except socket.timeout:
                self._drop_expired_pending()
            except OSError:
                break

    def _send_discovery_if_needed(self):
        now = time.monotonic()
        if now - self.last_discovery_time < ESP32_DISCOVERY_INTERVAL:
            return
        self.last_discovery_time = now
        try:
            message = f"DEEPRACER_DISCOVER {self.port}".encode("ascii")
            self.sock.sendto(message, (ESP32_DEVICE_HOST, ESP32_DISCOVERY_PORT))
        except OSError:
            pass

    def _handle_packet(self, packet):
        if len(packet) >= 2 and packet[:2] == b"\xff\xd8":
            self._decode_jpeg(packet, 0)
            return

        if len(packet) < ESP32_UDP_HEADER_SIZE:
            return

        frame_id, chunk_index, chunk_count, payload_size, timestamp_ms = struct.unpack(
            ESP32_UDP_HEADER,
            packet[:ESP32_UDP_HEADER_SIZE],
        )
        payload = packet[ESP32_UDP_HEADER_SIZE:ESP32_UDP_HEADER_SIZE + payload_size]

        if payload_size != len(payload) or chunk_count == 0 or chunk_index >= chunk_count:
            return
        if payload_size * chunk_count > ESP32_MAX_FRAME_BYTES:
            self.frames_dropped += 1
            return
        if frame_id < self.current_frame_id:
            self.frames_dropped += 1
            return
        if frame_id > self.current_frame_id:
            if self.pending is not None:
                self.frames_dropped += 1
            self.current_frame_id = frame_id
            self.pending = {
                "frame_id": frame_id,
                "timestamp_ms": timestamp_ms,
                "created_at": time.time(),
                "chunks": [None] * chunk_count,
                "received": 0,
            }

        if self.pending is None or self.pending["frame_id"] != frame_id:
            return
        if len(self.pending["chunks"]) != chunk_count:
            self.frames_dropped += 1
            self.pending = None
            return
        if self.pending["chunks"][chunk_index] is None:
            self.pending["chunks"][chunk_index] = payload
            self.pending["received"] += 1

        if self.pending["received"] == chunk_count:
            jpeg = b"".join(self.pending["chunks"])
            self._decode_jpeg(jpeg, timestamp_ms)
            self.pending = None

    def _drop_expired_pending(self):
        if self.pending is None:
            return
        if time.time() - self.pending["created_at"] > self.frame_timeout:
            self.frames_dropped += 1
            self.pending = None

    def _decode_jpeg(self, jpeg, timestamp_ms):
        np_buffer = np.frombuffer(jpeg, dtype=np.uint8)
        frame = cv2.imdecode(np_buffer, cv2.IMREAD_COLOR)
        if frame is None:
            self.frames_dropped += 1
            return
        now = time.time()
        with self.lock:
            self.frame = frame
            self.timestamp = now
            self.frames_decoded += 1
            # Solo es latencia real si la ESP envia tiempo Unix en ms sincronizado.
            # Si envia millis() desde arranque, no hay reloj comun y se deja en 0.
            if timestamp_ms > 1_000_000_000_000:
                self.last_latency_ms = max(0.0, (now * 1000.0) - float(timestamp_ms))
            elapsed = now - self.last_fps_time
            if elapsed >= 1.0:
                self.fps = self.frames_decoded / elapsed
                self.frames_decoded = 0
                self.last_fps_time = now

    def read(self):
        with self.lock:
            if self.frame is None:
                return False, None, 0.0
            return True, self.frame.copy(), self.timestamp

    def metrics_text(self):
        with self.lock:
            return f"UDP FPS:{self.fps:.1f} drop:{self.frames_dropped} lat:{self.last_latency_ms:.0f}ms"

    def release(self):
        self.running = False
        if self.thread is not None:
            self.thread.join(timeout=1.0)
        if self.sock is not None:
            self.sock.close()
            self.sock = None


def create_camera():
    if CAMERA_SOURCE == "esp32_udp":
        print(f"[*] Camara ESP32 UDP: {ESP32_VIDEO_HOST}:{ESP32_VIDEO_PORT}")
        return ESP32UdpJpegCamera(ESP32_VIDEO_HOST, ESP32_VIDEO_PORT)

    print(f"[*] Camara USB indice: {CAMERA_INDEX}")
    return LatestFrameCamera(CAMERA_INDEX, CAMERA_WIDTH, CAMERA_HEIGHT)


# ==================== CONSOLA ====================
def start_console_reader(command_queue):
    def worker():
        while True:
            try:
                text = input("RUTA> ").strip()
                if text:
                    command_queue.put(text)
            except EOFError:
                break
            except Exception:
                break

    threading.Thread(target=worker, daemon=True).start()


# ==================== UTILIDADES RUTA ====================
def normalize_text(text):
    return text.lower().strip()


def is_stop_instruction(instruction):
    text = normalize_text(instruction)
    return any(word in text for word in STOP_WORDS)


def place_name_for_aruco(marker_id):
    place = ARUCO_PLACES.get(int(marker_id))
    return place["name"] if place else f"aruco_{int(marker_id)}"


def aruco_id_for_place(place_name):
    for marker_id, place in ARUCO_PLACES.items():
        if place["name"] == place_name:
            return marker_id
    return None


def infer_place_from_instruction(instruction):
    text = normalize_text(instruction)
    for place in ARUCO_PLACES.values():
        names = [place["name"], *place.get("aliases", [])]
        if any(name in text for name in names):
            return place["name"]
    return ""


def shortest_place_route(start, goal):
    if not start or not goal:
        return []
    if start == goal:
        return [start]

    pending = [(start, [start])]
    visited = {start}
    while pending:
        current, path = pending.pop(0)
        for nxt in ARUCO_ROUTES.get(current, []):
            if nxt in visited:
                continue
            next_path = [*path, nxt]
            if nxt == goal:
                return next_path
            visited.add(nxt)
            pending.append((nxt, next_path))
    return []


def aruco_side_ratio(corners, frame_width, frame_height):
    points = np.asarray(corners[0], dtype=np.float32).reshape(4, 2)
    side_lengths = [
        np.linalg.norm(points[(i + 1) % 4] - points[i])
        for i in range(4)
    ]
    return float(max(side_lengths) / max(1.0, min(frame_width, frame_height)))


def estimate_pose_marker(corners, marker_size, camera_matrix, dist_coeffs):
    try:
        rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(corners, marker_size, camera_matrix, dist_coeffs)
        return rvecs[0], tvecs[0]
    except AttributeError:
        half_s = marker_size / 2.0
        object_points = np.array([
            [-half_s, half_s, 0.0],
            [half_s, half_s, 0.0],
            [half_s, -half_s, 0.0],
            [-half_s, -half_s, 0.0],
        ], dtype=np.float32)
        success, rvec, tvec = cv2.solvePnP(object_points, corners[0], camera_matrix, dist_coeffs)
        if success:
            return np.expand_dims(rvec, axis=0), np.expand_dims(tvec, axis=0)
        return None, None


def detect_aruco_markers(frame, detector, aruco_dict, aruco_params, has_new_aruco, camera_matrix, dist_coeffs):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    if has_new_aruco:
        corners, ids, rejected = detector.detectMarkers(gray)
    else:
        corners, ids, rejected = aruco.detectMarkers(gray, aruco_dict, parameters=aruco_params)

    if ids is None:
        return [], 0

    h, w = frame.shape[:2]
    markers = []
    for idx, marker_id in enumerate(ids.flatten()):
        marker_corners = [corners[idx]]
        side_ratio = aruco_side_ratio(marker_corners, w, h)
        if side_ratio < MIN_MARKER_SIDE_RATIO:
            continue
        rvec, tvec = estimate_pose_marker(marker_corners, MARKER_SIZE, camera_matrix, dist_coeffs)
        if tvec is not None:
            tvec_flat = np.asarray(tvec).reshape(-1)
            x = float(tvec_flat[0])
            z = float(tvec_flat[2])
        else:
            x = 0.0
            z = float("inf")
        angle_rad = math.atan2(x, z) if z != 0 else 0.0
        markers.append({
            "idx": idx,
            "id": int(marker_id),
            "place": place_name_for_aruco(int(marker_id)),
            "corners": marker_corners,
            "rvec": rvec,
            "tvec": tvec,
            "x": x,
            "z": z,
            "angle_rad": angle_rad,
            "angle_deg": math.degrees(angle_rad),
            "side_ratio": side_ratio,
            "has_pose": tvec is not None,
        })
    return markers, len(rejected) if rejected is not None else 0


def diagnose_aruco_dictionaries(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    hits = []
    for dict_name, dict_type in ARUCO_DIAGNOSTIC_DICTS:
        try:
            dictionary = aruco.getPredefinedDictionary(dict_type)
            params = aruco.DetectorParameters()
            detector = aruco.ArucoDetector(dictionary, params)
            _, ids, rejected = detector.detectMarkers(gray)
        except AttributeError:
            dictionary = aruco.Dictionary_get(dict_type)
            params = aruco.DetectorParameters_create()
            _, ids, rejected = aruco.detectMarkers(gray, dictionary, parameters=params)
        if ids is not None:
            hits.append({
                "dict": dict_name,
                "ids": [int(x) for x in ids.flatten()],
                "rejected": len(rejected) if rejected is not None else 0,
            })
    return hits


def choose_marker(markers, active_waypoint):
    if not markers:
        return None
    if active_waypoint:
        for marker in markers:
            if marker["place"] == active_waypoint:
                return marker
    return min(markers, key=lambda item: item["z"])


def arrived_at_marker(marker):
    distance_error = marker["z"] - TARGET_DISTANCE
    return abs(distance_error) <= DISTANCE_DEADZONE and abs(marker["angle_rad"]) <= ARUCO_CENTER_DEADZONE


def drive_command_for_marker(marker):
    distance_error = marker["z"] - TARGET_DISTANCE
    close = marker["z"] <= ARUCO_HARD_CLOSE_DISTANCE or marker["side_ratio"] >= ARUCO_CLOSE_SIDE_RATIO
    steer = float(np.clip(marker["angle_rad"] * KP_STEER, -STEER_CLAMP, STEER_CLAMP))

    if close:
        return 0.0, -FORWARD_THROTTLE_SIGN * ARUCO_REVERSE_THROTTLE, True

    if distance_error > 0.18:
        return steer, FORWARD_THROTTLE_SIGN * ARUCO_FAST_THROTTLE, False

    if distance_error > DISTANCE_DEADZONE:
        return steer, FORWARD_THROTTLE_SIGN * ARUCO_MIN_THROTTLE, False

    if distance_error < -DISTANCE_DEADZONE:
        return 0.0, -FORWARD_THROTTLE_SIGN * ARUCO_REVERSE_THROTTLE, False

    if abs(marker["angle_rad"]) > ARUCO_CENTER_DEADZONE and distance_error > 0.0:
        return steer, FORWARD_THROTTLE_SIGN * ARUCO_MIN_THROTTLE, False

    return 0.0, 0.0, False


def draw_marker_debug(frame, markers, selected_marker, current_place, active_waypoint, destination_place, rejected_count):
    for marker in markers:
        color = (0, 255, 255) if selected_marker and marker["id"] == selected_marker["id"] else (0, 180, 255)
        aruco.drawDetectedMarkers(frame, marker["corners"], np.array([[marker["id"]]]), borderColor=color)
        points = np.asarray(marker["corners"][0]).reshape(4, 2)
        x, y = points.mean(axis=0).astype(int)
        distance_text = f"{marker['z']:.2f}m" if marker["has_pose"] else "sin pose"
        cv2.putText(
            frame,
            f"ID {marker['id']} {marker['place']} {distance_text}",
            (x - 50, y - 10),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.45,
            color,
            1,
        )

    ids_text = ", ".join(str(marker["id"]) for marker in markers) or "ninguno"
    cv2.putText(frame, f"IDs vistos: {ids_text} | candidatos rechazados: {rejected_count}", (20, 85), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (255, 255, 255), 1)
    cv2.putText(frame, f"Ubicacion: {current_place or '-'}", (20, 110), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (255, 255, 255), 1)
    cv2.putText(frame, f"Waypoint: {active_waypoint or '-'} | Destino: {destination_place or '-'}", (20, 135), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (255, 255, 255), 1)


# ==================== MAIN ====================
def main():
    print("====================================================")
    print("         DEEPRACER ARUCO WAYPOINT NAVIGATOR         ")
    print("====================================================")
    print(f"[*] Fuente de camara: {CAMERA_SOURCE}")
    print("[*] Lugares configurados:")
    for marker_id, place in ARUCO_PLACES.items():
        print(f"    ID {marker_id}: {place['name']}")

    camera = create_camera()
    if not camera.is_opened():
        print("[-] No se pudo abrir la camara.")
        sys.exit(1)
    camera.start()

    api = None
    drive_sender = None
    if ENABLE_VEHICLE_CONTROL:
        api = DeepRacerAPIClient(BACKEND_URL)
        drive_sender = AsyncDriveSender(api)
        print("[*] Preparando modo manual...")
        if not api.prepare_manual():
            print("[!] Backend/manual no disponible. Continuo en modo visual.")

    try:
        aruco_dict = aruco.getPredefinedDictionary(ARUCO_DICT_TYPE)
        aruco_params = aruco.DetectorParameters()
        aruco_detector = aruco.ArucoDetector(aruco_dict, aruco_params)
        has_new_aruco = True
    except AttributeError:
        aruco_dict = aruco.Dictionary_get(ARUCO_DICT_TYPE)
        aruco_params = aruco.DetectorParameters_create()
        aruco_detector = None
        has_new_aruco = False

    ret, frame, _ = camera.read()
    deadline = time.time() + 3.0
    while not ret and time.time() < deadline:
        time.sleep(0.02)
        ret, frame, _ = camera.read()
    if not ret:
        print("[-] No se pudo leer el primer frame.")
        sys.exit(1)

    h, w = frame.shape[:2]
    camera_matrix = np.array([
        [float(w), 0.0, float(w) / 2.0],
        [0.0, float(w), float(h) / 2.0],
        [0.0, 0.0, 1.0],
    ], dtype=np.float32)
    dist_coeffs = np.zeros((5, 1), dtype=np.float32)

    command_queue = queue.Queue()
    start_console_reader(command_queue)

    safety = SafetyGate()
    current_place = ""
    destination_place = ""
    route_places = []
    route_index = 0
    active_waypoint = ""
    lost_frames = 0
    last_sent_stop = True
    steer_cmd = 0.0
    throttle_cmd = 0.0
    last_seen_ids = ()
    last_diag_text = ""

    print("\n[USO]")
    print(" -> Escribe: ve a salida / ve a impresora / ve a mesa")
    print(" -> ESPACIO: quitar/poner freno de mano")
    print(" -> q: salir y detener")
    print("----------------------------------------------------\n")

    while True:
        ret, frame, _ = camera.read()
        if not ret:
            time.sleep(0.02)
            continue

        display = frame.copy()
        update_safety_from_esp32_placeholder(safety)
        overlay = display.copy()
        cv2.rectangle(overlay, (10, 10), (620, 150), (0, 0, 0), -1)
        cv2.addWeighted(overlay, 0.5, display, 0.5, 0, display)

        while not command_queue.empty():
            text = command_queue.get()
            if is_stop_instruction(text):
                destination_place = ""
                route_places = []
                active_waypoint = ""
                route_index = 0
                steer_cmd = 0.0
                throttle_cmd = 0.0
                if ENABLE_VEHICLE_CONTROL and api is not None:
                    api.stop_vehicle()
                print("[RUTA] Detenido por orden.")
                continue

            requested_place = infer_place_from_instruction(text)
            if requested_place:
                destination_place = requested_place
                route_places = []
                active_waypoint = ""
                route_index = 0
                print(f"[RUTA] Destino solicitado: {destination_place}. Escaneando posicion...")
            else:
                print(f"[RUTA] No reconozco destino en: {text}")

        markers, rejected_count = detect_aruco_markers(
            frame,
            aruco_detector,
            aruco_dict,
            aruco_params,
            has_new_aruco,
            camera_matrix,
            dist_coeffs,
        )

        selected_marker = None
        diagnostic_message = ""
        seen_ids = tuple(sorted(marker["id"] for marker in markers))
        if seen_ids != last_seen_ids:
            print(f"[ARUCO] IDs vistos: {list(seen_ids) if seen_ids else 'ninguno'} | rechazados: {rejected_count}")
            last_seen_ids = seen_ids
        diagnostic_hits = []
        if not markers:
            diagnostic_hits = diagnose_aruco_dictionaries(frame)
            diag_text = "; ".join(f"{hit['dict']} IDs {hit['ids']}" for hit in diagnostic_hits)
            if diag_text and diag_text != last_diag_text:
                print(f"[ARUCO-DIAG] {diag_text}")
                last_diag_text = diag_text
        if markers:
            lost_frames = 0
            pose_markers = [marker for marker in markers if marker["has_pose"]]
            nearest_marker = min(pose_markers, key=lambda item: item["z"]) if pose_markers else None
            if nearest_marker is None:
                steer_cmd = 0.0
                throttle_cmd = 0.0
                diagnostic_message = "ArUco detectado sin pose: revisa tamano/angulo/luz"
            else:
                current_place = nearest_marker["place"]

            if nearest_marker is not None and destination_place and not route_places:
                route_places = shortest_place_route(current_place, destination_place)
                if route_places:
                    route_index = 1 if len(route_places) > 1 else 0
                    active_waypoint = route_places[route_index]
                    print(f"[RUTA] Estoy en {current_place}. Ruta: {' -> '.join(route_places)}")
                else:
                    print(f"[RUTA] No hay ruta desde {current_place} hasta {destination_place}.")
                    destination_place = ""
                    active_waypoint = ""

            if nearest_marker is not None and route_places and route_index < len(route_places):
                active_waypoint = route_places[route_index]
            elif nearest_marker is not None and not destination_place:
                active_waypoint = ""

            selected_marker = choose_marker(pose_markers, active_waypoint) if pose_markers else None

            if selected_marker:
                steer_cmd, throttle_cmd, close = drive_command_for_marker(selected_marker)

                if active_waypoint and selected_marker["place"] == active_waypoint and arrived_at_marker(selected_marker):
                    current_place = selected_marker["place"]
                    steer_cmd = 0.0
                    throttle_cmd = 0.0
                    if route_places and route_index < len(route_places) - 1:
                        route_index += 1
                        active_waypoint = route_places[route_index]
                        print(f"[RUTA] Llegue a {current_place}. Siguiente: {active_waypoint}")
                    elif destination_place and current_place == destination_place:
                        print(f"[RUTA] Destino alcanzado: {destination_place}")
                        destination_place = ""
                        route_places = []
                        active_waypoint = ""
                elif destination_place and active_waypoint and selected_marker["place"] != active_waypoint:
                    # Se ve otro ArUco, pero no el waypoint objetivo: usarlo para ubicacion y buscar.
                    steer_cmd = 0.0
                    throttle_cmd = 0.0

                safe_steer, safe_throttle, safety_reason = safety.filter_command(steer_cmd, throttle_cmd)

                if ENABLE_VEHICLE_CONTROL and selected_marker:
                    if safe_throttle == 0.0 and safe_steer == 0.0:
                        if not last_sent_stop:
                            drive_sender.send(0.0, 0.0, MAX_SPEED_LIMIT)
                            last_sent_stop = True
                    else:
                        drive_sender.send(safe_steer, safe_throttle, MAX_SPEED_LIMIT)
                        last_sent_stop = False
        else:
            lost_frames += 1
            if lost_frames >= LOST_TARGET_TIMEOUT_FRAMES:
                steer_cmd = 0.0
                throttle_cmd = 0.0
                if ENABLE_VEHICLE_CONTROL and not safety.paused() and not last_sent_stop:
                    drive_sender.send(0.0, 0.0, MAX_SPEED_LIMIT)
                    last_sent_stop = True

        draw_marker_debug(display, markers, selected_marker, current_place, active_waypoint, destination_place, rejected_count)
        if diagnostic_message:
            cv2.putText(display, diagnostic_message, (20, 160), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (0, 255, 255), 1)
        elif diagnostic_hits:
            diag_label = "; ".join(f"{hit['dict']} {hit['ids']}" for hit in diagnostic_hits[:2])
            cv2.putText(display, f"Detectado en otro diccionario: {diag_label}", (20, 160), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (0, 255, 255), 1)
        elif not markers:
            cv2.putText(display, f"No veo ArUco en {ARUCO_DICT_NAME}: acerca codigo o mejora luz", (20, 160), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (0, 255, 255), 1)

        status = safety.status_text()
        status_color = (0, 255, 0) if status == "ACTIVO" else (0, 0, 255)
        route_label = " -> ".join(route_places) if route_places else "-"
        cv2.putText(display, f"CONTROL: {status}", (20, 35), cv2.FONT_HERSHEY_SIMPLEX, 0.6, status_color, 2)
        cv2.putText(display, f"Ruta: {route_label}", (20, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
        cv2.putText(display, f"CMD steer:{steer_cmd:+.2f} throttle:{throttle_cmd:+.2f}", (20, h - 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 255), 1)
        if hasattr(camera, "metrics_text"):
            cv2.putText(display, camera.metrics_text(), (20, h - 45), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 255), 1)

        cv2.imshow("DeepRacer ArUco Navigator", display)
        key = cv2.waitKey(1) & 0xFF

        if key == ord(" "):
            safety.set_manual_pause(not safety.manual_pause)
            print(f"[*] Freno de mano: {'activo' if safety.manual_pause else 'liberado'}")
            if ENABLE_VEHICLE_CONTROL and api is not None:
                if not safety.manual_pause:
                    if not api.prepare_manual():
                        print("[!] No se pudo activar manual; mantengo freno.")
                        safety.set_manual_pause(True)
                else:
                    api.stop_vehicle()
                    last_sent_stop = True

        elif key == ord("q"):
            print("[*] Saliendo...")
            break

    print("[*] Deteniendo vehiculo y cerrando...")
    if ENABLE_VEHICLE_CONTROL and api is not None:
        api.stop_vehicle()
    if drive_sender is not None:
        drive_sender.stop()
    camera.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n[!] Interrumpido por usuario.")
        try:
            if ENABLE_VEHICLE_CONTROL:
                requests.post(f"{BACKEND_URL}/api/stop", json={}, timeout=1)
        except Exception:
            pass
        sys.exit(0)
