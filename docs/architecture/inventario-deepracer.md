# 📋 Inventario del AWS DeepRacer — SpeedRacer

> Generado: 2026-07-07

## 🔧 Sistema
- **SO:** Ubuntu 20.04.1 LTS, Kernel 4.15
- **ROS2:** Foxy Fitzroy
- **Python:** 3.8.5
- **Disco:** 29GB (15GB libres)

## 📡 Sensores
| Sensor | Detalle |
|--------|---------|
| Cámara frontal | /dev/video0/1, formato MJPEG |
| LiDAR | RPLIDAR, 64 sectores, ±60°, 1m alcance |
| I2C | 8 buses (batería, servo, motor, LED) |
| LED RGB | Controlable por PWM |
| Servo | PWM 1220000-1900000 |
| Motor | PWM 1311000-1603500, polaridad -1 |

## 🚗 Control API (puerto 5001)
**Flujo obligatorio:** Login → drive_mode=manual → start_stop=start → LOOP manual_drive → stop
**Watchdog:** 200ms — loop sin pausa entre comandos
**Throttle:** invertido (negativo = avanza), recomendado 0.7
**Angle:** -1 (izquierda) a +1 (derecha)
**Headers:** X-CSRFToken, X-Requested-With: XMLHttpRequest, Cookie: session

## 📡 ROS2 Topics
`/ctrl_pkg/raw_pwm` — PWM motor
`/ctrl_pkg/servo_msg` — Dirección servo
`/deepracer_navigation_pkg/auto_drive` — Auto drive
`/webserver_pkg/manual_drive` — Comandos manuales
`/webserver_pkg/calibration_drive` — Calibración
`/parameter_events` / `/rosout`

## 📡 ROS2 Servicios clave
`/i2c_pkg/battery_level`, `/ctrl_pkg/enable_state`, `/ctrl_pkg/vehicle_state`,
`/ctrl_pkg/get_car_cal`/`set_car_cal`, `/ctrl_pkg/set_car_led`,
`/servo_pkg/set_led_state`, `/servo_pkg/servo_gpio`,
`/inference_pkg/inference_state`/`load_model`

## 🌐 Puertos
| Puerto | Servicio |
|--------|----------|
| 22 | SSH |
| 80, 443 | Nginx |
| 5001 | API REST (dashboard) |
| 8080 | Streaming MJPEG (cámara + LiDAR overlay) |
| 8081 | Web adicional |

## 🔄 Arquitectura
```
Hermes (Docker) ──SSH──▶ DeepRacer (LAN)
Hermes (Docker) ──HTTP──▶ Backend Node.js (Windows host:5002)
                             └──HTTPS──▶ DeepRacer API (:5001)
```

## ⚠️ Notas técnicas
- Container Docker NO tiene acceso a Tailscale
- Firewall del robot: policy INPUT DROP — agregar `-s 10.0.0.0/8 -j ACCEPT`
- Para movimiento: el comando debe ejecutarse EN el robot (subir script bash), no por SSH uno a uno

## 📸 Snapshot 2026-09-08 (verificado en vivo, red NachoNacho + Tailscale)
- **Hostname:** `amss-wuot` · **Tailscale estable:** `100.117.192.31` (canal oficial; el DHCP movió la LAN `.103` → `.106`)
- **Acceso real:** API por nginx `:443` (el `:5001` directo sirve HTTP plano, sin TLS); cámara `:8080`; SSH `:22`
- **Reloj:** sin RTC — congela apagado y mata Tailscale (mTLS). Fix: `timedatectl set-ntp true` (el cron `@reboot`+`ntpdate` falla sin red al bootear)
- **Cámara:** `uvcvideo: Buffer is NULL` en loop → resolvió con `sudo reboot` (snapshot 200 ~10KB)
- **Hardware:** cable motor↔ruedas suelto (API 200 igual, motor sonaba sin girar); re-conectado
- **Convención boot:** negativo=adelante; reversa asimétrica (mínimo ~+0.55-0.60-norm vs adelante ~-0.40)
- **Correcciones a este inventario (07-07):** LiDAR = solo software (sin módulo físico); IMU no soldada; throttle "recomendado 0.7" obsoleto (ver `deepracer-calibration`)

## 🔁 Re-snapshot (sin secretos)
Ejecutar en el robot `bash robot-snapshot.sh` (este directorio) y pegar la
salida abajo con fecha. El script es solo-lectura y **nunca** imprime
`password.txt`, `token.txt`, WiFi, SSH ni `.env` — verificar antes de commitear.
