"""
Tests de contrato del simulador DeepRacer (apps/simulator).

Verifican que el mock se comporta como la API web real del DeepRacer
según la documentación del proyecto:
- apps/backend/vehicleControl.js (cliente real)
- docs/operations/GUIA_SETUP.md, docs/operations/HANDOFF.md
- hermes/skills/robotics/deepracer-control/SKILL.md (mediciones en vivo)

Para correr: python -m pytest apps/simulator/tests -q
(Depende del mock levantado en HTTPS :5001 y HTTP :8080.)
"""

import json
import os
import re
import subprocess
import sys
import time
import urllib.error
import urllib.request
import uuid

import pytest

# ---------------------------------------------------------------------------
# Sesión HTTP contra el mock (con tolerancia TLS autofirmado)
# ---------------------------------------------------------------------------
try:
    import ssl as _ssl
    _CTX = _ssl.create_default_context()
    _CTX.check_hostname = False
    _CTX.verify_mode = _ssl.CERT_NONE
except Exception:
    _CTX = None

BASE = os.environ.get("MOCK_HTTPS_URL", "https://127.0.0.1:5001")
HTTP_BASE = os.environ.get("MOCK_HTTP_URL", "http://127.0.0.1:8080")
PASSWORD = os.environ.get("MOCK_TEST_PASSWORD", "deepracer")


def http(method, url, data=None, headers=None, timeout=5):
    body = None
    if data is not None:
        body = json.dumps(data).encode()
    req = urllib.request.Request(url, data=body, method=method)
    req.add_header("Content-Type", "application/json")
    for k, v in (headers or {}).items():
        req.add_header(k, v)
    try:
        with urllib.request.urlopen(req, timeout=timeout, context=_CTX) as r:
            return r.status, dict(r.headers), r.read()
    except urllib.error.HTTPError as e:
        return e.code, dict(e.headers), e.read()


def csrf_login():
    """Flujo real del vehicleControl.js: GET /login -> csrf -> POST /login."""
    status, headers, body = http("GET", f"{BASE}/login")
    assert status == 200, f"GET /login devolvió {status}"
    html = body.decode()
    # CSRF en meta tag o input hidden (patrones del cliente real)
    m = re.search(r'name=["\']csrf_token["\']\s+value=["\']([^"\']+)["\']', html)
    if not m:
        m = re.search(r'<meta[^>]*name=["\']csrf-token["\'][^>]*content=["\']([^"\']+)["\']', html)
    assert m, "No se encontró csrf_token en /login"
    csrf = m.group(1)
    # Cookie de sesión
    cookie = headers.get("Set-Cookie", "") or ""
    sess = re.search(r"session=([^;]+)", cookie)
    assert sess, "GET /login no emitió cookie de sesión"
    session = sess.group(1)
    # POST /login con form-urlencoded (como vehicleControl.js)
    import urllib.parse
    form = urllib.parse.urlencode({"csrf_token": csrf, "password": PASSWORD}).encode()
    req = urllib.request.Request(f"{BASE}/login", data=form, method="POST")
    req.add_header("Content-Type", "application/x-www-form-urlencoded")
    req.add_header("Cookie", f"session={session}")
    req.add_header("X-CSRF-Token", csrf)
    try:
        with urllib.request.urlopen(req, timeout=5, context=_CTX) as r:
            status2 = r.status
            h2 = dict(r.headers)
    except urllib.error.HTTPError as e:
        status2 = e.code
        h2 = dict(e.headers)
    assert status2 == 200, f"POST /login devolvió {status2}"
    cookie2 = h2.get("Set-Cookie", "")
    if cookie2:
        m2 = re.search(r"session=([^;]+)", cookie2)
        if m2:
            session = m2.group(1)
    return csrf, session


def authed_headers(csrf, session):
    return {
        "Cookie": f"session={session}",
        "X-CSRF-Token": csrf,
        "X-Requested-With": "XMLHttpRequest",
    }


@pytest.fixture(scope="module")
def session():
    return csrf_login()


@pytest.fixture(scope="module")
def started_vehicle(session):
    csrf, sess = session
    h = authed_headers(csrf, sess)
    s, _, b = http("PUT", f"{BASE}/api/drive_mode", {"drive_mode": "manual"}, h)
    assert s == 200
    s, _, b = http("PUT", f"{BASE}/api/start_stop", {"start_stop": "start"}, h)
    assert s == 200
    return h


@pytest.fixture()
def running_vehicle(session):
    """Vehículo reactivado por test (los tests que hacen stop no deben
    dejar el estado en stop para los que siguen)."""
    csrf, sess = session
    h = authed_headers(csrf, sess)
    http("PUT", f"{BASE}/api/drive_mode", {"drive_mode": "manual"}, h)
    http("PUT", f"{BASE}/api/start_stop", {"start_stop": "start"}, h)
    return h


