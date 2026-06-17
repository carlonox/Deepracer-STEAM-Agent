import paramiko
import sys

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect('10.203.150.56', username='deepracer', password='Steambog1$', timeout=10)

def run(cmd, label):
    print(f"\n{'='*60}")
    print(f"## {label}")
    print(f"## CMD: {cmd}")
    print(f"{'='*60}")
    stdin, stdout, stderr = ssh.exec_command(cmd, timeout=30)
    out = stdout.read().decode()
    err = stderr.read().decode()
    if out:
        print(out)
    if err:
        print(f"[STDERR] {err}", file=sys.stderr)

# 1. Sistema general
run('whoami && hostname && uname -a', 'SISTEMA: usuario/hostname/kernel')
run('cat /etc/os-release', 'SISTEMA: OS release')
run('df -h', 'SISTEMA: disco')
run('free -m', 'SISTEMA: memoria')
run('ip addr show', 'SISTEMA: red')

# 2. Software ROS2
run('ls /opt/ros/ 2>/dev/null || echo "NO /opt/ros/"', 'ROS2: distros instaladas')
run('ls /opt/aws/deepracer/ 2>/dev/null || echo "NO /opt/aws/deepracer/"', 'ROS2: AWS DeepRacer')
run('ros2 node list 2>/dev/null || echo "ros2 no disponible o sin nodes"', 'ROS2: nodes activos')
run('ros2 topic list 2>/dev/null || echo "ros2 no disponible o sin topics"', 'ROS2: topics')
run('ros2 service list 2>/dev/null || echo "ros2 no disponible o sin services"', 'ROS2: services')

# 3. Procesos
run('ps aux | grep -E "ros|node|python|http|stream" | grep -v grep', 'PROCESOS: relevantes')

# 4. Proyecto custom
run('find /home /root /opt /var /srv -name "*.py" -not -path "*/usr/*" -not -path "*/lib/*" -not -path "*/site-packages/*" 2>/dev/null | head -50', 'CUSTOM: archivos Python custom')
run('find /home /root /opt /var /srv -name "package.json" -not -path "*/node_modules/*" 2>/dev/null', 'CUSTOM: package.json')
run('find / -name "*.launch*" -not -path "*/usr/*" -not -path "*/lib/*" -not -path "*/site-packages/*" 2>/dev/null | head -30', 'CUSTOM: launch files')

# 5. Puertos
run('ss -tlnp 2>/dev/null || netstat -tlnp 2>/dev/null', 'RED: puertos escuchando')

# 6. Hardware
run('lsusb 2>/dev/null', 'HW: USB devices')
run('ls /dev/video* 2>/dev/null || echo "No /dev/video*"', 'HW: cámaras')
run('arecord -l 2>/dev/null || echo "arecord no disponible"', 'HW: audio capture')
run('aplay -l 2>/dev/null || echo "aplay no disponible"', 'HW: audio playback')

# 7. Credenciales y config
run('ls /etc/wpa_supplicant/ 2>/dev/null; cat /etc/wpa_supplicant/wpa_supplicant.conf 2>/dev/null | grep -v "psk=" || echo "No wpa_supplicant o sin permiso"', 'CONFIG: WiFi')
run('ls ~/.ssh/ 2>/dev/null', 'CONFIG: SSH keys')
run('cat ~/.ssh/authorized_keys 2>/dev/null || echo "No authorized_keys"', 'CONFIG: SSH authorized keys')

# 8. Extra: servicios systemd
run('systemctl list-units --type=service --state=running 2>/dev/null | head -30', 'SERVICIOS: systemd running')

# 9. Extra: Docker
run('docker ps 2>/dev/null || echo "Docker no disponible o sin permisos"', 'DOCKER: containers')

# 10. Extra: entorno Python
run('which python3 && python3 --version', 'PYTHON: version')
run('pip3 list 2>/dev/null | grep -iE "flask|fastapi|opencv|numpy|torch|tensorflow" || echo "pip3 no disponible"', 'PYTHON: paquetes relevantes')

ssh.close()
print("\n\n=== EXPLORACION COMPLETADA ===")
