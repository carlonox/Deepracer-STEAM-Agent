# Vigila la USB del vault: al extraerla, bloquea (mata el backend).
# Al insertarla NO desbloquea solo: el PIN exige consola, así que avisa
# por log para que el operador corra unlock-vault.ps1.
[CmdletBinding()]
param([int]$IntervalSeconds = 2)

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig
$stateDir = Get-VaultStateDir -Config $Config
if (-not (Test-Path -LiteralPath $stateDir)) {
    New-Item -ItemType Directory -Path $stateDir -Force | Out-Null
}
$logPath = Join-Path $stateDir 'watcher.log'

function Write-Log {
    param([string]$Message)
    $line = "{0} {1}" -f (Get-Date -Format 's'), $Message
    Add-Content -LiteralPath $logPath -Value $line
    Write-Host $line
}

$present = [bool](Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial)
Write-Log "watcher iniciado (USB $($Config.UsbVolumeSerial), presente=$present)"

while ($true) {
    Start-Sleep -Seconds $IntervalSeconds
    $now = [bool](Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial)
    if ($now -and -not $present) {
        Write-Log 'USB insertada: corre unlock-vault.ps1 -StartBackend e ingresa el PIN.'
    } elseif (-not $now -and $present) {
        Write-Log 'USB extraida: bloqueando backend del vault.'
        try { & (Join-Path $PSScriptRoot 'lock-vault.ps1') } catch { Write-Log "lock fallo: $_" }
    }
    $present = $now
}
