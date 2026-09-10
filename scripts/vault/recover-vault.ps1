# Recupera el vault con la LLAVE DE RECUPERACION (guardada en BWS con 2FA).
# Descifra con esa llave y re-cifra a los destinatarios actuales, para que una
# identidad nueva (new-identity.ps1) pueda volver a abrir el vault.
# No requiere la USB ni el PIN viejo.
[CmdletBinding()]
param()

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig

$vaultPath = Get-VaultPath -Config $Config
if (-not (Test-Path -LiteralPath $vaultPath)) {
    throw "No hay vault en $vaultPath (nada que recuperar)."
}

$secret = (Read-VaultPin -Prompt 'Pega la llave de recuperación (AGE-SECRET-KEY-1...)').Trim()
if ($secret -notmatch '^AGE-SECRET-KEY-1') {
    throw "No parece una llave de recuperación válida (debe empezar con AGE-SECRET-KEY-1)."
}

$tmpId = New-SecureTempFile
try {
    Set-Content -LiteralPath $tmpId -Value $secret -NoNewline -Encoding ascii
    $text = Unprotect-VaultWithIdentity -InPath $vaultPath -IdentityPath $tmpId
} finally {
    Remove-Item -LiteralPath $tmpId -Force -ErrorAction SilentlyContinue
}

$recipients = Get-RecipientsPath -Config $Config
Protect-VaultTextToRecipients -Text $text -OutPath $vaultPath -RecipientsPath $recipients
$count = @(Get-RecipientKeys -RecipientsPath $recipients).Count
Write-Host "[vault] vault re-cifrado para $count destinatario(s)." -ForegroundColor Green
Write-Host '[vault] ahora corre unlock-vault.ps1 con tu PIN (tu identidad nueva ya abre el vault).'
