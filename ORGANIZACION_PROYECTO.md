# Plan maestro de organización y migración segura

> Estado: fases 0-10 ejecutadas el 2026-07-31. Pendientes de host:
> validación Docker Compose (daemon no disponible en la sesión de migración),
> validación PowerShell en Windows y borrado de una carpeta vacía residual (`backend/`).
>
> Audiencia: personas y agentes de IA que mantengan este repositorio.
>
> Regla principal: ninguna mejora estética de estructura justifica romper una
> ruta, perder datos persistentes, divulgar secretos o activar el vehículo.

## 1. Objetivo

Transformar el repositorio en una estructura predecible donde una persona o un
agente pueda responder rápidamente:

1. ¿Dónde está el código de cada componente?
2. ¿Cuál es el punto de entrada y cómo se ejecuta?
3. ¿Qué depende de qué?
4. ¿Qué archivos son fuente, generados, históricos, persistentes o secretos?
5. ¿Qué documentación es vigente y cuál es solo referencia histórica?
6. ¿Cómo añadir, mover o retirar un componente sin romper el sistema?

La migración debe preservar el comportamiento observable del proyecto. Un
cambio de ubicación no debe cambiar APIs, puertos, credenciales, parámetros de
control, volúmenes, comportamiento de arranque ni protocolos de hardware.

## 2. Cómo debe usar este documento un agente de IA

Un agente que ejecute este plan debe:

1. Leer primero `AGENTS.md`, este documento, `README.md` y los `README.md` de
   los componentes afectados.
2. Inspeccionar `git status --short` y tratar todo cambio previo como propiedad
   del usuario. No mezclarlo, revertirlo ni formatearlo de manera incidental.
3. Ejecutar una sola unidad de migración por vez. Una unidad equivale a un
   componente o grupo documental con dependencias acotadas.
4. Crear un inventario de referencias antes de mover, y repetir la búsqueda
   después del movimiento.
5. Usar movimientos preservando historial (`git mv` cuando el archivo esté
   rastreado; movimiento literal seguro cuando aún no lo esté).
6. Actualizar código, configuración, documentación, ejemplos y reglas de
   ignore en la misma unidad de cambio.
7. Ejecutar las puertas de validación indicadas para la unidad.
8. Detenerse si una validación falla. Reparar dentro de la misma unidad o
   restaurar únicamente los movimientos realizados por esa unidad.
9. No ejecutar pruebas que arranquen o muevan el vehículo sin autorización
   explícita y confirmación de que está elevado y en una zona despejada.
10. Registrar el resultado en la sección de progreso de este documento.

No se permite ejecutar todas las fases como una sustitución masiva sin puntos
de control. La estructura contiene datos vivos de Hermes, dependencias grandes,
documentos históricos y rutas utilizadas desde Windows y desde Docker.

## 3. Principios permanentes de organización

### 3.1 Organización por responsabilidad

- El código se agrupa por servicio o dispositivo, no por lenguaje.
- Un componente contiene su código, manifiesto de dependencias, pruebas,
  configuración de ejemplo y documentación local.
- El código compartido solo se extrae cuando lo consumen al menos dos
  componentes y existe un contrato estable.

### 3.2 Raíz pequeña y orientadora

La raíz se reserva para:

- `README.md`, `AGENTS.md` y este plan.
- Configuración transversal: Compose, Dockerfile, `.gitignore`, plantillas de
  variables globales.
- Lanzadores compatibles que una persona deba encontrar inmediatamente.

No deben aparecer en la raíz nuevos experimentos, logs, modelos, respaldos,
manuales aislados ni scripts de un único componente.

### 3.3 Fuente, estado y documentación separados

Cada archivo debe pertenecer a una categoría:

| Categoría | Ejemplos | Política |
|---|---|---|
| Fuente | `.py`, `.js`, `.jsx`, `.cpp` | Versionar, revisar y probar. |
| Configuración pública | `.env.example`, plantillas YAML | Versionar sin secretos. |
| Secreto local | `.env`, claves, tokens, `auth.json` | No versionar ni documentar valores. |
| Generado | `node_modules`, `venv`, `.pio`, cachés | No mover como fuente; regenerar. |
| Persistente | bases de datos, memorias y estado de Hermes | Respaldar; no reorganizar con Hermes activo. |
| Documentación activa | guías de operación y arquitectura actual | Mantener enlaces y propietario. |
| Histórico | entregas antiguas, copias, entornos ROS exportados | Archivar; nunca presentar como guía vigente. |
| Artefacto binario | modelos ONNX, herramientas descargadas | Documentar origen, versión, hash y licencia. |

