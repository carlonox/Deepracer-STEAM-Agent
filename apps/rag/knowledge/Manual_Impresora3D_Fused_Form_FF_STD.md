# Manual de Usuario — Impresora 3D Fused Form FF-STD
## Impresora 3D Profesional Doble Extrusor
### Aula STEAM — Universidad

---

## 1. Descripción General

La Fused Form FF-STD es una impresora 3D profesional de escritorio fabricada por la empresa colombiana ProtoLab 3D S.A.S., bajo la marca Fused Form. Esta impresora utiliza la tecnología FFF (Fused Filament Fabrication), también conocida como FDM (Fused Deposition Modeling), que consiste en depositar capas sucesivas de material termoplástico fundido para construir objetos tridimensionales a partir de un modelo digital. La FF-STD se posiciona como el modelo de entrada de la línea Fused Form, diseñada específicamente para usuarios que inician en el mundo de la impresión 3D pero que requieren capacidad profesional y fiabilidad de operación continua.

La característica más destacada de la FF-STD es su sistema de doble extrusor, que permite imprimir con dos materiales o colores simultáneamente. Esta funcionalidad es especialmente valiosa en el ámbito educativo y de prototipado, ya que permite crear piezas con soportes solubles (por ejemplo, usando PVA como material de soporte y PLA como material principal), imprimir objetos bicolor sin necesidad de cambiar filamento manualmente, y experimentar con combinaciones de materiales que aprovechen diferentes propiedades mecánicas. El doble extrusor también proporciona redundancia: si un extrusor presenta problemas, el otro puede continuar operando para impresiones de un solo material.

Fused Form, como marca colombiana con más de 12 años de experiencia en fabricación de impresoras 3D, ha diseñado la FF-STD con un enfoque en la robustez y la operación continua 24/7. El chasis está fabricado íntegramente en aluminio, lo que proporciona rigidez estructural y estabilidad durante la impresión, minimizando las vibraciones que pueden afectar la calidad de las piezas. Esta construcción robusta, combinada con componentes de calidad industrial, permite a la FF-STD operar de forma ininterrumpida durante días, una capacidad que la diferencia de las impresoras 3D de consumo típicamente disponibles en el mercado.

En el contexto del Aula STEAM, la FF-STD se utiliza como herramienta fundamental para el prototipado rápido, la fabricación de piezas personalizadas, la creación de maquetas y modelos arquitectónicos, y la producción de componentes para proyectos de robótica y diseño industrial. Su volumen de impresión de 24×20×32 cm permite fabricar piezas de tamaño considerable en una sola pieza, evitando la necesidad de ensamblar múltiples partes impresas por separado. La impresora está conectada al portátil Lenovo IdeaPad Slim 3, donde se encuentran instalados los slicers Ultimaker Cura (versiones 4.10.0, 5.8.1 y 5.10.0), Creality Print 6.2 y Orcaslicer, así como software de modelado 3D como Autodesk Fusion y Blender.

---

## 2. Especificaciones Técnicas

### 2.1 Parámetros de Impresión

| Parámetro | Valor |
|---|---|
| Tecnología de impresión | FFF (Fused Filament Fabrication) |
| Volumen de impresión | 24 × 20 × 32 cm (ancho × largo × alto) |
| Volumen con 1 boquilla | 20 × 20 × 24 cm |
| Altura de capa mínima | 60 micrones (0.06 mm) |
| Velocidad máxima de impresión | 200 mm/s |
| Diámetro de boquilla (predeterminado) | 0.4 mm |
| Diámetro de filamento | 1.75 mm |
| Tipo de extrusor | Doble extrusor (Bowden) |

### 2.2 Materiales Compatibles

| Material | Temperatura Boquilla | Temperatura Cama | Notas |
|---|---|---|---|
| PLA | 190–220 °C | 50–60 °C | Material más fácil de imprimir, ideal para principiantes |
| ABS | 230–260 °C | 100–110 °C | Requiere cámara cerrada; emite vapores, usar en ventilación |
| PETG | 220–250 °C | 70–80 °C | Buena resistencia química y mecánica; no requiere cámara |
| HIPS | 220–250 °C | 90–100 °C | Soluble en limoneno; útil como soporte soluble |
| TPU | 210–230 °C | 40–60 °C | Filamento flexible; requiere velocidades bajas (20–40 mm/s) |
| ASA | 240–260 °C | 90–110 °C | Resistente a UV; similar al ABS pero para exteriores |
| PVA | 180–200 °C | 45–60 °C | Soluble en agua; soporte soluble para doble extrusión |
| PA6 (Nylon) | 240–270 °C | 70–100 °C | Alta resistencia mecánica; higroscópico |

**Nota**: La FF-STD acepta carretes de filamento libres (no propietarios), lo que permite utilizar cualquier filamento estándar de 1.75 mm disponible en el mercado.

### 2.3 Características Mecánicas y Eléctricas

| Parámetro | Valor |
|---|---|
| Chasis | Aluminio 100% |
| Peso | 20 kg |
| Dimensiones físicas | 42 × 48 × 47 cm (ancho × profundidad × altura) |
| Requisitos de corriente | 110–240V AC, 60Hz |
| Consumo máximo | 180W |
| Capacidad de trabajo | 24/7 (operación continua) |

### 2.4 Conectividad y Software

| Parámetro | Valor |
|---|---|
| Conectividad | USB, tarjeta SD |
| Wi-Fi | Disponible (según configuración) |
| Sensor de filamento | Sí (detecta cuando se agota el filamento) |
| Formatos de archivo | .STL, .OBJ, .3MF (entrada al slicer); .GCODE (salida a la impresora) |
| Slicers compatibles | Ultimaker Cura, Creality Print, Orcaslicer, PrusaSlicer |
| Software de modelado recomendado | Autodesk Fusion, Blender, Tinkercad |

