# Manual de Usuario — Impresora 3D Creality K1

**Aula STEAM — Manual de referencia para estudiantes y asistente robot AI**

---

## 1. Descripción general

La Creality K1 es una impresora 3D FDM de alta velocidad que representa un salto cualitativo respecto a las impresoras de la generación anterior como la Ender-3. Diseñada en torno a una cinemática CoreXY con chasis soldado y carriles lineales metálicos en los ejes X e Y, la K1 es capaz de alcanzar velocidades de impresión de hasta 600 mm/s con aceleraciones de 20.000 mm/s², lo que la convierte en una de las impresoras de su rango de precio más rápidas del mercado. Para poner estas cifras en perspectiva, una Ender-3 S1 típica imprime a 60-80 mm/s, lo que significa que la K1 puede ser hasta 7-10 veces más rápida en condiciones óptimas.

El chasis está completamente cerrado con paneles laterales de acrílico tintado oscuro y una puerta frontal de vidrio, lo que proporciona estabilidad térmica para imprimir materiales como ABS, ASA y otros filamentos técnicos que requieren un entorno cerrado para minimizar el warping y las delaminaciones. Esta carcasa cerrada también reduce significativamente el ruido del ventilador y de los motores, haciendo que la K1 sea notablemente más silenciosa que las impresoras abiertas de la serie Ender.

A nivel de firmware, la K1 ejecuta CrealityOS, una versión personalizada de Klipper optimizada por Creality. Klipper es un firmware de código abierto que delega el procesamiento intensivo a un microprocesador de mayor potencia (en este caso, una CPU de doble núcleo a 1,2 GHz), liberando al microcontrolador tradicional de la placa base para que se dedique exclusivamente a generar los pulsos de paso para los motores. Esta arquitectura es lo que permite las altas velocidades y aceleraciones que caracterizan a la K1, junto con funciones avanzadas como el input shaping (compensación de resonancias mecánicas) que elimina el ghosting y el ringing en las piezas impresas a alta velocidad.

La K1 incorpora un extrusor directo (direct drive) de doble engranaje que proporciona una fuerza de empuje de hasta 80 N, suficiente para alimentar filamentos flexibles (TPU) de manera fiable sin necesidad de modificaciones. El hotend alcanza los 300 °C y utiliza una ruptura térmica de aleación de titanio con boquilla de acero endurecido, un conjunto de tipo Volcano que permite flujos volumétricos de hasta 32 mm³/s. La cama calefactada llega a 100 °C y cuenta con auto-nivelación mediante sensores de deformación (strain sensors) integrados bajo la placa de construcción.

En el aula STEAM se dispone de **dos (2) unidades** de la Creality K1, lo que permite trabajar en paralelo, asignar cada máquina a tipos de filamento diferentes para evitar contaminación cruzada, o bien dedicar una unidad a impresiones de alta calidad y la otra a prototipos rápidos. La K1 viene prácticamente ensamblada de fábrica; tras desempaquetarla, solo es necesario retirar los bloqueos de transporte, conectar los cables internos, insertar la placa de construcción flexible y ejecutar la auto-calibración para comenzar a imprimir.

---

## 2. Especificaciones técnicas

| Parámetro | Valor |
|---|---|
| **Tecnología de impresión** | FDM / FFF |
| **Cinemática** | CoreXY |
| **Volumen de impresión** | 220 × 220 × 250 mm |
| **Velocidad máxima** | 600 mm/s |
| **Velocidad recomendada** | 100 - 300 mm/s |
| **Aceleración máxima** | 20.000 mm/s² |
| **Flujo volumétrico máximo** | 32 mm³/s |
| **Altura de capa** | 0,1 - 0,35 mm |
| **Diámetro de boquilla** | 0,4 mm estándar (intercambiable: 0,6 / 0,8 mm) |
| **Tipo de boquilla** | Volcano (M6, 15 mm), acero endurecido |
| **Temperatura máxima del hotend** | 300 °C |
| **Temperatura máxima de la cama** | 100 °C |
| **Calentamiento del hotend** | 200 °C en 40 s |
| **Extrusor** | Direct drive de doble engranaje |
| **Fuerza de extrusión** | Hasta 80 N |
| **Diámetro de filamento** | 1,75 mm |
| **Firmware** | CrealityOS (basado en Klipper) |
| **Procesador** | CPU de doble núcleo a 1,2 GHz |
| **Almacenamiento** | 8 GB ROM (hasta 400 archivos de modelo) |
| **Pantalla** | Táctil a color de 4,3 pulgadas |
| **Conectividad** | Wi-Fi, USB, tarjeta TF, Creality Cloud |
| **Software de laminado** | Creality Print (también compatible con Cura, OrcaSlicer) |
| **Auto-nivelación** | Sensores de deformación (strain sensors) |
| **Input shaping** | Sí, compensación de resonancias |
| **Carriles lineales** | Metálicos en ejes X e Y |
| **Estructura** | Chasis soldado, completamente cerrada |
| **Placa de construcción** | Flexible PEI (dual texture: lisa + texturada) |
| **Recuperación de energía** | Sí (reanuda tras corte eléctrico) |
| **Sensor de filamento** | Sí (sensor de agotamiento) |
| **Cámara** | No (disponible en K1 Max) |
| **Lidar** | No (disponible en K1 Max) |
| **Fuente de alimentación** | 100-240 V CA, 50/60 Hz |
| **Potencia** | 350 W |
| **Dimensiones de la máquina** | 355 × 355 × 480 mm |
| **Peso neto** | 10,58 kg |
| **Materiales compatibles** | PLA, PETG, ABS, ASA, TPU, PA, PC, etc. |
| **Precio de referencia** | ~USD $299 - $399 |

---

## 3. Componentes y partes

### 3.1 Chasis soldado y carcasa cerrada

El chasis de la K1 está fabricado con perfiles de aluminio soldados en fábrica, lo que le confiere una rigidez estructural muy superior a la de las impresoras con chasis atornillados. Esta rigidez es fundamental para soportar las altas aceleraciones del sistema CoreXY sin que el chasis se deforme o vibre en exceso. La carcasa está completamente cerrada con paneles de acrílico tintado en los laterales, la parte superior y la trasera, y una puerta de vidrio con marco magnético en la parte frontal. Este diseño cerrado mantiene la temperatura interior estable, lo que es esencial para imprimir ABS y ASA sin warping, y también reduce la emisión de olores y la propagación de microplásticos en el aula.

La parte inferior de la máquina alberga la fuente de alimentación y la electrónica de control. Un panel de la base da acceso a estos componentes. La parte superior cuenta con una salida para ventilador de extracción donde se puede conectar un filtro de carbón activado o un conducto de ventilación hacia el exterior si se desea evacuar los VOC (compuestos orgánicos volátiles) generados durante la impresión con ciertos materiales.

