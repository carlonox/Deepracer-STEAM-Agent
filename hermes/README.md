# Datos y extensiones de Hermes

Esta carpeta se monta como `/opt/data` dentro del contenedor y mezcla
configuración mantenida por el proyecto con estado persistente de ejecución.

## Contenido mantenible

| Ruta | Propósito |
|---|---|
| `config.template.yaml` | Plantilla pública de configuración. |
| `SOUL.md` y `soul/` | Identidad y personalidad del agente. |
| `skills/` | Habilidades y referencias del DeepRacer. |
| `scripts/` | Diagnóstico y exploración del robot. |
| `memories/` | Memoria curada cuando se decide conservarla. |

## Contenido de ejecución

Configuraciones reales, `.env`, `auth.json`, claves, bases de datos, cachés,
logs, sesiones, archivos `pid/lock` y directorios internos son privados o
generados. No deben copiarse a documentación, moverse mientras Hermes está
activo ni versionarse sin una revisión explícita.