---

## 3. Componentes y Partes

### 3.1 Estructura Principal

La FF-STD presenta un diseño de marco cerrado con chasis de aluminio, que proporciona rigidez estructural superior frente a los diseños de marco abierto comunes en impresoras de consumo. Esta estructura cerrada ofrece ventajas significativas: reduce las corrientes de aire que pueden causar deformaciones en piezas impresas con materiales como ABS, proporciona una superficie de montaje estable para los componentes mecánicos, y protege al usuario del contacto accidental con partes calientes durante la operación.

**Componentes estructurales:**
- **Chasis de aluminio**: Marco rectangular de perfiles de aluminio extruido que soporta todos los componentes mecánicos. Los perfiles de aluminio proporcionan una relación rigidez/peso óptima, asegurando que las vibraciones del movimiento de los ejes se disipen rápidamente sin afectar la precisión de la impresión.
- **Base (Cama caliente)**: Plataforma de impresión calefaccionada montada sobre un sistema de guía lineal en el eje Y. La cama caliente es fundamental para la adherencia de la primera capa y para prevenir el warping (deformación por contracción térmica) en materiales como ABS y PETG.
- **Portal de eje X (Gantry)**: Estructura horizontal que soporta los dos extrusores y se mueve a lo largo del eje X (izquierda-derecha) y del eje Z (arriba-abajo). El movimiento en Z se realiza mediante varillas roscadas o husillos de bolas impulsados por motores paso a paso.

### 3.2 Sistema de Doble Extrusión

El corazón de la FF-STD es su sistema de doble extrusión, compuesto por dos extrusores tipo Bowden montados en el portal del eje X. En un sistema Bowden, el motor del extrusor está fijado al chasis de la impresora (no al cabezal móvil) y el filamento se empuja a través de un tubo de PTFE (tubo Bowden) hasta el hotend. Esta configuración reduce la masa del cabezal móvil en comparación con los extrusores directos (direct drive), lo que permite movimientos más rápidos y precisos, aunque a costa de una respuesta ligeramente inferior en la retracción del filamento.

**Componentes del sistema de extrusión:**

- **Motores de extrusión (2 unidades)**: Motores paso a paso que empujan el filamento a través de los tubos Bowden. Cada motor acciona un mecanismo de engranaje que muerde el filamento y lo avanza o retrae según las instrucciones del G-code.
- **Tubos Bowden (2 unidades)**: Tubos de PTFE de bajo coeficiente de fricción que guían el filamento desde el motor del extrusor hasta el hotend. El diámetro interior está optimizado para filamento de 1.75 mm, minimizando la holgura y el retroceso del filamento.
- **Hotends (2 unidades)**: Conjuntos de bloque calefactor, termistor y boquilla montados en el cabezal. Cada hotend incluye un disipador de calor con ventilador para evitar que el calor se propague hacia arriba por el filamento (lo que causaría atascos). La boquilla estándar es de 0.4 mm de diámetro, fabricada en latón, y puede reemplazarse por boquillas de otros diámetros.
- **Ventiladores de capa**: Ventiladores que dirigen aire frío sobre la capa recién depositada para solidificarla rápidamente, mejorando la calidad de los voladizos (overhangs) y los puentes (bridges). La velocidad del ventilador puede controlarse mediante G-code para optimizar la refrigeración según el material y la geometría de la pieza.

### 3.3 Sistema de Movimiento

- **Motores paso a paso**: La FF-STD utiliza motores paso a paso para el movimiento de los tres ejes (X, Y, Z) y los dos extrusores. Estos motores proporcionan un control preciso de la posición sin necesidad de retroalimentación (encoder), lo que simplifica el diseño y reduce el costo.
- **Correas de transmisión**: Los ejes X e Y utilizan correas dentadas de fibra de vidrio o kevlar recubiertas de poliuretano, que transfieren el movimiento del motor al cabezal y a la cama con mínima holgura y alta precisión de posicionamiento.
- **Guías lineales**: El eje Y (movimiento de la cama) y el eje X (movimiento del cabezal) utilizan varillas lisas o guías lineales con rodamientos de bolas para garantizar un movimiento suave y sin oscilaciones.
- **Endstops (finales de carrera)**: Sensores que detectan la posición de origen (home) de cada eje. Al iniciar una impresión, la impresora mueve cada eje hasta que el endstop correspondiente se activa, estableciendo el punto de referencia cero para todos los movimientos posteriores.

### 3.4 Electrónica y Controles

- **Pantalla LCD**: Interfaz de visualización que muestra el estado de la impresión, las temperaturas, el progreso y los menús de configuración. Permite controlar la impresora de forma autónoma sin necesidad de un ordenador conectado.
- **Rueda de navegación**: Control rotatorio con pulsación para navegar por los menús de la pantalla LCD, seleccionar archivos de la tarjeta SD, ajustar temperaturas y controlar la impresión.
- **Tarjeta SD**: Ranura para tarjeta SD donde se almacenan los archivos G-code que la impresora ejecuta. Este método permite la impresión autónoma sin necesidad de mantener el ordenador conectado durante todo el proceso.
- **Conexión USB**: Puerto para conectar la impresora directamente al ordenador, lo que permite enviar comandos G-code en tiempo real desde el slicer o un software de control como Pronterface o OctoPrint.
- **Sensor de filamento**: Dispositivo que detecta cuando el filamento se agota o se rompe, pausando automáticamente la impresión para permitir la recarga del carrete sin perder el progreso de la pieza.

---

## 4. Configuración y Puesta en Marcha

### 4.1 Desembalaje y Verificación

Al recibir la impresora Fused Form FF-STD, realice una verificación completa de todos los componentes:

