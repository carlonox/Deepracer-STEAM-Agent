#!/usr/bin/env python3
"""Login con csrf_token en body + cookie inyectada."""
import paramiko
import os, shlex

api_password = shlex.quote(os.environ["DEEPRACER_API_PASSWORD"])

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)

sftp = ssh.open_sftp()
with sftp.open('/tmp/debug_login4.sh', 'w') as f:
    f.write((r"""#!/bin/bash

# PASO 1: GET login, extraer cookie y CSRF
HEADERS=$(curl -s -D - http://localhost:5001/login 2>/dev/null)
SESSION_COOKIE=$(echo "$HEADERS" | grep -i "Set-Cookie:" | grep -oP 'session=[^;]+')
CSRF=$(echo "$HEADERS" | grep -oP 'meta name="csrf-token" content="\K[^"]+')

# Inyectar cookie manual
echo "localhost	FALSE	/	FALSE	0	session	${SESSION_COOKIE#session=}" > /tmp/cookies.txt

echo "CSRF: $CSRF"
echo "Cookie: ${SESSION_COOKIE#session=}"

# PASO 2: POST login con csrf_token EN EL BODY (como vehicleControl.js)
echo "=== POST /login (con csrf_token en body) ==="
curl -v -s -b /tmp/cookies.txt -c /tmp/cookies.txt \
  -X POST http://localhost:5001/login \
  -H "Content-Type: application/x-www-form-urlencoded" \
  -H "X-CSRFToken: $CSRF" \
  -d "csrf_token=$CSRF&password=${DEEPRACER_API_PASSWORD}"
echo ""
""").replace("${DEEPRACER_API_PASSWORD}", api_password))
sftp.close()

stdin, stdout, stderr = ssh.exec_command('chmod +x /tmp/debug_login4.sh && bash /tmp/debug_login4.sh', timeout=15)
print(stdout.read().decode())
err = stderr.read().decode()
if err:
    print(f"STDERR:\n{err}")

ssh.close()
