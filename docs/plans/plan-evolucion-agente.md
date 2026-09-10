# Plan de evolución — DeepRacer STEAM Agent (mascota del aula)

> **Audiencia:** el agente Hermes del DeepRacer (SpeedRacer) y las personas que
> mantengan este repositorio.
>
> **Fecha de creación:** 2026-09-05 (actualizado: gobernanza + upgrade Hermes)
> **Estado:** pendiente de ejecución
> (el robot no está disponible; el PC con el entorno real está en la U).
>
> **2026-09-05 — historial normalizado:** 19 commits reescritos con
> Conventional Commits (type+scope+imperativo). El repo ahora tiene
> protección de rama (ver Fase 8) y una skill de commits propia.
>
> **Regla principal:** ninguna mejora justifica romper una ruta, perder datos,
> divulgar secretos o **activar el vehículo sin autorización**. Todo cambio de
> comportamiento físico se prueba primero contra el simulador.

---

## 1. Por qué existe este plan

Este repositorio es el cerebro de una **mascota robótica del aula STEAM**:
un AWS DeepRacer que debe saludar, responder preguntas sobre los equipos del
aula (RAG), guiar con la cámara (marcadores ArUco) y moverse con seguridad
entre estaciones. El proyecto se hizo "a lo loco" en iteraciones anteriores;
este plan ordena la evolución del AGENTE (no del hardware): identidad,
memoria, RAG, visión y mantenimiento.

El agente NO es un asistente general: es un **manejador de RAG + compañero
físico del aula**. Su memoria debe ser ligera y curada, no un archivo infinito.

---

## 2. Estado actual (2026-09-05) — ya hecho, no repetir

