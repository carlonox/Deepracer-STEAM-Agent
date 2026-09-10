# Detiene el backend que arrancó unlock-vault.ps1 y limpia su registro.
[CmdletBinding()]
param()

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig

$stateDir = Get-VaultStateDir -Config $Config
$pidFile = Join-Path $stateDir 'vault.pid'

if (-not (Test-Path -LiteralPath $pidFile)) {
    Write-Host '[vault] no hay backend del vault registrado (nada que bloquear).'
    return
}

$vaultPid = [int]((Get-Content -LiteralPath $pidFile -Raw).Trim())
$proc = Get-Process -Id $vaultPid -ErrorAction SilentlyContinue
if ($proc) {
    Stop-Process -Id $vaultPid -Force
    Write-Host "[vault] backend detenido (PID $vaultPid)." -ForegroundColor Yellow
} else {
    Write-Host "[vault] el proceso $vaultPid ya no estaba vivo; limpio el registro."
}
Remove-Item -LiteralPath $pidFile -Force
