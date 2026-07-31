#!/usr/bin/env python3
"""Login con password correcto de la API web: ${DEEPRACER_API_PASSWORD}"""
import paramiko
import os, shlex

api_password = shlex.quote(os.environ["DEEPRACER_API_PASSWORD"])

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)

sftp = ssh.open_sftp()
with sftp.open('/tmp/debug_login5.sh', 'w') as f:
    f.write((r"""#!/bin/bash

# PASO 1: GET login, extraer cookie y CSRF
HEADERS=$(curl -s -D - http://localhost:5001/login 2>/dev/null)
SESSION_COOKIE=$(echo "$HEADERS" | grep -i "Set-Cookie:" | grep -oP 'session=[^;]+')
CSRF=$(echo "$HEADERS" | grep -oP 'meta name="csrf-token" content="\K[^"]+')

# Inyectar cookie manual (Secure flag ignora HTTP)
echo "localhost	FALSE	/	FALSE	0	session	${SESSION_COOKIE#session=}" > /tmp/cookies.txt

echo "CSRF: $CSRF"

# PASO 2: POST login con password de la API web
echo "=== POST /login ==="
curl -v -s -b /tmp/cookies.txt -c /tmp/cookies.txt \
  -X POST http://localhost:5001/login \
  -H "X-CSRFToken: $CSRF" \
  -d "password=${DEEPRACER_API_PASSWORD}"
echo ""
""").replace("${DEEPRACER_API_PASSWORD}", api_password))
sftp.close()

stdin, stdout, stderr = ssh.exec_command('chmod +x /tmp/debug_login5.sh && bash /tmp/debug_login5.sh', timeout=15)
print(stdout.read().decode())
err = stderr.read().decode()
if err:
    print(f"STDERR:\n{err}")

ssh.close()
