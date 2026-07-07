# Documento de Migración: Hermes v0.18.0 — Deepracer STEAM Agent

> **Fecha:** 2026-07-07
> **Versión anterior:** Hermes v0.16.0 (modo interactivo, sin dashboard)
> **Versión nueva:** Hermes v0.18.0 (2026.7.1) "Judgment Release" (gateway mode + dashboard web)
> **Plataforma:** Windows 11, Docker Desktop, PowerShell 7
> **Proyecto:** Deepracer STEAM Agent (robot AWS DeepRacer controlado por IA)
> **Referencia funcional:** ValentinaOS (mismo stack, funciona en otro PC)

---

## 1. Resumen Ejecutivo

### Objetivo
Migrar el agente Hermes del proyecto Deepracer-STEAM-Agent desde la versión v0.16.0 (modo interactivo, sin dashboard, sin API) a la versión v0.18.0 (gateway mode con dashboard web nativo y API OpenAI-compatible).

### Resultado
Sistema funcional con:
- ✅ Hermes v0.18.0 corriendo en container `deepracer-agent`
- ✅ Dashboard web accesible en `http://localhost:9999/login`
- ✅ Autenticación básica funcionando (usuario/password)
- ✅ Gateway corriendo con supervisión s6
- ✅ Modelo configurado: `deepseek-v4-flash` via OpenCode Go
- ✅ Proyecto montado en `/workspace/` dentro del container
- ✅ Scripts útiles del proyecto anterior preservados

### Duración total
Aproximadamente 4 horas de debugging distribuidas en una sesión.

### Problemas resueltos
- Dashboard no respondía HTTP (timeout silencioso)
- Bug conocido de v0.18.0 en la ruta `/auth/login`
- Autenticación mal configurada (password en texto plano vs hash)
- Variable `HERMES_DASHBOARD` no llegaba al container
- CMD del Dockerfile conflicto potencial con s6-overlay
- Agente no veía el proyecto (working directory incorrecto)

---

## 2. Contexto del Proyecto

### 2.1 Qué es Deepracer STEAM Agent
Un robot AWS DeepRacer convertido en mascota interactiva para aulas STEAM. El robot es controlado por un agente Hermes que:
- Conecta vía SSH al robot (paramiko)
- Tiene acceso a un backend Node.js (puerto 5002) para enviar comandos de movimiento
- Conversa con estudiantes en español
- Ejecuta secuencias de movimiento programadas
- Tiene una personalidad ("SpeedRacer")

### 2.2 Stack técnico

| Componente | Detalle |
|---|---|
| OS Host | Windows 11 |
| Container Runtime | Docker Desktop |
| Terminal | PowerShell 7 |
| Agente IA | Hermes Agent v0.18.0 |
| Imagen Docker | `nousresearch/hermes-agent:latest` |
| LLM | `deepseek-v4-flash` via OpenCode Go |
| Dependencia custom | Paramiko (SSH al robot) |
| Backend | Node.js (server.js, puerto 5002) |
| Proceso supervisor | s6-overlay v3 |

### 2.3 Arquitectura final

```
┌─────────────────────────────────────────────────────────────┐
│  Windows 11 Host                                            │
│                                                             │
│  ┌──────────────────┐    ┌──────────────────────────────┐   │
│  │  Navegador       │    │  Docker Container            │   │
│  │  localhost:9999   │───▶│  deepracer-agent             │   │
│  │  (Dashboard)     │    │                              │   │
│  └──────────────────┘    │  ┌─────────────────────────┐ │   │
│                          │  │ s6-overlay (PID 1)       │ │   │
│  ┌──────────────────┐    │  │  ├─ dashboard (:9119)   │ │   │
│  │  Backend Node.js │    │  │  ├─ main-hermes         │ │   │
│  │  localhost:5002  │◀───│  │  └─ gateway             │ │   │
│  └──────────────────┘    │  └─────────────────────────┘ │   │
│                          │                              │   │
│  ┌──────────────────┐    │  /workspace/ ← ./proyecto   │   │
│  │  AWS DeepRacer   │◀───│  /opt/data/  ← ./hermes     │   │
│  │  (SSH via WiFi)  │    │  (paramiko)                  │   │
│  └──────────────────┘    └──────────────────────────────┘   │
│                                                             │
│  ┌──────────────────┐                                       │
│  │  OpenCode Go API │◀── deepseek-v4-flash                 │
│  │  opencode.ai     │                                       │
│  └──────────────────┘                                       │
└─────────────────────────────────────────────────────────────┘
```

---

## 3. Migración Paso a Paso

### 3.1 Fase 1: Backup y Preservación

