# AWS DeepRacer

## Descripción general

### ¿Qué es?

El AWS DeepRacer es un vehículo autónomo a escala 1/18 diseñado por Amazon Web Services (AWS) como plataforma educativa para el aprendizaje práctico del aprendizaje por refuerzo (Reinforcement Learning, RL). Se trata de un coche de carreras en miniatura equipado con una cámara frontal, un módulo de cómputo basado en Intel Atom, y toda la electrónica necesaria para ejecutar modelos de inteligencia artificial entrenados en la nube de AWS y conducir de forma autónoma por una pista. Fue anunciado en noviembre de 2018 durante la conferencia AWS re:Invent por el entonces CEO de AWS, Andy Jassy, y estuvo disponible para compra a partir de marzo de 2019.

El DeepRacer combina hardware de radiocontrol (basado en la plataforma WLtoys 1/18) con un módulo de cómputo de borde que ejecuta Ubuntu y ROS 2 (Robot Operating System 2). El vehículo procesa las imágenes de su cámara en tiempo real mediante Intel OpenVINO, produciendo decisiones de dirección y velocidad a aproximadamente 15 fotogramas por segundo. Esto permite que el coche navegue de forma autónoma por una pista física sin intervención humana, utilizando únicamente el modelo de aprendizaje por refuerzo previamente entrenado en la nube. Desde abril de 2021, el proyecto se convirtió en código abierto, lo que permite desplegarlo en cuentas propias de AWS y modificar libremente el software del vehículo.

Existen dos versiones principales del hardware: el **AWS DeepRacer original** (2019), que cuenta con una única cámara frontal de 4 megapíxeles, y el **AWS DeepRacer Evo** (julio de 2020), que añade una segunda cámara estereoscópica y un sensor LiDAR de 360 grados con alcance de 12 metros. El Evo permite funcionalidades avanzadas como la evasión de obstáculos y las carreras frente a frente contra otros vehículos. Existe también un **Sensor Kit** de actualización que permite convertir un DeepRacer original en un Evo añadiendo la segunda cámara y el LiDAR. Adicionalmente, AWS lanzó **DeepRacer Student** en 2022, una versión web gratuita para estudiantes que no requiere el vehículo físico.

### ¿Para qué sirve en un contexto de diseño, ingeniería, arte o tecnología?

En un aula STEAM universitaria, el AWS DeepRacer es una plataforma excepcionalmente versátil que integra múltiples disciplinas y permite a los estudiantes experimentar de primera mano con conceptos avanzados de inteligencia artificial, robótica y sistemas embebidos. Sus aplicaciones educativas incluyen:

- **Inteligencia artificial y machine learning**: El DeepRacer es, ante todo, una herramienta para comprender el aprendizaje por refuerzo. Los estudiantes diseñan funciones de recompensa en Python, configuran espacios de acción (discretos o continuos), ajustan hiperparámetros y entrenan modelos en el simulador 3D de AWS RoboMaker. Este ciclo completo de entrenar, evaluar, optimizar y desplegar es fundamental para entender cómo los agentes de RL aprenden comportamientos complejos a partir de interacciones con su entorno.
- **Robótica y sistemas embebidos**: El vehículo ejecuta ROS 2 Foxy sobre Ubuntu 20.04, lo que permite a los estudiantes explorar la arquitectura de un sistema robótico real con múltiples nodos de percepción, control y navegación comunicándose entre sí. Los 15 paquetes oficiales de ROS 2 del DeepRacer ofrecen oportunidades para estudiar tópicos, servicios, acciones y la integración de sensores en un framework de robótica profesional.
- **Ingeniería de software y DevOps**: El flujo de trabajo del DeepRacer implica el uso de servicios en la nube (Amazon SageMaker para entrenamiento, AWS RoboMaker para simulación, Amazon S3 para almacenamiento, Amazon CloudWatch para monitoreo), lo que introduce a los estudiantes en prácticas de computación en la nube, pipelines de machine learning y despliegue continuo de modelos.
- **Electrónica y hardware**: Los estudiantes pueden estudiar la arquitectura hardware del vehículo: motores DC cepillados, servo de dirección con mecánica Ackermann, baterías LiPo, controlador de velocidad electrónico (ESC), módulo de cómputo Intel Atom, y sensores como cámara, LiDAR, acelerómetro y giroscopio. El chasis de radiocontrol permite modificaciones mecánicas, ajustes de suspensión y alineación.
- **Diseño y creatividad**: La carrocería del DeepRacer es intercambiable y los estudiantes pueden diseñar e imprimir sus propias carrocerías personalizadas en 3D. También pueden crear pistas de carreras con diseños propios utilizando los archivos PDF de bordes de pista proporcionados por AWS, combinando creatividad estética con precisión geométrica.
- **Programación práctica**: Además de las funciones de recompensa en Python, los estudiantes pueden controlar el vehículo manualmente mediante la API web, por SSH con scripts ROS 2, o a través de una interfaz web personalizada. El proyecto STEAM Agent del aula demuestra cómo construir un sistema de control completo con backend en Node.js, frontend en React, y comunicación en tiempo real con el vehículo.

### Principales características y capacidades

- **Escala 1/18 con tracción 4WD**: Chasis tipo monster truck con mecánica de dirección Ackermann, que proporciona un comportamiento de conducción realista a escala reducida.
- **Módulo de cómputo Intel Atom**: Procesador quad-core a 1.6 GHz (burst a 2.0 GHz), 4 GB de RAM y 32 GB de almacenamiento eMMC, suficiente para ejecutar Ubuntu, ROS 2 y la inferencia del modelo en tiempo real.
- **Cámara frontal de 4 MP con lente gran angular de 120 grados**: Captura imágenes que se procesan a 160x120 píxeles en escala de grises a 15 fps para la inferencia del modelo de RL.
- **Aprendizaje por refuerzo con PPO**: Utiliza el algoritmo Proximal Policy Optimization (PPO) implementado en Amazon SageMaker para entrenar los modelos de conducción autónoma.
- **Simulador 3D en la nube**: AWS RoboMaker proporciona un entorno de simulación realista donde los modelos se entrenan y evalúan antes de desplegarse en el vehículo físico.
- **Inferencia en el borde con Intel OpenVINO**: Los modelos entrenados se compilan con SageMaker Neo y se optimizan para ejecutarse eficientemente en el procesador Intel Atom del vehículo.
- **Código abierto**: Desde abril de 2021, todo el software del vehículo está disponible en GitHub bajo los 15 paquetes ROS 2, permitiendo modificaciones y contribuciones de la comunidad.
- **Conectividad Wi-Fi 802.11ac**: Permite la carga y descarga de modelos, el streaming de video en vivo y el control remoto del vehículo.
- **Pantalla OLED de 0.91 pulgadas**: Muestra la dirección IP y el estado del dispositivo, facilitando la identificación y el diagnóstico en el aula.
- **Múltiples modos de control**: Manual (vía consola web, interfaz web personalizada, SSH + ROS 2), autónomo (con modelo RL desplegado) y calibración.

---

## Especificaciones técnicas

### Especificaciones generales

| Parámetro | Valor |
|---|---|
| **Nombre** | AWS DeepRacer |
| **Versiones** | Original (2019) / Evo (2020) |
| **Escala** | 1/18 |
| **Tipo de tracción** | 4WD (tracción en las cuatro ruedas) |
| **Tipo de dirección** | Ackermann (servo) |
| **Peso (sin baterías)** | ~3.2 kg (Original) / ~3.5 kg (Evo) |
| **Largo** | ~258 mm |
| **Ancho** | ~178 mm |
| **Alto** | ~106 mm (Original) / ~115 mm (Evo con LiDAR) |

### Módulo de cómputo

