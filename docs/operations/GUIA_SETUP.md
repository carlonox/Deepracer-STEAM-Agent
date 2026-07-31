# 🚗 Guía de Setup y Control — AWS DeepRacer STEAM Agent

> Guía práctica completa para configurar, encender y controlar el vehículo AWS DeepRacer desde cero.

---

## 📋 Tabla de Contenidos

1. [Material necesario](#1-material-necesario)
2. [Encendido y conexión física](#2-encendido-y-conexión-física)
3. [Acceso SSH](#3-acceso-ssh)
4. [Opción 1: Control vía Interfaz Web (recomendado)](#4-opción-1-control-vía-interfaz-web-recomendado)
   - 4.1 Iniciar backend
   - 4.2 Iniciar frontend
   - 4.3 Controles por teclado
   - 4.4 Controles por gamepad
   - 4.5 Visualización de cámara
5. [Opción 2: Control por SSH + ROS2 (avanzado)](#5-opción-2-control-por-ssh--ros2-avanzado)
   - 5.1 Script básico de movimiento
   - 5.2 Control por teclado (SSH)
   - 5.3 Control por joystick (SSH)
6. [Opción 3: API Web directa](#6-opción-3-api-web-directa)
7. [Solución de problemas](#7-solución-de-problemas)
8. [Referencia rápida de comandos](#8-referencia-rápida-de-comandos)

---

## 1. Material Necesario

| Material | Descripción |
|----------|-------------|
| 🚗 **AWS DeepRacer** | Vehículo con batería cargada |
| 🔌 **Batería / Power Bank** | Fuente de alimentación para el vehículo |
| 📺 **Monitor HDMI** | Para configuración inicial y diagnóstico |
| 🖱️ **Ratón USB** | Para interactuar con la interfaz del vehículo |
| ⌨️ **Teclado USB** | Opcional, para comandos en el vehículo directamente |
| 💻 **Computadora** | Para ejecutar la interfaz web o conectarse por SSH |
| 🌐 **Red Wi-Fi** | Ambos dispositivos en la misma red |

> **⚠️ Nota:** Si usas un power bank, asegúrate de que proporcione suficiente amperaje para el DeepRacer (mínimo recomendado: 5V/2A).

---

## 2. Encendido y Conexión Física

1. **Conecta el DeepRacer al monitor** mediante cable HDMI.
2. **Conecta un ratón USB** al puerto disponible del vehículo.
3. **Conecta la batería** o power bank al vehículo.
4. **Enciende el vehículo** (el botón de encendido varía según modelo).
5. Espera a que el sistema operativo cargue (~1-2 minutos).
6. **Obtén la dirección IP** del vehículo abriendo una terminal en el monitor:

```bash
ip addr show
# o alternativamente:
ifconfig
```

Busca la dirección bajo la interfaz `wlan0` (Wi-Fi) o `eth0` (Ethernet). Generalmente tiene el formato `10.x.x.x` o `192.168.x.x`.

5. **Anota la IP** — la necesitarás para todos los pasos siguientes.

> **💡 Tip:** Si el vehículo y tu computadora están en redes diferentes, no podrás conectarte. Asegúrate de que ambos estén en la **misma red Wi-Fi**.

---

## 3. Acceso SSH

SSH es la forma de acceder al vehículamente remotamente desde tu computadora.

### Credenciales por defecto

| Campo | Valor |
|-------|-------|
| **Usuario** | `deepracer` |
| **Contraseña** | `${DEEPRACER_SSH_PASSWORD}` |

### Conectarse desde tu computadora

```bash
ssh deepracer@IP_DEL_DEEPRACER
```

Ejemplo:
```bash
ssh deepracer@10.203.139.55
```

### Si SSH no funciona

Ejecuta estos comandos **directamente en el vehículo** (con teclado y monitor):

```bash
# Regenerar claves del servidor SSH
sudo ssh-keygen -A

# Verificar que el servicio SSH está corriendo
sudo systemctl status sshd

# Si no está activo, iniciarlo:
sudo systemctl start sshd
sudo systemctl enable sshd
```

### Verificar conexión exitosa

Si la conexión es exitosa, verás un prompt como:
```
deepracer@deepracer:~$
```

> **💡 Tip:** Para salir de la sesión SSH, escribe `exit` o presiona `Ctrl + D`.

---

## 4. Opción 1: Control vía Interfaz Web (Recomendado)

Esta es la forma más cómoda y visual de controlar el vehículo, con controles por teclado y gamepad integrados.

### Arquitectura

```
[Tu computadora]
    │
    ├── Frontend (React) ────────── localhost:5173
    │       │
    │       ▼
    ├── Backend (Express) ──────── localhost:5002
    │       │
    │       ▼
    └── Servidor del DeepRacer ──── localhost:5001 (en el vehículo)
                                        │
                                        ├── /api/drive_mode
                                        ├── /api/start_stop
                                        ├── /api/manual_drive
                                        └── /login
```

### Protocolo de comunicación con el vehículo

El backend se autentica con el servidor del DeepRacer mediante:
1. `GET /login` → extrae token CSRF de la respuesta.
2. `POST /login` → envía contraseña + token CSRF.
3. Mantiene cookies de sesión para peticiones posteriores.

| Detalle | Valor |
|---------|-------|
| **Contraseña del servidor del vehículo** | `${DEEPRACER_API_PASSWORD}` |
| **Servidor de control** | `localhost:5001` (cuando se accede desde el vehículo) |
| **Protocolo** | HTTP (configurable a HTTPS) |

### 4.1 Iniciar Backend

El backend es un servidor en **Node.js + Express** que actúa como puente entre el frontend y el vehículo.

**Especificaciones:**
- Puerto: `5002`
- Módulos: ES modules (`"type": "module"` en package.json)
- Dependencias: `express ^5.1.0`, `cors ^2.8.5`

**Pasos:**

1. Abre una terminal en tu computadora.
2. Navega al directorio del proyecto:

```bash
cd C:\Deepracer-STEAM-Agent\backend
```

3. Instala dependencias (solo la primera vez):

```bash
npm install
```

4. Inicia el servidor:

```bash
npm start
```

5. Deberías ver un mensaje indicando que el servidor está corriendo en el puerto 5002.

> **⚠️ Importante:** El backend debe estar corriendo **antes** de abrir el frontend.

### API Endpoints del Backend

| Método | Endpoint | Descripción | Body |
|--------|----------|-------------|------|
| `POST` | `/api/start` | Activa modo manual en el vehículo | — |
| `POST` | `/api/stop` | Detiene el vehículo | — |
| `POST` | `/api/manual_drive` | Envía comandos de movimiento | `{ angle, throttle, max_speed }` o `{ init: true }` |
| `GET` | `/api/video_stream` | Stream de video de la cámara | — |

### 4.2 Iniciar Frontend

El frontend es una aplicación **React + Vite + Tailwind CSS + DaisyUI** que proporciona la interfaz gráfica.

**Especificaciones:**
- Puerto de desarrollo: `5173`
- Framework: React
- Build tool: Vite
- CSS: Tailwind CSS + DaisyUI

**Pasos:**

1. Abre una **nueva terminal** (mantén el backend corriendo).
2. Navega a la raíz del proyecto:

```bash
cd C:\Deepracer-STEAM-Agent
```

3. Instala dependencias (solo la primera vez):

```bash
npm install
```

4. Inicia el servidor de desarrollo:

```bash
npm run dev
```

5. Abre tu navegador en:

```
http://localhost:5173
```

**Para producción (opcional):**

```bash
npm run build
```

Esto genera los archivos estáticos en la carpeta `dist/`.

### Estados del vehículo en la interfaz

| Estado | Significado |
|--------|-------------|
| 🔴 **Detenido** | El vehículo está detenido |
| 🟢 **Automático activo** | El vehículo conducción autónoma |
| 🟡 **Control manual activo** | El vehículo está en modo manual y recibe comandos |

### 4.3 Controles por Teclado

Los controles están activos cuando la ventana del navegador está enfocada.

| Tecla | Acción | Comando enviado |
|-------|--------|-----------------|
| ↑  o **W** | Avanzar recto | `angle=0, throttle=-100` |
| ↓  o **S** | Retroceder recto | `angle=0, throttle=+100` |
| ←  o **A** | Girar izquierda | `angle=-45, throttle=-100` |
| →  o **D** | Girar derecha | `angle=+45, throttle=-100` |

**Combinaciones diagonales:**
- **↑ + →** = Avanzar girando a la derecha
- **↑ + ←** = Avanzar girando a la izquierda
- **↓ + →** = Retroceder girando a la derecha
- **↓ + ←** = Retroceder girando a la izquierda

**Al soltar todas las teclas:**
- El vehículo se detiene (`angle=0, throttle=0`).

> **⚠️ Convención invertida del throttle:**
> - `throttle` **negativo** (ej: `-100`) = vehículo **avanza**.
> - `throttle` **positivo** (ej: `+100`) = vehículo **retrocede**.
>
> Esto es normal en la API del DeepRacer.
>
> **🎛️ Calibración de zona muerta (2026-07-31):** este robot tiene una zona
> muerta de ~`|50|` (valores entre 0 y ~50 no mueven los motores; verificado en
> vivo: 45 no mueve, 50 sí). El **dashboard del robot** usa valores crudos
> (`-100..100`, mínimo efectivo ~50). Las interfaces que pasan por el **backend
> local (`apps/backend`)** — frontend, agente, navegación — envían throttle
> **normalizado** `[-1, 1]` (0 = parada) y el backend aplica la calibración
> automáticamente (`THROTTLE_DEAD_ZONE=0.5` en `.env`): 0.1 → ~0.55 real,
> 0.5 → 0.75 real, 1 → 1. Ver `apps/backend/API.md`.

**🚨 Seguridad automática:**
- Si cambias de pestaña o minimizes la ventana (`blur` / `visibilitychange`), el sistema: **suelta todas las teclas** y **envía comando de parada** automáticamente.

### 4.4 Controles por Gamepad

La interfaz detecta automáticamente mandos USB/Bluetooth conectados a la computadora.

#### Modo Joystick

| Control | Función | Rango |
|---------|---------|-------|
| Stick izquierdo X | Ángulo de dirección | `-45°` a `+45°` |
| Stick izquierdo Y | Velocidad (throttle) | `-100` a `+100` |

#### Modo Triggers (alternativo)

| Control | Función |
|---------|---------|
| Trigger derecho (BTN 7) | Acelerar adelante |
| Trigger izquierdo (BTN 6) | Retroceder |
| Stick izquierdo X | Ángulo de dirección |

#### Botones adicionales

| Botón | Función |
|-------|---------|
| **LB** (BTN 4) | Reducir velocidad máxima |
| **RB** (BTN 5) | Aumentar velocidad máxima |
| **D-PAD** (BTN 12-15) | Dirección (analaógico) ↑↓←→ |

**Zonas muertas (dead zones):**
- Ejes analógicos: `0.15` (ignora movimientos menores).
- Triggers: `0.05`.

> **💡 Tip:** El sistema actualiza los controles a la tasa de `requestAnimationFrame` (~60fps) y **solo envía comandos cuando los valores cambian significativamente**, reduciendo tráfico de red.

### 4.5 Visualización de Cámara

Hay dos formas de ver el stream de la cámara del DeepRacer:

#### Opción A: Vía Backend Proxy (recomendada)

```
http://localhost:5002/api/video_stream
```

- **Resolución:** 480×360
- **Fuente que consulta el backend:** `http://10.203.139.55:443/camera_pkg/display_mjpeg`
- Funciona sin necesidad de abrir puertos adicionales.
- El backend actúa como intermediario y retransmite el stream.

#### Opción B: Stream Directo ROS

```
http://IP_DEL_DEEPRACER:8080/stream?topic=/camera_pkg/display_mjpeg&width=1280&height=720
```

- **Resolución:** 1280×720 [HD]
- **Requiere:** Puerto 8080 accesible en el vehículo (`rosbridge` / `web_video_server`).
- Menor latencia al no pasar por el backend.

Ejemplo:
```
http://10.203.139.55:8080/stream?topic=/camera_pkg/display_mjpeg&width=1280&height=720
```

> **💡 Tip:** Si el puerto 8080 no responde, asegúrate de que el nodo `web_video_server` esté corriendo en el DeepRacer. Ver solución de problemas.

---

## 5. Opción 2: Control por SSH + ROS2 (Avanzada)

Para usuarios experimentados que quieren controlar el vehículo directamente mediante ROS2.

### Prerrequisitos

- Acceso SSH al DeepRacer (ver sección 3).
- ROS2 instalado en el vehículo (incluido por defecto).
- Conocimientos básicos de ROS2.

### 5.1 Script Básico de Movimiento

Crea un nodo ROS2 en Python que publique comandos de velocidad al tópico `/cmd_vel`:

```python
#!/usr/bin/env python3
"""
Script básico de movimiento para AWS DeepRacer mediante ROS2.
Publica mensajes Twist al tópico /cmd_vel.
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class DeepRacerController(Node):
    def __init__(self):
        super().__init__('deepracer_controller')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.get_logger().info('Nodo de control iniciado.')

    def move(self, linear_x: float, angular_z: float):
        """
        Publica un comando de velocidad.

        Args:
            linear_x: Velocidad lineal (positivo = adelante, negativo = atrás).
            angular_z: Velocidad angular (positivo = giro izquierda, negativo = giro derecha).
        """
        msg = Twist()
        msg.linear.x = linear_x
        msg.angular.z = angular_z
        self.publisher.publish(msg)
        self.get_logger().info(f'Moviendo: linear_x={linear_x}, angular_z={angular_z}')

    def stop(self):
        """Detiene el vehículo."""
        self.move(0.0, 0.0)
        self.get_logger().info('Vehículo detenido.')


def main(args=None):
    rclpy.init(args=args)
    controller = DeepRacerController()

    # Ejemplo: avanzar 2 segundos, detener
    controller.move(1.0, 0.0)
    rclpy.spin_once(controller, timeout_sec=2.0)

    controller.stop()
    controller.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
```

**Cómo ejecutar:**

```bash
python3 deepracer_controller.py
```

### 5.2 Control por Teclado (SSH)

Para control interactivo por teclado vía SSH:

```python
#!/usr/bin/env python3
"""
Control interactivo del DeepRacer por teclado vía SSH.
Usa las teclas WASD para mover el vehículo.
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
import tty
import termios
import select


def get_key():
    """Lee una tecla sin esperar Enter."""
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(fd)
        rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
        if rlist:
            ch = sys.stdin.read(1)
        else:
            ch = ''
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return ch


class KeyboardController(Node):
    LINEAR_SPEED = 1.0
    ANGULAR_SPEED = 0.5

    def __init__(self):
        super().__init__('keyboard_controller')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.linear = 0.0
        self.angular = 0.0
        self.get_logger().info('Control por teclado activo. Usa WASD. Q para salir.')
        self.print_instructions()

    def print_instructions(self):
        print("""
╔══════════════════════════════════════╗
║   CONTROL POR TECLADO - DEEPRACER   ║
╠══════════════════════════════════════╣
║  W = Avanzar                         ║
║  S = Retroceder                      ║
║  A = Girar izquierda                 ║
║  D = Girar derecha                   ║
║  Q = Salir                           ║
║  (Cualquier otra tecla = detener)    ║
╚══════════════════════════════════════╝
        """)

    def timer_callback(self):
        key = get_key().lower()
        if key == 'q':
            self.get_logger().info('Saliendo...')
            self.stop()
            rclpy.shutdown()
            sys.exit(0)
        elif key == 'w':
            self.linear = self.LINEAR_SPEED
            self.angular = 0.0
        elif key == 's':
            self.linear = -self.LINEAR_SPEED
            self.angular = 0.0
        elif key == 'a':
            self.angular = self.ANGULAR_SPEED
        elif key == 'd':
            self.angular = -self.ANGULAR_SPEED
        else:
            self.linear = 0.0
            self.angular = 0.0

        msg = Twist()
        msg.linear.x = self.linear
        msg.angular.z = self.angular
        self.publisher.publish(msg)

    def stop(self):
        msg = Twist()
        self.publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = KeyboardController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
```

### 5.3 Control por Joystick (SSH)

```python
#!/usr/bin/env python3
"""
Control del DeepRacer con joystick vía SSH.
Requiere: pip install pygame
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import pygame


class JoystickController(Node):
    def __init__(self):
        super().__init__('joystick_controller')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.timer = self.create_timer(0.05, self.timer_callback)

        # Inicializar pygame
        pygame.init()
        pygame.joystick.init()

        if pygame.joystick.get_count() == 0:
            self.get_logger().error('⚠️  No se detectó ningún joystick.')
            raise RuntimeError('Joystick no conectado')

        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()
        self.get_logger().info(f'Joystick detectado: {self.joystick.get_name()}')

    def timer_callback(self):
        pygame.event.pump()

        # Stick izquierdo para ángulo y throttle
        axis_x = self.joystick.get_axis(0)
        axis_y = self.joystick.get_axis(1)

        # Aplicar zona muerta
        deadzone = 0.15
        if abs(axis_x) < deadzone:
            axis_x = 0.0
        if abs(axis_y) < deadzone:
            axis_y = 0.0

        # Botón de parada (BTN 0 = A típico)
        if self.joystick.get_button(0):
            axis_x = 0.0
            axis_y = 0.0

        msg = Twist()
        msg.linear.x = -axis_y  # Invertido: Y negativo = adelante
        msg.angular.z = -axis_x  # Invertido: X positivo = giro derecha
        self.publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = JoystickController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
```

---

## 6. Opción 3: API Web Directa

Puedes controlar el vehículo directamente mediante peticiones HTTP sin usar la interfaz gráfica.

### Script de prueba incluido: `move.js`

El proyecto incluye un script de prueba en la raíz que conecta directamente al servidor del vehículo:

```bash
node move.js
```

**Qué hace:**
1. Se autentica con el servidor del vehículo (`localhost:5001`).
2. Configura modo manual.
3. Inicia el vehículo.
4. Envía un comando de movimiento por **5 segundos**.
5. Detiene el vehículo.

### Script Python para control por API

```python
#!/usr/bin/env python3
"""
Control del DeepRacer mediante la API Web directa.
Útil para integración con otros sistemas o scripts.
"""

import requests
import time


class DeepRacerWebAPI:
    """Cliente para controlar el DeepRacer vía API Web."""

    def __init__(self, ip_address: str, password: str = "${DEEPRACER_API_PASSWORD}"):
        self.base_url = f"http://{ip_address}"
        self.password = password
        self.session = requests.Session()
        self._login()

    def _login(self):
        """Autentica con el servidor del vehículo."""
        # Obtener token CSRF
        login_page = self.session.get(f"{self.base_url}/login")
        # Extraer CSRF token (simplificado; en producción parsear HTML)
        csrf_token = self._extract_csrf(login_page.text)

        # Enviar credenciales
        response = self.session.post(
            f"{self.base_url}/login",
            data={"password": self.password, "csrf_token": csrf_token}
        )
        if response.status_code == 200:
            print("✅ Autenticación exitosa")
        else:
            raise Exception(f"❌ Error de autenticación: {response.status_code}")

    def _extract_csrf(self, html: str) -> str:
        """Extrae el token CSRF del HTML de login."""
        import re
        match = re.search(r'name="csrf_token"\s+value="([^"]+)"', html)
        if match:
            return match.group(1)
        # Alternativa: buscar en meta tags
        match = re.search(r'csrf.*?content="([^"]+)"', html, re.IGNORECASE)
        return match.group(1) if match else ""

    def set_manual_mode(self):
        """Configura el vehículo en modo manual."""
        response = self.session.post(
            f"{self.base_url}/api/drive_mode",
            json={"drive_mode": "manual"}
        )
        return response.json()

    def start(self):
        """Inicia el vehículo."""
        response = self.session.post(
            f"{self.base_url}/api/start_stop",
            json={"start_stop": "start"}
        )
        return response.json()

    def stop(self):
        """Detiene el vehículo."""
        response = self.session.post(
            f"{self.base_url}/api/start_stop",
            json={"start_stop": "stop"}
        )
        return response.json()

    def set_throttle_and_angle(self, throttle: float, angle: float, max_speed: float = 100):
        """
        Envía comando de movimiento.

        Args:
            throttle: Velocidad (-100 a 100). Negativo = adelante, positivo = atrás.
            angle: Ángulo de dirección (-45 a 45 grados).
            max_speed: Velocidad máxima permitida.
        """
        response = self.session.post(
            f"{self.base_url}/api/manual_drive",
            json={
                "throttle": throttle,
                "angle": angle,
                "max_speed": max_speed
            }
        )
        return response.json()


# === Ejemplo de uso ===
if __name__ == "__main__":
    # Reemplazar con la IP de tu DeepRacer
    DEEPRACER_IP = "10.203.139.55"

    api = DeepRacerWebAPI(DEEPRACER_IP)

    # Configurar modo manual e iniciar
    api.set_manual_mode()
    api.start()

    # Avanzar recto por 3 segundos
    print("Avanzando...")
    api.set_throttle_and_angle(throttle=-50, angle=0)
    time.sleep(3)

    # Girar a la derecha por 2 segundos
    print("Girando derecha...")
    api.set_throttle_and_angle(throttle=-50, angle=45)
    time.sleep(2)

    # Detener
    print("Deteniendo...")
    api.stop()
    print("✅ Secuencia completada")
```

### Peticiones curl directas

```bash
# Modo manual
curl -X POST http://IP_DEEPRACER:5001/api/drive_mode \
  -H "Content-Type: application/json" \
  -d '{"drive_mode": "manual"}'

# Iniciar
curl -X POST http://IP_DEEPRACER:5001/api/start_stop \
  -H "Content-Type: application/json" \
  -d '{"start_stop": "start"}'

# Mover (avanzar recto)
curl -X POST http://IP_DEEPRACER:5001/api/manual_drive \
  -H "Content-Type: application/json" \
  -d '{"throttle": -50, "angle": 0, "max_speed": 100}'

# Detener
curl -X POST http://IP_DEEPRACER:5001/api/start_stop \
  -H "Content-Type: application/json" \
  -d '{"start_stop": "stop"}'
```

---

## 7. Solución de Problemas

### No puedo conectarme por SSH

| Síntoma | Posible causa | Solución |
|---------|---------------|----------|
| `Connection refused` | SSH no está activo | Ejecutar `sudo systemctl start sshd` en el vehículo |
| `Connection timeout` | Diferente red | Verificar que ambos estén en la misma red Wi-Fi |
| `Permission denied` | Credenciales incorrectas | Verificar usuario `deepracer` y contraseña `${DEEPRACER_SSH_PASSWORD}` |
| `Host key changed` | Reimagen del vehículo | Ejecutar `ssh-keygen -R IP_DEL_DEEPRACER` |

### El vehículo no se mueve

| Síntoma | Posible causa | Solución |
|---------|---------------|----------|
| No responde a comandos | No está en modo manual | Enviar `POST /api/drive_mode` con `{"drive_mode": "manual"}` |
| No responde a comandos | No se ha iniciado | Enviar `POST /api/start_stop` con `{"start_stop": "start"}` |
| Se mueve muy lento | Batería baja | Cargar la batería |
| Se mueve en dirección opuesta | Convención invertida | Recordar: throttle negativo = adelante |

### La cámara no muestra video

| Síntoma | Posible causa | Solución |
|---------|---------------|----------|
| Stream no carga (puerto 5002) | Backend no corriendo | Verificar `npm start` en `/backend` |
| Stream no carga (puerto 8080) | `web_video_server` no activo | Iniciar en el vehículo: `ros2 run web_video_server web_video_server` |
| Imagen congelada | Conexión lenta | Reducir resolución en la URL del stream |
| Sin imagen | Cámara desconectada | Verificar conexión física de la cámara |

### El frontend no se conecta al backend

| Síntoma | Posible causa | Solución |
|---------|---------------|----------|
| `Failed to fetch` | Backend no corriendo | Iniciar backend con `npm start` |
| CORS error | Configuración incorrecta | Verificar que `cors` esté habilitado en `server.js` |
| Página en blanco | Build no generado | Ejecutar `npm run build` o usar `npm run dev` |

### El gamepad no funciona

| Síntoma | Posible causa | Solución |
|---------|---------------|----------|
| No se detecta | Navegador no soporta | Usar Chrome o Edge (Gamepad API) |
| No se detecta | No conectado antes de cargar | Conectar el gamepad ANTES de abrir la página |
| Botones incorrectos | Mapeo diferente | Revisar consola del navegador para ver botones |

---

## 8. Referencia Rápida de Comandos

### Valores de Configuración Importantes

| Valor | Ubicación | Descripción |
|-------|-----------|-------------|
| `localhost:5001` | `apps/backend/vehicleControl.js` | API de control del DeepRacer |
| `${DEEPRACER_API_PASSWORD}` | `apps/backend/vehicleControl.js`, `apps/frontend/scripts/move.js` | Contraseña del servidor del vehículo |
| `10.203.139.55:443` | `apps/backend/vehicleControl.js` | Fuente del stream de cámara |
| `5002` | `apps/backend/server.js` | Puerto del backend Express |
| `localhost:5002` | `src/services/vehicleApi.js` | Destino de la API del frontend |
| `8080` | `src/components/camera/CameraFeed.jsx` | Puerto ROS web_video_server |

> **⚠️ Nota:** Estos valores están hardcodeados. Si tu configuración es diferente, deberás modificarlos en los archivos indicados.

### Comandos de Inicio Rápido

```bash
# === DESDE TU COMPUTADORA ===

# 1. Iniciar backend (terminal 1)
cd C:\Deepracer-STEAM-Agent\backend
npm start

# 2. Iniciar frontend (terminal 2)
cd C:\Deepracer-STEAM-Agent
npm run dev

# 3. Abrir navegador
# http://localhost:5173

# === DESDE SSH EN EL VEHÍCULO ===

# Verificar SSH
sudo systemctl status sshd

# Obtener IP
ip addr show

# Iniciar web_video_server (si la cámara no funciona)
ros2 run web_video_server web_video_server
```

### Comandos de Emergencia

```bash
# Detener el vehículo inmediatamente (desde SSH)
curl -X POST http://localhost:5001/api/start_stop \
  -H "Content-Type: application/json" \
  -d '{"start_stop": "stop"}'

# Reiniciar el servicio SSH
sudo systemctl restart sshd

# Ver logs del sistema
journalctl -u sshd -f
```

### Atajos de Teclado (Interfaz Web)

```
╔═══════════════════════════════════════╗
║     CONTROLES DE TECLADO WEB         ║
╠═══════════════════════════════════════╣
║                                       ║
║        ┌───┐                          ║
║        │ ↑ │  Avanzar recto           ║
║    ┌───┼───┼───┐                      ║
║    │ ← │   │ → │  Girar izq / der     ║
║    └───┼───┼───┘                      ║
║        │ ↓ │  Retroceder              ║
║        └───┘                          ║
║                                       ║
║  W = ↑    S = ↓    A = ←    D = →    ║
║                                       ║
║  Soltar teclas = DETENER             ║
║  Cambiar pestaña = DETENER           ║
║                                       ║
╚═══════════════════════════════════════╝
```

---

## 📝 Notas Finales

- **Seguridad primero:** Siempre ten el vehículo sobre una superficie estable antes de enviar comandos de movimiento.
- **Batería:** Monitorea el nivel de batería. Un voltaje bajo puede causar comportamientos impredecibles.
- **Actualizaciones:** Los valores de configuración (IPs, puertos, contraseñas) pueden cambiar entre versiones del firmware del DeepRacer.
- **Convención de throttle:** Recuerda que en la API del DeepRacer, `throttle` negativo = adelante y positivo = atrás.

---

*Guía creada para el proyecto AWS DeepRacer STEAM Agent.*
