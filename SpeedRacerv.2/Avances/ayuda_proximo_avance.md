DeibydBarragan: necesito que analizando este respositorio me digas de qué manera podría manejar el carro aws deepracer ya sea usando la terminal remotamente con ssh o usando teclado o usando un mando, simplemente quiero poder escribir código en python para poder manejarlo de diferentes maneras

Workspace: Collecting workspace informationAnalizando tu workspace de AWS DeepRacer, te puedo explicar las diferentes formas de controlarlo:

## Formas de Controlar el AWS DeepRacer

### 1. **Control a través de ROS (Recomendado)**
Tu workspace tiene configuración ROS (ver archivos en lib/). Puedes publicar mensajes a tópicos ROS:

```python
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class DeepRacerController(Node):
    def __init__(self):
        super().__init__('deepracer_controller')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
    
    def move(self, linear_x, angular_z):
        msg = Twist()
        msg.linear.x = linear_x  # velocidad adelante/atrás (-1.0 a 1.0)
        msg.angular.z = angular_z  # giro izquierda/derecha (-1.0 a 1.0)
        self.publisher.publish(msg)

# Uso:
# rclpy.init()
# controller = DeepRacerController()
# controller.move(0.5, 0.0)  # avanzar
```

### 2. **Control con Teclado (SSH)**
Puedes usar `pynput` o `keyboard` para capturar teclas remotamente:

```python
from pynput import keyboard
import rclpy
from geometry_msgs.msg import Twist

class KeyboardControl:
    def __init__(self, publisher):
        self.publisher = publisher
        self.current_speed = 0.0
        self.current_turn = 0.0
    
    def on_press(self, key):
        try:
            if key.char == 'w':  # adelante
                self.current_speed = 0.5
            elif key.char == 's':  # atrás
                self.current_speed = -0.5
            elif key.char == 'a':  # izquierda
                self.current_turn = 0.5
            elif key.char == 'd':  # derecha
                self.current_turn = -0.5
            self.publish_cmd()
        except AttributeError:
            pass
    
    def on_release(self, key):
        if key == keyboard.Key.esc:
            return False
        self.current_speed = 0.0
        self.current_turn = 0.0
        self.publish_cmd()
    
    def publish_cmd(self):
        msg = Twist()
        msg.linear.x = self.current_speed
        msg.angular.z = self.current_turn
        self.publisher.publish(msg)
```

### 3. **Control con Mando/Joystick**
Usando la librería `pygame`:

```python
import pygame
import rclpy
from geometry_msgs.msg import Twist

class JoystickControl:
    def __init__(self, publisher):
        pygame.init()
        pygame.joystick.init()
        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()
        self.publisher = publisher
    
    def run(self):
        while True:
            pygame.event.pump()
            
            # Joystick izquierdo: eje 1 (vertical) para velocidad
            linear_x = -self.joystick.get_axis(1)  # invertido
            
            # Joystick derecho: eje 2 (horizontal) para giro
            angular_z = self.joystick.get_axis(2)
            
            # Deadzone
            if abs(linear_x) < 0.1:
                linear_x = 0.0
            if abs(angular_z) < 0.1:
                angular_z = 0.0
            
            msg = Twist()
            msg.linear.x = linear_x
            msg.angular.z = angular_z
            self.publisher.publish(msg)
```

### 4. **Iniciar el Sistema**
Primero debes ejecutar el script start_ros.sh para iniciar ROS:

```bash
ssh deepracer@<IP_DEL_DEEPRACER>
cd /path/to/workspace
./start_ros.sh
```

### 5. **API Web (Alternativa)**
El DeepRacer también tiene una API web. Puedes usar `requests`:

```python
import requests

class DeepRacerWebAPI:
    def __init__(self, ip_address):
        self.base_url = f"http://{ip_address}"
    
    def set_throttle_and_angle(self, throttle, angle):
        # throttle: -1.0 a 1.0
        # angle: -1.0 (izquierda) a 1.0 (derecha)
        endpoint = f"{self.base_url}/api/vehicle/control"
        data = {"throttle": throttle, "angle": angle}
        response = requests.post(endpoint, json=data)
        return response.json()
```

## Recomendación
**Usa ROS** ya que tu workspace está configurado para ello. Publica mensajes `Twist` al tópico `/cmd_vel` para controlar el vehículo. Esto funciona de forma remota vía SSH y es el método más estable.

