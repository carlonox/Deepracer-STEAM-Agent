#!/usr/bin/env python3
"""Debug: encontrar el puerto correcto de la API y ver su login."""
import paramiko

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(__import__("os").environ["DEEPRACER_HOST"], username=__import__("os").environ["DEEPRACER_SSH_USER"], password=__import__("os").environ["DEEPRACER_SSH_PASSWORD"], timeout=10)

# Ver si hay algo en 5002
stdin, stdout, stderr = ssh.exec_command('ss -tlnp | grep 5002')
print("=== PUERTO 5002 ===")
print(stdout.read().decode())

# Ver si el backend node esta corriendo
stdin, stdout, stderr = ssh.exec_command('ps aux | grep "node server" | grep -v grep')
print("=== NODE SERVER ===")
print(stdout.read().decode())

# Ver que devuelve 5001 sin SSL (http)
stdin, stdout, stderr = ssh.exec_command('curl -s http://localhost:5001/login 2>&1 | head -40')
print("=== 5001 HTTP login ===")
print(stdout.read().decode()[:500])

# Ver que devuelve 5001 con path /
stdin, stdout, stderr = ssh.exec_command('curl -s http://localhost:5001/ 2>&1 | head -40')
print("=== 5001 HTTP / ===")
print(stdout.read().decode()[:500])

# Ver que hay en 8080
stdin, stdout, stderr = ssh.exec_command('curl -s http://localhost:8080/ 2>&1 | head -40')
print("=== 8080 HTTP / ===")
print(stdout.read().decode()[:500])

# Ver que hay en 8081
stdin, stdout, stderr = ssh.exec_command('curl -s http://localhost:8081/ 2>&1 | head -40')
print("=== 8081 HTTP / ===")
print(stdout.read().decode()[:500])

# Ver si hay un proceso node en el deepracerweb
stdin, stdout, stderr = ssh.exec_command('ls /home/deepracer/Desktop/deepracerweb/backend/')
print("=== BACKEND DIR ===")
print(stdout.read().decode())

# Ver server.js del deepracerweb
stdin, stdout, stderr = ssh.exec_command('cat /home/deepracer/Desktop/deepracerweb/backend/server.js 2>/dev/null | head -30')
print("=== SERVER.JS (deepracerweb) ===")
print(stdout.read().decode())

ssh.close()