1. **Inspección del chasis**: Verifique que la estructura de aluminio no presente golpes, abolladuras o deformaciones. Los perfiles deben estar alineados y las uniones firmes.
2. **Extrusores**: Compruebe que ambos extrusores están firmemente montados en el portal del eje X y que los tubos Bowden están conectados correctamente tanto en los motores de extrusión como en los hotends.
3. **Cama caliente**: Verifique que la cama se mueve libremente a lo largo del eje Y sin oscilaciones ni bloqueos. La superficie de impresión (generalmente una lámina de PEI, BuildTak o cinta de kapton) debe estar limpia y sin daños.
4. **Cables y conexiones**: Revise que todos los cables están correctamente conectados a la placa controladora y que no hay cables pelados, pellizcados o desconectados.
5. **Accesorios**: Verifique la presencia de la tarjeta SD, el cable USB, el cable de alimentación, los carretes de filamento de muestra (si aplica) y cualquier herramienta incluida (espátula, pinzas, etc.).

### 4.2 Ubicación y Entorno

La ubicación de la impresora es crucial para obtener resultados óptimos:

1. **Superficie estable**: Coloque la impresora sobre una mesa o superficie firme y nivelada que soporte al menos 25 kg (peso de la impresora más el material). La superficie no debe vibrar ni tambalearse durante la operación.
2. **Ventilación**: Asegure una ventilación adecuada en el área de trabajo, especialmente si se imprimirá con ABS u otros materiales que emiten compuestos orgánicos volátiles (COV). Una ventana abierta o un sistema de extracción son recomendables.
3. **Temperatura ambiente**: La temperatura ideal del entorno es entre 15°C y 30°C. Temperaturas inferiores pueden causar warping en materiales como ABS; temperaturas superiores pueden afectar el rendimiento de la electrónica.
4. **Alejar de corrientes de aire**: Evite colocar la impresora cerca de ventanas abiertas, ventiladores o aires acondicionados que puedan crear corrientes de aire súbitas sobre la pieza en impresión.
5. **Proximidad al ordenador**: La impresora debe estar lo suficientemente cerca del portátil Lenovo IdeaPad Slim 3 para permitir la conexión USB si se desea controlar la impresión desde el ordenador.

### 4.3 Conexión Eléctrica

1. Verifique que el interruptor de encendido de la impresora esté en posición OFF.
2. Conecte el cable de alimentación a la parte posterior de la impresora y a una toma de corriente con conexión a tierra (110V o 220V según la configuración local).
3. Encienda la impresora con el interruptor principal. La pantalla LCD debe iluminarse y mostrar el menú principal.

### 4.4 Configuración del Slicer (Ultimaker Cura)

El slicer es el software que convierte el modelo 3D (archivo STL, OBJ o 3MF) en instrucciones G-code que la impresora puede ejecutar. En el Aula STEAM, se utiliza principalmente Ultimaker Cura. La configuración del perfil de la FF-STD en Cura es el siguiente:

1. **Abrir Ultimaker Cura** en el portátil Lenovo IdeaPad Slim 3.
2. **Agregar impresora personalizada**: Vaya a Configuración > Impresora > Añadir impresora y seleccione "Añadir una impresora no conectada a la red".
3. **Configurar parámetros del perfil**:
   - Volumen de construcción: X = 240 mm, Y = 200 mm, Z = 320 mm
   - Número de extrusores: 2
   - Diámetro de boquilla: 0.4 mm
   - Diámetro de filamento: 1.75 mm
   - Temperatura de boquilla (PLA): 200°C
   - Temperatura de cama (PLA): 60°C
4. **Configurar el G-code de inicio** (start G-code): Este código se ejecuta antes de cada impresión para preparar la máquina. Un ejemplo típico incluye el calentamiento de la boquilla y la cama, el homing de los ejes y la purga del extrusor.
5. **Guardar el perfil** con el nombre "Fused Form FF-STD" para uso futuro.

### 4.5 Nivelación de la Cama

La nivelación de la cama es el paso más crítico para lograr impresiones exitosas. Una cama desnivelada causa problemas de adherencia, primera capa irregular y fallos de impresión. El procedimiento es:

1. **Calentar la cama**: Establezca la temperatura de la cama a la temperatura de impresión del material que utilizará (60°C para PLA, 100°C para ABS). La cama se expande ligeramente al calentarse, por lo que la nivelación debe realizarse con la cama a temperatura de operación.
2. **Preparar el papel de calibración**: Utilice una hoja de papel normal (espesor aprox. 0.1 mm) como calibre de separación entre la boquilla y la cama.
3. **Mover la boquilla a las cuatro esquinas**: Utilice los controles de la pantalla LCD o los controles de Cura para posicionar la boquilla sobre cada esquina de la cama.
4. **Ajustar los tornillos de nivelación**: En cada esquina, deslice el papel entre la boquilla y la cama. El papel debe deslizarse con una ligera resistencia (fricción suave), sin estar ni demasiado suelto ni demasiado apretado. Gire los tornillos de nivelación debajo de la cama para ajustar la altura en cada esquina.
5. **Verificar el centro**: Después de ajustar las cuatro esquinas, verifique el centro de la cama con el mismo método del papel.
6. **Repetir si es necesario**: Es común necesitar 2-3 iteraciones de ajuste ya que cambiar un tornillo puede afectar ligeramente los demás.

### 4.6 Carga del Filamento

1. **Calentar la boquilla**: Desde el menú de la pantalla LCD, seleccione "Preparar" > "Calentar boquilla" y establezca la temperatura correspondiente al material (200°C para PLA).
2. **Insertar el filamento**: Una vez que la boquilla alcanza la temperatura objetivo, presione la palanca del extrusor para abrir el mecanismo de agarre, e inserte el extremo del filamento en la entrada del tubo Bowden. Empuje suavemente hasta que el filamento salga por la boquilla.
3. **Purga**: Extruya un pequeño cantidad de filamento (aprox. 20 mm) para asegurar que el material fluye correctamente y que no hay aire en el sistema. El filamento debe salir de forma continua y uniforme.
4. **Repetir para el segundo extrusor** si se va a utilizar impresión dual.

