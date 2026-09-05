# Plan de hardening — firewall y red del robot

> **Fecha:** 2026-09-05
> **Estado:** pendiente (requiere acceso al robot y al PC de la U)
> **Audiencia:** mantenedores del repo / quien continúe el proyecto

---

## 1. Contexto (por qué existe este plan)

Historia real: el firewall del DeepRacer daba errores constantes — se
configuraban reglas, se reiniciaba el carro y **los cambios se perdían**.
Por frustración se terminaron abriendo muchos puertos y la seguridad de red
del robot quedó debilitada (superficie de ataque innecesaria en la red de la U).

**Este plan revierte eso.** No es urgente-riesgo para hoy (el robot está en una
red local de universidad, no expuesto directo a internet), pero **debe hacerse
antes de volver a operar el robot en serio**.

## 2. Causa raíz del problema original

El firewall del carro no persiste las reglas en caliente: `iptables`/`ufw`
cargados a mano se pierden en el reboot (o el carro restaura configs).
Por eso "reiniciaba el carro y se cambiaban las cosas" → el ciclo de abrir
puertos de más, por estrés.

**El fix real no es abrir más puertos: es hacer que las reglas persistan y
dejar de depender de puertos abiertos.**

## 3. Estrategia: acceso por Tailscale, cero puertos en la red física

El robot está detrás de NAT ajeno (WiFi de la U): IP estática no sirve (no
se pueden abrir puertos en un router que no controlamos). **Tailscale**
(mesh VPN WireGuard que perfora NAT) es la solución — por eso el proyecto
ya lo usa. Lo que hay que hacer es *aplicarlo bien*:

- El robot se une al tailnet **del proyecto** (migrar fuera de la cuenta
  personal anterior — el tailnet debe ser propiedad del proyecto, no de una
  persona).
- **Cerrar puertos en las interfaces físicas** y permitir acceso **solo por
  `tailscale0`**.

## 4. Checklist de hardening (15 minutos, con el robot enfrente)

```bash
# 1. Auditar qué quedó abierto
ss -tlnp

# 2. Política por defecto: denegar todo lo entrante en interfaces físicas
sudo ufw default deny incoming

# 3. Permitir SOLO lo necesario y SOLO por el tailnet
sudo ufw allow in on tailscale0 to any port 22 proto tcp      # SSH
sudo ufw allow in on tailscale0 to any port 5001 proto tcp    # API web (según contrato real)
sudo ufw allow in on tailscale0 to any port 8080 proto tcp    # cámara (según contrato real)

# 4. Activar y PERSISTIR (el paso que faltaba antes)
sudo ufw enable
sudo netfilter-persistent save
```

Verificación final:

- Desde el tailnet → SSH/API/cámara funcionan. ✅
- Desde la red local SIN Tailscale → nada responde (timeout/denegado). ✅
- `sudo reboot` → las reglas siguen activas después del reinicio. ✅

## 5. Tareas asociadas (mismo bloque de trabajo)

1. **Migrar el tailnet a una cuenta del proyecto** (o del mantenedor actual):
   crear tailnet nuevo → unir robot + PC de la U + nodos → sacar del tailnet
   de la cuenta anterior. Media hora, y el acceso deja de depender de una
   persona ajena.
2. **Rotar credenciales** al recuperar acceso (ver `CREDENTIAL_ROTATION.md`):
   password API web (regenerable desde serial) y device token.
3. **Verificar usuarios SSH** autorizados en el robot: solo claves conocidas
   (las públicas van en el repo/AGENTS.md, las privadas jamás).
4. Revisar qué servicios escuchan en `0.0.0.0` vs `127.0.0.1`/tailscale0 —
   si algo no necesita red, que escuche solo local.

## 6. Regla para el futuro

> **Nunca abrir un puerto "para que funcione" sin registrar por qué y sin que
> persista.** Si algo no conecta: primero Tailscale, después firewall, después
> preguntar. El estrés de "abro todo" es exactamente lo que este plan previene.