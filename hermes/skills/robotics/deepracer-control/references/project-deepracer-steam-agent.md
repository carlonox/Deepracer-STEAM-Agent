# Deepracer STEAM Agent — Project Reference

Actual working values for this specific project (Deepracer-STEAM-Agent).

## Network

| Type | Address | Reachable from Docker? |
|------|---------|----------------------|
| LAN IP | `10.203.150.56` | ✅ Ping + SSH (port 22) |
| Tailscale IP | `100.117.192.31` | ❌ Timeout from Docker container |

## Credentials (verified working)

| Service | Username | Password | Port |
|---------|----------|----------|------|
| SSH | `deepracer` | `${DEEPRACER_SSH_PASSWORD}` | 22 |
| Web API | — | `${DEEPRACER_API_PASSWORD}` | 5001 |

⚠️ The SSH password is `${DEEPRACER_SSH_PASSWORD}` (with **b**), NOT `${DEEPRACER_SSH_PASSWORD}` as written in some documentation files.

## Docker Container Setup

- Container name: `deepracer-agent`
- Image base: `nousresearch/hermes-agent:latest` + `uv pip install paramiko`
- Working directory: `/workspace` (project root)
- Volume mounts: `./hermes:/opt/data` (config), `./:/workspace` (project)
- Ports: `9999:9119` (dashboard), `8642:8642` (API)
- Dashboard URL: `http://localhost:9999/login` (NOT `/` — known v0.18.0 bug)
- API: `http://localhost:8642`

## Backend Node.js

- Path: `/workspace/backend/`
- Port: 5002
- Deps: express, cors, dotenv, ssh2
- Start: `npm install && npm start`
- .env template in `/workspace/.env.example`
- ⚠️ **.env variable names don't match .env.example**: The example uses `DEEPRACER_HOST`, `DEEPRACER_SSH_USER`, etc., but the code reads `HOST`, `SSH_USER`, `SSH_PASS`, `AWS_PORT`, `PASSWORD`, `PORT` directly. Always check the actual variable names in `server.js` and `vehicleControl.js`.

### Backend Startup

When the backend starts, it logs:
```
◇ injected env (7) from .env          ← Loaded credentials ✅
◇ injected env (0) from .env          ← Second load (vehicleControl.js also calls dotenv)
🔐 Inicializando sesión...            ← Trying to authenticate with DeepRacer
Backend activo en http://0.0.0.0:5002  ← Express is listening
```

If `🔐 Sesión lista.` never appears, the `initSession()` call in `server.js` failed silently (the `catch` block logs a warning). The backend Express server still works, but any endpoint that calls the DeepRacer (start, stop, manual_drive) will return `{"error":"Error al preparar el vehículo"}`. Check the backend's console window for the actual error message.

## Robot Web Dashboards

This project has **two separate web dashboards**:

| Dashboard | URL | Purpose | Auth |
|-----------|-----|---------|------|
| **Hermes Dashboard** | `http://localhost:9999/login` | AI agent chat UI | admin / ${HERMES_DASHBOARD_BASIC_AUTH_PASSWORD} |
| **DeepRacer Dashboard** | `http://10.203.150.56:5001/login` | Robot control (drive, camera, calibration) | password: `${DEEPRACER_API_PASSWORD}` |

⚠️ **Do NOT confuse them.** When the user says "dashboard" in the context of the robot, they mean the DeepRacer dashboard (port 5001 on the robot), NOT the Hermes dashboard.

## ROS2 Streaming (Port 8080)

The `web_video_server` serves MJPEG streams on port 8080:

| Stream | URL |
|--------|-----|
| Camera | `http://10.203.150.56:8080/stream_viewer?topic=/camera_pkg/display_mjpeg` |
| LiDAR overlay | `http://10.203.150.56:8080/stream_viewer?topic=/sensor_fusion_pkg/overlay_msg` |
| Snapshots | `http://10.203.150.56:8080/snapshot?topic=/camera_pkg/display_mjpeg` |
| Topic list | `http://10.203.150.56:8080/` |

## LiDAR Status

**Software:** Fully installed (`rplidar_ros` package + `sensor_fusion_node` + sample model at `/opt/aws/deepracer/artifacts/Sample_lidar_stereo_cam/model.pb`).
**Hardware:** No physical RPLIDAR connected (no `/dev/ttyUSB*` devices detected).
The `rplidarNode` is in the main launch file but fails due to missing ROS2 shared library paths.