**Objetivo:** Guardar scripts y archivos útiles del proyecto anterior antes de borrar nada.

**Acciones realizadas:**
```powershell
cd C:\Users\UNAL\Deepracer-STEAM-Agent

# Backup de scripts útiles
mkdir backup 2>$null
copy hermes\scripts\drive_test.py backup\
copy hermes\scripts\explore_ros2.py backup\
copy hermes\skills\drive_rules.md backup\
copy hermes\skills\connection_report.md backup\
copy hermes\skills\ros2_topics.md backup\
copy hermes\skills\aruco_detection.md backup\
copy hermes\memories\session_2026-06-17.md backup\
copy hermes\soul\soul.md backup\
```

**Archivos preservados:**

| Archivo | Propósito |
|---|---|
| `drive_test.py` | Script de prueba de movimiento del robot |
| `explore_ros2.py` | Exploración de tópicos ROS2 |
| `drive_rules.md` | Reglas de conducción del robot |
| `connection_report.md` | Reporte de conexión SSH al robot |
| `ros2_topics.md` | Documentación de tópicos ROS2 disponibles |
| `aruco_detection.md` | Documentación de detección ArUco |
| `session_2026-06-17.md` | Memoria de la primera sesión funcional |
| `soul.md` | Identidad del agente "SpeedRacer" |

**Resultado:** ✅ Todos los archivos preservados antes de cualquier cambio destructivo.

---

### 3.2 Fase 2: Limpieza del Entorno Anterior

**Objetivo:** Eliminar la instalación anterior de Hermes v0.16.0 y sus datos residuales.

**Acciones realizadas:**

**Parar servicios activos:**
```powershell
# Matar backend si está corriendo
Get-Process -Name node -ErrorAction SilentlyContinue | Stop-Process -Force

# Parar containers de Hermes
docker compose down

# Verificar que no queda nada
docker ps
```

**Borrar datos residuales de Hermes:**
```powershell
Remove-Item -Recurse -Force hermes\data 2>$null
Remove-Item -Recurse -Force hermes\.hermes 2>$null
Remove-Item -Recurse -Force hermes\.cache 2>$null
Remove-Item -Recurse -Force hermes\.ssh 2>$null
Remove-Item -Recurse -Force hermes\.npm 2>$null
Remove-Item -Recurse -Force hermes\bin 2>$null
Remove-Item -Recurse -Force hermes\home 2>$null
Remove-Item -Recurse -Force hermes\lsp 2>$null
Remove-Item -Recurse -Force hermes\pastes 2>$null
Remove-Item -Recurse -Force hermes\sessions 2>$null
Remove-Item -Recurse -Force hermes\cache 2>$null
Remove-Item -Force hermes\auth.json 2>$null
Remove-Item -Force hermes\auth.lock 2>$null
Remove-Item -Force hermes\config.yaml 2>$null
Remove-Item -Force hermes\config.yaml.bak* 2>$null
Remove-Item -Force hermes\state.db* 2>$null
Remove-Item -Force hermes\.hermes_history 2>$null
Remove-Item -Force hermes\.install_method 2>$null
Remove-Item -Force hermes\*.json 2>$null
```

**Borrar imagen Docker vieja:**
```powershell
docker image prune -f
# Imagen custom vieja identificada y eliminada:
docker rmi deepracer-steam-agent-hermes:latest
# Imagen base nousresearch/hermes-agent:latest se mantuvo (es la base del nuevo Dockerfile)
```

**Estructura limpia recreada:**
```powershell
mkdir hermes\soul 2>$null
mkdir hermes\memories 2>$null
mkdir hermes\scripts 2>$null
mkdir hermes\skills 2>$null
mkdir hermes\workspace 2>$null

# Restaurar archivos del backup
copy backup\drive_test.py hermes\scripts\
copy backup\explore_ros2.py hermes\scripts\
copy backup\drive_rules.md hermes\skills\
copy backup\connection_report.md hermes\skills\
copy backup\ros2_topics.md hermes\skills\
copy backup\aruco_detection.md hermes\skills\
copy backup\session_2026-06-17.md hermes\memories\
copy backup\soul.md hermes\soul\
```

**Resultado:** ✅ Entorno limpio, archivos útiles preservados.

---

### 3.3 Fase 3: Reconstrucción de Imagen Docker

**Objetivo:** Crear una nueva imagen Docker basada en Hermes v0.18.0 con paramiko.

**Dockerfile.hermes (versión final funcional):**
```dockerfile
FROM nousresearch/hermes-agent:latest
RUN uv pip install paramiko
```

