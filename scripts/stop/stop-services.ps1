# scripts/stop/stop-services.ps1
# Detiene SOLO los procesos iniciados por el proyecto.
# No mata procesos node no relacionados.

$ErrorActionPreference = "Stop"
$PidFile = Join-Path $env:TEMP "deepracer-backend.pid"

Write-Host "=== Deteniendo Deepracer STEAM Agent ===" -ForegroundColor Yellow

# 1. Parar backend (Node.js) usando el PID registrado al iniciar
Write-Host "[1/2] Deteniendo backend..." -ForegroundColor Yellow
if (Test-Path $PidFile) {
    $pid = Get-Content $PidFile -ErrorAction SilentlyContinue
    if ($pid -and (Get-Process -Id $pid -ErrorAction SilentlyContinue)) {
        Stop-Process -Id $pid -Force
        Write-Host "  Backend detenido (PID $pid)" -ForegroundColor Green
    } else {
        Write-Host "  Backend no estaba en ejecucion (PID $pid inexistente)" -ForegroundColor Gray
    }
    Remove-Item $PidFile -ErrorAction SilentlyContinue
} else {
    Write-Host "  No hay PID registrado del backend del proyecto; no se matan procesos." -ForegroundColor Gray
}

# 2. Parar Hermes (Docker)
Write-Host "[2/2] Deteniendo Hermes..." -ForegroundColor Yellow
docker compose down
Write-Host "  Hermes detenido" -ForegroundColor Green

Write-Host ""
Write-Host "Todo detenido." -ForegroundColor Green
Write-Host "Para iniciar: .\start-deepracer.ps1" -ForegroundColor Gray
