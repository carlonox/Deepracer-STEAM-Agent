# Reporte Técnico: Conexión al DeepRacer

Reporte completo de cómo se conecta OWL al AWS DeepRacer para control de movimiento.

---

## 1. CONEXIÓN SSH

- **IP LAN:** `10.203.150.56`
- **Tipo de red:** WiFi local (no Tailscale; la IP de Tailscale no ha sido proporcionada)
- **Usuario:** `deepracer`
- **Contraseña SSH:** `${DEEPRACER_SSH_PASSWORD}`
- **Uso:** Se usa para subir y ejecutar scripts bash directamente en el vehículo vía Paramiko (Python). El script de drive_test se copia por SFTP a `/tmp/drive_test.sh` y se ejecuta por SSH.

---

## 2. API WEB DEL ROBOT

- **Puerto:** `5001`
- **Protocolo:** HTTP (no HTTPS desde dentro del vehículo; el backend usa HTTPS con `rejectUnauthorized: false` para el certificado autofirmado)
- **Contraseña de la API:** `${DEEPRACER_API_PASSWORD}` (diferente de la contraseña SSH)

### Flujo de autenticación CSRF

1. **GET /login** → Se obtiene el HTML de la página de login.
2. **Extraer CSRF token** → Se busca en el HTML el meta tag:
   ```html
   <meta name="csrf-token" content="TOKEN_AQUI">
   ```
   O alternativamente un input hidden:
   ```html
   <input name="csrf_token" value="TOKEN_AQUI">
   ```
3. **POST /login** → Se envía el formulario con:
   - Body: `csrf_token=TOKEN&password=${DEEPRACER_API_PASSWORD}`
   - Header: `X-CSRF-Token: TOKEN`
   - Header: `Content-Type: application/x-www-form-urlencoded`
   - Cookie: la cookie de sesión obtenida del GET anterior
4. **Combinar cookies** → Se juntan las cookies del GET y del POST para formar la cookie header completa.

### Manejo de cookie Secure

La cookie de sesión del DeepRacer tiene el flag `Secure`, lo que significa que el navegador solo la envía por HTTPS. Como la comunicación interna del vehículo es HTTP, hay que **inyectar manualmente la cookie en el cookie jar** (archivo `/tmp/cookies.txt` en el script bash, o en el objeto session de vehicleControl.js).

En el backend (`vehicleControl.js`), esto se maneja combinando las cabeceras `Set-Cookie` de las respuestas del GET y POST de login, y enviándolas manualmente en cada request.

---

## 3. COMANDOS DE MOVIMIENTO

### Endpoints (todos PUT, todos requieren headers de auth)

| Acción | Ruta | Body JSON |
|--------|------|-----------|
| Modo manual | `PUT /api/drive_mode` | `{"drive_mode": "manual"}` |
| Arrancar | `PUT /api/start_stop` | `{"start_stop": "start"}` |
| Detener | `PUT /api/start_stop` | `{"start_stop": "stop"}` |
| Mover | `PUT /api/manual_drive` | `{"angle": -1..1, "throttle": -1..1, "max_speed": 0..1}` |

### Headers obligatorios en cada request

```
Content-Type: application/json;charset=UTF-8
X-Requested-With: XMLHttpRequest
X-CSRF-Token: <token>
Cookie: <session cookies>
```

### Flujo completo de movimiento

```
1. GET /login          → Extraer CSRF token
2. POST /login         → Autenticar, obtener cookie de sesión
3. PUT /api/drive_mode → {"drive_mode": "manual"}     → Cambiar a modo manual
4. PUT /api/start_stop → {"start_stop": "start"}       → Habilitar motores
5. PUT /api/manual_drive → {"angle": X, "throttle": Y, "max_speed": Z}  → Mover
   (repetir paso 5 en loop CONTINUON SIN PAUSA hasta duración deseada)
6. PUT /api/start_stop → {"start_stop": "stop"}        → Detener motores
```

### ⚠️ REGLA CRÍTICA: Loop sin pausa

El DeepRacer SOLO se mueve mientras recibe comandos continuos. Si hay un gap de más than ~200ms entre comandos, el robot se detiene automáticamente.