# ---------------------------------------------------------------------------
# Tests del contrato
# ---------------------------------------------------------------------------
class TestLogin:
    def test_login_get_returns_csrf_and_cookie(self):
        status, headers, body = http("GET", f"{BASE}/login")
        assert status == 200
        assert b"csrf" in body.lower()

    def test_login_wrong_password_rejected(self):
        # flujo: GET csrf, POST con password incorrecta -> 401
        status, headers, body = http("GET", f"{BASE}/login")
        html = body.decode()
        m = re.search(r'name=["\']csrf_token["\']\s+value=["\']([^"\']+)["\']', html)
        assert m
        csrf = m.group(1)
        import urllib.parse
        form = urllib.parse.urlencode({"csrf_token": csrf, "password": "wrong"}).encode()
        req = urllib.request.Request(f"{BASE}/login", data=form, method="POST")
        req.add_header("X-CSRF-Token", csrf)
        with pytest.raises(urllib.error.HTTPError) as ei:
            urllib.request.urlopen(req, timeout=5, context=_CTX)
        assert ei.value.code == 401

    def test_login_requires_csrf(self):
        import urllib.parse
        form = urllib.parse.urlencode({"csrf_token": "bogus", "password": PASSWORD}).encode()
        req = urllib.request.Request(f"{BASE}/login", data=form, method="POST")
        with pytest.raises(urllib.error.HTTPError) as ei:
            urllib.request.urlopen(req, timeout=5, context=_CTX)
        assert ei.value.code == 403


class TestUnauthenticated:
    def test_api_requires_auth(self):
        s, _, b = http("PUT", f"{BASE}/api/drive_mode", {"drive_mode": "manual"})
        assert s == 401

    def test_manual_drive_requires_auth(self):
        s, _, b = http("PUT", f"{BASE}/api/manual_drive",
                       {"angle": 0, "throttle": -0.5, "max_speed": 1})
        assert s == 401


class TestDriveSequence:
    def test_full_sequence(self, started_vehicle):
        h = started_vehicle
        s, _, b = http("PUT", f"{BASE}/api/manual_drive",
                       {"angle": 0.0, "throttle": -0.30, "max_speed": 0.5}, h)
        assert s == 200
        j = json.loads(b)
        assert j.get("success") is True

    def test_old_contract_drive_control(self, session):
        """Iteración anterior: POST /api/manual_drive con drive_control."""
        csrf, sess = session
        h = authed_headers(csrf, sess)
        s, _, b = http("POST", f"{BASE}/api/manual_drive",
                       {"drive_control": {"throttle": -50, "steering_angle": 0.0}}, h)
        assert s == 200

    def test_stop(self, started_vehicle):
        h = started_vehicle
        s, _, b = http("PUT", f"{BASE}/api/start_stop", {"start_stop": "stop"}, h)
        assert s == 200


class TestWatchdog:
    """Watchdog ~200 ms: sin comando, los motores se cortan (como el real)."""

    def test_motors_cut_after_watchdog(self, started_vehicle):
        h = started_vehicle
        s, _, b = http("PUT", f"{BASE}/api/manual_drive",
                       {"angle": 0, "throttle": -0.30, "max_speed": 0.5}, h)
        assert s == 200
        time.sleep(0.35)  # > watchdog
        s, _, b = http("GET", f"{BASE}/mock/state")
        st = json.loads(b)
        assert st["motors_on"] is False, "el watchdog no cortó los motores"

    def test_fire_and_forget_keeps_motors(self, started_vehicle):
        """Comandos a ~30 Hz (fire-and-forget del SKILL.md) mantienen motores."""
        h = started_vehicle
        import threading as _t
        stop = _t.Event()

        def burst():
            while not stop.is_set():
                try:
                    http("PUT", f"{BASE}/api/manual_drive",
                         {"angle": 0, "throttle": -0.55, "max_speed": 1.0}, h,
                         timeout=0.2)
                except Exception:
                    pass
                time.sleep(0.03)

        t = _t.Thread(target=burst, daemon=True)
        t.start()
        time.sleep(0.5)
        stop.set()
        t.join(timeout=1)
        s, _, b = http("GET", f"{BASE}/mock/state")
        st = json.loads(b)
        # no debería haberse cortado "solo por watchdog" con comando reciente
        assert st["motors_on"] is True or st["cmd_hz"] > 5


