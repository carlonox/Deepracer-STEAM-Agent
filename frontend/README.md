# Frontend

Interfaz React/Vite para operar el DeepRacer mediante teclado, controles
táctiles, gamepad y WebXR.

## Contenido

| Ruta | Propósito |
|---|---|
| `src/` | Código de la aplicación. |
| `public/` | Recursos servidos sin transformación. |
| `move.js` | Prueba independiente de movimiento desde Node.js. |
| `vite.config.js` | Configuración del servidor y build de Vite. |
| `tailwind.config.js` | Configuración visual de Tailwind. |
| `package.json` | Dependencias y comandos del frontend. |
| `../.env` | Variables locales compartidas; no debe versionarse. |

`node_modules/` y `dist/` son generados y deben recrearse con npm.
Vite lee el `.env` de la raíz mediante `envDir`; solo las variables con prefijo
`VITE_` quedan expuestas al navegador.