DeibydBarragan: dime como hacer eso

GitHub Copilot: # Guía Completa para Controlar el AWS DeepRacer

## Paso 1: Conectar por SSH al DeepRacer

```bash
# Encuentra la IP de tu DeepRacer (mira en la consola web o router)
ssh deepracer@<IP_DEL_DEEPRACER>
# Contraseña por defecto: deepracer
```

## Paso 2: Instalar Dependencias en tu PC

```bash
# En tu PC Windows (PowerShell o CMD)
pip install rclpy geometry-msgs pygame pynput
```

## Paso 3: Crear Script Básico de Control

````python
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time

class DeepRacerController(Node):
    def __init__(self):
        super().__init__('deepracer_manual_controller')
        # Publicar comandos al DeepRacer
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.get_logger().info('DeepRacer Controller iniciado')
    
    def move(self, speed, turn):
        """
        speed: velocidad (-1.0 a 1.0) negativo=atrás, positivo=adelante
        turn: giro (-1.0 a 1.0) negativo=izquierda, positivo=derecha
        """
        msg = Twist()
        msg.linear.x = float(speed)
        msg.angular.z = float(turn)
        self.publisher.publish(msg)
        self.get_logger().info(f'Enviando: velocidad={speed}, giro={turn}')
    
    def stop(self):
        """Detener el carro"""
        self.move(0.0, 0.0)

def main():
    rclpy.init()
    controller = DeepRacerController()
    
    try:
        print("=== Control Manual AWS DeepRacer ===")
        print("Comandos: adelante, atras, izquierda, derecha, stop, salir")
        
        while True:
            comando = input("\nComando: ").lower().strip()
            
            if comando == "adelante":
                controller.move(0.5, 0.0)
            elif comando == "atras":
                controller.move(-0.5, 0.0)
            elif comando == "izquierda":
                controller.move(0.3, -0.5)
            elif comando == "derecha":
                controller.move(0.3, 0.5)
            elif comando == "stop":
                controller.stop()
            elif comando == "salir":
                controller.stop()
                break
            else:
                print("Comando no reconocido")
                
    except KeyboardInterrupt:
        print("\nDeteniendo...")
    finally:
        controller.stop()
        controller.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
````

## Paso 4: Control con Teclado (Tiempo Real)

````python
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from pynput import keyboard
import threading

class KeyboardController(Node):
    def __init__(self):
        super().__init__('keyboard_controller')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.speed = 0.0
        self.turn = 0.0
        self.max_speed = 0.8
        self.max_turn = 1.0
        
        # Thread para publicar continuamente
        self.running = True
        self.publish_thread = threading.Thread(target=self.publish_loop)
        self.publish_thread.start()
        
        print("\n=== Control con Teclado ===")
        print("W/S: Adelante/Atrás")
        print("A/D: Izquierda/Derecha")
        print("ESPACIO: Frenar")
        print("ESC: Salir")
    
    def publish_loop(self):
        """Publica comandos continuamente a 10Hz"""
        rate = self.create_rate(10)
        while self.running:
            msg = Twist()
            msg.linear.x = self.speed
            msg.angular.z = self.turn
            self.publisher.publish(msg)
            rate.sleep()
    
    def on_press(self, key):
        try:
            if key.char == 'w':
                self.speed = self.max_speed
            elif key.char == 's':
                self.speed = -self.max_speed
            elif key.char == 'a':
                self.turn = self.max_turn
            elif key.char == 'd':
                self.turn = -self.max_turn
        except AttributeError:
            if key == keyboard.Key.space:
                self.speed = 0.0
                self.turn = 0.0
    
    def on_release(self, key):
        if key == keyboard.Key.esc:
            self.running = False
            return False
        
        try:
            if key.char in ['w', 's']:
                self.speed = 0.0
            elif key.char in ['a', 'd']:
                self.turn = 0.0
        except AttributeError:
            pass
    
    def start(self):
        with keyboard.Listener(on_press=self.on_press, on_release=self.on_release) as listener:
            listener.join()

def main():
    rclpy.init()
    controller = KeyboardController()
    
    try:
        controller.start()
    finally:
        controller.running = False
        controller.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
````

## Paso 5: Control con Mando/Joystick

````python
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import pygame
import sys

