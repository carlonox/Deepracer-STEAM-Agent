---
name: deepracer-motor-control
description: "Drive an AWS DeepRacer: backend-only movement channel, drive sequence, watchdog, drive daemon, safety limits, autonomous explorer, LED state signaling. Calibrations live in deepracer-calibration."
version: 1.0.0
author: Hermes Agent
platforms: [linux, macos, windows]
metadata:
  hermes:
    tags: [deepracer, robotics, motor-control, hardware-control]
---

# DeepRacer Motor Control

Movement side of `deepracer-control` (split 2026-09-08, Fase 6). Verbatim
move — the verified 2026-07-31 measurements live here unchanged. Numbers,
calibration curves and the live-trim protocol are in `deepracer-calibration`;
camera perception is in `deepracer-vision`; connectivity/diagnostics are in
`deepracer-troubleshooting`.

## Architecture Overview

```
[Hermes Agent (Docker)] ──LAN──▶ [DeepRacer Robot]
    │                                  │
    │  (no Tailscale access)           ├── SSH (port 22)
    │                                  ├── Web API (port 5001)
    │                                  └── Camera stream (port 8080)
    │
    ├── [Backend Proxy (Node.js)] ──▶ [DeepRacer]   (when Docker can't reach robot directly)
    │       port 5002
    │
    └── [Dashboard] port 9999
```

### Key Networking Facts

- **Docker containers usually CANNOT reach Tailscale IPs** of the DeepRacer. They can reach the **LAN IP** if on the same physical network.
- The **LAN IP** works for SSH (port 22) and camera stream (port 8080) from Docker. The web API (port 5001) is typically **firewalled** from Docker containers.
- When Docker can't reach the robot, deploy the **Node.js backend proxy** on the Windows/Linux host and have Hermes call `POST /api/exec`.
- **Port reachability from Docker**: ✅ SSH (22), ✅ Camera stream (8080), ❌ Web API (5001). Use SSH+paramiko or the backend proxy for control commands.

## Physical Setup

### ⚡ Two Separate Power Systems (CRITICAL)

The DeepRacer has **two independent power systems** — both must be connected for movement:

| System | Powers | Connector | Monitored? |
|--------|--------|-----------|:----------:|
| 💻 **Compute** | Ubuntu, ROS2, WiFi, LEDs | USB-C (power bank or wall charger) | ❌ No (standard USB, no data pins) |
| ⚡ **Motors** | Drive motor + steering servo | **White 2-pin connector** (LiPo battery) | ✅ Via I2C (`/i2c_pkg/battery_level`) |

**Without the LiPo chassis battery connected, the motors have no power** even though the computer boots, the web API returns `{"success": true}`, and the purple LED is on. The wall charger / power bank only powers the computer.

### 🔘 Physical Motor Enable Button

The DeepRacer has a **small push button on the main circuit board** that physically enables the motors. This button must be pressed after boot — it's a hardware safety interlock. Without pressing it, `PUT /api/drive_mode` and `PUT /api/start_stop` return `{"success": true}` but **no power reaches the motors**.

### Setup Steps

1. **Connect both power sources:** USB-C (compute) AND LiPo battery (motors)
2. **Press the motor enable button** on the main board (small tactile switch near battery connector)
3. **Connect monitor** via HDMI + USB mouse
4. **Wait ~1-2 min** for boot — purple LED means compute is ready
5. **Get IP:** run `ip addr show` in a terminal on the monitor, look for `wlan0` or `eth0`
6. Both robot and computer must be on the **same WiFi network**

> **🕳️ Pitfall — \"Robot doesn't move\" is usually a power issue first, a software issue second.** If the web API returns `{"success": true}` for all commands but nothing moves, check: (1) Is the LiPo battery connected? (2) Is the motor enable button pressed? Only then debug throttle convention or watchdog loops.

## Web API Login Flow (CSRF)

The DeepRacer's web server uses a CSRF-protected login:

1. `GET /login` → extract CSRF token from `<meta name="csrf-token"` or `<input name="csrf_token"`
2. `POST /login` with body `csrf_token=<TOKEN>&password=${DEEPRACER_API_PASSWORD}` and header `X-CSRF-Token: <TOKEN>`
3. Session cookie has `Secure` flag — must be injected manually for HTTP requests

