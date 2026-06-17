# Reglas de Control del DeepRacer

## Preparar el robot
curl -s -X POST http://host.docker.internal:5002/api/start
SIEMPRE antes de cualquier movimiento.

## Mover el robot
Loop SIN PAUSA, nunca usar sleep entre comandos.
URL: http://host.docker.internal:5002/api/manual_drive
Método: POST
Headers: Content-Type: application/json

### Parámetros
- angle: -1.0 (izquierda) a 1.0 (derecha), 0 = recto
- throttle: -1.0 (reversa) a 1.0 (adelante)
- max_speed: 0.0 a 1.0

### Ejemplo de una fase
END=$(($(date +%s%N) + DURACION_EN_NANOSEGUNDOS))
while [ $(date +%s%N) -lt $END ]; do
  curl -s -X POST http://host.docker.internal:5002/api/manual_drive \
    -H "Content-Type: application/json" \
    -d '{"angle": 0, "throttle": 0.5, "max_speed": 0.7}' > /dev/null
done

## Detener el robot
curl -s -X POST http://host.docker.internal:5002/api/stop
SIEMPRE al final de cualquier secuencia.

## Secuencia obligatoria
1. api/start (preparar)
2. api/manual_drive en loop (mover)
3. api/stop (parar)

## Valores recomendados
- Arranque suave: throttle=0.3, max_speed=0.5
- Normal: throttle=0.5, max_speed=0.7
- Rápido: throttle=0.8, max_speed=1.0
- Giro suave: angle=±0.4
- Giro fuerte: angle=±0.7
- Reversa: throttle negativo

## Conexión
- Backend: host.docker.internal:5002 (desde Docker)
- Backend: localhost:5002 (desde Windows directo)
- DeepRacer: 100.117.192.31 (Tailscale)
