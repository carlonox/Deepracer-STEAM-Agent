# stop-deepracer.ps1
# Lanzador compatible: delega en scripts/stop/stop-services.ps1
& (Join-Path $PSScriptRoot "scripts\stop\stop-services.ps1") @args
