# Lista de rotación de credenciales

Este documento registra qué credenciales deben rotarse después de haber sido
retiradas del código y la documentación. No contiene valores reales.

> El archivo `.env` es la única fuente local de configuración sensible. Está
> ignorado por Git. Después de cada rotación, actualiza allí el valor nuevo sin
> copiarlo a documentación, commits, chats o logs.

## Prioridad crítica

### API key de OpenCode

- Variable local: `OPENCODE_API_KEY`.
- Ubicación actual: `.env` de la raíz.
- Rotación: portal o panel del proveedor OpenCode correspondiente.
- Motivo: el valor anterior estuvo incrustado en configuración local y debe
  considerarse expuesto.
- Después de rotar:
  1. Actualizar `OPENCODE_API_KEY` en `.env`.
  2. Revisar si `OPENCODE_GO_API_KEY` usa la misma credencial; si es distinta,
     rotarla por separado.
  3. Recrear Hermes con `docker compose up -d --force-recreate hermes`.
  4. Confirmar que Hermes puede consultar el proveedor.

### Contraseña SSH del DeepRacer

- Variable local: `DEEPRACER_SSH_PASSWORD`.
- Usuario relacionado: `DEEPRACER_SSH_USER`.
- Ubicación actual: `.env` de la raíz.
- Rotación: directamente en el sistema operativo del DeepRacer, mediante un
  procedimiento autorizado que mantenga una sesión de recuperación disponible.
- Motivo: el valor anterior aparece en commits históricos.
- Después de rotar:
  1. Mantener abierta una sesión SSH existente hasta verificar la nueva.
  2. Actualizar `DEEPRACER_SSH_PASSWORD` en `.env`.
  3. Probar únicamente una conexión SSH sin ejecutar comandos de movimiento.
  4. Confirmar que los scripts Paramiko leen la variable correctamente.

### Contraseña de la API web del DeepRacer

- Variable local: `DEEPRACER_API_PASSWORD`.
- Ubicación actual: `.env` de la raíz.
- Rotación: interfaz o procedimiento de recuperación de contraseña del propio
  DeepRacer.
- Motivo: el valor anterior aparece en commits históricos.
- Después de rotar:
  1. Actualizar `DEEPRACER_API_PASSWORD` en `.env`.
  2. Reiniciar únicamente los clientes locales que lean esa configuración.
  3. Probar el login o un endpoint de estado que no active el vehículo.
  4. No usar `/api/start` ni `/api/manual_drive` como prueba de credenciales.

## Rotadas localmente durante la remediación

### Dashboard de Hermes

- Variables:
  - `HERMES_DASHBOARD_BASIC_AUTH_USERNAME`
  - `HERMES_DASHBOARD_BASIC_AUTH_PASSWORD`
  - `HERMES_DASHBOARD_BASIC_AUTH_SECRET`
- Ubicación actual: `.env` de la raíz.
- Estado: contraseña y secreto rotados localmente.
- Verificación realizada: login por `/auth/password-login` exitoso.
- Si se vuelve a rotar: recrear el contenedor Hermes y repetir el login.

### API server local

- Variable: `API_SERVER_KEY`.
- Ubicación actual: `.env` de la raíz.
- Estado: rotada localmente.
- Verificación pendiente: realizarla cuando el API server protegido esté
  habilitado, sin invocar acciones de movimiento.

### Punto de acceso Wi-Fi de la cámara ESP32

- Variables:
  - `ESP32_CAMERA_WIFI_SSID`
  - `ESP32_CAMERA_WIFI_PASSWORD`
- Ubicaciones locales:
  - `.env` de la raíz.
  - `esp32_camera_udp/include/secrets.h`, ignorado por Git.
- Estado: contraseña rotada en ambos archivos locales.
- Importante: la nueva contraseña no llega al dispositivo hasta recompilar y
  cargar el firmware.
- Después de cargar:
  1. Verificar el SSID por serial sin imprimir la contraseña.
  2. Actualizar la conexión Wi-Fi del PC usando el valor de `.env`.
  3. Probar descubrimiento UDP y recepción de video.

## Historial de Git

Mover credenciales a `.env` protege commits nuevos, pero no elimina valores de
commits anteriores. El análisis local encontró las credenciales SSH y API del
DeepRacer en varios commits históricos.

Opciones:

1. Rotar las credenciales y conservar el historial. Los valores antiguos dejan
   de ser útiles, aunque siguen visibles.
2. Rotar y reescribir el historial con una herramienta como `git filter-repo`,
   coordinando después un `force push` y la resincronización de todos los clones.

La opción 1 es suficiente para invalidar los secretos anteriores. La opción 2
reduce su exposición documental, pero es disruptiva y requiere coordinación.

## Comprobación previa al push

- [ ] `.env` está ignorado por Git.
- [ ] `esp32_camera_udp/include/secrets.h` está ignorado.
- [ ] `.env.example` contiene solo `CHANGE_ME` o valores no sensibles.
- [ ] No hay contraseñas, tokens o claves privadas en el diff.
- [ ] Las bases de datos, caches, logs y estados de Hermes no están staged.
- [ ] Las credenciales críticas expuestas se rotarán inmediatamente después del
      commit, o antes si el repositorio es público.
- [ ] Se revisó `git diff --cached` antes de hacer push.