- The Docker container has no Tailscale connectivity — use LAN IP for SSH.
- Port 5001 (web API) times out from Docker but works from the Windows host.
- Backend proxy pattern: backend runs on host → proxy to DeepRacer → Hermes calls backend.
- **SSH connectivity can be intermittent**: the robot's SSH port 22 may respond to some connection attempts and time out on others, even while ping succeeds consistently. This is usually **not** WiFi instability — check `sudo iptables -L -n` for `(policy DROP)` on the INPUT chain or a `f2b-sshd` chain. If present, fail2ban is blocking your IP after failed auth attempts. Fix: `sudo iptables -I INPUT 1 -s 10.0.0.0/8 -j ACCEPT`. On-robot diagnostics: `sudo iptables -L -n` (firewall), `sudo journalctl -u sshd --no-pager -n 30` (SSH logs), `iwconfig wlan0 | grep ESSID` (WiFi).
- **C:\\\\ is mounted at /workspace** in this environment (9p/drvfs mount). Windows paths like `C:\\Users\\UNAL\\Deepracer-STEAM-Agent\\file.md` resolve to `/workspace/file.md` directly — NOT under `/mnt/c/`. Always check `df` first when translating paths.
- **`ssh -v` is essential for diagnosing**: it reveals whether you're getting "Connection timed out" (network/firewall issue) vs "Permission denied" (password/key issue) vs no TTY fallback behavior.
- **The `start-deepracer.ps1` script is designed for PowerShell on Windows**, not for running inside the Hermes Docker container. It references Docker Desktop, the project path `C:\\Users\\UNAL\\Deepracer-STEAM-Agent`, and `node.exe` directly.
- **`stop-deepracer.ps1` is empty** (0 bytes) — there's no automated stop script implemented yet.

## SSH Authentication Pitfalls

1. **No TTY = silent failure**: SSH without `PreferredAuthentications=password` tries publickey, fails, then falls back to password. With no TTY it can't prompt and silently fails with `Permission denied (publickey,password)`. **Fix**: always pass `-o PreferredAuthentications=password -o PubkeyAuthentication=no` when scripting.
2. **Password prompt detection in pty**: When using Python's `pty` + `subprocess`, the password prompt appears as lowercase `password:` in the byte output. Wait for it before writing the password. Without this detection, the password is written too early (before the prompt is displayed) and gets consumed as command input, not as the password.
3. **Empty password attempts**: Without the TTY-prompt cycle, SSH sends 3 empty passwords in rapid succession. The log on the robot shows 3 "Failed password" entries per failed connection attempt.
4. **iptables policy DROP + fail2ban**: The DeepRacer may have `Chain INPUT (policy DROP)` as default, with fail2ban (`f2b-sshd` chain) blocking IPs after failed SSH attempts. This blocks ALL ports (22, 5001, etc.) from the blocked IP. **Diagnostic**: `sudo iptables -L -n` shows `Chain INPUT (policy DROP ...)` and a `f2b-sshd` chain. **Fix**: `sudo iptables -I INPUT 1 -s 10.0.0.0/8 -j ACCEPT` to allow local subnet before any firewall rules.

## Creating the .env File from PowerShell

When creating the backend `.env` from PowerShell, use a here-string to avoid issues with the `$` in `${DEEPRACER_SSH_PASSWORD}`:

```powershell
@"
HOST=10.203.150.56
SSH_PORT=22
SSH_USER=deepracer
SSH_PASS=${DEEPRACER_SSH_PASSWORD}
AWS_PORT=5001
PASSWORD=${DEEPRACER_API_PASSWORD}
PORT=5002
"@ | Out-File -Encoding UTF8 .env
```

PowerShell's `@"..."@` here-string treats `$` as a literal character, not a variable prefix. Regular PowerShell strings would need backtick escaping: `` `$ ``.

## Project Documentation Layout

| File | Actual purpose | Common mistake |
|------|---------------|----------------|
| `/workspace/Documentacion.md` | Migration log (v0.16→v0.18) — NOT an operations guide | Mistaking this for the setup guide |
| `/workspace/docs/GUIA_SETUP.md` | Full operations guide — physical setup, SSH, web control | Overlooking this in favor of the migration doc |
| `/workspace/RAG/GUIA_SETUP.md` | Same content, duplicate in RAG folder | — |
| `/workspace/backend/API.md` | API reference | — |
| `/workspace/README.md` | Quickstart overview | — |
