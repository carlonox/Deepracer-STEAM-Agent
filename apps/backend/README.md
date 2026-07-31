# Backend

Proxy Node.js entre las interfaces locales y la API del AWS DeepRacer.

## Contenido

| Ruta | Propósito |
|---|---|
| `server.js` | Servidor Express, API HTTP, proxy de video y canal TCP de manejo. |
| `vehicleControl.js` | Autenticación, comandos y **calibración de throttle** (zona muerta, `THROTTLE_DEAD_ZONE`). |
| `API.md` | Contrato y ejemplos de la API local. |
| `scripts/` | Utilidades que se ejecutan en el robot o apoyan el diagnóstico. |
| `package.json` | Dependencias y metadatos de Node.js. |
| `../../.env` | Configuración local compartida y sensible; no debe versionarse. |

`node_modules/` es generado por `npm install` y no forma parte del código fuente.
Las variables requeridas se documentan en `../../.env.example` (incluye `THROTTLE_DEAD_ZONE=0.5`).

El `/api/manual_drive` recibe throttle **normalizado** `[-1,1]` y lo calibra al rango real del robot (ver `API.md`).
