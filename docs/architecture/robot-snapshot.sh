#!/bin/bash
# Snapshot de SOLO LECTURA del DeepRacer (SpeedRacer / amss-wuot).
# Uso: copiar al robot (SFTP o pegado), correr:  bash robot-snapshot.sh
# Salida: pegar en docs/architecture/inventario-deepracer.md (sección Snapshot).
#
# REGLA DURA: este script NUNCA imprime secretos. Prohibido agregar:
#   /opt/aws/deepracer/password.txt, token.txt, perfiles WiFi
#   (/etc/NetworkManager/*), claves SSH (~/.ssh), .env, cookies/sesiones.
# Lo que sí lista (operativo, no secreto): IPs LAN/Tailscale propias,
# paquetes, cron, reglas iptables (sin contraseñas), topics y archivos /tmp.

echo '=== 1. fecha (reloj RTC ausente: debe ser HOY o Tailscale muere) ==='
date
echo '=== 2. IPs propias ==='
hostname -I
echo '=== 3. disco y RAM ==='
df -h / | tail -1
free -m | head -2
echo '=== 4. video y serie ==='
ls -l /dev/video* 2>/dev/null
ls /dev/ttyUSB* /dev/ttyACM* 2>/dev/null || echo '(sin ttyUSB/ACM)'
echo '=== 5. cron propio ==='
crontab -l 2>/dev/null || echo '(sin crontab)'
echo '=== 6. servicios fallidos ==='
systemctl list-units --state=failed --no-legend 2>/dev/null | head -5 || echo '(sin systemctl)'
echo '=== 7. nodos ROS clave ==='
ps aux | grep -E 'camera_node|web_video_server|webserver_publisher|ctrl_node' | grep -v grep | awk '{print $11, $12}' | head -8
echo '=== 8. python y paquetes de robot ==='
python3 --version
pip3 list 2>/dev/null | grep -iE 'opencv|numpy|esptool|ampy|pyserial|flask|werkzeug' || echo '(pip sin coincidencias)'
echo '=== 9. tailscale propio ==='
tailscale ip -4 2>/dev/null || echo '(tailscale caído: revisar reloj primero)'
echo '=== 10. scripts y logs en /tmp ==='
ls -l /tmp/*.py /tmp/*.log 2>/dev/null | head -20 || echo '(/tmp sin py/log)'
echo '=== FIN (revisar que NO haya secretos arriba antes de pegar al repo) ==='
