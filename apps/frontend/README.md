# Frontend

Interfaz React/Vite para operar el DeepRacer mediante teclado, controles
táctiles, gamepad y WebXR.

## Contenido

| Ruta | Propósito |
|---|---|
| `src/` | Código de la aplicación. |
| `public/` | Recursos servidos sin transformación. |
| `scripts/move.js` | ⚠️ Prueba de hardware: mueve el vehículo. Requiere autorización explícita. |
| `vite.config.js` | Configuración del servidor y build de Vite. |
| `tailwind.config.js` | Configuración visual de Tailwind. |
| `package.json` | Dependencias y comandos del frontend. |
| `../../.env` | Variables locales compartidas; no debe versionarse. |

`node_modules/` y `dist/` son generados y deben recrearse con npm.
Vite lee el `.env` de la raíz mediante `envDir`; solo las variables con prefijo
`VITE_` quedan expuestas al navegador.

## VR en Quest por LAN (HTTPS opcional)

El navegador 2D del Quest **no expone** los Touch fuera de sesión XR y la
sesión inmersiva exige **contexto seguro**. Sin HTTPS el panel VR muestra
`Seguro: NO (http) · XR: no · pads: 0` y los gatillos no fluyen (el casco sí
los ve a nivel sistema, la página no).

### Activarlo (solo dev, certificado local de corta vida)

1. Generar cert fuera del repo (aquí 2 días, atado a la IP LAN del PC):
   `"C:\Program Files\Git\usr\bin\openssl.exe" req -x509 -newkey rsa:2048 -keyout <dir>\vr-lan.key -out <dir>\vr-lan.crt -days 2 -nodes -subj "/CN=<IP-LAN>" -addext "subjectAltName=IP:<IP-LAN>,IP:127.0.0.1,DNS:localhost"`
2. En el `.env` de la raíz (lo edita el operador, nunca se commitea):
   `VITE_API_PROXY=1`, `VITE_HTTPS_KEY=<dir>\vr-lan.key`,
   `VITE_HTTPS_CERT=<dir>\vr-lan.crt`.
3. Reiniciar **solo vite** (`npm run dev` en `apps/frontend`; el backend
   `:5002` no se toca). Abrir en el casco `https://<IP-LAN>:5173`,
   aceptar el aviso de certificado, pulsar **VR** y elegir modo
   (Joystick / Gatillos). Dentro del casco se ve la cámara del robot +
   un HUD con modo y valores (la sesión inmersiva sin render quedaría
   en negro: `useQuestVRInput.js` dibuja esa capa).

Con `VITE_API_PROXY=1` el frontend llama a `/api` y `/video` en mismo
origen y vite los proxea al backend (`127.0.0.1:5002`) y a la cámara del
robot: sin esto la página HTTPS bloquearía backend y cámara
(mixed-content).

### Sin certificado no se rompe nada

Si las variables no existen o los archivos no están, `vite.config.js`
arranca en **HTTP plano como siempre**: teclado, táctil, gamepad y cámara
funcionan igual. Lo único que no fluye son los controles del Quest en la
página (ver diagnóstico en el panel VR). Los `.key`/`.crt` jamás van al
repo (gitleaks/CI los rechazarían).
