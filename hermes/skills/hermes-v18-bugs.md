\# Hermes v0.18.0 — Bugs Conocidos (Verificados)



\## Bug: Dashboard login devuelve 500 en ruta `/`

\- \*\*Ruta rota:\*\* `http://localhost:9999/` → redirige a `/auth/login?provider=basic` → 500

\- \*\*Ruta funcional:\*\* `http://localhost:9999/login` → muestra formulario → 200

\- \*\*Causa:\*\* Bug conocido de Hermes v0.18.0. El redirect de SSO llama `start\_login()` en BasicAuthProvider que lanza `NotImplementedError`.

\- \*\*Referencia:\*\* Hermes Issue #58237

\- \*\*Solución:\*\* Usar siempre `/login` directamente



\## Configuración auth que funciona

\- Auth va en `config.yaml` con `username` + `password` + `secret`

\- Las env vars `HERMES\_DASHBOARD\_BASIC\_AUTH\_\*` son IGNORADAS si `config.yaml` existe en bind mount

\- El campo `secret` es OBLIGATORIO en v0.18.0 (sin él, Starlette no inicializa SessionMiddleware)



\## Puerto del dashboard

\- Puerto interno nativo: \*\*9119\*\* (no 9999)

\- Mapeo en docker-compose: `9999:9119`

