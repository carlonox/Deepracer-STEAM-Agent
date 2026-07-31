# 📦 Inventario Detallado del Workspace — Deepracer-STEAM-Agent

> **Fecha del inventario:** 2026-07-31
> **Ubicación:** `/workspace` (montado desde el repositorio `Deepracer-STEAM-Agent`)
> **Proyecto:** Mascota AI basada en AWS DeepRacer controlada por Hermes Agent
> **Propósito de este documento:** Describir qué contiene cada archivo y carpeta del proyecto, para orientar cualquier sesión futura sin tener que re-explorar todo.

---

## 🧭 Visión general

El proyecto convierte un **AWS DeepRacer** (robot con ruedas, cámara, LEDs y ROS2) en una **mascota robótica autónoma del aula STEAM** de la Universidad Nacional de Colombia (sede Bogotá). El robot debe:

- Saludar y conversar con estudiantes (cerebro: Hermes Agent).
- Responder preguntas sobre los equipos del aula (sistema RAG con ~20 manuales).
- Navegar entre estaciones usando **marcadores ArUco** y cámara monocular.
- Recibir comandos por voz (STT) y responder hablando (TTS).

### Arquitectura en capas

```
┌─────────────────────────────────────────────────────┐
│  Hermes Agent (cerebro) — hermes/ + Docker          │
│  Dashboard web :9999 · API agente :8642             │
├─────────────────────────────────────────────────────┤
│  Frontend React (interfaz) — frontend/              │
│  Teclado · Gamepad · Quest VR · cámara en vivo      │
├─────────────────────────────────────────────────────┤
│  Backend Node.js (proxy) — backend/                 │
│  HTTP :5002 · TCP drive :5003 · SSH /api/exec       │
├─────────────────────────────────────────────────────┤
│  AWS DeepRacer (10.203.150.56)                      │
│  API web :5001 · cámara MJPEG :8080 · ROS2 Foxy     │
├─────────────────────────────────────────────────────┤
│  Sensores externos                                   │
│  ESP32-S3 + cámara OV3660 (video UDP) · KY-037      │
└─────────────────────────────────────────────────────┘
```

### Referencia rápida de red (credenciales en `HANDOFF.md` / `.env`)

| Servicio | Dirección |
|---|---|
| Robot IP LAN | `10.203.150.56` |
| Robot IP Tailscale | `100.117.192.31` |
| API web del robot | `https://10.203.150.56:5001` |
| Cámara MJPEG del robot | `http://10.203.150.56:8080/stream_viewer?topic=/camera_pkg/display_mjpeg` |
| Backend proxy local | `http://localhost:5002` |
| Canal TCP de manejo | `127.0.0.1:5003` |
| Dashboard Hermes | `http://localhost:9999` |
| API del agente Hermes | `http://localhost:8642` |
| Red Wi-Fi de la ESP32 | `DeepRacer-Camera` / clave `${ESP32_CAMERA_WIFI_PASSWORD}`, ESP en `192.168.4.1` |

---

## 📄 Archivos en la raíz del proyecto

### Documentación principal