### 3.4 Navegación en tres saltos como máximo

Desde `README.md` debe poder llegarse en no más de tres enlaces a:

- El README de cualquier componente.
- Su punto de entrada.
- Sus instrucciones de ejecución y pruebas.
- Su configuración de ejemplo.
- Su documentación técnica relevante.

### 3.5 Documentación junto al cambio

Un cambio estructural no está completo si no actualiza:

- El README raíz cuando cambia el mapa general.
- El README del componente cuando cambia su contenido o forma de ejecución.
- Este documento si cambia un principio, categoría o destino canónico.
- `AGENTS.md` si cambia una regla que futuros agentes deben aplicar.
- Enlaces, ejemplos de comandos y diagramas que nombren rutas antiguas.

## 4. Arquitectura y dependencias que deben preservarse

### 4.1 Flujo funcional

```text
Usuario / Hermes / Frontend
             |
             v
Backend local :5002 y canal TCP :5003
             |
             v
API web del AWS DeepRacer :5001

Cámara DeepRacer / Cámara ESP32
             |
             v
Navegación ArUco (controlcamara.py)
             |
             v
Backend local -> vehículo

Voz -> STT -> Hermes/RAG -> TTS
```

### 4.2 Contratos de rutas actuales

Estos contratos existen antes de la migración y deben actualizarse de forma
coordinada:

| Contrato | Consumidores principales | Riesgo |
|---|---|---|
| Raíz montada en `/workspace` | Compose, Hermes, skills, documentación | Alto |
| `./hermes` montado en `/opt/data` | Compose y estado persistente | Crítico |
| `working_dir: /workspace` | Docker/Hermes | Alto |
| `$PSScriptRoot\backend` | `start-deepracer.ps1` | Alto |
| `controlcamara.py` en raíz | comandos, planes ArUco/ESP32, handoff | Alto |
| `RAG/indexador.py` | mensajes de ayuda y documentación | Medio |
| `backend/vehicleControl.js` | servidor Node y documentación | Alto |
| `frontend/src/services/vehicleApi.js` | frontend -> backend | Alto |
| `esp32_camera_udp/platformio.ini` | PlatformIO | Medio |
| rutas `/opt/data/skills/...` | Hermes y handoff | Crítico |

### 4.3 Contratos que no son parte de la reorganización

Salvo solicitud funcional separada, una migración de carpetas no cambia:

- Puertos 9999, 8642, 5002, 5003, 5001 ni puertos UDP de cámara.
- Endpoints HTTP, esquemas JSON o protocolo de líneas TCP.
- Valores de dirección, throttle, watchdog o seguridad del vehículo.
- Nombres de variables de entorno.
- Formato de paquetes UDP de la ESP32.
- Modelo RAG, prompts, personalidad o memoria de Hermes.
- Versiones de dependencias.

Si resulta imprescindible modificar uno de estos contratos, debe hacerse como
un cambio funcional independiente, no oculto dentro de la reorganización.

## 5. Estructura objetivo canónica