**Nota importante:** El Dockerfile NO incluye `CMD`, `EXPOSE` ni instrucciones adicionales. La imagen base ya tiene el ENTRYPOINT y CMD correctos. Agregar `CMD ["gateway", "run"]` causó problemas potenciales con s6-overlay (ver sección de errores).

**Construcción:**
```powershell
docker compose build --no-cache hermes
```

**Resultado:**
```
✔ Image deepracer-steam-agent-hermes Built
Tamaño: ~4.83 GB (base ~3.8 GB + dependencias)
```

✅ Imagen construida exitosamente.

---

### 3.4 Fase 4: Configuración del Setup Wizard

**Objetivo:** Ejecutar el asistente de configuración de Hermes v0.18.0.

**Ejecución:**
```powershell
docker compose run --rm hermes setup
```

**Configuración elegida:**

| Pregunta | Respuesta |
|---|---|
| Terminal backend | `local` |
| Provider | OpenCode Go |
| API Key | Token de OpenCode Go |
| Modelo | `deepseek-v4-flash` |
| Browser | `local` (Chromium incluido) |
| TTS | Edge TTS (incluido) |
| Image Gen | OpenAI (Codex auth) |
| Vision | Skip |
| Web Search | DuckDuckGo (ddgs) |
| Computer Use | cua-driver (instalado) |
| Messaging platforms | Ninguno |

**Resultado:** ✅ Configuración completada. Versión confirmada: `Hermes Agent v0.18.0 (2026.7.1)`.

---

### 3.5 Fase 5: Debugging del Dashboard (Problema Principal)

Esta fue la fase más larga. El dashboard no respondía HTTP a pesar de que los logs mostraban servicios arrancados correctamente.

#### Error 1: Dashboard sin respuesta HTTP

**Síntoma:**
```
curl.exe -v http://localhost:9999/
→ Connection established
→ Empty reply from server
→ curl: (52) Empty reply from server
```

**Diagnóstico:**
```powershell
# Puertos dentro del container
docker exec deepracer-agent sh -c "cat /proc/net/tcp"
# Resultado: Solo DNS de Docker (127.0.0.11). NADA en puerto 9119 ni 8642.
```

**Causa raíz:** El dashboard no estaba arrancando en absoluto. Los logs de s6 decían `dashboard successfully started` pero el proceso del dashboard HTTP nunca abría un socket.

**Técnicas de diagnóstico utilizadas:**

| Comando | Propósito | Resultado |
|---|---|---|
| `cat /proc/net/tcp` | Ver puertos escuchando | Solo DNS, nada más |
| `printenv HERMES_DASHBOARD` | Verificar variable de entorno | Variable presente |
| `env \| grep HERMES` | Listar env vars de Hermes | Variable NO aparecía en grep |
| `curl.exe -v` | HTTP verbose desde Windows | Empty reply |
| `docker compose logs hermes` | Logs del container | Servicios s6 "started" sin errores visibles |

---

#### Error 2: Variable `HERMES_DASHBOARD` no llegaba al container

**Síntoma:** `env | grep HERMES` no mostraba `HERMES_DASHBOARD` aunque estaba en docker-compose.yml.

**Causa:** La variable se escribió como `HERMES_DASHBOARD=true` en el docker-compose. Hermes requiere el valor numérico `1`.

**Fix:**
```yaml
# ANTES (no funcionaba)
environment:
  - HERMES_DASHBOARD=true

# DESPUÉS (funciona)
environment:
  - HERMES_DASHBOARD=1
```

**Verificación:**
```powershell
docker exec deepracer-agent sh -c "printenv HERMES_DASHBOARD"
# Resultado: 1
```

**Resultado:** ✅ Variable corregida y verificada.

---

#### Error 3: Puerto interno incorrecto

**Síntoma:** El puerto mapeado no coincidía con el puerto nativo del dashboard.

**Causa:** El dashboard nativo de Hermes v0.18.0 usa el puerto **9119** internamente, no 9999.

**Fix en docker-compose.yml:**
```yaml
# ANTES (incorrecto)
ports:
  - "9999:9999"

# DESPUÉS (correcto)
ports:
  - "9999:9119"
```

**Resultado:** ✅ Mapeo de puertos corregido.

---

#### Error 4: Autenticación mal configurada

**Síntoma:** Con `host: "0.0.0.0"` en config, el dashboard se negaba a abrir el puerto sin autenticación correctamente configurada.

**Causa:** Hermes v0.18.0 tiene un bloqueo de seguridad: si configuras `host: "0.0.0.0"`, requiere autenticación robusta. Sin ella, el dashboard se niega a abrir el puerto (fail closed). Además, `password` en texto plano no es aceptado — se requiere `password_hash` con scrypt o `password` gestionado por env vars.