| Archivo | Detalle |
|---|---|
| **`README.md`** | Portada del proyecto: requisitos (Docker Desktop, Tailscale, SSH), instalación rápida (`docker compose build` → `setup` → `run`), configuración del DeepRacer y estructura de carpetas. |
| **`Documentacion.md`** | (863 líneas) Documento de **migración de Hermes v0.16.0 → v0.18.0** "Judgment Release" (2026.7.1): paso a gateway mode con dashboard web nativo y API OpenAI-compatible. Incluye todos los problemas resueltos: dashboard con timeout silencioso, bug de v0.18.0 en `/auth/login`, autenticación en texto plano vs hash, variable `HERMES_DASHBOARD` que no llegaba al container, conflicto del CMD con s6-overlay y working directory incorrecto. |
| **`HANDOFF.md`** | (312 líneas) Guía de handoff para nueva sesión del agente: tabla de accesos (IPs, SSH, API, dashboards), **problemas de conexión conocidos** (SSH intermitente → persistir; firewall `iptables policy DROP` → `sudo iptables -I INPUT 1 -s 10.0.0.0/8 -j ACCEPT`; container Docker sin Tailscale → usar IP LAN; backend Node en Windows `:5002` como proxy alternativo), especificaciones del robot (Ubuntu 20.04.1, kernel 4.15 deepens, ROS2 Foxy, Python 3.8.5, Intel Atom x86_64, 29GB disco / 15GB libres, ~4GB RAM) y sección "sensores: realidad vs documentación". |
| **`inventario_deepracer.md`** | Inventario técnico del robot: **sensores** (cámara frontal `/dev/video0/1` MJPEG, LiDAR RPLIDAR 64 sectores ±60° 1m de alcance, I2C con 8 buses — batería/servo/motor/LED —, LED RGB por PWM, servo PWM 1220000–1900000, motor PWM 1311000–1603500 con polaridad −1); **API de control :5001** (flujo obligatorio: login → `drive_mode=manual` → `start_stop=start` → loop `manual_drive` → stop; watchdog 200ms sin pausas; throttle invertido — negativo = avanza — recomendado 0.7; angle −1 izq a +1 der; headers `X-CSRFToken`, `X-Requested-With: XMLHttpRequest`, cookie de sesión); **topics ROS2**: `/ctrl_pkg/raw_pwm` (motor) y `/ctrl_pkg/servo_msg` (dirección). |
| **`ESP32_CAMERA_UDP.md`** | Protocolo de la **cámara ESP32-S3 por UDP**: dos fuentes de video en `controlcamara.py` (`usb` o `esp32_udp`, actualmente `esp32_udp`); el PC escucha UDP `0.0.0.0:5000`; la ESP crea la red `DeepRacer-Camera`; descubrimiento con el mensaje `DEEPRACER_DISCOVER 5000` hacia UDP `5001`; formato de paquetes: **header big-endian de 14 bytes** = `frame_id:uint32, chunk_index:uint16, chunk_count:uint16, payload_size:uint16, timestamp_ms:uint32` + payload JPEG. |
| **`PENDIENTE_ESP32_CAMERA.md`** | Estado de la tarea **pausada** de la cámara ESP32: el firmware está escrito pero **no compilado ni cargado**. Hardware detectado: `COM8`, adaptador `USB-Enhanced-SERIAL CH343`, placa asumida **ESP32-S3-WROOM N16R8** con OV3660 (16MB flash, 8MB PSRAM). Cambios ya hechos (fuente `esp32_udp`, receptor UDP, firmware), herramienta PlatformIO instalada (ruta `$env:APPDATA\Python\Python313\Scripts\pio.exe`), pasos para terminar (compilar con `pio run`, cargar con `pio run --target upload` — truco BOOT+RESET —, monitor serie buscando `CAMERA_OK`/`WIFI SSID=DeepRacer-Camera`, conectar a la red Wi-Fi y probar con `py controlcamara.py`), pinout N16R8 CAM y advertencia de no cambiar pines a ciegas. |
| **`PROXIMA_ACTIVIDAD_ARUCO.md`** | Plan de la próxima actividad: **imprimir y pegar códigos ArUco** en el aula. Recomienda diccionario `DICT_6X6_250`, tamaño > 4×4 cm, IDs de ejemplo (10 = mesa, 20 = impresora, 30 = salida, 40 = zona de carga) y medir el tamaño real de cada código. |
| **`RESUMEN_FINAL_ARUCO.md`** | Resumen del sistema de navegación ArUco final: `controlcamara.py` como archivo único de control, detección de marcadores, ubicación por el ArUco más cercano, definición de lugares con `ARUCO_PLACES` (por ejemplo `10: mesa`, `20: impresora`, `30: salida`). |

### Código principal

| Archivo | Detalle |
|---|---|
| **`controlcamara.py`** | (1013 líneas) **Navegador ArUco + control del vehículo**, el cerebro de movimiento. Secciones: |
| | • **Config red/backend**: `BACKEND_URL = http://127.0.0.1:5002`, canal TCP de manejo `127.0.0.1:5003`, `ENABLE_VEHICLE_CONTROL = True`. |
| | • **Config cámara**: `CAMERA_SOURCE = "esp32_udp"` (o `"usb"`), tamaño 640×480, UDP `0.0.0.0:5000`, ESP en `192.168.4.1`. |
| | • **Config ArUco**: diccionario `DICT_ARUCO_ORIGINAL` + 6 diccionarios de diagnóstico, `MARKER_SIZE = 0.125` m (12.5 cm), distancia objetivo al waypoint 0.50 m con deadzone 0.08, throttles 0.60–0.70, `KP_STEER = 1.3`, límite de velocidad 0.70, safety frontal 35 cm, timeout de 2 frames si pierde el objetivo. |
| | • **Mapa/rutas**: `ARUCO_PLACES = {50: mesa, 100: impresora, 150: salida}` y grafo `ARUCO_ROUTES` (`mesa → impresora → salida`); palabras de parada (`para`, `detente`, `stop`…) y de movimiento (`ve`, `anda`, `llévame`…). |
| | • **Clases**: `DeepRacerAPIClient` (cliente del backend), `AsyncDriveSender` (envío asíncrono de comandos), `SafetyGate` (parada de seguridad), `LatestFrameCamera` (cámara USB) y `ESP32UdpJpegCamera` (receptor UDP con reassembly de JPEG). |
| | • **Funciones**: detección de marcadores, `estimate_pose_marker` (estimación de pose), `choose_marker`, `arrived_at_marker`, `drive_command_for_marker` (control proporcional al error), `shortest_place_route` (BFS por el grafo), consola de texto con intérprete de instrucciones ("ve a salida"), y `main()` con el bucle de navegación. |
| **`requirements-controlcamara.txt`** | Dependencias de `controlcamara.py` (62 bytes; verificar contenido — probablemente `opencv-contrib-python`, `numpy`, `requests`). |
| **`get_ip.py`** | Archivo de 2 bytes, prácticamente vacío (placeholder). |