| Parámetro | Valor |
|---|---|
| **CPU** | Intel Atom x5-E3940, quad-core, 1.6 GHz (burst 2.0 GHz) |
| **GPU** | Intel HD Graphics 500 (integrada) |
| **Memoria RAM** | 4 GB DDR3L |
| **Almacenamiento** | 32 GB eMMC (expandible via microSD) |
| **Sistema operativo** | Ubuntu 20.04 LTS Focal Fossa (Evo/open-source) / Ubuntu 16.04 LTS (original) |
| **Framework de inferencia** | Intel OpenVINO Toolkit 2021.1.110 |
| **Framework de ML** | TensorFlow (compilado con SageMaker Neo) |
| **ROS** | ROS 2 Foxy Fitzroy (Evo/open-source) / ROS Kinetic (original) |

### Cámara

| Parámetro | Original | Evo |
|---|---|---|
| **Cantidad** | 1 cámara frontal | 2 cámaras estereoscópicas |
| **Resolución del sensor** | 4 Megapíxeles | 4 Megapíxeles cada una |
| **Formato de salida** | MJPEG | MJPEG |
| **Campo de visión (FOV)** | 120 grados | 120 grados |
| **Resolución de inferencia** | 160x120 px (escala de grises, 15 fps) | 160x120 px (escala de grises, 15 fps) |
| **Interfaz** | USB | USB |

### Sensor LiDAR (solo Evo)

| Parámetro | Valor |
|---|---|
| **Tipo** | LiDAR rotacional de 360 grados |
| **Radio de escaneo** | 12 metros |
| **Función** | Evasión de obstáculos y carreras frente a frente |

### Motores y dirección

| Parámetro | Valor |
|---|---|
| **Motores de tracción** | 2× motores DC cepillados (eje delantero y trasero) |
| **Servo de dirección** | Motor servo con linkage Ackermann |
| **Velocidad máxima física** | ~2 m/s (~7.2 km/h) |
| **Velocidad máxima en simulador** | ~5 m/s (~18 km/h) |
| **Ángulo de dirección máximo** | ±30 grados |
| **Control de velocidad** | PWM vía controlador ESC |

### Baterías

| Parámetro | Batería de tracción | Batería de cómputo |
|---|---|---|
| **Tipo** | LiPo (polímero de litio) | Power bank USB-C PD |
| **Voltaje** | 7.4 V | 5 V / variable PD |
| **Capacidad** | 1100 mAh | 13,600 mAh (ASUS ZenPower) |
| **Autonomía** | 10-15 minutos de conducción activa | ~6 horas |
| **Carga** | Cargador LiPo dedicado | Cargador USB-C PD |

### Conectividad y puertos

| Interfaz | Cantidad | Detalle |
|---|---|---|
| **USB-A** | 4 | Cámara(s), LiDAR, periféricos |
| **USB-C** | 1 | Alimentación/carga de batería de cómputo (PD) |
| **Micro-USB** | 1 | Puerto de servicio / depuración |
| **HDMI** | 1 | Salida de video a monitor externo |
| **Wi-Fi** | 802.11ac | Adaptador USB 2.4 GHz incluido |
| **OLED** | 1 | Pantalla de 0.91 pulgadas (dirección IP y estado) |

### Sensores integrados

| Sensor | Presente | Notas |
|---|---|---|
| **Acelerómetro** | Sí | Integrado en el módulo de cómputo |
| **Giroscopio** | Sí | Integrado en el módulo de cómputo |
| **Cámara frontal** | Sí (1 o 2) | 4 MP, 120 grados FOV, MJPEG |
| **LiDAR** | Solo Evo | 360 grados, 12 m de alcance |
| **OLED** | Sí | 0.91 pulgadas, monocromática |

### Entorno de funcionamiento

| Parámetro | Valor |
|---|---|
| **Superficie recomendada** | Pista plana con bordes definidos (moqueta o vinilo) |
| **Iluminación** | Interior, luz uniforme (evitar luz solar directa) |
| **Temperatura de funcionamiento** | 10 °C a 35 °C (recomendada interior) |
| **Humedad relativa** | 5% a 85% (sin condensación) |
| **Espacio requerido para pista estándar** | 10.36 m × 8.23 m (pista completa) / ~5.2 m × 2.85 m (mini pista) |

### Software y servicios en la nube

| Componente | Descripción |
|---|---|
| **Amazon SageMaker** | Entrenamiento de modelos RL (algoritmo PPO, integración con CloudWatch) |
| **AWS RoboMaker** | Entorno de simulación 3D para entrenamiento y evaluación |
| **Amazon S3** | Almacenamiento de modelos, datos de entrenamiento y logs |
| **Amazon SageMaker Neo** | Compilación y optimización de modelos para Intel Atom |
| **Amazon CloudWatch** | Monitoreo de métricas de entrenamiento y del dispositivo |
| **Consola AWS DeepRacer** | Interfaz web para crear modelos, entrenar, evaluar y competir |

---

## Componentes y partes

### Vista general del vehículo

El AWS DeepRacer está compuesto por los siguientes elementos principales, organizados desde el chasis hasta la parte superior:

### 1. Chasis base (1/18 monster truck)

Es la plataforma de radiocontrol sobre la cual se monta toda la electrónica. Basado en la plataforma WLtoys 1/18, el chasis incluye el sistema de suspensión, los diferenciales, los ejes y los puntos de anclaje para los componentes. El chasis es de plástico resistente con refuerzos metálicos en los puntos críticos. La suspensión cuenta con amortiguadores de resorte en las cuatro ruedas, aunque la carga adicional del módulo de cómputo y las baterías puede hacer que la suspensión se hunda, requiriendo ajustes o sustitución por resortes más rígidos.

### 2. Eje delantero y mecánica Ackermann

El eje delantero contiene el ensamblaje de dirección con el mecanismo Ackermann, que consiste en brazos de dirección, barras de acoplamiento (tie rods) y el servo de dirección. La geometría Ackermann garantiza que las ruedas interiores y exteriores giren a ángulos diferentes durante un giro, reduciendo el deslizamiento y mejorando la estabilidad. El servo de dirección recibe señales PWM del controlador y gira las ruedas hasta un máximo de ±30 grados.

### 3. Eje trasero y transmisión

El eje trasero contiene el diferencial trasero y la transmisión al eje. Los dos motores DC cepillados (uno en el eje delantero y otro en el trasero) proporcionan tracción a las cuatro ruedas (4WD). Los diferenciales permiten que las ruedas de cada eje giren a velocidades distintas durante los giros, lo que es esencial para un manejo estable.

### 4. Motores DC cepillados (2 unidades)

Dos motores DC cepillados proporcionan la fuerza motriz, uno para cada eje. Son controlados mediante señales PWM a través del controlador de velocidad electrónico (ESC). La velocidad máxima alcanzable es de aproximadamente 2 m/s en el vehículo físico. Estos motores son consumibles que eventualmente pueden necesitar reemplazo tras un uso intensivo.

### 5. Servo de dirección

El servo de dirección controla el ángulo de las ruedas delanteras. Recibe señales PWM del controlador del vehículo y convierte la señal en un movimiento angular preciso del mecanismo Ackermann. El ángulo de dirección va de -30 grados (giro completo a la izquierda) a +30 grados (giro completo a la derecha).

### 6. Controlador de velocidad electrónico (ESC / Motor Controller)

El ESC es el circuito que controla la velocidad de los motores DC y la posición del servo de dirección. Recibe comandos desde el módulo de cómputo a través de los paquetes ROS 2 y genera las señales PWM correspondientes. También gestiona la alimentación eléctrica desde la batería de tracción hacia los motores.

### 7. Batería de tracción (7.4V 1100mAh LiPo)

Batería de polímero de litio de 7.4 voltios y 1100 mAh que alimenta los motores, el servo y el ESC. Se aloja en un compartimento en la parte inferior del chasis. Su autonomía es de 10 a 15 minutos de conducción activa, lo que hace necesario tener varias baterías cargadas para sesiones prolongadas. Utiliza un conector específico que debe coincidir con el del ESC. Las baterías de reemplazo compatibles son las diseñadas para la plataforma WLtoys A949/A959.

### 8. Batería de cómputo (13,600 mAh USB-C PD Power Bank)