**Intentos fallidos:**

| Intento | Configuración | Resultado |
|---|---|---|
| Sin auth | Solo `host` + `port` | Dashboard no abre puerto |
| Auth con placeholder | `password_hash: "scrypt$..."` (placeholder inválido) | Dashboard no abre puerto |
| Auth incompleta | `username` sin `password_hash` | Starlette crashea |
| Env vars de auth | `HERMES_DASHBOARD_BASIC_AUTH_*` | Ignoradas si config.yaml existe en bind mount |

**Fix definitivo (funcional):**
```yaml
dashboard:
  host: 0.0.0.0
  port: 9119
  basic_auth:
    username: admin
    password: <contraseña_en_texto_plano>
    secret: "***REMOVED***"
```

**Descubrimiento:** El campo `password` (no `password_hash`) con el campo `secret` es aceptado cuando se configura via `hermes config set` dentro del container. El setup wizard se encarga de generar el hash internamente.

**Resultado:** ✅ Autenticación configurada correctamente.

---

#### Error 5: CMD del Dockerfile conflicto con s6-overlay

**Síntoma:** Preocupación de que `CMD ["gateway", "run"]` interfiriera con los servicios s6.

**Causa:** La imagen de Hermes v0.18.0 usa s6-overlay v3 como supervisor de procesos (PID 1). s6 gestiona el gateway, el dashboard y otros servicios automáticamente. Agregar `CMD ["gateway", "run"]` explícitamente podría bypassar s6.

**Diagnóstico:**
```powershell
# Sin CMD en Dockerfile + HERMES_DASHBOARD=1 + auth correcta
# → s6 arranca TODOS los servicios incluyendo gateway
```

**Decisión:** Eliminar `CMD` del Dockerfile y dejar que s6-overlay gestione todo.

**Dockerfile final:**
```dockerfile
FROM nousresearch/hermes-agent:latest
RUN uv pip install paramiko
```

**Resultado:** ✅ Sin conflictos. s6 gestiona gateway + dashboard automáticamente.

---

#### Error 6: Bug conocido de v0.18.0 — Login devuelve 500

**Síntoma:** Al abrir `http://localhost:9999/` en el navegador, redirige a `/auth/login?provider=basic` que devuelve **500 Internal Server Error**.