## Movement Control

### 🔀 Control path preference (user, 2026-07-31 — explicit twice)

**ALL driving goes through the Node backend (`apps/backend`, port 5002) —
NEVER SSH for movement.** The user said it plainly: "para controlar el robot
usas el backend de node... nada de ssh". SSH is for maintenance/diagnostics
only (clock sync, firewall, deploying robot-side scripts, hardware checks).
The backend applies throttle calibration (`THROTTLE_DEAD_ZONE`) and steering
trim (`STRAIGHT_ANGLE_OFFSET`) automatically; robot-side scripts (daemon,
explorer) that talk to the robot's local API must replicate the calibration
functions if used at all.

### Required Sequence (always follow this order)

```
PUT /api/drive_mode   { "drive_mode": "manual" }    # 1. Switch to manual mode
PUT /api/start_stop   { "start_stop": "start" }     # 2. Enable motors
PUT /api/manual_drive { "angle": X, "throttle": Y, "max_speed": Z }  # 3. Move (repeat in loop)
```

### Parameters

| Field | Range | Description |
|-------|-------|-------------|
| `angle` | -1.0 to 1.0 | Negative = left, Positive = right |
| `throttle` | -1.0 to 1.0 | ⚠️ **CONVENTION VARIES — ALWAYS TEST FIRST.** This robot's web API was proven (2026-07-10 session) to use **negative = forward** (throttle=-0.5 goes forward). However, earlier sessions found positive=forward, and the project's own `drive_test.py` uses throttle=+0.7 for forward. The convention can flip between reboots. **Always run a direction test** (`throttle=+0.3` then `throttle=-0.3`, observe which is forward) before assuming. The ROS2 convention (polarity=-1 calibration) is consistently negative=forward. See `#1 Pitfall` in `deepracer-calibration`. |
| `max_speed` | 0.0 to 1.0 | Speed limit fraction |

### ⚠️ Watchdog Timer

The firmware has a **~200ms watchdog**. If no new command arrives within that window, motors stop automatically. Commands must be sent in a tight loop **without sleep/pause** between them (50-100ms interval recommended).

**🕳️ Pitfall — synchronous command loops starve the watchdog (verified 2026-07-31).**
Waiting for each API response (container → backend → robot → back) yields only
~5-10 Hz effective (one command every ~170-220 ms) — right at/over the 200 ms
watchdog edge: the motors keep cutting and the robot does NOT move (or only
twitches), even with correct throttle, motors enabled, and commands returning
200. Fix: **fire-and-forget** — POST without waiting for the response
(`requests.post(..., timeout=0.05)` in a loop with `sleep(0.03)`, ~15-30 Hz
attempted). Proven live: synchronous loop = no movement at real -0.65;
fire-and-forget at the same throttle = moves. When the command count per
second drops below ~8-10 through the backend, suspect the watchdog first.

**🔴 Pitfall — a SYNCHRONOUS loop through the backend starves the watchdog.**
Sending one `POST /api/manual_drive` and WAITING for each response (container →
Windows backend → robot) achieves only ~5-6 Hz end-to-end = a command every
~180-220 ms, right AT the 200 ms edge: motors twitch or don't move at all while
every request still returns 200. Verified live 2026-07-31: 9 commands in 1.5 s
(synchronous) = NO movement; fire-and-forget at ~30 Hz attempted (~15 Hz
effective) = movement. The pattern that works (only `init` and the final `stop`
are synchronous):

```python
def burst(throttle, seconds, base):
    t0 = time.time()
    while time.time() - t0 < seconds:
        try:
            requests.post(f"{base}/manual_drive",
                          json={"angle": 0.0, "throttle": throttle, "max_speed": 0.5},
                          timeout=0.05)
        except Exception:
            pass  # fire-and-forget: la petición ya fue enviada
        time.sleep(0.03)
```

Watch the phase command count the script prints: below ~10 commands/s the
watchdog may cut movement again — suspect rate, not motors. Robot-side scripts
(daemon 30 Hz, explorer) don't have this problem because they talk to the local
API.

### Typical Values for Movement

