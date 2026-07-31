#!/usr/bin/env python3
"""Login inyectando la cookie Secure manualmente."""
import paramiko
import os, shlex

api_password = shlex.quote(os.environ["DEEPRACER_API_PASSWORD"])

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)

sftp = ssh.open_sftp()
with sftp.open('/tmp/debug_login3.sh', 'w') as f:
    f.write((r"""#!/bin/bash

# PASO 1: GET login, capturar headers para extraer Set-Cookie
echo "=== PASO 1: GET /login ==="
HEADERS=$(curl -s -D - -c /tmp/cookies.txt http://localhost:5001/login 2>/dev/null)
echo "$HEADERS" > /tmp/login_full.txt

# Extraer la cookie session del Set-Cookie header
SESSION_COOKIE=$(echo "$HEADERS" | grep -i "Set-Cookie:" | grep -oP 'session=[^;]+')
echo "SESSION_COOKIE: $SESSION_COOKIE"

# Inyectar la cookie manualmente en el cookie jar (forzar domain localhost)
echo "localhost	FALSE	/	FALSE	0	session	${SESSION_COOKIE#session=}" >> /tmp/cookies.txt
echo "=== COOKIES ==="
cat /tmp/cookies.txt

# Extraer CSRF del HTML
CSRF=$(echo "$HEADERS" | grep -oP 'meta name="csrf-token" content="\K[^"]+')
echo "CSRF: $CSRF"

# PASO 2: POST login con cookie inyectada + CSRF en header
echo "=== PASO 2: POST /login ==="
curl -v -s -b /tmp/cookies.txt -c /tmp/cookies.txt \
  -X POST http://localhost:5001/login \
  -H "X-CSRFToken: $CSRF" \
  -d "password=${DEEPRACER_API_PASSWORD}"
echo ""

echo "=== COOKIES AFTER POST ==="
cat /tmp/cookies.txt
""").replace("${DEEPRACER_API_PASSWORD}", api_password))
sftp.close()

stdin, stdout, stderr = ssh.exec_command('chmod +x /tmp/debug_login3.sh && bash /tmp/debug_login3.sh', timeout=15)
print(stdout.read().decode())
err = stderr.read().decode()
if err:
    print(f"STDERR:\n{err}")

ssh.close()
