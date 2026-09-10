# GUI local del vault (WinForms, sin dependencias ni web).
# Desbloquea con tu USB + PIN, lista los secretos, y arranca/para backend y Hermes.
# Uso:  powershell -ExecutionPolicy Bypass -File scripts\vault\DeepRacerVaultGui.ps1
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

. (Join-Path $PSScriptRoot 'vault-common.ps1')

$Config = Get-VaultConfig
$RepoRoot = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
$script:SecretMap = $null   # hashtable en memoria; nunca a disco

function Unlock-VaultGui {
    param([string]$Pin)
    $usb = Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial
    if (-not $usb) { throw "USB no encontrada (serial $($Config.UsbVolumeSerial))." }
    $idPath = Get-IdentityPath -DeviceId $usb.DeviceID -Config $Config
    if (-not (Test-Path -LiteralPath $idPath)) { throw "Falta identity.age en la USB." }
    $vaultPath = Get-VaultPath -Config $Config
    if (-not (Test-Path -LiteralPath $vaultPath)) { throw "No hay vault cifrado ($vaultPath)." }
    $tmpId = $null
    try {
        $tmpId = Get-IdentityTemp -UsbIdentityPath $idPath -Pin $Pin
        $text = Unprotect-VaultWithIdentity -InPath $vaultPath -IdentityPath $tmpId
    } finally { if ($tmpId) { Remove-Item -LiteralPath $tmpId -Force -ErrorAction SilentlyContinue } }
    $map = ConvertFrom-EnvText -Text $text
    foreach ($k in $map.Keys) { Set-Item -Path ("Env:" + $k) -Value $map[$k] }
    return $map
}

function Start-VaultBackend {
    $server = Join-Path $RepoRoot $Config.BackendRelative
    if (-not (Test-Path -LiteralPath $server)) { throw "No encontré el backend: $server" }
    $proc = Start-Process -FilePath 'node' -ArgumentList @($server) `
        -WorkingDirectory (Split-Path -Parent $server) -PassThru
    Set-Content -LiteralPath (Join-Path (Get-VaultStateDir -Config $Config) 'vault.pid') `
        -Value $proc.Id -Encoding ascii
    return $proc.Id
}

function Stop-VaultBackend { & (Join-Path $PSScriptRoot 'lock-vault.ps1') }

function Start-Hermes {
    & docker compose -f (Join-Path $RepoRoot 'docker-compose.yml') --project-directory $RepoRoot up -d | Out-Null
}
function Stop-Hermes {
    & docker compose -f (Join-Path $RepoRoot 'docker-compose.yml') --project-directory $RepoRoot stop | Out-Null
}

# ---------- ventana ----------
[System.Windows.Forms.Application]::EnableVisualStyles()
$form = New-Object System.Windows.Forms.Form
$form.Text = 'DeepRacer Vault'
$form.Size = New-Object System.Drawing.Size(560, 520)
$form.StartPosition = 'CenterScreen'
$form.FormBorderStyle = 'FixedDialog'
$form.MaximizeBox = $false

$lblState = New-Object System.Windows.Forms.Label
$lblState.Location = New-Object System.Drawing.Point(12, 12)
$lblState.Size = New-Object System.Drawing.Size(520, 20)
$lblState.Text = 'Bloqueado'
$lblState.ForeColor = [System.Drawing.Color]::Firebrick
$form.Controls.Add($lblState)

$txtPin = New-Object System.Windows.Forms.TextBox
$txtPin.Location = New-Object System.Drawing.Point(12, 38)
$txtPin.Size = New-Object System.Drawing.Size(300, 24)
$txtPin.UseSystemPasswordChar = $true
if ($txtPin.PSObject.Properties.Name -contains 'PlaceholderText') { $txtPin.PlaceholderText = 'PIN de tu identidad' }
$form.Controls.Add($txtPin)

$btnUnlock = New-Object System.Windows.Forms.Button
$btnUnlock.Location = New-Object System.Drawing.Point(320, 37)
$btnUnlock.Size = New-Object System.Drawing.Size(100, 26)
$btnUnlock.Text = 'Desbloquear'
$form.Controls.Add($btnUnlock)

$btnLock = New-Object System.Windows.Forms.Button
$btnLock.Location = New-Object System.Drawing.Point(428, 37)
$btnLock.Size = New-Object System.Drawing.Size(100, 26)
$btnLock.Text = 'Bloquear'
$form.Controls.Add($btnLock)

$lst = New-Object System.Windows.Forms.ListBox
$lst.Location = New-Object System.Drawing.Point(12, 74)
$lst.Size = New-Object System.Drawing.Size(516, 150)
$form.Controls.Add($lst)

$txtValue = New-Object System.Windows.Forms.TextBox
$txtValue.Location = New-Object System.Drawing.Point(12, 232)
$txtValue.Size = New-Object System.Drawing.Size(400, 24)
$txtValue.ReadOnly = $true
$txtValue.Font = New-Object System.Drawing.Font('Consolas', 9)
$form.Controls.Add($txtValue)

$btnCopy = New-Object System.Windows.Forms.Button
$btnCopy.Location = New-Object System.Drawing.Point(420, 231)
$btnCopy.Size = New-Object System.Drawing.Size(108, 26)
$btnCopy.Text = 'Copiar'
$form.Controls.Add($btnCopy)
$btnCopy.Enabled = $false

$btnBackend = New-Object System.Windows.Forms.Button
$btnBackend.Location = New-Object System.Drawing.Point(12, 275)
$btnBackend.Size = New-Object System.Drawing.Size(160, 30)
$btnBackend.Text = 'Iniciar backend'
$form.Controls.Add($btnBackend)

