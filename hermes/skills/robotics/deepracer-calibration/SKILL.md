---
name: deepracer-calibration
description: "Calibrate an AWS DeepRacer: throttle dead zone, steering trim (STRAIGHT_ANGLE_OFFSET), real speed measurements, live calibration protocol. Verified 2026-07-31 on this robot."
version: 1.0.0
author: Hermes Agent
platforms: [linux, macos, windows]
metadata:
  hermes:
    tags: [deepracer, robotics, calibration, servo]
---

# DeepRacer Calibration

Calibration side of `deepracer-control` (split 2026-09-08, Fase 6).
Verbatim move — every number below was measured live 2026-07-31 on this
robot. Movement channel and procedures are in `deepracer-motor-control`.

### 🎯 Steering Trim (servo) — verified 2026-07-31

With angle=0 this robot drifts RIGHT ~4.4° per 1.9 m (~2°/s at real -0.65;
measured: 14.5 cm lateral in 190.5 cm forward). Compensation: the backend adds
`STRAIGHT_ANGLE_OFFSET` (`.env`, default 0) to every angle, and can be tuned
**live** via `POST /api/calibration {"angle_offset": X}` (no restart; GET
returns the active values).

⚠️ **The steering is EXTREMELY sensitive near center** — measured:
- offset `-0.11` → ~40°/s left turn (90° in 2.2 s! radius ~1.2 m)
- offset `-0.01` → still a clear left turn
- Linear estimate for zero drift ≈ **-0.005**, but iterate from **-0.002/-0.003**
  (tiny values; the gain near center may be nonlinear and battery-dependent).

Tuning loop: run 2 s at -0.30 normalized (real -0.65), measure lateral
deviation, adjust via POST /api/calibration, rerun. No restarts needed.

### 📏 Real Speed Measurements — verified 2026-07-31

Ground truth with tape + timed bursts (watchdog decay ~0.2 s):

| Throttle real | Measured speed | Notes |
|:---:|:---:|---|
| -0.55 (normalized -0.10) | ~0.87 m/s | "minimum moving" is NOT slow |
| -0.65 (normalized -0.30) | ~0.83 m/s | within measurement noise of the above |
| 0 | 0 | |

Implications: the speed curve is nearly flat at the low end (or measurements
are too coarse); max speed is probably ~1.6-2 m/s. Even the minimum moving
throttle is walking pace — autonomous exploration must respect this (real 0.55
≈ 0.9 m/s, not a crawl). Same test also showed the right drift above.

### 🎛️ Calibration: Throttle Dead Zone (verified 2026-07-31)

This robot has a **dead zone of ~|0.5|**: raw throttles between 0 and ~0.5 do
NOT move the motors (verified live: 0.45 no movement, 0.50 moves, both
directions). Causes: `|0.50|` is the minimum usable throttle.

**Normalized semantics** (interfaces through the local backend `apps/backend`):
consumers send throttle in `[-1, 1]` where 0 = stop and |v|>0 = movement; the
backend stretches it to the real range `[THROTTLE_DEAD_ZONE, 1]`:

```
throttle_real = sign(v) * (DZ + (1 - DZ) * |v|)     # DZ = THROTTLE_DEAD_ZONE (default 0.5)
normalized 0.1 → real 0.55 | 0.3 → 0.65 | 0.5 → 0.75 | 1 → 1
```

- `THROTTLE_DEAD_ZONE` configurable in the root `.env` (0-0.95; raise it when
  the battery is low — the dead zone grows).
- `0` always stays `0` (explicit stop for the watchdog).
- Sign (direction) is preserved: the negative=forward convention is per-boot
  and chosen by the consumer.
- Robot-side scripts that talk to the robot's local API directly (drive daemon,
  explorer) implement the same `cal()` curve internally with normalized
  constants.

Detalle completo de la sesión (datos del barrido, implementación en backend/
daemon/explorer/controlcamara, ritmos medidos): `../deepracer-control/references/throttle-dead-zone-2026-07-31.md`.

### 🎛️ Calibration: Steering Trim (STRAIGHT_ANGLE_OFFSET, 2026-07-31)

This robot **drifts right** with `angle=0`: measured **14.5 cm lateral over
190.5 cm forward ≈ 4.4° heading error** (~1.9°/s at real -0.65). The backend
applies a steering trim before sending (`calibrateAngle` in
`apps/backend/vehicleControl.js`):

