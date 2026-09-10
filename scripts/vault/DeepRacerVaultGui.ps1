# GUI local del vault (WinForms, sin web ni dependencias).
# Desbloquea con USB + PIN, muestra secretos, opera backend/Hermes, vigila el
# estado con indicadores (LEDs) y visor de logs.
# Uso:  scripts\vault\abrir-gui.cmd   (o compilar a .exe con build-gui-exe.ps1)
# Nota: este archivo es SOLO ASCII a proposito (Windows PowerShell 5.1 lee
# .ps1 sin BOM como ANSI; los acentos/emojis rompen el parseo).
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

. (Join-Path $PSScriptRoot 'vault-common.ps1')

$Config = Get-VaultConfig
$RepoRoot = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
$stateDir = Get-VaultStateDir -Config $Config
if (-not (Test-Path -LiteralPath $stateDir)) { New-Item -ItemType Directory -Path $stateDir -Force | Out-Null }
$backendOut = Join-Path $stateDir 'backend.out.log'
$backendErr = Join-Path $stateDir 'backend.err.log'
$hermesLog = Join-Path $stateDir 'hermes.log'

$script:SecretMap = $null
$script:GuiLog = New-Object System.Collections.Generic.List[string]
$script:LogSource = 'GUI'
$script:Prev = @{}

function Add-GuiLog([string]$Msg) {
    $script:GuiLog.Add((Get-Date -Format 'HH:mm:ss') + '  ' + $Msg)
    if ($script:GuiLog.Count -gt 500) { $script:GuiLog.RemoveAt(0) }
}
function Unlock-VaultGui([string]$Pin) {
    $usb = Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial
    if (-not $usb) { throw "USB no encontrada (serial $($Config.UsbVolumeSerial))." }
    $idPath = Get-IdentityPath -DeviceId $usb.DeviceID -Config $Config
    if (-not (Test-Path -LiteralPath $idPath)) { throw 'Falta identity.age en la USB.' }
    $vaultPath = Get-VaultPath -Config $Config
    if (-not (Test-Path -LiteralPath $vaultPath)) { throw "No hay vault cifrado ($vaultPath)." }
    $tmpId = $null
    try {
        $tmpId = Get-IdentityTemp -UsbIdentityPath $idPath -Pin $Pin
        $text = Unprotect-VaultWithIdentity -InPath $vaultPath -IdentityPath $tmpId
    } finally { if ($tmpId) { Remove-Item -LiteralPath $tmpId -Force -ErrorAction SilentlyContinue } }
    $map = ConvertFrom-EnvText -Text $text
    foreach ($k in $map.Keys) { Set-Item -Path ('Env:' + $k) -Value $map[$k] }
    return $map
}
function Start-VaultBackend {
    $server = Join-Path $RepoRoot $Config.BackendRelative
    if (-not (Test-Path -LiteralPath $server)) { throw "No encontre el backend: $server" }
    $p = Start-Process -FilePath 'node' -ArgumentList @($server) `
        -WorkingDirectory (Split-Path -Parent $server) -PassThru `
        -RedirectStandardOutput $backendOut -RedirectStandardError $backendErr
    Set-Content -LiteralPath (Join-Path $stateDir 'vault.pid') -Value $p.Id -Encoding ascii
    return $p.Id
}
function Stop-VaultBackend { & (Join-Path $PSScriptRoot 'lock-vault.ps1') }
function Start-Hermes { & docker compose -f (Join-Path $RepoRoot 'docker-compose.yml') --project-directory $RepoRoot up -d 2>&1 | Out-File -LiteralPath $hermesLog -Append }
function Stop-Hermes { & docker compose -f (Join-Path $RepoRoot 'docker-compose.yml') --project-directory $RepoRoot stop 2>&1 | Out-File -LiteralPath $hermesLog -Append }
function Test-Listen([int]$Port) { [bool](Get-NetTCPConnection -State Listen -ErrorAction SilentlyContinue | Where-Object LocalPort -eq $Port | Select-Object -First 1) }
function Get-BackendPid {
    $f = Join-Path $stateDir 'vault.pid'
    if (Test-Path -LiteralPath $f) { return [int]((Get-Content -LiteralPath $f -Raw).Trim()) }
    return 0
}
function Test-ProcessAlive([int]$Id) { if ($Id -le 0) { return $false }; [bool](Get-Process -Id $Id -ErrorAction SilentlyContinue) }
function Get-Tail([string]$Path, [int]$Lines = 200) {
    if (-not (Test-Path -LiteralPath $Path)) { return "(sin log: $Path)" }
    return ((Get-Content -LiteralPath $Path -Tail $Lines -ErrorAction SilentlyContinue) -join "`r`n")
}