### Infraestructura Docker

| Archivo | Detalle |
|---|---|
| **`docker-compose.yml`** | Servicio único `hermes` → container `deepracer-agent`, `restart: unless-stopped`, puertos `9999:9119` (dashboard) y `8642:8642` (API agente), volúmenes `./hermes:/opt/data` y `./:/workspace`, working dir `/workspace`. Variables: `TERM`, `OPENCODE_API_KEY`, `HERMES_DASHBOARD=1`, basic auth del dashboard (usuario `admin`). |
| **`docker-compose.template.yml`** | Plantilla del compose (632 bytes), probablemente sin credenciales reales. |
| **`Dockerfile.hermes`** | Imagen de Hermes con **paramiko** instalado (para SSH desde el container). |

### Scripts de arranque Windows

| Archivo | Detalle |
|---|---|
| **`start-deepracer.ps1`** | Orquestador de arranque en 5 pasos: (1) verifica/inicia Docker Desktop con timeout de 60s, (2) `docker compose build hermes`, (3) `docker compose up -d hermes` con chequeo de estado, (4) inicia el backend Node (`server.js` en `backend/`, ventana minimizada), (5) verifica servicios: dashboard `:9999/login`, API `:8642` y backend `:5002/api/start`. Imprime URLs finales. |
| **`stop-deepracer.ps1`** | Detiene los servicios (641 bytes). |

### Otros

- **`.gitignore`** — excluye `.env`, `node_modules`, archivos internos de Hermes, etc.
- **`.git/`** — repositorio git (ver historial al final).
- **`.env.example`** — plantilla de variables: `DEEPRACER_HOST`, `DEEPRACER_SSH_USER`, `DEEPRACER_SSH_PASS`, `DEEPRACER_API_PORT`, `DEEPRACER_API_PASS`.

---

## 🔧 `backend/` — Proxy Node.js + Express (puerto 5002)

Backend que **intermedia entre cualquier cliente y la API web del DeepRacer**. Maneja la autenticación (login + CSRF + cookies), el proxy de video y un canal TCP rápido para manejo continuo.

| Archivo | Detalle |
|---|---|
| **`server.js`** | (220 líneas) API Express + CORS + bodyParser. Endpoints: |
| | • `POST /api/start` — prepara el vehículo (`drive_mode/manual` + `start_stop/start`). |
| | • `POST /api/stop` — detiene el vehículo. |
| | • `POST /api/manual_drive` — con `{init:true}` activa modo manual; si no, envía `{angle, throttle, max_speed}` (valida que estén los 3). |
| | • `POST /api/exec` — ejecuta **comandos SSH arbitrarios** en el robot vía `ssh2` (devuelve `{stdout, stderr, exit}`). |
| | • `GET /api/video_stream` — proxy del stream MJPEG del robot (`/route?topic=/camera_pkg/display_mjpeg&width=480&height=360`) con reautenticación automática si la sesión expira. |
| | • **Servidor TCP de manejo** en `127.0.0.1:5003`: protocolo de líneas JSON (`{init:true}`, `{stop:true}` o `{angle, throttle, max_speed}`), responde `{ok, message}` por línea; encadena comandos con promises para no pisarse (crítico por el watchdog de 200ms del robot). |
| **`vehicleControl.js`** | Cliente HTTPS de la API del robot: `findCsrf()` (parsea el token CSRF del HTML del login), `authenticate()` (POST del formulario con cookie), `ensureSession()`/`initSession()` con **reautenticación automática** al fallar; `startVehicle()`, `stopVehicle()`, `manualDrive()` (con clamp de angle/throttle/max_speed a [−1,1]/[0,1]); `getVideoStream()` con retry si recibe 401/403. Usa `keepAliveAgent` con `rejectUnauthorized: false` (certificado autofirmado). |
| **`API.md`** | Documentación de la API con ejemplos `curl` para cada endpoint y explicación de las acciones internas contra el robot. |
| **`scripts/aruco_detect.py`** | Detector de marcadores ArUco para correr **en el propio DeepRacer**: captura frames del `web_video_server` (puerto 8080), calcula distancia estimada con tamaño del marcador y longitud focal; opciones `--calibrate`, `--marker-size`, `--focal-length`. Autor: OWL, 2026-01-17. |
| **`package.json`** | Dependencias: `express ^5.1.0`, `cors ^2.8.5`, `dotenv ^17.4.2`, `ssh2 ^1.17.0`. `"type": "module"`. |
| **`node_modules/`** | Dependencias instaladas (26 MB). |

