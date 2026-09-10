# Vault local del DeepRacer (una identidad por persona)

Vault local según `docs/plans/plan-seguridad-secretos.md` §7-8. **Cada persona
tiene su propia llave** (identidad `age` con su PIN, guardada en su USB); el
vault `secrets.age` se cifra a la **unión de llaves públicas**. Así cada quien
descifra con su USB+PIN, y revocar a alguien = re-cifrar sin su llave.

## Cómo funciona

- **Identidad (por persona):** par `age` X25519. La llave **privada** se guarda
  cifrada con tu PIN en tu USB (`D:\DeepRacerVault\identity.age`). La **pública**
  (`age1...`) se agrega a `%LOCALAPPDATA%\DeepRacerVault\recipients.txt`.
- **Vault:** `%LOCALAPPDATA%\DeepRacerVault\secrets.age`, cifrado a **todos** los
  destinatarios de `recipients.txt`. No vive en el repo.
- **Inyección:** el backend usa `dotenv` **sin override**; `unlock-vault.ps1`
  descifra la identidad con tu PIN y el vault con esa identidad, e inyecta las
  variables solo en la memoria del proceso `node` que arranca.
- La USB se identifica por **serial de volumen** (`vault.config.psd1`), no por
  letra, así que `D:`/`E:` pueden cambiar.

## Requisitos

- `age` instalado: `winget install --id FiloSottile.age` (probado con 1.3.1).
- **Pre-requisitos honestos** del plan (§9): cuentas de Windows individuales,
  BitLocker y bloqueo automático de sesión. Sin eso, ningún vault sirve.
- PowerShell 5.1+ (viene con Windows).

## Alta de una persona (una vez, con SU USB)

```powershell
.\scripts\vault\new-identity.ps1 -Label <nombre>     # pide su PIN; crea identity.age en su USB
```
Guarda el `age1...` que imprime. **No borres** `identity.age` de la USB: sin eso
no se descifra nada.

## Crear / actualizar el vault

```powershell
Copy-Item .env secrets.local.env                     # o el archivo con los valores
.\scripts\vault\init-vault.ps1 -SecretsFile secrets.local.env
Remove-Item secrets.local.env                        # borra el plano
```

## Uso diario

```powershell
.\scripts\vault\unlock-vault.ps1                     # descifra e inyecta (prueba)
.\scripts\vault\unlock-vault.ps1 -StartBackend       # + arranca el backend
.\scripts\vault\lock-vault.ps1                       # detiene el backend del vault
.\scripts\vault\install-watcher.ps1                   # auto-lock al extraer la USB
```

## Ver un secreto (p. ej. la del dashboard)

La password del dashboard de Hermes es `HERMES_DASHBOARD_BASIC_AUTH_PASSWORD`
(usuario `admin`). Para verla:

```powershell
# opción directa: desbloquear y leer del entorno
.\scripts\vault\unlock-vault.ps1
$env:HERMES_DASHBOARD_BASIC_AUTH_PASSWORD

# o en un paso
.\scripts\vault\show-secret.ps1 -Name HERMES_DASHBOARD_BASIC_AUTH_PASSWORD
```

Otros nombres útiles: `DEEPRACER_API_PASSWORD`, `DEEPRACER_SSH_PASSWORD`,
`OPENCODE_API_KEY`, `OPENCODE_GO_API_KEY`, `API_SERVER_KEY`,
`ESP32_CAMERA_WIFI_PASSWORD`.

Truco para no memorizarla: la primera vez guarda `admin` + esa password en el
**gestor de contraseñas del navegador**; luego `localhost:9999` se rellena solo.
Cierra la consola al terminar (queda con los secretos en el entorno).

## Hermes (Docker)

Hermes usa el `.env` de la raíz vía `env_file`. Como los secretos ya no viven
ahí, se los pasa el vault por interpolación de shell. Con esta parte en
`docker-compose.yml`:

```yaml
    env_file:
      - .env            # solo config
    environment:
      OPENCODE_API_KEY: ${OPENCODE_API_KEY}
      OPENCODE_GO_API_KEY: ${OPENCODE_GO_API_KEY}
      HERMES_DASHBOARD_BASIC_AUTH_PASSWORD: ${HERMES_DASHBOARD_BASIC_AUTH_PASSWORD}
      HERMES_DASHBOARD_BASIC_AUTH_SECRET: ${HERMES_DASHBOARD_BASIC_AUTH_SECRET}
      API_SERVER_KEY: ${API_SERVER_KEY}
```