---

## 5. Guía de Uso Paso a Paso

### 5.1 Flujo de Trabajo Completo de Impresión 3D

El proceso de impresión 3D sigue un flujo de trabajo que va desde la concepción del diseño hasta la pieza física terminada. A continuación se describe cada etapa en detalle:

**Paso 1: Diseño o descarga del modelo 3D**

El primer paso es obtener un modelo 3D en formato digital. Existen dos caminos principales: diseñar el modelo desde cero utilizando software de modelado 3D, o descargar un modelo preexistente de un repositorio en línea. En el Aula STEAM, los programas disponibles para diseño son Autodesk Fusion (para modelado paramétrico orientado a ingeniería y piezas mecánicas), Blender (para modelado orgánico, escultórico y artístico), y Tinkercad (para principiantes, accesible vía web). Los repositorios más populares para descargar modelos son Thingiverse, Printables, y MyMiniFactory.

**Paso 2: Preparación del modelo en el slicer**

Una vez que se tiene el archivo STL u OBJ, se importa en el slicer (Ultimaker Cura) donde se configuran todos los parámetros de impresión:

1. **Importar el modelo**: Arrastre el archivo STL a la ventana de Cura o use Archivo > Abrir archivo.
2. **Posicionar el modelo**: Ubique el modelo sobre la cama virtual, asegurándose de que está completamente dentro del volumen de impresión. Utilice las herramientas de mover, rotar y escalar según sea necesario.
3. **Orientar el modelo**: La orientación afecta drásticamente la calidad y el tiempo de impresión. Como regla general, la cara más plana y grande del modelo debe apoyarse sobre la cama. Minimice los voladizos (overhangs) para reducir la necesidad de soportes.
4. **Configurar parámetros de impresión**: Seleccione el perfil de calidad, relleno, temperatura, velocidad y soportes. Los perfiles recomendados para empezar son:

| Parámetro | Configuración Inicial (PLA) |
|---|---|
| Altura de capa | 0.2 mm (calidad estándar) |
| Relleno (infill) | 15–20% (patrón cúbico o giroide) |
| Temperatura de boquilla | 200°C |
| Temperatura de cama | 60°C |
| Velocidad de impresión | 50–60 mm/s |
| Soportes | Activar si hay voladizos > 45° |
| Adhesión de primera capa | Borde (brim) o balsa (raft) |
| Patrón de pared exterior | 2 líneas |

5. **Generar el G-code**: Haga clic en "Rebanar" (Slice). Cura calculará las trayectorias del extrusor y generará el archivo G-code. Revise la estimación de tiempo, consumo de filamento y la visualización de la vista previa capa por capa.
6. **Guardar el G-code**: Exporte el archivo G-code a la tarjeta SD o envíelo directamente a la impresora por USB.

**Paso 3: Impresión**

1. Inserte la tarjeta SD con el archivo G-code en la ranura de la impresora.
2. Desde la pantalla LCD, seleccione el archivo y pulse iniciar.
3. Observe la primera capa: es el momento más crítico de la impresión. Verifique que el filamento se adhiere correctamente a la cama en toda su superficie. Si la primera capa no se adhiere, cancele la impresión y ajuste la nivelación de la cama o la temperatura.
4. Monitoree periódicamente la impresión, especialmente en las primeras horas, para detectar problemas como desprendimiento de la cama, atascos de filamento o desplazamiento de capas.

**Paso 4: Postprocesado**

1. Espere a que la cama se enfríe antes de retirar la pieza. La pieza se desprende más fácilmente cuando la cama está fría porque los materiales se contraen ligeramente.
2. Utilice la espátula para despegar la pieza de la cama, deslizándola cuidadosamente por debajo de los bordes.
3. Retire los soportes con pinzas o alicates, teniendo cuidado de no dañar las superficies de la pieza.
4. Lije o pula las superficies si es necesario. El PLA se lija fácilmente con papel de lija de grano progresivo (desde 120 hasta 400 o más).

### 5.2 Impresión con Doble Extrusor

La impresión dual permite aprovechar al máximo la capacidad de la FF-STD. Los casos de uso principales son:

**Impresión bicolor:**
1. Cargue filamento de diferente color en cada extrusor.
2. En Cura, asigne cada parte del modelo al extrusor correspondiente. Para modelos de una sola pieza con cambios de color, utilice la función "Modificar G-code para cambio de extrusor" o diseñe el modelo como dos partes separadas en Fusion/Blender.
3. Configure la temperatura de cada extrusor según el material cargado.
4. Active la opción "Limpiar boquilla al cambiar de extrusor" (prime tower o ooze shield) para evitar que el material residual de un extrusor contamine la impresión del otro.

**Impresión con soportes solubles (PLA + PVA):**
1. Cargue PLA en el extrusor 1 y PVA en el extrusor 2.
2. En Cura, configure el extrusor 1 como material principal y el extrusor 2 como material de soporte.
3. Los soportes se imprimirán en PVA, que se disuelve en agua tibia en 2-8 horas, dejando la pieza principal limpia sin marcas de soportes.

### 5.3 Recomendaciones por Material

**PLA (ácido poliláctico):**
El PLA es el material más recomendado para usuarios principiantes y para la mayoría de las aplicaciones en el Aula STEAM. Es un bioplástico derivado de recursos renovables (almidón de maíz, caña de azúcar) que se imprime a temperaturas relativamente bajas (190–220°C), no emite olores tóxicos significativos, y ofrece excelente detalle superficial. Sin embargo, tiene limitaciones mecánicas: se deforma a temperaturas superiores a 60°C, es relativamente quebradizo bajo impacto, y no es resistente a la humedad prolongada. Para piezas funcionales que requieran mayor resistencia, considere PETG.

