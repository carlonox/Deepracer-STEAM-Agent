"""Smoke test: el módulo importa y expone constantes sin GPU ni micrófono."""
import sys
import types
import pathlib
import importlib.util

# Cargar server.py por ruta absoluta con nombre de módulo único (evita
# colisión con apps/text-to-speech/src/server.py en sys.modules).
SRC = pathlib.Path(__file__).resolve().parents[1] / "src" / "server.py"

# Stubs para validar estructura sin instalar dependencias pesadas
whisper_model = type("WhisperModel", (), {"__init__": lambda self, *a, **k: None})
for name, attrs in {
    "faster_whisper": {"WhisperModel": whisper_model},
    "sounddevice": {"InputStream": type("InputStream", (), {})},
}.items():
    mod = types.ModuleType(name)
    for attr, val in attrs.items():
        setattr(mod, attr, val)
    sys.modules[name] = mod

import numpy as _np  # noqa: E402  (numpy suele estar disponible)

spec = importlib.util.spec_from_file_location("stt_server", SRC)
stt = importlib.util.module_from_spec(spec)
spec.loader.exec_module(stt)


def test_constantes():
    assert stt.SAMPLE_RATE == 16000
    assert 0 < stt.ENERGY_THRESHOLD < 1
    assert stt.MIN_SPEECH_DURATION_SEC < stt.SILENCE_DURATION_SEC + 1


def test_numpy_real():
    assert _np is not None