$btnBackendStop = New-Object System.Windows.Forms.Button
$btnBackendStop.Location = New-Object System.Drawing.Point(180, 275)
$btnBackendStop.Size = New-Object System.Drawing.Size(160, 30)
$btnBackendStop.Text = 'Detener backend'
$form.Controls.Add($btnBackendStop)

$btnHermes = New-Object System.Windows.Forms.Button
$btnHermes.Location = New-Object System.Drawing.Point(12, 313)
$btnHermes.Size = New-Object System.Drawing.Size(160, 30)
$btnHermes.Text = 'Iniciar Hermes'
$form.Controls.Add($btnHermes)

$btnHermesStop = New-Object System.Windows.Forms.Button
$btnHermesStop.Location = New-Object System.Drawing.Point(180, 313)
$btnHermesStop.Size = New-Object System.Drawing.Size(160, 30)
$btnHermesStop.Text = 'Detener Hermes'
$form.Controls.Add($btnHermesStop)

$btnDash = New-Object System.Windows.Forms.Button
$btnDash.Location = New-Object System.Drawing.Point(348, 275)
$btnDash.Size = New-Object System.Drawing.Size(180, 30)
$btnDash.Text = 'Abrir dashboard Hermes'
$form.Controls.Add($btnDash)

$btnRefresh = New-Object System.Windows.Forms.Button
$btnRefresh.Location = New-Object System.Drawing.Point(348, 313)
$btnRefresh.Size = New-Object System.Drawing.Size(180, 30)
$btnRefresh.Text = 'Recargar lista'
$form.Controls.Add($btnRefresh)

$log = New-Object System.Windows.Forms.TextBox
$log.Location = New-Object System.Drawing.Point(12, 355)
$log.Size = New-Object System.Drawing.Size(516, 110)
$log.Multiline = $true
$log.ReadOnly = $true
$log.ScrollBars = 'Vertical'
$log.Font = New-Object System.Drawing.Font('Consolas', 8)
$form.Controls.Add($log)

function Write-GuiLog([string]$Msg) {
    $log.AppendText((Get-Date -Format 'HH:mm:ss') + '  ' + $Msg + "`r`n")
}

function Refresh-List {
    $lst.Items.Clear()
    if ($null -eq $script:SecretMap) { return }
    foreach ($k in ($script:SecretMap.Keys | Sort-Object)) { [void]$lst.Items.Add($k) }
}

$btnUnlock.Add_Click({
    try {
        if ([string]::IsNullOrWhiteSpace($txtPin.Text)) { throw 'Escribe el PIN.' }
        $map = Unlock-VaultGui -Pin $txtPin.Text
        $script:SecretMap = $map
        $txtPin.Text = ''
        $lblState.Text = "Desbloqueado · $($map.Keys.Count) secretos"
        $lblState.ForeColor = [System.Drawing.Color]::DarkGreen
        Refresh-List
        Write-GuiLog "Desbloqueado ($($map.Keys.Count) secretos)."
    } catch {
        Write-GuiLog "ERROR al desbloquear: $($_.Exception.Message)"
        [System.Windows.Forms.MessageBox]::Show($_.Exception.Message, 'Vault') | Out-Null
    }
})

$lst.Add_SelectedIndexChanged({
    if ($lst.SelectedItem -and $script:SecretMap) {
        $name = [string]$lst.SelectedItem
        $txtValue.Text = [string]$script:SecretMap[$name]
        $btnCopy.Enabled = $true
    }
})

$btnCopy.Add_Click({
    if ($txtValue.Text) {
        [System.Windows.Forms.Clipboard]::SetText($txtValue.Text)
        Write-GuiLog "Copiado al portapapeles: $($lst.SelectedItem)"
    }
})

$btnBackend.Add_Click({
    if ($null -eq $script:SecretMap) { Write-GuiLog 'ERROR: desbloquea primero.'; return }
    try { $id = Start-VaultBackend; Write-GuiLog "Backend arrancado (PID $id)." }
    catch { Write-GuiLog "ERROR backend: $($_.Exception.Message)" }
})
$btnBackendStop.Add_Click({ try { Stop-VaultBackend } catch { Write-GuiLog "ERROR: $($_.Exception.Message)" } })
$btnHermes.Add_Click({
    if ($null -eq $script:SecretMap) { Write-GuiLog 'ERROR: desbloquea primero (Hermes necesita los secretos).'; return }
    try { Write-GuiLog 'Iniciando Hermes (docker compose up -d)...'; Start-Hermes; Write-GuiLog 'Hermes: up enviado.' }
    catch { Write-GuiLog "ERROR Hermes: $($_.Exception.Message)" }
})
$btnHermesStop.Add_Click({ try { Stop-Hermes; Write-GuiLog 'Hermes detenido.' } catch { Write-GuiLog "ERROR: $($_.Exception.Message)" } })
$btnDash.Add_Click({ Start-Process 'http://localhost:9999/login'; Write-GuiLog 'Abriendo dashboard...' })
$btnRefresh.Add_Click({ Refresh-List })

$btnLock.Add_Click({
    if ($script:SecretMap) {
        foreach ($k in $script:SecretMap.Keys) {
            Remove-Item -Path ("Env:" + $k) -ErrorAction SilentlyContinue
        }
    }
    $script:SecretMap = $null
    $lst.Items.Clear()
    $txtValue.Text = ''
    $btnCopy.Enabled = $false
    $lblState.Text = 'Bloqueado'
    $lblState.ForeColor = [System.Drawing.Color]::Firebrick
    Write-GuiLog 'Bloqueado (secretos fuera de memoria).'
})

[void]$form.ShowDialog()
