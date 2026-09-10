# Descifra el vault y arranca el backend con los secretos inyectados.
# Requiere la USB (identificada por serial de volumen) + el PIN.
[CmdletBinding()]
param(
    [switch]$StartBackend,
    [string]$RepoRoot = (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
)

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig

$usb = Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial
if (-not $usb) {
    throw "USB no encontrada (serial de volumen $($Config.UsbVolumeSerial)). Sin la llave no hay vault."
}

$keyPath = Get-KeyfilePath -DeviceId $usb.DeviceID -RelativePath $Config.UsbKeyfileRelative
if (-not (Test-Path -LiteralPath $keyPath)) {
    throw "Falta el keyfile en la USB: $keyPath"
}

$vaultPath = Get-VaultPath -Config $Config
if (-not (Test-Path -LiteralPath $vaultPath)) {
    throw "No hay vault cifrado en $vaultPath. Corre primero init-vault.ps1."
}

$keyBytes = [IO.File]::ReadAllBytes($keyPath)
$pin = Read-VaultPin -Prompt 'PIN del vault'
$pass = Get-VaultPassphrase -KeyfileBytes $keyBytes -Pin $pin

try {
    $text = Unprotect-VaultFile -InPath $vaultPath -Passphrase $pass
} catch {
    throw "No se pudo descifrar: PIN o keyfile incorrectos (o USB equivocada)."
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