| Command | angle | throttle (normalizado) | max_speed |
|---------|:-----:|:--------:|:---------:|
| Forward (this robot, 2026-07-31) | 0 | **-0.10 a -0.30** (real -0.55 a -0.65) | 1.0 |
| Fast forward | 0 | **-0.70** (real -0.85) | 1.0 |
| Forward right | 0.5 | **-0.10 a -0.30** | 1.0 |
| Forward left | -0.5 | **-0.10 a -0.30** | 1.0 |
| Reverse (this robot) | 0 | **+0.10 a +0.20** (real +0.55 a +0.60) | 0.7 |
| Brake/Stop | 0 | 0.0 | 0.0 |

> ⚠️ Convención verificada 2026-07-31 en este robot: **negativo = adelante,
> positivo = atrás** (coincide con GUIA_SETUP/HANDOFF; el `drive_test.py` viejo
> que usaba +0.7 para avanzar está obsoleto). OJO: la convención puede voltearse
> entre reinicios — siempre probar dirección antes de asumir:
> ```bash
> # Send throttle=+0.3 for 1s, observe direction
> # Then throttle=-0.3 for 1s
> # Whichever goes forward is the current convention
> ```
> Update the drive daemon's `COMMANDS` dict accordingly. This is a known quirk on this hardware.

### 🔄 Real-Time Drive Daemon

For **interactive real-time control** (rather than pre-scripted sequences), use a drive daemon — a background process on the robot that reads commands from `/tmp/drive_cmd` and maintains the watchdog loop at 30Hz:

```bash
echo "forward"  > /tmp/drive_cmd    # Advance straight (throttle -0.5, neg=forward)
echo "fast"     > /tmp/drive_cmd    # Fast forward (throttle -0.8)
echo "back"     > /tmp/drive_cmd    # Reverse (throttle +0.4, pos=reverse)
echo "left"     > /tmp/drive_cmd    # Turn left (while advancing)
echo "right"    > /tmp/drive_cmd    # Turn right (while advancing)
echo "fleft"    > /tmp/drive_cmd    # Forward + sharp left
echo "fright"   > /tmp/drive_cmd    # Forward + sharp right
echo "bleft"    > /tmp/drive_cmd    # Reverse + left
echo "bright"   > /tmp/drive_cmd    # Reverse + right
echo "brake"    > /tmp/drive_cmd    # Brake (throttle=0)
echo "stop"     > /tmp/drive_cmd    # Full stop
```

**How it works:**
1. Daemon does CSRF login once, enables manual mode, starts motors
2. Reads `/tmp/drive_cmd` in a 30Hz loop — sends `PUT /api/manual_drive` each cycle
3. Agent or user just writes to the command file; daemon handles the watchdog
4. On exit, daemon automatically stops motors

**Start on the robot:**
```bash
nohup python3 /tmp/drive-daemon.py > /tmp/drive_daemon.log 2>&1 &
```

> **⚠️ The daemon reads `DEEPRACER_API_PASSWORD` from the environment** — the bare launch line above fails with a KeyError unless the variable is set. Deployment that works (SFTP the script, write the password to a 600-perm file, expand it inside the robot command so the secret never appears in the command string):
> ```python
> sftp.put("drive-daemon.py", "/tmp/drive-daemon.py")
> with sftp.open("/tmp/drive_pw", "w") as f: f.write(api_pw)
> sftp.chmod("/tmp/drive_pw", 0o600)
> # luego, en el robot:
> #   DEEPRACER_API_PASSWORD="$(cat /tmp/drive_pw)" nohup python3 /tmp/drive-daemon.py > /tmp/drive_daemon.log 2>&1 &
> ```
>
> **🙋 Preferencia del usuario (2026-07): el control del vehículo va SOLO por el backend Node (Windows) — "nada de SSH".** No desplegar ni usar daemons robot-side ni comandos SSH de movimiento sin pedirlo antes: el usuario quiere el camino frontend/agente → `apps/backend` (:5002) → API del robot. SSH queda exclusivamente para diagnóstico y mantenimiento (reloj, firewall, IP, servicios).

See `../deepracer-control/scripts/drive-daemon.py` for the implementation.

### 🛑 SAFETY: Autonomous Throttle Limits (CRITICAL — Read Before Running Explorer)