---

## 🖥️ `frontend/` — Interfaz web React + Vite

Interfaz heredada del proyecto 2025 (conservada como base de comunicación con el hardware). React 18 + Vite 7 + Tailwind 3 + daisyUI 4 + lucide-react.

| Archivo | Detalle |
|---|---|
| **`src/App.jsx`** | Componente raíz: orquesta todo — estado de `manualMode`, `maxSpeed` (slider, default 0.5), `gamepadMode` (`joystick`/`triggers`), `vrMode`; conecta los hooks de gamepad, teclado y VR; incluye logging exhaustivo de eventos pointer/mouse/touch (para depuración); botones de iniciar/detener. |
| **`src/services/vehicleApi.js`** | Capa de API del frontend: `apiPost()` a `http://<hostname>:5002/api/...`; exporta `startAutoMode`, `stopVehicle`, `activateManualMode` (con `{init:true}`), `sendManualCommand(angle, throttle, maxSpeed)`. |
| **`src/hooks/useVehicleControl.js`** | Hook de operaciones del vehículo: `startAuto`, `stop`, `activateManual`, con estados `loading`/`status`/`manualMode`. |
| **`src/hooks/useGamepad.js`** | Control por gamepad (Xbox): modo joystick o triggers; deadzone de ejes 0.15, triggers 0.05, paso de velocidad 0.05; botones LB/RB (freno), L3/R3 y A/B/X/Y; loop de lectura con `requestAnimationFrame` y envío continuo de comandos. |
| **`src/hooks/useKeyboard.js`** | Control por teclado: flechas + WASD, combinaciones para ángulo+throttle simultáneos; devuelve el set de teclas presionadas. |
| **`src/hooks/useQuestVRInput.js`** | Entrada VR (Meta Quest 3) vía **WebXR**: detección de soporte (`navigator.xr`, modos immersive-vr/ar/inline), sesión inmersiva, estado de los controladores izquierdo/derecho (stick, trigger, grip) y envío de steering/throttle. |
| **`src/components/camera/CameraFeed.jsx`** | Visor de la cámara: MJPEG desde `http://<VITE_AWS_HOST>:8080/stream?topic=/camera_pkg/display_mjpeg&width=1280&height=720` con botón de pantalla completa. |
| **`src/components/camera/CameraStream.jsx`** | Variante/alternativa del visor de cámara (junto con `index.js` barrel export). |
| **`src/components/controls/KeyboardControls.jsx`** | Botones direccionales en pantalla (táctiles) que emulan el teclado (d-pad con flechas). |
| **`src/components/controls/GamepadSettings.jsx`** | Panel de configuración del gamepad: tarjetas seleccionables joystick vs triggers (deshabilitadas si no hay gamepad conectado). |
| **`src/components/vr/QuestVRControls.jsx`** | Panel de control VR: estado de soporte, iniciar/terminar sesión WebXR, indicadores de conexión. |
| **`move.js`** | (314 líneas) Script de **depuración de movimiento** en Node: login contra `:5001` y loop de `manual_drive` por 5s con intervalo de 100ms y 3 reintentos (útil para probar el robot sin el frontend). |
| **`vite.config.js`, `tailwind.config.js`, `postcss.config.js`, `eslint.config.js`, `index.html`, `src/main.jsx`, `src/index.css`** | Configuración estándar del toolchain. |
| **`package.json`** | Deps: `react`, `react-dom`, `lucide-react`, `dotenv`. Dev: vite, tailwind, daisyUI, eslint, autoprefixer, postcss, plugin-react. |
| **`node_modules/`** | Dependencias instaladas (121 MB). |

---

