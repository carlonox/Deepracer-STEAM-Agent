@{
    # Vault local, modelo por persona (plan-seguridad-secretos.md §7-8):
    # cada persona tiene una identidad age (llave privada) cifrada con su PIN
    # en su USB; el vault se cifra a la union de llaves publicas.
    # La USB se identifica por serial de VOLUMEN, nunca por letra. Sin secretos.
    UsbVolumeSerial     = '14B0E7FA'
    UsbIdentityRelative = 'DeepRacerVault\identity.age'
    VaultDirectory      = 'DeepRacerVault'   # bajo %LOCALAPPDATA%
    VaultFileName       = 'secrets.age'
    RecipientsFileName  = 'recipients.txt'
    EnvTemplateName     = 'secrets.example.env'
    BackendRelative     = 'apps\backend\server.js'
}
