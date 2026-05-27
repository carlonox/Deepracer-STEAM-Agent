# Brazo Robot MG-400, Marca Dobot

## Descripción general

### ¿Qué es?

El DOBOT MG-400 es un brazo robótico colaborativo de escritorio (cobot) de 4 ejes, diseñado y fabricado por la empresa Shenzhen Yuejiang Technology Co., Ltd. (DOBOT). Se trata de un robot industrial ligero y compacto cuya huella en la mesa es inferior al tamaño de una hoja A4 (190 mm × 190 mm de base), lo que lo convierte en uno de los brazos robóticos colaborativos de menor tamaño del mercado. Su modelo completo es DT-MG-P4R07-01I. Fue presentado como una solución accesible para la automatización de pequeñas producciones y entornos educativos, combinando la precisión de un robot industrial con la seguridad de un cobot diseñado para trabajar junto a personas.

El MG-400 pertenece a la categoría de robots SCARA (Selective Compliance Assembly Robot Arm) de 4 grados de libertad, lo que significa que es especialmente adecuado para tareas de manipulación en el plano horizontal, como recogida y colocación (pick-and-place), ensamblaje, dispensado de adhesivos y manipulación de piezas ligeras. A diferencia de los robots articulados de 6 ejes, un SCARA de 4 ejes ofrece mayor rigidez en el eje vertical, lo que resulta en movimientos más rápidos y precisos para tareas repetitivas en superficies planas.

### ¿Para qué sirve en un contexto de diseño, ingeniería, arte o tecnología?

En un aula STEAM universitaria, el MG-400 es una herramienta versátil que permite a los estudiantes experimentar de primera mano con conceptos de robótica, automatización, programación y diseño mecatrónico. Sus aplicaciones educativas incluyen:

- **Ingeniería y automatización**: Los estudiantes pueden diseñar flujos de trabajo automatizados de pick-and-place, simulando líneas de producción industriales a escala de escritorio. Es ideal para comprender conceptos de control de movimiento, cinemática de robots, planificación de trayectorias y protocolos de comunicación industrial (TCP/IP, Modbus).
- **Diseño y fabricación digital**: Puede integrarse con otros equipos del aula, como impresoras 3D o fresadoras CNC, para automatizar procesos como la retirada de piezas impresas, el cambio de herramientas o la alimentación de material. Con el efector final de ventosa, puede manipular láminas delgadas o piezas ligeras en procesos de prototipado.
- **Arte y creatividad**: Con el efector final de sujetador de marcador, el robot puede realizar dibujos, caligrafía y patrones gráficos en papel, lo que lo convierte en una herramienta de arte generativo y exploración estética mediante algoritmos. Los estudiantes de artes visuales pueden programar trayectorias complejas y explorar la intersección entre tecnología y expresión artística.
- **Ciencia y tecnología**: Permite realizar experimentos de cinemática directa e inversa, análisis de precisión y repetibilidad, estudio de sensores (fuerza, visión, proximidad) y desarrollo de aplicaciones de visión por computador cuando se integra con cámaras o sensores externos.
- **Educación en programación**: DobotStudio Pro ofrece tres niveles de programación: bloques gráficos (Blockly) para principiantes, scripting en Lua para usuarios intermedios, y desarrollo en Python/C++ mediante TCP/IP para usuarios avanzados. Esto permite una curva de aprendizaje progresiva, desde la enseñanza por arrastre (drag-to-teach) hasta la programación de alto nivel.

### Principales características y capacidades

- **4 ejes de movimiento (SCARA)**: Alta velocidad y precisión en tareas planas de manipulación.
- **Carga útil de hasta 750 g**: Suficiente para manipular piezas pequeñas, componentes electrónicos, objetos de escritorio y herramientas ligeras.
- **Alcance máximo de 440 mm**: Radio de trabajo amplio para un robot de escritorio.
- **Repetibilidad de ±0,05 mm**: Precisión industrial adecuada para tareas de ensamblaje y posicionamiento fino.
- **Enseñanza por arrastre (drag-to-teach)**: Permite guiar el brazo manualmente para registrar puntos de trayectoria de forma intuitiva.
- **Detección de colisión**: Algoritmo de detección con umbral de fuerza inferior a 12 N; el robot se detiene instantáneamente al detectar contacto, permitiendo la colaboración segura con humanos sin necesidad de valla de seguridad.
- **Frenos en articulaciones J2 y J3**: Mantienen la posición del brazo en caso de corte de energía, evitando caídas accidentales.
- **Sensores integrados**: Sensores de fuerza multi-eje, sensores de visión y sensores de proximidad.
- **Conectividad rica**: Dos puertos Ethernet (LAN1 para conexión al PC, LAN2 para comunicación con dispositivos externos), soporte para TCP/IP, UDP y Modbus.
- **Programación multinivel**: Blockly (visual), Lua (scripting), Python/C++ (TCP/IP), lo que lo hace accesible para todos los niveles de experiencia.

---

## Especificaciones técnicas

### Especificaciones generales

| Parámetro | Valor |
|---|---|
| **Nombre** | DOBOT MG-400 |
| **Modelo** | DT-MG-P4R07-01I |
| **Número de ejes** | 4 (SCARA) |
| **Carga útil nominal** | 500 g |
| **Carga útil máxima** | 750 g |
| **Alcance máximo** | 440 mm |
| **Repetibilidad** | ±0,05 mm |
| **Peso del robot** | 8 kg |
| **Tamaño de la base** | 190 mm × 190 mm |
| **Huella** | Inferior a una hoja A4 |

### Rango de articulaciones

| Articulación | Rango |
|---|---|
| **J1** (base, rotación) | ±160° |
| **J2** (brazo, vertical) | -25° ~ +85° |
| **J3** (antebrazo, vertical) | -25° ~ +105° |
| **J4** (muñeca, rotación continua) | -360° ~ +360° |