**NEVER use throttle > |0.5| in autonomous mode without direct user supervision.** A throttle of -0.75 caused the robot to crash into a wall at full speed. This was a preventable accident.

| Throttle | Speed | Risk Level | When to Use |
|----------|-------|:----------:|-------------|
| -0.25 to -0.35 | Slow crawl | 🟢 Safe | Default for autonomous exploration |
| -0.40 to -0.50 | Walking pace | 🟡 Caution | Open spaces, user watching camera |
| -0.55 to -0.75 | Running speed | 🔴 DANGER | Only with direct line-of-sight supervision |

**Hard rule:** If the user is NOT standing next to the robot watching it, the explorer must use the minimum normalized throttle that still moves this robot. With the dead-zone calibration (THROTTLE_DEAD_ZONE=0.5), the real minimum is **~0.5** (= walking pace 🟡 caution) — the old 0.35 real default sits in the dead zone and never moved this robot. Current explorer constants (normalized): GO **-0.10** (real -0.55), backup straight **+0.10** (real +0.55), reverse-turn **-0.05** (real -0.525). Do not raise the explorer's normalized throttle above 0.20 (real 0.60) without direct supervision.

### 🤖 Autonomous Explorer (Camera + Optional ESP32)

For **autonomous exploration** with obstacle avoidance, use `../deepracer-control/scripts/explorer.py`.

**⚠️ CRITICAL: Never run the drive daemon AND the explorer simultaneously.** See "Daemon/Explorer Conflict" in Common Issues.

```bash
# Run ONLY the explorer (NO daemon):
nohup python3 /tmp/explorer.py > /tmp/explorer.log 2>&1 &

# Or run ONLY the daemon (NO explorer) for manual control:
nohup python3 /tmp/drive-daemon.py > /tmp/drive_daemon.log 2>&1 &
```

#### Navigation Algorithm (v6 — Skip Counter, Long Strokes, No Wiggles)

The current explorer (v6) uses a three-state loop with a skip counter to reduce camera checks. Every other forward segment skips the camera check, making movement smoother.

```python
IDLE:
  if obstacle_ignore_until > now:
    → GO (skip=1, ignore camera for 8s after escape)
  elif skip > 0:
    skip -= 1 → GO (skip camera check this cycle)
  else:
    📸 Check camera
    ├── Obstacle detected → BACKUP
    └── Clear → GO

GO (10.0s at throttle=-0.35):
  🚗 Drive continuously for 10 seconds
  After 10s → stop → IDLE

BACKUP (3.0s total, ONE reverse-turn then escape):
  0-1.5s:  ⏪ Reverse straight (throttle=+0.40)
  1.5-3.0s: ↩️ Reverse-turn in RANDOM direction (angle=±0.8, throttle=-0.30)
  3.0s+:    → set obstacle_ignore_until=now+8.0s, skip=2 → GO
```

**Key design decisions:**
- **Skip counter**: After escape, skip=2 means the next TWO forward segments (20s) run without camera checks. This eliminates the "stop-check-go" jerkiness. Default throttle is -0.35 (safe and slow).
- **10s forward strokes**: Long enough to cover ground. With the skip counter, effective movement is often 20s between camera checks.
- **No wheel wiggling**: Backup does ONE continuous reverse-turn. No separate "look left"/"look right" phases.
- **8s forced advance after escape**: Ignore camera for 8s after backup to ensure the robot clears the obstacle area.
- **Random turn direction**: Picks left or right randomly.
- **ESP32 optional**: Wrapped in try/except — runs fine without the sensor.

#### Stuck Detection (Frame Comparison — deprecated in v4)

V3's frame comparison approach (comparing camera snapshots before/after movement, see v3 code in session reference) was replaced in v4 by the forced-advance grace period. Frame comparison suffered from:
- **Camera timeout blocking movement**: a 2s camera snapshot timeout blocked the 0.5s forward segment entirely
- **Gray floor false positives**: the comparison diff was too sensitive to floor texture
- **No improvement over forced advance**: the 3.5s grace period achieves the same effect more simply

V4's forced-advance is simpler and more robust. Only revert to frame comparison if the robot needs to navigate in spaces where 1.5s of forward movement would collide with something.

