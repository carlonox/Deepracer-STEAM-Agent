#!/usr/bin/env python3
"""Diagnostico completo: verificar ROS2 y topics de movimiento."""
import paramiko
import time

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect('10.203.150.56', username='deepracer', password='Steambog1$', timeout=10)
print("SSH OK")

def run(ssh, cmd, label="", timeout=15):
    if label:
        print(f"\n{'='*60}")
        print(f"## {label}")
        print(f"{'='*60}")
    stdin, stdout, stderr = ssh.exec_command(cmd, timeout=timeout)
    out = stdout.read().decode()
    err = stderr.read().decode()
    if out:
        print(out)
    if err:
        print(f"[ERR] {err}")
    return out, err

# 1. Sourcear ROS2 y ver topics
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 topic list 2>/dev/null', 'ROS2 TOPICS')

# 2. Ver servicios
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 service list 2>/dev/null', 'ROS2 SERVICES')

# 3. Ver nodos activos
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 node list 2>/dev/null', 'ROS2 NODES')

# 4. Topics con tipo
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 topic list -t 2>/dev/null', 'TOPICS CON TIPO')

# 5. Info del webserver node
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 node info /webserver_pkg/webserver_publisher_node 2>/dev/null', 'WEBSERVER NODE INFO')

# 6. Info del ctrl_node
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 node info /ctrl_pkg/ctrl_node 2>/dev/null', 'CTRL NODE INFO')

# 7. Info del servo_node
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 node info /servo_pkg/servo_node 2>/dev/null', 'SERVO NODE INFO')

# 8. Buscar cualquier topic que tenga "cmd" o "drive" o "manual" en el nombre
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 topic list 2>/dev/null | grep -iE "cmd|drive|manual|servo|throttle|steer|motor|ctrl|action|goal|cmd_vel|twist"', 'TOPICS RELACIONADOS CON MOVIMIENTO')

# 9. Ver que tipos de mensajes usan los topics de ctrl_pkg
run(ssh, 'source /opt/ros/foxy/setup.bash && source /opt/aws/deepracer/lib/setup.bash && ros2 topic list 2>/dev/null | grep ctrl_pkg | while read t; do echo "--- $t ---"; ros2 topic info "$t" 2>/dev/null; done', 'CTRL_PKG TOPICS INFO')

ssh.close()
print("\n=== DIAGNOSTICO COMPLETADO ===")
