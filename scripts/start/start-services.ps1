# scripts/start/start-services.ps1
# Arranca los servicios del proyecto SIN preparar el vehículo.
# No llama /api/start, /api/manual_drive ni comandos SSH de movimiento.
param(
    [switch]$SkipBuild
)

$ErrorActionPreference = "Stop"
$BackendDir = Join-Path $PSScriptRoot "..\..\apps\backend"
$BackendDir = [System.IO.Path]::GetFullPath($BackendDir)
$PidFile = Join-Path $env:TEMP "deepracer-backend.pid"

Write-Host "=== Deepracer STEAM Agent - Servicios ===" -ForegroundColor Cyan

# 1. Verificar Docker Desktop
Write-Host "[1/4] Verificando Docker Desktop..." -ForegroundColor Yellow
if (-not (docker info 2>$null)) {
    Write-Host "  Iniciando Docker Desktop..." -ForegroundColor Yellow
    Start-Process "C:\Program Files\Docker\Docker\Docker Desktop.exe"
    $timeout = 60
    while ($timeout -gt 0 -and -not (docker info 2>$null)) {
        Start-Sleep -Seconds 2
        $timeout -= 2
        Write-Host "  Esperando Docker... ($timeout s)" -ForegroundColor Gray
    }
    if (-not (docker info 2>$null)) {
        Write-Host "  ERROR: Docker Desktop no arranco" -ForegroundColor Red
        exit 1
    }
}
Write-Host "  Docker OK" -ForegroundColor Green

# 2. Construir imagen si es necesario
Write-Host "[2/4] Verificando imagen..." -ForegroundColor Yellow
if (-not $SkipBuild) {
    docker compose build hermes 2>$null
}
Write-Host "  Imagen OK" -ForegroundColor Green

# 3. Iniciar Hermes en gateway mode
Write-Host "[3/4] Iniciando Hermes (gateway mode)..." -ForegroundColor Yellow
docker compose up -d hermes
Start-Sleep -Seconds 8
if (-not (docker compose ps --status running --services | Select-String -SimpleMatch "hermes")) {
    Write-Host "  ERROR: Hermes no quedo en ejecucion" -ForegroundColor Red
    docker compose logs --tail 80 hermes
    exit 1
}
Write-Host "  Hermes iniciado" -ForegroundColor Green

# 4. Iniciar backend (NO toca el vehículo; solo abre puertos 5002/5003)
Write-Host "[4/4] Iniciando backend (puerto 5002)..." -ForegroundColor Yellow
if (Test-Path $PidFile) {
    $oldPid = Get-Content $PidFile -ErrorAction SilentlyContinue
    if ($oldPid -and (Get-Process -Id $oldPid -ErrorAction SilentlyContinue)) {
        Write-Host "  Backend ya en ejecucion (PID $oldPid)" -ForegroundColor Yellow
        exit 0
    }
}
$proc = Start-Process -FilePath "node" -ArgumentList "server.js" `
    -WorkingDirectory $BackendDir -WindowStyle Minimized -PassThru
$proc.Id | Set-Content $PidFile
Start-Sleep -Seconds 3
Write-Host "  Backend iniciado (PID $($proc.Id))" -ForegroundColor Green

# 5. Verificación segura (healthcheck, sin hardware)
Write-Host ""
Write-Host "=== Verificando servicios ===" -ForegroundColor Cyan
try {
    $hermes = Invoke-WebRequest -Uri http://localhost:9999/login -MaximumRedirection 0 -TimeoutSec 5 -ErrorAction Stop
    Write-Host "  Hermes: OK" -ForegroundColor Green
} catch {
    Write-Host "  Hermes: ERROR (revisa docker compose logs hermes)" -ForegroundColor Red
}
try {
    $health = Invoke-RestMethod -Uri http://localhost:5002/api/health -TimeoutSec 5 -ErrorAction Stop
    Write-Host "  Backend: OK ($($health.service), uptime $($health.uptime_s)s)" -ForegroundColor Green
} catch {
    Write-Host "  Backend: ERROR (revisa la ventana de node)" -ForegroundColor Red
}

Write-Host ""
Write-Host "=== Servicios activos ===" -ForegroundColor Cyan
Write-Host "  Dashboard:  http://localhost:9999" -ForegroundColor White
Write-Host "  API:        http://localhost:8642" -ForegroundColor White
Write-Host "  Backend:    http://localhost:5002" -ForegroundColor White
Write-Host "  Healthcheck: http://localhost:5002/api/health" -ForegroundColor White
Write-Host ""
Write-Host "Para detener: .\stop-deepracer.ps1" -ForegroundColor Gray
Write-Host "ADVERTENCIA: este script NO prepara el vehículo. Para manejar el" -ForegroundColor Yellow
Write-Host "DeepRacer usa la interfaz web o el backend con autorización explícita." -ForegroundColor Yellow