## Backend Proxy (Node.js + Express)

When Hermes is in Docker and can't reach the DeepRacer directly:

### Project Structure (post-2026-07 reorganization: `apps/backend/`)

```
apps/backend/
├── server.js            # Express server, port 5002 (+ GET /api/health seguro)
├── vehicleControl.js    # DeepRacer API client (CSRF auth + movement)
├── API.md               # Contrato de la API local
├── package.json         # type: "module", deps: express, cors, dotenv, ssh2
└── .env                 # Credentials (cargado como ../../.env desde apps/backend/)
```

### .env Variables

```
HOST=<DeepRacer LAN IP>
AWS_PORT=5001
PASSWORD=${DEEPRACER_API_PASSWORD}
SSH_USER=deepracer
SSH_PASS=${DEEPRACER_SSH_PASSWORD}
SSH_PORT=22
PORT=5002                # Backend's own port
```

### Available Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| GET | `/api/health` | Safe healthcheck — no vehicle contact, no hardware (añadido 2026-07) |
| POST | `/api/start` | Activate manual mode + start motors |
| POST | `/api/stop` | Stop motors |
| POST | `/api/manual_drive` | Send `{angle, throttle, max_speed}` or `{init: true}` |
| GET | `/api/video_stream` | Proxy MJPEG camera stream (480x360) |
| POST | `/api/exec` | Execute SSH command on robot, returns `{stdout, stderr, exit}` |

### Starting

```bash
cd apps/backend
npm install
npm start   # → http://0.0.0.0:5002 (verificar con GET /api/health)
```

**🔄 Backend restart verification (2026-07-31).** `dotenv` reads `.env` ONLY at
startup — after changing backend code or `.env` values, the running process
must be restarted or the change is silently inert. When in doubt whether the
restart actually happened, check `GET /api/health` → `uptime_s`: a fresh small
uptime means the new code is live (a stale uptime means the old process is
still running and your change did NOT take effect — this confused a whole
tuning iteration). For calibration tuning, avoid restarts entirely: use
`POST /api/calibration {"angle_offset": X}` (live, in-memory) and confirm with
`GET /api/calibration`. To make a value permanent, edit `.env` and restart.

**Lanzadores del repo (Windows):** `scripts/start/start-services.ps1` arranca
Hermes + backend y verifica con `/api/health` (nunca `/api/start`);
`scripts/start/start-backend-only.ps1` arranca SOLO el backend (sin Docker) y
registra su PID en `%TEMP%\deepracer-backend.pid`; `scripts/stop/stop-services.ps1`
mata solo ese PID. `start-deepracer.ps1`/`stop-deepracer.ps1` de la raíz delegan
en esos scripts. El PID-file es lo que permite detener el backend sin matar
otros procesos node del usuario.

> **📤 Canal de diagnóstico Windows→agente (probado 2026-07):** si el visor del
> TUI colapsa los pegados largos del usuario a `[N lines]`, pídele que escriba el
> resultado a un archivo en la raíz del repo compartido
> (`C:\Users\UNAL\Deepracer-STEAM-Agent\diagnostico.txt` = `/workspace/diagnostico.txt`)
> y léelo tú con read_file. Borra el archivo al terminar. Comandos PowerShell
> para el usuario: una sola línea por prueba, siempre con `try/catch` que escriba
> `OK`/`ERROR` al archivo (si el comando falla sin catch, el archivo queda sin
> actualizar y parece que el usuario no ejecutó nada). Evita `2>$null` dentro de
> `$(...)` en strings de PowerShell: crea un archivo literal llamado `$null`.