```text
Deepracer-STEAM-Agent/
├── README.md
├── AGENTS.md
├── ORGANIZACION_PROYECTO.md
├── .gitignore
├── .env.example
├── docker-compose.yml
├── docker-compose.template.yml
├── Dockerfile.hermes
├── start-deepracer.ps1        # lanzador compatible y visible
├── stop-deepracer.ps1         # lanzador compatible y visible
├── scripts/
│   ├── README.md
│   ├── start/                  # implementación interna de arranque
│   ├── stop/                   # implementación interna de parada
│   ├── diagnostics/            # verificaciones sin activar hardware
│   └── maintenance/            # tareas explícitas de mantenimiento
├── apps/
│   ├── README.md
│   ├── backend/
│   │   ├── README.md
│   │   ├── package.json
│   │   ├── src/
│   │   ├── scripts/
│   │   └── tests/
│   ├── frontend/
│   │   ├── README.md
│   │   ├── package.json
│   │   ├── public/
│   │   ├── src/
│   │   └── tests/
│   ├── navigation/
│   │   ├── README.md
│   │   ├── requirements.txt
│   │   ├── src/
│   │   ├── tests/
│   │   └── config/
│   ├── rag/
│   │   ├── README.md
│   │   ├── requirements.txt
│   │   ├── src/
│   │   ├── knowledge/          # manuales que son fuentes del índice
│   │   └── tests/
│   ├── speech-to-text/
│   │   ├── README.md
│   │   ├── requirements.txt
│   │   ├── src/
│   │   └── tests/
│   └── text-to-speech/
│       ├── README.md
│       ├── requirements.txt
│       ├── src/
│       └── tests/
├── firmware/
│   ├── README.md
│   └── esp32-camera-udp/
│       ├── README.md
│       ├── platformio.ini
│       ├── src/
│       └── test/
├── hermes/
│   ├── README.md
│   ├── config.template.yaml
│   ├── SOUL.md
│   ├── skills/
│   ├── scripts/
│   └── ...                    # estado persistente ignorado
├── models/
│   ├── README.md
│   └── vision/
├── tools/
│   ├── README.md
│   └── arduino/
├── docs/
│   ├── README.md
│   ├── architecture/
│   ├── operations/
│   ├── development/
│   ├── plans/
│   └── archive/
└── archive/
    ├── README.md
    └── hermes-legacy/
```

### 5.1 Convenciones de nombres

- Carpetas nuevas: minúsculas y `kebab-case`.
- Código Python: `snake_case.py`.
- JavaScript/React: respetar la convención local; componentes en `PascalCase`.
- Documentos: nombres descriptivos en `kebab-case.md`, salvo nombres estándar
  (`README.md`, `AGENTS.md`, `HANDOFF.md`).
- No usar nombres genéricos como `nuevo`, `final`, `copia`, `test2` o `backup2`.
- Los experimentos deben indicar propósito y fecha o vivir en un directorio de
  pruebas, no junto al punto de entrada.

## 6. Mapa de migración

| Origen | Destino | Actualizaciones obligatorias |
|---|---|---|
| `backend/` | `apps/backend/` | PowerShell, docs, imports, comandos npm. |
| `frontend/` | `apps/frontend/` | Docs, comandos npm y referencias al script `move.js`. |
| `controlcamara.py` | `apps/navigation/src/controlcamara.py` | Lanzador compatible, docs, rutas de modelos/config. |
| `requirements-controlcamara.txt` | `apps/navigation/requirements.txt` | Guías de instalación. |
| `RAG/agente.py` | `apps/rag/src/agente.py` | Imports y mensajes de ayuda. |
| `RAG/indexador.py` | `apps/rag/src/indexador.py` | Resolución de `knowledge/` relativa al archivo. |
| `RAG/Manual_*.md` | `apps/rag/knowledge/` | Patrón del indexador y docs. |
| `SpeechToText/server.py` | `apps/speech-to-text/src/server.py` | Lanzadores y dependencias reproducibles. |
| `TextToSpeech/server.py` | `apps/text-to-speech/src/server.py` | Lanzadores y dependencias reproducibles. |
| `esp32_camera_udp/` | `firmware/esp32-camera-udp/` | Docs y comandos PlatformIO. |
| `bin/arduino-cli` | `tools/arduino/arduino-cli` | Scripts que lo invoquen y metadatos del binario. |
| `backup/` | `archive/hermes-legacy/` | Índices; ninguna referencia operativa debe apuntar aquí. |
| `Documentacion.md` | `docs/development/migracion-hermes-v018.md` | Enlaces e índice documental. |
| `HANDOFF.md` | `docs/operations/HANDOFF.md` | Skills y enlaces; primero retirar secretos. |
| `inventario_deepracer.md` | `docs/architecture/inventario-deepracer.md` | Enlaces desde skills y resúmenes. |
| `ESP32_CAMERA_UDP.md` | `docs/architecture/protocolo-camara-esp32-udp.md` | Firmware, navegación e índices. |
| `PENDIENTE_ESP32_CAMERA.md` | `docs/plans/camara-esp32-pendiente.md` | Índices y enlaces relativos. |
| `PROXIMA_ACTIVIDAD_ARUCO.md` | `docs/plans/actividad-aruco.md` | Comandos de navegación. |
| `RESUMEN_FINAL_ARUCO.md` | `docs/architecture/navegacion-aruco.md` | Índices y rutas de código. |
| `docs/SpeedRacerv.2/` | `docs/archive/SpeedRacerv.2/` | Marcar explícitamente como histórico. |

