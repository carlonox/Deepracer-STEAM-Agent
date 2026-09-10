# Helpers compartidos del vault local (modelo por persona).
# Cada persona tiene una identidad age (llave privada) cifrada con su PIN en
# su USB; el vault se cifra a la UNION de llaves publicas (recipients.txt).
# NO contiene secretos: solo rutas, identificacion de la USB y helpers age.
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

function Get-VaultConfig {
    Import-PowerShellDataFile -LiteralPath (Join-Path $PSScriptRoot 'vault.config.psd1')
}

function Get-AgeDir {
    $cmd = Get-Command age.exe -ErrorAction SilentlyContinue
    if ($cmd) { $dir = Split-Path -Parent $cmd.Source }
    else {
        $link = Join-Path $env:LOCALAPPDATA 'Microsoft\WinGet\Links\age.exe'
        if (Test-Path -LiteralPath $link) { $dir = Split-Path -Parent $link }
    }
    if (-not $dir) {
        throw "age.exe no encontrado. Instalalo con: winget install --id FiloSottile.age"
    }
    # age busca sus plugins (age-plugin-*) en PATH; winget actualiza el PATH
    # persistente pero no la sesión abierta, así que lo agregamos aquí.
    if (($env:PATH -split ';') -notcontains $dir) { $env:PATH = "$dir;$env:PATH" }
    return $dir
}

function Get-AgeExe { Join-Path (Get-AgeDir) 'age.exe' }
function Get-AgeKeygen { Join-Path (Get-AgeDir) 'age-keygen.exe' }

# Los binarios (age/age-keygen) escriben avisos a stderr; con ErrorActionPreference
# Stop eso abortaría el script. Este wrapper los corre con preferencia Continue y
# devuelve el exit code (o el stdout con -CaptureOutput).
function Invoke-Native {
    param(
        [Parameter(Mandatory)][string]$FilePath,
        [string[]]$Arguments = @(),
        [switch]$CaptureOutput
    )
    $prev = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try {
        if ($CaptureOutput) { $output = & $FilePath @Arguments 2>$null }
        else { $null = & $FilePath @Arguments 2>&1 }
        $code = $LASTEXITCODE
    } finally { $ErrorActionPreference = $prev }
    if ($CaptureOutput) { return [pscustomobject]@{ Code = $code; Output = @($output) } }
    return $code
}

function New-SecureTempFile {
    # Temp dentro del perfil del usuario (no en TEMP compartido), para reducir
    # la exposición del material de llave mientras se descifra.
    $dir = Join-Path $env:LOCALAPPDATA 'DeepRacerVault\.tmp'
    if (-not (Test-Path -LiteralPath $dir)) { New-Item -ItemType Directory -Path $dir -Force | Out-Null }
    return (Join-Path $dir ([IO.Path]::GetRandomFileName()))
}

function Get-UsbVolume {
    param([Parameter(Mandatory)][string]$VolumeSerial)
    Get-CimInstance Win32_LogicalDisk -Filter 'DriveType=2' |
        Where-Object { $_.VolumeSerialNumber -eq $VolumeSerial }
}