> **🕳️ Pitfall — `ETIMEDOUT <robot>:443` en la consola del backend NO es fatal.**
> El backend intenta el login CSRF al arrancar (`initSession`); si el robot no
> responde, registra "⚠️ No se pudo inicializar sesión aún" y sigue vivo —
> reintenta la autenticación en la siguiente petición (`ensureSession`), así que
> si el robot vuelve, el backend reconecta solo. Para diagnosticar: el
> `DEEPRACER_HOST` del `.env` raíz es LA autoridad (los docs del proyecto suelen
> estar desactualizados — p. ej. docs decían `10.203.150.56` y el `.env` tenía
> `10.203.169.138`); verificar robot encendido/misma WiFi, luego firewall
> (`sudo iptables -I INPUT 1 -s 10.0.0.0/8 -j ACCEPT`), luego si la IP cambió
> (DHCP).
>
> **Triage de alcance desde múltiples puntos (2026-07, probado en vivo):**
> 1. Desde el contenedor: `ping` + `https://<LAN-IP>/` (443) + `:8080` + SSH — el
>    contenedor SÍ llega a la LAN del robot (solo la IP Tailscale le es
>    inalcanzable). Si el 443 da 200 y el login devuelve `<title>AWS DeepRacer`,
>    el robot está sano.
> 2. Desde el propio robot (vía SSH): `curl -sk -o /dev/null -w '%{http_code}'
>    https://<tailscale-ip>/` → 200 = la ruta Tailscale sirve el 443 (prueba
>    proxy de lo que vería el host Windows).
> 3. Desde el host Windows: `Test-Connection <IP> -Count 2 -Quiet` — **`PING=False`
>    desde el host = robot apagado o IP vieja**, no un problema de software.
> 4. `hostname -I` en el robot es la única fuente de verdad para la IP actual
>    (DHCP la cambia; el proyecto ya ha visto 3 IPs LAN distintas).

## Controlling LEDs

The DeepRacer has a **rear LED strip** (transparent plate at the back with purple LEDs) that indicates vehicle state.

### ⚠️ The Priority Conflict Problem

The rear LEDs suffer from a **control loop conflict**:

| System | Frequency | Behavior |
|--------|-----------|----------|
| Web server main loop | ~1 Hz | Continuously overwrites LEDs to "race mode" purple |
| Your ROS2/API command | One-shot | Hardware changes briefly, then web server reverts it |

This is why `{"success": true}` is returned but the physical color doesn't change — the web server's loop beats your single command.

**Solution: High-frequency loop.** Send LED commands at **50-100 Hz**. Your commands arrive more frequently and "win" on the I2C bus. The web server's 1 Hz can't keep up.

Reference file with full details: `references/deepracer-led-control.md`

Reusable script for rainbow animation: `../deepracer-control/scripts/led-rainbow.sh` (usage: `bash led-rainbow.sh [seconds]`)

Throttle-reactive LED script: `../deepracer-control/scripts/brake-led.py` — ROS2 node that turns LEDs red when reversing/braking and green when moving forward, by subscribing to `/webserver_pkg/manual_drive`.

Test drive script: `../deepracer-control/scripts/test-drive.py` — full movement sequence through the web API (forward → brake → reverse → turn left → turn right → stop). Run on the robot via `python3 /tmp/test-drive.py`.

Real-time drive daemon: `../deepracer-control/scripts/drive-daemon.py` — reads commands from `/tmp/drive_cmd` and maintains a continuous drive loop at 30Hz for interactive control. Start via `nohup python3 /tmp/drive-daemon.py > /tmp/drive_daemon.log 2>&1 &`.

Combined drive + ESP32 monitor: `../deepracer-control/scripts/drive-and-listen.py` — drives the robot slowly while reading the KY-037 sound sensor on the ESP32. Useful for detecting motor noise, collisions, or environmental sounds during movement.

### Via REST API

The robot's web interface (port 5001) exposes dedicated LED endpoints found in the `bundle.js`:

| Method | Endpoint | Body |
|--------|----------|------|
| POST | `/api/set_led_color` | `{"red": 0, "green": 255, "blue": 0}` |
| GET | `/api/get_led_color` | — |

RGB values are 0-255 integers. The API requires authentication (CSRF token + session cookie).

```python
# 1. Login to get CSRF + cookie
i,o,e = ssh.exec_command('curl -s -D - http://localhost:5001/login', timeout=10)
resp = o.read().decode()
csrf = re.search(r'csrf-token" content="([^"]+)"', resp)
cookie = re.search(r'session=([^;]+)', resp)

# 2. Authenticate
ssh.exec_command(
    f'curl -s -b "session={ck}" -X POST http://localhost:5001/login '
    f'-H "X-CSRFToken: {csrft}" -d "password=${DEEPRACER_API_PASSWORD}"', timeout=5)

# 3. Set LED to green
i,o,e = ssh.exec_command(
    f'curl -s -b "session={ck}" -X POST http://localhost:5001/api/set_led_color '
    f'-H "Content-Type: application/json" '
    f'-H "X-Requested-With: XMLHttpRequest" '
    f'-H "X-CSRFToken: {csrft}" '
    f"-d '{{\"red\":0,\"green\":255,\"blue\":0}}'", timeout=5)
print(o.read().decode())  # {"success": true}
```

