#!/usr/bin/env python3
"""
Lanzador de compatibilidad de apps/navigation/src/controlcamara.py.

Este archivo conserva la ruta histórica de la raíz para no romper comandos,
documentos y skills que invocan `py controlcamara.py`. La implementación real
vive en apps/navigation/src/controlcamara.py.
"""
import pathlib
import runpy
import sys

REAL = pathlib.Path(__file__).resolve().parent / "apps" / "navigation" / "src" / "controlcamara.py"
sys.path.insert(0, str(REAL.parent))
runpy.run_path(str(REAL), run_name="__main__")
