# Plan de seguridad de secretos — gestión con BWS para el equipo

> **Fecha:** 2026-09-05
> **Estado:** pendiente de ejecutar cuando haya acceso al robot/PC de la U
> **Audiencia:** mantenedores del repo y quien continúe el proyecto
> **Motivo:** el repo es público, ya hubo 3 secretos filtrados en el historial
> (purgados 2026-09-05, ver `CREDENTIAL_ROTATION.md`). Con varias personas
> operando, las credenciales no pueden vivir en un `.env` personal ni en chats.

---

## 1. Principio rector

> **Nadie comparte credenciales. Cada persona tiene SU identidad; los secretos
> compartidos viven en un vault con permisos; cada máquina tiene su propio
> token.**

Un secreto compartido entre personas es un secreto sin dueño: no se sabe quién
lo usó, no se puede revocar a uno sin revocar a todos, y termina en un README.

## 2. Modelo de Bitwarden Secrets Manager (BWS)

BWS tiene dos tipos de acceso:

| Tipo | Qué es | Cómo entra |
|---|---|---|
| **Usuarios humanos** | Personas invitadas a la organización | Su propia cuenta, rol **Read** o **Read/Write** sobre un proyecto |
| **Machine accounts** | Identidades de máquina (agentes, CI, PCs) | **Access token** propio en su `.env`, permisos por proyecto |

- **Projects** = contenedores de secretos con permisos por persona/máquina.
- **Anti-patrón:** compartir el MISMO access token entre personas (pierde
  auditoría y revocación individual).
- Cada humano → su cuenta. Cada máquina → su machine account.

## 3. Organización propuesta para el DeepRacer

Crear un **proyecto propio en BWS** (ej. `deepracer-robot`) con los secretos
del robot:

| Secreto | Notas |
|---|---|
| Password API web del robot | Regenerable desde el serial (`reset_default_password.py`) |
| Device token | Vive en el robot; rotar al recuperar acceso |
| Cualquier credencial futura (WiFi, servicios) | Agregar acá, jamás al repo |

Accesos:

| Quién | Acceso | Rol |
|---|---|---|
| Mantenedores humanos (Carlos, quien continúe) | Cuenta propia en la org | Read/Write |
| SpeedRacer (agente Hermes) | Machine account propio | Read (o Read/Write si debe rotar) |
| CI de GitHub | GitHub Actions secrets o machine account | Read |
| PC de la universidad | Machine account propio (`BWS_ACCESS_TOKEN` en su `.env`) | Read |

## 4. Límites del plan Free (verificado en docs oficiales, sep-2026)

- **2 usuarios humanos** · **3 proyectos** · **3 machine accounts** · secretos ilimitados
- Para el equipo actual (Carlos + 1-2 personas) **alcanza justo**.
- Si el equipo humano pasa de 2 → opciones:
  - **Teams**: $6/usuario/mes, sin límites
  - **Vaultwarden self-hosted**: gratis y sin límites; para eso hay que
    hostearlo (ej. en una VM ARM 24/7) **con backups diarios cifrados**
    (tar + age/gpg → repo privado + segundo destino) — el backup del vault
    está cifrado por diseño, pero se cifra igual por defensa en profundidad.

> **Decisión de escalado:** mientras el equipo sea ≤2 humanos, seguir en BWS
> Free. Migrar a Vaultwarden solo cuando duela (3+ personas).

## 5. Hoja de ruta (cuando haya acceso)

1. Crear el proyecto `deepracer-robot` en BWS.
2. Guardar los secretos actuales (password API, device token).
3. **Rotar password y device token** primero (los viejos están en BWS como
   `DEEPRACER_LEGACY_*`; ver `CREDENTIAL_ROTATION.md`).
4. Crear machine account para SpeedRacer + para el PC de la U; poner cada
   token en su `.env` local (`.env` sigue ignorado por git).
5. Invitar a los mantenedores humanos con su propia cuenta.
6. Documentar en `docs/operations/` cómo cada rol accede a los secretos.

## 6. Reglas duras

- ❌ Nunca escribir un secreto en el repo (gitleaks en CI lo caza igual).
- ❌ Nunca compartir un access token entre humanos.
- ❌ Nunca un `.env` "del equipo" por Drive/WhatsApp.
- ✅ Rotar al salir alguien del proyecto.
- ✅ `CREDENTIAL_ROTATION.md` es la fuente de verdad de rotaciones.

---

## 7. Opción A — Vault local + QR (costo $0, apertura manual)

> Para PC compartido del aula con 3-4 operadores. BWS Free solo da 2
> humanos; esta opción no depende de cuentas en la nube.

**Idea:** las credenciales viven en UN archivo cifrado (`secrets.age`,
con `age`), cuya llave se deriva de DOS partes: algo que sabés (PIN del
equipo) + algo que tenés (secreto de 32 bytes impreso como QR). Sin las
dos partes no se abre nada. Nunca hay `.env` en texto plano en disco.

