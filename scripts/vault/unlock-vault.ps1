# Descifra el vault con TU identidad (USB + PIN) y arranca el backend.
[CmdletBinding()]
param(
    [switch]$StartBackend,
    [string]$RepoRoot = (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
)

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig

$usb = Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial
if (-not $usb) {
    throw "USB no encontrada (serial de volumen $($Config.UsbVolumeSerial)). Sin tu llave no hay vault."
}

$idPath = Get-IdentityPath -DeviceId $usb.DeviceID -Config $Config
if (-not (Test-Path -LiteralPath $idPath)) {
    throw "Falta tu identidad en la USB ($idPath). Corre new-identity.ps1."
}

$vaultPath = Get-VaultPath -Config $Config
if (-not (Test-Path -LiteralPath $vaultPath)) {
    throw "No hay vault cifrado en $vaultPath. Corre init-vault.ps1."
}

$pin = Read-VaultPin -Prompt 'PIN de tu identidad'
$tmpId = $null
try {
    $tmpId = Get-IdentityTemp -UsbIdentityPath $idPath -Pin $pin
    $text = Unprotect-VaultWithIdentity -InPath $vaultPath -IdentityPath $tmpId
} finally {
    if ($tmpId) { Remove-Item -LiteralPath $tmpId -Force -ErrorAction SilentlyContinue }
}

$map = ConvertFrom-EnvText -Text $text
foreach ($k in $map.Keys) {
    Set-Item -Path ("Env:" + $k) -Value $map[$k]
}
Write-Host "[vault] secretos cargados en este proceso: $($map.Keys -join ', ')" -ForegroundColor Green

if ($StartBackend) {
    $server = Join-Path $RepoRoot $Config.BackendRelative
    if (-not (Test-Path -LiteralPath $server)) {
        throw "No encontré el backend: $server"
    }
    $proc = Start-Process -FilePath 'node' -ArgumentList @($server) `
        -WorkingDirectory (Split-Path -Parent $server) -PassThru
    $stateDir = Get-VaultStateDir -Config $Config
    Set-Content -LiteralPath (Join-Path $stateDir 'vault.pid') -Value $proc.Id -Encoding ascii
    Write-Host "[vault] backend arrancado con secretos inyectados (PID $($proc.Id))." -ForegroundColor Green
}
