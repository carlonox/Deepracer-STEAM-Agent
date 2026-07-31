# scripts/diagnostics/health-check.ps1
# Verificaciones seguras: no activa hardware ni mueve el vehículo.

Write-Host "=== Diagnóstico seguro Deepracer STEAM Agent ===" -ForegroundColor Cyan

# 1. Docker
try {
    $docker = docker info 2>$null
    if ($docker) { Write-Host "  Docker: OK" -ForegroundColor Green } else { Write-Host "  Docker: NO disponible" -ForegroundColor Red }
} catch { Write-Host "  Docker: NO disponible" -ForegroundColor Red }

# 2. Dashboard Hermes (puerto 9999)
try {
    $r = Invoke-WebRequest -Uri http://localhost:9999/login -MaximumRedirection 0 -TimeoutSec 5 -ErrorAction Stop
    Write-Host "  Hermes (9999): OK ($($r.StatusCode))" -ForegroundColor Green
} catch { Write-Host "  Hermes (9999): ERROR" -ForegroundColor Red }

# 3. Backend /api/health (sin hardware)
try {
    $h = Invoke-RestMethod -Uri http://localhost:5002/api/health -TimeoutSec 5 -ErrorAction Stop
    Write-Host "  Backend (5002): OK - $($h.service) uptime $($h.uptime_s)s" -ForegroundColor Green
} catch { Write-Host "  Backend (5002): ERROR" -ForegroundColor Red }

# 4. Canal TCP 5003 (sin enviar comandos)
$tcp = New-Object System.Net.Sockets.TcpClient
try {
    $tcp.Connect("127.0.0.1", 5003)
    Write-Host "  Canal TCP (5003): OK" -ForegroundColor Green
} catch { Write-Host "  Canal TCP (5003): ERROR" -ForegroundColor Red }
finally { $tcp.Close() }

Write-Host ""
Write-Host "Para controlar el vehículo se requiere autorización explícita y" -ForegroundColor Yellow
Write-Host "operador presente; este diagnóstico nunca lo hace." -ForegroundColor Yellow