| Área | Estado |
|---|---|
| **Seguridad del repo** | ✅ Historial git purgado (3 secretos reales removidos con filter-repo, verificado con gitleaks = 0 leaks). CI `secret-scan.yml` (gitleaks + trufflehog) activo. |
| **CI** | ✅ `ci.yml`: node --check, pytest (Python 3.13 — numpy 2.5.1 lo exige), build+lint del frontend. |
| **Simulador** | ✅ `apps/simulator/` — mock fiel de la API web del DeepRacer (login CSRF, watchdog 200ms, dead zone, servo sensible, MJPEG). 19 tests de contrato. **Puede correr SIN el robot y SIN opencv.** |
| **Docs** | `docs/archive/SpeedRacerv.2/` (iteración anterior) se **conserva tal cual** — decisión explícita de Carlos. No mover, no borrar. |
| **ESP32** | ❌ **Descartado como sensor por Carlos** (2026-09-05): el sensor de sonido solo detectaba choques y no aportaba. ⚠️ **Reavivado solo como teleoperación BLE** (2026-09-08, `docs/plans/bt-teleop.md`, PR #14): no volver a invertir en él como sensor del agente. |
| **Pendientes de seguridad** | Rotar password API web del robot y regenerar device token cuando haya acceso (ver `CREDENTIAL_ROTATION.md`). Los valores viejos están en BWS como `DEEPRACER_LEGACY_*`. |
| **Commits** | ✅ Historial normalizado a Conventional Commits (19 commits, type+scope+imperativo). Skill propia: `hermes/skills/github/conventional-commits-deepracer/`. |
| **Gobernanza** | ✅ Protección de rama `main` (PRs obligatorios + CI verde + sin push directo). Ver Fase 8. |
| **Actualizar Hermes** | ⏳ El agente corre v0.18 (los docs mencionan `config_version: 33`); planificar upgrade a la última versión estable (Fase 1.5). |

---

## 3. Visión del agente (identidad objetivo)

SpeedRacer debe ser:

- **Mascota del aula**: curiosa, amable, habla español, ayuda a estudiantes
  y profesores. Tiene cuerpo físico: un robot que se mueve despacio y con
  permiso.
- **Experto del aula**: responde sobre impresoras 3D, soldadura, Wacom,
  Lenovo, curado, etc. usando el RAG (`apps/rag/knowledge/`).
- **Guía visual**: navega hasta estaciones usando marcadores ArUco con la
  cámara monocular (es el único sensor de percepción real; NO hay IMU, NO
  hay LiDAR físico).
- **Seguro por diseño**: nunca se mueve sin autorización explícita y
  operador presente; el control físico va SIEMPRE por el backend Node
  (`apps/backend`, puerto 5002), nunca por SSH para movimiento.

---

## 4. Fases de ejecución

### Fase 0 — Verificar el simulador (obligatoria antes de tocar el robot)

Cuando el agente vuelva a tener un entorno con este repo, lo primero es
demostrar que el mock funciona. Criterios de aceptación:

```bash
# 1. Tests de contrato (levantan el mock solos)
python -m pytest apps/simulator/tests -q          # → 19 passed

# 2. Levantar el mock manualmente
python apps/simulator/deepracer_mock.py           # HTTPS :5001 + HTTP :8080
```

- [ ] `pytest apps/simulator/tests` → 19 passed
- [ ] `GET https://127.0.0.1:5001/login` → 200 con `csrf_token`
- [ ] Login con password del `.env` → cookie de sesión
- [ ] Secuencia completa vía **backend real** (Node): con
      `DEEPRACER_HOST=127.0.0.1` en el `.env`, `POST /api/start`,
      `POST /api/manual_drive {angle:0, throttle:-0.3, max_speed:0.5}`,
      `POST /api/stop` → todo 200
- [ ] `GET /api/video_stream` → multipart MJPEG con frames
- [ ] **Watchdog**: enviar un comando suelto y verificar que los motores
      simulados vuelven a OFF ~200ms después (`/mock/state` → `motors_on:false`)
- [ ] Dashboard `https://127.0.0.1:5001/home` con login → control → robotcito
      se mueve con "Enviar en loop"

> Si algo falla acá, se arregla el mock o el stack ANTES de acercarse al
> robot. El simulador es la red de seguridad para perderle el miedo a la API.

### Fase 1 — Entorno real (cuando haya acceso al robot y al PC de la U)

- [ ] Resincronizar el repo en el PC de la U (el historial cambió):
      `git fetch origin && git reset --hard origin/main` (o re-clonar)
- [ ] Copiar `.env.example` → `.env` con los valores reales y **rotar**:
      password API web (reset con `reset_default_password.py` en el robot)
      y device token (ver `CREDENTIAL_ROTATION.md`)
- [ ] Verificar conectividad: SSH (diagnóstico/mantenimiento SOLO), API web
      `:5001`, cámara `:8080`, backend local `:5002`
- [ ] Correr la Fase 0 completamente contra el robot real (sin comandos de
      movimiento al inicio: login, health, cámara)
- [ ] Prueba de dirección controlada (throttle ±0.3, 1s, zona despejada,
      operador presente) → registrar convención actual del boot en la memoria

### Fase 1.5 — Actualizar Hermes del agente a la última versión estable

El agente del DeepRacer corre Hermes v0.18 (los docs del repo mencionan
`hermes-v18-bugs.md` y `config_version: 33`). Hermes avanza rápido; conviene
actualizar ANTES de seguir con SOUL/memoria para no construir sobre una base
vieja.

- [ ] Verificar la versión actual: `hermes --version` dentro del entorno real
- [ ] Leer la documentación de migración de Hermes (https://hermes-agent.nousresearch.com/docs)
      para el salto v0.18 → última estable (probablemente v0.20+)
- [ ] **Backup completo antes de actualizar**: `hermes/` (config, skills,
      memories, state), el `.env`, y las claves — nada se pierde
- [ ] Subir versión de la imagen en `Dockerfile.hermes` / `docker-compose.template.yml`
- [ ] Probar el upgrade contra el **simulador primero** (Fase 0): login,
      dashboard, control — antes de tocar el robot
- [ ] Documentar cambios de config necesarios (vars renombradas, plugins,
      `config_version`) en `docs/development/`
- [ ] Verificar que la skill `deepracer-control` y las nuevas skills
      sobreviven al upgrade (formato SKILL.md estable, pero confirmar)

> Si el upgrade rompe algo, el bundle de respaldo permite volver atrás.
> No actualizar el robot real hasta que el stack completo pase la Fase 0.

### Fase 2 — Actualizar el SOUL del agente (`hermes/soul/soul.md`)

El SOUL actual (32 líneas) es funcional pero está desactualizado y es plano.
Actualizarlo para que refleje la visión de la sección 3:

- [ ] **Identidad**: mascota del aula STEAM, habla español, rol de guía y
      experto RAG. Curiosa y amable, con límites claros.
- [ ] **Reglas de seguridad física** (obligatorias):
      - Nunca moverse sin autorización explícita y operador presente
      - Zona despejada + velocidad limitada (autónomo ≤ 0.20 normalizado)
      - Batería baja → avisar y no moverse
- [ ] **Canal de control**: todo movimiento por el backend Node
      (`apps/backend` :5002), **nunca SSH** para movimiento (SSH = solo
      diagnóstico/mantenimiento)
- [ ] **Conocimiento**: usar el RAG del aula (`apps/rag`) para responder;
      nombrar la fuente cuando sea posible
- [ ] **Cuerpo**: cámara monocular única percepción; batería LiPo monitoreada;
      LED trasero de estado; sin IMU/LiDAR

### Fase 3 — Memoria del agente (Mnemosyne, ligera y curada)

El agente usa hoy `hermes/memories/MEMORY.md` (texto plano con secciones
separadas por `§`) — sin recall semántico y con **contradicciones conocidas**:
dice "HTTP" donde el cliente real usa HTTPS; dice "+0.7 = adelante" donde la
medición en vivo (2026-07-31) dice "negativo = adelante".

El propósito del agente (RAG + mascota) no necesita una memoria enorme, pero
sí necesita hechos durables correctos:

- [ ] Migrar los hechos durables actuales de `MEMORY.md` a **Mnemosyne**
      (scope `global`): IPs, puertos, convención de signo, dead zone, trim,
      watchdogs, credenciales referenciadas por env (no valores)
- [ ] **Invalidar** los hechos viejos contradictorios (no borrarlos: historial)
- [ ] Reglas de memoria: guardar calibraciones verificadas, datos del robot,
      preferencias de Carlos y lecciones; NO guardar conversaciones efímeras
      ni estados de ánimo
- [ ] Revisar y actualizar `hermes/memories/` como respaldo curado visible
      (los txt planos pasan a ser snapshot, no fuente de verdad)

### Fase 4 — RAG del aula

Ya existe: `apps/rag/` con `knowledge/` (manuales: impresoras 3D, soldadura,
Wacom, Lenovo, curado...), `src/indexador.py` (FAISS + sentence-transformers)
y `src/agente.py` (respuestas vía Ollama).

- [ ] Verificar que el índice se construye y las consultas responden con
      fuentes: `python apps/rag/src/indexador.py` → `agente.py --pregunta "..."`
- [ ] Decidir un lugar estable para nuevos manuales del aula y documentarlo
      en `apps/rag/README.md`
- [ ] Integrar las respuestas del RAG con el agente conversacional (que
      SpeedRacer cite el manual que usó)
- [ ] Asegurar que los manuales no contengan datos personales/secretos
      (revisión previa al commit, ver `SECURITY.md`)

### Fase 5 — Cámara y sensores (lo que realmente hay)

Hardware verificado: cámara monocular MJPEG (`web_video_server` :8080),
batería LiPo (I2C `0x5E`), servo/motor (I2C `0x44`), LED trasero. **NO hay**
IMU, Ni LiDAR, Ni ESP32 como sensor (descartado 2026-09-05). El ESP32 sí
existe **solo como teleoperación BLE** (`docs/plans/bt-teleop.md`), no como
sensor del agente.

- [ ] Navegación ArUco: validar `apps/navigation/src/controlcamara.py` contra
      el stream real (marcadores impresos, focal length calibrada)
- [ ] Detección de obstáculos simple (ROI central, umbrales de
      brillo/desaturado/bordes ya documentados en la skill)
- [ ] Monitoreo de batería: alertar antes de quedarse sin carga
- [ ] (Opcional, futuro) Voz: STT/TTS local sin depender de la nube

### Fase 6 — Separar la skill monolítica (patrón Thalor)

`hermes/skills/robotics/deepracer-control/SKILL.md` tiene **1716 líneas** con
todo mezclado. El repositorio del agente debe separarla por responsabilidad
(siguiendo el patrón de `examples/robot-assistant` del repo **Thalor**:
skills `motor-control`, `sensor-reader`, `live-calibration`):

- [x] `deepracer-motor-control`: secuencia drive_mode → start_stop →
      manual_drive, watchdog, daemon, safety, explorer, LEDs, backend proxy
      (rama `feature/skill-split`, PR pendiente de revisión)
- [x] `deepracer-calibration`: trim del servo, dead zone, mediciones en vivo,
      speeds 2026-07-31, direction test + `#1 Pitfall` completo
- [x] `deepracer-vision`: MJPEG, ArUco (`actividad-aruco.md`), detección de
      obstáculos (gray-floor fix), LiDAR (sin hardware), verificación cámara
- [x] `deepracer-troubleshooting`: SSH/firewall/Tailscale, dashboards, ROS2
      topics, auditoría hardware, checklist post-reboot, issues; ESP32 como
      apéndice legacy etiquetado (descartado como sensor 2026-09-05, no
      invertir; teleop BLE reavivado aparte: `docs/plans/bt-teleop.md`)
- [x] Conservar el conocimiento verificado intacto (las mediciones de
      2026-07-31 son oro; mover, no reescribir) — verificado por auditoría
      automatizada: 0 líneas de contenido perdidas (solo headers renombrados,
      rutas `../deepracer-control/` y punteros entre skills)
- `deepracer-control/SKILL.md` queda como router (v3.0.0) a las 4 skills;
  `references/`, `scripts/`, `templates/` siguen en su lugar para no romper
  `skill_view()` existentes (HANDOFF). Dead zone vive en calibration (motor
  la referencia, no duplica).

### Fase 8 — Gobernanza del repo (varias personas operan este proyecto)

El proyecto lo maneja más de una persona (semestre a semestre cambia quién
opera el robot). Para que nadie "mande todo al carajo" con un push:

- [ ] **Protección de rama `main` en GitHub** (Settings → Branches):
      - Require pull request reviews (mínimo 1)
      - Require status checks (los workflows `ci` y `secret-scan` existentes)
      - Require branches up to date
      - **Bloquear push directo a `main`** — todo entra por PR
- [ ] Actualizar `AGENTS.md` con: Conventional Commits obligatorio +
      PR obligatorio + nunca force-push a main
- [ ] Hooks locales: `scripts/install-hooks.sh` (gitleaks pre-commit) en
      cualquier clon que trabaje el robot
- [ ] Definir quién puede mergear (los mantenedores del semestre) y
      documentarlo en `AGENTS.md`
- [ ] Si alguien externo necesitó acceso, otorgar **solo** vía GitHub
      collabs con permiso de escritura, nunca claves del repo de Carlos
- [ ] Auditoría periódica: quién pusheó qué (git log + GitHub activity)

> La protección de rama es el candado principal: un push directo a `main`
> queda rechazado por GitHub aunque el que lo intente tenga permisos de
> escritura. El CI verde es el segundo candado: nada rompe `main` sin que
> los tests pasen.

### Fase 9 — Versión usable para no-programadores (el que muestra el robot no es programador)

Problema: hoy manejar el robot exige pedirle a una IA o a Carlos. Quienes
muestran el robot en el aula (mecatrónica, electrónica) necesitan abrir algo
y manejar, sin terminal, sin agentes y sin llamar a nadie.

Opciones (research pendiente, ver prompt entregado a Carlos 2026-09-10):
A. **PWA instalable** del frontend actual (costo ~0, se instala desde el
   navegador del PC del aula, funciona offline contra el backend local).
B. **Ejecutable Tauri** (liviano, ~10MB) o Electron (pesado, ~150MB):
   doble-clic y anda. Más trabajo de build/release.
C. **Frontend mejorado + lanzador**: atajo `.bat`/QR en el PC del aula que
   abre el dashboard ya apuntando al robot. Mínimo esfuerzo, UX media.
D. **Modo demo con simulador**: el mismo dashboard contra el mock, para
   mostrar sin robot (ferias, clases sin hardware).

Restricciones: $0, PCs Windows del aula, gates físicos intactos (autorización,
operador, zona despejada, throttle ≤0.20), sin pedirle nada a una IA.
Decisión y comparativa en el research; implementar la ganadora contra el
simulador primero (regla 3 de operación).

### Fase 10 — Skills de ingeniería para el agente del aula ✅ (2026-09-10)

El agente del aula no tiene las skills de programación del entorno de Carlos.
Portadas a `hermes/skills/dev/` (rama `fix/skills-dev`):

| Skill | Para qué en este repo |
|---|---|
| `design-taste-frontend` | Que el dashboard no salga "basura": entregables visuales con estándar real |
| `systematic-debugging` | Debug en 4 fases (entender antes de arreglar), anti-parches a ciegas |
| `test-driven-development` | RED-GREEN-REFACTOR para lógica de control y contratos del simulador |
| `requesting-code-review` | Auto-revisión pre-commit (scan, quality gates) antes de pedir review |
| `plan` | Planes markdown de cambios no triviales antes de ejecutarlos |
| `excalidraw` | Mockups y diagramas a mano para docs visuales (Fase 9 + docs) |

La skill de commits ya existía (`conventional-commits-deepracer`), no se duplica.

### Fase 11 — Enjambre en Oracle (revisores 24/7, $0 Always Free)

El PR-Agent de GitHub Actions es single-shot sin herramientas. La evolución es
un harness persistente en la VM Always Free (patrón Thalor expert-panel):
workers por dominio con skills reales (las `dev/` de la Fase 10), MCP
(github, filesystem) y colas por labels. Candidatos: reviewer profundo
(segunda opinión tras el CI), doc-auditor (frescura de `docs/` vs realidad),
vigía del repo (secretos, branches stales, dependencias).
Pre-requisito: Fase "reviewer en verde" (PR #19 mergeado y probado en un PR
real). Sin costo: solo recursos Always Free, como el resto de la infra.

### Fase 12 — Documentación visual (no un reguero de .md)

Audiencia: estudiantes que NO programaron el robot. Principios:
- **Diátaxis**: tutoriales (paso a paso con fotos), guías (una tarea, una
  página), referencia (el .md técnico actual), explicación (el porqué).
- **Quickstart de 1 página** imprimible con QR al dashboard (Fase 9).
- Screenshots + GIFs de cada flujo (manejar, ver cámara, parar de emergencia);
  mockups Excalidraw versionados en el repo antes de codear UI.
- Prohibido documentar lo no verificado (regla heredada de Fase 7).
- Research de herramientas y comparativa encargado a IA de investigación
  (prompt en manos de Carlos 2026-09-10).

### Fase 7 — Higiene y mantenimiento continuo

- [ ] Limpiar `hermes/scripts/` de scripts de debug one-off
      (`debug_login*.py`, `debug_api*.py`, `explore_*`, `get_login*`) —
      archivar o borrar los obsoletos; los útiles se documentan en su skill
- [ ] Adoptar el patrón de **doc-auditor** de Thalor: mantener las guías
      (`docs/operations/GUIA_SETUP.md`, `HANDOFF.md`) frescas contra el estado
      real; nunca documentar lo que no se verificó
- [ ] Backup periódico del estado del agente (memoria, skills, config) — el
      repo ya versiona lo mantenible; decidir dónde vive el estado runtime
- [ ] Actualizar `AGENTS.md`/`ORGANIZACION_PROYECTO.md` solo si cambian
      rutas o reglas (seguir su propio proceso)

---

## 5. Reglas de operación obligatorias (para el agente y quien lo opere)

1. **Control físico SOLO por backend** (`apps/backend` :5002) — nunca SSH
   para mover el robot. SSH es diagnóstico/mantenimiento.
2. **Pruebas físicas**: autorización explícita, operador presente, zona
   despejada, velocidad limitada, parada verificada.
3. **El simulador primero**: cualquier cambio de lógica de control se valida
   contra `apps/simulator` antes del robot.
4. **Throttle autónomo ≤ 0.20 normalizado** (0.60 real) sin supervisión
   directa — el mínimo que mueve ya es paso de caminata (~0.9 m/s).
5. **Convención del throttle se verifica en cada boot** (puede cambiar entre
   reboots): ±0.3 durante 1s con operador, se registra la ganadora.
6. **Nunca** subir secretos, `.env`, `state.db` o datos personales al repo.
7. **`docs/archive/SpeedRacerv.2/` no se toca** (historia del proyecto).
8. Los commits siguen el estándar del repo (`chore:`, `feat:`, `fix:`, ...)
   con conventional commits y sin secretos (gitleaks está en CI).

---

## 6. Referencias

| Fuente | Para qué |
|---|---|
| `apps/simulator/README.md` | Cómo usar y verificar el mock (Fase 0) |
| `apps/backend/API.md` | Contrato del backend local (:5002) |
| `docs/operations/GUIA_SETUP.md` | Setup físico, SSH, calibración |
| `docs/operations/HANDOFF.md` | Acceso, movimiento, descubrimientos |
| `hermes/skills/.../deepracer-control/` | Conocimiento verificado del robot |
| `CREDENTIAL_ROTATION.md` | Qué rotar y cómo al recuperar acceso |
| `docs/plans/plan-seguridad-secretos.md` | Secretos del equipo con BWS (a ejecutar con acceso) |
| `docs/plans/plan-hardening-firewall.md` | Hardening de red/firewall del robot (a ejecutar con acceso) |
| `docs/plans/plan-voz.md` | Voz: STT/TTS heredados, HTTP, micrófono remoto, integración con el agente |
| Repo **Thalor** (`github.com/carlonox/Thalor`) | Patrones: `examples/robot-assistant`, doc-auditor, backup |
| `hermes/skills/github/conventional-commits-deepracer/` | Skill de commits obligatoria para este repo |
| `docs/plans/vision-nuevo-proyecto.md` | Visión original del proyecto 2026 |

---

## 7. Orden sugerido

```
Fase 0 (verificar mock) → Fase 1 (entorno real + rotar credenciales)
→ Fase 1.5 (upgrade Hermes) → Fase 2 (SOUL) → Fase 3 (memoria)
→ Fase 4 (RAG) → Fase 5 (cámara) → Fase 6 (skills) → Fase 7 (higiene)
→ **Fase 8 (gobernanza — activa YA si el repo aún no tiene protección)**
→ Fase 9 (versión usable) → Fase 10 (skills dev ✅) → Fase 11 (enjambre Oracle)
→ Fase 12 (docs visuales)
```

Cada fase termina con sus checks marcados y, si toca comportamiento físico,
una ejecución contra el simulador antes que contra el robot.