Un banco de energía USB-C Power Delivery (originalmente ASUS ZenPower) que alimenta exclusivamente el módulo de cómputo Intel Atom. Se monta sobre el chasis mediante correas o soportes de fijación. Su autonomía es de aproximadamente 6 horas, lo que permite sesiones de trabajo prolongadas sin necesidad de recarga. Se carga mediante un adaptador USB-C PD externo.

### 9. Módulo de cómputo (Intel Atom)

Es el cerebro del vehículo, una placa de ordenador de placa única basada en el procesador Intel Atom x5-E3940 con 4 GB de RAM y 32 GB de almacenamiento eMMC. Ejecuta Ubuntu 20.04 LTS con ROS 2 Foxy y todo el software de inferencia. Se monta en la parte superior del chasis y se conecta a los sensores, el ESC y la red Wi-Fi. Incluye:

- **Pantalla OLED de 0.91 pulgadas**: Muestra la dirección IP del vehículo y su estado operativo, lo que es fundamental para la conexión remota.
- **Hub USB de 4 puertos USB-A**: Permite conectar la cámara, el LiDAR y otros periféricos.
- **Puerto USB-C**: Para la alimentación desde la batería de cómputo.
- **Puerto Micro-USB**: Puerto de servicio para depuración y mantenimiento.
- **Puerto HDMI**: Para conectar un monitor externo, útil durante la configuración inicial.
- **Módulo Wi-Fi**: Adaptador USB 2.4 GHz para conectividad de red.

### 10. Cámara frontal (4 MP, 120 grados FOV)

Cámara de 4 megapíxeles con lente gran angular de 120 grados de campo de visión, conectada al módulo de cómputo por USB. Captura imágenes en formato MJPEG que se redimensionan a 160x120 píxeles en escala de grises para la inferencia del modelo de RL a 15 fps. En el modelo Evo, hay una segunda cámara idéntica que forma un par estereoscópico, permitiendo la percepción de profundidad y la evasión de obstáculos.

### 11. Sensor LiDAR (solo Evo)

Sensor LiDAR rotacional de 360 grados con un alcance de 12 metros, montado en la parte superior del vehículo en el modelo Evo. Proporciona datos de distancia a objetos circundantes que el modelo de RL utiliza para la evasión de obstáculos y las carreras frente a frente contra otros vehículos. Se conecta al módulo de cómputo mediante USB.

### 12. Carrocería (body shell)

Cubierta de plástico moldeado que se ajusta sobre el chasis y el módulo de cómputo. La carrocería original tiene la librea oficial de AWS DeepRacer y se sujeta mediante clips o montajes de fijación. Es intercambiable: los estudiantes pueden diseñar e imprimir carrocerías personalizadas en 3D, siempre que respeten las dimensiones del chasis y no obstruyan la cámara ni los sensores. Cualquier carrocería de RC a escala 1/18 puede adaptarse con modificaciones menores.

### 13. Ruedas y neumáticos (4 unidades)

Cuatro ruedas de goma con insertos de espuma, dimensionadas para la escala 1/18. Los neumáticos proporcionan tracción sobre las superficies de la pista (moqueta o vinilo). Son consumibles que se desgastan con el uso y pueden reemplazarse por neumáticos compatibles WLtoys 1/18 disponibles en tiendas de radiocontrol.

### 14. Parachoques delantero y trasero

Piezas de plástico que protegen el chasis y la electrónica en caso de colisión. El parachoques delantero ofrece protección limitada, y muchos usuarios de la comunidad optan por imprimir en 3D parachoques personalizados más robustos o añadir acolchado de espuma.

### 15. Amortiguadores (4 unidades)

Cuatro amortiguadores de resorte (coil-over), uno en cada rueda, que componen el sistema de suspensión. La suspensión de serie es relativamente blanda para el peso total del vehículo con el módulo de cómputo y las baterías, lo que puede causar que el chasis roce el suelo. Es común sustituir los resortes por otros más rígidos o añadir arandelas separadoras para aumentar la precarga.

### 16. Cables y conectores

- **Cable USB de la cámara**: Conecta la cámara al hub USB del módulo de cómputo.
- **Cable USB del LiDAR** (Evo): Conecta el sensor LiDAR al hub USB.
- **Cable de alimentación USB-C**: Conecta la batería de cómputo al módulo de cómputo.
- **Conector de batería de tracción**: Conector específico que vincula la batería LiPo al ESC.
- **Cargador de batería LiPo**: Cargador dedicado para la batería de tracción de 7.4V.
- **Adaptador de carga USB-C PD**: Cargador para la batería de cómputo.
- **Cable HDMI**: Para conectar un monitor externo durante la configuración inicial.

---

## Configuración y puesta en marcha

### Paso 1: Verificación del contenido del paquete

Antes de comenzar, verifique que el paquete incluye todos los componentes:

- Vehículo AWS DeepRacer (chasis con motores, servo y ESC montados).
- Módulo de cómputo Intel Atom.
- Cámara frontal con cable USB.
- Batería de tracción 7.4V 1100mAh LiPo.
- Cargador de batería LiPo.
- Batería de cómputo (power bank USB-C PD 13,600 mAh).
- Adaptador de carga USB-C PD.
- Carrocería con clips de montaje.
- Adaptador Wi-Fi USB.
- Guía de inicio rápido.

En el modelo Evo, verifique adicionalmente:
- Segunda cámara estereoscópica con cable USB.
- Sensor LiDAR con cable USB y soporte de montaje.

Si falta algún componente, no intente operar el vehículo y contacte al proveedor o al soporte de AWS.

### Paso 2: Carga de las baterías

Antes del primer uso, ambas baterías deben estar completamente cargadas:

1. **Batería de tracción LiPo**: Conéctela al cargador LiPo dedicado. Asegúrese de configurar el cargador en el modo correcto (7.4V, LiPo balance charge). El tiempo de carga típico es de 1 a 2 horas. Nunca deje una batería LiPo cargando sin supervisión.
2. **Batería de cómputo**: Conéctela al adaptador USB-C PD y cargue hasta el 100%. El tiempo de carga es de aproximadamente 3 a 4 horas para una carga completa desde vacío.

### Paso 3: Montaje físico del vehículo

1. **Instale la batería de tracción**: Abra el compartimento inferior del chasis e inserte la batería LiPo de 7.4V. Asegúrese de que el conector está firmemente insertado en el ESC y de que la batería queda bien sujeta en su compartimento.
2. **Monte el módulo de cómputo**: Coloque el módulo Intel Atom sobre el chasis en su posición designada. Fíjelo con los soportes o correas incluidos.
3. **Conecte la cámara**: Conecte el cable USB de la cámara a uno de los puertos USB-A del hub del módulo de cómputo. Asegúrese de que la cámara queda firmemente montada en su soporte delantero.
4. **Conecte el LiDAR (Evo)**: Monte el sensor LiDAR en la parte superior del vehículo y conecte su cable USB a otro puerto USB-A disponible.
5. **Conecte la batería de cómputo**: Conecte el cable USB-C desde la batería de cómputo al puerto USB-C del módulo de cómputo. Asegúrese de que la batería está bien sujeta al chasis.
6. **Instale la carrocería**: Coloque la carrocería sobre el chasis y asegúrela con los clips de montaje.
7. **Conecte el adaptador Wi-Fi**: Inserte el adaptador Wi-Fi USB en uno de los puertos USB-A disponibles.

### Paso 4: Conexión a monitor y periféricos (configuración inicial)

Para la configuración inicial, es necesario conectar el vehículo a un monitor y un ratón:

1. Conecte un cable HDMI desde el puerto HDMI del módulo de cómputo a un monitor externo.
2. Conecte un ratón USB al puerto USB-A disponible (o al hub si todos los puertos están ocupados por sensores).
3. Opcionalmente, conecte un teclado USB para comandos directos en el vehículo.

### Paso 5: Encendido del vehículo

