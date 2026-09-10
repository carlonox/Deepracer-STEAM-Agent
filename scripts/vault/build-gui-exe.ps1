# Compila la GUI a un ejecutable Windows (scripts\vault\DeepRacerVault.exe).
# Usa ps2exe (se instala solo si falta, en tu perfil). El .exe NO se versiona.
[CmdletBinding()]
param([string]$Out)

$ErrorActionPreference = 'Stop'
if (-not $Out) { $Out = Join-Path $PSScriptRoot 'DeepRacerVault.exe' }
$gui = Join-Path $PSScriptRoot 'DeepRacerVaultGui.ps1'
if (-not (Test-Path -LiteralPath $gui)) { throw "No existe $gui" }

if (-not (Get-Module -ListAvailable -Name ps2exe)) {
    Write-Host 'Preparando PowerShellGet (NuGet)...'
    if (-not (Get-PackageProvider -Name NuGet -ErrorAction SilentlyContinue)) {
        Install-PackageProvider -Name NuGet -MinimumVersion 2.8.5.201 -Force -Scope CurrentUser | Out-Null
    }
    $repo = Get-PSRepository -Name PSGallery -ErrorAction SilentlyContinue
    if ($repo -and $repo.InstallationPolicy -ne 'Trusted') {
        Set-PSRepository -Name PSGallery -InstallationPolicy Trusted
    }
    Write-Host 'Instalando ps2exe (CurrentUser)...'
    Install-Module ps2exe -Scope CurrentUser -Force -AllowClobber
}
Import-Module ps2exe

Invoke-PS2EXE -InputFile $gui -OutputFile $Out -noConsole `
    -title 'DeepRacer Vault' -description 'Vault local del DeepRacer' `
    -product 'DeepRacer Vault' -company 'carlonox' -version '1.0.0.0'

Write-Host "[exe] generado: $Out" -ForegroundColor Green
Write-Host '[exe] el .exe usa los .ps1 del vault que estan junto a el; mantenlos juntos.'
