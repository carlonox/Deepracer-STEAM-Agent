#!/usr/bin/env python3
"""Debug: login con cookie Secure forzada."""
import paramiko

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect('10.203.150.56', username='deepracer', password='Steambog1$', timeout=10)

sftp = ssh.open_sftp()
with sftp.open('/tmp/debug_login2.sh', 'w') as f:
    f.write("""#!/bin/bash

# PASO 1: GET login, guardar cookies
echo "=== PASO 1: GET /login ==="
curl -v -s -c /tmp/cookies.txt http://localhost:5001/login > /dev/null 2>&1
echo "=== COOKIES (raw) ==="
cat /tmp/cookies.txt

# Extraer CSRF del HTML
curl -s http://localhost:5001/login > /tmp/login.html
CSRF=$(grep -oP 'meta name="csrf-token" content="\\K[^"]+' /tmp/login.html)
echo "CSRF: $CSRF"

# PASO 2: POST login - como lo hace el JS: solo password, CSRF en header X-CSRFToken
echo "=== PASO 2: POST /login ==="
curl -v -s -b /tmp/cookies.txt -c /tmp/cookies.txt \\
  -X POST http://localhost:5001/login \\
  -H "X-CSRFToken: $CSRF" \\
  -d "password=Steambog1\$"
echo ""

echo "=== COOKIES AFTER POST ==="
cat /tmp/cookies.txt
""")
sftp.close()

stdin, stdout, stderr = ssh.exec_command('chmod +x /tmp/debug_login2.sh && bash /tmp/debug_login2.sh', timeout=15)
print(stdout.read().decode())
err = stderr.read().decode()
if err:
    print(f"STDERR:\n{err}")

ssh.close()
