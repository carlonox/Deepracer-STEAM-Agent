# Crea/actualiza el vault cifrado (Opción B: USB keyfile + PIN).
# Cifra un archivo .env local (con valores reales) y lo deja como secrets.age.
# El archivo plano de entrada queda a tu cargo: BÓRRALO después de cifrar.
[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$SecretsFile,
    [int]$MinPinLength = 6
)

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig

if (-not (Test-Path -LiteralPath $SecretsFile)) {
    throw "No existe el archivo de secretos: $SecretsFile"
}

$usb = Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial
if (-not $usb) {
    throw "USB no encontrada (serial de volumen $($Config.UsbVolumeSerial)). Sin la llave no se crea el vault."
}

$keyPath = Get-KeyfilePath -DeviceId $usb.DeviceID -RelativePath $Config.UsbKeyfileRelative
$created = New-KeyfileIfMissing -Path $keyPath
if ($created) {
    Write-Host "[vault] keyfile nuevo (64 bytes) en la USB. Esa USB es la llave: no la copies." -ForegroundColor Yellow
} else {
    Write-Host "[vault] reutilizando keyfile existente en la USB."
}

$pin = Read-VaultPin -Prompt 'Nuevo PIN del vault'
if ($pin.Length -lt $MinPinLength) { throw "PIN demasiado corto (mínimo $MinPinLength)." }
$pin2 = Read-VaultPin -Prompt 'Repite el PIN'
if ($pin -ne $pin2) { throw "Los PIN no coinciden." }

$keyBytes = [IO.File]::ReadAllBytes($keyPath)
$pass = Get-VaultPassphrase -KeyfileBytes $keyBytes -Pin $pin

$vaultPath = Get-VaultPath -Config $Config
$vaultDir = Split-Path -Parent $vaultPath
if (-not (Test-Path -LiteralPath $vaultDir)) {
    New-Item -ItemType Directory -Path $vaultDir -Force | Out-Null
}

$plainFull = (Resolve-Path -LiteralPath $SecretsFile).Path
Protect-VaultFile -PlainPath $plainFull -OutPath $vaultPath -Passphrase $pass

Write-Host "[vault] vault cifrado: $vaultPath" -ForegroundColor Green
Write-Host "[vault] pendiente: borra el archivo plano '$plainFull' (contiene los valores reales)." -ForegroundColor Yellow