function Get-IdentityPath {
    param([Parameter(Mandatory)][string]$DeviceId, [Parameter(Mandatory)]$Config)
    Join-Path ($DeviceId.TrimEnd('\') + '\') $Config.UsbIdentityRelative
}

function Get-VaultPath {
    param([Parameter(Mandatory)]$Config)
    Join-Path (Join-Path $env:LOCALAPPDATA $Config.VaultDirectory) $Config.VaultFileName
}

function Get-VaultStateDir {
    param([Parameter(Mandatory)]$Config)
    Join-Path $env:LOCALAPPDATA $Config.VaultDirectory
}

function Get-RecipientsPath {
    param([Parameter(Mandatory)]$Config)
    Join-Path (Get-VaultStateDir -Config $Config) $Config.RecipientsFileName
}

function Read-VaultPin {
    param([string]$Prompt = 'PIN del vault')
    $secure = Read-Host -Prompt $Prompt -AsSecureString
    $bstr = [Runtime.InteropServices.Marshal]::SecureStringToBSTR($secure)
    try { return [Runtime.InteropServices.Marshal]::PtrToStringBSTR($bstr) }
    finally { [Runtime.InteropServices.Marshal]::ZeroFreeBSTR($bstr) }
}

function Get-RecipientKeys {
    param([Parameter(Mandatory)][string]$RecipientsPath)
    if (-not (Test-Path -LiteralPath $RecipientsPath)) { return @() }
    Get-Content -LiteralPath $RecipientsPath |
        ForEach-Object { $_.Trim() } |
        Where-Object { $_ -and -not $_.StartsWith('#') }
}

function Add-RecipientKey {
    param(
        [Parameter(Mandatory)][string]$RecipientsPath,
        [Parameter(Mandatory)][string]$PublicKey,
        [string]$Label
    )
    $dir = Split-Path -Parent $RecipientsPath
    if (-not (Test-Path -LiteralPath $dir)) { New-Item -ItemType Directory -Path $dir -Force | Out-Null }
    $line = if ($Label) { "# $Label`n$PublicKey" } else { $PublicKey }
    Add-Content -LiteralPath $RecipientsPath -Value $line
}

function New-VaultIdentity {
    # Genera identidad age, la cifra con el PIN en la USB y devuelve la publica.
    param(
        [Parameter(Mandatory)][string]$UsbIdentityPath,
        [Parameter(Mandatory)][string]$Pin
    )
    $age = Get-AgeExe
    $keygen = Get-AgeKeygen
    $dir = Split-Path -Parent $UsbIdentityPath
    if (-not (Test-Path -LiteralPath $dir)) { New-Item -ItemType Directory -Path $dir -Force | Out-Null }

    $tmp = New-SecureTempFile
    try {
        if ((Invoke-Native -FilePath $keygen -Arguments @('-o', $tmp)) -ne 0) {
            throw "age-keygen falló"
        }
        $pub = Invoke-Native -FilePath $keygen -Arguments @('-y', $tmp) -CaptureOutput
        if ($pub.Code -ne 0) { throw "age-keygen -y falló" }
        $publicKey = ($pub.Output -join "`n").Trim()
        if ($publicKey -notmatch '^age1') { throw "No pude obtener la llave publica" }

        $env:AGE_PASSPHRASE = $Pin
        try {
            $code = Invoke-Native -FilePath $age -Arguments @('--encrypt', '--armor', '-j', 'batchpass', '-o', $UsbIdentityPath, $tmp)
            if ($code -ne 0) { throw "age falló al cifrar la identidad" }
        } finally { Remove-Item Env:AGE_PASSPHRASE -ErrorAction SilentlyContinue }
        return $publicKey
    } finally { Remove-Item -LiteralPath $tmp -Force -ErrorAction SilentlyContinue }
}

function Get-IdentityTemp {
    # Descifra la identidad de la USB a un temp y devuelve su ruta (borrar luego).
    param(
        [Parameter(Mandatory)][string]$UsbIdentityPath,
        [Parameter(Mandatory)][string]$Pin
    )
    $age = Get-AgeExe
    $tmp = New-SecureTempFile
    $env:AGE_PASSPHRASE = $Pin
    try {
        $code = Invoke-Native -FilePath $age -Arguments @('--decrypt', '-j', 'batchpass', '-o', $tmp, $UsbIdentityPath)
    } finally { Remove-Item Env:AGE_PASSPHRASE -ErrorAction SilentlyContinue }
    if ($code -ne 0) {
        Remove-Item -LiteralPath $tmp -Force -ErrorAction SilentlyContinue
        throw "No se pudo descifrar la identidad (PIN incorrecto o USB equivocada)."
    }
    return $tmp
}

function ConvertFrom-EnvText {
    param([Parameter(Mandatory)][string]$Text)
    $map = [ordered]@{}
    foreach ($line in ($Text -split "`r?`n")) {
        $t = $line.Trim()
        if (-not $t -or $t.StartsWith('#')) { continue }
        $i = $t.IndexOf('=')
        if ($i -lt 1) { continue }
        $map[$t.Substring(0, $i).Trim()] = $t.Substring($i + 1).Trim()
    }
    return $map
}

function Protect-VaultFileToRecipients {
    param(
        [Parameter(Mandatory)][string]$PlainPath,
        [Parameter(Mandatory)][string]$OutPath,
        [Parameter(Mandatory)][string]$RecipientsPath
    )
    $age = Get-AgeExe
    $dir = Split-Path -Parent $OutPath
    if (-not (Test-Path -LiteralPath $dir)) { New-Item -ItemType Directory -Path $dir -Force | Out-Null }
    $code = Invoke-Native -FilePath $age -Arguments @('--encrypt', '--armor', '-R', $RecipientsPath, '-o', $OutPath, $PlainPath)
    if ($code -ne 0) { throw "age falló al cifrar" }
}

function Protect-VaultTextToRecipients {
    param(
        [Parameter(Mandatory)][string]$Text,
        [Parameter(Mandatory)][string]$OutPath,
        [Parameter(Mandatory)][string]$RecipientsPath
    )
    $age = Get-AgeExe
    $prev = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try {
        $Text | & $age --encrypt --armor -R $RecipientsPath -o $OutPath 2>$null
        $code = $LASTEXITCODE
    } finally { $ErrorActionPreference = $prev }
    if ($code -ne 0) { throw "age falló al re-cifrar" }
}

function Unprotect-VaultWithIdentity {
    param(
        [Parameter(Mandatory)][string]$InPath,
        [Parameter(Mandatory)][string]$IdentityPath
    )
    $age = Get-AgeExe
    $r = Invoke-Native -FilePath $age -Arguments @('--decrypt', '-i', $IdentityPath, $InPath) -CaptureOutput
    if ($r.Code -ne 0) { throw "age falló al descifrar" }
    return ($r.Output -join "`n")
}
