# Plan de voz — darle oídos y voz a la mascota

> **Fecha:** 2026-09-05
> **Estado:** heredado (prototipos sin integrar) → pendiente de ejecución
> **Audiencia:** mantenedores del repo / quien continúe el proyecto
> **Origen:** iteración previa (27-jul-2026, commit `939fd51` "feat(voice)"):
> otro integrante del equipo dejó prototipos de reconocimiento y síntesis.

---

## 1. Estado actual (lo que ya existe — no repetir)

| Módulo | Ruta | Qué hace | Limitación |
|---|---|---|---|
| **STT** | `apps/speech-to-text/` | Captura micrófono local 16 kHz, detecta silencio, transcribe con **Faster Whisper `large-v3` en CUDA** (float16) | Imprime en consola; **sin HTTP**; requiere GPU |
| **TTS** | `apps/text-to-speech/` | **edge-tts** voz `es-CO-SalomeNeural`, convierte a PCM 16 kHz mono 16-bit | Genera archivo de prueba; **sin HTTP**; edge-tts es **nube** (Microsoft), no offline |
| **Tests** | `apps/speech-to-text/tests/`, `apps/text-to-speech/tests/` | Smoke tests sin GPU ni micrófono | Solo estructura |

**El problema físico real:** el robot **no tiene micrófono ni parlantes**. En la
iteración anterior se probó usando un **celular** como micrófono y salida de
audio (por eso el prototipo lee del micrófono local de donde corre el script).
La visión original (`docs/plans/vision-nuevo-proyecto.md`) soñaba con
micrófono + parlante USB en el robot y Vosk + Piper 100% offline; lo que quedó
implementado fue faster-whisper local (STT) + edge-tts en la nube (TTS).

## 2. Principios

1. **La voz es una capa, no el cerebro**: el flujo es
   `audio → STT → texto → agente → texto → TTS → audio`. Nunca el STT/TTS
   toman decisiones; solo convierten.
2. **El agente (Hermes) es el dueño de la conversación**: los servicios de
   voz se exponen como HTTP para que la skill `deepracer-control` (o una
   skill nueva `voice-bridge`) los use.
3. **Funcionar SIN el robot**: el micrófono remoto (celular/PC) permite
   desarrollar y probar el flujo de voz completo sin tocar el vehículo.
4. **Privacidad**: no almacenar audio ni transcripciones de personas sin
   control; la recopilación 2026-1 ya lo marcaba como requisito.

## 3. Fases propuestas

### Fase V0 — Verificar lo heredado (sin robot)
- [ ] Correr los smoke tests existentes (`pytest apps/speech-to-text/tests apps/text-to-speech/tests`)
- [ ] Probar TTS en el entorno real: generar `audio_prueba.mp3` y escucharlo
- [ ] Probar STT solo si hay GPU disponible; si no, documentar qué hardware
      necesita (faster-whisper `large-v3` en CPU es lento pero viable con
      modelo más chico, p. ej. `small`/`medium` en español)

### Fase V1 — Exponer STT y TTS como servicios HTTP
- [ ] Convertir `src/server.py` de cada app en un servidor FastAPI sencillo:
  - `POST /api/stt` — recibe audio (WAV/PCM 16 kHz mono) → devuelve `{"text": "..."}`
  - `POST /api/tts` — recibe `{"text": "..."}` → devuelve audio PCM/WAV
- [ ] Mantener el contrato de audio del prototipo (16 kHz mono 16-bit)
- [ ] Config por env vars (`.env.example`): `STT_MODEL_SIZE`, `STT_DEVICE`
      (`cuda`/`cpu`), `TTS_VOZ`, puertos
- [ ] Tests de contrato nuevos en cada app

### Fase V2 — Micrófono y parlante remotos (celular como oídos/boca)
El robot no tiene audio físico; el camino corto es el celular:
- [ ] **App/cliente de captura** en el celular (o en el PC de la U): captura
      micrófono → envía tramos al `POST /api/stt` (por la red local o
      Tailscale, no por internet)
- [ ] **Reproductor** en el celular/PC: recibe el audio de TTS y lo reproduce
      (también se puede usar como *speaker* del robot mientras no haya uno
      USB conectado)
- [ ] Opción futuro: micrófono/parlante USB en el robot cuando exista — los
      servicios HTTP ya no cambian, solo cambia el cliente de audio

### Fase V3 — Integrar con el agente (Hermes)
- [ ] Crear skill `voice-bridge` (o ampliar `deepracer-control`) con:
  - `#escuchar` (o comando equivalente): captura tramo → STT → transcribe
  - `#hablar "texto"`: TTS → reproduce
- [ ] Flujo completo probado primero contra el simulador/backend HTTP:
      "comando por voz → agente → respuesta de voz"
- [ ] Decidir wake-word o push-to-talk (menos cómputo, más fiable en aula)

### Fase V4 — Calidad y decisiones pendientes
- [ ] Español: faster-whisper soporta español bien; edge-tts ya tiene
      `es-CO-SalomeNeural` ✅
- [ ] **Offline vs nube**: la visión quería 100% offline (Piper); edge-tts
      depende de Microsoft. Decidir: ¿aceptar nube para TTS (simple) o
      migrar a Piper (offline)? Documentar la decisión aquí cuando se tome.
- [ ] Ruido de aula: probar umbrales (`ENERGY_THRESHOLD`,
      `SILENCE_DURATION_SEC`) con audio real del aula, no ideal

### Fase V5 — Privacidad y cierre
- [ ] Política: no guardar audio; transcripciones solo en memoria de sesión
- [ ] Actualizar `apps/README.md` con los puertos nuevos
- [ ] Actualizar la sección "Voz" del plan maestro cuando V1-V3 estén

## 4. Referencias

| Fuente | Para qué |
|---|---|
| `apps/speech-to-text/README.md` | Contrato actual del STT |
| `apps/text-to-speech/README.md` | Contrato actual del TTS |
| `docs/plans/vision-nuevo-proyecto.md` | Visión original (Vosk/Piper, mic USB) |
| `docs/development/recopilacion-2026-1.md` | Sección 6.6 interacción por voz |
| `hermes/skills/robotics/deepracer-control/SKILL.md` | Dónde vive el conocimiento del robot |
| `apps/simulator/` | Patrón de "probar sin robot" (Fase 0 del plan maestro) |