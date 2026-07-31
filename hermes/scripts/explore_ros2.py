#!/usr/bin/env python3
"""explore_ros2.py - Explora topics ROS2 del DeepRacer vÃ­a SSH (paramiko)."""
import paramiko
import time

HOST = __import__("os").environ["DEEPRACER_HOST"]
USER = __import__("os").environ["DEEPRACER_SSH_USER"]
PASS = __import__("os").environ["DEEPRACER_SSH_PASSWORD"]
def run(ssh, cmd, timeout=15):
    stdin, stdout, stderr = ssh.exec_command(cmd, timeout=timeout)
    out = stdout.read().decode().strip()
    err = stderr.read().decode().strip()
    return out, err

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(HOST, username=USER, password=PASS, timeout=15)
print(f"SSH conectado a {HOST}")

# Source ROS2 + listar topics
print("\n=== SOURCE + ROS2 TOPIC LIST ===")
out, err = run(ssh, (
    "source /opt/ros/foxy/setup.bash && "
    "source /opt/aws/deepracer/lib/setup.bash && "
    "ros2 topic list"
))
print(out)
if err:
    print(f"STDERR: {err}")

topics = [t.strip() for t in out.splitlines() if t.strip()]

# Info de cada topic
print("\n=== TOPIC INFO (type + publishers/subscribers) ===")
for t in topics:
    out, err = run(ssh, (
        "source /opt/ros/foxy/setup.bash && "
        "source /opt/aws/deepracer/lib/setup.bash && "
        f"ros2 topic info {t}"
    ))
    print(f"\n--- {t} ---")
    print(out)
    if err:
        print(f"STDERR: {err}")

# Echo de topics relevantes
KEYWORDS = ["odom", "imu", "battery", "sensor_fusion", "ctrl_pkg", "camera_pkg", "speed", "state", "pose", "velocity", "motor", "lidar", "scan"]
relevant = [t for t in topics if any(k in t.lower() for k in KEYWORDS)]

print(f"\n=== ECHO DE TOPICS RELEVANTES ({len(relevant)} encontrados) ===")
for t in relevant:
    print(f"\n--- echo {t} ---")
    out, err = run(ssh, (
        "source /opt/ros/foxy/setup.bash && "
        "source /opt/aws/deepracer/lib/setup.bash && "
        f"ros2 topic echo {t} --once --timeout 3"
    ), timeout=10)
    if out:
        print(out)
    if err:
        print(f"STDERR: {err}")
    if not out and not err:
        print("(sin datos)")

ssh.close()
print("\n=== EXPLORACIÃ“N COMPLETA ===")
