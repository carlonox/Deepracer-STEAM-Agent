# stop-deepracer.ps1
Write-Host "=== Deteniendo Deepracer STEAM Agent ===" -ForegroundColor Yellow

# 1. Parar backend (Node.js)
Write-Host "[1/2] Deteniendo backend..." -ForegroundColor Yellow
Get-Process -Name node -ErrorAction SilentlyContinue | Stop-Process -Force
Write-Host "  Backend detenido" -ForegroundColor Green

# 2. Parar Hermes (Docker)
Write-Host "[2/2] Deteniendo Hermes..." -ForegroundColor Yellow
docker compose down
Write-Host "  Hermes detenido" -ForegroundColor Green

Write-Host ""
Write-Host "Todo detenido." -ForegroundColor Green
Write-Host "Para iniciar: .\start-deepracer.ps1" -ForegroundColor Gray