### 3.2 Sistema de movimiento CoreXY

La cinemática CoreXY es la clave de la velocidad de la K1. En un sistema CoreXY, los dos motores de los ejes X e Y trabajan de forma conjunta y sincronizada mediante un sistema de correas cruzadas, de modo que el cabezal puede moverse en cualquier dirección del plano XY con la misma dinámica. Esto elimina la necesidad de mover una pesada cama en el eje Y (como ocurre en las impresoras de tipo cartesiano como la Ender-3), reduciendo drásticamente la masa en movimiento y permitiendo aceleraciones mucho mayores. Los carriles lineales metálicos (linear rails) en los ejes X e Y proporcionan movimientos suaves y precisos con mínima holgura, contribuyendo a la calidad de impresión a alta velocidad.

### 3.3 Extrusor directo de doble engranaje

El extrusor directo (direct drive) de la K1 monta dos engranajes de agarre que sujetan el filamento por ambos lados, proporcionando una fuerza de empuje de hasta 80 N. Esta configuración ofrece varias ventajas frente a los extrusores Bowden: permite imprimir filamentos flexibles (TPU) sin problemas, reduce la distancia entre el punto de agarre y el hotend (lo que significa menos retracción necesaria y menos stringing), y ofrece un control más preciso del flujo de material. El extrusor está montado directamente sobre el carro del eje X, lo que añade algo de masa en movimiento, pero la potencia de los motores y la cinemática CoreXY compensan este incremento de peso.

### 3.4 Hotend de alto flujo

El hotend de la K1 es un diseño propietario de tipo Volcano con las siguientes características:

- **Ruptura térmica de aleación de titanio:** El bloque de titanio tiene una baja conductividad térmica que aísla la zona fría del hotend de la zona caliente, previniendo atascos causados por el reblandecimiento prematuro del filamento.
- **Boquilla de acero endurecido:** Resistente a la abrasión, lo que es importante cuando se imprimen filamentos con cargas (carbono, fibra de vidrio, etc.). La rosca es de tamaño Volcano (M6, 15 mm de longitud), que ofrece una zona de fusión más larga que las boquillas estándar V6, permitiendo mayores tasas de flujo.
- **Temperatura máxima de 300 °C:** Suficiente para imprimir la mayoría de los filamentos técnicos, incluyendo nailon (PA), policarbonato (PC) y sus compuestos.
- **Calentamiento ultrarrápido:** Alcanza 200 °C en solo 40 segundos gracias al cartucho calefactor de alta potencia.

### 3.5 Cama calefactada y placa de construcción

La cama calefactada de la K1 alcanza los 100 °C y utiliza una placa de construcción flexible de PEI con doble textura: una cara lisa para piezas que requieren un acabado suave en la base, y una cara texturada para piezas que necesitan una adherencia extra o que prefieren un acabado estriado en la base. La flexibilidad de la placa permite retirar las piezas impresas simplemente doblando la superficie, sin necesidad de espátulas ni herramientas que podrían dañar la impresión o la superficie de la placa.

El sistema de auto-nivelación utiliza sensores de deformación (strain sensors) montados debajo de la placa de construcción. Cuando la boquilla toca la superficie en diferentes puntos durante la calibración, los sensores detectan la fuerza y calculan la compensación necesaria para que la primera capa se imprima con una distancia uniforme en toda la superficie.

### 3.6 Electrónica y procesador

La K1 incorpora una CPU de doble núcleo a 1,2 GHz que ejecuta CrealityOS (basado en Klipper). Este procesador de alto rendimiento permite:

- Calcular trayectorias de movimiento complejas a alta velocidad sin cuellos de botella.
- Ejecutar el algoritmo de input shaping que compensa las resonancias mecánicas de la impresora, eliminando artefactos como el ghosting (imágenes fantasma) y el ringing (anillos en las superficies verticales).
- Gestionar la conectividad Wi-Fi y la comunicación con Creality Cloud.
- Almacenar hasta 400 archivos de modelo en los 8 GB de memoria ROM interna.

La placa controladora principal gestiona los motores paso a paso, los sensores de temperatura, el sistema de auto-nivelación y los periféricos. Los controladores de motores son silenciosos (TMC), lo que contribuye al bajo nivel de ruido de la máquina.

### 3.7 Pantalla táctil de 4,3 pulgadas

La interfaz de usuario se maneja a través de una pantalla táctil a color de 4,3 pulgadas montada en la parte frontal superior de la máquina. Desde ella se pueden iniciar y detener impresiones, ajustar parámetros en tiempo real (velocidad, flujo, temperaturas), controlar manualmente los ejes, ejecutar la auto-calibración, gestionar los archivos almacenados en la memoria interna o en la tarjeta TF, y configurar la conexión Wi-Fi. La interfaz es intuitiva y responde con fluidez gracias al procesador de doble núcleo.

### 3.8 Sensores de seguridad y funciones inteligentes

- **Sensor de agotamiento de filamento:** Detecta cuando el filamento se ha terminado y pausa la impresión automáticamente, permitiendo insertar un nuevo carrete y reanudar sin perder la pieza.
- **Recuperación tras corte de energía:** Si la alimentación eléctrica se interrumpe durante una impresión, la máquina guarda la posición y reanuda automáticamente desde ese punto cuando se restaura la energía.
- **Sensores de deformación (strain sensors):** Permiten la auto-nivelación automática sin necesidad de sonda Z separada.
- **Input shaping:** Compensación automática de resonancias que se calibra al inicio de cada impresión o bajo demanda del usuario.

### 3.9 Accesorios incluidos de fábrica

- Placa de construcción flexible PEI (doble textura)
- Soporte de carrete de filamento con rodamientos
- Tarjeta TF con archivos de prueba
- Cable USB
- Cable de alimentación
- Juego de herramientas (llaves Allen, espátula, tijeras)
- Muestra de filamento PLA
- Guía de inicio rápido

---

## 4. Configuración y puesta en marcha

### 4.1 Desempaquetado e inspección

La K1 viene prácticamente ensamblada de fábrica en una caja de cartón reforzada con espuma de protección interna. Al desempaquetar las dos unidades del aula, etiquételas como **Unidad 1** y **Unidad 2** y siga estos pasos:

1. Retirar la impresora de la caja con la ayuda de dos personas (pesa 10,58 kg). Nunca levantar la máquina tirando del cable de la pantalla o de los carriles.
2. Colocar la impresora sobre una superficie plana y estable.
3. Retirar todos los bloqueos de transporte: tirantas de plástico, cintas adhesivas y espumas de fijación que inmovilizan el cabezal y los carriles durante el envío. Es importante no olvidar ninguna, ya que las tirantas de los carriles pueden causar fallos de movimiento si no se retiran.
4. Abrir la puerta frontal y verificar que el cable plano (ribbon cable) del extrusor está correctamente conectado al cabezal. En algunos envíos este cable puede haberse desconectado durante el transporte.
5. Verificar la presencia de todos los accesorios listados en la sección 3.9.
6. Inspeccionar visualmente el hotend y la boquilla para confirmar que no hay residuos de filamento de fábrica ni daños visibles.
7. Registrar el número de serie de cada unidad en el inventario del aula.

### 4.2 Conexión de componentes internos

Antes de encender la máquina por primera vez, es necesario realizar unas conexiones mínimas:

1. **Cable del extrusor y el hotend:** Verificar que el cable plano que conecta el extrusor/hotend con la placa controladora está firmemente insertado en ambos extremos. Este cable transporte las señales de los termistores, la alimentación del cartucho calefactor y el control del motor del extrusor.
2. **Cable del sensor de filamento:** Confirmar que el sensor óptico de agotamiento de filamento está conectado.
3. **Soporte de carrete:** Ensamblar el soporte del carrete de filamento en la parte superior o posterior de la máquina según las instrucciones de la guía de inicio rápido.

### 4.3 Ubicación en el aula

Al seleccionar la ubicación de las dos unidades K1 en el aula STEAM, considere lo siguiente:

- **Superficie estable:** La máquina genera fuerzas de aceleración significativas (20.000 mm/s²). Una mesa inestable amplificará las vibraciones y puede afectar la calidad de impresión. Mesas de trabajo pesadas o bancos de laboratorio son ideales.
- **Ventilación:** Aunque la carcasa cerrada contiene la mayoría de las emisiones, la impresión con ABS y otros materiales genera VOC y olores. Ubicar las impresoras en una zona bien ventilada o cerca de una ventana. Si es posible, instalar un filtro de carbón activado en la salida superior.
- **Espacio de acceso:** Dejar al menos 15 cm de espacio libre alrededor de la máquina para la ventilación y el acceso a los puertos traseros (alimentación, USB, tarjeta TF). La puerta frontal necesita espacio para abrirse completamente.
- **Proximidad a la red eléctrica:** Cada unidad consume hasta 350 W. Conectar cada máquina a un tomacorriente independiente o a una regleta con protección contra sobrecargas. No conectar ambas máquinas al mismo enchufe si hay otros equipos de alto consumo en el mismo circuito.
- **Red Wi-Fi:** La K1 necesita conexión Wi-Fi para enviar trabajos de impresión desde Creality Print y para acceder a Creality Cloud. Verificar que la señal Wi-Fi llega con suficiente intensidad a la ubicación elegida.

### 4.4 Primera puesta en marcha

1. Insertar la placa de construcción flexible PEI sobre la cama calefactada, asegurándose de que las pestañas magnéticas la sujetan firmemente.
2. Conectar el cable de alimentación y encender la máquina con el interruptor trasero.
3. La pantalla táctil se iluminará y mostrará el asistente de configuración inicial de CrealityOS.
4. Seleccionar el idioma (español, si está disponible; en caso contrario, inglés).
5. Conectar la impresora a la red Wi-Fi del aula siguiendo las instrucciones en pantalla. Se necesitará la contraseña de la red.
6. La máquina ejecutará automáticamente la auto-calibración: los sensores de deformación medirán la planitud de la cama en múltiples puntos y ajustarán la malla de compensación.
7. Una vez completada la calibración, la máquina está lista para imprimir.

### 4.5 Instalación de Creality Print

Creality Print es el software de laminado oficial optimizado para la K1, con perfiles preconfigurados que aprovechan el input shaping y las capacidades de alta velocidad:

