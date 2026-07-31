# start-deepracer.ps1
# Lanzador compatible: delega en scripts/start/start-services.ps1
& (Join-Path $PSScriptRoot "scripts\start\start-services.ps1") @args
