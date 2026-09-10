# Registra la llave publica de otra persona y re-cifra el vault para incluirla.
# Para REMOVER a alguien, edita recipients.txt (borra sus lineas) y corre
# -ReencryptOnly. Revocar = re-cifrar sin su llave.
[CmdletBinding()]
param(
    [string]$PublicKey,
    [string]$Label,
    [switch]$Remove,
    [switch]$ReencryptOnly
)

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig
$recipients = Get-RecipientsPath -Config $Config
$vaultPath = Get-VaultPath -Config $Config

if (-not $ReencryptOnly) {
    if (-not $PublicKey) { throw "Falta -PublicKey (age1...) o usa -ReencryptOnly." }
    if ($Remove) {
        $lines = Get-Content -LiteralPath $recipients
        $kept = $lines | Where-Object { $_.Trim() -ne $PublicKey }
        Set-Content -LiteralPath $recipients -Value $kept
        Write-Host "[vault] llave removida de $recipients"
    } else {
        if ($PublicKey -notmatch '^age1') { throw "No parece una llave publica age (age1...)." }
        Add-RecipientKey -RecipientsPath $recipients -PublicKey $PublicKey -Label $Label
        Write-Host "[vault] llave agregada a $recipients"
    }
}

if (-not (Test-Path -LiteralPath $vaultPath)) {
    Write-Host "[vault] no hay vault todavía; nada que re-cifrar (corre init-vault.ps1)."
    return
}

# Re-cifrar requiere la identidad del que corre (USB + PIN).
$usb = Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial
if (-not $usb) { throw "Necesitas tu USB puesta para re-cifrar el vault." }
$idPath = Get-IdentityPath -DeviceId $usb.DeviceID -Config $Config
if (-not (Test-Path -LiteralPath $idPath)) { throw "Falta tu identidad en la USB." }

$pin = Read-VaultPin -Prompt 'PIN de tu identidad (para re-cifrar)'
$tmpId = $null
try {
    $tmpId = Get-IdentityTemp -UsbIdentityPath $idPath -Pin $pin
    $text = Unprotect-VaultWithIdentity -InPath $vaultPath -IdentityPath $tmpId
} finally {
    if ($tmpId) { Remove-Item -LiteralPath $tmpId -Force -ErrorAction SilentlyContinue }
}

Protect-VaultTextToRecipients -Text $text -OutPath $vaultPath -RecipientsPath $recipients
$count = @(Get-RecipientKeys -RecipientsPath $recipients).Count
Write-Host "[vault] re-cifrado para $count destinatario(s)." -ForegroundColor Green