# ---------- tema ----------
$bg = [System.Drawing.Color]::FromArgb(30, 34, 42)
$panel = [System.Drawing.Color]::FromArgb(24, 28, 34)
$okColor = [System.Drawing.Color]::FromArgb(70, 200, 120)
$badColor = [System.Drawing.Color]::FromArgb(220, 80, 80)
$gray = [System.Drawing.Color]::FromArgb(150, 160, 175)

[System.Windows.Forms.Application]::EnableVisualStyles()
$form = New-Object System.Windows.Forms.Form
$form.Text = 'DeepRacer Vault'
$form.ClientSize = New-Object System.Drawing.Size(800, 640)
$form.StartPosition = 'CenterScreen'
$form.MinimumSize = New-Object System.Drawing.Size(820, 680)
$form.Font = New-Object System.Drawing.Font('Segoe UI', 9.5)
$form.BackColor = $bg; $form.ForeColor = [System.Drawing.Color]::White

function New-Label([string]$Text, [int]$X, [int]$Y, [int]$W, [int]$H, [double]$Size = 9.5, $Color = $null) {
    $l = New-Object System.Windows.Forms.Label
    $l.Text = $Text; $l.Location = New-Object System.Drawing.Point($X, $Y)
    $l.Size = New-Object System.Drawing.Size($W, $H)
    $l.Font = New-Object System.Drawing.Font('Segoe UI', $Size)
    $l.ForeColor = if ($null -eq $Color) { [System.Drawing.Color]::White } else { $Color }
    $l.BackColor = [System.Drawing.Color]::Transparent
    return $l
}
function New-Button([string]$Text, [int]$X, [int]$Y, [int]$W, [int]$H) {
    $b = New-Object System.Windows.Forms.Button
    $b.Text = $Text; $b.Location = New-Object System.Drawing.Point($X, $Y)
    $b.Size = New-Object System.Drawing.Size($W, $H)
    $b.FlatStyle = 'Flat'; $b.BackColor = [System.Drawing.Color]::FromArgb(44, 50, 62)
    $b.ForeColor = [System.Drawing.Color]::White
    $b.FlatAppearance.BorderColor = [System.Drawing.Color]::FromArgb(90, 100, 120)
    return $b
}
function New-TextBox([int]$X, [int]$Y, [int]$W, [int]$H, [switch]$ReadOnly, [switch]$Password) {
    $t = New-Object System.Windows.Forms.TextBox
    $t.Location = New-Object System.Drawing.Point($X, $Y); $t.Size = New-Object System.Drawing.Size($W, $H)
    $t.BackColor = $panel; $t.ForeColor = [System.Drawing.Color]::White; $t.BorderStyle = 'FixedSingle'
    if ($ReadOnly) { $t.ReadOnly = $true }
    if ($Password) { $t.UseSystemPasswordChar = $true }
    if (($t.PSObject.Properties.Name -contains 'PlaceholderText') -and -not $ReadOnly) { $t.PlaceholderText = 'PIN de tu identidad' }
    return $t
}
function New-Led([int]$X, [int]$Y) {
    $p = New-Object System.Windows.Forms.Panel
    $p.Location = New-Object System.Drawing.Point($X, $Y); $p.Size = New-Object System.Drawing.Size(14, 14)
    $p.BackColor = $gray; $p.BorderStyle = 'FixedSingle'
    return $p
}

$form.Controls.Add((New-Label 'DeepRacer Vault' 18 12 400 30 16))
$form.Controls.Add((New-Label 'Estado del sistema' 18 44 300 18 9 $gray))

$ledUsb = New-Led 18 68; $lblUsb = New-Label 'USB -' 38 68 130 18 9 $gray
$ledVault = New-Led 176 68; $lblVault = New-Label 'Vault -' 196 68 120 18 9 $gray
$ledBack = New-Led 324 68; $lblBack = New-Label 'Backend -' 344 68 155 18 9 $gray
$ledHermes = New-Led 506 68; $lblHermes = New-Label 'Hermes -' 526 68 150 18 9 $gray
foreach ($c in @($ledUsb, $lblUsb, $ledVault, $lblVault, $ledBack, $lblBack, $ledHermes, $lblHermes)) { $form.Controls.Add($c) }

$form.Controls.Add((New-Label 'Desbloqueo' 18 98 200 18 9 $gray))
$txtPin = New-TextBox 18 120 360 26 -Password
$btnUnlock = New-Button 'Desbloquear' 384 119 130 28
$btnLock = New-Button 'Bloquear' 520 119 130 28
$form.Controls.Add($txtPin); $form.Controls.Add($btnUnlock); $form.Controls.Add($btnLock)