**PETG (polietileno tereftalato glicol):**
El PETG es una excelente alternativa al PLA cuando se necesita mayor resistencia mecánica, química y térmica. Es más resistente al impacto, más flexible (menos quebradizo), y soporta temperaturas de hasta 80°C sin deformarse. Se imprime a 220–250°C con cama a 70–80°C. Su principal desventaja es que tiende a crear "strings" (hilos de plástico entre partes de la pieza durante los desplazamientos), lo que requiere optimizar los parámetros de retracción y temperatura.

**ABS (acrilonitrilo butadieno estireno):**
El ABS es un material de ingeniería con alta resistencia al impacto y estabilidad térmica (hasta 100°C). Sin embargo, es considerablemente más difícil de imprimir que PLA o PETG: requiere temperaturas de extrusión altas (230–260°C), cama caliente a 100–110°C, y es muy susceptible al warping (deformación por contracción térmica). Además, durante la impresión emite estireno, un compuesto con potenciales efectos en la salud, por lo que es obligatorio usar la impresora en un área bien ventilada o con sistema de extracción de humos.

---

## 6. Mantenimiento Básico

### 6.1 Limpieza de la Cama de Impresión

La limpieza regular de la superficie de impresión es esencial para mantener una buena adherencia de la primera capa. Los residuos de aceite, grasa de los dedos y polvo reducen significativamente la adherencia del filamento.

**Procedimiento:**
1. Espere a que la cama se enfríe completamente a temperatura ambiente.
2. Retire la pieza impresa con la espátula.
3. Limpie la superficie con un paño limpio humedecido con alcohol isopropílico al 90% o superior. El alcohol disuelve los residuos de grasa y aceite sin dañar la superficie.
4. Si la superficie tiene residuos de filamento adheridos que no se despegan, caliéntela a la temperatura de impresión del material (60°C para PLA) y luego retire los residuos con la espátula.
5. No utilice limpiadores abrasivos, acetona (si la superficie es de ABS) ni objetos metálicos que puedan rayar la superficie.
6. Para camas con superficie PEI, un limpieza con alcohol isopropílico cada 5-10 impresiones es suficiente. Si la adherencia disminuye notablemente, una ligera pasada con lana de acero fina (grano 0000) puede restaurar la rugosidad superficial necesaria.

### 6.2 Limpieza de las Boquillas

Las boquillas pueden obstruirse con residuos de filamento carbonizado, especialmente si se imprime a temperaturas altas con materiales como ABS o Nylon. Los síntomas de una boquilla obstruida incluyen flujo irregular de filamento, sub-extrusión o falta total de extrusión.

**Procedimiento de limpieza (método de la aguja):**
1. Caliente la boquilla a la temperatura de impresión del último material utilizado.
2. Retire el filamento del extrusor.
3. Inserte una aguja de limpieza de 0.4 mm (incluida en la mayoría de kits de mantenimiento) por la parte inferior de la boquilla, empujando suavemente para desalojar el bloqueo.
4. Extraiga la aguja y extruya filamento de limpieza (filamento de limpieza comercial o simplemente PLA) hasta que fluya de forma uniforme.
5. Repita si es necesario.

**Método de extracción en frío (cold pull):**
1. Caliente la boquilla a 200°C.
2. Inserte filamento PLA manualmente y empújelo hasta que salga por la boquilla.
3. Reduzca la temperatura a 90°C.
4. Cuando la temperatura alcance 90°C, tire firmemente del filamento hacia arriba. El filamento debería salir con la forma del interior de la boquilla, arrastrando los residuos de carbonización.

### 6.3 Lubricación de las Guías Lineales

Las guías lineales y varillas lisas deben lubricarse periódicamente para asegurar un movimiento suave y prevenir el desgaste prematuro:

1. Utilice grasa de litio o aceite de máquina de coser (no aceite WD-40, que es un desengrasante y puede dañar los rodamientos).
2. Aplique una pequeña cantidad en las varillas y guías, distribuyendo con un paño limpio.
3. Mueva manualmente los ejes para distribuir la lubricación uniformemente.
4. Limpie el exceso de lubricante.
5. Frecuencia recomendada: cada 3 meses con uso regular, o cada mes con uso intensivo.

### 6.4 Verificación de la Tensión de las Correas

Las correas de transmisión deben mantener una tensión adecuada para garantizar la precisión del posicionamiento. Una correa demasiado floja causa imprecisiones (backlash) y capas desalineadas; una correa demasiado tensa desgasta prematuramente los rodamientos y los motores.

1. Verifique la tensión presionando la correa con el dedo en el punto medio entre las dos poleas. Debe ceder ligeramente (2-3 mm) con presión moderada.
2. Si la correa está floja, ajuste el tensor de correa (si la impresora lo tiene) o afloje los tornillos de fijación del motor, tire del motor para tensar la correa y vuelva a apretar.
3. Verifique ambas correas (eje X y eje Y).

### 6.5 Calibración Periódica

Se recomienda realizar las siguientes calibraciones de forma periódica:

| Calibración | Frecuencia | Procedimiento |
|---|---|---|
| Nivelación de cama | Cada 10 impresiones o al cambiar de material | Ver sección 4.5 |
| Calibración de pasos por mm | Cada 3 meses o si las dimensiones de las piezas son inexactas | Imprimir un cubo de calibración de 20×20×20 mm y medir con calibrador |
| Eje Z offset | Si cambia la boquilla o la superficie de la cama | Ajustar la distancia boquilla-cama en el firmware o slicer |
| Flujo de extrusión | Al cambiar de marca o tipo de filamento | Imprimir un cubo hueco de una pared y medir el espesor real vs. el configurado |

