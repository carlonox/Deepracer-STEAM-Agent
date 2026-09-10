# Helpers compartidos del vault local (Opción B: USB keyfile + PIN).
# NO contiene secretos: solo rutas, identificación de la USB y KDF.
# Uso: dot-source desde los scripts del vault:  . .\vault-common.ps1
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

function Get-VaultConfig {
    Import-PowerShellDataFile -LiteralPath (Join-Path $PSScriptRoot 'vault.config.psd1')
}

function Get-AgeExe {
    $cmd = Get-Command age.exe -ErrorAction SilentlyContinue
    if ($cmd) {
        $dir = Split-Path -Parent $cmd.Source
    } else {
        $link = Join-Path $env:LOCALAPPDATA 'Microsoft\WinGet\Links\age.exe'
        if (Test-Path -LiteralPath $link) { $dir = Split-Path -Parent $link }
    }
    if (-not $dir) {
        throw "age.exe no encontrado. Instalalo con: winget install --id FiloSottile.age"
    }
    # age busca sus plugins (age-plugin-*) en PATH; winget actualiza el PATH
    # persistente pero no la sesión abierta, así que lo agregamos aquí.
    if (($env:PATH -split ';') -notcontains $dir) { $env:PATH = "$dir;$env:PATH" }
    return (Join-Path $dir 'age.exe')
}

function Get-UsbVolume {
    param([Parameter(Mandatory)][string]$VolumeSerial)
    Get-CimInstance Win32_LogicalDisk -Filter 'DriveType=2' |
        Where-Object { $_.VolumeSerialNumber -eq $VolumeSerial }
}

function Get-KeyfilePath {
    param(
        [Parameter(Mandatory)][string]$DeviceId,
        [Parameter(Mandatory)][string]$RelativePath
    )
    Join-Path ($DeviceId.TrimEnd('\') + '\') $RelativePath
}

function New-KeyfileIfMissing {
    param([Parameter(Mandatory)][string]$Path, [int]$Length = 64)
    if (Test-Path -LiteralPath $Path) { return $false }
    $parent = Split-Path -Parent $Path
    if (-not (Test-Path -LiteralPath $parent)) {
        New-Item -ItemType Directory -Path $parent -Force | Out-Null
    }
    $bytes = New-Object byte[] $Length
    $rng = [Security.Cryptography.RNGCryptoServiceProvider]::Create()
    try { $rng.GetBytes($bytes) } finally { $rng.Dispose() }
    [IO.File]::WriteAllBytes($Path, $bytes)
    return $true
}

function Get-VaultPassphrase {
    # passphrase = Base64(HMAC-SHA256(keyfile, PIN)); age le aplica scrypt encima.
    param(
        [Parameter(Mandatory)][byte[]]$KeyfileBytes,
        [Parameter(Mandatory)][string]$Pin
    )
    $hmac = [Security.Cryptography.HMACSHA256]::new($KeyfileBytes)
    try {
        $hash = $hmac.ComputeHash([Text.Encoding]::UTF8.GetBytes($Pin))
        return [Convert]::ToBase64String($hash)
    } finally { $hmac.Dispose() }
}

function Read-VaultPin {
    param([string]$Prompt = 'PIN del vault')
    $secure = Read-Host -Prompt $Prompt -AsSecureString
    $bstr = [Runtime.InteropServices.Marshal]::SecureStringToBSTR($secure)
    try { return [Runtime.InteropServices.Marshal]::PtrToStringBSTR($bstr) }
    finally { [Runtime.InteropServices.Marshal]::ZeroFreeBSTR($bstr) }
}

function Get-VaultPath {
    param([Parameter(Mandatory)]$Config)
    Join-Path (Join-Path $env:LOCALAPPDATA $Config.VaultDirectory) $Config.VaultFileName
}

function Get-VaultStateDir {
    param([Parameter(Mandatory)]$Config)
    Join-Path $env:LOCALAPPDATA $Config.VaultDirectory
}

function ConvertFrom-EnvText {
    # ".env" -> ordered hashtable; ignora vacías y comentarios.
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

function Protect-VaultFile {
    param(
        [Parameter(Mandatory)][string]$PlainPath,
        [Parameter(Mandatory)][string]$OutPath,
        [Parameter(Mandatory)][string]$Passphrase
    )
    $age = Get-AgeExe
    $env:AGE_PASSPHRASE = $Passphrase
    try {
        & $age --encrypt --armor -j batchpass -o $OutPath $PlainPath
        if ($LASTEXITCODE -ne 0) { throw "age falló al cifrar (código $LASTEXITCODE)" }
    } finally { Remove-Item Env:AGE_PASSPHRASE -ErrorAction SilentlyContinue }
}

function Unprotect-VaultFile {
    param(
        [Parameter(Mandatory)][string]$InPath,
        [Parameter(Mandatory)][string]$Passphrase
    )
    $age = Get-AgeExe
    $env:AGE_PASSPHRASE = $Passphrase
    try {
        $out = & $age --decrypt -j batchpass $InPath
        if ($LASTEXITCODE -ne 0) { throw "age falló al descifrar (código $LASTEXITCODE)" }
        return ($out -join "`n")
    } finally { Remove-Item Env:AGE_PASSPHRASE -ErrorAction SilentlyContinue }
}
