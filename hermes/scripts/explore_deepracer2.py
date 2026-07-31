import paramiko
import sys

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)

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

# Proyecto deepracerweb en el robot
run('ls -la /home/deepracer/Desktop/deepracerweb/ 2>/dev/null || echo "No existe"', 'PROYECTO WEB en robot')
run('cat /home/deepracer/Desktop/deepracerweb/package.json 2>/dev/null', 'package.json del proyecto web')
run('cat /home/deepracer/Desktop/deepracerweb/backend/package.json 2>/dev/null', 'backend package.json del proyecto web')

# Config nginx
run('cat /etc/nginx/nginx.conf 2>/dev/null', 'NGINX config')
run('ls /etc/nginx/sites-enabled/ 2>/dev/null', 'NGINX sites-enabled')
run('cat /etc/nginx/sites-enabled/default 2>/dev/null', 'NGINX default site')

# Deepracer web server API
run('curl -s -o /dev/null -w "%{http_code}" http://localhost:5001/api/drive_mode 2>/dev/null || echo "no response"', 'API drive_mode status')
run('curl -s http://localhost:5001/api/drive_mode 2>/dev/null', 'API drive_mode response')

# Servicio deepracer-core
run('systemctl status deepracer-core.service 2>/dev/null | head -20', 'deepracer-core service status')
run('cat /etc/systemd/system/deepracer-core.service 2>/dev/null', 'deepracer-core service file')

# start_ros.sh
run('cat /opt/aws/deepracer/start_ros.sh 2>/dev/null', 'start_ros.sh')

# Calibración
run('cat /opt/aws/deepracer/calibration.json 2>/dev/null', 'calibration.json')

# Sensor config
run('cat /opt/aws/deepracer/sensor_configuration.json 2>/dev/null', 'sensor_configuration.json')

# Network monitor - como se obtiene la IP
run('cat /opt/aws/deepracer/lib/deepracer_systems_pkg/lib/deepracer_systems_pkg/network_monitor_node 2>/dev/null | head -50', 'network_monitor_node (primeras 50 lineas)')

# Web video server info
run('ros2 pkg list 2>/dev/null | grep -i video', 'ROS2 video packages')
run('ros2 pkg list 2>/dev/null | grep -i web', 'ROS2 web packages')

# Ollama check
run('which ollama 2>/dev/null && ollama list 2>/dev/null || echo "Ollama no instalado"', 'Ollama check')

# Pip packages en el sistema
run('pip3 list 2>/dev/null | grep -iE "langchain|faiss|ollama|openai|flask|opencv|numpy|torch|tensorflow|paramiko|vosk|piper"', 'Pip packages relevantes')

# Audio devices
run('cat /proc/asound/cards 2>/dev/null', 'Audio cards')
run('pactl list sources short 2>/dev/null || echo "pactl no disponible"', 'Audio sources')
run('pactl list sinks short 2>/dev/null || echo "pactl no disponible"', 'Audio sinks')

ssh.close()
print("\n\n=== EXPLORACION COMPLETADA ===")
