# Steering Trim (STRAIGHT_ANGLE_OFFSET) — sesión 2026-07-31

## Problema

Con `angle=0` el robot se desvía a la derecha durante el avance. Medido en
vivo con cinta en el piso (burst de 2.0-2.1 s, throttle normalizado -0.30 =
real -0.65):

- Avance: 190.5 cm
- Desvío lateral a la derecha: 14.5 cm
- Trayectoria real: √(190.5² + 14.5²) ≈ 191.1 cm
- Ángulo de deriva: atan(14.5 / 190.5) ≈ **4.35°** (~1.9°/s)
- Tasa: ~7.6 cm por metro recorrido

## 🔴 Lección CLAVE: el servo es MUY sensible (no lineal, medido en vivo)

Dos corridas de calibración del trim (mismo boot, robot en el suelo, burst
2.2 s a real -0.65):

| Offset | Tasa de giro observada | Consecuencia |
|--------|------------------------|--------------|
| 0.00 | +2°/s (deriva derecha) | 14.5 cm de desvío en 190.5 cm |
| -0.11 | **~-40°/s** (giro izquierdo fuerte) | **90° literales en 2.2 s** 😅 |
| -0.01 | visible a la izquierda (sobre-corrige) | aún demasiado |

- Ganancia medida: **~380°/s de yaw por 1.0 de angle** (en -0.11). La
  suposición inicial de ±40° por ±1.0 (≈ 9°/s por 0.01) quedó refutada: el
  servo responde mucho más fuerte de lo que la geometría sugiere.
- Ajuste lineal con dos puntos (0 → +2°/s; -0.11 → -40°/s): el trim recto
  predicho es **≈ -0.005**. -0.01 ya sobre-gira a la izquierda → iterar desde
  **-0.005 en pasos de ±0.005**, NUNCA saltar a -0.1.
- Si una prueba de trim produce un GIRO FUERTE en vez de una corrección suave,
  el offset está un orden de magnitud por encima — bajar 10× antes de seguir.

## Solución implementada

En `apps/backend/vehicleControl.js` (mismo patrón que `calibrateThrottle`):

```js
let straightAngleOffset = Math.max(-1, Math.min(1, parseFloat(process.env.STRAIGHT_ANGLE_OFFSET || "0")));

export function calibrateAngle(angle) {
  const a = Math.max(-1, Math.min(1, angle));
  return Math.max(-1, Math.min(1, a + straightAngleOffset));
}

export function setCalibration({ angleOffset } = {}) { ... }  // muta en vivo
export function getCalibration() { ... }                       // valores activos
```

`manualDrive()` usa `calibrateAngle(angle)`. El `.env` raíz y `.env.example`
llevan `STRAIGHT_ANGLE_OFFSET` (inicial; el valor en vivo se ajusta por API).

### Endpoint de calibración en vivo (sin reiniciar el backend)

```
GET  /api/calibration                        → {"straightAngleOffset":..., "throttleDeadZone":...}
POST /api/calibration  {"angle_offset": -0.005}  → configuración activa
```

- El POST persiste solo en memoria; el `.env` manda al reiniciar.
- **Siempre GET antes de culpar al trim**: un backend que no se reinició sigue
  con el offset viejo. El `uptime_s` de `/api/health` desambigua si el
  reinicio ocurrió de verdad.
- Unit test del módulo (node --input-type=module): in=0 → -0.01 (con .env),
  in=0.5 → 0.39, in=-0.5 → -0.61, in=1 → 0.89, in=-1 → -1 (clamp OK).

## Ajuste fino (protocolo de iteración)

1. `POST /api/calibration {"angle_offset": X}` (sin reinicios).
2. Corrida de deriva: burst 2.0-2.2 s a real -0.65, robot con parachoques en
   el inicio de la cinta.
3. Mide avance y desvío lateral (cm y lado).
4. Aún derecha → más negativo; izquierda → menos negativo. Pasos ±0.005.

## Estado de verificación

- Implementado + unit tests OK (2026-07-31).
- Verificación física en curso al cierre: -0.01 todavía gira a la izquierda;
  pendiente confirmar ≈ -0.005 (y fijarlo en `.env` cuando se valide).

## Notas

- El trim afecta a TODO lo que pasa por el backend (frontend, agente,
  navegación vía HTTP/TCP). Los scripts robot-side (daemon/explorer) no lo
  tienen — añadir constante propia si se necesitan.
- La calibración "de verdad" es el centro físico del servo (dashboard del
  robot, `/webserver_pkg/calibration_drive`); el trim es el parche software
  reversible y actual del proyecto.
- La deriva puede variar con la carga de batería y la superficie.
