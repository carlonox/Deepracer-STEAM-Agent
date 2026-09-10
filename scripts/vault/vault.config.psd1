@{
    # Vault local Opción B (plan-seguridad-secretos.md §8):
    # keyfile en USB + PIN. La USB se identifica por serial de VOLUMEN,
    # nunca por letra (D:/E: cambian). Este archivo no contiene secretos.
    UsbVolumeSerial    = '14B0E7FA'
    UsbKeyfileRelative = 'DeepRacerVault\keyfile.bin'
    VaultDirectory     = 'DeepRacerVault'   # bajo %LOCALAPPDATA%
    VaultFileName      = 'secrets.age'
    EnvTemplateName    = 'secrets.example.env'
    BackendRelative    = 'apps\backend\server.js'
}