### Velocidad máxima de articulaciones

| Articulación | Velocidad máxima |
|---|---|
| **J1** | 300 °/s |
| **J2** | 300 °/s |
| **J3** | 300 °/s |
| **J4** | 300 °/s |

### Especificaciones eléctricas

| Parámetro | Valor |
|---|---|
| **Alimentación** | 100 ~ 240 V CA, 50/60 Hz |
| **Tensión nominal** | 48 V CC |
| **Potencia nominal** | 240 W |
| **Consumo típico** | 150 W |

### Entorno de funcionamiento

| Parámetro | Valor |
|---|---|
| **Temperatura de funcionamiento** | 0 °C ~ 40 °C |
| **Humedad relativa** | 5% ~ 95% (sin condensación) |
| **Instalación** | Escritorio (superficie plana y estable) |

### Conectividad y comunicación

| Interfaz | Detalle |
|---|---|
| **LAN1** | Puerto Ethernet para conexión al PC (configuración y control mediante DobotStudio Pro) |
| **LAN2** | Puerto Ethernet para comunicación con dispositivos externos (soporta TCP, UDP) |
| **Puerto TCP/IP** | Puerto 502 (Modbus TCP) y otros puertos configurables para desarrollo secundario |
| **Protocolos** | TCP/IP, UDP, Modbus (RTU y TCP) |
| **Entradas/Salidas digitales** | Múltiples puertos DI/DO para integración con sensores y actuadores externos |
| **Entradas/Salidas analógicas** | Disponibles para señales de sensores analógicos |

### Sensores integrados

- Sensores de fuerza multi-eje (para detección de colisión y enseñanza por arrastre).
- Sensores de proximidad (detectan objetos cercanos al efector final).
- Sensores de posición absoluta (encoders absolutos en las 4 articulaciones, lo que elimina la necesidad de homing al encender).

### Software compatible

| Software | Descripción |
|---|---|
| **DobotStudio Pro** | Software oficial de control para MG-400 y M1 Pro. Incluye programación por bloques (Blockly), scripting en Lua, control manual, monitorización en tiempo real y simulación. |
| **Python (TCP/IP)** | Librería oficial de Dobot para desarrollo secundario mediante protocolo TCP/IP. Permite control completo del robot desde scripts de Python. |
| **C/C++** | SDK disponible para desarrollo de aplicaciones personalizadas en lenguajes compilados. |
| **ROS** | Comunidad de usuarios ha desarrollado paquetes ROS (Robot Operating System) para integración con frameworks de robótica avanzados. |

### Motores

- Motores servo de alta precisión con encoders absolutos en las 4 articulaciones.
- Frenos electromecánicos en las articulaciones J2 y J3 (las articulaciones J1 y J4 no requieren freno porque solo rotan en el plano horizontal y no se ven afectadas por la gravedad en caso de corte de energía).

---

## Componentes y partes

### Vista general del robot

El MG-400 está compuesto por los siguientes elementos principales, enumerados de la base al efector final:

### 1. Base (Base)

Es el elemento de anclaje del robot, de forma cuadrada (190 mm × 190 mm) y peso suficiente para proporcionar estabilidad. La base contiene:

- **Tornillería de fijación**: Agujeros para montaje en superficies o placas de trabajo.
- **Conector de alimentación**: Entrada del cable de alimentación (100-240 V CA).
- **Puerto LAN1**: Conector Ethernet para enlace con el ordenador de control.
- **Puerto LAN2**: Conector Ethernet para comunicación con dispositivos externos.
- **Puertos DI/DO**: Conectores para entradas y salidas digitales/analógicas.
- **Botón de encendido/apagado**: Interruptor principal con indicador LED.
- **Indicadores de estado**: LEDs que muestran el estado del robot (encendido, error, listo).

### 2. Articulación J1 (Base rotatoria)

Es la articulación de la base que permite la rotación del brazo completo en el plano horizontal. Tiene un rango de ±160° y es responsable del posicionamiento angular del robot respecto a la mesa de trabajo. No cuenta con freno porque la rotación horizontal no se ve afectada por la gravedad. El motor servo de esta articulación proporciona una velocidad máxima de 300 °/s.

### 3. Articulación J2 (Brazo superior)

Es la primera articulación vertical, responsable de la elevación y descenso del brazo. Su rango es de -25° a +85°. Esta articulación sí cuenta con freno electromecánico, lo que mantiene la posición del brazo en caso de pérdida de energía eléctrica. El peso del resto del brazo y la carga reposan sobre esta articulación, por lo que el freno es esencial para la seguridad.

### 4. Articulación J3 (Antebrazo)

Es la segunda articulación vertical, que controla la posición del extremo del brazo respecto al antebrazo. Su rango es de -25° a +105°. Al igual que J2, cuenta con freno electromecánico por las mismas razones de seguridad. Trabaja en conjunto con J2 para posicionar el efector final en el espacio de trabajo tridimensional.

### 5. Articulación J4 (Muñeca)

Es la articulación de rotación continua del efector final, con un rango de -360° a +360°. Permite orientar la herramienta o efector final en cualquier ángulo de rotación alrededor de su eje vertical. No requiere freno porque la rotación no se ve comprometida por la gravedad en caso de corte de energía.

### 6. Efector final (End Effector)

Es la herramienta montada en el extremo del brazo, intercambiable según la aplicación. El MG-400 admite los siguientes efectores finales oficiales:

- **Pinza electromagnética (Electromagnetic Gripper)**: Para sujetar piezas ferromagnéticas (metales que responden a imanes). Es la opción más sencilla y económica para manipulación de piezas metálicas pequeñas.
- **Pinza eléctrica servo (Electric Gripper - Servo Type)**: Pinza de dos dedos con control de apertura y fuerza de agarre precisos. Ideal para manipular piezas delicadas o de formas irregulares. Permite ajustar la fuerza de agarre para no dañar el objeto.
- **Kit de ventosa (Vacuum Suction Cup Kit)**: Requiere la bomba de vacío mini (Mini Vacuum Pump Box). Permite recoger y colocar objetos lisos y planos como tarjetas, láminas de plástico, piezas impresas en 3D y componentes electrónicos. Es muy utilizada en tareas de pick-and-place.
- **Bomba de vacío mini (Mini Vacuum Pump Box)**: Accesorio necesario para alimentar la ventosa. Se conecta al robot y genera el vacío necesario para la succión.
- **Pinza suave (Soft Gripper)**: Pinza de dedos blandos diseñada para manipular objetos frágiles o de formas irregulares sin dañarlos, como frutas, envases de plástico blando o piezas delicadas.

### 7. Cables y conexiones

- **Cable de alimentación**: Cable de red estándar que conecta el adaptador de potencia a la base del robot.
- **Cable Ethernet (LAN1)**: Cable de red para conectar el robot al ordenador.
- **Cable Ethernet (LAN2)**: Opcional, para conectar el robot a dispositivos externos como PLCs, sensores inteligentes o sistemas de visión.
- **Cable del efector final**: Cable que conecta la herramienta al brazo para transmitir señales de control y alimentación.

### 8. Fuente de alimentación

El MG-400 utiliza una fuente de alimentación externa que convierte 100-240 V CA a 48 V CC para alimentar el robot. La fuente se conecta a la base mediante un conector específico. Es importante utilizar siempre la fuente de alimentación original suministrada por Dobot para evitar daños al equipo.

### 9. Botón de parada de emergencia

El robot cuenta con un botón de parada de emergencia (E-stop) accesible. Al pulsarlo, el robot se detiene inmediatamente y los frenos de J2 y J3 se activan para mantener la posición. Es un elemento de seguridad esencial que debe estar siempre accesible durante la operación del robot.

---

## Configuración y puesta en marcha

### Paso 1: Verificación del contenido del paquete

Antes de comenzar, verifique que el paquete incluye todos los componentes:

- Robot MG-400.
- Fuente de alimentación (100-240 V CA → 48 V CC).
- Cable de alimentación.
- Cable Ethernet.
- Efector final (según la configuración adquirida: pinza, ventosa, etc.).
- Guía de inicio rápido (Quickstart Guide).
- Tarjeta de garantía.

Si falta algún componente, no intente operar el robot y contacte al proveedor.

### Paso 2: Selección y preparación de la superficie de trabajo

- Elija una superficie plana, estable y nivelada, como un banco de trabajo o mesa resistente.
- Asegúrese de que la superficie soporta el peso del robot (8 kg) más la fuerza de reacción durante el movimiento.
- Verifique que hay suficiente espacio libre alrededor del robot para el alcance completo de los 440 mm del brazo. Se recomienda un área libre de al menos 1 m × 1 m alrededor de la base.
- No coloque el robot cerca de bordes de mesas donde pueda caer.
- Asegúrese de que no hay objetos frágiles, líquidos o cables sueltos en el área de trabajo del brazo.

### Paso 3: Fijación del robot

Para un uso seguro, se recomienda fijar la base del robot a la superficie de trabajo utilizando los agujeros de montaje de la base. Si no es posible fijarlo permanentemente, asegúrese de que la superficie tenga suficiente fricción (superficie antideslizante) o utilice abrazaderas de sujeción. Un robot que se desplace durante la operación puede causar errores de posicionamiento y riesgos de seguridad.

### Paso 4: Montaje del efector final

- Seleccione el efector final adecuado para su tarea.
- Monte el efector en el extremo del brazo (articulación J4) siguiendo las instrucciones del manual del efector.
- Conecte el cable del efector al conector correspondiente en el brazo.
- Verifique que el efector está firmemente sujeto antes de encender el robot.
- Si utiliza la ventosa, monte también la bomba de vacío mini y conecte el tubo de vacío entre la bomba y la ventosa.

### Paso 5: Conexión de cables

1. **Conexión de red**: Conecte un cable Ethernet desde el puerto LAN1 de la base del robot al ordenador que ejecutará DobotStudio Pro.
2. **Conexión de alimentación**: Conecte el cable de alimentación a la fuente de alimentación externa y luego conecte la salida de la fuente al conector de la base del robot.
3. **Conexión a red eléctrica**: Enchufe la fuente de alimentación a una toma de corriente de 100-240 V CA.

### Paso 6: Configuración de red del ordenador

Para comunicarse con el robot por primera vez, debe configurar la dirección IP del ordenador en la misma subred que el robot:

1. Conecte el cable Ethernet al puerto LAN1 del robot y al adaptador de red del ordenador.
2. En el ordenador, vaya a **Configuración de red → Cambiar configuración del adaptador**.
3. Haga clic derecho en el adaptador de red Ethernet conectado al robot y seleccione **Propiedades**.
4. Seleccione **Protocolo de Internet versión 4 (TCP/IPv4)** y haga clic en **Propiedades**.
5. Configure una dirección IP estática en el rango 192.168.1.x (por ejemplo, 192.168.1.100), con máscara de subred 255.255.255.0.
6. La dirección IP predeterminada del robot MG-400 es 192.168.1.6. Asegúrese de que no hay conflicto de direcciones IP.

### Paso 7: Encendido del robot

1. Verifique que todas las conexiones están correctas y firmes.
2. Pulse el botón de encendido en la base del robot.
3. El indicador LED se iluminará y el robot iniciará su secuencia de arranque.
4. Espere a que el robot complete la inicialización (los LEDs indicarán cuando está listo).
5. Los motores servo se activarán y el robot mantendrá su posición actual.

**Precaución**: Al encender, el robot puede realizar un pequeño movimiento de inicialización. Asegúrese de que no hay objetos ni personas en el área de trabajo antes de encender.