$form.Controls.Add((New-Label 'Secretos' 18 158 300 18 9 $gray))
$lst = New-Object System.Windows.Forms.ListBox
$lst.Location = New-Object System.Drawing.Point(18, 180); $lst.Size = New-Object System.Drawing.Size(380, 150)
$lst.BackColor = $panel; $lst.ForeColor = [System.Drawing.Color]::White; $lst.BorderStyle = 'FixedSingle'
$form.Controls.Add($lst)
$txtValue = New-TextBox 408 180 374 26 -ReadOnly
$txtValue.Font = New-Object System.Drawing.Font('Consolas', 9)
$btnCopy = New-Button 'Copiar' 408 212 374 28; $btnCopy.Enabled = $false
$form.Controls.Add($txtValue); $form.Controls.Add($btnCopy)

$form.Controls.Add((New-Label 'Servicios' 18 340 200 18 9 $gray))
$bBack = New-Button 'Iniciar backend' 18 362 145 30
$bBackStop = New-Button 'Detener backend' 166 362 145 30
$bHerm = New-Button 'Iniciar Hermes' 314 362 145 30
$bHermStop = New-Button 'Detener Hermes' 462 362 145 30
$bDash = New-Button 'Abrir dashboard' 610 362 172 30
$form.Controls.Add($bBack); $form.Controls.Add($bBackStop); $form.Controls.Add($bHerm); $form.Controls.Add($bHermStop); $form.Controls.Add($bDash)

$form.Controls.Add((New-Label 'Logs' 18 402 40 18 9 $gray))
$cmbLog = New-Object System.Windows.Forms.ComboBox
$cmbLog.Location = New-Object System.Drawing.Point(60, 399); $cmbLog.Size = New-Object System.Drawing.Size(180, 24)
$cmbLog.DropDownStyle = 'DropDownList'; $cmbLog.BackColor = $panel; $cmbLog.ForeColor = [System.Drawing.Color]::White
[void]$cmbLog.Items.AddRange(@('GUI', 'Backend', 'Hermes')); $cmbLog.SelectedIndex = 0
$btnRefresh = New-Button 'Refrescar' 248 398 110 26
$form.Controls.Add($cmbLog); $form.Controls.Add($btnRefresh)
$txtLog = New-Object System.Windows.Forms.TextBox
$txtLog.Location = New-Object System.Drawing.Point(18, 428); $txtLog.Size = New-Object System.Drawing.Size(764, 194)
$txtLog.Multiline = $true; $txtLog.ReadOnly = $true; $txtLog.ScrollBars = 'Vertical'
$txtLog.BackColor = $panel; $txtLog.ForeColor = [System.Drawing.Color]::FromArgb(200, 210, 220)
$txtLog.Font = New-Object System.Drawing.Font('Consolas', 8.5)
$form.Controls.Add($txtLog)

# ---------- logica ----------
function Refresh-List {
    $lst.Items.Clear()
    if ($null -eq $script:SecretMap) { return }
    foreach ($k in ($script:SecretMap.Keys | Sort-Object)) { [void]$lst.Items.Add($k) }
}
function Set-Led($led, $label, [string]$name, [bool]$ok, [string]$extra = '') {
    if ($ok) { $led.BackColor = $okColor; $label.Text = "$name ok $extra"; $label.ForeColor = $okColor }
    else { $led.BackColor = $badColor; $label.Text = "$name - $extra"; $label.ForeColor = $gray }
}
function Show-Logs {
    switch ($script:LogSource) {
        'Backend' { $txtLog.Text = (Get-Tail $backendOut) + "`r`n--- stderr ---`r`n" + (Get-Tail $backendErr 100) }
        'Hermes'  { $txtLog.Text = Get-Tail $hermesLog }
        default   { $txtLog.Text = ($script:GuiLog -join "`r`n") }
    }
    $txtLog.SelectionStart = $txtLog.Text.Length; $txtLog.ScrollToCaret()
}
function Sync-GuiLog { if ($script:LogSource -eq 'GUI') { Show-Logs } }