### ROS2 Services (Direct)

| Service | Python Type | Purpose |
|---------|-------------|---------|
| `/ctrl_pkg/set_car_led` | `deepracer_interfaces_pkg.srv.SetLedCtrlSrv` | Set RGB (0-255 per channel) |
| `/ctrl_pkg/get_car_led` | `deepracer_interfaces_pkg.srv.GetLedCtrlSrv` | Read current LED state |
| `/servo_pkg/set_led_state` | `deepracer_interfaces_pkg.srv.SetLedCtrlSrv` | Same type, different node |

> ⚠️ The `ros2 service call` CLI **does not work** on this robot (Python 3.8 importlib bug). Always use a Python rclpy script.

### 🚦 Throttle-Reactive LED Control

A ROS2 node `../deepracer-control/scripts/brake-led.py` dynamically changes the rear LED color based on the current throttle command. It subscribes to the `/webserver_pkg/manual_drive` ROS2 topic (type `deepracer_interfaces_pkg/msg/ServoCtrlMsg`) where the webserver_publisher_node publishes each incoming API drive command.

| Throttle value | Meaning (web API) | LED color | Duration |
|----------------|--------------------|-----------|----------|
| `throttle > 0.01` | Moving FORWARD | 🟢 Green | Continuous |
| `throttle < -0.01` | REVERSING | 🟠 Orange | Continuous |
| `throttle = 0` (was moving forward) | BRAKING flash | 🔴 Red | 0.5 seconds |
| `throttle = 0` (idle/stopped) | STOPPED | 🟣 Purple | Continuous |

**⚠️ ROS2 CLI daemon is unreliable.** `ros2 topic info /webserver_pkg/manual_drive` may report `Publisher count: 0` even though DDS is actively publishing to the topic. This is a known ROS2 Foxy bug where the daemon's DDS discovery state gets out of sync. **Do NOT trust `ros2 topic info` to determine if a topic has publishers.** Instead, test with an actual rclpy subscriber — it will receive messages even when the CLI reports 0 publishers. The `../deepracer-control/scripts/brake-led.py` uses rclpy subscription and works correctly.

**Fire & forget for speed:** The 100Hz LED loop uses `call_async(self.req)` without waiting for the service response. Waiting for responses (even with `spin_until_future_complete(timeout_sec=0.1)`) adds up to 200ms per cycle across two services, dropping the effective frequency below 5Hz — not enough to beat the web server's 1Hz purple override. Unwaited async calls return immediately, keeping the loop at ~100Hz.

**`spin_once(0.05)` for DDS delivery:** The main loop uses `executor.spin_once(timeout_sec=0.05)` to give DDS enough time to deliver the queued service requests. With `timeout_sec=0.001` the requests may never leave the local queue.

**`/servo_pkg/set_led_state` is optional.** This service may not be discovered by the ROS2 daemon right after boot. The current `../deepracer-control/scripts/brake-led.py` handles this gracefully: it tries both services with individual timeouts and works with just `/ctrl_pkg/set_car_led` if needed. One service is sufficient for full LED control.

**Start on the robot:**
```bash
# 1. Start the drive daemon first
nohup python3 /tmp/drive-daemon.py > /tmp/drive_daemon.log 2>&1 &

# 2. Then start the brake LED node
source /opt/ros/foxy/setup.bash
source /opt/aws/deepracer/lib/setup.bash
nohup python3 /tmp/brake-led.py > /tmp/brake_led.log 2>&1 &
```

> 💡 Upload scripts via SFTP (paramiko.SFTPClient.put()) to avoid shell escaping issues with heredoc.

### ⚠️ ROS2 Foxy Pitfall: `RuntimeError: dictionary changed size during iteration`