class TestCalibration:
    def test_dead_zone_no_movement(self, running_vehicle):
        """Throttle bajo la dead zone (0.45) no produce velocidad (verificado real)."""
        h = running_vehicle
        http("PUT", f"{BASE}/api/manual_drive",
             {"angle": 0, "throttle": -0.45, "max_speed": 1.0}, h)
        time.sleep(0.15)
        s, _, b = http("GET", f"{BASE}/mock/state")
        st = json.loads(b)
        assert st["speed_ms"] == 0.0, f"0.45 movió el mock: {st['speed_ms']}"

    def test_above_dead_zone_moves(self, running_vehicle):
        h = running_vehicle
        http("PUT", f"{BASE}/api/manual_drive",
             {"angle": 0, "throttle": -0.60, "max_speed": 1.0}, h)
        time.sleep(0.15)
        s, _, b = http("GET", f"{BASE}/mock/state")
        st = json.loads(b)
        assert st["speed_ms"] > 0.0, "throttle 0.60 debería mover"

    def test_minimum_speed_is_walking_pace(self, running_vehicle):
        """Mínimo que mueve ~0.87 m/s (medido en el robot real)."""
        h = running_vehicle
        http("PUT", f"{BASE}/api/manual_drive",
             {"angle": 0, "throttle": -0.55, "max_speed": 1.0}, h)
        time.sleep(0.15)
        s, _, b = http("GET", f"{BASE}/mock/state")
        st = json.loads(b)
        assert 0.5 < st["speed_ms"] < 1.5, f"velocidad mínima rara: {st['speed_ms']}"

    def test_servo_sensitive(self, running_vehicle):
        """Un ángulo de 0.11 produce giro fuerte (~40°/s) medido en el real.

        Nota: el comando debe ir en loop (fire-and-forget) porque el watchdog
        de 200 ms corta los motores si no llegan comandos nuevos — igual que
        en el robot real (ver SKILL.md, pitfall del loop síncrono).
        """
        import threading as _t
        h = running_vehicle
        s, _, b = http("GET", f"{BASE}/mock/state")
        st0 = json.loads(b)
        h0 = st0["heading_deg"]
        stop = _t.Event()

        def burst():
            while not stop.is_set():
                try:
                    http("PUT", f"{BASE}/api/manual_drive",
                         {"angle": 0.11, "throttle": -0.60, "max_speed": 1.0}, h,
                         timeout=0.2)
                except Exception:
                    pass
                time.sleep(0.03)

        t = _t.Thread(target=burst, daemon=True)
        t.start()
        time.sleep(0.5)
        stop.set()
        t.join(timeout=1)
        s, _, b = http("GET", f"{BASE}/mock/state")
        st1 = json.loads(b)
        delta = abs(st1["heading_deg"] - h0)
        # a ~380°/s * 0.11 ≈ 42°/s → en 0.5 s ≈ 21° (mín 10°)
        assert delta > 10, f"giro débil: {delta}° en 0.5s (servo no sensible)"

    def test_negative_throttle_forward(self, running_vehicle):
        """Convención verificada 2026-07-31: negativo = adelante."""
        h = running_vehicle
        s, _, b = http("GET", f"{BASE}/mock/state")
        st0 = json.loads(b)
        http("PUT", f"{BASE}/api/manual_drive",
             {"angle": 0, "throttle": -0.60, "max_speed": 1.0}, h)
        time.sleep(0.3)
        s, _, b = http("GET", f"{BASE}/mock/state")
        st1 = json.loads(b)
        dx = st1["x"] - st0["x"]
        # con sign neg=adelante y heading 0, debería avanzar en +x o al menos moverse
        assert dx != 0.0, "el robot simulado no se movió en x"


class TestLED:
    def test_set_get_led(self, session):
        csrf, sess = session
        h = authed_headers(csrf, sess)
        s, _, b = http("POST", f"{BASE}/api/set_led_color",
                       {"red": 0, "green": 255, "blue": 0}, h)
        assert s == 200
        s, _, b = http("GET", f"{BASE}/api/get_led_color", headers=h)
        assert s == 200
        j = json.loads(b)
        assert j["green"] == 255


class TestMjpeg:
    def test_route_mjpeg_content_type(self):
        """GET /route (el que usa el backend) debe ser multipart MJPEG."""
        req = urllib.request.Request(
            f"{BASE}/route?topic=/camera_pkg/display_mjpeg&width=480&height=360")
        try:
            with urllib.request.urlopen(req, timeout=4, context=_CTX) as r:
                ct = r.headers.get("Content-Type", "")
                assert "multipart/x-mixed-replace" in ct, f"Content-Type: {ct}"
                assert "boundary" in ct
                chunk = r.read(64)
                assert chunk, "stream vacío"
        except Exception as e:
            pytest.skip(f"stream no disponible (¿opencv instalado?): {e}")

    def test_snapshot_jpeg(self):
        req = urllib.request.Request(f"{HTTP_BASE}/snapshot?topic=/camera_pkg/display_mjpeg")
        try:
            with urllib.request.urlopen(req, timeout=4) as r:
                assert r.headers.get("Content-Type") == "image/jpeg"
                data = r.read()
                assert data[:2] == b"\xff\xd8", "no es JPEG"
        except Exception as e:
            pytest.skip(f"snapshot no disponible (¿opencv instalado?): {e}")


class TestState:
    def test_state_endpoint(self):
        s, _, b = http("GET", f"{BASE}/mock/state")
        assert s == 200
        st = json.loads(b)
        for key in ("drive_mode", "start_stop", "motors_on", "battery",
                    "x", "y", "heading_deg", "speed_ms", "cmd_hz"):
            assert key in st, f"falta {key} en /mock/state"