1. **Encienda la batería de cómputo**: Pulse el botón de encendido del power bank USB-C. El módulo de cómputo comenzará a arrancar.
2. **Encienda el sistema de tracción**: Encienda el interruptor del ESC en el chasis (si existe) o simplemente conecte la batería LiPo. Algunos modelos encienden automáticamente los motores al conectar la batería.
3. **Espere el arranque**: El sistema operativo tarda aproximadamente 1 a 2 minutos en arrancar completamente. La pantalla OLED mostrará la dirección IP del vehículo una vez que el sistema esté listo.
4. **Verifique la pantalla OLED**: Anote la dirección IP mostrada en la pantalla OLED del módulo de cómputo. Esta dirección es esencial para todas las conexiones remotas posteriores.

### Paso 6: Conexión a la red Wi-Fi

El vehículo y la computadora desde la que se controla deben estar en la misma red Wi-Fi:

1. En el monitor conectado al vehículo, abra una terminal (puede necesitar hacer clic derecho en el escritorio).
2. Verifique la conexión Wi-Fi y la dirección IP:

```bash
ip addr show
```

Busque la dirección bajo la interfaz `wlan0` (Wi-Fi). Generalmente tiene el formato `10.x.x.x` o `192.168.x.x`.

3. Si el vehículo no está conectado a la red Wi-Fi deseada, configúrelo desde la interfaz de red de Ubuntu en el monitor conectado.
4. Verifique que puede hacer ping desde su computadora a la dirección IP del vehículo:

```bash
ping IP_DEL_DEEPRACER
```

### Paso 7: Acceso SSH al vehículo

SSH es la forma principal de acceder remotamente al vehículo desde su computadora:

**Credenciales por defecto del aula STEAM:**

| Campo | Valor |
|---|---|
| **Usuario** | `deepracer` |
| **Contraseña** | `Steampog1$` |

Conéctese desde su computadora:

```bash
ssh deepracer@IP_DEL_DEEPRACER
```

Ejemplo:

```bash
ssh deepracer@10.203.139.55
```

Si la conexión es exitosa, verá un prompt como:

```
deepracer@deepracer:~$
```

**Si SSH no funciona**, ejecute estos comandos directamente en el vehículo (con teclado y monitor conectados):

```bash
# Regenerar claves del servidor SSH
sudo ssh-keygen -A

# Verificar que el servicio SSH está corriendo
sudo systemctl status sshd

# Si no está activo, iniciarlo:
sudo systemctl start sshd
sudo systemctl enable sshd
```

### Paso 8: Verificación de los servicios ROS 2

Una vez conectado por SSH, verifique que los servicios de ROS 2 están funcionando:

```bash
# Verificar los nodos ROS 2 activos
ros2 node list

# Verificar los tópicos disponibles
ros2 topic list
```

Debería ver nodos como `/camera_pkg`, `/ctrl_pkg`, `/servo_pkg`, etc., y tópicos como `/camera_pkg/display_mjpeg`, `/cmd_vel`, `/servo_pkg/servo`, etc.

### Paso 9: Calibración del vehículo

Antes de conducir, es fundamental calibrar el vehículo para asegurar que la dirección y la velocidad responden correctamente:

1. Acceda a la consola web del vehículo desde su navegador: `https://IP_DEL_DEEPRACER`
2. Inicie sesión con la contraseña del servidor del vehículo (configurada durante la puesta en marcha inicial).
3. Vaya a la sección de **Calibración**.
4. **Calibración de dirección**: Centre el servo de dirección y ajuste los valores mínimo y máximo del ángulo. Verifique visualmente que las ruedas delanteras se mueven simétricamente a izquierda y derecha.
5. **Calibración de velocidad**: Ajuste los valores PWM de velocidad mínima y máxima. Verifique que el vehículo avanza y retrocede correctamente.
6. Guarde los valores de calibración.

**Alternativa de calibración manual**: Si las ruedas no están alineadas, ajuste las barras de acoplamiento (tie rods) del mecanismo de dirección con unas pinzas hasta que las ruedas estén rectas cuando el servo está centrado.

### Precauciones de seguridad importantes

- **Nunca** opere el vehículo cerca de escaleras, bordes de mesas o superficies elevadas donde pueda caer.
- **Siempre** coloque el vehículo en el suelo o sobre una pista plana antes de enviar comandos de movimiento.
- **No** deje el vehículo sin supervisión mientras está encendido y con la batería de tracción conectada.
- **No** exceda el tiempo de uso de la batería LiPo. Si nota que el vehículo pierde potencia, deténgalo y retire la batería inmediatamente. Una batería LiPo descargada por debajo de su voltaje mínimo puede dañarse permanentemente o presentar riesgo de incendio.
- **No** cargue baterías LiPo sobre superficies inflamables. Utilice siempre bolsas de carga LiPo seguras.
- **Mantenga** las manos y objetos alejados de las ruedas y partes móviles mientras el vehículo está encendido.
- **Desconecte** la batería de tracción cuando no utilice el vehículo durante períodos prolongados.
- **No** manipule el vehículo mientras el modelo autónomo está en ejecución; el vehículo puede moverse inesperadamente.
- **Mantenga** líquidos y alimentos alejados del vehículo y sus conexiones eléctricas.
- Si el vehículo emite sonidos inusuales, humo o calor excesivo, **deténgalo inmediatamente** y desconecte las baterías.

---

## Guía de uso paso a paso

### Tarea típica: Control manual del vehículo mediante la interfaz web del aula STEAM

A continuación se describe paso a paso cómo controlar el AWS DeepRacer de forma manual utilizando la interfaz web personalizada desarrollada para el aula STEAM (proyecto Deepracer-STEAM-Agent). Esta es la forma más accesible y visual de controlar el vehículo, especialmente para estudiantes que se inician en la robótica.

### Paso 1: Preparación del entorno

1. Asegúrese de que el vehículo está encendido, conectado a la red Wi-Fi y que la pantalla OLED muestra una dirección IP válida.
2. Verifique que la batería de tracción está conectada y suficientemente cargada.
3. Coloque el vehículo en una superficie plana, preferiblemente sobre la pista de carreras o en un área despejada de al menos 2 m × 2 m.
4. Asegúrese de que su computadora está conectada a la misma red Wi-Fi que el vehículo.

### Paso 2: Iniciar el servidor backend

El backend es un servidor Node.js + Express que actúa como puente entre el frontend web y el servidor API del vehículo.

1. Abra una terminal en su computadora.
2. Navegue al directorio del proyecto:

```bash
cd C:\Deepracer-STEAM-Agent\backend
```

3. Instale las dependencias (solo la primera vez):

```bash
npm install
```

4. Inicie el servidor:

```bash
npm start
```

5. Debería ver un mensaje indicando que el servidor está corriendo en el puerto 5002.

**Especificaciones del backend:**

| Parámetro | Valor |
|---|---|
| Puerto | 5002 |
| Módulos | ES modules |
| Dependencias | express ^5.1.0, cors ^2.8.5 |
| Destino API del vehículo | localhost:5001 |

**API Endpoints del backend:**

| Método | Endpoint | Descripción |
|---|---|---|
| `POST` | `/api/start` | Activa modo manual en el vehículo |
| `POST` | `/api/stop` | Detiene el vehículo |
| `POST` | `/api/manual_drive` | Envía comandos de movimiento |
| `GET` | `/api/video_stream` | Stream de video de la cámara |

### Paso 3: Iniciar el frontend

El frontend es una aplicación React + Vite + Tailwind CSS + DaisyUI que proporciona la interfaz gráfica de control.

1. Abra una **nueva terminal** (mantenga el backend corriendo en la otra).
2. Navegue a la raíz del proyecto:

```bash
cd C:\Deepracer-STEAM-Agent
```

3. Instale las dependencias (solo la primera vez):

```bash
npm install
```

4. Inicie el servidor de desarrollo:

```bash
npm run dev
```

5. Abra su navegador en: `http://localhost:5173`

### Paso 4: Activar el control manual

1. En la interfaz web, pulse el botón de **Inicio** o **Start** para activar el modo manual del vehículo.
2. El estado del vehículo cambiará a "Control manual activo" (indicador amarillo).
3. El stream de video de la cámara debería mostrarse en la interfaz.

**Estados del vehículo:**