## 7. Zonas protegidas y exclusiones

### 7.1 Nunca tratar como fuente

- `node_modules/`, `.venv/`, `venv/`, `__pycache__/`, `.pio/`.
- Cachés, logs, sesiones, audio e imágenes generadas.
- `*.pid`, `*.lock`, `*-wal`, `*-shm`.
- Directorios internos descargados bajo `hermes/home/`, `.platformio`, Arduino u
  otros gestores de herramientas.

### 7.2 Datos persistentes de Hermes

Antes de tocar `hermes/`:

1. Confirmar que el contenedor está detenido si habrá movimientos internos.
2. Identificar fuente mantenible frente a estado generado usando
   `hermes/README.md`.
3. Crear un respaldo verificable fuera del árbol que se va a modificar.
4. No imprimir ni copiar el contenido de secretos a logs o documentación.
5. Preservar el montaje `./hermes:/opt/data` durante esta migración. Dividir ese
   volumen requiere un proyecto posterior específico.

### 7.3 Secretos

No incluir valores reales en commits, ejemplos, resultados de herramientas ni
mensajes finales. Buscar nombres y patrones de credenciales sin mostrar sus
valores. Si un documento histórico contiene secretos, crear primero una copia
saneada y solicitar rotación; no propagar el secreto a la nueva ubicación.

## 8. Modelo de ejecución: unidades atómicas

Cada unidad debe seguir este ciclo:

### Paso A — Preparación

1. Registrar rama, commit y `git status --short`.
2. Listar los archivos exactos de la unidad.
3. Identificar archivos modificados por el usuario que se solapen.
4. Clasificar el riesgo: documentación, código aislado, servicio o persistencia.
5. Guardar un listado de referencias a rutas antiguas.
6. Definir comandos de validación antes de editar.

### Paso B — Línea base

Ejecutar solo verificaciones seguras y reproducibles:

- `docker compose config` para validar Compose sin arrancar servicios.
- `node --check` para archivos Node modificados.
- Compilación del frontend si sus dependencias están disponibles.
- `python -m py_compile` para módulos Python modificados.
- Lectura de manifiestos y resolución de rutas.

No usar `start-deepracer.ps1` como prueba automática de línea base: actualmente
llama `/api/start`, lo que puede preparar físicamente el vehículo.

### Paso C — Movimiento

1. Crear solo los directorios canónicos necesarios.
2. Mover archivos fuente; no copiar dependencias o generados.
3. Mantener temporalmente un lanzador de compatibilidad si usuarios o skills
   llaman la ruta anterior.
4. Corregir rutas usando resolución relativa al archivo, no al directorio desde
   donde casualmente se ejecutó el proceso.
5. No realizar refactors funcionales durante el movimiento.

### Paso D — Actualización de consumidores

Buscar y actualizar, como mínimo:

- Código e imports.
- `docker-compose*.yml`, Dockerfiles y volúmenes.
- PowerShell y scripts shell.
- `package.json`, configuración de Vite/PlatformIO y requirements.
- README, HANDOFF, guías, skills de Hermes y mensajes mostrados por CLI.
- CI, tests y reglas `.gitignore`, si existen.

Repetir la búsqueda de la ruta anterior. Las coincidencias restantes solo se
permiten en el registro histórico de migración y deben estar marcadas como
“ruta anterior”.

### Paso E — Validación por capas

Aplicar, en orden:

1. Formato y sintaxis.
2. Resolución de imports y rutas.
3. Build del componente.
4. Prueba del servicio aislado.
5. Integración local sin hardware.
6. Integración Docker.
7. Hardware, únicamente con autorización y medidas de seguridad.

### Paso F — Cierre

1. Actualizar índices y progreso.
2. Revisar el diff buscando cambios funcionales accidentales.
3. Confirmar que no aparecieron secretos ni generados.
4. Documentar qué se probó, qué no se pudo probar y por qué.
5. Crear un commit exclusivo para la unidad si el usuario autorizó commits.

## 9. Fases detalladas

### Fase 0 — Preflight y protección

Objetivo: conseguir una línea base confiable sin reorganizar.

Tareas:

- Inventariar archivos rastreados, no rastreados y generados.
- Corregir `.gitignore` para dependencias, entornos, logs, bases temporales y
  secretos sin ignorar plantillas públicas.
- Detectar archivos rastreados que deberían ser secretos o generados.
- Crear comandos de diagnóstico que no activen el vehículo.
- Documentar versiones de Node, Python, Docker, PlatformIO y firmware.
- Respaldar datos persistentes de Hermes antes de fases que los afecten.

Puerta de salida:

- El estado inicial está documentado.
- Se sabe qué cambios eran previos.
- `docker compose config` es válido.
- Ninguna prueba de preflight mueve el robot.

### Fase 1 — Gobernanza e índices

Objetivo: hacer navegable la estructura actual antes de moverla.

Tareas:

- Mantener `AGENTS.md`, este plan y el índice raíz.
- Asegurar README en cada componente mantenible.
- Etiquetar directorios históricos y generados.
- Añadir una plantilla de README de componente con propietario, entradas,
  salidas, dependencias, ejecución, pruebas y datos generados.

Puerta de salida:

- Todos los componentes son accesibles desde el README raíz.
- Una persona puede distinguir implementación activa de historia.
- Las reglas para agregar y retirar contenido están documentadas.

### Fase 2 — Documentación

Orden recomendado:

1. Crear subdirectorios e índices de `docs/`.
2. Mover arquitectura e inventarios.
3. Mover planes y tareas pendientes.
4. Sanear y mover operación/HANDOFF.
5. Mover migraciones técnicas.
6. Archivar `SpeedRacerv.2` al final.

Validaciones:

- Enlaces Markdown locales resuelven.
- Los comandos apuntan a rutas actuales o explican claramente que son
  históricos.
- No se duplican documentos activos con versiones contradictorias.
- Las skills de Hermes apuntan a la guía operativa vigente.

### Fase 3 — Firmware y herramientas

Orden:

1. `esp32_camera_udp` -> `firmware/esp32-camera-udp`.
2. `bin` -> `tools`, documentando binarios.
3. Eliminar del traslado `.pio` y logs de compilación.

Validaciones:

- `platformio.ini` conserva entorno, placa y flags.
- El firmware compila si las dependencias ya están disponibles.
- No cargar firmware automáticamente; upload requiere autorización y hardware
  identificado.
- Documentación del protocolo y pinout sigue enlazada.

### Fase 4 — Servicios de voz

Orden: TTS primero por ser menor; STT después.

Tareas:

- Crear `src/`, `tests/`, README y `requirements.txt` reproducible.
- Mover únicamente fuente y pruebas útiles.
- Regenerar entornos virtuales en la nueva ubicación.
- Configurar logs fuera del código o mediante una carpeta ignorada.

Validaciones:

- Importación y `py_compile` exitosos.
- El servidor puede iniciar y detenerse sin hardware.
- Puertos y esquema de petición/respuesta no cambian.

### Fase 5 — RAG

Tareas:

- Separar `src/` de `knowledge/`.
- Hacer que las rutas se resuelvan desde `Path(__file__)`, no desde el CWD.
- Mover manuales sin cambiar su contenido.
- Definir dónde vive el índice generado y excluirlo del control de versiones.
- Mantener un manifiesto de fuentes documentales.

Validaciones:

- El indexador descubre exactamente el mismo conjunto de manuales.
- La cantidad y nombres de fuentes antes/después coinciden.
- Una consulta de humo devuelve una fuente, sin exigir hardware.
- Mensajes de ayuda muestran rutas nuevas.

### Fase 6 — Frontend

Tareas:

- Mover el proyecto completo excepto `node_modules` y builds.
- Mantener `.env.example`; no mover `.env` a control de versiones.
- Decidir si `move.js` es prueba de hardware y ubicarlo bajo scripts con una
  advertencia explícita.
- Actualizar documentación y lanzadores.

Validaciones:

- Instalación reproducible desde `package-lock.json`.
- Lint y build pasan.
- La URL del backend se resuelve igual.
- La UI carga sin necesidad de mover el robot.

### Fase 7 — Backend

El backend se mueve después del frontend porque es un contrato central con el
vehículo y lo arranca el script principal.

Tareas:

