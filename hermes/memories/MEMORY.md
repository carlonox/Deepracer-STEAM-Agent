DeepRacer web API:
- IP LAN: 10.203.150.56, Tailscale IP: 100.117.192.31
- Puerto 5001 (HTTP, no HTTPS)
- Password API web: 48AW5fAB (diferente de SSH)
- SSH: deepracer@<IP>, password Steambog1$
- Login: GET /login → extraer CSRF del meta tag → POST /login con password + header X-CSRFToken
- La cookie session tiene flag Secure, hay que inyectarla manualmente en el cookie jar
- Endpoints: PUT /api/drive_mode, PUT /api/start_stop, PUT /api/manual_drive
- Headers necesarios: X-CSRFToken, X-Requested-With: XMLHttpRequest
- Script de control: /workspace/hermes/scripts/drive_test.py
- Skill: deepracer-control (devops/deepracer-control)
§
Backend server.js corre en puerto 5002 (PORT env var). Expone endpoints POST /api/start, POST /api/stop, POST /api/manual_drive, GET /api/video_stream. Se autentica contra el DeepRacer (puerto 5001 por defecto) via vehicleControl.js. credenciales en /workspace/backend/.env. No hay SOUL.md ni memories.md en el repo.
§
DeepRacer connection report requested by user. Save to hermes/skills/connection_report.md. Covers: SSH connection details, web API (port 5001, HTTPS, CSRF flow, Secure cookie handling), movement endpoints, scripts location, latency observations, and known issues.
§
DeepRacer SSH: el container Docker NO tiene conectividad al Tailscale del DeepRacer (100.117.192.31). Solo el backend Node.js (corriendo en Windows host) puede alcanzarlo. Solución: agregar endpoint POST /api/exec al backend que use ssh2 para ejecutar comandos SSH en el vehículo. El backend ya tiene las credenciales SSH en .env (SSH_USER=deepracer, SSH_PASS=Steambog1$, SSH_PORT=22). El endpoint /api/exec recibe {"command": "..."} y devuelve {stdout, stderr, exit}.
§
Sesión 2026-06-17: Instalé opencv-contrib-python 4.13.0.92 en el DeepRacer (tenía 4.5.1 base sin aruco). Creé script /home/deepracer/aruco_detect.py para detección de marcadores ArUco con cálculo de distancia. Probado: funciona, detecta "sin marcadores visibles" (correcto). Documentación en /workspace/hermes/skills/aruco_detection.md. Siguiente: imprimir marcadores, calibrar focal length.