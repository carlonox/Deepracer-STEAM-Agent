# Backend

Proxy Node.js entre las interfaces locales y la API del AWS DeepRacer.

## Contenido

| Ruta | Propósito |
|---|---|
| `server.js` | Servidor Express, API HTTP, proxy de video y canal TCP de manejo. |
| `vehicleControl.js` | Autenticación y comandos contra la API web del vehículo. |
| `API.md` | Contrato y ejemplos de la API local. |
| `scripts/` | Utilidades que se ejecutan en el robot o apoyan el diagnóstico. |
| `package.json` | Dependencias y metadatos de Node.js. |
| `../.env` | Configuración local compartida y sensible; no debe versionarse. |

`node_modules/` es generado por `npm install` y no forma parte del código fuente.
Las variables requeridas se documentan en `../.env.example`.