## 📚 `RAG/` — Sistema RAG del aula STEAM

Base de conocimiento para que la mascota responda preguntas sobre los equipos del aula. **20 manuales en Markdown**:

| Manual | Equipo |
|---|---|
| `Manual_AWS_DeepRacer.md` | El propio robot |
| `Manual_Brazo_Robot_MG-400_Dobot.md` | Brazo robótico Dobot MG-400 |
| `Manual_Computador_Mesa_HP.md` | PC de mesa HP |
| `Manual_Computadores_Lenovo_IdeaPad_Slim_3.md` | Portátiles Lenovo |
| `Manual_Dron_DJI_Mini_3.md` | Dron DJI Mini 3 |
| `Manual_Escaner_3D_Revopoint_Range_2.md` | Escáner 3D Revopoint |
| `Manual_Estacion_Soldadura_Baku_909.md` | Estación de soldadura |
| `Manual_Herramienta_Rotativa_Truper_MOTO-A2.md` | Dremel Truper |
| `Manual_Impresora3D_Fused_Form_FF_STD.md` | Impresora Fused Form |
| `Manual_Impresora_3D_Anycubic_Photon_Mono_2.md` | Impresora resina Anycubic |
| `Manual_Impresora_3D_Creality_Ender_3_S1.md` | Impresora Creality Ender 3 S1 |
| `Manual_Impresora_3D_Creality_K1.md` | Impresora Creality K1 |
| `Manual_Impresora_3D_Tronxy_Moore_1.md` | Impresora Tronxy |
| `Manual_Lapiz_3D_SUNLU_SL_300.md` | Lápiz 3D SUNLU |
| `Manual_Maquina_Curado_Anycubic_Wash_and_Cure_3.md` | Máquina de lavado/curado |
| `Manual_Microcontrolador_Arduino_Mega_2560.md` | Arduino Mega |
| `Manual_Samsung_Gear_360_2017.md` | Cámara 360 Samsung |
| `Manual_Veikk_VK2200_PRO.md` | Tableta gráfica Veikk |
| `Manual_Wacom_Cintiq_Pro_16.md` | Tableta Wacom |
| `GUIA_SETUP.md` | Guía de setup y control del DeepRacer (copia de `docs/`) |

**Código:**

| Archivo | Detalle |
|---|---|
| **`indexador.py`** | Indexación: lee todos los `.md`, los parte con `RecursiveCharacterTextSplitter`, genera embeddings con `HuggingFaceEmbeddings` (sentence-transformers) y construye un **índice FAISS** guardado en disco. |
| **`agente.py`** | Consulta semántica: carga el índice FAISS, recupera los fragmentos relevantes y genera **respuestas en español** usando un LLM vía `OpenAI`-compatible (Ollama local) — patrón RAG clásico (retrieve + generate). |
| **`requirements.txt`** | `langchain >=0.3`, `langchain-community`, `sentence-transformers >=3`, `faiss-cpu >=1.8`, `openai >=1`, `python-dotenv`. |

---

## 🎙️ `SpeechToText/` — Reconocimiento de voz en tiempo real

| Archivo | Detalle |
|---|---|
| **`server.py`** | Servidor STT con **Faster Whisper large-v3 en CUDA** (`float16`): sample rate 16 kHz, umbral de energía 0.015 (sensibilidad del micrófono), pausa de 0.7s para considerar frase completa, duración mínima de habla 0.8s (ignora ruidos cortos), frames de 30ms, transcripción asíncrona con `beam_size=5`, idioma español y filtro VAD. Imprime la transcripción por frase. |
| **`test/audio_convert.py`** | Utilidad para convertir audio de prueba. |
| **`test/server_test.py`** | Prueba del servidor con `test/audio.wav`. |
| **`test/audio.wav`** | Audio de prueba. |
| **`venv/`** | Entorno virtual con el modelo (≈1.1 GB en total con dependencias). |
| **`realtimesst.log`** | Log de ejecuciones anteriores. |

---

## 🔊 `TextToSpeech/` — Síntesis de voz

| Archivo | Detalle |
|---|---|
| **`server.py`** | Genera audio hablado con **edge-tts** usando la voz `es-CO-SalomeNeural`; luego convierte el MP3 a **WAV PCM 16 kHz mono 16-bit** con `pydub` — el formato exacto que espera el pipeline de audio del robot (compatible con el STT). Incluye texto de prueba con pausas naturales. |

---

## 📷 `esp32_camera_udp/` — Firmware ESP32-S3 (cámara por UDP)