### Paso 8: Instalación de DobotStudio Pro

1. Descargue la última versión de DobotStudio Pro desde el centro de descargas de Dobot: https://www.dobot-robots.com/service/download-center
2. Instale el software en el ordenador siguiendo el asistente de instalación.
3. Ejecute DobotStudio Pro.
4. El software buscará automáticamente el robot en la red. Si no lo detecta, verifique la configuración de red y la conexión del cable Ethernet.
5. Seleccione el robot MG-400 cuando aparezca en la lista de dispositivos detectados.
6. Haga clic en **Conectar** para establecer la comunicación.

### Paso 9: Verificación del funcionamiento

Una vez conectado, realice las siguientes comprobaciones:

1. **Estado del robot**: Verifique que DobotStudio Pro muestra el estado "Conectado" y las coordenadas actuales del brazo.
2. **Movimiento manual**: Utilice el control de movimiento manual en DobotStudio Pro para mover cada articulación individualmente (J1, J2, J3, J4) y verificar que responden correctamente.
3. **Efector final**: Pruebe la apertura y cierre de la pinza o la activación de la ventosa desde el software para confirmar que el efector final funciona.
4. **Enseñanza por arrastre**: Active el modo de enseñanza por arrastre (drag-to-teach) y mueva manualmente el brazo a varias posiciones para verificar que los frenos se liberan y el brazo se mueve suavemente.
5. **Detección de colisión**: Con la detección de colisión activada, aplique una fuerza suave al brazo durante su movimiento para verificar que el robot se detiene correctamente.

### Precauciones de seguridad importantes

- **Nunca** opere el robot sin supervisión si es la primera vez que lo utiliza.
- **Siempre** mantenga el botón de parada de emergencia al alcance durante la operación.
- **No** exceda la carga útil máxima de 750 g. El sobreesfuerzo puede dañar los motores y reducir la vida útil del robot.
- **No** coloque los dedos entre las articulaciones del brazo mientras está en movimiento.
- **No** intente desmontar o modificar el robot. Cualquier modificación no autorizada anula la garantía y puede causar lesiones.
- **Asegúrese** de que el área de trabajo esté libre de obstáculos antes de ejecutar un programa.
- **Desconecte** la alimentación cuando no utilice el robot durante períodos prolongados.
- **Mantenga** líquidos y alimentos alejados del robot y sus conexiones eléctricas.
- **No** utilice el robot en entornos con polvo metálico, humedad excesiva o temperaturas fuera del rango de 0 °C a 40 °C.
- Si el robot emite sonidos inusuales, se mueve de forma errática o muestra mensajes de error, **deténgalo inmediatamente** y consulte la sección de solución de problemas.

---

## Guía de uso paso a paso

### Tarea típica: Programar un ciclo de pick-and-place con pinza eléctrica

A continuación se describe paso a paso cómo programar una tarea de recogida y colocación (pick-and-place) utilizando la pinza eléctrica servo y el entorno de programación por bloques Blockly en DobotStudio Pro. Esta es una de las tareas más representativas y frecuentes con el MG-400, y constituye un excelente punto de partida para estudiantes.

### Paso 1: Preparación del entorno

1. Asegúrese de que el robot está encendido, conectado al ordenador y que DobotStudio Pro muestra el estado "Conectado".
2. Monte la pinza eléctrica servo en el extremo del brazo (J4) y conecte su cable.
3. Coloque el objeto a recoger (por ejemplo, un cubo de plástico ligero de menos de 500 g) en una posición accesible dentro del área de trabajo del robot.
4. Defina mentalmente dos posiciones: la posición de recogida (donde está el objeto) y la posición de colocación (donde quiere depositarlo).

### Paso 2: Crear un nuevo proyecto en DobotStudio Pro

1. Abra DobotStudio Pro.
2. Haga clic en **Nuevo proyecto** o **New Project**.
3. Seleccione **Proyecto Blockly** (recomendado para principiantes). Los proyectos Blockly permiten crear programas arrastrando y soltando bloques visuales, de forma similar a Scratch.
4. Asigne un nombre descriptivo al proyecto, por ejemplo, "Pick_and_Place_Basico".
5. Seleccione el robot MG-400 como dispositivo de destino.

### Paso 3: Configurar la velocidad y el modo de movimiento

1. En el panel de bloques, busque la categoría **Movimiento**.
2. Arrastre el bloque de configuración de velocidad al área de trabajo. Se recomienda una velocidad del 30% al 50% para principiantes, ya que permite observar el movimiento con suficiente tiempo de reacción en caso de error.
3. Configure la aceleración a un valor moderado (20-30%).

### Paso 4: Enseñar las posiciones de recogida y colocación

Existen dos métodos para enseñar posiciones al robot:

**Método A: Enseñanza por arrastre (drag-to-teach)**

1. En DobotStudio Pro, active el modo de enseñanza por arrastre.
2. Mueva manualmente el brazo del robot hasta la posición de recogida (sobre el objeto).
3. En el software, haga clic en **Registrar punto** o **Add Point**. El software guardará las coordenadas (X, Y, Z) y la orientación (R) actuales.
4. Nombre este punto como "Recogida" o "Pick".
5. Repita el proceso para la posición de colocación y nombre el punto como "Colocacion" o "Place".
6. También registre dos posiciones intermedias elevadas (aproximadamente 50 mm por encima de las posiciones de recogida y colocación) para que el robot se eleve entre movimientos y no arrastre el objeto por la superficie. Nómbrelas "Recogida_Arriba" y "Colocacion_Arriba".

**Método B: Ingreso manual de coordenadas**

Si conoce las coordenadas exactas de las posiciones, puede escribirlas directamente en los bloques de movimiento. Esto es útil cuando se trabaja con calibraciones precisas.