- **Generar (una vez, en máquina confiable):** secreto aleatorio 32 bytes
  → QR impreso/laminado → cada uno de los 4 lo guarda en su celu (NO
  pegado en la pared). Con `PIN + secreto_QR` se cifra el vault inicial.
- **Abrir (cada jornada):** correr `scripts/vault/unlock-vault.ps1` → pide el
  PIN + escanear el QR con la webcam (OpenCV + pyzbar) o pegarlo a mano
  → descifra a RAM, inyecta env vars y arranca el backend. Nada queda
  en disco.
- **Cerrar:** `scripts/vault/lock-vault.ps1` mata el backend y limpia las vars.
  Se dispara solo al bloquear Windows, tras X horas, o manual.
- **Si se filtra:** una FOTO del QR sola no alcanza (falta el PIN). Si
  alguien sale del equipo se regenera QR + PIN y se re-cifra (5 min).
- **Límite honesto:** el QR NO se auto-detecta. Hay que escanearlo a
  propósito cada vez. Si querés "lo conecto y se abre solo", eso es la
  Opción B (USB).

## 8. Opción B — Vault local + USB keyfile (auto-detect, ~$5)

> **Estado: implementada** en `scripts/vault/` (2026-09-10, con `age` +
> `age-plugin-batchpass`; ver `scripts/vault/README.md`). Modelo **una
> identidad por persona**: cada quien tiene su llave en su USB protegida con su
> PIN y el vault se cifra a la unión de llaves públicas (alta con
> `new-identity.ps1`, revocación con `add-recipient.ps1`). Falta probarla en el
> PC de la U con las cuentas Windows/BitLocker del pre-requisito.

**Idea:** igual que la Opción A, pero la mitad física vive en una USB
(identidad `age` de cada persona, cifrada con su PIN) en vez de un QR.
Windows SÍ detecta la USB sola, así que el bloqueo puede ser automático.

- **Generar:** cada persona crea su identidad en su USB (identificada por su
  Volume Serial, no por letra `E:`/`F:`) con `scripts/vault/new-identity.ps1`;
  su llave pública entra en `recipients.txt` y `scripts/vault/init-vault.ps1`
  cifra `secrets.age` a la unión de llaves. Una USB por persona.
- **Abrir:** `scripts/vault/unlock-vault.ps1 -StartBackend` verifica la USB por
  serial, pide el PIN, descifra la identidad y el vault a RAM y levanta el
  backend con las variables inyectadas. Un watcher (`scripts/vault/watch-vault.ps1`,
  tarea programada con `install-watcher.ps1`) avisa por log al insertar la USB:
  el PIN exige consola, así que el desbloqueo es manual (no hay prompt en un
  watcher de fondo).
- **Cerrar:** al EXTRAER la USB el watcher corre `scripts/vault/lock-vault.ps1`
  → mata el backend del vault (las credenciales viven solo en la memoria de ese
  proceso y mueren con él). Cerrá también la consola que corrió el unlock: el
  proceso PowerShell que lo ejecutó conserva las variables en su entorno. Sin
  USB puesta no hay credenciales vivas.
- **Si se pierde/roba:** una copia de la identidad + PIN abre el vault, así que
  el PIN es obligatorio y conviene ser largo. Se revoca re-cifrando sin la llave
  de esa persona (`add-recipient.ps1`).
- **Costo:** una USB cualquiera (~$5). Lo único "automático" de las dos
  opciones.

## 9. Matriz y protocolo de prueba (probar A primero, B después)

| | QR (A) | USB (B) |
|---|---|---|
| Costo | $0 | ~$5 |
| Auto-detect | No (escaneo manual) | Sí (insertar/sacar) |
| Copiable a escondidas | Sí (foto) | Sí (copia archivo) |
| Mitigación | PIN obligatorio + rotación | PIN obligatorio + rotación |
| Ideal para | Probar YA sin comprar nada | Uso diario si el escaneo aburre |

**Pre-requisito de ambas (sin esto todo es cosmético):** cuentas de
Windows individuales + BitLocker + bloqueo automático de sesión. Si el PC
queda con sesión abierta, ningún vault sirve.

**Prueba A (QR):** generar QR de prueba → cifrar UN secreto falso →
probar unlock/lock en el PC de la U → medir tiempo y fricción.
**Prueba B (USB):** misma prueba con USB + watcher → verificar que al
sacar la USB el backend muere y las vars se limpian.
**Éxito:** abrir <1 min, cerrar automático verificado, nadie dejó texto
plano, rotación practicada una vez.

> Nota 2FA: QR+PIN (o USB+PIN) YA es 2FA — posesión + conocimiento. El
> TOTP tipo Google Authenticator es OTRO 2FA distinto, para logins online
> (GitHub), no para descifrar archivos locales porque rota cada 30 s.
> Se usan los dos: TOTP para GitHub, QR/USB+PIN para el vault del robot.

---

*Patrón aplicado: el mismo stack de secretos que usa la infraestructura
personal del mantenedor (BWS + machine accounts), adaptado a un repo con
varios operadores.*