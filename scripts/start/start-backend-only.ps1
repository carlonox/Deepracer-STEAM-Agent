# scripts/start/start-backend-only.ps1
# Arranca SOLO el backend del proyecto (sin Docker, sin tocar Hermes/el agente).
# Registra el PID para que stop-services.ps1 pueda matarlo, y escribe el
# resultado del healthcheck en <raiz>/diagnostico.txt.

$ErrorActionPreference = "Stop"
$RootDir = Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
$BackendDir = [System.IO.Path]::GetFullPath((Join-Path $RootDir "apps\backend"))
$PidFile = Join-Path $env:TEMP "deepracer-backend.pid"
$OutFile = Join-Path $RootDir "diagnostico.txt"

try {
    $proc = Start-Process -FilePath "node" -ArgumentList "server.js" `
        -WorkingDirectory $BackendDir -WindowStyle Minimized -PassThru
    "BACKEND_PID=$($proc.Id)" | Out-File $OutFile -Encoding utf8
    $proc.Id | Set-Content $PidFile
    Start-Sleep -Seconds 4
} catch {
    "START_ERROR: $($_.Exception.Message)" | Out-File $OutFile -Encoding utf8
    exit 1
}

try {
    $r = Invoke-RestMethod -Uri http://localhost:5002/api/health -TimeoutSec 5 -ErrorAction Stop
    "HEALTH_OK: $($r | ConvertTo-Json -Compress)" | Out-File $OutFile -Encoding utf8 -Append
} catch {
    "HEALTH_ERROR: $($_.Exception.Message)" | Out-File $OutFile -Encoding utf8 -Append
}
