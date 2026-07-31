"""Smoke test: el módulo importa y expone sus constantes sin generar audio."""
import sys
import types
import pathlib
import importlib.util

# Cargar server.py por ruta absoluta con nombre de módulo único (evita
# colisión con apps/speech-to-text/src/server.py en sys.modules).
SRC = pathlib.Path(__file__).resolve().parents[1] / "src" / "server.py"

# Stub de dependencias pesadas para validar estructura sin instalarlas
for name in ("edge_tts", "pydub"):
    mod = types.ModuleType(name)
    if name == "edge_tts":
        class _Communicate:
            def __init__(self, *a, **k): pass
            async def save(self, *a, **k): pass
        mod.Communicate = _Communicate
    else:
        class _AudioSegment:
            @classmethod
            def from_file(cls, *a, **k): return cls()
            def set_frame_rate(self, *a, **k): return self
            def set_channels(self, *a, **k): return self
            def set_sample_width(self, *a, **k): return self
            def export(self, *a, **k): return None
        mod.AudioSegment = _AudioSegment
    sys.modules[name] = mod

spec = importlib.util.spec_from_file_location("tts_server", SRC)
tts = importlib.util.module_from_spec(spec)
spec.loader.exec_module(tts)


def test_constantes():
    assert tts.VOZ == "es-CO-SalomeNeural"
    assert tts.ARCHIVO_FINAL == "audio_prueba.mp3"
    assert tts.TEXTO