```
angle_real = clamp(angle + STRAIGHT_ANGLE_OFFSET, -1, 1)
```

**🔴 CRITICAL — the servo is EXTREMELY sensitive, an order of magnitude more
than intuition suggests.** Verified live: offset **-0.11 → ~40°/s yaw → a
literal 90° turn in 2.2 s** (gain ≈ 380°/s per 1.0 of angle). A trim that
"should" be a gentle correction can spin the robot. The linear fit from two
measured points (0 → +2°/s right; -0.11 → -40°/s left) predicts the straight
trim at ≈ **-0.005**, and even **-0.01 visibly over-turns left**.

- **Start tiny: -0.005 to -0.01, iterate in ±0.005 steps** (NOT ±0.03). Never
  jump to -0.1. The trim also shifts with battery, surface, tire wear.
- `STRAIGHT_ANGLE_OFFSET` in the root `.env` is the startup default (negative
  = corrects right drift; default 0 = no trim).
- **Runtime tuning without restarts**: the backend exposes
  `GET /api/calibration` (active values) and
  `POST /api/calibration {"angle_offset": X}` (in-memory override until
  restart). Always GET first — a backend that wasn't actually restarted still
  runs the old offset (check `uptime_s` in `/api/health` to disambiguate).
- Same choke point as the throttle calibration: everything through the backend
  (frontend, agent, navigation) gets the trim. Robot-side scripts (daemon,
  explorer) do NOT have it — add their own constant if needed.
- The "true" fix is physical servo-center calibration in the robot's dashboard
  (calibration_drive topic); the software trim is the immediate, reversible
  option and the project's current approach.
- Detalle y mediciones: `../deepracer-control/references/steering-trim-2026-07-31.md`.

### 📏 Real Speeds Measured (2026-07-31, floor tape + fixed-duration burst)

This robot is **fast even at its minimum moving throttle**: real -0.55 (=
normalized -0.10) traveled **191 cm in 2.2 s ≈ 0.87 m/s**. Second point
measured the same day: real -0.65 (= normalized -0.30) traveled **190.5 cm in
2.31 s ≈ 0.83 m/s** — both runs sit within measurement noise (±5-10 %), so the
throttle→speed curve looks flat in [0.55, 0.65]; do not trust single-run
differences below ~0.1 m/s. Max speed estimated at **1.6-2 m/s** (roughly
linear throttle→speed). No odometry/IMU exists on this robot (see hardware
audit) — speed must be measured externally.

**Safety implication:** any command that actually moves this robot moves it at
walking pace or faster. The old "slow crawl 0.35 real" docs values sat in the
dead zone and never moved; the minimum that moves (real ≥0.5) is already 🟡
caution speed. Never assume "low throttle = crawl" on this hardware; account
for ~0.9 m/s minimum motion in autonomous exploration.

**Speed measurement protocol (proven):**
1. Tape measure on the floor, clear straight zone, robot on the ground,
   operator watching (same reference point — front bumper — at start and end).
2. Drive a **fixed-duration burst**: fire-and-forget loop with a
   `time.monotonic()` deadline (e.g. 2.0 s), then send stops.
3. The watchdog stops motors ~0.2 s after the last command → travel time ≈
   burst_duration + 0.2 s. `speed = distance / (burst_duration + 0.2)`.
4. Two points (e.g. real -0.55 and -0.65) + 0 m/s at 0 are enough to build a
   usable speed map for planning.

### 📏 Calibración medida en vivo (2026-07-31, mismo boot)

> ⚠️ Normalized values (through the backend). Raw values are shown in
> parentheses. Values below ~0.5 raw / 0.05 normalized sit in the dead zone and
> will NOT move this robot.
> ```python
> def burst(throttle, seconds, base):
>     t0 = time.time()
>     while time.time() - t0 < seconds:
>         try:
>             requests.post(f"{base}/manual_drive",
>                           json={"angle": 0.0, "throttle": throttle, "max_speed": 0.5},
>                           timeout=0.05)
>         except Exception:
>             pass  # fire-and-forget: la petición ya fue enviada
>         time.sleep(0.03)
> ```
> Sequence that works: `init` → throttle-0 check → burst(+0.45, 2s) → hold stop → burst(-0.45, 2s) → stop + `/api/stop`. The API returns 200 even with **no motor power** — if wheels don't turn with a correct-rate burst, it's hardware (LiPo/button), not software.

