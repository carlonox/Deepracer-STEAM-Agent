# Crea una LLAVE DE RECUPERACION (identidad age sin PIN) y la registra como
# destinatario. Guarda la clave que imprime en BWS (con 2FA) y no la pierdas:
# sirve para re-cifrar el vault si alguien olvida su PIN.
[CmdletBinding()]
param([string]$Label = 'recovery')

. (Join-Path $PSScriptRoot 'vault-common.ps1')
$Config = Get-VaultConfig

$r = New-RawIdentity
if ($r.PublicKey -notmatch '^age1') { throw "No pude generar la identidad de recuperación." }

$recipients = Get-RecipientsPath -Config $Config
Add-RecipientKey -RecipientsPath $recipients -PublicKey $r.PublicKey -Label $Label
Write-Host "[vault] llave de recuperación agregada a $recipients" -ForegroundColor Green
Write-Host ''
Write-Host 'GUARDA ESTA CLAVE EN BWS (con 2FA). No se vuelve a mostrar:' -ForegroundColor Yellow
Write-Host $r.Secret
Write-Host ''

$vaultPath = Get-VaultPath -Config $Config
if (Test-Path -LiteralPath $vaultPath) {
    Write-Host '[vault] re-cifrando el vault para incluir la llave de recuperación...'
    & (Join-Path $PSScriptRoot 'add-recipient.ps1') -ReencryptOnly
} else {
    Write-Host '[vault] no hay vault todavía; quedará incluida en el próximo init-vault.ps1.'
}
