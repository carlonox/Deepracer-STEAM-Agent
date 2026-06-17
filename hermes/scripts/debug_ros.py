#!/usr/bin/env python3
"""Diagnosticar topics y servicios ROS2 del DeepRacer."""
import paramiko

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect('10.203.150.56', username='deepracer', password='Steambog1$', timeout=10)

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

# Todos los topics
run(ssh, 'ros2 topic list 2>/dev/null', 'ALL TOPICS')

# Todos los servicios
run(ssh, 'ros2 service list 2>/dev/null', 'ALL SERVICES')

# Info del webserver node
run(ssh, 'ros2 node info /webserver_pkg/webserver_publisher_node 2>/dev/null', 'WEBSERVER NODE')

# Info del ctrl_node
run(ssh, 'ros2 node info /ctrl_pkg/ctrl_node 2>/dev/null', 'CTRL NODE')

# Ver que publica/escucha el servo_node
run(ssh, 'ros2 node info /servo_pkg/servo_node 2>/dev/null', 'SERVO NODE')

# Ver el mensaje de control
run(ssh, 'ros2 topic list -t 2>/dev/null', 'TOPICS CON TIPO')

ssh.close()
print("\nDone.")
