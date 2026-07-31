#!/usr/bin/env python3
"""Ver el HTML del login del DeepRacer."""
import paramiko

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)

# Descargar el login.html
sftp = ssh.open_sftp()
sftp.get('/tmp/login.html', '/tmp/login_deepracer.html')
sftp.close()

# Leerlo
with open('/tmp/login_deepracer.html', 'r') as f:
    content = f.read()

print(f"Tamano: {len(content)} bytes")
print("=== CONTENIDO ===")
print(content[:2000])

ssh.close()