When calling `client.call_async()` in a tight loop (50-100 Hz) from a background thread while `rclpy.spin()` runs in the main thread, ROS2 Foxy's `rclpy/client.py` crashes with:

```
RuntimeError: dictionary changed size during iteration
```

**Root cause:** The executor iterates over `_pending_requests` dict in `remove_pending_request()` while the background thread adds new entries via `call_async()`.

**Fix — Manual spin_once() loop with synchronous calls:**

Instead of `rclpy.spin(node)` + background thread with `call_async()`, use a single-threaded loop:
```python
executor = SingleThreadedExecutor()
executor.add_node(node)

while rclpy.ok():
    executor.spin_once(timeout_sec=0.005)  # Process callbacks
    node.set_led()                          # Synchronous LED update
    time.sleep(0.01)                        # ~100 Hz
```

Then make LED service calls synchronous by wrapping `call_async()` with `rclpy.spin_until_future_complete()`:
```python
future = cli.call_async(req)
rclpy.spin_until_future_complete(node, future, timeout_sec=0.1)
```

This avoids the dict mutation issue entirely. See `../deepracer-control/scripts/brake-led.py` for a complete working example.

### Running ROS2 Commands via SSH

The trick: write a bash script that sources the ROS2 environment FIRST, then runs Python. Each `ssh.exec_command()` is a **fresh shell** — `source` has no effect across calls, so both source and Python must be in the **same** `exec_command()` call.

```python
cmd = """cat > /tmp/led.py << 'PYEOF'
import rclpy
from rclpy.node import Node
from deepracer_interfaces_pkg.srv import SetLedCtrlSrv

rclpy.init()
node = Node('led')
cli = node.create_client(SetLedCtrlSrv, '/ctrl_pkg/set_car_led')
if cli.wait_for_service(3):
    req = SetLedCtrlSrv.Request()
    req.red = 0; req.green = 255; req.blue = 0  # Green
    future = cli.call_async(req)
    rclpy.spin_until_future_complete(node, future, timeout_sec=3)
    print('OK' if future.result() else 'FAIL')
node.destroy_node()
rclpy.shutdown()
PYEOF
source /opt/ros/foxy/setup.bash
source /opt/aws/deepracer/lib/setup.bash
python3 /tmp/led.py
"""
stdin, stdout, stderr = ssh.exec_command(cmd, timeout=15)
```

> **🕳️ Pitfall**: If you try to write the Python file with one `exec_command()` and run it with another, the second call starts a fresh shell that hasn't sourced ROS2. The `.so` libraries won't be found. Always bundle `source + python3` into one command.

### Alternate LED Control via `SetStatusLedSolidSrv`

There is also a `SetStatusLedSolidSrv` service type for solid-color status LEDs, with fields `led_index` (int), `color` (string), and `hold` (float). This was not functional on the robot tested but exists in the codebase (`deepracer_interfaces_pkg/srv/_set_status_led_solid_srv.py`).

### LED Quick Reference

> **⚠️ LED brightness warning:** The standard RGB range is 0-255, but **255 is very dim on this hardware**. For full brightness, use the PWM-scaled values from the persistent config (`/opt/aws/deepracer/led_values.json`), which go up to **9999825** (`0x9898A9`). Always use `9999825` (or `MAX_PWM`) instead of `255` for visible LEDs:
> - `255` → barely visible
> - `9999825` → full brightness

| Color | Standard (0-255) | Full brightness |
|-------|:----------------:|:---------------:|
| 🟣 Purple (default) | 255, 0, 255 | 9999825, 0, 9999825 |
| 🟢 Green | 0, 255, 0 | 0, 9999825, 0 |
| 🔴 Red | 255, 0, 0 | 9999825, 0, 0 |
| 🔵 Blue | 0, 0, 255 | 0, 0, 9999825 |
| 🟠 Orange | 255, 85, 0 | 9999825, 3333275, 0 |
| ⚫ Off | 0, 0, 0 | 0, 0, 0 |

```python
MAX_PWM = 9999825  # Full brightness constant — always use this, not 255
```

The persistent config lives at `/opt/aws/deepracer/led_values.json` (root-owned, uses PWM-scale values). The runtime state (via API or ROS2) is separate from this file.
