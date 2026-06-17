#!/usr/bin/env python3
"""Debug: ver que devuelve la API del DeepRacer."""
import paramiko

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect('10.203.150.56', username='deepracer', password='Steambog1$', timeout=10)

# Ver puertos escuchando
stdin, stdout, stderr = ssh.exec_command('ss -tlnp 2>/dev/null | head -20')
print("=== PUERTOS ===")
print(stdout.read().decode())

# Ver procesos del web server
stdin, stdout, stderr = ssh.exec_command('ps aux | grep -E "node|python|flask|uvicorn|gunicorn|express" | grep -v grep')
print("=== PROCESOS WEB ===")
print(stdout.read().decode())

# Ver que devuelve el login (sin grep)
stdin, stdout, stderr = ssh.exec_command('curl -sk https://localhost:5001/login 2>&1 | head -80')
print("=== LOGIN HTML ===")
print(stdout.read().decode())

# Ver si hay redirect
stdin, stdout, stderr = ssh.exec_command('curl -sk -D - https://localhost:5001/login 2>&1 | head -40')
print("=== LOGIN HEADERS ===")
print(stdout.read().decode())

ssh.close()
