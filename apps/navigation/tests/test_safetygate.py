"""SafetyGate con entradas simuladas (sin hardware)."""
import sys
import pathlib
import time

SRC = pathlib.Path(__file__).resolve().parents[1] / "src"
sys.path.insert(0, str(SRC))

from controlcamara import SafetyGate, FORWARD_THROTTLE_SIGN  # noqa: E402


def test_freno_manual_bloquea_todo():
    gate = SafetyGate()
    gate.set_manual_pause(True)
    assert gate.filter_command(0.5, 0.7) == (0.0, 0.0, "manual")
    assert gate.status_text() == "FRENO"


def test_avance_con_freno_liberado():
    gate = SafetyGate()
    gate.set_manual_pause(False)
    steer, throttle, reason = gate.filter_command(0.3, 0.6)
    assert (steer, throttle) == (0.3, 0.6)
    assert reason == ""
    assert gate.status_text() == "ACTIVO"


def test_obstaculo_bloquea_solo_avance():
    gate = SafetyGate()
    gate.set_manual_pause(False)
    gate.update_front_distance_cm(20.0)  # < umbral 35 cm
    assert gate.filter_command(0.0, FORWARD_THROTTLE_SIGN * 0.5)[2] == "obstaculo"
    # reversa no se bloquea por obstáculo frontal
    result = gate.filter_command(0.0, -FORWARD_THROTTLE_SIGN * 0.5)
    assert result[0:2] == (0.0, -FORWARD_THROTTLE_SIGN * 0.5)
    assert gate.status_text().startswith("OBSTACULO")


def test_espera_despeje():
    gate = SafetyGate()
    gate.set_manual_pause(False)
    gate.blocked_until = time.time() + 5.0
    result = gate.filter_command(0.0, FORWARD_THROTTLE_SIGN * 0.5)
    assert result[2] == "esperando despeje"
    assert gate.status_text() == "DESPEJE"