---

## 7. Solución de Problemas Comunes

### 7.1 La pieza no se adhiere a la cama

**Causas posibles y soluciones:**

- **Cama desnivelada**: Es la causa más común. Realice la nivelación de la cama según la sección 4.5, asegurándose de que la separación entre la boquilla y la cama sea de aproximadamente 0.1 mm en las cuatro esquinas y el centro.
- **Cama sucia**: Limpie la superficie con alcohol isopropílico. Los residuos de grasa de los dedos son la causa más frecuente de mala adherencia.
- **Temperatura de cama demasiado baja**: Aumente la temperatura de la cama en 5°C. Para PLA, 60°C suele ser suficiente; para ABS, puede necesitar 100–110°C.
- **Primera capa demasiado alta**: Aumente el flujo de la primera capa al 110–120% en el slicer, o reduzca ligeramente la altura de la primera capa.
- **Sin adhesivo de primera capa**: Active la opción "Brim" (borde) o "Raft" (balsa) en el slicer. El brim añade un borde de varias líneas alrededor de la pieza que aumenta el área de contacto con la cama.
- **Cama sin textura**: Si la superficie de impresión está muy lisa o desgastada, considere reemplazarla o aplicar una capa de adhesivo para impresión 3D (glue stick, laca para el pelo, o adhesivo especializado como Magigoo).

### 7.2 Warping (Deformación de las esquinas)

El warping ocurre cuando las esquinas de la pieza se curvan hacia arriba, desprendiéndose de la cama. Es especialmente común con ABS y piezas grandes.

**Soluciones:**
- **Usar brim o raft**: Añadir un borde amplio (brim de 8-10 líneas) aumenta la superficie de adherencia.
- **Aumentar la temperatura de la cama**: 5-10°C más pueden marcar la diferencia.
- **Cerrar la estructura**: Si la impresora tiene tapas laterales, colóquelas para mantener una temperatura uniforme alrededor de la pieza.
- **Usar PLA en lugar de ABS**: El PLA tiene una contracción térmica mucho menor (0.3–0.5% vs. 0.7–1.0% del ABS) y es mucho menos propenso al warping.
- **Diseñar con chaflanes**: Añadir chaflanes (ángulos redondeados) en la base del modelo reduce la concentración de tensiones en las esquinas.

### 7.3 Stringing (Hilos entre partes de la pieza)

Los hilos de plástico que aparecen entre partes separadas de la pieza durante los desplazamientos del cabezal son causados por material que gotea de la boquilla cuando no debería.

**Soluciones:**
- **Aumentar la retracción**: La retracción tira del filamento hacia atrás durante los desplazamientos para evitar el goteo. Aumente la distancia de retracción en 0.5 mm (típico: 5–7 mm para Bowden) y la velocidad de retracción a 40–60 mm/s.
- **Reducir la temperatura**: Una temperatura de boquilla 5°C más baja puede reducir significativamente el stringing.
- **Activar la vuelta de compresión (combing)**: En Cura, active la opción "Combing" para que el cabezal se mueva dentro de la pieza ya impresa en lugar de a través de espacios vacíos.
- **Aumentar la velocidad de desplazamiento**: Un desplazamiento más rápido (travel speed) reduce el tiempo durante el cual el material puede gotear.

### 7.4 Sub-extrusión (La pieza queda con huecos o capas incompletas)

La sub-extrusión ocurre cuando la cantidad de filamento depositada es insuficiente, resultando en capas con huecos, paredes delgadas o líneas interrumpidas.

**Causas y soluciones:**
- **Filamento atascado en el extrusor**: Retire el filamento, córtelo por encima de la zona deformada y vuelva a cargarlo.
- **Boquilla obstruida**: Limpie la boquilla según el procedimiento de la sección 6.2.
- **Diámetro de filamento incorrecto en el slicer**: Verifique que el diámetro configurado en Cura es 1.75 mm. Medir el filamento real con un calibrador puede revelar variaciones.
- **Temperatura demasiado baja**: Aumente la temperatura de la boquilla en 5°C.
- **Velocidad demasiado alta**: Reduzca la velocidad de impresión, especialmente para materiales como TPU.
- **Tensión del extrusor incorrecta**: Ajuste la tensión del resorte del extrusor para que el engranaje agarre firmemente el filamento sin deformarlo.

### 7.5 Desplazamiento de capas (Layer shifting)

El layer shifting ocurre cuando las capas de la pieza no están alineadas entre sí, creando un efecto escalonado. Este problema es causado por una pérdida de posición en uno o más ejes durante la impresión.

**Causas y soluciones:**
- **Correa floja**: Verifique y ajuste la tensión de las correas (sección 6.4).
- **Velocidad demasiado alta**: Reduzca la velocidad de impresión, especialmente si la pieza tiene geometrías complejas que requieren muchos cambios de dirección.
- **Corriente del motor insuficiente**: Si los motores pierden pasos, puede ser necesario aumentar la corriente del driver en la placa controladora. Este ajuste debe realizarlo personal con experiencia.
- **Obstrucción mecánica**: Verifique que no hay cables, tubos Bowden o residuos de filamento que interfieran con el movimiento libre de los ejes.

### 7.6 Atasco de filamento (Clogging)

El atasco de filamento es uno de los problemas más frecuentes y se produce cuando el filamento se bloquea en el hotend o el tubo Bowden.

**Procedimiento de resolución:**
1. Intente extruir filamento manualmente desde el menú de la pantalla LCD. Si no sale material, confirme el atasco.
2. Caliente la boquilla a la temperatura de impresión + 10°C.
3. Retire el filamento del extrusor tirando hacia arriba.
4. Si el filamento está atascado dentro del hotend, corte el filamento por encima del conector Bowden y retire la porción atascada con pinzas.
5. Pase filamento nuevo y extruya hasta que fluya de forma continua.
6. Si el atasco persiste, desmonte el hotend y limpie la boquilla con el método de la aguja o cold pull (sección 6.2).

