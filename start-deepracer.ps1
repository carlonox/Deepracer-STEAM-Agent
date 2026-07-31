# start-deepracer.ps1
Write-Host "=== Deepracer STEAM Agent ===" -ForegroundColor Cyan

# 1. Verificar Docker Desktop
Write-Host "[1/5] Verificando Docker Desktop..." -ForegroundColor Yellow
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
Write-Host "[2/5] Verificando imagen..." -ForegroundColor Yellow
docker compose build hermes 2>$null
Write-Host "  Imagen OK" -ForegroundColor Green

# 3. Iniciar Hermes en gateway mode
Write-Host "[3/5] Iniciando Hermes (gateway mode)..." -ForegroundColor Yellow
docker compose up -d hermes
Start-Sleep -Seconds 8
if (-not (docker compose ps --status running --services | Select-String -SimpleMatch "hermes")) {
    Write-Host "  ERROR: Hermes no quedo en ejecucion" -ForegroundColor Red
    docker compose logs --tail 80 hermes
    exit 1
}
Write-Host "  Hermes iniciado" -ForegroundColor Green

# 4. Iniciar backend
Write-Host "[4/5] Iniciando backend (puerto 5002)..." -ForegroundColor Yellow
Start-Process -FilePath "node" -ArgumentList "server.js" -WorkingDirectory "$PSScriptRoot\backend" -WindowStyle Minimized
Start-Sleep -Seconds 3
Write-Host "  Backend iniciado" -ForegroundColor Green

# 5. Verificar
Write-Host "[5/5] Verificando servicios..." -ForegroundColor Yellow

try {
    # El dashboard siempre esta disponible cuando HERMES_DASHBOARD=1. La API
    # del agente en 8642 puede estar deshabilitada en versiones nuevas.
    $hermes = Invoke-WebRequest -Uri http://localhost:9999/login -MaximumRedirection 0 -TimeoutSec 5 -ErrorAction Stop
    Write-Host "  Hermes: OK" -ForegroundColor Green
} catch {
    Write-Host "  Hermes: ERROR (revisa docker compose logs hermes)" -ForegroundColor Red
}

try {
    $backend = Invoke-RestMethod -Uri http://localhost:5002/api/start -Method POST -TimeoutSec 5 -ErrorAction Stop
    Write-Host "  Backend: OK" -ForegroundColor Green
} catch {
    Write-Host "  Backend: ERROR (revisa la ventana de node)" -ForegroundColor Red
}

Write-Host ""
Write-Host "=== Servicios activos ===" -ForegroundColor Cyan
Write-Host "  Dashboard:  http://localhost:9999" -ForegroundColor White
Write-Host "  API:        http://localhost:8642" -ForegroundColor White
Write-Host "  Backend:    http://localhost:5002" -ForegroundColor White
Write-Host ""
Write-Host "Para detener: .\stop-deepracer.ps1" -ForegroundColor Gray
