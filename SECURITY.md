# Seguridad y credenciales

## Configuración local

Todas las credenciales operativas deben vivir en el archivo `.env` de la raíz.
Ese archivo está ignorado por Git. La lista pública de variables y valores de
ejemplo está en `.env.example`.

No se deben crear archivos `.env` adicionales dentro de `apps/backend/`, `apps/frontend/`
o `hermes/`. Backend y Vite leen la configuración de la raíz; Docker Compose la
carga mediante `env_file`.

El firmware ESP32 es la única excepción técnica: C++ necesita
`firmware/esp32-camera-udp/include/secrets.h` durante la compilación. El archivo está
ignorado y su plantilla segura es `secrets.example.h`.

## Reglas

- Nunca escribir contraseñas, tokens o claves dentro de código, documentación,
  scripts, ejemplos, memorias o skills.
- Documentar una credencial usando solo el nombre de variable, por ejemplo
  `${DEEPRACER_API_PASSWORD}`.
- No imprimir contraseñas en logs, consola, puerto serie ni mensajes de error.
- No subir bases de datos, caches, archivos de estado o sesiones de Hermes.
- Antes de un commit, buscar secretos tanto en archivos rastreados como nuevos.
- Si un secreto entró en Git, moverlo a `.env` no es suficiente: debe rotarse y
  debe evaluarse limpiar el historial.

## Rotación

La lista operativa y el estado de cada credencial se mantienen en
[`CREDENTIAL_ROTATION.md`](CREDENTIAL_ROTATION.md).

Las credenciales locales del dashboard, API server y cámara ESP32 pueden
rotarse actualizando `.env`. La cámara también requiere actualizar el header
privado y recompilar/cargar el firmware.

Las claves de proveedores externos se rotan en el portal de su proveedor. Las
credenciales del DeepRacer se rotan en el propio dispositivo siguiendo su
procedimiento de recuperación. Nunca se inventan ni se cambian automáticamente
durante una reorganización del repositorio.

## Publicación segura

Antes de hacer push:

1. Confirmar que `.env` y `include/secrets.h` están ignorados.
2. Confirmar que no hay valores reales en el diff.
3. Retirar del índice archivos generados que Git ya estuviera siguiendo.
4. Rotar cualquier credencial que haya aparecido en commits anteriores.
5. Si el repositorio fue público o compartido, considerar comprometida toda
   credencial presente alguna vez en su historial.