- **Correcto:** Loop `while` sin `sleep` entre comandos
- **Incorrecto:** `for` con `sleep 200ms` entre comandos (mata el movimiento)
- **Throttle mínimo:** ≥ 0.5 para movimiento notable; recomendado 0.8 con max_speed 1.0
- **Duración del movimiento** = tiempo que dura el loop sin pausa

Ver `hermes/skills/drive_rules.md` para ejemplos funcionales.

---

## 4. SCRIPTS

### Script principal: drive_test.py

- **Ubicación:** `/workspace/hermes/scripts/drive_test.py`
- **Lenguaje:** Python 3 con Paramiko
- **Qué hace:**
  1. Conecta por SSH al DeepRacer (`10.203.150.56`)
  2. Genera un script bash con toda la secuencia de login + movimientos
  3. Lo sube por SFTP a `/tmp/drive_test.sh` en el vehículo
  4. Lo ejecuta por SSH
- **Secuencia de movimientos del script:**
  1. Recto rápido (throttle=0.7, 2s, 10 comandos a 0.2s)
  2. Giro izquierda (angle=-0.5, throttle=0.4, 1.5s)
  3. Giro derecha (angle=0.5, throttle=0.4, 1.5s)
  4. Recto lento (throttle=0.3, 2s)
  5. Stop
- **Tiempo de ejecución:** ~45 segundos (timeout del SSH exec_command)

### Backend proxy: server.js + vehicleControl.js

- **Ubicación:** `/workspace/backend/`
- **Lenguaje:** Node.js (ESM modules)
- **Puerto:** 5002
- **Tiempo de inicio:** ~3 segundos (incluye autenticación inicial con el vehículo)

---

## 5. VELOCIDAD Y REACCIÓN

### Latencias medidas (backend proxy, puerto 5002)

| Endpoint | Latencia |
|----------|----------|
| `POST /api/manual_drive` | **~115 ms** |
| `POST /api/stop` | **~3 ms** |

La diferencia se debe a que `manual_drive` hace un PUT HTTPS al vehículo (que incluye el handshake TCP/TLS), mientras que `stop` encuentra la sesión ya establecida.

### Latencia percibida

- Desde que se envía un comando al backend hasta que el robot reacciona: **~100-150 ms**
- El robot necesita comandos en loop **sin pausa** para mantener el movimiento
- Un solo comando `manual_drive` no produce movimiento sostenido
- Ver `hermes/skills/drive_rules.md` para la técnica correcta

---

## 6. PROBLEMAS Y LIMITACIONES

### Problemas conocidos

0. **Comando único no mueve:** Un solo `manual_drive` no produce movimiento sostenido. El robot necesita un flujo continuo de comandos sin pausa. Si hay un gap >200ms, se detiene. Esto NO es un bug del backend, es el comportamiento del firmware del DeepRacer.

1. **Cookie Secure flag:** La cookie de sesión tiene flag Secure pero el vehículo usa HTTP internamente. Requiere inyección manual del cookie jar. Si no se maneja correctamente, todos los requests devuelven 401/403.

2. **Sesión expirada:** Si la sesión caduca, los requests devuelven 401/403. El backend maneja reautenticación automática, pero el script bash de drive_test.py **no** — si la sesión expira a mitad de la secuencia, los comandos siguientes fallan silenciosamente.

3. **Certificado autofirmado:** El DeepRacer usa HTTPS con certificado autofirmado. El backend lo acepta con `rejectUnauthorized: false`, pero cualquier cliente estándar (curl, navegador) rechazará la conexión sin ese flag.

4. **Sin feedback de estado:** Los endpoints del DeepRacer no devuelven estado del vehículo (velocidad actual, ángulo de ruedas, etc.). No hay forma de saber si el robot ejecutó el comando más allá de observar el video stream.

5. **Video stream frágil:** El endpoint `/api/video_stream` puede colgarse si se abren múltiples conexiones simultáneas. Solo un cliente a la vez.

### Limitaciones

- No hay odometría ni telemetría disponible vía la API web
- No hay forma de saber la batería restante
- El control es open-loop: se envía el comando pero no se confirma ejecución
- El script drive_test.py solo funciona desde fuera del vehículo (requiere SSH desde otra máquina)
