# Zona muerta del throttle — calibración y verificación (2026-07-31)

Sesión en la que se descubrió que este robot NO mueve los motores con
`|throttle| < 0.5` (crudo), se implementó la compensación en el backend y se
verificó en vivo. Robot: LAN `10.203.191.86` / Tailscale `100.117.192.31`,
convención de ese boot: **negativo = adelante** (coincide con GUIA_SETUP/HANDOFF).

## Datos medidos (barrido con ruedas libres)

| Throttle crudo | Resultado |
|:--------------:|:---------:|
| ±0.45 | ❌ nada (ambas direcciones) |
| +0.50 | ✅ retroceso (creíble; ver anomalía abajo) |
| +0.55 | ❌ nada * |
| +0.60 | ❌ nada * |
| -0.50 / -0.55 / -0.60 | ✅ avance |

\* **Anomalía NO monótona = obstáculo físico, no umbral**: en el barrido, el
robot estaba en el suelo; tras el tramo +0.50 (retroceso) se topó con algo
detrás y los tramos +0.55/+0.60 quedaron bloqueados. Repetido con espacio
(+0.60 en el test con LED), sí se movió. Conclusión: ante un barrido no
monótono, preguntar por el entorno / reubicar el robot antes de declarar motor
muerto.

Conclusión: **mínimo efectivo ≈ |0.50| crudo** (0.45 no, 0.50 sí). El umbral
puede subir con batería baja.

## Implementación de la compensación

- `apps/backend/vehicleControl.js`: `calibrateThrottle(t)` exportada
  ```
  throttle_real = sign(t) * (DZ + (1 - DZ) * |t|)   # DZ = THROTTLE_DEAD_ZONE (env, default 0.5)
  ```
  - `0` → `0` (parada explícita, intacta).
  - Signo preservado (la dirección la decide el consumidor, se verifica por boot).
  - Aplicada en `manualDrive()` — el mismo punto por el que pasan HTTP y TCP.
  - Unit test (node): 0→0, 0.1→0.55, 0.5→0.75, 1→1, -0.1→-0.55, -0.5→-0.75, -1→-1, 0.3→0.65 — 8/8 OK.
- `THROTTLE_DEAD_ZONE=0.5` añadido a `.env` (real) y `.env.example` (público).
- Scripts robot-side (hablan directo con la API local, BYPASS del backend):
  - `drive-daemon.py`: `cal()` aplicada en `send_drive`; COMMANDS en normalizado
    (forward 0.30→real 0.65, fast 0.70→0.85, back -0.20→-0.60).
  - `explorer.py`: `cal()` en `go()`; GO -0.10→real -0.55 (igual que antes),
    backup +0.10→+0.55 (¡antes 0.40 estaba en zona muerta y no retrocedía!),
    reverse-turn -0.05→-0.525.
- `apps/navigation/src/controlcamara.py`: constantes normalizadas (el tráfico
  pasa por el backend): `ARUCO_FAST_THROTTLE` 0.70→0.40 (real 0.70),
  `ARUCO_MIN_THROTTLE` 0.60→0.20 (real 0.60), `ARUCO_REVERSE_THROTTLE` 0.60→0.20.

## Ritmo de envío a través del backend (clave del watchdog)

| Patrón | Comandos | Resultado |
|--------|:--------:|:---------:|
| Síncrono (esperar respuesta por comando) | 9 en 1.5 s ≈ 6 Hz | ❌ sin movimiento |
| Fire-and-forget (timeout corto, sleep 0.03) | 20-30 en 1.5-2 s ≈ 15 Hz | ✅ movimiento |
| Fire-and-forget (corrida degradada) | 11 en 2 s ≈ 4.5 Hz | ⚠️ al borde — vigilar |

Regla práctica: si la fase imprime < ~10 comandos/s, sospechar watchdog (ritmo),
no motores. Solo `init` y el `stop` final necesitan confirmación síncrona.

## Verificación física final (ruedas libres, backend reiniciado)

Normalizado -0.10 (real -0.55) → avance lento ✓; -0.30 (real -0.65) → avance ✓;
+0.10 (real +0.55) → retroceso ✓. **0.1 normalizado = movimiento real.**

## Notas de despliegue usadas en la sesión

- Daemon robot-side necesita `DEEPRACER_API_PASSWORD`: escribir la contraseña a
  `/tmp/drive_pw` (chmod 600) vía SFTP y expandirla DENTRO del comando del robot
  (`DEEPRACER_API_PASSWORD="$(cat /tmp/drive_pw)" nohup python3 ...`) para que
  el secreto no aparezca en la línea de comando.
- `exec_command` con `nohup ... &` cuelga el `stdout.read()` (fds heredados):
  verificar con conexión NUEVA (`pgrep -f <script>` + `tail <log>`).
- `brake-led.py` (anunciador de fases por LED): arrancó con `c1 ready`/`c2
  ready` pero **el LED no cambió durante el barrido** — no fiable como señal
  de fase.
