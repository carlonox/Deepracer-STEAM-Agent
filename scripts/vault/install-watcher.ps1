# Registra el watcher del vault para que arranque al iniciar sesión.
# Si falla por permisos, corré esta consola como el mismo usuario o como admin.
[CmdletBinding()]
param([string]$TaskName = 'DeepRacerVaultWatcher')

$watchScript = Join-Path $PSScriptRoot 'watch-vault.ps1'
if (-not (Test-Path -LiteralPath $watchScript)) {
    throw "No existe $watchScript"
}

$action = New-ScheduledTaskAction -Execute 'powershell.exe' `
    -Argument "-NoProfile -WindowStyle Hidden -ExecutionPolicy Bypass -File `"$watchScript`""
$trigger = New-ScheduledTaskTrigger -AtLogOn
$principal = New-ScheduledTaskPrincipal -UserId "$env:USERDOMAIN\$env:USERNAME" -LogonType Interactive
$settings = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries `
    -DontStopIfGoingOnBatteries -StartWhenAvailable `
    -RestartCount 3 -RestartInterval (New-TimeSpan -Minutes 1)

$task = New-ScheduledTask -Action $action -Trigger $trigger `
    -Principal $principal -Settings $settings
Register-ScheduledTask -TaskName $TaskName -InputObject $task -Force | Out-Null

Write-Host "[vault] tarea '$TaskName' registrada. Arranca al iniciar sesión." -ForegroundColor Green
Write-Host "[vault] para quitarla:  Unregister-ScheduledTask -TaskName $TaskName -Confirm:`$false"
