# Vault local del DeepRacer (Opción B: USB keyfile + PIN)

Implementa la **Opción B** de `docs/plans/plan-seguridad-secretos.md` §8:
las credenciales viven cifradas y solo se pueden descifrar con **algo que
tenés** (una USB con un `keyfile` aleatorio) **+ algo que sabés** (un PIN).
Sin USB no hay vault; con la USB sola tampoco (falta el PIN).

## Cómo funciona

- **keyfile:** 64 bytes aleatorios en la USB, en `D:\DeepRacerVault\keyfile.bin`.
  La USB se identifica por **serial de volumen** (`vault.config.psd1`), no por
  letra, así que `D:`/`E:` pueden cambiar sin romper nada.
- **passphrase derivada:** `Base64(HMAC-SHA256(keyfile, PIN))`. age le aplica
  `scrypt` encima (plugin `age-plugin-batchpass`), así que una PIN corta igual
  cuesta fuerza bruta.
- **vault:** `%LOCALAPPDATA%\DeepRacerVault\secrets.age` (cifrado con `age`,
  formato armor). No vive en el repo.
- **inyección:** el backend (`apps/backend`) usa `dotenv` **sin override**, así
  que las variables del vault ganan sobre `.env`; `unlock-vault.ps1 -StartBackend`
  arranca `node` con esos valores solo en la memoria del proceso.

## Requisitos

- `age` instalado: `winget install --id FiloSottile.age` (probado con 1.3.1).
- **Pre-requisitos honestos** del plan (§9): cuentas de Windows individuales,
  BitLocker y bloqueo automático de sesión. Sin eso, ningún vault sirve.
- PowerShell 5.1+ (viene con Windows).

## Flujo

```powershell
# 1) Crear el vault (una vez). Te pide PIN dos veces.
Copy-Item scripts\vault\secrets.example.env secrets.local.env   # edita valores
.\scripts\vault\init-vault.ps1 -SecretsFile secrets.local.env
Remove-Item secrets.local.env        # el plano con valores reales se borra

# 2) Desbloquear + arrancar backend (cada jornada)
.\scripts\vault\unlock-vault.ps1 -StartBackend

# 3) Bloquear (mata el backend del vault)
.\scripts\vault\lock-vault.ps1

# 4) Auto-lock al sacar la USB (opcional)
.\scripts\vault\install-watcher.ps1
```

Al **extraer** la USB, el watcher corre `lock-vault.ps1` y mata el backend.
Al **insertarla** solo avisa por log: desbloquear exige teclado/PIN, así que se
hace a mano con `unlock-vault.ps1`.

## Archivos

| Archivo | Rol |
|---|---|
| `vault-common.ps1` | Helpers (USB por serial, KDF, proteger/descifrar). Sin secretos. |
| `vault.config.psd1` | Serial de la USB, rutas, nombre del vault. Sin secretos. |
| `init-vault.ps1` | Crea keyfile + cifra un `.env` local en `secrets.age`. |
| `unlock-vault.ps1` | Descifra (USB+PIN) y arranca el backend con los secretos. |
| `lock-vault.ps1` | Detiene el backend del vault. |
| `watch-vault.ps1` | Sondea la USB; auto-lock al extraer. |
| `install-watcher.ps1` | Registra el watcher al iniciar sesión. |
| `secrets.example.env` | Plantilla de nombres de variables (sin valores). |

## Límites (honestos)

- La USB **se puede copiar** (igual que un QR), por eso el PIN es obligatorio.
- El PIN se lee con `Read-Host -AsSecureString`; la passphrase derivada se pasa
  a `age` por variable de entorno (`AGE_PASSPHRASE`), nunca por línea de
  comandos, y se limpia al terminar. En un PC con sesión abierta, otro proceso
  del mismo usuario podría leer el entorno: de ahí el bloqueo automático.
- No es anti-adversario: frena el acceso casual, no a un atacante con el equipo.
- Rotación: si alguien sale del equipo, se regenera el keyfile y se re-cifra
  (`init-vault.ps1` con la USB nueva).

> Este directorio **no** contiene secretos. El keyfile (USB) y `secrets.age`
> (PC) están ignorados por Git; jamás deben versionarse.
