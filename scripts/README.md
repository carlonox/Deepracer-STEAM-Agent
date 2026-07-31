# Scripts

Scripts de arranque, parada, diagnóstico y mantenimiento del proyecto.

| Carpeta | Propósito |
|---|---|
| `start/` | Implementación interna del arranque de servicios. |
| `stop/` | Implementación interna de la parada de servicios. |
| `diagnostics/` | Verificaciones seguras que **no activan hardware**. |
| `maintenance/` | Tareas explícitas de mantenimiento (solo bajo demanda). |

Los lanzadores de la raíz (`start-deepracer.ps1`, `stop-deepracer.ps1`)
delegan en estas carpetas. **Iniciar servicios no debe implicar movimiento
físico del vehículo**: ninguna verificación automática llama a `/api/start`,
`/api/manual_drive` ni comandos SSH de movimiento.
