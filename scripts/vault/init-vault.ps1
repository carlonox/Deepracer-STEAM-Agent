# Cifra un archivo .env local hacia TODOS los destinatarios del vault.
# No pide PIN: usa las llaves publicas de recipients.txt (deriva de identidades
# ya creadas con new-identity.ps1). El archivo plano se borra tras cifrar.
[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$SecretsFile
)

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig

if (-not (Test-Path -LiteralPath $SecretsFile)) {
    throw "No existe el archivo de secretos: $SecretsFile"
}

$recipients = Get-RecipientsPath -Config $Config
$keys = @(Get-RecipientKeys -RecipientsPath $recipients)
if ($keys.Count -eq 0) {
    throw "No hay destinatarios en $recipients. Corre new-identity.ps1 con tu USB primero."
}

$vaultPath = Get-VaultPath -Config $Config
$plainFull = (Resolve-Path -LiteralPath $SecretsFile).Path
Protect-VaultFileToRecipients -PlainPath $plainFull -OutPath $vaultPath -RecipientsPath $recipients

Write-Host "[vault] cifrado para $($keys.Count) destinatario(s): $vaultPath" -ForegroundColor Green
Write-Host "[vault] pendiente: borra el archivo plano '$plainFull'." -ForegroundColor Yellow
