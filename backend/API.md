# Control del Vehículo vía API Backend

Backend en **Node.js + Express** que actúa como proxy entre el cliente y la API web del AWS DeepRacer.

---

## Inicio

```bash
cd /workspace/backend
npm run start
```

El servidor escucha en `http://0.0.0.0:5002` (puerto configurable vía variable de entorno `PORT`).

Al iniciar, automáticamente se autentica contra el DeepRacer (login CSRF + cookie session). Si la sesión expira, reautentica en el siguiente request.

---

## Endpoints

### POST /api/start

Prepara el vehículo para conducción manual.

**Request:**
```bash
curl -X POST http://localhost:5002/api/start
```

**Acciones internas:**
1. `PUT /api/drive_mode` → `{ "drive_mode": "manual" }`
2. `PUT /api/start_stop` → `{ "start_stop": "start" }`

**Respuesta:**
```json
{ "message": "Vehículo preparado (drive_mode/manual + start_stop/start)" }
```

---

### POST /api/stop

Detiene el vehículo.

**Request:**
```bash
curl -X POST http://localhost:5002/api/stop
```

**Acción interna:**
- `PUT /api/start_stop` → `{ "start_stop": "stop" }`

**Respuesta:**
```json
{ "message": "Vehículo detenido" }
```

---

### POST /api/manual_drive

Envía comandos de conducción manual al vehículo.

#### Activar modo manual (init)

Prepara el vehículo sin moverlo:

```bash
curl -X POST http://localhost:5002/api/manual_drive \
  -H "Content-Type: application/json" \
  -d '{"init": true}'
```

**Respuesta:**
```json
{ "message": "Modo manual activado y vehículo habilitado (esperando comandos)" }
```

#### Enviar comando de movimiento

```bash
curl -X POST http://localhost:5002/api/manual_drive \
  -H "Content-Type: application/json" \
  -d '{"angle": 0.5, "throttle": 0.3, "max_speed": 0.5}'
```

**Parámetros:**

| Campo      | Tipo   | Rango    | Descripción                          |
|------------|--------|----------|--------------------------------------|
| `angle`    | float  | -1 a 1   | Dirección (-1=izquierda, 1=derecha)  |
| `throttle` | float  | -1 a 1   | Aceleración (-1=reversa, 1=adelante) |
| `max_speed`| float  | 0 a 1    | Límite de velocidad (fracción)       |

Los valores se clamping automáticamente al rango válido.

**Acción interna:**
- `PUT /api/manual_drive` → `{ "angle": <clamped>, "throttle": <clamped>, "max_speed": <clamped> }`

**Respuesta:**
```json
{ "message": "Comando manual enviado" }
```

---

### GET /api/video_stream

Proxy del stream MJPEG de la cámara del DeepRacer.

```bash
curl http://localhost:5002/api/video_stream
```

Retorna un stream `multipart/x-mixed-replace` con boundary `boundarydonotcross`. Al cerrar la conexión, el servidor destruye el stream del vehículo.

---

## Flujo típico de uso

```
1. POST /api/start          → Prepara el vehículo
2. POST /api/manual_drive   → Envía comandos de movimiento (repetir según necesidad)
3. POST /api/stop           → Detiene el vehículo
```

### Ejemplo completo

```bash
# Iniciar
curl -X POST http://localhost:5002/api/start

# Giro suave a la derecha
curl -X POST http://localhost:5002/api/manual_drive \
  -H "Content-Type: application/json" \
  -d '{"angle": 0.5, "throttle": 0.3, "max_speed": 0.5}'

# Recto
curl -X POST http://localhost:5002/api/manual_drive \
  -H "Content-Type: application/json" \
  -d '{"angle": 0, "throttle": 0.3, "max_speed": 0.5}'

# Detener
curl -X POST http://localhost:5002/api/stop
```

---

## Autenticación interna

El backend gestiona automáticamente la autenticación contra el DeepRacer:

1. **GET /login** → Extrae el token CSRF del HTML (meta tag o input hidden)
2. **POST /login** → Envía `csrf_token` + `password` con header `X-CSRF-Token`
3. **Cookies** → Combina cookies del GET y POST para formar la sesión
4. **Reautenticación** → Si recibe 401/403, reautentica transparentemente

Todos los requests al DeepRacer incluyen:
- Header `X-CSRF-Token`
- Header `X-Requested-With: XMLHttpRequest`
- Cookie de sesión

---

## Dependencias

- `express` ^5.1.0
- `cors` ^2.8.5
- `dotenv` ^17.4.2

---

## Notas

- El backend usa **HTTPS** para comunicarse con el DeepRacer (puerto 5001) y **HTTP** para exponer la API local (puerto 5002).
- `rejectUnauthorized: false` está habilitado para el certificado autofirmado del DeepRacer.
- Los valores de `angle`, `throttle` y `max_speed` se limitan (clamping) al rango válido antes de enviarlos.
