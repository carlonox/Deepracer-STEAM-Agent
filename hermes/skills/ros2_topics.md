# ROS2 Topics del DeepRacer

## Exploración realizada

Se conectó al DeepRacer vía SSH (a través del backend proxy) y se ejecutó:
```
source /opt/ros/foxy/setup.bash
source /opt/aws/deepracer/lib/setup.bash
ros2 topic list
```

## Topics encontrados (7 total)

Todos son de **control**, no de telemetría/lectura:

| Topic | Tipo | Descripción |
|-------|------|-------------|
| `/ctrl_pkg/raw_pwm` | Publicación | Estado PWM del motor (activo/no activo) |
| `/ctrl_pkg/servo_msg` | Publicación | Dirección actual de las ruedas (ángulo) |
| `/webserver_pkg/manual_drive` | Suscripción | Confirmación de comandos manuales recibidos |
| *(4 topics restantes)* | Control | Relacionados con el stack de control del vehículo |

## Lo que NO existe

- ❌ `/odom` — No hay odometría (posición, velocidad)
- ❌ `/imu` — No hay sensor IMU (inclinación, aceleración)
- ❌ `/battery` / `/battery_state` — No hay lectura de batería
- ❌ `/scan` / `/lidar` — No hay sensores de distancia
- ❌ `/sensor_fusion` — No hay fusión de sensores
- ❌ `/camera_pkg/*` — La cámara se accede por HTTP (puerto 8080), no por ROS2

## Conclusión

**El DeepRacer no tiene telemetría accesible vía ROS2.** Los 7 topics son puramente de control (enviar comandos al vehículo), no de lectura de estado.

## Alternativas para el proyecto mascota AI

1. **Cámara (puerto 8080)** — Ya funciona. Es el único sensor real disponible.
2. **Estimación por tiempo** — Distancia ≈ tiempo × velocidad_estimada (basada en throttle). Muy impreciso.
3. **ArUco markers** — Colocar marcadores en el aula para que la cámara detecte posición. Es la opción más viable para localización.
4. **PWM/Servo como feedback limitado** — `/ctrl_pkg/raw_pwm` y `/ctrl_pkg/servo_msg` pueden confirmar que el motor y servo responden, pero no dan posición ni velocidad real.