### Paso 5: Construir el programa en Blockly

Organice los bloques en la siguiente secuencia lógica:

```
1. [Configurar velocidad: 30%]
2. [Abrir pinza]
3. [Mover a: Recogida_Arriba] (movimiento articular, JointMovJ)
4. [Mover a: Recogida] (movimiento articular o lineal, MovJ o MovL)
5. [Cerrar pinza]
6. [Esperar: 0.5 segundos]
7. [Mover a: Recogida_Arriba]
8. [Mover a: Colocacion_Arriba]
9. [Mover a: Colocacion]
10. [Abrir pinza]
11. [Esperar: 0.5 segundos]
12. [Mover a: Colocacion_Arriba]
13. [Volver a posición inicial/Home]
```

**Tipos de movimiento importantes**:

- **JointMovJ (Movimiento articular)**: El robot se mueve a la posición objetivo utilizando el camino más rápido para cada articulación de forma independiente. Es el movimiento más rápido pero la trayectoria en el espacio cartesiano no es una línea recta. Ideal para movimientos entre posiciones distantes donde la trayectoria no es crítica.
- **MovL (Movimiento lineal)**: El efector final se mueve en línea recta desde la posición actual hasta la posición objetivo. Es más lento pero ofrece un control preciso de la trayectoria. Ideal para aproximaciones y retiradas donde es importante no chocar con objetos.
- **MovJ (Movimiento de salto)**: Combinación de movimiento articular y lineal. El robot se mueve de forma articular pero con una transición suave cerca del objetivo.

### Paso 6: Probar el programa en velocidad reducida

1. **Nunca** ejecute un programa por primera vez a velocidad completa.
2. Configure la velocidad al 10-20% para la primera prueba.
3. Haga clic en **Ejecutar** o **Run** en DobotStudio Pro.
4. Observe cuidadosamente cada movimiento del robot y verifique que:
   - Las posiciones de recogida y colocación son correctas.
   - El robot no choca con ningún obstáculo.
   - La pinza abre y cierra en los momentos adecuados.
   - El objeto se recoge y se coloca correctamente.
5. Si el robot se mueve a una posición inesperada, pulse inmediatamente el botón de parada de emergencia.

### Paso 7: Ajustar y optimizar

- Si la pinza no agarra bien el objeto, ajuste la fuerza de agarre en el bloque de la pinza.
- Si el robot se aproxima demasiado rápido a la posición de recogida, sustituya el último tramo de movimiento por un MovL (lineal) a velocidad reducida.
- Añada pausas (esperas) entre movimientos si necesita que el robot se detenga brevemente.
- Si el movimiento es demasiado lento para producción, aumente gradualmente la velocidad tras verificar que todo funciona correctamente.

### Paso 8: Guardar y documentar el programa

1. Guarde el proyecto en DobotStudio Pro.
2. Tome notas de las posiciones registradas, los ajustes de velocidad y cualquier modificación realizada.
3. Si desea ejecutar el programa de forma autónoma (sin el ordenador conectado), puede cargar el programa en el controlador del robot utilizando la función de exportación a script Lua y luego cargarlo en el robot.

### Consejos para principiantes

- **Empiece simple**: No intente programar tareas complejas en su primer intento. Un pick-and-place básico es suficiente para entender los conceptos fundamentales.
- **Use posiciones intermedias elevadas**: Siempre eleve el brazo entre la recogida y la colocación para evitar colisiones con objetos en la superficie de trabajo.
- **Reduzca la velocidad al mínimo** durante las pruebas y aumente gradualmente solo cuando confirme que el programa funciona correctamente.
- **Aproveche la enseñanza por arrastre**: Es la forma más intuitiva de enseñar posiciones al robot. No necesita calcular coordenadas manualmente.
- **Pruebe un movimiento a la vez**: En lugar de ejecutar todo el programa de una vez, ejecute los bloques uno por uno durante la depuración para identificar errores fácilmente.
- **Mantenga el área de trabajo despejada**: Retire objetos innecesarios de la zona de alcance del robot antes de ejecutar programas.
- **Consulte la documentación oficial**: El *DobotStudio Pro User Guide* y el *MG400 User Guide* contienen información detallada sobre cada función y comando.

---

## Mantenimiento básico

### Limpieza

La limpieza regular del MG-400 es esencial para mantener su precisión y prolongar su vida útil. Se recomienda seguir estas pautas:

- **Frecuencia**: Limpie el robot después de cada sesión de uso intensivo o, como mínimo, una vez por semana en un aula STEAM con uso regular.
- **Superficie exterior**: Utilice un paño suave y ligeramente humedecido con agua o alcohol isopropílico al 70% para limpiar las superficies exteriores del robot. No utilice disolventes agresivos (acetona, benceno) que puedan dañar los plásticos o las etiquetas.
- **Articulaciones**: Limpie cuidadosamente alrededor de las articulaciones con un pincel suave o aire comprimido para eliminar polvo y residuos. Evite que entre humedad en las juntas de las articulaciones.
- **Efector final**: Limpie las superficies de agarre de la pinza después de cada uso. Si utiliza la ventosa, asegúrese de que la superficie de la copa de succión esté libre de polvo y residuos, ya que cualquier partícula puede comprometer el sellado al vacío.
- **Cables**: Inspeccione los cables periódicamente para detectar desgaste, dobleces o cortes. Limpie los conectores con aire comprimido para garantizar una buena conexión.
- **Base**: Asegúrese de que la base del robot esté limpia y libre de residuos que puedan afectar la estabilidad del montaje.

### Calibración

El MG-400 cuenta con encoders absolutos en sus cuatro articulaciones, lo que significa que **no requiere un procedimiento de homing (retorno al origen) al encender**, a diferencia de otros robots que necesitan volver a una posición de referencia conocida. Sin embargo, es importante verificar la calibración periódicamente:

- **Verificación de repetibilidad**: Ejecute un programa simple que mueva el robot a una posición y vuelva, y verifique que el efector final retorna exactamente al mismo punto. Una desviación superior a ±0,05 mm puede indicar un problema de calibración.
- **Verificación de coordenadas**: Compare las coordenadas mostradas en DobotStudio Pro con la posición real del efector final utilizando un calibrador o regla de precisión.
- **Recalibración**: Si detecta desviaciones, consulte el manual de usuario del hardware del MG-400 para el procedimiento de recalibración. Este proceso puede requerir herramientas especializadas y es recomendable que lo realice personal técnico capacitado.
- **Offset de articulaciones**: En DobotStudio Pro, puede ajustar los offsets de las articulaciones (J1-J4) para compensar desviaciones menores sin necesidad de recalibración completa.

### Cambio de efectores finales

El cambio de efector final es una operación frecuente en un aula STEAM. Siga estos pasos:

1. **Apague el robot** o póngalo en modo de seguridad antes de realizar el cambio.
2. **Desconecte el cable** del efector actual del brazo.
3. **Aflore los tornillos** de fijación del efector y retírelo con cuidado.
4. **Monte el nuevo efector** alineando los puntos de fijación y apretando los tornillos firmemente.
5. **Conecte el cable** del nuevo efector al conector correspondiente en el brazo.
6. **Encienda el robot** y seleccione el tipo de efector correcto en DobotStudio Pro (Configuración → Efector final → Tipo).
7. **Pruebe el efector** realizando movimientos simples de apertura y cierre o activación/desactivación antes de ejecutar programas completos.

### Inspección periódica

Se recomienda realizar las siguientes inspecciones de forma regular:

- **Mensual**: Inspeccionar visualmente todas las articulaciones en busca de holguras o desgaste anormal. Verificar que los cables no presenten dobleces o rozaduras.
- **Trimestral**: Comprobar la repetibilidad del robot con un programa de prueba. Verificar el correcto funcionamiento de los frenos de J2 y J3 (el brazo no debe caer al desconectar la alimentación).
- **Semestral**: Revisar los conectores de la base en busca de oxidación o corrosión. Verificar la fijación del robot a la superficie de trabajo.
- **Anual**: Realizar una revisión completa del robot, incluyendo la inspección de los motores servo, los engranajes internos y la electrónica. Esta revisión puede requerir la intervención del servicio técnico de Dobot o un distribuidor autorizado.

### Almacenamiento adecuado

Cuando el robot no se utilice durante períodos prolongados (por ejemplo, durante vacaciones o recesos académicos):

- **Apague el robot** y desconecte la alimentación de la red eléctrica.
- **Retire el efector final** y guárdelo en su embalaje original o en un lugar protegido.
- **Cubra el robot** con una funda antipolvo para proteger las articulaciones y la superficie.
- **Guarde los cables** enrollados sin dobleces pronunciados.
- **Mantenga el robot** en un lugar seco, a temperatura ambiente (15-25 °C) y lejos de la luz solar directa.
- **No apile** objetos sobre el robot durante el almacenamiento.
- Si el almacenamiento supera los 6 meses, realice una prueba de funcionamiento antes de volver a ponerlo en operación regular.

---

## Solución de problemas comunes

A continuación se presenta una tabla con los problemas más frecuentes que pueden surgir al usar el DOBOT MG-400, junto con sus posibles causas y soluciones recomendadas.

| Problema | Posible causa | Solución |
|---|---|---|
| El robot no enciende | Cable de alimentación desconectado o fuente dañada | Verifique que el cable de alimentación está firmemente conectado a la fuente y a la toma de corriente. Compruebe que la toma de corriente funciona. Si el problema persiste, la fuente de alimentación puede estar defectuosa; contacte al soporte técnico. |
| DobotStudio Pro no detecta el robot | Configuración de red incorrecta o cable Ethernet desconectado | Verifique que el cable Ethernet está conectado al puerto LAN1. Compruebe que la dirección IP del ordenador está en la misma subred que el robot (192.168.1.x). Intente hacer ping a 192.168.1.6 desde la consola de comandos. Reinicie el robot y el software. |
| El robot se mueve a posiciones incorrectas | Calibración desalineada o offsets incorrectos | Verifique los offsets de las articulaciones en DobotStudio Pro. Compare las coordenadas del software con la posición real del brazo. Si hay desviación, ajuste los offsets o realice una recalibración. |
| La pinza no abre o no cierra | Efector final no configurado correctamente o cable desconectado | En DobotStudio Pro, verifique que el tipo de efector final seleccionado corresponde a la pinza instalada. Compruebe que el cable del efector está conectado. Pruebe el efector desde el panel de control manual. |
| La ventosa no succiona | Bomba de vacío apagada, tubo obstruido o copa dañada | Verifique que la bomba de vacío mini está encendida y conectada. Inspeccione el tubo de vacío en busca de obstrucciones o fugas. Compruebe que la superficie de la copa de succión está limpia y sin grietas. Reemplace la copa si está desgastada. |
| El robot se detiene durante un programa | Detección de colisión activada o error de servo | Verifique si hay un mensaje de error en DobotStudio Pro. Si es una detección de colisión, quite el obstáculo y reinicie el programa. Si es un error de servo, apague y encienda el robot. Si el error persiste, contacte al soporte técnico. |
| Error de comunicación TCP/IP | Puerto incorrecto o firewall bloqueando | Verifique que está utilizando el puerto correcto (502 para Modbus TCP, u otros según configuración). Desactive temporalmente el firewall del ordenador para descartarlo. Compruebe que la dirección IP del robot es accesible. |
| El brazo cae al apagar | Frenos de J2 o J3 defectuosos | Los frenos de J2 y J3 deben mantener la posición del brazo al cortar la energía. Si el brazo cae, uno o ambos frenos pueden estar dañados. **No utilice el robot** hasta que un técnico revise los frenos, ya que constituye un riesgo de seguridad. |
| Movimiento irregular o tembloroso | Velocidad o aceleración excesiva, o carga superior al límite | Reduzca la velocidad y la aceleración en la configuración del programa. Verifique que la carga no supera los 750 g. Si el problema persiste con carga ligera, puede haber un problema mecánico en las articulaciones. |
| El robot no guarda el programa para ejecución autónoma | Proyecto no exportado correctamente | Para ejecutar el robot de forma autónoma (sin PC), debe exportar el proyecto Blockly a script Lua y cargarlo en el controlador del robot. Consulte la sección "Porting Blockly Program to Script" en la guía de DobotStudio Pro. |
| Ruido anormal en las articulaciones | Falta de lubricación, desgaste de engranajes o cuerpo extraño | Detenga el robot inmediatamente. Inspeccione visualmente la articulación afectada. Si el ruido persiste, contacte al servicio técnico de Dobot. No intente lubricar o desmontar las articulaciones por su cuenta, ya que puede anular la garantía. |
| Error "Robot no está listo" en DobotStudio Pro | Robot en estado de error o no inicializado | Reinicie el robot apagándolo y encendiéndolo. Verifique que no hay botones de parada de emergencia activados. Si el error persiste, consulte el código de error en el manual del usuario. |
| El programa se ejecuta pero los movimientos no coinciden | Sistema de coordenadas incorrecto | Verifique que el sistema de coordenadas seleccionado (articulación, base o herramienta) es el correcto para su programa. Los puntos enseñados en un sistema de coordenadas no son directamente compatibles con otro. |