| Estado | Significado |
|---|---|
| Detenido (rojo) | El vehículo está detenido y no responde a comandos |
| Automático activo (verde) | El vehículo está en modo autónomo con un modelo RL |
| Control manual activo (amarillo) | El vehículo está en modo manual y recibe comandos |

### Paso 5: Control por teclado

Los controles de teclado están activos cuando la ventana del navegador está enfocada:

| Tecla | Acción | Comando enviado |
|---|---|---|
| ↑ o **W** | Avanzar recto | `angle=0, throttle=-100` |
| ↓ o **S** | Retroceder recto | `angle=0, throttle=+100` |
| ← o **A** | Girar izquierda | `angle=-45, throttle=-100` |
| → o **D** | Girar derecha | `angle=+45, throttle=-100` |

**Combinaciones diagonales:**
- **↑ + →** = Avanzar girando a la derecha
- **↑ + ←** = Avanzar girando a la izquierda
- **↓ + →** = Retroceder girando a la derecha
- **↓ + ←** = Retroceder girando a la izquierda

**Al soltar todas las teclas**, el vehículo se detiene automáticamente (`angle=0, throttle=0`).

**Convención de throttle invertida:**
- `throttle` **negativo** (ej: -100) = vehículo **avanza**.
- `throttle` **positivo** (ej: +100) = vehículo **retrocede**.
- Esto es una particularidad de la API del DeepRacer y no un error.

**Seguridad automática:** Si cambia de pestaña o minimiza la ventana del navegador, el sistema suelta todas las teclas y envía un comando de parada automáticamente.

### Paso 6: Control por gamepad

La interfaz detecta automáticamente mandos USB o Bluetooth conectados a la computadora:

**Modo Joystick:**

| Control | Función | Rango |
|---|---|---|
| Stick izquierdo X | Ángulo de dirección | -45° a +45° |
| Stick izquierdo Y | Velocidad (throttle) | -100 a +100 |

**Modo Triggers (alternativo):**

| Control | Función |
|---|---|
| Trigger derecho (BTN 7) | Acelerar adelante |
| Trigger izquierdo (BTN 6) | Retroceder |
| Stick izquierdo X | Ángulo de dirección |

**Botones adicionales:**

| Botón | Función |
|---|---|
| LB (BTN 4) | Reducir velocidad máxima |
| RB (BTN 5) | Aumentar velocidad máxima |

Las zonas muertas (dead zones) están configuradas en 0.15 para ejes analógicos y 0.05 para triggers, lo que evita que movimientos involuntarios mínimos del gamepad generen comandos al vehículo.

### Paso 7: Visualización de la cámara

Hay dos formas de ver el stream de la cámara del DeepRacer:

**Opción A: Vía Backend Proxy (recomendada para principiantes)**

```
http://localhost:5002/api/video_stream
```

- Resolución: 480x360
- No requiere abrir puertos adicionales.
- El backend actúa como intermediario.

**Opción B: Stream directo ROS**

```
http://IP_DEL_DEEPRACER:8080/stream?topic=/camera_pkg/display_mjpeg&width=1280&height=720
```

- Resolución: 1280x720 (HD)
- Requiere que el nodo `web_video_server` esté corriendo en el vehículo.
- Menor latencia al no pasar por el backend.

Para iniciar el `web_video_server` si no está activo:

```bash
# Desde SSH en el vehículo
ros2 run web_video_server web_video_server
```

### Paso 8: Detener el vehículo

1. Suelte todas las teclas del teclado o del gamepad.
2. Pulse el botón de **Detener** o **Stop** en la interfaz web.
3. El estado del vehículo cambiará a "Detenido" (indicador rojo).
4. Desconecte la batería de tracción si no va a usar el vehículo en los próximos minutos.

### Tarea avanzada: Entrenar y desplegar un modelo de conducción autónoma

Para estudiantes que deseen avanzar al aprendizaje por refuerzo, el flujo de trabajo completo es:

1. **Acceder a la consola AWS DeepRacer**: Inicie sesión en `https://deepracer.aws` con su cuenta de AWS.
2. **Crear un modelo**: Defina una función de recompensa en Python que premie al agente por mantenerse en la pista y avanzar rápido.
3. **Configurar el espacio de acción**: Elija entre discreto (conjunto fijo de velocidades y ángulos) o continuo (rangos de velocidad y dirección).
4. **Entrenar en simulación**: Lance el entrenamiento en AWS RoboMaker con SageMaker. El proceso típico dura de 1 a 4 horas.
5. **Evaluar el modelo**: Pruebe el modelo entrenado en el simulador en diferentes pistas.
6. **Optimizar con SageMaker Neo**: Compile el modelo para el procesador Intel Atom del vehículo.
7. **Desplegar en el vehículo**: Descargue el modelo optimizado al vehículo a través de la red Wi-Fi desde la consola de AWS.
8. **Probar en la pista física**: Active el modo autónomo en la consola del vehículo y observe el comportamiento del coche en la pista real.
9. **Iterar**: Ajuste la función de recompensa y los hiperparámetros basándose en el rendimiento observado, y repita el ciclo.

### Tarea avanzada: Control por SSH + ROS 2

Para usuarios con experiencia en ROS 2, es posible controlar el vehículo directamente publicando mensajes al tópico `/cmd_vel`:

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

**Ejecución:**

```bash
python3 deepracer_controller.py
```

### Consejos para principiantes

- **Empiece con el control manual**: Antes de intentar entrenar modelos de RL, familiarícese con el vehículo controlándolo manualmente. Entender cómo responde la dirección y la velocidad le ayudará a diseñar mejores funciones de recompensa.
- **Use velocidades bajas al principio**: Configure la velocidad máxima al 30-50% durante las primeras sesiones. El vehículo puede ser sorprendentemente rápido a velocidad completa.
- **Cuide las baterías LiPo**: Nunca descargue la batería de tracción por debajo de 3.0V por celda (6.0V total para una 2S). Use un verificador de voltaje LiPo externo si es necesario. Almacene las baterías LiPo al 50-60% de carga si no las va a usar por más de una semana.
- **Mantenga la cámara limpia**: La cámara es el sensor principal del vehículo. Una lente sucia degradará significativamente el rendimiento del modelo autónomo. Límpiela con un paño de microfibra suave.
- **Calibre antes de cada sesión**: La alineación de las ruedas puede cambiar con el uso. Verifique la calibración de dirección y velocidad antes de cada sesión de conducción.
- **Pruebe en un área despejada**: Antes de usar la pista, pruebe el vehículo en un área abierta y despejada para verificar que responde correctamente a los comandos.
- **Tenga baterías de repuesto**: Con solo 10-15 minutos de autonomía por batería de tracción, necesitará al menos 2-3 baterías cargadas para una sesión productiva.

---

## Mantenimiento básico

### Limpieza

La limpieza regular del AWS DeepRacer es esencial para mantener el correcto funcionamiento de sus sensores y la precisión de sus movimientos. Se recomienda seguir estas pautas:

- **Frecuencia**: Limpie el vehículo después de cada sesión de uso intensivo o, como mínimo, una vez por semana en un aula STEAM con uso regular.
- **Cámara**: La limpieza de la lente de la cámara es la tarea de mantenimiento más importante. Utilice un paño de microfibra suave y limpio para eliminar polvo, huellas dactilares y residuos de la lente. No utilice líquidos agresivos ni frote con fuerza. Una lente sucia es la causa más común de degradación del rendimiento del modelo autónomo, ya que la cámara es el único sensor de percepción visual del vehículo (en el modelo original).
- **Carrocería**: Limpie la carrocería con un paño húmedo. Si la carrocería tiene adhesivos o decoraciones, tenga cuidado de no dañarlos.
- **Chasis y suspensión**: Utilice un pincel suave o aire comprimido para eliminar polvo, tierra y residuos del chasis, los amortiguadores y las articulaciones de dirección. Los residuos acumulados pueden afectar la suspensión y la alineación.
- **Ruedas**: Limpie los neumáticos con un paño húmedo para eliminar polvo y residuos que puedan afectar la tracción. Verifique que no hay piedras pequeñas o debris atrapados en la banda de rodadura.
- **Puertos USB y conectores**: Utilice aire comprimido para limpiar los puertos USB y los conectores. Los conectores sucios pueden causar desconexiones intermitentes de la cámara o el LiDAR.
- **Cables**: Inspeccione los cables USB de la cámara y el LiDAR periódicamente. Las vibraciones del vehículo pueden aflojar las conexiones. Si un cable está dañado, reemplácelo inmediatamente.

