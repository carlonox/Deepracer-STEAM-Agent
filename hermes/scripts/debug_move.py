#!/usr/bin/env python3
"""Diagnosticar por que el DeepRacer no se mueve."""
import paramiko

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)
print("SSH OK")

def run(ssh, cmd, label=""):
    if label:
        print(f"\n=== {label} ===")
    stdin, stdout, stderr = ssh.exec_command(cmd, timeout=15)
    out = stdout.read().decode()
    err = stderr.read().decode()
    if out:
        print(out)
    if err:
        print(f"[ERR] {err}")
    return out, err

# 1. Ver si el webserver_publisher_node esta corriendo y que puerto usa
run(ssh, 'ps aux | grep webserver | grep -v grep', 'Webserver process')

# 2. Ver los topics de ROS2 relacionados con movimiento
run(ssh, 'ros2 topic list 2>/dev/null | grep -iE "drive|motor|servo|cmd|vel|throttle|steer|manual"', 'ROS2 drive topics')

# 3. Ver si hay algun nodo suscrito a comandos de movimiento
run(ssh, 'ros2 node info /webserver_pkg/webserver_publisher_node 2>/dev/null | head -30', 'Webserver node info')

# 4. Ver el estado actual del vehiculo
run(ssh, 'ros2 topic echo --once /ctrl_pkg/control_cmd 2>/dev/null || echo "No control_cmd topic"', 'Control command topic')

# 5. Ver si el nodo de control (ctrl_node) esta vivo
run(ssh, 'ros2 node list 2>/dev/null | grep -i ctrl', 'Control nodes')

# 6. Ver los servicios disponibles para movimiento
run(ssh, 'ros2 service list 2>/dev/null | grep -iE "drive|motor|start|stop|mode"', 'Drive services')

# 7. Ver que hay en el puerto 5001 realmente
run(ssh, 'ss -tlnp | grep 5001', 'Puerto 5001')

# 8. Ver si hay un servicio web alternativo
run(ssh, 'ss -tlnp | grep -E "5000|5002|8080|8081|80|443"', 'Otros puertos web')

# 9. Ver los logs del webserver
run(ssh, 'journalctl -u deepracer-core --no-pager -n 20 2>/dev/null || echo "No systemd logs"', 'DeepRacer logs')

# 10. Ver si existe el archivo de launch del webserver
run(ssh, 'cat /opt/aws/deepracer/deepracer_launcher.py 2>/dev/null | head -50 || find /opt/aws -name "*.launch*" -o -name "*webserver*" 2>/dev/null | head -10', 'Launch files')

ssh.close()
print("\nDone.")