1. Descargar Creality Print desde [https://www.creality.com/pages/download-software](https://www.creality.com/pages/download-software) o desde la página de Creality Cloud.
2. Instalar el software en el computador del aula (disponible para Windows, macOS y Linux).
3. Al abrir Creality Print por primera vez, seleccionar la impresora "Creality K1" de la lista de modelos. El software cargará automáticamente los perfiles de impresión optimizados.
4. Conectar la impresora a través de la red Wi-Fi: Creality Print detectará las unidades K1 en la red local y permitirá enviar archivos directamente a la memoria de la impresora.
5. Si se prefiere usar Cura u OrcaSlicer, es posible importar perfiles personalizados para la K1. Sin embargo, Creality Print ofrece la mejor integración con CrealityOS y el envío directo por Wi-Fi.

### 4.6 Primera impresión de prueba

1. Cargar el carrete de filamento PLA incluido en el soporte superior.
2. Insertar el extremo del filamento en el sensor de agotamiento y luego en la entrada del extrusor, empujando hasta que el motor lo agarre.
3. Desde la pantalla táctil, seleccionar *Preheat* (Precalentar) y elegir PLA (hotend 200 °C, cama 60 °C).
4. Una vez alcanzadas las temperaturas, extruir manualmente un poco de filamento para verificar que fluye correctamente por la boquilla.
5. Seleccionar un archivo de prueba preinstalado en la memoria interna (generalmente un cubo de calibración o un pequeño modelo de prueba) e iniciar la impresión.
6. Observar la primera capa: debe estar uniformemente adherida a la placa PEI sin espacios ni arrugas. Si la primera capa no se adhiere bien, ejecutar la auto-calibración nuevamente o ajustar el offset Z manualmente desde la pantalla.

---

## 5. Guía de uso paso a paso

### 5.1 Diseño o selección del modelo 3D

Al igual que con cualquier impresora FDM, el proceso comienza con un modelo 3D. Puede diseñarse en cualquier software de modelado (Tinkercad, Fusion 360, Blender, SolidWorks) o descargarse de repositorios como Creality Cloud, Thingiverse, Printables o MyMiniFactory. Exportar el modelo en formato .STL o .3MF.

Al diseñar para la K1, se pueden aprovechar sus capacidades de alta velocidad: los modelos con paredes de grosor estándar (1,2-2,0 mm) y geometrías que no requieran gran cantidad de retracciones se imprimirán mucho más rápido que los modelos con detalles minúsculos o volumes de relleno complejos. Para prototipos rápidos, se pueden usar alturas de capa de 0,2-0,3 mm con velocidades de 200-300 mm/s; para piezas finales de alta calidad, se recomiendan alturas de capa de 0,1-0,16 mm con velocidades de 80-150 mm/s.

### 5.2 Laminado con Creality Print

1. Abrir Creality Print y cargar el archivo .STL o .3MF.
2. Posicionar el modelo en la plataforma virtual. Aprovechar el volumen de construcción de 220 × 220 × 250 mm.
3. Seleccionar el perfil de impresión adecuado:

| Perfil | Velocidad | Altura de capa | Uso |
|---|---|---|---|
| Draft (Borrador) | 300-500 mm/s | 0,28-0,35 mm | Prototipos rápidos, verificación de forma |
| Standard (Estándar) | 150-250 mm/s | 0,2 mm | Piezas funcionales de uso general |
| Fine (Fino) | 80-120 mm/s | 0,12-0,16 mm | Piezas de presentación, detalles finos |

4. Configurar los parámetros según el material:

| Parámetro | PLA | PETG | ABS | TPU |
|---|---|---|---|---|
| Temp. hotend | 200-220 °C | 230-250 °C | 240-260 °C | 210-230 °C |
| Temp. cama | 55-65 °C | 70-80 °C | 90-100 °C | 40-50 °C |
| Vel. impresión | 150-300 mm/s | 100-200 mm/s | 100-200 mm/s | 30-60 mm/s |
| Vel. primera capa | 30-50 mm/s | 30-50 mm/s | 20-40 mm/s | 15-25 mm/s |
| Ventilador parte | 100% | 50-80% | 0-30% | 50-100% |
| Retracción | 0,4-0,8 mm | 0,6-1,0 mm | 0,6-1,0 mm | 0,4-0,6 mm |
| Flujo | 95-100% | 95-100% | 95-100% | 100-105% |

5. Habilitar el soporte (*supports*) si el modelo tiene ángulos de sobrehang superiores a 45°.
6. Seleccionar el relleno (*infill*): 10-15% para piezas decorativas, 20-30% para piezas funcionales, 50%+ para piezas sometidas a carga mecánica.
7. Hacer clic en *Slice* (Laminar) y verificar la vista previa.
8. Enviar el archivo a la impresora por Wi-Fi o guardarlo en la tarjeta TF.

### 5.3 Preparación de la impresora

1. Verificar que la placa PEI está limpia (sin residuos de aceite, polvo o adhesivo). Limpiar con alcohol isopropílico si es necesario.
2. Cargar el filamento en el extrusor, asegurándose de que el extremo esté cortado en ángulo y de que no haya curvas o nudos en el carrete que puedan causar atascos.
3. Desde la pantalla táctil, seleccionar el perfil de temperatura correspondiente al material.
4. Ejecutar la auto-calibración si no se ha realizado recientemente (recomendado al inicio de cada sesión o al cambiar de material).

### 5.4 Durante la impresión

1. Iniciar la impresión desde la pantalla táctil o desde Creality Print.
2. Observar la primera capa completa antes de alejarse. La primera capa es crítica: si no se adhiere correctamente, cancelar la impresión y ajustar el offset Z o limpiar la placa.
3. Desde la pantalla táctil o desde Creality Print, se pueden hacer ajustes en tiempo real: velocidad, flujo, temperaturas del hotend y la cama, y ventilador de la parte.
4. Si se imprime con ABS, mantener la puerta cerrada para conservar el calor en el interior de la carcasa y minimizar las corrientes de aire que causan warping.
5. Si se imprime con PLA, se puede abrir ligeramente la puerta frontal o la tapa superior para mejorar la ventilación y evitar que las capas superiores se reblandezcan por el calor acumulado.

### 5.5 Retirada de la pieza

1. Esperar a que la cama se enfríe por debajo de 40 °C antes de retirar la pieza. El PEI libera las piezas con mucha más facilidad cuando está frío.
2. Retirar la placa flexible PEI de la cama (levantando por las esquinas).
3. Doblar la placa suavemente para liberar la pieza. No usar fuerza excesiva ni herramientas metálicas que puedan dañar la superficie del PEI.
4. Si la pieza resiste, usar una espátula de plástico para ayudar a despegarla por los bordes.

### 5.6 Uso simultáneo de las dos unidades

Con dos K1 en el aula, se pueden implementar las siguientes estrategias:

- **Impresión paralela:** Ambas unidades pueden imprimir simultáneamente, duplicando la producción. Cada unidad se conecta a la red Wi-Fi y puede recibir archivos independientemente desde Creality Print.
- **Especialización por material:** Asignar cada unidad a un tipo de filamento específico (por ejemplo, Unidad 1 para PLA y TPU, Unidad 2 para ABS y PETG) para evitar la necesidad de purgar el hotend y cambiar parámetros con frecuencia.
- **Modo borrador + modo fino:** Usar la Unidad 1 con perfil Draft para prototipos rápidos y la Unidad 2 con perfil Fine para piezas de presentación, maximizando la eficiencia del flujo de trabajo.
- **Turnos de uso:** Si hay más de dos estudiantes que necesitan imprimir, establecer un sistema de reservas con tiempos definidos.

---

## 6. Mantenimiento básico

### 6.1 Limpieza de la placa PEI

La superficie PEI es uno de los componentes que más se desgasta y contamina con el uso. Una placa sucia es la causa más común de fallos de adherencia de la primera capa:

1. Después de cada impresión, limpiar la placa con un paño limpio para eliminar residuos.
2. Periódicamente (cada 5-10 impresiones), limpiar la placa con alcohol isopropílico al 90%+ para eliminar los aceites residuales del filamento y los dedos.
3. Si la adherencia disminuye significativamente, lavar la placa con agua tibia y jabón de platos, secarla completamente y luego aplicar alcohol isopropílico.
4. Si la superficie se daña o desgasta excesivamente, puede lijarse ligeramente con lija de grano 400-600 y luego limpiar con alcohol. Como último recurso, reemplazar la placa.

### 6.2 Limpieza y mantenimiento del hotend

1. **Limpieza de la boquilla:** Después de imprimir con materiales de alta temperatura (ABS, PETG) que pueden dejar residuos carbonizados, limpiar la boquilla con un cepillo de alambre de latón mientras está caliente (a temperatura de impresión). Tener cuidado de no quemarse.
2. **Purga de cambio de material:** Al cambiar de un material a otro (especialmente de un color oscuro a uno claro o de un material de alta temperatura a uno de baja), extruir suficiente filamento nuevo hasta que el material que sale por la boquilla sea completamente limpio y uniforme.
3. **Cold pull (extracción en frío):** Si se sospecha de una obstrucción parcial del hotend, realizar un cold pull: calentar el hotend a 200 °C, insertar filamento manualmente, apagar el calentador y dejar enfriar a 90 °C (para PLA), luego tirar firmemente del filamento para extraer los residuos acumulados en el interior del hotend.

### 6.3 Limpieza del extrusor

1. Inspeccionar periódicamente los engranajes del extrusor para verificar que no haya residuos de filamento acumulados entre los dientes. Los engranajes sucios reducen la fuerza de agarre y causan sub-extrusión.
2. Limpiar los engranajes con un cepillo pequeño y, si es necesario, una aguja para retirar los restos de filamento incrustados.
3. Verificar la tensión del resorte del extrusor: debe ofrecer una presión firme pero no excesiva. Si el filamento se aplasta demasiado o se desliza, ajustar el tornillo de tensión.

### 6.4 Lubricación de carriles lineales

Los carriles lineales de los ejes X e Y son componentes de precisión que requieren lubricación periódica:

1. Usar grasa de litio o aceite ligero para cojinetes lineales. No usar WD-40.
2. Aplicar una pequeña cantidad en los carriles y mover el cabezal a lo largo de todo el recorrido varias veces para distribuir el lubricante.
3. Limpiar el exceso con un paño limpio.
4. Frecuencia: cada 100 horas de impresión o cada 4 semanas de uso regular.

### 6.5 Verificación y ajuste de correas

Las correas del sistema CoreXY deben mantener una tensión adecuada para garantizar la precisión de los movimientos:

1. Verificar que las correas no estén flojas (se pueden hundir más de 5-10 mm al presionar con un dedo) ni excesivamente tensas (producen un sonido agudo al pulsarlas).
2. Si las correas están flojas, ajustar los tensores correspondientes (generalmente accesibles sin desmontar la carcasa).
3. Inspeccionar visualmente las correas para detectar desgaste, dientes saltados o fisuras.
4. Frecuencia: mensualmente o cada 200 horas de impresión.

### 6.6 Actualización de firmware

CrealityOS recibe actualizaciones periódicas que corrigen errores y mejoran la funcionalidad:

1. Desde la pantalla táctil, acceder a *Settings > Firmware Update* para verificar si hay actualizaciones disponibles.
2. También se pueden descargar las actualizaciones desde [https://github.com/CrealityOfficial/K1_Series_Klipper/releases](https://github.com/CrealityOfficial/K1_Series_Klipper/releases) y cargarlas mediante tarjeta TF.
3. Antes de actualizar, asegurarse de que la impresora no está imprimiendo y de que la conexión eléctrica es estable.
4. No apagar la máquina durante la actualización.

> **Precaución:** Si se ha realizado el *rooting* de la impresora (acceso de administrador al sistema operativo), el proceso de actualización puede ser diferente y requerir pasos adicionales. Consultar la documentación de la comunidad antes de actualizar una máquina rooteada.

### 6.7 Programa de mantenimiento preventivo

| Tarea | Frecuencia |
|---|---|
| Limpieza de la placa PEI con alcohol | Cada 5-10 impresiones |
| Limpieza de la boquilla con cepillo de latón | Después de cada sesión |
| Inspección del extrusor y engranajes | Semanalmente |
| Cold pull del hotend | Cada cambio de material o mensualmente |
| Lubricación de carriles lineales | Cada 100 horas / 4 semanas |
| Verificación de tensión de correas | Mensualmente / 200 horas |
| Limpieza general del interior | Mensualmente |
| Actualización de firmware | Según disponibilidad |
| Inspección de cables y conexiones | Mensualmente |
| Verificación de tornillos del chasis | Trimestralmente |

---

## 7. Solución de problemas comunes

### 7.1 La primera capa no se adhiere

**Causas posibles:**
- Placa PEI sucia (aceite, polvo, residuos de adhesivo).
- Offset Z incorrecto (la boquilla está demasiado alta o demasiado baja).
- Cama no calibrada o malla de compensación desactualizada.
- Temperatura de la cama demasiado baja para el material.
- Primera capa impresa a velocidad excesiva.

**Soluciones:**
- Limpiar la placa PEI con alcohol isopropílico al 90%+.
- Ajustar el offset Z: si la primera capa está redondeada y no se aplana, la boquilla está demasiado alta (reducir el offset Z); si la primera capa es transparente y se rasga, la boquilla está demasiado baja (aumentar el offset Z).
- Ejecutar la auto-calibración desde la pantalla táctil.
- Aumentar la temperatura de la cama en 5-10 °C.
- Reducir la velocidad de la primera capa a 30-50 mm/s.

### 7.2 Sub-extrusión (la pieza tiene huecos o paredes incompletas)

**Causas posibles:**
- Filamento atascado o enrollado en el carrete.
- Engranajes del extrusor sucios o con tensión insuficiente.
- Hotend parcialmente obstruido.
- Diámetro del filamento irregular.
- Temperatura del hotend demasiado baja.
- Velocidad de impresión demasiado alta para el flujo volumétrico del hotend.

**Soluciones:**
- Verificar que el filamento se desliza libremente del carrete al extrusor.
- Limpiar los engranajes del extrusor y ajustar la tensión del resorte.
- Realizar un cold pull para limpiar el hotend.
- Medir el diámetro del filamento con un calibrador y ajustar el flujo si es necesario.
- Aumentar la temperatura del hotend en 5-10 °C.
- Reducir la velocidad de impresión; a velocidades superiores a 200 mm/s con una boquilla de 0,4 mm, el flujo volumétrico puede ser el factor limitante (máximo ~32 mm³/s).

### 7.3 Warping (deformación de la base de la pieza)

**Causas posibles:**
- Pieza grande con gran área de contacto con la cama, impresa en ABS/ASA sin suficiente adhesión.
- Corrientes de aire dentro de la carcasa (puerta abierta).
- Temperatura de la cama demasiado baja.
- Pieza impresa sin brim (borde) o raft (balsa).

**Soluciones:**
- Mantener la puerta cerrada al imprimir ABS/ASA para conservar el calor en el interior.
- Aumentar la temperatura de la cama al máximo (100 °C para ABS).
- Añadir un brim de 5-10 mm en el software de laminado para aumentar el área de contacto.
- Aplicar una capa fina de adhesivo para impresión 3D (glue stick, hairspray, o Magigoo) sobre la placa PEI.
- Para piezas muy grandes o problemáticas, considerar el uso de una balsa (raft).

### 7.4 Stringing (hilos de filamento entre superficies)

**Causas posibles:**
- Retracción insuficiente (distancia o velocidad).
- Temperatura del hotend demasiado alta.
- Filamento húmedo.

**Soluciones:**
- Aumentar la distancia de retracción en 0,2-0,4 mm (valores típicos: 0,4-1,0 mm para extrusor directo).
- Aumentar la velocidad de retracción.
- Reducir la temperatura del hotend en 5-10 °C.
- Secar el filamento (especialmente PETG y nailon) en un horno a 50-60 °C durante 4-6 horas o usar un secador de filamento.

### 7.5 Ghosting / ringing (imágenes fantasma en las superficies verticales)

**Causas posibles:**
- Input shaping no calibrado o desactivado.
- Velocidad de impresión excesiva para la rigidez del chasis.
- Correas flojas.
- Superficie de apoyo inestable (mesa que vibra).

**Soluciones:**
- Ejecutar la calibración del input shaping desde la pantalla táctil o desde Creality Print. El input shaping mide las frecuencias de resonancia de la impresora y genera un filtro compensatorio.
- Reducir la velocidad de impresión, especialmente en las aceleraciones.
- Verificar y ajustar la tensión de las correas del CoreXY.
- Colocar la impresora sobre una superficie pesada y estable. Se puede añadir una almohadilla antivibración bajo los pies de la máquina.

### 7.6 Atasco del extrusor / hotend obstruido

**Causas posibles:**
- Filamento reblandecido antes de la zona de fusión (heat creep).
- Residuos carbonizados en el interior del hotend.
- Filamento de diámetro excesivo o deformado.
- Polvo o contaminación en el filamento.

**Soluciones:**
- Realizar un cold pull (sección 6.2) para extraer los residuos.
- Si el cold pull no resuelve el problema, desmontar el hotend y limpiar los componentes internos con acetona (para residuos de ABS) o con una aguja de limpieza.
- Verificar que el ventilador del disipador del hotend funciona correctamente (el ventilador lateral debe estar siempre encendido durante la impresión para evitar el heat creep).
- Pasar el filamento por un paño ligeramente húmedo antes de cargarlo para eliminar el polvo.

### 7.7 La impresión no comienza o se detiene inesperadamente

**Causas posibles:**
- Archivo G-code corrupto o con instrucciones incompatibles.
- Firmware desactualizado.
- Conexión Wi-Fi inestable (si se imprime por red).
- Tarjeta TF defectuosa.
- Sensor de filamento activado y filamento agotado.

**Soluciones:**
- Re-laminar el modelo y generar un nuevo archivo G-code.
- Actualizar el firmware a la última versión estable.
- Si se imprimía por Wi-Fi, intentar usando tarjeta TF o USB.
- Formatear la tarjeta TF o usar una nueva.
- Verificar que el sensor de filamento no esté activado por error (puede desactivarse desde la pantalla táctil).

### 7.8 Problemas con la conexión Wi-Fi o Creality Cloud

**Causas posibles:**
- Contraseña de Wi-Fi incorrecta o cambiada.
- La impresora está fuera del alcance del router.
- El firmware de la impresora no es compatible con la versión actual de Creality Cloud.

**Soluciones:**
- Volver a configurar la conexión Wi-Fi desde la pantalla táctil (Settings > Network).
- Acercar la impresora al router o instalar un repetidor Wi-Fi.
- Actualizar el firmware de la impresora y la aplicación Creality Print a la última versión.
- Como alternativa, usar tarjeta TF para transferir archivos sin depender de la red Wi-Fi.

---

## 8. Materiales, repuestos y accesorios

### 8.1 Materiales de impresión compatibles

| Material | Temp. hotend | Temp. cama | Dificultad | Observaciones |
|---|---|---|---|---|
| **PLA** | 200-220 °C | 55-65 °C | Fácil | Material de referencia, ideal para principiantes. Biodegradable. |
| **PLA+ / PLA Pro** | 210-230 °C | 55-65 °C | Fácil | Mayor resistencia que el PLA estándar. |
| **PETG** | 230-250 °C | 70-80 °C | Media | Buena resistencia química y térmica. Propenso a stringing. |
| **ABS** | 240-260 °C | 90-100 °C | Difícil | Requiere carcasa cerrada. Emite VOC. Excelente resistencia mecánica y térmica. |
| **ASA** | 240-260 °C | 90-100 °C | Difícil | Similar al ABS pero con resistencia UV. Ideal para piezas de exterior. |
| **TPU (95A)** | 210-230 °C | 40-50 °C | Media | Filamento flexible. Velocidad reducida (30-60 mm/s). El extrusor directo lo maneja bien. |
| **PA (Nailon)** | 250-270 °C | 80-100 °C | Difícil | Muy resistente y flexible. Extremadamente higroscópico: requiere secado previo. |
| **PC (Policarbonato)** | 270-300 °C | 90-100 °C | Muy difícil | Máxima resistencia al impacto y térmica. Requiere carcasa cerrada y temperaturas altas. |
| **Filamentos compuestos** | Variable | Variable | Variable | Carbono, fibra de vidrio, madera, metal. Usar boquilla de acero endurecido o nozzle X. |

### 8.2 Almacenamiento de filamentos

Los filamentos, especialmente el PLA, PETG y el nailon, absorben humedad del ambiente, lo que causa problemas de impresión (pops, stringing, superficies rugosas, sub-extrusión). En el clima húmedo de muchas regiones colombianas, el almacenamiento adecuado es esencial:

- Guardar los carretes en bolsas herméticas con bolsas de gel de sílice (sílice gel).
- Para filamentos muy higroscópicos (nailon, PETG), usar un secador de filamento o un horno a baja temperatura (50-60 °C) durante 4-6 horas antes de imprimir.
- Etiquetar cada carrete con la fecha de apertura y el tipo de material.
- No dejar carretes expuestos al aire más de 24-48 horas sin protección.

### 8.3 Boquillas de repuesto

La K1 utiliza boquillas de tipo Volcano (rosca M6, longitud 15 mm). Las boquillas estándar de la K1 son de acero endurecido, pero existen opciones de repuesto y upgrade:

| Tipo de boquilla | Características | Precio aprox. |
|---|---|---|
| Acero endurecido (stock) | Resistente a la abrasión, incluida con la impresora | USD $5-10 |
| Latón | Excelente conductividad térmica, baja durabilidad con filamentos abrasivos | USD $3-5 |
| Acero inoxidable | Resistente a la abrasión, para filamentos con cargas | USD $8-15 |
| Ruby (rubí) | Máxima durabilidad, punta de rubí, para uso intensivo | USD $30-50 |
| Nozzle X (E3D) | Recubrimiento ultra resistente, compatible Volcano | USD $25-35 |

Diámetros disponibles: 0,4 mm (estándar), 0,6 mm (impresión rápida), 0,8 mm (muy rápido, menor detalle).

### 8.4 Otros repuestos y consumibles

- **Placa PEI flexible de repuesto:** La superficie PEI se desgasta con el uso y eventualmente necesita reemplazo.
- **Correas GT2 de repuesto:** Para el sistema CoreXY.
- **Tarjetas TF:** De clase 10, capacidad de 8-32 GB.
- **Cable plano del extrusor:** Componente delicado que puede dañarse con manipulación incorrecta.
- **Cartucho calefactor del hotend:** 24 V, para reemplazo en caso de fallo.
- **Termistor del hotend:** Sensor de temperatura de repuesto.
- **Filtro de carbón activado:** Para instalar en la salida superior de la carcasa.

### 8.5 Accesorios complementarios recomendados para el aula

- **Secador de filamento:** Para prevenir y corregir la absorción de humedad.
- **Filtro de carbón activado para la K1:** Se acopla a la salida superior de la carcasa para filtrar VOC.
- **Cámara externa USB:** Dado que la K1 base no incluye cámara, se puede instalar una cámara USB para monitorear las impresiones de forma remota.
- **Adhesivo para impresión 3D:** Magigoo, glue stick o laca para casos de adherencia difícil.
- **Calibrador digital:** Para medir el diámetro del filamento y las dimensiones de las piezas impresas.
- **Juego de llaves Allen y torx:** Para el mantenimiento de la máquina.
- **Cepillo de alambre de latón:** Para la limpieza de la boquilla.

---

## 9. Normas de uso STEAM

### 9.1 Normas generales de seguridad

La Creality K1 es una máquina que opera con temperaturas elevadas (hasta 300 °C en el hotend y 100 °C en la cama) y movimientos mecánicos rápidos. Las siguientes normas de seguridad son de cumplimiento obligatorio en el aula:

- **Piezas calientes:** Nunca tocar la boquilla, el bloque calefactor, el disipador del hotend o la cama calefactada mientras están a temperatura de impresión o en proceso de enfriamiento. Esperar al menos 10 minutos después de que la impresora indique que se ha enfriado antes de manipular estos componentes.
- **Mecanismos de movimiento:** El cabezal de la K1 puede moverse a velocidades de hasta 600 mm/s con aceleraciones de 20.000 mm/s². No introducir las manos en el área de impresión durante la operación. Recoger el cabello largo y evitar ropa suelta, mangas anchas o joyas colgantes.
- **Carcasa cerrada:** Mantener la puerta cerrada durante la impresión, especialmente con ABS y ASA, para contener las emisiones y evitar contactos accidentales con las partes calientes.
- **Emisiones y ventilación:** La impresión con ABS, ASA y otros materiales emite VOC y partículas ultrafinas (UFP). Asegurar una ventilación adecuada del aula y considerar el uso de filtros de carbón activado. Si se imprimen grandes volúmenes de ABS, abrir las ventanas del aula o usar un sistema de extracción.
- **Electricidad:** La K1 funciona con 350 W a 24 V CC (desde el adaptador integrado). No desmontar la carcasa de la fuente de alimentación. Desconectar la máquina antes de realizar cualquier mantenimiento interno.
- **Supervisión:** Aunque la K1 puede operar sin supervisión constante gracias al sensor de agotamiento de filamento y la recuperación tras corte de energía, se recomienda que un estudiante o el coordinador esté presente o monitoree la impresión a través de Creality Cloud o una cámara USB.

### 9.2 Protocolo de uso por sesiones

1. **Reserva:** Cada estudiante o grupo debe reservar un bloque de tiempo con una de las unidades K1. Indicar la unidad (1 o 2), el material a utilizar y el tiempo estimado de impresión.
2. **Preparación previa:** Antes de la sesión, el estudiante debe tener listo su archivo G-code enviado a la impresora (por Wi-Fi o tarjeta TF) y el carrete de filamento preparado.
3. **Chequeo inicial:** Verificar la limpieza de la placa PEI, el estado del filamento (sin nudos, sin humedad visible) y la conexión Wi-Fi. Ejecutar la auto-calibración si no se ha hecho recientemente.
4. **Impresión:** Iniciar la impresión y observar al menos la primera capa completa. Realizar ajustes si es necesario.
5. **Monitoreo:** Comprobar periódicamente el progreso de la impresión (cada 15-30 minutos para impresiones largas).
6. **Retirada y limpieza:** Al finalizar, retirar la pieza con la cama fría, limpiar la placa PEI con alcohol y limpiar la boquilla si quedan residuos.
7. **Registro:** Anotar en el registro del aula: fecha, estudiante, unidad utilizada, material, tiempo de impresión, resultado (éxito/fracaso) y observaciones.

### 9.3 Integración curricular STEAM

La Creality K1 es una herramienta excepcional para la educación STEAM gracias a su velocidad (que reduce los tiempos de espera y permite más iteraciones de diseño), su versatilidad de materiales y su conectividad:

**Ciencia (Science):**
- Estudio de las propiedades mecánicas y térmicas de los materiales poliméricos (PLA, PETG, ABS, TPU): resistencia a la tracción, temperatura de transición vítrea, degradación térmica.
- Análisis de la dinámica de fluidos del filamento fundido: flujo volumétrico, viscosidad, efecto de la temperatura en la fluidez.
- Experimentación con la contracción térmica de diferentes materiales y su efecto en la precisión dimensional de las piezas.

**Tecnología (Technology):**
- Comprensión de la cinemática CoreXY frente a la cartesiana: ventajas y desventajas de cada sistema.
- Exploración del firmware Klipper y sus funciones avanzadas: input shaping, pressure advance, control de temperatura PID.
- Uso de Creality Cloud y el ecosistema de software para la gestión remota de impresoras.
- Programación de macros de Klipper para automatizar tareas de calibración y mantenimiento.

**Ingeniería (Engineering):**
- Diseño paramétrico de piezas optimizadas para impresión FDM (orientación, grosor de paredes, ángulos de sobrehang).
- Metodología de diseño iterativo: imprimir prototipos rápidos (perfil Draft a 300 mm/s), evaluar, rediseñar y reimprimir en perfil Fine.
- Análisis de fallos: estudio de los modos de fallo comunes (warping, delaminación, sub-extrusión) y sus causas raíz.
- Ingeniería inversa: escanear un objeto físico, procesar la malla y reimprimir una réplica.

**Arte (Art):**
- Creación de esculturas, joyería y objetos decorativos combinando técnicas digitales y analógicas.
- Experimentación con filamentos de colores, gradientes y materiales especiales (madera, metal, cambio de color con temperatura).
- Diseño de piezas con patrones generativos y algorítmicos usando software como Grasshopper o Processing.

**Matemáticas (Mathematics):**
- Cálculo de tiempos de impresión estimados en función de la velocidad, la altura de capa y el volumen de la pieza.
- Geometría de las trayectorias de la herramienta: perímetros, rellenos y su relación con la resistencia mecánica.
- Análisis estadístico de la precisión dimensional: medir piezas impresas y comparar con las dimensiones nominales del modelo digital.
- Modelado de la compensación de input shaping: frecuencias de resonancia y filtros digitales.

### 9.4 Proyectos STEAM sugeridos

1. **Prototipado rápido de soluciones:** Identificar un problema real en el aula o la universidad, diseñar una solución, imprimir un prototipo en perfil Draft (15 min), evaluar, rediseñar y reimprimir en perfil Standard o Fine. La velocidad de la K1 permite completar 3-4 iteraciones en una sola sesión de clase.
2. **Puente de filamento:** Diseñar e imprimir puentes de diferentes geometrías usando varios materiales, y someterlos a pruebas de carga para determinar la relación entre diseño, material y resistencia.
3. **Engranajes y mecanismos:** Diseñar sistemas de engranajes, levas y eslabones que funcionen correctamente tras la impresión. Ajustar las tolerancias en el diseño digital para compensar la expansión del filamento.
4. **Piezas de recambio para el aula:** Diseñar e imprimir soportes, organizadores, carcasas de protección y otros accesorios funcionales para los equipos del aula STEAM.
5. **Topología optimizada:** Usar software de diseño generativo (Fusion 360 Generative Design) para crear piezas con la máxima resistencia y el mínimo material, e imprimirlas en PETG o ABS para evaluar su rendimiento.
6. **Vaselina de materiales:** Imprimir el mismo modelo en PLA, PETG, ABS y TPU, y comparar las propiedades mecánicas, la calidad superficial y la precisión dimensional de cada material.

### 9.5 Normas de convivencia y trabajo en equipo

- Respetar los turnos de uso y los tiempos asignados. La K1 es rápida, pero una impresión de gran volumen aún puede tardar varias horas.
- No cancelar la impresión de otro estudiante sin su autorización.
- Compartir los perfiles de impresión optimizados y los hallazgos sobre parámetros con el resto del grupo.
- Limpiar la máquina después de cada uso: placa PEI, boquilla y zona alrededor del extrusor.
- Reportar inmediatamente cualquier fallo, ruido anormal o daño a la máquina. No intentar reparaciones complejas sin supervisión del coordinador.
- Mantener los carretes de filamento almacenados correctamente en bolsas herméticas con gel de sílice después de cada uso.
- Documentar los proyectos (fotografías del proceso y resultado, notas de parámetros) para la base de conocimiento del aula.

---

## 10. Enlaces y recursos adicionales

### 10.1 Sitios oficiales

- **Creality Official - K1:** [https://www.creality.com/products/creality-k1-3d-printer](https://www.creality.com/products/creality-k1-3d-printer)
- **Creality Store - K1:** [https://store.creality.com/products/k1-3d-printer](https://store.creality.com/products/k1-3d-printer)
- **Creality Wiki - K1 Series:** [https://wiki.creality.com/en/k1-flagship-series](https://wiki.creality.com/en/k1-flagship-series)
- **Creality Cloud:** [https://www.crealitycloud.com/](https://www.crealitycloud.com/)

### 10.2 Software

- **Creality Print (laminado oficial):** [https://www.creality.com/pages/download-software](https://www.creality.com/pages/download-software)
- **Ultimaker Cura:** [https://ultimaker.com/software/ultimaker-cura](https://ultimaker.com/software/ultimaker-cura)
- **OrcaSlicer:** [https://github.com/SoftFever/OrcaSlicer](https://github.com/SoftFever/OrcaSlicer)
- **PrusaSlicer:** [https://www.prusa3d.com/prusaslicer/](https://www.prusa3d.com/prusaslicer/)
- **Tinkercad:** [https://www.tinkercad.com/](https://www.tinkercad.com/)
- **Fusion 360:** [https://www.autodesk.com/products/fusion-360/](https://www.autodesk.com/products/fusion-360/)
- **Blender:** [https://www.blender.org/](https://www.blender.org/)

### 10.3 Firmware y recursos técnicos

- **GitHub - Creality K1 Series Klipper:** [https://github.com/CrealityOfficial/K1_Series_Klipper/releases](https://github.com/CrealityOfficial/K1_Series_Klipper/releases)
- **Klipper Firmware (documentación oficial):** [https://www.klipper3d.org/](https://www.klipper3d.org/)
- **Creality Community Forum:** [https://forum.creality.com/](https://forum.creality.com/)

### 10.4 Guías de solución de problemas

- **Creality Cloud - K1 Troubleshooting Guide:** [https://www.crealitycloud.com/blog/3d-printing-troubleshooting/creality-k1-troubleshooting](https://www.crealitycloud.com/blog/3d-printing-troubleshooting/creality-k1-troubleshooting)
- **Creality Wiki - Print Quality:** [https://wiki.creality.com/en/k1-flagship-series/k1-max/print-quality-3d-models](https://wiki.creality.com/en/k1-flagship-series/k1-max/print-quality-3d-models)

### 10.5 Revisiones y comparaciones

- **3D Print Beginner - Creality K1 Review:** [https://3dprintbeginner.com/creality-k1-review-corexy-for-tinkerers](https://3dprintbeginner.com/creality-k1-review-corexy-for-tinkerers)
- **All3DP - K1 vs K1 Max vs K1C:** [https://all3dp.com/2/creality-k1-vs-k1c-vs-k1-max-comparison-differences](https://all3dp.com/2/creality-k1-vs-k1c-vs-k1-max-comparison-differences)
- **Clever Creations - K1 Review:** [https://clevercreations.org/creality-k1-3d-printer-review-specs](https://clevercreations.org/creality-k1-3d-printer-review-specs)

### 10.6 Comunidad

- **Reddit - r/crealityk1:** [https://www.reddit.com/r/crealityk1/](https://www.reddit.com/r/crealityk1/) (Subreddit dedicado a la serie K1)
- **Reddit - r/Creality:** [https://www.reddit.com/r/Creality/](https://www.reddit.com/r/Creality/) (Comunidad general de Creality)
- **Creality Facebook Group:** Grupo oficial de usuarios de Creality con soporte comunitario.

### 10.7 Videos tutoriales

- **Creality K1 Unboxing and Review:** [https://www.youtube.com/watch?v=a6FzC-ApMx0](https://www.youtube.com/watch?v=a6FzC-ApMx0)
- **Creality K1 Hands-On Review:** [https://www.youtube.com/watch?v=DGUd5TzmBMU](https://www.youtube.com/watch?v=DGUd5TzmBMU)
- **Unlock Your Creality K1 Full Klipper Potential:** [https://www.youtube.com/watch?v=rJFQTUREVPE](https://www.youtube.com/watch?v=rJFQTUREVPE)
- **Creality K1 REVIEW: Worth buying in 2025?:** [https://www.youtube.com/watch?v=ap9kklnttkQ](https://www.youtube.com/watch?v=ap9kklnttkQ)

---

*Manual elaborado para el Aula STEAM. Basado en especificaciones oficiales de Creality, documentación de la comunidad de usuarios, revisiones técnicas y experiencia práctica con la Creality K1.*
