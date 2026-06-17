#!/usr/bin/env python3
"""drive_test.py - Secuencia de movimientos variados del DeepRacer."""
import paramiko
import time

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect('10.203.150.56', username='deepracer', password='Steambog1$', timeout=10)
print("SSH OK")

sftp = ssh.open_sftp()
with sftp.open('/tmp/drive_test.sh', 'w') as f:
    f.write("""#!/bin/bash

# === LOGIN ===
echo "=== LOGIN ==="
HEADERS=$(curl -s -D - http://localhost:5001/login 2>/dev/null)
SESSION_COOKIE=$(echo "$HEADERS" | grep -i "Set-Cookie:" | grep -oP 'session=[^;]+')
CSRF=$(echo "$HEADERS" | grep -oP 'meta name="csrf-token" content="\\K[^"]+')
echo "localhost\tFALSE\t/\tFALSE\t0\tsession\t${SESSION_COOKIE#session=}" > /tmp/cookies.txt

curl -s -b /tmp/cookies.txt -c /tmp/cookies.txt \\
  -X POST http://localhost:5001/login \\
  -H "X-CSRFToken: $CSRF" \\
  -d "password=48AW5fAB"
echo ""

# === MODO MANUAL + START ===
echo "=== MODO MANUAL + START ==="
curl -s -b /tmp/cookies.txt -c /tmp/cookies.txt -X PUT http://localhost:5001/api/drive_mode \\
  -H "Content-Type: application/json;charset=UTF-8" \\
  -H "X-Requested-With: XMLHttpRequest" -H "X-CSRFToken: $CSRF" \\
  -d '{"drive_mode":"manual"}'
echo ""

curl -s -b /tmp/cookies.txt -c /tmp/cookies.txt -X PUT http://localhost:5001/api/start_stop \\
  -H "Content-Type: application/json;charset=UTF-8" \\
  -H "X-Requested-With: XMLHttpRequest" -H "X-CSRFToken: $CSRF" \\
  -d '{"start_stop":"start"}'
echo ""

# === MOVIMIENTO 1: Recto rapido 2s ===
echo "=== MOV 1: Recto rapido (throttle=0.7, 2s) ==="
for i in $(seq 1 10); do
  curl -s -b /tmp/cookies.txt -c /tmp/cookies.txt -X PUT http://localhost:5001/api/manual_drive \\
    -H "Content-Type: application/json;charset=UTF-8" \\
    -H "X-Requested-With: XMLHttpRequest" -H "X-CSRFToken: $CSRF" \\
    -d '{"angle":0,"throttle":0.7,"max_speed":1.0}'
  sleep 0.2
done
echo "OK"

# Pausa breve
sleep 0.5

# === MOVIMIENTO 2: Giro izquierda 1.5s ===
echo "=== MOV 2: Giro izquierda (angle=-0.5, throttle=0.4, 1.5s) ==="
for i in $(seq 1 8); do
  curl -s -b /tmp/cookies.txt -c /tmp/cookies.txt -X PUT http://localhost:5001/api/manual_drive \\
    -H "Content-Type: application/json;charset=UTF-8" \\
    -H "X-Requested-With: XMLHttpRequest" -H "X-CSRFToken: $CSRF" \\
    -d '{"angle":-0.5,"throttle":0.4,"max_speed":0.6}'
  sleep 0.2
done
echo "OK"

# Pausa breve
sleep 0.5

# === MOVIMIENTO 3: Giro derecha 1.5s ===
echo "=== MOV 3: Giro derecha (angle=0.5, throttle=0.4, 1.5s) ==="
for i in $(seq 1 8); do
  curl -s -b /tmp/cookies.txt -c /tmp/cookies.txt -X PUT http://localhost:5001/api/manual_drive \\
    -H "Content-Type: application/json;charset=UTF-8" \\
    -H "X-Requested-With: XMLHttpRequest" -H "X-CSRFToken: $CSRF" \\
    -d '{"angle":0.5,"throttle":0.4,"max_speed":0.6}'
  sleep 0.2
done
echo "OK"

# Pausa breve
sleep 0.5

# === MOVIMIENTO 4: Recto lento 2s ===
echo "=== MOV 4: Recto lento (throttle=0.3, 2s) ==="
for i in $(seq 1 10); do
  curl -s -b /tmp/cookies.txt -c /tmp/cookies.txt -X PUT http://localhost:5001/api/manual_drive \\
    -H "Content-Type: application/json;charset=UTF-8" \\
    -H "X-Requested-With: XMLHttpRequest" -H "X-CSRFToken: $CSRF" \\
    -d '{"angle":0,"throttle":0.3,"max_speed":0.4}'
  sleep 0.2
done
echo "OK"

# === STOP ===
echo "=== STOP ==="
curl -s -b /tmp/cookies.txt -c /tmp/cookies.txt -X PUT http://localhost:5001/api/start_stop \\
  -H "Content-Type: application/json;charset=UTF-8" \\
  -H "X-Requested-With: XMLHttpRequest" -H "X-CSRFToken: $CSRF" \\
  -d '{"start_stop":"stop"}'
echo ""

echo "=== DONE ==="
""")
sftp.close()
print("Script subido")

stdin, stdout, stderr = ssh.exec_command('chmod +x /tmp/drive_test.sh && bash /tmp/drive_test.sh', timeout=45)
print("\n--- SALIDA ---")
print(stdout.read().decode())
err = stderr.read().decode()
if err:
    print(f"--- ERR ---\n{err}")

ssh.close()
print("\nDone.")