> **📏 Calibración medida en vivo (2026-07-31, mismo boot):** ±0.45 NO movió
> nada; ±0.50, ±0.55 y ±0.60 SÍ movieron (el mínimo efectivo fue ~0.50, no 0.3).
> El umbral depende del estado (batería) — cuando un throttle bajo "no hace
> nada", **sube el barrido hasta ±0.60 antes de declarar hardware**. Convención
> confirmada ese boot: **negativo = adelante** (coincide con GUIA_SETUP/HANDOFF;
> `drive_test.py` viejo con positivo=adelante está obsoleto). La frecuencia
> efectiva puede degradarse (medida 4.5 Hz en una corrida): si una fase no mueve,
> calcula comandos/segundo — bajo ~10 Hz sospecha watchdog, no motores.
>
> **🚧 Robot en el suelo ≠ ruedas libres:** una fase "sin movimiento" puede ser
> un **bloqueo físico** (el robot retrocedió contra una pared/pata de silla en la
> fase anterior). Pregunta al usuario por el entorno antes de concluir motor
> muerto. Prueba el protocolo: robot elevado o zona despejada + operador viendo.
>
> **💡 Anunciador de fases por LED:** con `brake-led.py` corriendo en el robot,
> el LED trasero muestra 🟠 naranja con throttle negativo, 🟢 verde con positivo,
> 🟣 morado detenido — úsalo para anunciar fases al usuario durante un barrido
> (él mira el LED y reporta las ruedas). OJO: las etiquetas del nodo asumen
> positivo=adelante, así que en un robot negativo=adelante el **LED naranja =
> avance físico**. Barrido reutilizable: `../deepracer-control/scripts/drive-calibration.py`.
> **Medido en vivo: el LED NO cambió durante el barrido aunque el nodo reportaba
> `c1 ready`/`c2 ready`** — el anunciador LED no es fiable como señal de fase
> (el override del webserver o la suscripción no ganan); no diseñes un test que
> dependa de él, usa los prints del script como referencia temporal y el
> usuario reporta lo que ve.

### Direction Test (per-boot, obligatorio)

### 🎯 #1 Pitfall: Throttle convention flips between reboots

**This is the single most common cause of "robot doesn't move" in this project.** The DeepRacer web API's throttle convention can change **between reboots** on the same robot:

- On **this robot** (2026-07-10): **negative = forward**, positive = reverse
- On other units / earlier sessions: positive = forward, negative = reverse
- The project's own `drive_test.py` uses positive=forward (throttle=0.7)
- The convention can flip **after a reboot** without warning

**🔴 ALWAYS diagnose before driving.** Do NOT assume from memory:

| Interface | Forward | Reverse |
|-----------|:-------:|:-------:|
| **ROS2** (`/cmd_vel`, `ctrl_pkg`) | **negative** (polarity=-1) | positive |
| **Web API** on THIS robot (as of 2026-07-10) | **negative** | positive |
| **Web API** on some robots | positive | negative |
| **Project's old `drive_test.py`** | **positive** (throttle=0.7) | negative |

**🔴 ALWAYS diagnose before driving.** The convention can change between sessions. Do NOT assume from memory:

```bash
# Quick direction test — run on the robot
echo 'throttle=+0.3' && sleep 1 && echo 'throttle=-0.3'
# Observe which direction is forward — update your daemon's COMMANDS dict
```

Update the drive daemon's `COMMANDS` dict accordingly. This is a known quirk on this hardware.

**The `/webserver_pkg/manual_drive` ROS2 topic reflects the raw API value** as sent, before any polarity inversion. So if the API sends `throttle=-0.5` and that moves the robot forward, the topic will show `throttle=-0.5`. The brake LED node subscribes to this topic and uses the raw value.

The throttle convention can flip between reboots — always test before driving.
Also note: the drive daemon's source header (`../deepracer-control/scripts/drive-daemon.py` line 8)
claims `POSITIVE = forward`, but this robot was confirmed negative=forward.
The header comment is aspirational, not authoritative — the actual convention
depends on motor calibration polarity (`polarity: -1`). Always test direction
before accepting the daemon's header comment.