$btnUnlock.Add_Click({
    try {
        if ([string]::IsNullOrWhiteSpace($txtPin.Text)) { throw 'Escribe el PIN.' }
        $map = Unlock-VaultGui $txtPin.Text
        $script:SecretMap = $map; $txtPin.Text = ''
        Refresh-List; Add-GuiLog "Desbloqueado ($($map.Keys.Count) secretos)."; Sync-GuiLog
    } catch {
        Add-GuiLog "ERROR al desbloquear: $($_.Exception.Message)"
        [System.Windows.Forms.MessageBox]::Show($_.Exception.Message, 'Vault') | Out-Null
        Sync-GuiLog
    }
})
$btnLock.Add_Click({
    if ($script:SecretMap) { foreach ($k in $script:SecretMap.Keys) { Remove-Item -Path ('Env:' + $k) -ErrorAction SilentlyContinue } }
    $script:SecretMap = $null; $lst.Items.Clear(); $txtValue.Text = ''; $btnCopy.Enabled = $false
    Add-GuiLog 'Bloqueado.'; Sync-GuiLog
})
$lst.Add_SelectedIndexChanged({
    if ($lst.SelectedItem -and $script:SecretMap) { $txtValue.Text = [string]$script:SecretMap[[string]$lst.SelectedItem]; $btnCopy.Enabled = $true }
})
$btnCopy.Add_Click({ if ($txtValue.Text) { [System.Windows.Forms.Clipboard]::SetText($txtValue.Text); Add-GuiLog "Copiado: $($lst.SelectedItem)"; Sync-GuiLog } })
$bBack.Add_Click({
    if ($null -eq $script:SecretMap) { Add-GuiLog 'ERROR: desbloquea primero.'; Sync-GuiLog; return }
    try { $id = Start-VaultBackend; Add-GuiLog "Backend arrancado (PID $id)." } catch { Add-GuiLog "ERROR backend: $($_.Exception.Message)" }
    Sync-GuiLog
})
$bBackStop.Add_Click({ try { Stop-VaultBackend; Add-GuiLog 'Backend detenido.' } catch { Add-GuiLog "ERROR: $($_.Exception.Message)" }; Sync-GuiLog })
$bHerm.Add_Click({
    if ($null -eq $script:SecretMap) { Add-GuiLog 'ERROR: desbloquea primero (Hermes necesita los secretos).'; Sync-GuiLog; return }
    try { Add-GuiLog 'Iniciando Hermes...'; Start-Hermes; Add-GuiLog 'Hermes: up enviado.' } catch { Add-GuiLog "ERROR Hermes: $($_.Exception.Message)" }
    Sync-GuiLog
})
$bHermStop.Add_Click({ try { Stop-Hermes; Add-GuiLog 'Hermes detenido.' } catch { Add-GuiLog "ERROR: $($_.Exception.Message)" }; Sync-GuiLog })
$bDash.Add_Click({ try { Start-Process 'http://localhost:9999/login'; Add-GuiLog 'Abriendo dashboard...' } catch { Add-GuiLog "ERROR: $($_.Exception.Message)" }; Sync-GuiLog })
$btnRefresh.Add_Click({ Show-Logs })
$cmbLog.Add_SelectedIndexChanged({ $script:LogSource = [string]$cmbLog.SelectedItem; Show-Logs })

$timer = New-Object System.Windows.Forms.Timer
$timer.Interval = 2500
$timer.Add_Tick({
    $usb = [bool](Get-UsbVolume -VolumeSerial $Config.UsbVolumeSerial)
    Set-Led $ledUsb $lblUsb 'USB' $usb $(if ($usb) { '' } else { 'no detectada' })
    Set-Led $ledVault $lblVault 'Vault' ($null -ne $script:SecretMap) $(if ($script:SecretMap) { "($($script:SecretMap.Keys.Count))" } else { 'bloqueado' })

    $bp = Get-BackendPid; $alive = Test-ProcessAlive $bp; $listen = Test-Listen 5002
    $bExtra = if ($bp -gt 0) { "PID $bp$(if (-not $listen) { ' (sin :5002)' })" } else { 'apagado' }
    Set-Led $ledBack $lblBack 'Backend' ($bp -gt 0 -and $alive -and $listen) $bExtra
    if ($bp -gt 0 -and -not $alive) {
        if ($script:Prev['backfail'] -ne $true) { Add-GuiLog 'AVISO: el backend se cayo (proceso no vivo).'; $script:Prev['backfail'] = $true }
    } elseif ($bp -gt 0 -and -not $listen) {
        if ($script:Prev['backfail'] -ne $true) { Add-GuiLog 'AVISO: backend vivo pero :5002 no escucha.'; $script:Prev['backfail'] = $true }
    } else { $script:Prev['backfail'] = $false }

    $hermes = Test-Listen 9999
    Set-Led $ledHermes $lblHermes 'Hermes' $hermes $(if ($hermes) { ':9999' } else { 'apagado' })

    if ($script:LogSource -ne 'GUI') { Show-Logs } elseif ($script:GuiLog.Count -gt 0) { Show-Logs }
})
$timer.Start()

$form.Add_FormClosing({
    $timer.Stop()
    if ($script:SecretMap) { foreach ($k in $script:SecretMap.Keys) { Remove-Item -Path ('Env:' + $k) -ErrorAction SilentlyContinue } }
})

[void]$form.ShowDialog()
