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

*Patrón aplicado: el mismo stack de secretos que usa la infraestructura
personal del mantenedor (BWS + machine accounts), adaptado a un repo con
varios operadores.*