Proyecto **PlatformIO** para convertir una ESP32-S3 con cámara OV3660 en una cámara inalámbrica para el robot (porque la cámara USB del DeepRacer tiene limitaciones).

| Archivo | Detalle |
|---|---|
| **`platformio.ini`** | Config: plataforma `espressif32`, board `esp32-s3-devkitc-1`, framework Arduino, monitor 115200, puertos `COM8`, **flash 16MB** (`qio_opi`), **PSRAM OPI**, particiones `huge_app.csv`, flags `BOARD_HAS_PSRAM` y `CORE_DEBUG_LEVEL=3`. |
| **`src/main.cpp`** | (222 líneas) Firmware completo: |
| | • Crea **punto de acceso Wi-Fi** `DeepRacer-Camera` / `${ESP32_CAMERA_WIFI_PASSWORD}` (IP de la ESP: `192.168.4.1`). |
| | • Escucha **descubrimiento** UDP en `5001` (`DEEPRACER_DISCOVER`); aprende la IP del PC y empieza a transmitir. |
| | • Transmite **JPEG HVGA (480×320), calidad 16, máx 25 FPS** por UDP `5000`, fragmentado en chunks de 1300 bytes con el **header de 14 bytes big-endian** del protocolo (`frame_id`, `chunk_index`, `chunk_count`, `payload_size`, `timestamp_ms`). |
| | • **Timeout de 3s**: si no recibe mensajes del PC, deja de enviar (ahorro de batería). |
| | • Pinout de la variante **N16R8 CAM**: SDA=4, SCL=5, XCLK=15, PCLK=13, VSYNC=6, HREF=7, D0=11, D1=9, D2=8, D3=10, D4=12, D5=18, D6=17, D7=16. Frames en **PSRAM** con `CAMERA_GRAB_LATEST`. |
| **`pio-build.out.log` / `pio-build.err.log`** | Logs de la compilación previa (quedó pausada al 60% de la descarga del framework; ver `PENDIENTE_ESP32_CAMERA.md`). |

---

## 📁 `docs/` — Documentación del proyecto

| Archivo | Detalle |
|---|---|
| **`GUIA_SETUP.md`** | Guía práctica **completa** de setup y control: material necesario (DeepRacer, power bank 5V/2A, monitor HDMI, ratón…), encendido y conexión física, acceso SSH, **3 opciones de control** (1: interfaz web con teclado/gamepad/cámara; 2: SSH + ROS2 con script básico, teclado y joystick; 3: API web directa), solución de problemas y referencia rápida de comandos. |
| **`VISION_NUEVO_PROYECTO.md`** | **Visión 2026**: transformar el DeepRacer en mascota autónoma del aula STEAM — recepcionista que saluda, responde con RAG, guía físicamente con ArUco y (futuro) alarma sonora de fin de asesoría. Componentes: agente conversacional (OpenRouter), RAG local (FAISS/Chroma), navegación visual ArUco, voz local offline (Vosk STT + Piper TTS). Incluye tabla comparativa proyecto 2025 vs 2026 y qué se heredó del código anterior. |
| **`Recopilacion_2026-1_mejorada.md`** | Recopilación académica del proyecto: propósito (mascota STEAM), punto de partida (sistema web heredado funcional: frontend + backend), **limitaciones identificadas** del sistema heredado (errores poco claros, API sin especificar, interfaz incompleta para navegación/RAG/Hermes), y arquitectura modular propuesta. |
| **`INDICE_DOCUMENTACION.md`** | Índice que clasifica la documentación del proyecto anterior `SpeedRacerv.2` con tabla de relevancia: `calibration.json` (PWM motor/servo — Alta), `led_values.json` (PWM LEDs), `password.txt` (token — Alta), `sensor_configuration.json` (LiDAR), `software_update_status.json`, `start_ros.sh` (arranque ROS2 — Alta), `token.txt` (UUID), scripts de setup de ROS2 Foxy, y `ayuda_proximo_avance.md` (código ROS2 de control por teclado/gamepad — Alta). |
| **`README.md`** | Template por defecto de React + Vite (sin contenido propio). |
| **`SpeedRacerv.2/`** | Proyecto anterior (2025): |
| | • `Formulación del proyecto conducción autónoma mediante machine learning.pdf` / `.docx` — formulación original del proyecto de conducción autónoma con ML. |
| | • `Avances/` — avances 2–11 + `Actividades.docx` + `ayuda_proximo_avance.md` (493 líneas de código ROS2 reutilizable: control por teclado, gamepad, joystick, publicación a `/cmd_vel`). Los avances contienen configuraciones reales del DeepRacer (carpetas `aws/` y `foxy/`: calibración PWM, valores LED, configuración LiDAR, scripts de setup ROS2). |