**Prevención:**
- No deje la impresora calentada con filamento cargado si no está imprimiendo (el filamento puede carbonizarse).
- Asegúrese de que el tubo Bowden está completamente insertado en los conectores del hotend.
- Almacene el filamento en un lugar seco para evitar que absorba humedad.

---

## 8. Materiales, Repuestos y Accesorios

### 8.1 Materiales de Consumo

| Material | Uso Típico | Rango de Precio (aprox.) | Notas |
|---|---|---|---|
| PLA 1.75mm | Prototipos, modelos decorativos, piezas educativas | $20–40 USD/kg | Material de entrada; fácil de imprimir |
| PETG 1.75mm | Piezas funcionales, componentes mecánicos | $25–45 USD/kg | Mayor resistencia térmica y mecánica que PLA |
| ABS 1.75mm | Piezas resistentes al calor, carcasas | $20–35 USD/kg | Requiere ventilación; propenso a warping |
| TPU 1.75mm | Fundas, juntas, piezas flexibles | $30–50 USD/kg | Velocidad baja; requiere extrusor Bowden con retracción moderada |
| PVA 1.75mm | Soportes solubles para doble extrusión | $50–80 USD/kg | Soluble en agua; higroscópico |
| HIPS 1.75mm | Soportes solubles alternativos | $25–40 USD/kg | Soluble en limoneno; alternativa al PVA |

### 8.2 Repuestos Comunes

| Repuesto | Código/Referencia | Notas |
|---|---|---|
| Boquilla de latón 0.4mm | Estándar M6 | Compatible con hotend estándar; reemplazar cada 3-6 meses con uso regular |
| Tubo Bowden (PTFE) | DI 1.75mm / DE 4mm | Cortar a la medida; reemplazar si presenta marcas de desgaste |
| Correa de transmisión GT2 | 6mm de ancho | Verificar longitud antes de pedir |
| Ventilador de capa | 40×40mm, 24V | Reemplazar si hace ruido excesivo o no gira |
| Ventilador del hotend | 30×30mm o 40×40mm, 24V | Crucial para evitar atascos; reemplazar inmediatamente si falla |
| Superficie de impresión | PEI o BuildTak | Reemplazar cuando la adherencia disminuye irreversiblemente |
| Tarjeta SD | Formato FAT32, 4–32 GB | Usar tarjetas de marca; las tarjetas defectuosas causan fallos de impresión |

### 8.3 Accesorios Complementarios

| Accesorio | Función | Recomendado para Aula STEAM |
|---|---|---|
| Espátula de impresión 3D | Despegar piezas de la cama | Sí, indispensable |
| Pinzas de punta fina | Retirar soportes, cortar filamento | Sí, indispensable |
| Cinta Kapton | Superficie de impresión alternativa | Opcional (para ABS) |
| Glue stick o laca | Adhesivo para primera capa | Recomendado como respaldo |
| Calibrador digital | Medir piezas y verificar dimensiones | Recomendado |
| Secador de filamento | Eliminar humedad del filamento | Recomendado para Nylon y PVA |
| Cámara de ventilación | Extraer vapores de ABS | Necesario si se imprime ABS en interior |

---

## 9. Normas de Uso STEAM

### 9.1 Normas Generales de Seguridad

1. **Superficies calientes**: La boquilla alcanza temperaturas de hasta 260°C y la cama caliente hasta 110°C. NUNCA tocar estas superficies durante la impresión o mientras estén calientes. Esperar al menos 15 minutos después de apagar la impresora antes de manipular cualquier componente interno.

2. **Partes móviles**: Los ejes de la impresora se mueven a velocidades de hasta 200 mm/s. Mantener las manos, cabello, ropa suelta y objetos alejados del área de impresión durante la operación. No intentar alcanzar el interior de la impresora mientras está en movimiento.

3. **Ventilación**: Siempre imprimir en un área bien ventilada. La impresión con ABS, ASA y otros materiales emite compuestos orgánicos volátiles (COV) que pueden ser perjudiciales con exposición prolongada. Para PLA y PETG, la ventilación normal del aula es suficiente. Para ABS, se recomienda una ventana abierta o un sistema de extracción.

4. **No dejar la impresora sin supervisión prolongada**: Aunque la FF-STD está diseñada para operación 24/7, en el contexto del Aula STEAM se recomienda que alguien verifique periódicamente la impresión (al menos cada 2 horas) para detectar problemas a tiempo.

5. **Apagar al finalizar**: Al terminar la sesión, esperar a que la impresora se enfríe y apagarla con el interruptor principal. No dejar la impresora encendida fuera del horario del Aula sin autorización.

### 9.2 Normas de Uso del Equipamiento

1. **Reserva de uso**: La impresora 3D es un recurso compartido del Aula STEAM. Se debe reservar con antelación a través del sistema de reservas del Aula. Cada sesión tiene un tiempo máximo de uso para garantizar el acceso equitativo.

2. **No modificar los perfiles del slicer sin autorización**: Los perfiles de impresión en Ultimaker Cura están configurados y validados para la FF-STD. Si necesita ajustar parámetros para un proyecto específico, consulte al coordinador del Aula y documente los cambios realizados.

3. **Usar filamento del Aula**: El Aula STEAM proporciona filamento PLA de calidad verificada. No utilice filamento de fuentes desconocidas o de dudosa calidad, ya que puede contener impurezas que obstruyan las boquillas o generar emisiones tóxicas.

4. **No forzar mecanismos**: Si la cama, los ejes o los extrusores presentan resistencia al moverse, no fuerce el movimiento. Informe al coordinador del Aula para que revise el equipo.

