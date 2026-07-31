# Deepracer STEAM Agent

Mascota AI basada en AWS DeepRacer controlada por Hermes Agent.

## Cómo orientarse

- [Guía de operación (GUIA_SETUP)](docs/operations/GUIA_SETUP.md): setup físico
  del robot, SSH, control por teclado/gamepad, ROS2 y solución de problemas.
- [API del backend (API.md)](apps/backend/API.md): endpoints, autenticación y
  calibración del vehículo (zona muerta de throttle y trim de dirección).
- [Plan maestro de organización](ORGANIZACION_PROYECTO.md): estructura vigente,
  decisiones registradas y mantenimiento futuro.
- [Instrucciones para agentes](AGENTS.md): reglas obligatorias al añadir,
  mover o retirar contenido.
- [Política de seguridad](SECURITY.md): almacenamiento, rotación y publicación
  segura de credenciales.
- [Lista de rotación](CREDENTIAL_ROTATION.md): credenciales que deben renovarse
  y cómo verificar cada cambio sin activar el vehículo.
- [Índice de documentación](docs/README.md): guías activas e historia.

Antes de reorganizar rutas, lee el plan completo. Los movimientos se ejecutan
por componentes y con validaciones intermedias; iniciar el software no debe
usarse como prueba automática porque algunos flujos pueden activar el vehículo.

## Requisitos

- [Docker Desktop](https://www.docker.com/products/docker-desktop/)
- [Tailscale](https://tailscale.com/download) (en el PC y en el DeepRacer)
- Acceso SSH al DeepRacer
- Node.js ≥ 18 (para el backend local)

## Instalación rápida

1. Clona el repositorio:
   ```bash
   git clone https://github.com/carlonox/Deepracer-STEAM-Agent.git
   cd Deepracer-STEAM-Agent
   ```

2. Construye la imagen de Hermes (instala paramiko automáticamente):
   ```bash
   docker compose build hermes
   ```

3. Configura Hermes (primera vez):
   ```bash
   docker compose run --rm hermes setup
   ```

4. Ejecuta Hermes:
   ```bash
   docker compose run --rm hermes
   ```

5. Levanta el backend de control (Node.js — el puente entre las apps y el robot):
   ```bash
   cd apps/backend
   npm install
   npm start          # → http://localhost:5002 (verificar con GET /api/health)
   ```
   En Windows también puedes usar `scripts/start/start-backend-only.ps1`
   (arranca solo el backend y registra su PID). La API se documenta en
   [apps/backend/API.md](apps/backend/API.md).

## Configuración del DeepRacer

1. Copia `.env.example` como `.env` y llena tus datos (incluye la calibración
   del vehículo: `THROTTLE_DEAD_ZONE` y `STRAIGHT_ANGLE_OFFSET`)
2. El DeepRacer necesita Tailscale conectado a la misma cuenta
3. La IP de Tailscale del DeepRacer nunca cambia (la IP LAN sí cambia por DHCP)
4. Calibración: el backend aplica la zona muerta del throttle automáticamente;
   el trim de dirección se ajusta en vivo con `POST /api/calibration` — ver
   [API.md](apps/backend/API.md)

## Estructura

La estructura vigente es el resultado de la migración por fases de 2026-07-31;
consulta [ORGANIZACION_PROYECTO.md](ORGANIZACION_PROYECTO.md) para las
decisiones registradas y el mantenimiento futuro.

| Ruta | Contenido |
|---|---|
| [`apps/`](apps/README.md) | Aplicaciones: backend, frontend, navegación, RAG, voz. |
| [`firmware/`](firmware/README.md) | Firmware de microcontroladores (ESP32-S3). |
| [`hermes/`](hermes/README.md) | Extensiones y volumen persistente de Hermes. |
| [`models/`](models/README.md) | Modelos binarios de visión. |
| [`tools/`](tools/README.md) | Herramientas binarias locales. |
| [`docs/`](docs/README.md) | Documentación activa e histórica. |
| [`scripts/`](scripts/README.md) | Arranque, parada, diagnóstico y mantenimiento. |

Puntos de entrada en la raíz: `start-deepracer.ps1` y `stop-deepracer.ps1`
(delegan en `scripts/`). El lanzador compatible `controlcamara.py` delega en
`apps/navigation/src/controlcamara.py`.

## Validación

```bash
# Backend (Node): sintaxis
node --check apps/backend/server.js
node --check apps/backend/vehicleControl.js

# Python: navegación, RAG y voz (requiere venv con pytest)
python -m pytest apps/navigation/tests apps/rag/tests \
  apps/speech-to-text/tests apps/text-to-speech/tests -q

# Frontend: build y lint
cd apps/frontend
npm ci
node ./node_modules/vite/bin/vite.js build
node ./node_modules/eslint/bin/eslint.js .
```

> ⚠️ Nunca uses `/api/start`, `/api/manual_drive` ni `/api/exec` como prueba
> automática: preparan o mueven el vehículo (ver [API.md](apps/backend/API.md)).