- Mover a `apps/backend` preservando `package-lock.json`.
- Actualizar `$PSScriptRoot\backend` en el lanzador.
- Mantener endpoints, puertos y canal TCP sin cambios.
- Separar en una fase posterior —no durante el movimiento— cualquier refactor
  interno de `server.js` y `vehicleControl.js`.

Validaciones:

- `node --check` pasa.
- El proceso inicia y responde a un endpoint de salud que no active hardware.
- Si no existe un healthcheck seguro, añadirlo como cambio pequeño y probado
  antes de mover el backend.
- No llamar `/api/start`, `/api/manual_drive` ni comandos SSH de movimiento en
  pruebas automáticas.

### Fase 8 — Navegación

Se realiza al final de las aplicaciones porque concentra cámara, ArUco,
modelos, red, backend y control físico.

Tareas:

- Crear paquete `apps/navigation/src` y tests separados.
- Mover requirements y documentar versión de Python.
- Resolver rutas de modelos y configuración desde el módulo.
- Crear un lanzador compatible en la raíz durante al menos una fase.
- Separar modo de percepción/simulación de modo de conducción antes de usarlo
  como prueba automatizada.

Validaciones sin hardware:

- Compilación/importación.
- Pruebas de reensamblaje UDP con paquetes sintéticos.
- Detección ArUco con imágenes de fixtures.
- Cálculo de dirección, ruta BFS y SafetyGate con entradas simuladas.
- Confirmación de que importar el módulo no inicia cámara ni movimiento.

Validación con hardware, solo autorizada:

- Vehículo elevado o ruedas libres y parada de emergencia disponible.
- Primero video; luego percepción; luego comandos con throttle cero; finalmente
  movimiento limitado.
- Operador presente y endpoint de stop verificado antes de iniciar.

### Fase 9 — Compose, lanzadores y compatibilidad

Tareas:

- Mantener el montaje raíz `/workspace` para minimizar riesgo.
- Mantener `./hermes:/opt/data` sin cambios.
- Actualizar rutas internas de componentes movidos.
- Conservar lanzadores de raíz que deleguen a `scripts/`.
- Separar “iniciar servicios” de “preparar/mover vehículo”: el arranque del
  software no debe implicar movimiento físico.

Validaciones:

- `docker compose config`.
- Build de Hermes.
- Dashboard responde y autenticación funciona.
- Backend inicia sin activar el vehículo.
- Stop termina procesos iniciados por el proyecto sin matar procesos Node no
  relacionados.

### Fase 10 — Archivo y limpieza

Tareas:

- Mover `backup/` a `archive/hermes-legacy`.
- Archivar documentación histórica.
- Retirar duplicados solo después de comparar contenido y referencias.
- Eliminar generados únicamente si son reproducibles y el usuario lo autoriza.

Puerta final:

- Búsqueda global sin referencias operativas a rutas antiguas.
- Árbol navegable y documentado.
- Build y pruebas de todos los componentes disponibles.
- Smoke test integrado sin hardware.
- Prueba de hardware documentada o marcada explícitamente como pendiente.

## 10. Matriz mínima de validación

| Componente | Estática | Build | Servicio seguro | Hardware |
|---|---|---|---|---|
| Compose/Hermes | `docker compose config` | `docker compose build hermes` | dashboard/login | No aplica |
| Backend | `node --check` | instalación npm | health/status sin start | Autorización |
| Frontend | lint | build Vite | carga UI | No necesario |
| Navegación | `py_compile` + tests | instalación Python | simulación/fixtures | Autorización |
| RAG | `py_compile` | indexado temporal | consulta de humo | No aplica |
| STT | `py_compile` | instalación Python | endpoint con fixture | Micrófono opcional |
| TTS | `py_compile` | instalación Python | generar audio temporal | Altavoz opcional |
| ESP32 | revisión config | PlatformIO build | No aplica | Upload autorizado |
| Documentación | enlaces y búsquedas | No aplica | navegación manual | No aplica |

## 11. Rollback y recuperación

Antes de cada unidad, registrar origen, destino y archivos consumidores. Si
falla una puerta:

1. No continuar a la siguiente unidad.
2. Guardar salida de la prueba sin secretos.
3. Revertir solo archivos creados o movidos por la unidad actual.
4. No usar `git reset --hard`, `git clean` ni operaciones que destruyan cambios
   del usuario.