---

## Materiales, repuestos o accesorios típicos

### Efectores finales oficiales

Los siguientes efectores finales son los accesorios oficiales diseñados específicamente para el MG-400:

| Accesorio | Descripción | Uso típico en el aula |
|---|---|---|
| **Pinza electromagnética** | Pinza que utiliza un electroimán para sujetar piezas ferromagnéticas. | Manipulación de piezas metálicas pequeñas, demostraciones de automatización. |
| **Pinza eléctrica servo** | Pinza de dos dedos con control de apertura y fuerza de agarre precisos. | Pick-and-place de piezas delicadas, ensamblaje de componentes, manipulación de objetos de formas variadas. |
| **Kit de ventosa** | Conjunto de copa de succión y accesorios de montaje. Requiere la bomba de vacío mini. | Manipulación de objetos lisos y planos: tarjetas, láminas, piezas impresas en 3D. |
| **Bomba de vacío mini** | Unidad compacta que genera vacío para la ventosa. Se conecta al robot. | Componente necesario para el funcionamiento del kit de ventosa. |
| **Pinza suave (Soft Gripper)** | Pinza de dedos blandos adaptativos. | Manipulación de objetos frágiles o irregulares: frutas, envases, piezas delicadas. |

### Consumibles

Los siguientes elementos se consideran consumibles que pueden necesitar reemplazo periódico:

- **Copa de succión (ventosa)**: Las copas de succión se desgastan con el uso y deben reemplazarse cuando pierden elasticidad o presentan grietas. Se recomienda tener repuestos en el aula.
- **Cables Ethernet**: Los cables de red pueden sufrir desperfectos por dobleces o tirones. Tenga al menos un cable de repuesto.
- **Cable de alimentación**: Similar al cable Ethernet, debe tener un repuesto disponible.
- **Cable del efector final**: Puede desgastarse por el movimiento repetitivo del brazo. Inspeccione periódicamente y reemplace si muestra signos de deterioro.

### Repuestos recomendados para el aula

Se sugiere mantener un inventario mínimo de los siguientes elementos:

- 2 copas de succión de repuesto.
- 1 cable Ethernet de repuesto (longitud adecuada).
- 1 cable de alimentación de repuesto.
- Tornillería de fijación de la base (juego completo de repuesto).
- Tornillería de montaje de efectores finales.

### Disponibilidad en el aula

Los accesorios y consumibles del MG-400 pueden adquirirse a través de:

- Distribuidores oficiales de Dobot en su región.
- Tiendas en línea especializadas en robótica educativa (Afinia, RobotLAB, etc.).
- El sitio oficial de Dobot (https://www.dobot-robots.com) para compras directas o referencias a distribuidores locales.

Consulte con el coordinador del aula STEAM sobre la disponibilidad actual de cada accesorio y repuesto, así como el procedimiento para solicitar compras de reposición.

---

## Normas de uso en el aula STEAM

### Normas generales

1. **Formación obligatoria**: Todo estudiante debe recibir una inducción básica sobre el funcionamiento y la seguridad del MG-400 antes de operarlo por primera vez. Esta inducción incluye la lectura de este manual, una demostración práctica por parte del asistente o docente, y la firma de un compromiso de uso responsable.

2. **Supervisión**: Los estudiantes de primer uso deben operar el robot bajo la supervisión directa de un docente, asistente de laboratorio o estudiante previamente certificado. No se permite el uso autónomo del robot hasta que el estudiante haya demostrado competencia en las operaciones básicas.

3. **Reserva de uso**: El uso del MG-400 debe reservarse con anticipación a través del sistema de reservas del aula STEAM. Cada sesión tiene una duración máxima de 2 horas, prorrogables solo si no hay otros estudiantes en espera.

4. **Registro de uso**: Al inicio de cada sesión, el estudiante debe registrar su nombre, fecha, hora de inicio y el tipo de tarea a realizar en el cuaderno de registro del aula. Al finalizar, debe registrar la hora de finalización y cualquier incidencia observada.

### Normas de seguridad

5. **Espacio de trabajo libre**: Antes de encender el robot, verifique que el área de trabajo (radio de al menos 50 cm alrededor de la base) está libre de objetos innecesarios, líquidos y cables sueltos.

6. **Parada de emergencia**: El botón de parada de emergencia debe estar siempre accesible y el operador debe conocer su ubicación. En caso de movimiento inesperado o situación de peligro, pulse el botón inmediatamente.

7. **Velocidad reducida para principiantes**: Los estudiantes que utilizan el robot por primera vez deben operar a una velocidad máxima del 30% hasta que demuestren competencia. La velocidad solo puede aumentarse con autorización del docente o asistente.

8. **No intervenir durante el movimiento**: Nunca introduzca las manos u objetos en el espacio de trabajo del robot mientras está en movimiento. Espere a que el robot se detenga completamente antes de realizar ajustes.

9. **Carga útil respetada**: No intente manipular objetos que superen los 750 g de carga máxima. El exceso de peso puede dañar los motores y generar errores de posicionamiento.

10. **Detección de colisión activada**: La detección de colisión debe estar siempre activada durante la operación, especialmente en entornos educativos con múltiples usuarios.

### Normas de higiene y cuidado

11. **Limpieza obligatoria**: Al finalizar cada sesión, el estudiante debe limpiar el robot (superficies, articulaciones y efector final) y el área de trabajo. Utilice un paño suave ligeramente humedecido. No utilice productos abrasivos.

12. **Dejar en posición segura**: Al terminar, deje el robot en su posición de fábrica (Home) o en una posición plegada que minimice el riesgo de golpes accidentales. Apague el robot y desconecte la alimentación.

13. **Guardado de accesorios**: Los efectores finales no utilizados deben guardarse en su lugar designado (caja de accesorios del aula). No deje efectores sueltos sobre la mesa de trabajo.

14. **Reporte de daños**: Cualquier daño, funcionamiento anormal o pieza faltante debe reportarse inmediatamente al coordinador del aula o al docente responsable. No intente reparar el robot por su cuenta.

### Normas de convivencia

15. **Respeto del turno**: Si hay estudiantes en espera, respete el límite de tiempo de su sesión. Si necesita más tiempo, coordine con el siguiente usuario.

16. **Compartir conocimientos**: Se fomenta que los estudiantes con más experiencia apoyen a los principiantes, siempre bajo la supervisión del docente.

17. **No modificar programas ajenos**: No modifique o elimine programas creados por otros estudiantes sin su autorización. Guarde sus propios programas con un nombre que incluya su identificación.

18. **Cierre de sesión**: Al finalizar, cierre DobotStudio Pro y cierre sesión en el ordenador. No deje programas ejecutándose sin supervisión.

---

## Enlaces y recursos adicionales

### Sitio oficial y documentación

- **Sitio oficial de DOBOT MG-400**: https://www.dobot-robots.com/products/desktop-four-axis/mg400.html
- **Centro de descargas de Dobot** (manuales, software, firmware): https://www.dobot-robots.com/service/download-center
- **Guía de inicio rápido del MG-400** (PDF): https://www.dobot.us/wp-content/uploads/2024/10/MG400-QUICKSTART-GUIDE.pdf
- **Guía de usuario del MG-400** (PDF, inglés): https://dobotpolska.pl/wp-content/uploads/2024/08/Dobot-MG400-User-Guide-V1.7_20231116_eng.pdf
- **Guía de usuario de DobotStudio Pro** (PDF, para MG-400 y M1 Pro): https://www.pololu.com/file/0J2074/DobotStudio%20Pro%20User%20Guide%20(MG400&M1%20Pro)%20V2.8.0_20240226_en.pdf
- **Especificaciones del MG-400** (Dobot US): https://www.dobot.us/mg400-specs
- **Efectores finales del MG-400** (Dobot US): https://www.dobot.us/mg400-end-effectors
- **Sitio en español de Dobot**: https://es.dobot-robots.com/
- **Distribuidor en España (Dobotspain)**: https://www.dobotspain.com/products/desktop-four-axis/mg400.php

### Recursos de programación

- **Repositorio oficial de TCP/IP para Python** (GitHub): https://github.com/Dobot-Arm/TCP-IP-4Axis-Python
- **Documentación de la API TCP/IP para desarrollo secundario**: Disponible en el centro de descargas de Dobot, sección "TCP/IP Secondary Development Interface".

### Tutoriales en vídeo

- **Dobot MG400 Robotic Arm: First Impressions and Demos** (inglés, descripción general del hardware y software): https://www.youtube.com/watch?v=6nGexb_i0aM
- **Setting Up Dobot MG400: First Steps** (inglés, configuración inicial): https://www.youtube.com/watch?v=wsEc-jdXfJs
- **MG400 Training 2021** (inglés, formación completa): https://www.youtube.com/watch?v=NFcDOGSBEKM
- **Dobot MG400 Accessories and End Effectors** (inglés, demostración de accesorios): https://www.youtube.com/watch?v=jCH-F3oApt8

### Foros y comunidades

- **Subreddit de Dobot** (Reddit): https://www.reddit.com/r/Dobot/
- **Stack Overflow** (preguntas técnicas sobre programación): Busque con la etiqueta "dobot" o "mg400".
- **Foro oficial de Dobot**: Disponible a través del centro de soporte en el sitio web de Dobot.
- **Comunidad de Robótica en ROS Discourse**: Para usuarios que integran el MG-400 con ROS.

### Manuales adicionales

- **Manual del MG-400 en Manuals+** (español): https://manuals.plus/es/dobot/mg400-robot-arm-kit-desktop-manual
- **Especificaciones del producto (Flyer 2024)**: https://optima-robotics.com/wp-content/uploads/2024/07/MG400-Flyer-2024-EN.pdf
- **Guía de hardware del MG-400** (PDF, inglés): https://digioptima.eu/wp-content/uploads/2023/10/Dobot-MG400-Hardware-User-Guide-V1.1.pdf
