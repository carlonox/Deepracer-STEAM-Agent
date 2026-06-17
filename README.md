# Deepracer STEAM Agent

Mascota AI basada en AWS DeepRacer controlada por Hermes Agent.

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

```
├── docker-compose.yml      # Contenedor Docker
├── Dockerfile.hermes        # Imagen con paramiko
├── backend/                 # Express.js (proxy API)
├── frontend/                # React + Vite (interfaz web)
├── RAG/                     # Sistema RAG (20 manuales)
├── hermes/                  # Hermes Agent
│   ├── soul/                # Personalidad del robot
│   ├── scripts/             # Scripts de control
│   ├── skills/              # Habilidades aprendidas
│   └── memories/            # Contexto acumulado
└── docs/                    # Documentación
```