---

## 🧠 `models/` — Modelos de IA

| Archivo | Detalle |
|---|---|
| **`yolov5n.onnx`** | Modelo **YOLOv5 nano** en formato ONNX (3.9 MB) — detección de objetos (probablemente para detectar personas/obstáculos con la cámara). |

---

## 💾 `backup/` — Respaldos de sesiones anteriores

| Archivo | Detalle |
|---|---|
| **`aruco_detection.md`** | Sistema de detección ArUco: pre-requisitos (`opencv-contrib-python==4.13.0.92`, `numpy`, `ffmpeg`, `web_video_server` en 8080) y verificación de dependencias en el DeepRacer. |
| **`connection_report.md`** | Reporte de conexión SSH: IP LAN, usuario `deepracer`, uso de **Paramiko** (subir scripts por SFTP a `/tmp/` y ejecutar por SSH). |
| **`drive_rules.md`** | **Reglas de control** aprendidas: `POST /api/start` siempre antes de mover; loop **sin pausas** (nunca `sleep` entre comandos); parámetros `angle` (−1 izq a +1 der) y `throttle` (−1 reversa a +1 adelante). |
| **`drive_test.py`** | Script de prueba de movimientos vía Paramiko: login con curl, extracción de cookie de sesión y CSRF, secuencia de movimientos en el robot. |
| **`explore_ros2.py`** | Explora los topics ROS2 del robot vía SSH (Paramiko) con timeout por comando. |
| **`ros2_topics.md`** | Resultado de la exploración: **7 topics ROS2**, todos de control (no de telemetría). |
| **`session_2026-06-17.md`** | Cuestionario de la sesión del 17-jun-2026: cómo conectarse (SSH, API web :5001 con HTTPS autofirmado), diferencias de credenciales, etc. |
| **`soul.md`** | **Primera versión del alma** de SpeedRacer (versión corta: identidad, personalidad, cuerpo). Predecesora del `SOUL.md` actual en `hermes/`. |

---

## 🔧 `bin/` — Herramientas

| Archivo | Detalle |
|---|---|
| **`arduino-cli`** | Binario de Arduino CLI (36 MB) — usado para flashear microcontroladores (Arduino Mega del aula, ESP32, etc.). |

---

## 🤖 `hermes/` — Hogar de Hermes Agent (11 GB)

Carpeta montada como `/opt/data` dentro del container. Contiene todo el estado del agente:

| Ruta | Detalle |
|---|---|
| **`SOUL.md`** | **Personalidad actual de SpeedRacer** (versión extendida): identidad (agente de IA en un DeepRacer, hogar = Hermes sobre `/workspace`, robot en `10.203.150.56`), personalidad en español, capacidades (conducir con throttle negativo = adelante, LEDs por estado — verde=ando, rojo=freno, naranja=reversa, morado=quieto —, escuchar aplausos/golpes con KY-037 en ESP32, ver con OpenCV, explorador autónomo v4, detectar atascos comparando fotos, esquivar obstáculos), aprendizajes en curso (no confundir motor con aplauso, mirar antes de moverse, retroceder más al atascarse, medir distancias, mapa mental) y filosofía: *"No necesito sensores caros si puedo chocar suave y recordar"*. |
| **`soul/soul.md`** | Copia/versión del alma en subcarpeta. |
| **`skills/`** | Habilidades de Hermes: archivos propios del proyecto (`aruco_detection.md`, `connection_report.md`, `drive_rules.md`, `ros2_topics.md`, `hermes-v18-bugs.md`) + categorías estándar (robotics, creative, github, mlops, productivity, research, smart-home, social-media, software-development, note-taking, email, media, data-science, autonomous-ai-agents, apple). |
| **`memories/`** | `MEMORY.md` (memoria persistente del agente), `USER.md` (perfil del usuario), `session_2026-06-17.md` (memoria de sesión). |
| **`scripts/`** | **19 scripts de diagnóstico y control** usados durante el desarrollo: `capture_photo.py` (captura de cámara), `debug_api*.py` (5 variantes de depuración de la API), `debug_login*.py` (5 variantes del login), `debug_move.py`, `debug_ros.py` / `debug_ros2.py`, `drive_test.py`, `explore_deepracer.py` / `explore_deepracer2.py`, `explore_ros2.py`, `get_login.py` / `get_login_html.py`. |
| **`cron/`** | Tareas programadas de Hermes: `executions.db`, `output/`, ticker de heartbeat. |
| **`config.yaml`** (+ 3 backups de 2026-07-07) | Configuración de Hermes: modelo `deepseek-v4-flash` vía proveedor `opencode-go`, dashboard, gateway, etc. |
| **`auth.json`, `gateway.pid`, `gateway_state.json`, `gateway-starts.log`, `gateway.lock`** | Estado del gateway de Hermes. |
| **`sessions/`, `logs/`, `plans/`, `kanban/`, `state.db`, `projects.db`, `verification_evidence.db`** | Base de datos de sesiones, logs, planes, tablero kanban y proyectos. |
| **`image_cache/`, `audio_cache/`, `images/`, `pastes/`, `pending_messages/`, `sandboxes/`, `lazy-packages/`** | Cachés y almacenamiento temporal del agente. |
| **`bin/`, `home/`, `hooks/`, `desktop/`, `skins/`, `pairing/`, `platforms/`, `channel_directory.json`** | Runtime de Hermes (binarios, hooks, plataformas de mensajería). |

