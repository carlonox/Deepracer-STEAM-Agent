"""Reensamblaje UDP de la cámara ESP32 con paquetes sintéticos."""
import sys
import pathlib
import struct
import time

SRC = pathlib.Path(__file__).resolve().parents[1] / "src"
sys.path.insert(0, str(SRC))

from controlcamara import ESP32UdpJpegCamera  # noqa: E402

import cv2
import numpy as np


def _jpeg_bytes():
    frame = np.zeros((16, 16, 3), dtype=np.uint8)
    frame[:, :, 1] = 200  # verde, compresible
    ok, buf = cv2.imencode(".jpg", frame)
    assert ok
    return buf.tobytes()


def _make_camera():
    cam = ESP32UdpJpegCamera.__new__(ESP32UdpJpegCamera)
    cam.frame_timeout = 1.0
    cam.current_frame_id = -1
    cam.pending = None
    cam.frames_decoded = 0
    cam.frames_dropped = 0
    cam.frame = None
    cam.timestamp = 0.0
    cam.last_fps_time = time.time()
    cam.fps = 0.0
    cam.last_latency_ms = 0.0
    cam.lock = __import__("threading").Lock()
    return cam


def _chunk(frame_id, index, count, payload, ts=0):
    hdr = struct.pack("!IHHHI", frame_id, index, count, len(payload), ts)
    return hdr + payload


def test_jpeg_completo_en_un_datagrama():
    cam = _make_camera()
    jpeg = _jpeg_bytes()
    cam._handle_packet(jpeg)
    assert cam.frames_decoded == 1
    assert cam.frame is not None


def _split3(jpeg):
    n = len(jpeg)
    third = max(1, n // 3)
    return [jpeg[:third], jpeg[third:2 * third], jpeg[2 * third:]]


def test_reensambla_ordenado():
    cam = _make_camera()
    chunks = _split3(_jpeg_bytes())
    for i, c in enumerate(chunks):
        cam._handle_packet(_chunk(7, i, 3, c))
    assert cam.frames_decoded == 1
    assert cam.frame is not None
    assert cam.pending is None


def test_reensambla_fuera_de_orden():
    cam = _make_camera()
    chunks = _split3(_jpeg_bytes())
    for i in (2, 0, 1):
        cam._handle_packet(_chunk(7, i, 3, chunks[i]))
    assert cam.frames_decoded == 1
    assert cam.frame is not None


def test_duplicados_no_rompen():
    cam = _make_camera()
    jpeg = _jpeg_bytes()
    chunks = [jpeg[:len(jpeg) // 2], jpeg[len(jpeg) // 2:]]
    cam._handle_packet(_chunk(7, 0, 2, chunks[0]))
    cam._handle_packet(_chunk(7, 0, 2, chunks[0]))  # duplicado
    cam._handle_packet(_chunk(7, 1, 2, chunks[1]))
    assert cam.frames_decoded == 1
    assert cam.frame is not None


def test_fragmento_incompleto_no_decodifica():
    cam = _make_camera()
    cam._handle_packet(_chunk(7, 0, 3, _jpeg_bytes()[:40]))
    assert cam.frames_decoded == 0
    assert cam.pending is not None


def test_frame_id_anterior_se_descarta():
    cam = _make_camera()
    cam.current_frame_id = 10
    cam._handle_packet(_chunk(5, 0, 1, b"AA"))
    assert cam.frames_dropped == 1
    assert cam.frames_decoded == 0


def test_paquete_corto_se_ignora():
    cam = _make_camera()
    cam._handle_packet(b"\x00" * 5)
    assert cam.frames_decoded == 0


def test_payload_sobredimensionado_se_descarta():
    cam = _make_camera()
    big = _chunk(7, 0, 3, b"A" * 65535)  # 65535*3 > ESP32_MAX_FRAME_BYTES
    cam._handle_packet(big)
    assert cam.frames_dropped == 1
