# Deepracer STEAM Agent

Mascota AI basada en AWS DeepRacer controlada por Hermes Agent.

## Cómo orientarse

- [Plan maestro de organización](ORGANIZACION_PROYECTO.md): estructura
  canónica, migración segura, verificaciones y mantenimiento futuro.
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

## Instalación rápida

1. Clona el repositorio:
   ```bash
   git clone https://github.com/carlonox/Deepracer-STEAM-Agent.git
   cd Deepracer-STEAM-Agent
   ```

2. Construye la imagen (instala paramiko automáticamente):
   ```bash
   docker compose build
   ```

3. Configura Hermes (primera vez):
   ```bash
   docker compose run --rm hermes setup
   ```

4. Ejecuta Hermes:
   ```bash
   docker compose run --rm hermes
   ```

## Configuración del DeepRacer

1. Copia `.env.example` como `.env` y llena tus datos
2. El DeepRacer necesita Tailscale conectado a la misma cuenta
3. La IP de Tailscale del DeepRacer nunca cambia

## Estructura

Consulta [ORGANIZACION_PROYECTO.md](ORGANIZACION_PROYECTO.md) para ver la
estructura objetivo y el plan de migración seguro.

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