---

## 🗂️ Otras carpetas

| Carpeta | Detalle |
|---|---|
| **`.kilo/`** | Herramienta KILO (agente de planificación): `node_modules/`, `package.json`, `plans/` (vacío por ahora). |
| **`.venv/`** | Entorno virtual Python de Windows (`Include/`, `Lib/`, `Scripts/`, `pyvenv.cfg`) — venv creado en Windows y montado en WSL. |
| **`__pycache__/`** | `controlcamara.cpython-313.pyc` — bytecode compilado de `controlcamara.py`. |
| **`.agents/`** | Vacío (reservado para agentes). |

---

## 📜 Historial del repositorio (git log, 15 commits más recientes)

| Commit | Descripción |
|---|---|
| `e729893` | **feat: voice transcription functionality** (STT) |
| `87efa51` | feat: pruebas de manejo |
| `856ff16` | feat: add KILO code y AgentWorkshop a .gitignore |
| `104474f` | feat: control, LEDs, ESP32, camera y explorador autónomo v4 |
| `11ff455` | docs: sesión ESP32 — MicroPython, KY-037, toolchain y hallazgos (identificación del ESP32-D0WD-V3, flasheo de MicroPython v1.28.0, integración KY-037 para aplausos/golpes, workarounds de toolchain, alternativas BLE: nativo/HC-05, pinout ESP32 DevKit V1) |
| `a8deffe` | feat: upgrade a Hermes v0.18.0 gateway mode con dashboard |
| `04949fe` | feat: DeepRacer STEAM Agent v2 — control, ROS2, cámara, ArUco, STT, proxy SSH |
| `f44f801` | fix: excluir archivos internos de Hermes del git |
| `060b686` | feat: añadir Hermes Agent al proyecto |
| `dc52d95` | feat: mejorar control del vehículo |
| `b9ee8c5` | feat: control del vehículo vía LAN |
| `2389a12` | fix: problema del stream de cámara |
| `83fd375` | feat: variables de entorno para el frontend |
| `9c2f4e3` | fix: reemplazar valores hardcodeados por env |
| `78dac0e` | fix: error de variables de entorno |

**Evolución del proyecto:** control por LAN → control de vehículo mejorado → Hermes integrado → v2 completo (ROS2, cámara, ArUco, STT, SSH proxy) → Hermes v0.18 gateway → sesión ESP32 (KY-037, MicroPython) → explorador autónomo v4 + cámara ESP32 → KILO → pruebas de manejo → transcripción de voz.

---

## ⚠️ Notas y advertencias para futuras sesiones

1. **Las contraseñas reales** (SSH, API web, dashboard) están en `HANDOFF.md`, `backup/`, `session_2026-06-17.md` y `.env` — este documento no las replica a propósito.
2. **Tarea pausada**: el firmware de `esp32_camera_udp` sigue sin compilarse/cargarse en la ESP32 (ver `PENDIENTE_ESP32_CAMERA.md`).
3. **Regla de oro del manejo**: siempre `POST /api/start` antes de mover y **nunca** `sleep` entre comandos (watchdog de 200ms del robot).
4. **SSH intermitente**: persistir en los reintentos; firewall del robot con `iptables policy DROP` (abrir con `-s 10.0.0.0/8 -j ACCEPT`).
5. **El container Docker no tiene Tailscale**: usar la IP LAN `10.203.150.56`.
6. `controlcamara.py` está pensado para correr con el **backend Node en `127.0.0.1:5002`** (o en el PC Windows con `start-deepracer.ps1`).

---

*Documento generado automáticamente tras exploración completa del workspace — 2026-07-31.*
