#!/usr/bin/env python3
"""Debug: verbose del GET login para ver headers."""
import paramiko

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)

sftp = ssh.open_sftp()
with sftp.open('/tmp/debug_login.sh', 'w') as f:
    f.write("""#!/bin/bash
echo "=== GET /login verbose ==="
curl -v -s -c /tmp/cookies.txt http://localhost:5001/login 2>&1
echo ""
echo "=== COOKIES ==="
cat /tmp/cookies.txt
""")
sftp.close()

stdin, stdout, stderr = ssh.exec_command('chmod +x /tmp/debug_login.sh && bash /tmp/debug_login.sh', timeout=15)
print(stdout.read().decode())
err = stderr.read().decode()
if err:
    print(f"STDERR:\n{err}")

ssh.close()
