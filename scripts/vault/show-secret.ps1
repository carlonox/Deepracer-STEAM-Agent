# Muestra el valor de UN secreto del vault (p. ej. la password del dashboard).
# Descifra el vault en este proceso y luego imprime la variable pedida.
# OJO: imprime el secreto en pantalla; úsalo en un lugar privado.
[CmdletBinding()]
param([Parameter(Mandatory)][string]$Name)

. (Join-Path $PSScriptRoot 'unlock-vault.ps1')

$item = Get-Item -Path ("Env:" + $Name) -ErrorAction SilentlyContinue
if (-not $item) { throw "El vault no define '$Name'." }
Write-Host ("{0}={1}" -f $Name, $item.Value)