**Causa raíz:** Bug documentado de Hermes v0.18.0 (Issue #58237). Cuando `basic_auth` es el único proveedor de autenticación y el dashboard está enlazado a `0.0.0.0`, visitar `/` redirige a `/auth/login?provider=basic` que llama `start_login()`. Pero `BasicAuthProvider` es password-only y lanza `NotImplementedError`, resultando en 500.

**Verificación de que el backend SÍ funciona:**
```powershell
# Autenticación via header HTTP funciona perfectamente
$pair = "admin:steambogadm"
$bytes = [System.Text.Encoding]::ASCII.GetBytes($pair)
$base64 = [Convert]::ToBase64String($bytes)
$authHeader = "Basic $base64"

curl.exe -v -H "Authorization: $authHeader" "http://localhost:9999/api/status"
# Resultado: 200 OK con JSON completo
```

**Fix:** Usar la ruta `/login` directamente en vez de `/`:
```
http://localhost:9999/login    ← FUNCIONA (formulario directo)
http://localhost:9999/         ← NO FUNCIONA (redirect roto → 500)
```

**Resultado:** ✅ Dashboard accesible usando ruta `/login`.

---

### 3.6 Fase 6: Configuración Final

**docker-compose.yml (versión final funcional):**
```yaml
services:
  hermes:
    build:
      context: .
      dockerfile: Dockerfile.hermes
    container_name: deepracer-agent
    restart: unless-stopped
    ports:
      - "9999:9119"
      - "8642:8642"
    volumes:
      - ./hermes:/opt/data
      - ./:/workspace
    working_dir: /workspace
    environment:
      - TERM=xterm-256color
      - OPENCODE_API_KEY=sk-...
      - HERMES_DASHBOARD=1
      - API_SERVER_ENABLED=true
      - API_SERVER_HOST=0.0.0.0
      - API_SERVER_KEY=deepracer-steam-agent-2026-secret
```

**config.yaml (versión final funcional):**
```yaml
model:
  default: deepseek-v4-flash
  provider: opencode-go
  base_url: https://opencode.ai/zen/go/v1
  api_mode: chat_completions
agent:
  max_turns: 150
  verify_on_stop: false
  verbose: false
  reasoning_effort: medium
dashboard:
  host: 0.0.0.0
  port: 9119
  basic_auth:
    username: admin
    password: <contraseña>
    secret: "***REMOVED***"
terminal:
  backend: local
  cwd: /workspace
  timeout: 180
memory:
  memory_enabled: false
  user_profile_enabled: false
session_reset:
  mode: none
compression:
  enabled: true
  threshold: 0.5
  target_ratio: 0.2
  protect_last_n: 20
  protect_first_n: 3
display:
  compact: false
  streaming: true
  tool_progress: all
web:
  backend: ddgs
  use_gateway: false
browser:
  cloud_provider: local
  use_gateway: false
tts:
  use_gateway: false
image_gen:
  use_gateway: false
plugins:
  enabled: []
_config_version: 33
```

**Configuración de `terminal.cwd: /workspace`:**
```powershell
docker exec -it deepracer-agent bash
hermes config set terminal.cwd /workspace
exit
docker compose restart hermes
```

**Resultado:** ✅ Agente ahora opera desde `/workspace/` (todo el proyecto).

---

### 3.7 Fase 7: Restauración de Archivos del Proyecto

**Archivos restaurados en la nueva estructura:**

```
hermes/
├── config.yaml              ← Config de Hermes v0.18.0
├── soul/
│   └── soul.md              ← Identidad de SpeedRacer
├── memories/
│   └── session_2026-06-17.md ← Memoria de sesión anterior
├── scripts/
│   ├── drive_test.py        ← Script de prueba de movimiento
│   └── explore_ros2.py      ← Exploración de tópicos ROS2
├── skills/
│   ├── drive_rules.md       ← Reglas de conducción
│   ├── connection_report.md ← Reporte de conexión SSH
│   ├── ros2_topics.md       ← Tópicos ROS2 documentados
│   └── aruco_detection.md   ← Detección ArUco
└── workspace/
    └── .gitkeep
```

**Resultado:** ✅ Todos los archivos útiles del proyecto anterior disponibles en la nueva versión.

---

## 4. Logros Alcanzados

| # | Logro | Estado | Detalle |
|---|---|---|---|
| 1 | Upgrade a Hermes v0.18.0 | ✅ | De v0.16.0 interactivo a v0.18.0 gateway mode |
| 2 | Dashboard web funcionando | ✅ | http://localhost:9999/login |
| 3 | Autenticación activa | ✅ | Basic auth con usuario/password |
| 4 | Gateway corriendo | ✅ | Supervisado por s6, auto-restart on crash |
| 5 | Modelo configurado | ✅ | deepseek-v4-flash via OpenCode Go |
| 6 | Sin modelos pagos | ✅ | Solo OpenCode Go, sin OpenRouter/Claude/GPT |
| 7 | Sin mem0/Qdrant | ✅ | Memoria desactivada (simplificación) |
| 8 | Proyecto accesible | ✅ | `/workspace/` como working directory |
| 9 | SSH habilitado | ✅ | Paramiko instalado en el Dockerfile |
| 10 | Scripts preservados | ✅ | Backup y restauración completos |
| 11 | Supervisión automática | ✅ | s6-overlay v3 con auto-restart |
| 12 | API Server configurado | ✅ | Puerto 8642 con API key |

---

## 5. Errores Encontrados y Soluciones

### 5.1 Tabla Resumen

| # | Error | Causa | Solución | Tiempo |
|---|---|---|---|---|
| 1 | Dashboard no abre puerto | `HERMES_DASHBOARD` no llegaba al container | Cambiar `true` → `1` en env var | ~30 min |
| 2 | Puerto incorrecto | Mapeo `9999:9999` pero puerto interno es 9119 | Cambiar a `9999:9119` | ~10 min |
| 3 | Auth rechaza conexiones | `host: 0.0.0.0` sin auth robusta bloquea el dashboard | Configurar `basic_auth` completo con `secret` | ~45 min |
| 4 | Auth con placeholder inválido | `password_hash: "scrypt$..."` era texto literal | Usar `password` en texto plano + `secret` | ~20 min |
| 5 | Env vars de auth ignoradas | `config.yaml` en bind mount prevalece sobre env vars | Configurar auth directamente en config.yaml | ~15 min |
| 6 | Login devuelve 500 | Bug conocido #58237 de v0.18.0 | Usar ruta `/login` en vez de `/` | ~20 min |
| 7 | Agente no ve proyecto | `terminal.cwd` apunta a `/opt/data/` | Cambiar a `/workspace` | ~5 min |
| 8 | CMD conflicto con s6 | `CMD ["gateway", "run"]` potencialmente bypassaba s6 | Eliminar CMD del Dockerfile | ~10 min |

### 5.2 Detalle de Cada Error

#### Error 1: `HERMES_DASHBOARD` no llegaba al container

**Causa profunda:** s6-overlay maneja variables de entorno de forma específica. La variable `HERMES_DASHBOARD=true` (string) no es interpretada igual que `HERMES_DASHBOARD=1` (numérico). Hermes internamente comprueba `if HERMES_DASHBOARD` de forma estricta.

**Lección:** Siempre usar valores numéricos para flags booleanos en variables de entorno de Hermes.

**Verificación:**
```powershell
# ANTES (no funcionaba)
docker exec deepracer-agent sh -c "printenv HERMES_DASHBOARD"
# Resultado: true (pero Hermes no lo reconocía)

# DESPUÉS (funciona)
docker exec deepracer-agent sh -c "printenv HERMES_DASHBOARD"
# Resultado: 1
```

#### Error 2: Puerto interno incorrecto

**Causa profunda:** La documentación de ValentinaOS menciona que el puerto nativo es 9119. Sin embargo, había confusión con el puerto 9999 que se usaba como "externo" en el mapeo. El error fue asumir que el puerto interno era igual al externo.

**Lección:** El puerto interno del dashboard de Hermes v0.18.0 es **9119** siempre. El puerto externo en docker-compose es el que tú elijas.

#### Error 3: Auth rechaza conexiones con `host: 0.0.0.0`

**Causa profunda:** Hermes v0.18.0 implementó una protección de seguridad: si el dashboard escucha en `0.0.0.0` (todas las interfaces), exige autenticación robusta. Sin ella, el dashboard se niega a abrir el socket HTTP. Esto es un fail-closed (más seguro que fail-open).

**Lección:** En Hermes v0.18.0, `host: 0.0.0.0` requiere `basic_auth` completo con `username` + `password` + `secret`.

#### Error 4: `password_hash` con placeholder

**Causa profunda:** Escribir `password_hash: "scrypt$N=16384$r=8$p=1$salt$hash"` como texto literal no es un hash válido. Hermes intenta parsearlo y falla silenciosamente.

**Lección:** No inventar hashes. Usar `password` en texto plano (Hermes lo hashea internamente al guardar con `hermes config set`) o generar el hash con herramientas cryptográficas reales.

#### Error 5: Env vars de auth ignoradas

**Causa profunda:** Documentado en ValentinaOS: "Las variables de entorno `HERMES_DASHBOARD_BASIC_AUTH_*` son IGNORADAS si el `config.yaml` ya existe en el bind mount." Hermes prioriza el archivo de configuración sobre las env vars para la sección de auth.

**Lección:** Siempre configurar auth en `config.yaml`. Las env vars son un fallback que solo funciona si NO hay config.yaml.

#### Error 6: Login devuelve 500

**Causa profunda:** Bug documentado de Hermes v0.18.0 (Issue #58237). El redirect de SSO de la ruta `/` a `/auth/login?provider=basic` llama `start_login()` que `BasicAuthProvider` no implementa. El flujo correcto es `/login` → formulario de contraseña → POST a `/auth/password-login`.

**Lección:** Siempre usar `http://localhost:9999/login` para acceder al dashboard.

#### Error 7: Agente no ve el proyecto

**Causa profunda:** El `working_dir` del docker-compose era `/workspace`, pero Hermes internamente usa `terminal.cwd` del config.yaml que apuntaba a `.` (que se resuelve a `/opt/data/`).

**Lección:** Configurar `terminal.cwd: /workspace` en el config.yaml para que el agente opere desde el directorio del proyecto.

#### Error 8: CMD conflicto con s6

**Causa profunda:** s6-overlay v3 toma control de PID 1 y gestiona sus propios servicios. El `ENTRYPOINT` de la imagen base es `/init` que arranca s6. Si agregas `CMD ["gateway", "run"]`, s6 lo trata como argumento del entrypoint y puede causar que el gateway se inicie DOS veces (una por s6 y otra por CMD).

**Lección:** No agregar CMD al Dockerfile si la imagen base ya usa s6-overlay.

---

## 6. Referencias

### 6.1 Documentación Consultada

| Fuente | URL / Referencia | Utilidad |
|---|---|---|
| Hermes Docker Guide | https://hermes-agent.nousresearch.com/docs/user-guide/docker.md | Configuración base del container |
| Hermes S6 Container Supervision | https://hermes-agent.nousresearch.com/docs/user-guide/skills/optional/devops/devops-hermes-s6-container-supervision | Arquitectura s6-overlay |
| Hermes Web Dashboard Docs | https://hermes-agent.nousresearch.com/docs/user-guide/features/web-dashboard | Dashboard configuration |
| s6-overlay v3 Migration Guide | https://github.com/just-containers/s6-overlay/blob/master/MOVING-TO-V3.md | Cambios de v2 a v3 |
| s6-rc Documentation | https://skarnet.org/software/s6-rc/s6-rc.html | Sistema de servicios |
| Hermes GitHub Issues | https://github.com/NousResearch/hermes-agent/issues | Bugs conocidos |
| ValentinaOS (proyecto hermano) | Documentación interna (06-troubleshooting.md, 07-migracion.md) | Referencia funcional directa |

### 6.2 Documentos de ValentinaOS Consultados

| Documento | Secciones Útiles |
|---|---|
| `06-troubleshooting.md` | Problema 1: Dashboard timeout silencioso (falta `secret`), Problema 2: Puertos interceptados por WSL2 |
| `07-migracion-a-hermes-v018.md` | Causa #3: Falta `HERMES_DASHBOARD=1`, Causa #7: Dashboard sin auth, Lección: Campo `secret` obligatorio |

### 6.3 Colaboración Inter-Agentes

| IA | Rol | Contribución |
|---|---|---|
| MiMo (Xiaomi) | Agente principal | Debugging, diagnóstico, implementación de fixes |
| DeepSeek v4-flash (via OpenCode Go) | Análisis de config | Identificó que `CMD` del Dockerfile interfería con s6 |
| Otra IA (con búsqueda web) | Investigación externa | Encontró Issue #58237 (bug del login), documentó workaround `/login` |

---

## 7. Recomendaciones

### 7.1 Para Futuras Migraciones de Hermes

1. **Leer la documentación ANTES de migrar** — Los 5 minutos que tomó leer `06-troubleshooting.md` de ValentinaOS habrían ahorrado ~2 horas de debugging.

2. **Usar `hermes config set` dentro del container** — Es la forma más confiable de configurar Hermes. Edita el config.yaml correctamente con hashes y todo.

3. **No inventar hashes de contraseña** — Usar `hermes config set dashboard.basic_auth.password <contraseña>` y dejar que Hermes genere el hash internamente.

4. **Siempre mapear al puerto 9119** — El puerto interno del dashboard es 9119 en v0.18.0. Ejemplo: `ports: "9988:9119"`.

5. **Usar `HERMES_DASHBOARD=1` (numérico)** — No `true`, no `yes`, no `on`. Solo `1`.

6. **No agregar CMD al Dockerfile** — La imagen base ya tiene s6-overlay que gestiona todo.

7. **Usar `/login` para acceder al dashboard** — Bug conocido de v0.18.0 en la ruta `/`.

8. **Configurar `terminal.cwd`** — Si tu proyecto no está en `/opt/data/`, configura el working directory en el config.yaml.

### 7.2 Para el Proyecto Deepracer STEAM Agent

1. **Crear scripts de inicio/apagado** — Los scripts `start-deepracer.ps1` y `stop-deepracer.ps1` automatizan el ciclo de vida.

2. **Documentar bugs conocidos** — Guardar los bugs de Hermes v0.18.0 en `hermes/skills/hermes-v18-bugs.md` para referencia futura.

3. **Configurar el SOUL.md** — Asegurar que el agente cargue su identidad de "SpeedRacer" automáticamente.

4. **Preparar skills de movimiento** — Crear skills para que el agente sepa cómo controlar el robot (secuencias de movimiento, detección de obstáculos, etc.).

5. **Configurar la comunicación con el backend** — El agente necesita saber cómo hablar con `http://host.docker.internal:5002/api/...` para enviar comandos al robot.

6. **Versionar con Git** — Hacer commit de la configuración final y push a GitHub.

### 7.3 Para Debugging de Docker + Hermes

1. **`cat /proc/net/tcp`** — Cuando `ss` y `netstat` no están disponibles, este archivo de `/proc` muestra todos los sockets TCP abiertos. El formato hex de puertos: `2367` = 9119, `21CA` = 8642.

2. **`curl.exe -v`** — Usar SIEMPRE `curl.exe` (no el alias de PowerShell `curl` que es `Invoke-WebRequest`). El `-v` muestra el handshake TCP completo.

3. **`docker exec <container> printenv <VAR>`** — Más confiable que `env | grep` para verificar una variable específica.

4. **`docker compose run --rm hermes`** — Para ver stdout/stderr en tiempo real (foreground) cuando los logs de `docker compose logs` no muestran errores.

5. **Separar problemas compuestos** — Resolver uno a la vez. Primero la variable de entorno, luego el puerto, luego la auth, luego el bug del login.

---

## 8. Comandos de Referencia Rápida

### Ciclo de Vida
```powershell
# Arrancar todo
.\start-deepracer.ps1

# Apagar todo
.\stop-deepracer.ps1

# Solo Hermes
docker compose up -d hermes
docker compose down

# Reiniciar Hermes
docker compose restart hermes
```

### Diagnóstico
```powershell
# Estado del container
docker ps --filter name=deepracer-agent

# Puertos escuchando dentro del container
docker exec deepracer-agent sh -c "cat /proc/net/tcp"

# Variables de entorno
docker exec deepracer-agent sh -c "printenv HERMES_DASHBOARD"

# Logs
docker compose logs hermes --tail 50

# Estado de servicios s6
docker exec deepracer-agent s6-rc -a list

# Health check del dashboard
curl.exe -s http://localhost:9999/api/status

# Health check con auth
$pair = "admin:steambogadm"
$bytes = [System.Text.Encoding]::ASCII.GetBytes($pair)
$base64 = [Convert]::ToBase64String($bytes)
curl.exe -s -H "Authorization: Basic $base64" http://localhost:9999/api/status
```

### Configuración
```powershell
# Entrar al container
docker exec -it deepracer-agent bash

# Cambiar config
hermes config set <key> <value>

# Ver config completa
hermes config show

# Editar config manualmente
notepad C:\Users\UNAL\Deepracer-STEAM-Agent\hermes\config.yaml
```

### Acceso al Dashboard
```
URL:     http://localhost:9999/login  (NO http://localhost:9999/)
Usuario: admin
Password: <la que configuraste>
```

---

## 9. Archivos del Proyecto (Estado Final)

```
C:\Users\UNAL\Deepracer-STEAM-Agent\
├── docker-compose.yml           ← Configuración de Docker Compose
├── Dockerfile.hermes            ← Imagen Docker (base + paramiko)
├── start-deepracer.ps1          ← Script de inicio
├── stop-deepracer.ps1           ← Script de apagado
├── backup/                      ← Archivos preservados de v0.16.0
│   ├── drive_test.py
│   ├── explore_ros2.py
│   ├── drive_rules.md
│   ├── connection_report.md
│   ├── ros2_topics.md
│   ├── aruco_detection.md
│   ├── session_2026-06-17.md
│   └── soul.md
├── hermes/                      ← Datos de Hermes (bind mount → /opt/data)
│   ├── config.yaml              ← Config de Hermes v0.18.0
│   ├── SOUL.md                  ← Identidad del agente
│   ├── soul/
│   │   └── soul.md
│   ├── memories/
│   │   └── session_2026-06-17.md
│   ├── scripts/
│   │   ├── drive_test.py
│   │   └── explore_ros2.py
│   └── skills/
│       ├── drive_rules.md
│       ├── connection_report.md
│       ├── ros2_topics.md
│       ├── aruco_detection.md
│       └── hermes-v18-bugs.md
├── backend/                     ← Backend Node.js
│   ├── server.js
│   └── ...
└── ... (otros archivos del proyecto)
```

---

## 10. Diferencias: Antes vs Después

| Aspecto | v0.16.0 (antes) | v0.18.0 (después) |
|---|---|---|
| Modo de operación | Interactivo (`docker compose run --rm`) | Gateway mode (servicio persistente) |
| Dashboard web | No disponible | http://localhost:9999/login |
| API OpenAI-compatible | No disponible | Puerto 8642 |
| Persistencia | Se pierde al cerrar terminal | `restart: unless-stopped` |
| Supervisión | Manual | s6-overlay v3 (auto-restart) |
| Autenticación | No disponible | Basic auth con usuario/password |
| Acceso | Solo terminal | Navegador web + terminal + API |
| Puertos expuestos | Ninguno | 9999 (dashboard), 8642 (API) |
| Working directory | `/opt/data/` | `/workspace/` (proyecto completo) |

---

## 11. Pendientes (Siguientes Pasos)

| # | Tarea | Prioridad | Dependencia |
|---|---|---|---|
| 1 | Conectar Hermes con backend Node.js (puerto 5002) | Alta | Backend corriendo |
| 2 | Configurar SOUL.md de SpeedRacer | Alta | Archivo existente |
| 3 | Crear skills de movimiento del robot | Alta | SSH al DeepRacer |
| 4 | Probar chat desde dashboard controlando robot | Media | Skills + backend |
| 5 | Configurar el watchdog (200ms) para comandos | Media | Backend + scripts |
| 6 | Push a GitHub | Baja | Todo funcional |
| 7 | Limpiar backup/ | Baja | Confirmar que todo funciona |

---

*Documento generado el 2026-07-07 durante la migración de Hermes v0.16.0 a v0.18.0 para el proyecto Deepracer STEAM Agent.*