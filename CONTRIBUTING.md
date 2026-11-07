# Cómo contribuir

Gracias por querer aportar. Este repo es un proyecto de robótica STEAM con hardware real: un cambio descuidado puede mover un vehículo o romper una demostración. Por eso pedimos tres cosas simples.

## Antes de escribir código

- **Abre un issue** si el cambio toca hardware, el protocolo del backend, la API o la arquitectura. Sirve para acordar el enfoque antes de que alguien escriba 800 líneas.
- Para typos, docs y arreglos evidentes no hace falta: manda el PR directamente.

## Qué debe traer un PR

El cuerpo del PR responde a cuatro preguntas (la plantilla las pide):

1. **Qué cambia** — en dos o tres líneas.
2. **Por qué** — el problema real, no la solución que te gusta.
3. **Cómo lo probaste** — el comando, el test o la prueba física. «No lo probé» es una respuesta válida; mentir no.
4. **Riesgo** — qué puede romperse y cómo se revierte.

Además:

- **Un PR, un tema.** Un refactor y un feature en el mismo PR se revisan mal y se revierten peor.
- **Conventional Commits 1.0.0** en los mensajes (`type(scope): imperativo`, ≤72 caracteres).
- **Nada de secretos**: ni `.env`, ni tokens, ni claves, ni `state.db`. Si necesitas una credencial para probar, dilo en el issue.
- **Docs en el mismo cambio** que el código: si añades un módulo, actualiza el índice de su carpeta.

## Pruebas

Corre lo que exista antes de pedir revisión y di qué corriste. Si el cambio toca el vehículo, el movimiento se prueba **solo** con autorización, operador y zona despejada: nunca como parte automática del PR.

## Revisión

Todo entra por PR. Un revisor automático (Kiro) comenta en cada uno y publica el estado `kiro-review`; un humano decide el merge. Si el revisor marca Major, la conversación va en el PR, no por fuera.

## Idioma

Español, aquí y en los issues. El resto de repos públicos del autor van en inglés.

## Licencia

Al enviar un PR aceptas que tu contribución se publique bajo la licencia del repositorio.
