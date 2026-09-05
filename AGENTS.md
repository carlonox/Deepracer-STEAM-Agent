# Instrucciones de organización para agentes

Estas reglas aplican a todo el repositorio.

## Antes de modificar la estructura

1. Lee `ORGANIZACION_PROYECTO.md`, `README.md` y el README del componente.
2. Revisa `git status --short`; conserva todos los cambios previos del usuario.
3. Busca consumidores de cualquier ruta que vayas a mover o renombrar.
4. Clasifica el contenido como fuente, configuración pública, secreto,
   generado, persistente, documentación activa, histórico o binario.
5. Define una validación segura antes de editar.

## Reglas obligatorias

- Organiza por componente o responsabilidad, no por lenguaje.
- No añadas archivos nuevos en la raíz salvo configuración transversal,
  documentación de entrada o lanzadores principales.
- Cada componente mantenible debe tener un `README.md` actualizado.
- No combines movimientos con refactors funcionales.
- No muevas `node_modules`, entornos virtuales, `.pio`, cachés o logs como si
  fueran fuente; deben regenerarse.
- No muestres, copies ni documentes valores de `.env`, tokens, contraseñas,
  claves SSH o `auth.json`.
- Sigue `SECURITY.md` para almacenamiento, rotación y revisión previa al push.
- Trata `hermes/` como volumen persistente mixto. No muevas su estado interno
  con el contenedor activo y no alteres `./hermes:/opt/data` incidentalmente.
- Mantén `/workspace` y `/opt/data` como contratos hasta que una fase explícita
  del plan autorice cambiarlos.
- Usa rutas relativas al archivo o a la raíz detectada, no al CWD accidental.
- Actualiza código, configuración, documentación, skills e índices en la misma
  unidad de cambio.
- Una ruta antigua solo puede quedar en documentación histórica si está
  etiquetada como antigua.

## Seguridad del robot

- No ejecutes `start-deepracer.ps1`, `/api/start`, `/api/manual_drive`, scripts
  de manejo, comandos SSH de movimiento ni cargas de firmware como prueba
  automática.
- Las pruebas físicas requieren autorización explícita, operador presente,
  zona despejada, parada verificada y velocidad limitada.
- Prefiere validaciones estáticas, builds, mocks, fixtures y endpoints de salud.

## Commits y push (reglas obligatorias)

- Todos los commits siguen **Conventional Commits 1.0.0**:
  `<type>(<scope>): <descripción imperativa>` (≤72 chars, sin emojis, sin
  atribuciones automáticas). Skill de referencia:
  `hermes/skills/github/conventional-commits-deepracer/`.
- El detalle va en el **cuerpo** del mensaje, nunca en la primera línea.
- **NADIE hace push directo a `main`** (protección de rama activa). Todo
  cambio entra por **pull request** con al menos 1 review y CI en verde
  (`ci` + `secret-scan`).
- Prohibido `--force` a `main` (y en general, prohibido reescribir historial
  sin autorización explícita del mantenedor).
- Hooks locales: correr `scripts/install-hooks.sh` en cada clon que trabaje
  el robot (gitleaks pre-commit).
- Verificar antes de pushear: `git diff --cached` sin `.env`, claves,
  `state.db`, tokens ni certificados (`apps/simulator/certs/`).

## Gobernanza

- La rama `main` está protegida: PRs obligatorios, reviews, CI verde.
- Mantenedores del semestre: autorizados para mergear los PRs.
- Colaboradores externos: acceso SOLO como GitHub collaborators con permiso
  de escritura — nunca claves del repositorio personal del dueño.
- El agente del DeepRacer debe corregir formatos de commit en la revisión
  de PRs, jamás reescribir historial por su cuenta.

## Al añadir o retirar contenido

- Sigue las listas de comprobación de las secciones 12 y 13 de
  `ORGANIZACION_PROYECTO.md`.
- Enlaza componentes nuevos desde el README del padre y desde el índice raíz si
  son de primer nivel.
- Antes de retirar un archivo, demuestra que no tiene consumidores; archiva lo
  histórico y explica cómo regenerar lo generado.
- Si cambias la organización objetivo, actualiza el árbol, el mapa, el registro
  de decisiones y estas instrucciones en el mismo cambio.

## Cierre de una unidad de migración

1. Busca referencias a las rutas antiguas.
2. Ejecuta las puertas de validación aplicables.
3. Revisa que no aparezcan secretos ni generados.
4. Actualiza el registro de progreso del plan.
5. Informa qué fue validado y qué sigue pendiente.