### Calibración

La calibración del DeepRacer debe realizarse con regularidad para asegurar un comportamiento predecible y consistente:

- **Calibración de dirección**: Verifique que las ruedas delanteras están rectas cuando el servo está en la posición centrada. Si las ruedas están desalineadas, ajuste las barras de acoplamiento (tie rods) con unas pinzas. También puede ajustar los valores de calibración en la consola web del vehículo para compensar desviaciones. Se recomienda verificar la alineación antes de cada sesión de conducción autónoma.
- **Calibración de velocidad**: Verifique que el vehículo avanza y retrocede a las velocidades esperadas. Ajuste los valores PWM mínimo y máximo en la consola web si el vehículo no responde correctamente al acelerar o si se mueve cuando debería estar detenido.
- **Prueba de conducción recta**: Después de calibrar, haga una prueba de conducción manual recta a velocidad baja y verifique que el vehículo avanza en línea recta sin desviarse. Si se desvía, ajuste la calibración de dirección.

### Inspección periódica

Se recomienda realizar las siguientes inspecciones de forma regular:

- **Después de cada sesión**: Verificar que no hay piezas sueltas, cables desconectados o daños visibles en la carrocería o el chasis. Comprobar que la cámara sigue firmemente montada.
- **Semanal**: Inspeccionar los neumáticos en busca de desgaste excesivo o deformación. Comprobar la fijación del módulo de cómputo al chasis. Verificar que los amortiguadores no tienen holgura excesiva.
- **Mensual**: Comprobar la alineación de las ruedas y la calibración de dirección. Inspeccionar los cables USB en busca de desgaste por vibración. Verificar el estado de los conectores de la batería de tracción.
- **Trimestral**: Realizar una prueba completa de conducción manual y autónoma. Verificar el correcto funcionamiento de todos los sensores (cámara, LiDAR si aplica, IMU). Comprobar la autonomía de las baterías y su estado de salud.
- **Semestral**: Revisar los motores DC en busca de desgaste o ruidos anormales. Comprobar el servo de dirección. Verificar las conexiones internas del ESC.

### Mantenimiento de baterías

Las baterías, especialmente las LiPo, requieren un cuidado especial:

- **Batería de tracción LiPo 7.4V**:
  - Nunca la descargue por debajo de 6.0V total (3.0V por celda). El voltaje bajo puede causar daños permanentes o riesgo de incendio.
  - Cargue siempre con el cargador LiPo dedicado en modo balance charge.
  - Almacene al 50-60% de carga si no la va a usar durante más de una semana.
  - Nunca la cargue sin supervisión.
  - Si la batería se hincha, se daña o muestra signos de deformación, deséchela de forma segura en un punto de reciclaje de baterías LiPo. No la use.
  - Utilice bolsas de carga LiPo ignífugas durante la carga.

- **Batería de cómputo (power bank USB-C PD)**:
  - Cargue completamente antes de cada sesión de uso prolongado.
  - Si no se usa durante más de un mes, carguela al 50% y almacénela en un lugar fresco y seco.
  - Verifique periódicamente que el power bank no se calienta excesivamente durante el uso.

### Almacenamiento adecuado

Cuando el vehículo no se utilice durante períodos prolongados (por ejemplo, durante vacaciones o recesos académicos):

- **Desconecte ambas baterías**: Retire la batería de tracción LiPo del compartimento y desconecte la batería de cómputo del módulo de cómputo.
- **Almacene las baterías LiPo al 50-60% de carga**: Nunca almacene una batería LiPo completamente cargada ni completamente descargada.
- **Cubra el vehículo**: Utilice una funda antipolvo para proteger la cámara, los sensores y la electrónica.
- **Guarde los cables**: Enrolle los cables sin dobleces pronunciados.
- **Mantenga el vehículo**: En un lugar seco, a temperatura ambiente (15-25 °C) y lejos de la luz solar directa.
- **No apile objetos**: Sobre el vehículo durante el almacenamiento.
- Si el almacenamiento supera los 3 meses, realice una carga y descarga de mantenimiento de las baterías LiPo y una prueba de funcionamiento antes de volver a ponerlo en operación regular.

---

## Solución de problemas comunes

A continuación se presenta una tabla con los problemas más frecuentes que pueden surgir al usar el AWS DeepRacer, junto con sus posibles causas y soluciones recomendadas.

| Problema | Posible causa | Solución |
|---|---|---|
| El vehículo no enciende | Batería de cómputo agotada o no conectada | Verifique que el power bank está encendido y conectado al puerto USB-C del módulo de cómputo. Cargue el power bank si es necesario. |
| La pantalla OLED no muestra la IP | El módulo de cómputo no ha terminado de arrancar | Espere 1-2 minutos adicionales. Si la pantalla permanece en negro, conecte un monitor por HDMI para diagnosticar. |
| No puedo conectarme por SSH | SSH no está activo, red incorrecta o credenciales erróneas | Ejecute `sudo systemctl start sshd` en el vehículo. Verifique que ambos dispositivos están en la misma red Wi-Fi. Confirme las credenciales (`deepracer` / `Steampog1$`). Ejecute `ssh-keygen -R IP_DEL_DEEPRACER` si cambia la clave del host. |
| El vehículo no se mueve | No está en modo manual, no se ha iniciado, o batería de tracción baja | Envíe `POST /api/drive_mode` con `{"drive_mode": "manual"}`. Envíe `POST /api/start_stop` con `{"start_stop": "start"}`. Verifique que la batería LiPo está conectada y cargada. |
| El vehículo se mueve en dirección opuesta | Convención invertida del throttle | Recuerde: throttle negativo = adelante, throttle positivo = atrás. Ajuste los comandos en consecuencia. |
| El vehículo tira hacia un lado | Ruedas desalineadas o calibración incorrecta | Ajuste las barras de acoplamiento (tie rods) del mecanismo de dirección. Recalibre la dirección en la consola web del vehículo. |
| La cámara no muestra video (puerto 5002) | Backend no corriendo | Inicie el backend con `npm start` en el directorio `/backend`. Verifique que el backend se conecta al vehículo. |
| La cámara no muestra video (puerto 8080) | `web_video_server` no activo en el vehículo | Conéctese por SSH y ejecute `ros2 run web_video_server web_video_server`. Verifique que el puerto 8080 es accesible. |
| Imagen de la cámara congelada | Conexión de red lenta o inestable | Reduzca la resolución del stream. Mejore la señal Wi-Fi. Use el stream de menor resolución (480x360 por el backend). |
| La cámara se desconecta durante la conducción | Vibraciones aflojan el conector USB | Asegure las conexiones USB con cinta adhesiva o bridas. Use cables USB con conector de cierre si es posible. |
| El frontend no se conecta al backend | Backend no corriendo o error CORS | Inicie el backend con `npm start`. Verifique que `cors` está habilitado en `server.js`. |
| El gamepad no funciona | Navegador no soporta Gamepad API o no conectado antes de cargar la página | Use Chrome o Edge (soporte completo de Gamepad API). Conecte el gamepad antes de abrir la página web. Revise la consola del navegador para verificar la detección. |
| El modelo autónomo no funciona bien en la pista real | Brecha sim-to-real (sim-to-real gap) | Use aleatorización de dominios en el entrenamiento. Añada ruido a la simulación. Reduzca la velocidad máxima. Mejore la iluminación de la pista. Calibre el vehículo. |
| Error al subir el modelo al vehículo | Wi-Fi débil o permisos S3 incorrectos | Mejore la señal Wi-Fi. Verifique los permisos del bucket S3. Reintente la subida. |
| El vehículo se detiene inesperadamente | Detección de obstáculos (Evo) o batería baja | Verifique si el LiDAR detecta objetos falsos (superficie reflectante). Compruebe el voltaje de la batería de tracción. |
| Sobrecalentamiento del módulo de cómputo | Uso prolongado sin ventilación | Asegure una ventilación adecuada. Evite la luz solar directa. Considere actualizar las pastillas térmicas. |
| El servidor del vehículo no responde (puerto 5001) | Servicio webserver caído | Reinicie el servicio desde SSH: `sudo systemctl restart deepracer-webserver`. Si persiste, reinicie el vehículo. |
| La batería LiPo se hincha | Sobrecarga, sobredescarga o edad | **Deje de usarla inmediatamente**. Llévela a un punto de reciclaje de baterías LiPo. No intente cargarla o usarla. |
| Ruido anormal en los motores | Desgaste de los motores DC o cuerpo extraño | Detenga el vehículo. Inspeccione visualmente. Si el ruido persiste, considere reemplazar los motores. |
| La suspensión se hunde | Resortes demasiado blandos para la carga total | Sustituya los resortes por otros más rígidos. Añada arandelas separadoras en los amortiguadores. |
| Wi-Fi se desconecta intermitentemente | Señal débil o interferencia en 2.4 GHz | Acerque el vehículo al router Wi-Fi. Cambie al canal de 5 GHz si es posible. Use un adaptador Wi-Fi USB de mayor alcance. |