5. Restaurar rutas antiguas o el lanzador de compatibilidad.
6. Repetir la línea base para confirmar recuperación.
7. Documentar el bloqueo y la condición necesaria para reintentar.

Las bases de datos y datos persistentes se recuperan desde el respaldo previo,
no desde una suposición sobre Git.

## 12. Reglas para añadir contenido en el futuro

### Añadir un componente

Debe incluir:

- Carpeta bajo `apps/`, `firmware/` o la categoría adecuada.
- `README.md` con propósito, arquitectura, entradas/salidas, ejecución, pruebas,
  configuración, datos generados y riesgos de hardware.
- Manifiesto de dependencias y lockfile cuando aplique.
- `.env.example` si necesita configuración; nunca `.env` real.
- Tests o, como mínimo, un smoke test seguro.
- Enlace desde el índice de su carpeta padre.

### Añadir un archivo

Antes de crearlo, preguntar:

1. ¿A qué responsabilidad pertenece?
2. ¿Es fuente, configuración, documentación, generado, persistente o secreto?
3. ¿Ya existe un archivo que cumple esa función?
4. ¿Quién lo consume y cómo se prueba?
5. ¿Debe enlazarse desde un README?

### Mover o renombrar

- Buscar consumidores antes y después.
- Actualizar rutas y documentación en el mismo cambio.
- Mantener compatibilidad temporal para puntos de entrada públicos.
- No combinar el movimiento con cambios funcionales.

### Retirar contenido

- Demostrar que no tiene consumidores activos.
- Distinguir eliminación de archivo reproducible frente a pérdida de datos.
- Archivar documentos con valor histórico.
- Actualizar índices, manifiestos y pruebas.
- Indicar cómo recuperar o regenerar lo retirado.

## 13. Plantilla obligatoria para README de componente

```markdown
# Nombre del componente

Resumen de una frase.

## Responsabilidad
Qué hace y qué explícitamente no hace.

## Entradas y salidas
APIs, puertos, archivos, eventos o hardware.

## Estructura
Tabla de carpetas y puntos de entrada.

## Dependencias
Runtime, manifiesto, servicios y hardware.

## Configuración
Variables y plantillas, nunca secretos reales.

## Ejecución
Comandos desde la raíz del repositorio.

## Pruebas
Comandos seguros y pruebas que requieren autorización.

## Datos generados
Qué se puede regenerar y qué debe respaldarse.

## Mantenimiento
Cómo añadir, mover o retirar funcionalidades.
```

## 14. Registro de decisiones estructurales

Toda modificación futura a esta arquitectura debe añadir una entrada breve:

| Fecha | Decisión | Motivo | Rutas afectadas | Compatibilidad |
|---|---|---|---|---|
| 2026-07-31 | Adoptar organización por componentes y migración por fases. | Separar fuente, estado, documentación e históricos. | Todo el repositorio. | Ejecutado (fases 0-10); validaciones Docker/PS pendientes en el host. |
| 2026-07-31 | Cambio funcional: calibración de zona muerta del throttle (THROTTLE_DEAD_ZONE=0.5) en el backend; consumidores envían valores normalizados [-1,1]. | El robot no mueve motores con |throttle| < 0.5 (verificado en vivo); se estira (0,1] a [0.5,1] preservando 0=parada y el signo. | apps/backend/vehicleControl.js, controlcamara.py, scripts del skill (daemon/explorer), .env(.example), GUIA_SETUP, HANDOFF, API.md. | Cambio deliberado e independiente de la migración; autorizado por el usuario; pendiente verificación física con backend reiniciado. |
| 2026-07-31 | Cambio funcional: trim de dirección (STRAIGHT_ANGLE_OFFSET) + endpoints de calibración en vivo (GET/POST /api/calibration). | Con angle=0 el robot deriva ~4.4° a la derecha por 1.9 m; el servo es muy sensible (-0.11 → giro de 90° en 2 s), se itera desde -0.002/-0.003. | apps/backend/vehicleControl.js, apps/backend/server.js, .env(.example), API.md, skill deepracer-control. | Ajuste en vivo sin reinicios; mediciones de velocidad real: -0.55→0.87 m/s, -0.65→0.83 m/s. |

Si una decisión cambia la estructura objetivo, debe actualizar en el mismo
cambio el árbol canónico, mapa de migración, reglas de mantenimiento y README
raíz. No se añaden excepciones silenciosas.