class JoystickController(Node):
    def __init__(self):
        super().__init__('joystick_controller')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        
        # Inicializar pygame y joystick
        pygame.init()
        pygame.joystick.init()
        
        if pygame.joystick.get_count() == 0:
            print("No se detectó ningún mando. Conecta un joystick USB.")
            sys.exit(1)
        
        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()
        
        print(f"\n=== Control con Mando ===")
        print(f"Mando detectado: {self.joystick.get_name()}")
        print("Stick Izquierdo (vertical): Adelante/Atrás")
        print("Stick Derecho (horizontal): Izquierda/Derecha")
        print("Botón START o Ctrl+C: Salir")
        
        self.deadzone = 0.15
        self.max_speed = 0.8
        self.max_turn = 1.0
    
    def run(self):
        clock = pygame.time.Clock()
        running = True
        
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.JOYBUTTONDOWN:
                    # Botón START (7 en Xbox, 9 en PS4)
                    if event.button in [7, 9]:
                        running = False
            
            # Leer ejes del joystick
            # Eje 1: Stick izquierdo vertical (arriba/abajo)
            linear = -self.joystick.get_axis(1)  # Invertido
            
            # Eje 0 o 2: Stick derecho horizontal (izquierda/derecha)
            try:
                angular = self.joystick.get_axis(2)  # Algunos mandos
            except:
                angular = self.joystick.get_axis(0)  # Alternativamente
            
            # Aplicar deadzone
            if abs(linear) < self.deadzone:
                linear = 0.0
            if abs(angular) < self.deadzone:
                angular = 0.0
            
            # Escalar valores
            linear *= self.max_speed
            angular *= self.max_turn
            
            # Publicar comando
            msg = Twist()
            msg.linear.x = linear
            msg.angular.z = angular
            self.publisher.publish(msg)
            
            # Mostrar valores
            print(f"\rVelocidad: {linear:+.2f} | Giro: {angular:+.2f}", end="")
            
            clock.tick(20)  # 20 Hz
        
        # Detener el carro al salir
        msg = Twist()
        msg.linear.x = 0.0
        msg.angular.z = 0.0
        self.publisher.publish(msg)
        print("\n\nDetenido.")

def main():
    rclpy.init()
    controller = JoystickController()
    
    try:
        controller.run()
    except KeyboardInterrupt:
        print("\nInterrumpido por usuario")
    finally:
        controller.destroy_node()
        rclpy.shutdown()
        pygame.quit()

if __name__ == '__main__':
    main()
````

## Paso 6: Ejecutar en el DeepRacer

### Opción A: Ejecutar desde tu PC (conectado a la red del DeepRacer)

```bash
# Configurar ROS_DOMAIN_ID para comunicarse con el DeepRacer
set ROS_DOMAIN_ID=0
set ROS_MASTER_URI=http://<IP_DEL_DEEPRACER>:11311

# Ejecutar el script que prefieras
python deepracer_control.py
# o
python keyboard_control.py
# o
python joystick_control.py
```

### Opción B: Copiar y ejecutar directamente en el DeepRacer

```bash
# Desde tu PC, copiar archivos al DeepRacer
scp deepracer_control.py deepracer@<IP_DEL_DEEPRACER>:/home/deepracer/

# Conectar por SSH
ssh deepracer@<IP_DEL_DEEPRACER>

# Ejecutar
cd /home/deepracer
python3 deepracer_control.py
```

## Paso 7: Script de Inicio Rápido

````python
"""
Script de inicio rápido - Detecta automáticamente el método de control disponible
"""
import sys

print("=== AWS DeepRacer Control Selector ===")
print("1. Control por comandos de texto")
print("2. Control con teclado (W/A/S/D)")
print("3. Control con mando/joystick")

choice = input("\nSelecciona método (1-3): ").strip()

if choice == "1":
    import deepracer_control
    deepracer_control.main()
elif choice == "2":
    import keyboard_control
    keyboard_control.main()
elif choice == "3":
    import joystick_control
    joystick_control.main()
else:
    print("Opción inválida")
    sys.exit(1)
````

## Resumen de Comandos

```bash
# 1. Instalar dependencias
pip install rclpy geometry-msgs pygame pynput

# 2. Ejecutar control
python start_control.py

# 3. O ejecutar directamente
python keyboard_control.py  # Para teclado
python joystick_control.py  # Para mando
```

¡Con esto ya puedes controlar tu DeepRacer de 3 formas diferentes! 🚗