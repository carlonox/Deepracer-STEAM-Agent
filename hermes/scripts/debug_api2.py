#!/usr/bin/env python3
"""Debug: encontrar la API Flask del deepracerweb."""
import paramiko

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)

# Ver que hay en el proyecto deepracerweb
stdin, stdout, stderr = ssh.exec_command('ls -la /home/deepracer/Desktop/deepracerweb/ 2>/dev/null || echo "No existe"')
print("=== PROYECTO WEB ===")
print(stdout.read().decode())

# Ver package.json del backend
stdin, stdout, stderr = ssh.exec_command('cat /home/deepracer/Desktop/deepracerweb/backend/package.json 2>/dev/null')
print("=== BACKEND package.json ===")
print(stdout.read().decode())

# Ver si hay un .env con el puerto
stdin, stdout, stderr = ssh.exec_command('cat /home/deepracer/Desktop/deepracerweb/backend/.env 2>/dev/null')
print("=== BACKEND .env ===")
print(stdout.read().decode())

# Ver que proceso tiene el 5001
stdin, stdout, stderr = ssh.exec_command('ss -tlnp | grep 5001')
print("=== PUERTO 5001 PROCESS ===")
print(stdout.read().decode())

# Ver si hay algo en 5000, 3000, 8000
stdin, stdout, stderr = ssh.exec_command('ss -tlnp | grep -E "5000|3000|8000|8080|8081"')
print("=== OTROS PUERTOS WEB ===")
print(stdout.read().decode())

# Ver que devuelve 8080
stdin, stdout, stderr = ssh.exec_command('curl -sk https://localhost:8080/ 2>&1 | head -20')
print("=== 8080 RESPONSE ===")
print(stdout.read().decode()[:500])

# Ver que devuelve 8081
stdin, stdout, stderr = ssh.exec_command('curl -sk https://localhost:8081/ 2>&1 | head -20')
print("=== 8081 RESPONSE ===")
print(stdout.read().decode()[:500])

# Ver que devuelve 5001/login con mas detalle
stdin, stdout, stderr = ssh.exec_command('curl -sk -v https://localhost:5001/login 2>&1 | head -40')
print("=== 5001/login VERBOSE ===")
print(stdout.read().decode()[:800])

ssh.close()
