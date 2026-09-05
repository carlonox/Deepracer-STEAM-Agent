# DeepRacer Simulador (mock de la API web)

Simula la API web del AWS DeepRacer para **desarrollar y practicar sin el
robot físico**. Es el mismo contrato que usa `apps/backend/vehicleControl.js`
contra el hardware real — si tu código funciona contra el simulador, funciona
contra el robot (y al revés).

## Por qué existe

La API del robot es delicada (login CSRF, watchdog de 200 ms, dead zone del
throttle, servo ultrasensible) y **no se aprende sin riesgo**: un error mueve
un carro de $400 contra una pared. Este simulador reproduce el comportamiento
medido del hardware real para que puedas:

- Aprender el flujo de login CSRF (token en HTML y en cookie de sesión).
- Entender el **watchdog de ~200 ms**: si no llegan comandos, los motores se
  cortan (el loop síncrono "muere de hambre"; el fire-and-forget funciona).
- Ver la **dead zone real (~0.5)**: `0.45` no mueve, `0.50` sí.
- Sentir la **sensibilidad del servo** (~380°/s por unidad de angle).
- Respetar la convención **negativo = adelante** (y cambiarla con
  `SIM_THROTTLE_SIGN` para practicar el "cambia entre reboots" del real).
- Probar el stack completo: frontend → backend (`apps/backend`) → mock, sin
  encender el robot.

## Contrato emulado (fiel a la documentación)

| Endpoint | Métodos | Body | Respuesta |
|---|---|---|---|
| `/login` | GET | — | HTML con `csrf_token` (meta + input) y cookie `session` |
| `/login` | POST | `csrf_token` + `password` (form) | 200 + cookie autenticada; 401/403 si falla |
| `/api/drive_mode` | PUT, POST | `{"drive_mode": "manual"}` | `{"success": true}` |
| `/api/start_stop` | PUT, POST | `{"start_stop": "start"\|"stop"}` | `{"success": true}` |
| `/api/manual_drive` | PUT, POST | `{"angle": X, "throttle": Y, "max_speed": Z}` | `{"success": true}` |
| `/api/manual_drive` | POST | `{"drive_control": {"throttle": -50, "steering_angle": 0}}` (contrato viejo) | `{"success": true}` |
| `/api/set_led_color` | POST | `{"red": 0, "green": 255, "blue": 0}` | `{"success": true}` |
| `/api/get_led_color` | GET | — | `{"success": true, "red": ..., ...}` |
| `/mock/state` | GET | — | Estado completo (extensión del simulador) |
| `/route?topic=/camera_pkg/display_mjpeg` | GET | — | MJPEG `multipart/x-mixed-replace` (lo que usa el backend) |
| `/stream_viewer?topic=...` | GET | — | MJPEG (equivalente a `web_video_server` :8080) |
| `/snapshot?topic=...` | GET | — | JPEG individual |

Endpoints `/api/*` exigen **cookie de sesión autenticada**. Sin sesión → 401
(el backend real reautentica solo, igual que con el robot).

Todo lo documentado proviene de: `apps/backend/vehicleControl.js`,
`docs/operations/GUIA_SETUP.md`, `docs/operations/HANDOFF.md`,
`hermes/skills/robotics/deepracer-control/SKILL.md` (mediciones en vivo
2026-07-31) y `docs/archive/SpeedRacerv.2` (iteración anterior: CSRF en
cookie, contrato `drive_control`).

## Uso

```bash
# 1. Dependencias (opcionales: solo para el stream MJPEG; el resto es stdlib)
pip install -r apps/simulator/requirements.txt   # o usa el venv de navigation

# 2. Arrancar
python apps/simulator/deepracer_mock.py
```

```text
API HTTPS   : https://127.0.0.1:5001/login          (password: deepracer)
Dashboard   : https://127.0.0.1:5001/home
MJPEG HTTP  : http://127.0.0.1:8080/stream_viewer?topic=/camera_pkg/display_mjpeg
Estado      : https://127.0.0.1:5001/mock/state
```

**Certificado autofirmado**: se genera solo en `apps/simulator/certs/`
(ignorado por git). El navegador te va a advertir — es esperado. El backend
Node ya habla HTTPS con `rejectUnauthorized: false` (igual que con el robot).

### Probar con el backend real (recomendado)

```bash
# En el .env de la raíz (o variables de entorno):
DEEPRACER_HOST=127.0.0.1
DEEPRACER_API_PORT=5001
DEEPRACER_API_PASSWORD=deepracer
DEEPRACER_API_HTTPS=true
# (deja el resto igual)

cd apps/backend
npm start
# → http://localhost:5002/api/health  (OK)
# → POST /api/start → "Vehículo preparado..."
# → POST /api/manual_drive {"angle":0,"throttle":-0.3,"max_speed":0.5}
# → GET  /api/video_stream → MJPEG
```

⚠️ Con el simulador **sí se puede** usar `/api/start`, `/api/manual_drive`
como prueba automática (no hay robot físico). Con el hardware real, NO.

### Tests de contrato

```bash
python -m pytest apps/simulator/tests -q        # arranca el mock solo
```

Cubren: login CSRF (HTML + cookie), password incorrecta → 401, CSRF inválido
→ 403, endpoints sin sesión → 401, secuencia completa drive/start/move/stop,
contrato viejo `drive_control`, **watchdog corta motores**, fire-and-forget
mantiene motores, dead zone (0.45 no mueve / 0.60 mueve), velocidad mínima
~0.87 m/s, **servo sensible** (0.11 gira ~40°/s), convención negativo=adelante,
LED set/get, MJPEG `multipart` y snapshot JPEG.

## Configuración (por entorno)

| Variable | Default | Significado |
|---|---|---|
| `DEEPRACER_API_PASSWORD` | `deepracer` | Password del login (igual que `.env`) |
| `DEEPRACER_API_PORT` | `5001` | Puerto HTTPS de la API |
| `MOCK_HTTP_PORT` | `8080` | Puerto HTTP del MJPEG (web_video_server) |
| `THROTTLE_DEAD_ZONE` | `0.5` | Zona muerta real del robot |
| `STRAIGHT_ANGLE_OFFSET` | `0` | Trim de dirección (se suma al angle) |
| `SIM_THROTTLE_SIGN` | `-1` | Convención: -1 = negativo adelante |
| `SIM_WATCHDOG_MS` | `200` | Watchdog del simulador (igual que el real) |
| `SIM_BATTERY_DRAIN` | `0.5` | % de batería por minuto con motores activos |
| `SIM_CERT_DIR` | `certs/` | Dónde guardar el certificado autofirmado |

## Limites conocidos (no emula)

- ROS2, nginx, SSH, ESP32/UDP, LiDAR, IMU (el hardware real tampoco tiene IMU).
- La física es un modelo 2D aproximado del robot medido (curva de velocidad
  lineal entre los puntos reales); no hay odometría real ni IMU.
- El stream MJPEG es sintético (OpenCV dibuja piso + robot + HUD). Sirve para
  probar el pipeline de video, no para entrenar visión.
- No hay "convención que cambia sola entre reboots": se fija con
  `SIM_THROTTLE_SIGN`. Cambiala a mano para practicar el pitfall.

## Verificación de fidelidad

Este simulador fue validado contra el **backend real** de Node
(`apps/backend/server.js` + `vehicleControl.js`) sin modificar una línea del
backend: el flujo completo `start → manual_drive → stop` y el stream MJPEG
funcionan de punta a punta contra el mock. Si el robot real responde distinto
en algún punto, la fuente de verdad es la documentación del proyecto — no
este simulador (abrí un issue o actualizá el README).