## 15. Registro de progreso de ejecución

| Fase | Estado | Evidencia | Pendientes |
|---|---|---|---|
| 0 — Preflight | ✅ Completada | Inventario y baseline documentados; `.gitignore` corregido (node_modules, venv, faiss_index, archive); fuera de tracking: `RAG/__pycache__/*.pyc` y `SpeechToText/realtimesst.log`; `py_compile`, `node --check` y YAML de compose válidos. | `docker compose config` real pendiente (plugin no disponible en la sesión). |
| 1 — Gobernanza | ✅ Completada | READMEs por componente existentes; plantilla creada en `docs/development/plantilla-README-componente.md`; reglas en `AGENTS.md`. | — |
| 2 — Documentación | ✅ Completada | `docs/{architecture,operations,development,plans,archive}` con índices; 11 documentos movidos (GUIA_SETUP, HANDOFF, migración v0.18, protocolo ESP32, planes, inventario, SpeedRacerv.2 completo); 0 enlaces locales rotos. | — |
| 3 — Firmware/herramientas | ✅ Completada | `firmware/esp32-camera-udp/` con `platformio.ini` intacto; `tools/arduino/arduino-cli` v1.5.1 con SHA-256 documentado. | Compilación PlatformIO no ejecutada (toolchain no disponible); upload requiere autorización. |
| 4 — Voz | ✅ Completada | `apps/speech-to-text/` y `apps/text-to-speech/` con `src/`, `tests/`, `requirements.txt`; 3 tests de humo pasando. | Prueba con micrófono/altavoz real opcional. |
| 5 — RAG | ✅ Completada | `apps/rag/{src,knowledge,tests}`; rutas resueltas desde `Path(__file__)`; índice generado en `faiss_index/` ignorado; 2 tests pasando (mismo conjunto de 20 fuentes). | Reindexar con langchain en el entorno destino. |
| 6 — Frontend | ✅ Completada | `apps/frontend/`; `envDir` y rutas `.env` corregidas; `move.js` movido a `scripts/` con advertencia de hardware; `npm ci` + `vite build` OK. | Lint: 18 errores preexistentes en archivos modificados por el usuario (no tocados). |
| 7 — Backend | ✅ Completada | `apps/backend/`; healthcheck seguro `GET /api/health` probado antes y después del movimiento; `npm ci` OK; `node --check` OK; **validado en el host Windows 2026-07-31** (`BACKEND_PID=19276`, `HEALTH_OK`). | — |
| 8 — Navegación | ✅ Completada | `apps/navigation/src/controlcamara.py` + lanzador compatible en raíz; `models/vision/yolov5n.onnx`; 18 tests sin hardware pasando (BFS, UDP, SafetyGate). | Pruebas físicas solo con autorización explícita. |
| 9 — Integración | ✅ Completada | `scripts/{start,stop,diagnostics,maintenance}`; arranque sin activar vehículo (healthcheck); stop solo mata el PID del proyecto; lanzadores de raíz delegan; `start-backend-only.ps1` validado en el host (healthcheck OK); README raíz y `apps/README.md` actualizados; montajes intactos. | `docker compose build hermes` y `start-services.ps1` completos pendientes de ejecutar en el host (opcional). |
| 10 — Archivo/limpieza | ✅ Completada | `archive/hermes-legacy/` (antes `backup/`, ignorado por Git); `archive/README.md`; skills de Hermes actualizadas; barrido global sin referencias operativas a rutas antiguas; **carpetas residuales `backend/` y `.stuck/` eliminadas desde Windows 2026-07-31**. | — |

## 16. Definición de terminado

La reorganización completa termina únicamente cuando:

- Cada componente tiene destino canónico, README y manifiesto reproducible.
- La raíz contiene solo orientación, configuración transversal y lanzadores.
- No hay secretos ni dependencias generadas rastreadas.
- Hermes conserva memoria/configuración y sigue montado correctamente.
- Las rutas antiguas no tienen consumidores operativos.
- Los enlaces Markdown locales resuelven.
- Los builds y pruebas seguras pasan.
- Iniciar el software no mueve el vehículo.
- Las pruebas físicas se realizaron de forma controlada o quedaron pendientes
  explícitamente, sin afirmar validación inexistente.
- El registro de decisiones y progreso refleja el estado real.
