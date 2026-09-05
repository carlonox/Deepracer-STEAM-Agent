"""
conftest del simulador: levanta el mock automáticamente si no está corriendo.

Así los tests funcionan en CI (donde nadie levantó el mock) y en local
(si ya lo tenés corriendo, lo reutiliza; si no, lo arranca y lo mata al final).
"""

import os
import socket
import subprocess
import sys
import time

import pytest

MOCK_HTTPS_PORT = int(os.environ.get("DEEPRACER_API_PORT", "5001"))
MOCK_HTTP_PORT = int(os.environ.get("MOCK_HTTP_PORT", "8080"))
MOCK_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def port_open(port: int, host: str = "127.0.0.1") -> bool:
    try:
        with socket.create_connection((host, port), timeout=1):
            return True
    except OSError:
        return False


@pytest.fixture(scope="session", autouse=True)
def mock_server():
    running = port_open(MOCK_HTTPS_PORT) and port_open(MOCK_HTTP_PORT)
    proc = None
    if not running:
        # levantar el mock con el python actual (el entorno debe tener
        # opencv para el stream; el resto del contrato funciona sin él)
        env = dict(os.environ)
        env["DEEPRACER_API_PORT"] = str(MOCK_HTTPS_PORT)
        env["MOCK_HTTP_PORT"] = str(MOCK_HTTP_PORT)
        proc = subprocess.Popen(
            [sys.executable, os.path.join(MOCK_DIR, "deepracer_mock.py")],
            cwd=MOCK_DIR, env=env,
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
        )
        # esperar a que levante (máx 15 s)
        for _ in range(30):
            if port_open(MOCK_HTTPS_PORT):
                break
            time.sleep(0.5)
        else:
            proc.kill()
            pytest.fail("el mock no levantó en 15 s")
        time.sleep(0.5)  # dejar que genere el cert y los threads arranquen
    yield
    if proc is not None:
        proc.terminate()
        try:
            proc.wait(timeout=5)
        except subprocess.TimeoutExpired:
            proc.kill()