Arranca Hermes **desde una consola desbloqueada** (si no, `${...}` queda vacío):

```powershell
.\scripts\vault\unlock-vault.ps1     # setea los secretos en el shell
docker compose up -d
```

> `hermes/config.yaml` y `hermes/auth.json` tienen secretos propios del agent
> (estado persistente); eso es aparte del vault y no se inyecta por env.

## Agregar / revocar personas

```powershell
# Agregar: pega la llave publica (age1...) de la persona nueva.
.\scripts\vault\add-recipient.ps1 -PublicKey age1... -Label <nombre>

# Revocar: borra sus lineas de recipients.txt y re-cifra.
# (edita el archivo y luego)
.\scripts\vault\add-recipient.ps1 -ReencryptOnly
```
Re-cifrar requiere **tu** USB + PIN (usa tu identidad para abrir y volver a
cerrar para el nuevo conjunto de llaves).

## Recuperación (si olvidas el PIN)

Con `age` y sin servidor, olvidar el PIN deja tu identidad ilegible: **el 2FA
por sí solo no recupera**. La salida es una **llave de recuperación** guardada
aparte, que sí puede descifrar el vault.

1. Una vez (con el vault funcionando):
   ```powershell
   .\scripts\vault\new-recovery.ps1 -Label recovery
   ```
   Imprime una clave `AGE-SECRET-KEY-1...`. **Guárdala en BWS (con 2FA)**; no se
   vuelve a mostrar. Su pública queda en `recipients.txt`.

2. Si olvidas tu PIN:
   ```powershell
   # a) crea una identidad nueva con PIN nuevo (nueva USB o la misma)
   .\scripts\vault\new-identity.ps1 -Label <nombre>
   # b) recupera el vault con la clave de BWS (login BWS + TOTP)
   .\scripts\vault\recover-vault.ps1     # pega AGE-SECRET-KEY-1...
   # c) ahora tu identidad nueva ya abre el vault
   .\scripts\vault\unlock-vault.ps1
   ```
   Esto es "cambiar contraseña con verificación 2FA": el 2FA abre BWS, BWS da
   la llave de recuperación, y con ella se re-cifra para tu llave nueva.

> La llave de recuperación es tan poderosa como cualquier USB: no la guardes en
> el mismo PC que el vault. En BWS, protégé la cuenta con TOTP y rol mínimo.

## Archivos

| Archivo | Rol |
|---|---|
| `vault-common.ps1` | Helpers (USB por serial, identidades, proteger/descifrar). Sin secretos. |
| `vault.config.psd1` | Serial de la USB, rutas, nombres. Sin secretos. |
| `new-identity.ps1` | Crea tu identidad (USB+PIN) y te registra como destinatario. |
| `new-recovery.ps1` | Crea la llave de recuperación; guardarla en BWS con 2FA. |
| `recover-vault.ps1` | Re-cifra el vault usando la llave de recuperación. |
| `init-vault.ps1` | Cifra un `.env` local a todos los destinatarios. |
| `unlock-vault.ps1` | Descifra con tu USB+PIN; opcional `-StartBackend`. |
| `add-recipient.ps1` | Agrega/remueve destinatarios y re-cifra. |
| `lock-vault.ps1` | Detiene el backend del vault. |
| `watch-vault.ps1` | Sondea la USB; auto-lock al extraer. |
| `install-watcher.ps1` | Registra el watcher al iniciar sesión. |
| `secrets.example.env` | Plantilla de nombres de variables (sin valores). |

## Límites (honestos)

- Una **copia** de `identity.age` + PIN abre el vault igual que la USB: el PIN
  protege la identidad (scrypt de `age`), pero no hay factor físico infalible.
- `add-recipient.ps1` conserva el vault en claro un instante en memoria al
  re-cifrar; no deja plano en disco.
- No es anti-adversario: frena el acceso casual, no a un atacante con el equipo.
- Al salir alguien: revocar (re-cifrar sin su llave) y rotar los secretos que
  pudo haber visto.

> Este directorio **no** contiene secretos. `identity.age` (USB),
> `recipients.txt` y `secrets.age` (PC) están ignorados por Git; jamás
> versionar.