---

## Materiales, repuestos o accesorios típicos

### Accesorios oficiales

Los siguientes accesorios son los diseñados específicamente para el AWS DeepRacer:

| Accesorio | Descripción | Uso típico en el aula |
|---|---|---|
| **AWS DeepRacer Sensor Kit** | Kit de actualización para convertir el modelo original en Evo (añade 2a cámara + LiDAR) | Evasión de obstáculos, carreras frente a frente, proyectos avanzados de percepción |
| **Batería de tracción de repuesto** | 7.4V 1100mAh LiPo compatible con WLtoys | Sesiones de uso continuo sin interrupciones por recarga |
| **Batería de cómputo de repuesto** | Power bank USB-C PD 13,600 mAh | Reemplazo en caso de fallo, sesiones prolongadas |
| **Cargador LiPo dedicado** | Cargador balance para baterías 2S LiPo | Carga segura de baterías de tracción |
| **Pista estándar (moqueta)** | 10.36 m × 8.23 m, 4 mm de grosor, 5 rollos | Entrenamiento y evaluación de modelos autónomos |
| **Pista estándar (vinilo)** | Dimensiones similares, material vinilo | Alternativa más ligera y fácil de configurar |
| **Mini pista** | ~5.20 m × 2.85 m | Uso en espacios reducidos del aula |

### Repuestos y componentes reemplazables

| Repuesto | Compatibilidad | Fuente |
|---|---|---|
| **Batería de tracción LiPo** | WLtoys 7.4V 1100mAh (ej: Klions) | Amazon, tiendas de radiocontrol |
| **Neumáticos** | WLtoys 1/18 escala | Amazon, tiendas de radiocontrol |
| **Amortiguadores / resortes** | WLtoys 1/18 upgrade | Tiendas de radiocontrol |
| **Carrocería** | Cualquier RC 1/18 (con adaptación) | Tiendas de radiocontrol, impresión 3D |
| **Cables USB** | USB-A a USB (cámara, LiDAR) | Cualquier tienda de electrónica |
| **Motor DC cepillado** | WLtoys 1/18 compatible | Amazon, tiendas de radiocontrol |
| **Servo de dirección** | WLtoys 1/18 compatible | Amazon, tiendas de radiocontrol |

### Consumibles

Los siguientes elementos se consideran consumibles que pueden necesitar reemplazo periódico:

- **Baterías LiPo de tracción**: Con uso regular, las baterías LiPo pierden capacidad después de 100-200 ciclos de carga. Se recomienda tener al menos 3 baterías de repuesto cargadas para sesiones de 1 hora.
- **Neumáticos**: Se desgastan con el uso, especialmente sobre superficies abrasivas. Inspeccione periódicamente y reemplace cuando la banda de rodadura esté lisa.
- **Cables USB de la cámara**: Las vibraciones del vehículo pueden causar fatiga en los cables. Inspeccione regularmente y reemplace si muestra signos de desgaste.
- **Copa del LiDAR (Evo)**: Si se daña en una colisión, puede necesitar reemplazo.

### Repuestos recomendados para el aula

Se sugiere mantener un inventario mínimo de los siguientes elementos:

- 3 baterías de tracción LiPo de repuesto (cargadas y listas para usar).
- 1 batería de cómputo de repuesto.
- 1 cargador LiPo de repuesto.
- 1 juego de neumáticos de repuesto.
- 2 cables USB de repuesto (para cámara).
- 1 set de resortes de suspensión más rígidos.
- Bolsas de carga LiPo ignífugas (para carga segura).
- Verificador de voltaje LiPo externo.

### Herramientas recomendadas

- Pinzas para ajustar las barras de acoplamiento de la dirección.
- Destornilladores de precisión (philips y plano) para ajustes del chasis.
- Paño de microfibra para la limpieza de la lente de la cámara.
- Aire comprimido en lata para limpieza de puertos y conectores.
- Bridas de plástico para asegurar cables.
- Cinta adhesiva de doble cara para fijar componentes adicionales.

### Disponibilidad en el aula

Los accesorios y consumibles del DeepRacer pueden adquirirse a través de:

- La tienda oficial de AWS DeepRacer (store.awsdeepracer.com).
- Amazon y tiendas en línea de radiocontrol (para repuestos compatibles WLtoys).
- Tiendas de electrónica (para cables USB, cargadores y accesorios genéricos).
- Impresión 3D local (para carrocerías, parachoques y montajes personalizados).

Consulte con el coordinador del aula STEAM sobre la disponibilidad actual de cada accesorio y repuesto, así como el procedimiento para solicitar compras de reposición.

---

## Normas de uso en el aula STEAM

### Normas generales

1. **Formación obligatoria**: Todo estudiante debe recibir una inducción básica sobre el funcionamiento y la seguridad del AWS DeepRacer antes de operarlo por primera vez. Esta inducción incluye la lectura de este manual, una demostración práctica por parte del docente o asistente, y la firma de un compromiso de uso responsable. La inducción debe cubrir tanto el control manual como las precauciones con las baterías LiPo.

2. **Supervisión**: Los estudiantes de primer uso deben operar el vehículo bajo la supervisión directa de un docente, asistente de laboratorio o estudiante previamente certificado. No se permite el uso autónomo del vehículo hasta que el estudiante haya demostrado competencia en las operaciones básicas de control manual y detención de emergencia.

3. **Reserva de uso**: El uso del DeepRacer debe reservarse con anticipación a través del sistema de reservas del aula STEAM. Cada sesión tiene una duración máxima de 2 horas, prorrogables solo si no hay otros estudiantes en espera. La reserva debe incluir el tipo de actividad (control manual, entrenamiento de modelo, conducción autónoma).

4. **Registro de uso**: Al inicio de cada sesión, el estudiante debe registrar su nombre, fecha, hora de inicio y el tipo de tarea a realizar en el cuaderno de registro del aula. Al finalizar, debe registrar la hora de finalización, el estado de las baterías y cualquier incidencia observada.

5. **Zona de operación**: El vehículo solo debe operarse dentro de la zona designada del aula (la pista de carreras o el área delimitada para pruebas). Bajo ninguna circunstancia debe operarse en pasillos, escaleras o áreas no designadas.

### Normas de seguridad

6. **Superficie adecuada**: Antes de encender el vehículo, verifique que la superficie de operación es plana, limpia y libre de obstáculos. La pista debe estar despejada de objetos que puedan dañar el vehículo o ser dañados por él.

7. **Detención de emergencia**: Todo estudiante debe conocer cómo detener el vehículo de emergencia: (a) pulsar el botón Stop en la interfaz web, (b) desconectar la batería de tracción, o (c) usar el comando SSH de parada: `curl -X POST http://localhost:5001/api/start_stop -H "Content-Type: application/json" -d '{"start_stop": "stop"}'`.

