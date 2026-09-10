# Datos y extensiones de Hermes

Esta carpeta se monta como `/opt/data` dentro del contenedor y mezcla
configuración mantenida por el proyecto con estado persistente de ejecución.

## Contenido mantenible

| Ruta | Propósito |
|---|---|
| `config.template.yaml` | Plantilla pública de configuración. |
| `soul/soul.md` | Identidad y personalidad del agente (única fuente vigente; legacy en `docs/archive/SOUL-legacy-20260908.md`). |

> Hermes lee el SOUL de `HERMES_HOME/SOUL.md` (`/opt/data/SOUL.md`). El
> `docker-compose.yml` monta `soul/soul.md` **read-only** sobre esa ruta, así el
> SOUL curado es el que usa el agente. `hermes/SOUL.md` es de runtime y no se
> versiona (`.gitignore`).
| `skills/` | Habilidades y referencias del DeepRacer. |
| `scripts/` | Diagnóstico y exploración del robot. |
| `memories/` | Memoria curada cuando se decide conservarla. |

## Contenido de ejecución

Configuraciones reales, `.env`, `auth.json`, claves, bases de datos, cachés,
logs, sesiones, archivos `pid/lock` y directorios internos son privados o
generados. No deben copiarse a documentación, moverse mientras Hermes está
activo ni versionarse sin una revisión explícita.
