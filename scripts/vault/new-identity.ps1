# Crea TU identidad en tu USB (llave privada age cifrada con tu PIN) y la
# registra como destinatario del vault. Cada persona corre esto una vez con SU USB.
[CmdletBinding()]
param(
    [string]$Label = $env:USERNAME,
    [int]$MinPinLength = 6
)

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig

$usb = Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial
if (-not $usb) {
    throw "USB no encontrada (serial de volumen $($Config.UsbVolumeSerial))."
}

$idPath = Get-IdentityPath -DeviceId $usb.DeviceID -Config $Config
if (Test-Path -LiteralPath $idPath) {
    throw "Esta USB ya tiene identidad ($idPath). No la sobrescribo."
}

$pin = Read-VaultPin -Prompt 'PIN para tu identidad'
if ($pin.Length -lt $MinPinLength) { throw "PIN demasiado corto (mínimo $MinPinLength)." }
$pin2 = Read-VaultPin -Prompt 'Repite el PIN'
if ($pin -ne $pin2) { throw "Los PIN no coinciden." }

$publicKey = New-VaultIdentity -UsbIdentityPath $idPath -Pin $pin

$recipients = Get-RecipientsPath -Config $Config
Add-RecipientKey -RecipientsPath $recipients -PublicKey $publicKey -Label $Label

Write-Host "[vault] identidad creada en la USB: $idPath" -ForegroundColor Green
Write-Host "[vault] llave publica: $publicKey"
Write-Host "[vault] registrada en: $recipients"
