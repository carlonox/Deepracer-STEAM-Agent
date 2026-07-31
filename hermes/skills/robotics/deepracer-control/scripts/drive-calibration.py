#!/usr/bin/env python3
"""drive-calibration.py — Barrido de calibración de throttle a través del backend.

Determina el umbral mínimo de movimiento y la convención de dirección del boot
actual, con ráfagas fire-and-forget (el watchdog de 200ms se muere de hambre si
esperas la respuesta de cada comando).

Uso (el contenedor llega al backend del host por host.docker.internal:5002):
    python drive-calibration.py [--base http://host.docker.internal:5002/api]
                                 [--phases +0.50 +0.55 +0.60 -0.50 -0.55 -0.60]

Protocolo de seguridad: vehículo elevado (ruedas libres) o zona despejada,
operador presente, throttle <= 0.6, stop disponible. Cada fase imprime su
marcador ANTES de la ráfaga; el operador reporta dirección por fase
(adelante/atrás/nada). Opcional: con brake-led.py corriendo en el robot, el LED
anuncia las fases (naranja=negativo, verde=positivo, morado=pausa).
"""
import argparse
import time
import requests


def parse_args():
    ap = argparse.ArgumentParser()
    ap.add_argument("--base", default="http://host.docker.internal:5002/api")
    ap.add_argument("--phases", nargs="+", type=float,
                    default=[0.50, 0.55, 0.60, -0.50, -0.55, -0.60])
    ap.add_argument("--duration", type=float, default=1.5)
    return ap.parse_args()


def main():
    args = parse_args()
    base = args.base
    s = requests.Session()
    errs = []

    def post(**kw):
        try:
            return s.post(f"{base}/manual_drive", json=kw, timeout=2).status_code
        except Exception as e:
            errs.append(str(e)[:60])
            return None

    def burst(throttle):
        t0 = time.time()
        n = 0
        while time.time() - t0 < args.duration:
            post(angle=0.0, throttle=throttle, max_speed=abs(throttle))
            n += 1
            time.sleep(0.03)
        return n

    def hold_stop(n=5):
        for _ in range(n):
            post(angle=0.0, throttle=0.0, max_speed=0.6)
            time.sleep(0.04)

    print("== init ==")
    print("init:", post(init=True))
    time.sleep(0.5)
    print("stop:", post(angle=0.0, throttle=0.0, max_speed=0.6))
    time.sleep(0.3)

    for i, thr in enumerate(args.phases, 1):
        sign = "NARANJA" if thr < 0 else "VERDE"
        print(f"=== TRAMO {i}: throttle {thr:+.2f} (LED {sign}) ===", flush=True)
        n = burst(thr)
        print(f"  -> {n} comandos", flush=True)
        hold_stop()
        time.sleep(0.6)

    print("== cierre ==")
    print("stop:", post(angle=0.0, throttle=0.0, max_speed=0.6))
    try:
        r = s.post(f"{base}/stop", timeout=3)
        print("/api/stop:", r.status_code)
    except Exception as e:
        print("/api/stop error:", e)
    print("errores:", len(errs), errs[:2] if errs else "ninguno")
    print("FIN — pedir al operador: dirección por tramo (adelante/atras/nada)")


if __name__ == "__main__":
    main()