5. **Limpieza post-impresión**: Después de cada impresión, retire la pieza, limpie la cama con alcohol isopropílico, retire los restos de filamento y soportes del área de trabajo, y guarde el filamento sobrante en su bolsa sellada con desecante.

### 9.3 Normas de Almacenamiento de Filamento

1. **Mantener en bolsas selladas**: El filamento es higroscópico (absorbe humedad del aire), especialmente el Nylon, el PVA y el PETG. Guardar siempre en bolsas selladas con paquetes de gel de sílice (desecante) cuando no esté en uso.
2. **Almacenar en lugar fresco y seco**: Evitar la exposición directa al sol y temperaturas superiores a 40°C.
3. **Etiquetar el filamento**: Indicar la fecha de apertura, el material, el color y la marca. El filamento abierto por más de 3 meses puede haber absorbido suficiente humedad para requerir secado antes de usarlo.

### 9.4 Configuración Específica del Aula STEAM

En el Aula STEAM, la Fused Form FF-STD está conectada al portátil **Lenovo IdeaPad Slim 3** (Laptop 1 — configuración estándar) con las siguientes particularidades:

- **Slicers instalados**: Ultimaker Cura 4.10.0, 5.8.1 y 5.10.0; Creality Print 6.2; Orcaslicer
- **Software de modelado 3D**: Autodesk Fusion, Blender 4.4.3, Meshmixer 3.5
- **Software de escaneo 3D**: RevoScan 5 v5.5.3.1720 (para generar modelos STL a partir de escaneos 3D)
- **Conexión preferida**: Tarjeta SD (para impresión autónoma sin dependencia del ordenador)
- **Materiales disponibles en el Aula**: PLA (varios colores), PETG, TPU
- **Ubicación física**: Estación de impresión 3D del Aula STEAM, sobre mesa estable con ventilación adecuada

---

## 10. Enlaces y Recursos Adicionales

### 10.1 Sitio Web Oficial y Soporte

- **Página oficial de Fused Form**: https://fusedformcorp.com
- **Página del producto FF-STD (inglés)**: https://fusedformcorp.com/en/3d-printer/double-extruder-3d-printer-ff-std
- **Página del producto FF-STD (español)**: https://fusedformcorp.com/impresoras-3d/impresora-3d-doble-extrusor-ffstd
- **Especificaciones técnicas (todos los modelos)**: https://fusedformcorp.com/en/3d-printer/3d-printer-technical-specifications
- **Descargables (manuales, drivers)**: https://fusedformcorp.com/descargables
- **Manual de usuario v3 (PDF)**: https://fusedformcorp.com/wp-content/uploads/2020/10/Manual-de-usuario-Fused-Form_v3.pdf
- **Manual de usuario v2.1 (PDF)**: https://fusedformcorp.com/wp-content/uploads/2020/04/Manual-de-Usuario-FF_v2.1.pdf

### 10.2 Tutoriales en Video (Oficiales Fused Form)

- **Video 1: Conociendo tu Impresora 3D Fused Form**: Serie de tutoriales oficiales para familiarizarse con la impresora.
- **Video 2: Ingresando el Material**: https://www.youtube.com/watch?v=qRp149DoCks — Guía paso a paso para cargar filamento.
- **Video 3: Calibrando tu Impresora 3D Fused Form**: https://www.youtube.com/watch?v=XaBUOShy7Io — Procedimiento de calibración de la cama.
- **Video 4: Imprimir en 3D con tu Impresora 3D Fused Form**: https://www.youtube.com/watch?v=svVtDHcCsl4 — Primeros pasos de impresión.

### 10.3 Recursos de Aprendizaje para Impresión 3D

- **Ultimaker Cura (descarga y documentación)**: https://ultimaker.com/software/ultimaker-cura
- **Guía de Cura para principiantes**: https://support.ultimaker.com/hc/en-us/articles/360012497839-How-to-use-Ultimaker-Cura
- **Orcaslicer (descarga)**: https://github.com/SoftFever/OrcaSlicer
- **Thingiverse (repositorio de modelos)**: https://www.thingiverse.com
- **Printables (repositorio de modelos)**: https://www.printables.com
- **All3DP (guías y tutoriales)**: https://all3dp.com
- **3D Printing Handbook (guía completa)**: Recursos educativos sobre tecnología FFF, materiales y técnicas.

### 10.4 Recursos de Modelado 3D

- **Autodesk Fusion (aprendizaje)**: https://www.autodesk.com/products/fusion-360/learn
- **Blender (documentación oficial)**: https://docs.blender.org/
- **Tinkercad (modelado web para principiantes)**: https://www.tinkercad.com
- **Meshmixer (edición y reparación de mallas)**: https://www.meshmixer.com

### 10.5 Comunidad y Foros

- **Fused Form en redes sociales**: Seguir las cuentas oficiales de Fused Form para novedades, actualizaciones y soporte.
- **Reddit r/3Dprinting**: Comunidad general de impresión 3D con resolución de problemas y recomendaciones — https://www.reddit.com/r/3Dprinting/
- **Reddit r/FDM3DPrinting**: Comunidad específica para impresión FDM — https://www.reddit.com/r/FDM3DPrinting/

### 10.6 Recursos para el Aula STEAM

- **Manual del portátil Lenovo IdeaPad Slim 3 (Aula STEAM)**: Documento complementario con las especificaciones del ordenador anfitrión y la configuración de software relacionada.
- **Manual de la tableta gráfica VEIKK VK2200 PRO (Aula STEAM)**: Documento del dispositivo de entrada utilizado para el diseño digital previo a la impresión.
- **Brochure Fused Form 2023 (Scribd)**: https://es.scribd.com/document/758692204/Brochure-FusedForm-2023 — Catálogo completo de productos Fused Form con especificaciones detalladas.
