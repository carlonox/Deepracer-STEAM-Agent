# Revisor propio de PRs (gratuito)

> **Estado:** implementado en rama `feature/pr-reviewer` (PR pendiente).
> **Fecha:** 2026-09-08. **Costo:** $0 (Actions + OpenRouter tier gratuito:
> 50 req/día y 20/min; 1000/día solo con $10 en créditos alguna vez).

## Qué es

Un segundo revisor automático junto a CodeRabbit, especializado en las
reglas **de este robot** que el genérico no conoce (canal backend-only,
gates físicos, Conventional Commits del repo). Stack: **PR-Agent**
(open-source, Apache 2.0, comunidad) como GitHub Action + modelos vía
**OpenRouter** (tier gratuito, ~1000 req/día: sobra a este volumen).

## Archivos

| Archivo | Rol |
|---|---|
| `.github/workflows/pr-reviewer.yml` | Corre en cada PR (`opened`, `synchronize`, `reopened`, `ready_for_review`). Se omite si falta el secreto o si el autor es un bot. |
| `.pr_agent.toml` | Modelo barato + `fallback_models`, respuesta en español e `extra_instructions` con las reglas del robot. PR-Agent ya lee `AGENTS.md` y `SKILL.md` por defecto. Ojo bootstrap: el toml solo se lee desde `main`, así que el workflow lleva modelo/fallback/`pr_actions` por env hasta el merge. |

## Secreto requerido (lo pone un mantenedor, nunca en el repo)

`Settings → Secrets and variables → Actions → New repository secret`:

- Nombre: `OPENROUTER_API_KEY` — valor: la key de OpenRouter.

Sin ese secreto el workflow se salta en silencio y CodeRabbit sigue solo.
La key también alimenta futuros usos (swarm en Oracle, scripts locales).

## GitHub Pro (universidad)

La cuenta Pro del equipo amplía los **minutos mensuales de Actions**
respecto al Free, así que el revisor + CI + secret-scan corren sin pelear
cuota. No habilita nada de CodeRabbit (es otro vendor): el "Pro" que
importa acá es minutos de runner + las reglas de protección de rama.

## Estado real de MCP y skills (verificado 2026-09-08, sin humo)

- **MCP asignado: ninguno.** El action PR-Agent hace llamadas single-shot
  sin tool-use loop: no ejecuta scripts ni consume MCP servers. Un MCP solo
  cabe en un job custom aparte (runner levanta el server y lo consume en el
  mismo job) — futuro, no actual.
- **Skills cargadas hoy:** `AGENTS.md` (auto-inyección de PR-Agent) +
  `extra_instructions` escritas a mano en `.pr_agent.toml`. Los 4
  `SKILL.md` de `hermes/skills/robotics/` **no** los carga: `skills.paths`
  es solo host-level por seguridad (un repo que lo definiera podría exfiltrar
  archivos del host al prompt) y se ignora con warning si viene del repo.
- Para que las skills pesen de verdad hay dos vías: destilar sus reglas a
  `extra_instructions` (hecho) o un job revisor custom que lea
  `hermes/skills/**` como contexto (pendiente, patrón Thalor expert-panel).

## Qué puede hacer un Action (MCP, skills, herramientas: sí, gratis)

Un runner de GitHub es una VM completa por minutos: puede correr lo mismo
que este PC, todo con software libre:

- **Skills del repo como contexto**: PR-Agent inyecta `AGENTS.md`/`SKILL.md`;
  cualquier Action puede leer `hermes/skills/**` y decidir con ellas.
- **MCP**: un step puede levantar un MCP server (`npx`, Docker) y
  consumirlo en el mismo job. Útil a futuro: servidor de contratos del
  simulador, secret-scan local, auditoría de docs.
- **Verificación ejecutable (mejor que opinar)**: pytest del simulador,
  `node --check`, build del frontend — el CI ya lo hace; el paso natural
  es que el revisor *cite* esos resultados en vez de adivinar.
- **Determinista antes que LLM**: commit-linter y secret-scan cuestan
  0 requests. El LLM entra solo para juicio (safety, diseño).

## Límites honestos

- Los modelos gratis rotan y rate-limitan; por eso hay `fallback_models`
  y el `auto_improve`/`auto_describe` están apagados (menos ruido, menos
  requests). Solo `auto_review`.
- No reemplaza la aprobación humana (Fase 8): es señal, no voto.
- Si el diff toca movimiento/secretos/gobernanza y el revisor no lo marca,
  igual aplica la regla — el humano manda.

## Futuro (swarm en Oracle)

Cuando exista la VM Always Free: daemon revisor persistente (patrones
multi-agente de Thalor: expert-panel, sister-bridge), Vaultwarden co-hosteado
y este mismo `.pr_agent.toml` como base de prompts. Este doc es el punto de
partida para que el otro agente (casa) continúe sin preguntar de cero.
