# Teleoperación Bluetooth (diseño)

> **Estado:** diseño (2026-09-08). Sin implementar.
> **Decisión que revierte parcialmente:** el ESP32 se descartó el 2026-09-05
> como *sensor de autonomía*. Este diseño lo revive SOLO como accesorio de
> teleoperación manual (mando a distancia), no como sensor del agente.

## Objetivo
Manejar el carro desde el celu o el Meta Quest por BLE, **sin PC, sin WiFi,
sin backend**: `mando → BLE → ESP32 → serial USB → bridge en robot → API
local`. Latencia local (~10-30 ms) vs Tailscale (~40-80 ms).

## No-objetivos
- Autonomía por BT (el agente sigue por backend + cámara + RAG).
- Telemetría rica por BT (para eso está el backend + dashboard).
- Seguridad anti-adversario: el aula confía; el diseño frena bromistas,
  no atacantes.

## Arquitectura (elegida: standalone, sin backend)
El backend **no** participa en esta vía (sigue vivo para agente/autonomía).
El bridge corre en el robot, lee el serial del ESP32 y maneja la API local
(`http://localhost:5001`, loop 30 Hz, watchdog satisfecho por construcción).

```
Celu/Quest (app BLE, servicio NUS) ──BLE──▶ ESP32 ──USB serial──▶ bridge ──HTTP local──▶ API robot
```

## Protocolo NUS (una línea por comando, `\n`)
| Comando | Efecto |
|---|---|
| `F`,`B`,`L`,`R` | Adelante / atrás / izq / der (combinables: `FL`) |
| `S` o silencio >500 ms | STOP inmediato |
| `V0`-`V9` | Tope de velocidad 0-9 (default `V4` ≈ 0.4-norm) |
- Throttle máximo del bridge: **0.60-norm** (real 0.80), mesmo techo probado.
- Desconexión BLE o silencio >500 ms ⇒ stop + `start_stop=stop` (fail-safe).
- El bridge SOLO corre armado: archivo `/tmp/bt_armed` creado por el
  operador (vía SSH/backend) con expiración de 10 min; sin armar, ignora todo.

## Seguridad honesta
BLE "Just Works" no autentica: cualquiera a <10 m podría conectar. Mitiga:
operador presente + armado con expiración + tope 0.60 + zona despejada.
No es control de acceso serio; si el aula lo exige, sigue el backend.

## Quest
- **Vía BT (nueva):** sideloadear app BLE (nRF Connect / Serial Bluetooth
  Terminal) en el Quest, mismo protocolo NUS. Sin WebBluetooth: no confiable
  en el navegador del Quest.
- **Vía WebXR (existente, sin cambios):** `apps/frontend` (`QuestVRControls`,
  `useQuestVRInput`) → backend → robot. Requiere red + backend + PC.

## Fases
1. **Bridge** (`bt-bridge.py` en robot): serial→API local, loop 30 Hz, caps,
   fail-safe, armado `/tmp/bt_armed`. Probar elevado, luego suelo.
2. **Protocolo**: validar F/B/L/R/S/V + stop por silencio con app en celu.
3. **Quest**: sideload app BLE, repetir pruebas.
4. **Docs**: skills (`deepracer-motor-control` apéndice BT), reconciliar
   descarte ESP32 en plan maestro (alcance: solo teleop).

## Pruebas (todas con operador, zona despejada, LiPo llena)
- Elevado: cada comando mueve/para; matar BLE a mitad ⇒ stop <1 s.
- Suelo: adelante/atrás/giros a `V4`; confirmar convención (neg=adelante).
- Regresión: backend y autonomía intactos (bridge apagado por defecto).