8. **Manejo de baterías LiPo**: Las baterías de tracción LiPo deben manipularse con precaución: (a) nunca perforar, aplastar o exponer al calor; (b) cargar siempre sobre una superficie no inflamable o dentro de una bolsa ignífuga; (c) nunca cargar sin supervisión; (d) retirar inmediatamente si se hincha, calienta anormalmente o emite olor; (e) almacenar al 50-60% de carga cuando no se usen; (f) desechar en un punto de reciclaje autorizado, nunca en la basura común.

9. **Velocidad controlada**: Durante las sesiones de control manual, la velocidad máxima debe mantenerse al 50% o menos para los principiantes. Solo los estudiantes certificados pueden usar velocidades superiores, y siempre dentro de la pista y con espacio libre suficiente.

10. **Distancia de seguridad**: Mantenga al menos 1 metro de distancia del vehículo en movimiento. No se pare en la pista mientras el vehículo está en movimiento, ni siquiera en modo manual a baja velocidad.

11. **Protección de cables**: Verifique que todos los cables (USB de cámara, LiDAR, alimentación) están correctamente conectados y asegurados antes de encender el vehículo. Las conexiones sueltas pueden causar desconexiones durante la conducción.

### Normas de uso del software

12. **No modificar configuraciones del sistema**: Los estudiantes no deben modificar la configuración del sistema operativo, los servicios de ROS 2 o los archivos de configuración del vehículo sin autorización del docente o coordinador del aula.

13. **Uso responsable de la red**: El vehículo y la interfaz web utilizan la red Wi-Fi del aula. No intente acceder a otros dispositivos de la red, realizar descargas masivas o saturar el ancho de banda durante las sesiones de uso.

14. **Código propio**: Los estudiantes pueden desarrollar y probar sus propios scripts de control (Python, Node.js) siempre que no interfieran con los servicios críticos del vehículo. Se recomienda probar primero en modo simulación o con el vehículo levantado (ruedas sin contacto con el suelo).

15. **Credenciales**: Las credenciales de acceso al vehículo (SSH, consola web) son de uso exclusivo del aula STEAM. No las comparta fuera del entorno académico.

### Normas de mantenimiento y cuidado

16. **Limpieza post-uso**: Al finalizar cada sesión, el estudiante debe limpiar el vehículo, especialmente la lente de la cámara, y guardarlo en su lugar designado con la funda antipolvo puesta.

17. **Carga de baterías**: Al finalizar la sesión, el estudiante debe conectar las baterías a sus cargadores correspondientes y registrar el estado de carga. Las baterías LiPo no deben dejarse conectadas al vehículo cuando no están en uso.

18. **Reporte de incidencias**: Cualquier daño, mal funcionamiento o comportamiento anormal del vehículo debe reportarse inmediatamente al coordinador del aula y registrarse en el cuaderno de incidencias. No intente reparar el vehículo sin autorización.

19. **Modificaciones**: Las modificaciones hardware (impresión 3D de piezas, sustitución de resortes, etc.) solo pueden realizarse con autorización previa del coordinador y deben documentarse en el registro del aula.

### Normas específicas para conducción autónoma

20. **Evaluación previa en simulador**: Antes de desplegar un modelo autónomo en el vehículo físico, el estudiante debe demostrar que el modelo funciona correctamente en el simulador AWS RoboMaker con un rendimiento mínimo aceptable (al menos completar una vuelta sin salirse de la pista en la evaluación simulada).

21. **Primer despliegue a velocidad reducida**: Al probar un modelo autónomo por primera vez en el vehículo físico, configúrelo a velocidad reducida (máximo 30% de la velocidad permitida) para evaluar su comportamiento real antes de aumentar la velocidad.

22. **Supervisión durante conducción autónoma**: El vehículo en modo autónomo debe estar siempre supervisado por al menos una persona con acceso al botón de parada de emergencia. Nunca deje el vehículo conduciendo solo sin supervisión.

---

## Enlaces y recursos adicionales

### Documentación oficial de AWS

| Recurso | URL |
|---|---|
| **Página oficial de AWS DeepRacer** | https://aws.amazon.com/deepracer/ |
| **Guía del desarrollador de AWS DeepRacer** | https://docs.aws.amazon.com/deepracer/ |
| **Guía del desarrollador (PDF)** | https://docs.aws.amazon.com/pdfs/deepracer/latest/developerguide/awsracerdg.pdf |
| **DeepRacer on AWS - Guía de implementación** | https://docs.aws.amazon.com/solutions/latest/deepracer-on-aws/solution-overview.html |
| **Anuncio del DeepRacer Evo** | https://aws.amazon.com/blogs/machine-learning/aws-deepracer-evo-and-sensor-kit-now-available-for-purchase |
| **Anuncio del código abierto** | https://aws.amazon.com/blogs/opensource/aws-deepracer-is-now-open-source-and-ready-to-hit-the-road-with-ros-2 |

### Repositorios de código fuente

| Recurso | URL |
|---|---|
| **GitHub: aws-deepracer (15 paquetes ROS 2)** | https://github.com/aws-deepracer |
| **GitHub: aws-deepracer-launcher** | https://github.com/aws-deepracer/aws-deepracer-launcher |
| **GitHub: FAQ oficial** | https://github.com/aws-deepracer/aws-deepracer/blob/main/frequently_asked_questions.md |
| **ROS Wiki: aws_deepracer** | http://wiki.ros.org/aws_deepracer |

### Recursos educativos y comunitarios

| Recurso | URL |
|---|---|
| **AWS DeepRacer Student (plataforma gratuita)** | https://student.deepracer.com |
| **AWS DeepRacer League** | https://aws.amazon.com/deepracer/league/ |
| **AWS Builder: Modificaciones del vehículo** | https://builder.aws.com/content/2wmc5dBRDe3jBPmu7WSJsZuaxa5/aws-deepracer-car-modifications |
| **Paper académico de Amazon Science** | https://assets.amazon.science/92/cf/eab397024814acaa157fb6db4d8a/scipub-1014.pdf |
| **Comunidad AWS re:Post (DeepRacer)** | https://repost.aws/tags/TAO7M4RzpLQIaKsz5bKzQ9Kw/aws-deepracer |
| **Deepracer for Cloud (DRFC)** | https://github.com/aws-deepracer-community/deepracer-for-cloud |

### Tutoriales y guías de entrenamiento

| Recurso | Descripción |
|---|---|
| **AWS DeepRacer Workshop** | Talleres oficiales de AWS para aprender a entrenar modelos RL paso a paso |
| **DeepRacer Analyser** | Herramienta comunitaria para analizar logs de entrenamiento y optimizar funciones de recompensa |
| **Action Space Guide** | Guía oficial sobre la selección y configuración del espacio de acción (discreto vs. continuo) |
| **Reward Function Examples** | Repositorio comunitario de funciones de recompensa de ejemplo para diferentes escenarios |

### Recursos del aula STEAM

| Recurso | Ubicación |
|---|---|
| **Guía de Setup y Control (STEAM Agent)** | Carpeta del proyecto Deepracer-STEAM-Agent |
| **Backend de control (Node.js + Express)** | `C:\Deepracer-STEAM-Agent\backend` |
| **Frontend de control (React + Vite)** | `C:\Deepracer-STEAM-Agent` |
| **Script de prueba move.js** | `C:\Deepracer-STEAM-Agent\move.js` |
| **Manual de referencia (este documento)** | Carpeta de manuales del aula STEAM |

### Soporte técnico

| Canal | Descripción |
|---|---|
| **AWS Support** | Soporte técnico oficial de AWS para problemas con los servicios en la nube (requiere plan de soporte) |
| **AWS re:Post** | Foro comunitario oficial donde consultar dudas y buscar soluciones |
| **GitHub Issues** | Reportar bugs y solicitar funcionalidades en los repositorios de código abierto |
| **Coordinador del aula STEAM** | Primer punto de contacto para problemas con el hardware y el software del vehículo en el aula |
