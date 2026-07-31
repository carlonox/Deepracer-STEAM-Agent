# Manual de Usuario — Impresora 3D de Arcilla Tronxy Moore 1

**Aula STEAM — Manual de referencia para estudiantes y asistente robot AI**

---

## 1. Descripción general

La Tronxy Moore 1 es una impresora 3D de escritorio especializada en Modelado por Deposición Líquida (LDM, por sus siglas en inglés: *Liquid Deposition Modeling*), una variante de la tecnología FDM adaptada para trabajar con materiales viscosos y fluidos como arcilla, lodo cerámico, porcelana roja y otras pastas líquidas. A diferencia de las impresoras 3D convencionales que utilizan filamentos sólidos de plástico (PLA, ABS, PETG, etc.), la Moore 1 emplea un sistema de extrusión por varilla eléctrica push-rod combinada con un tornillo sinfín que empuja la arcilla contenida en un cilindro o barril hacia la boquilla, depositando capas sucesivas de material cerámico sobre la plataforma de impresión.

Este equipo es especialmente relevante en un contexto educativo STEAM porque cierra la brecha entre la fabricación digital y la artesanía tradicional. Los estudiantes pueden diseñar piezas en software de modelado 3D, enviarlas a la Moore 1 y obtener objetos de arcilla húmeda que, tras un proceso de secado, esmaltado y cocción en horno, se convierten en cerámica funcional y decorativa. Esta combinación de tecnologías contemporáneas con técnicas milenarias de alfarería convierte a la Moore 1 en un puente interdisciplinario entre ingeniería, diseño, arte y ciencia de materiales.

En el aula STEAM se dispone de **dos (2) unidades** de la Tronxy Moore 1, lo que permite que varios estudiantes trabajen simultáneamente en proyectos de impresión cerámica. La máquina llega completamente ensamblada de fábrica (estructura *all-in-one*), por lo que no requiere un proceso de montaje complicado; tras desempaquetarla, basta con conectarla a la corriente, nivelar la cama y preparar la arcilla para comenzar a imprimir. La interfaz de pantalla táctil a color de 3,5 pulgadas facilita la operación incluso para usuarios sin experiencia previa en impresión 3D.

La Moore 1 no requiere compresor de aire externo, ya que su sistema de alimentación por varilla eléctrica y tornillo de extrusión genera la presión necesaria para hacer fluir la arcilla. Esto simplifica enormemente la configuración y reduce el equipo periférico necesario en el aula. Su tamaño compacto (355 × 252 × 370 mm) permite ubicarla en espacios reducidos, y su diseño de estructura integrada la hace estable durante la impresión, minimizando vibraciones que podrían afectar la calidad de las piezas cerámicas.

---

## 2. Especificaciones técnicas

| Parámetro | Valor |
|---|---|
| **Tecnología de impresión** | LDM (Liquid Deposition Modeling) |
| **Volumen de impresión** | 180 × 180 × 180 mm |
| **Volumen útil de pieza** | ~5,8 L |
| **Diámetro de boquilla** | 1,0 - 3,0 mm (2,0 mm estándar) |
| **Grosor de capa** | 0,3 - 3,0 mm (0,5 mm estándar) |
| **Resolución de posicionamiento XY** | 6,25 µm |
| **Resolución de posicionamiento Z** | 1,25 µm |
| **Velocidad máxima de impresión** | 40 mm/s |
| **Velocidad recomendada** | 15 - 30 mm/s |
| **Modo de alimentación** | Varilla eléctrica push-rod + tornillo de extrusión |
| **Materiales compatibles** | Arcilla, lodo cerámico, porcelana roja, materiales fluidos líquidos |
| **Firmware** | Marlin |
| **Pantalla** | TFT táctil a color de 3,5 pulgadas |
| **Conectividad** | Tarjeta TF (microSD) / memoria USB (U-disk) / cable USB |
| **Formatos de archivo** | .STL, .OBJ, .G-code |
| **Software de laminado compatible** | Cura, Simplify3D, PrusaSlicer v2.x+ |
| **Número de extrusores** | 1 |
| **Cama de impresión** | Plataforma rígida fija (sin calefacción) |
| **Fuente de alimentación** | Entrada: 100-240 V CA, 50/60 Hz; Salida: 24 V / 4 A CC |
| **Dimensiones de la máquina** | 355 × 252 × 370 mm |
| **Peso neto aproximado** | ~8 kg |
| **Estructura** | Todo en uno (all-in-one), preensamblada |
| **¿Requiere compresor de aire?** | No |
| **Cabezal de impresión** | Desmontable para limpieza |
| **Precio de referencia** | ~USD $466 - $699 |

---

## 3. Componentes y partes

### 3.1 Cuerpo principal y estructura

La Tronxy Moore 1 presenta una estructura compacta de tipo *all-in-one* donde todos los componentes mecánicos, electrónicos y el sistema de extrusión están integrados en una sola carcasa. El chasis está fabricado principalmente con perfiles de aluminio y paneles de plástico ABS, proporcionando rigidez y ligereza. Las guías lineales en los ejes X, Y y Z aseguran movimientos precisos, lo que es especialmente importante cuando se trabaja con arcilla, ya que cualquier vibración excesiva puede causar deformaciones en las paredes de la pieza. La base de la máquina es estable y cuenta con patas de goma antideslizantes que absorben micro-vibraciones durante la impresión.

### 3.2 Sistema de extrusión LDM

El corazón de la Moore 1 es su sistema de extrusión por deposición líquida. Este sistema se compone de los siguientes elementos:

- **Barril cilíndrico (cartridge/barrel):** Recipiente de aluminio donde se carga la arcilla preparada. Tiene una capacidad aproximada de 1 L de material. Se extrae con facilidad para su limpieza y recarga. Es fundamental que la arcilla se cargue sin burbujas de aire para evitar interrupciones durante la impresión.
- **Varilla eléctrica push-rod (electric push rod):** Un actuador lineal eléctrico que empuja un émbolo dentro del barril, generando la presión necesaria para que la arcilla fluya hacia la boquilla. Este sistema elimina la necesidad de un compresor de aire, simplificando la operación y reduciendo el ruido en el aula.
- **Tornillo de extrusión (screw extrusion):** Complementa la acción de la varilla push-rod, proporcionando un flujo más constante y controlado de material hacia la boquilla. El tornillo sinfín ayuda a homogeneizar la presión de extrusión y a evitar atascos.
- **Émbolo/pistón:** Pieza que se desplaza dentro del barril empujada por la varilla eléctrica, comprimiendo la arcilla contra la salida.

### 3.3 Cabezal de impresión y boquilla

El cabezal de impresión es desmontable, lo cual es una característica de diseño muy importante para una impresora de arcilla. La arcilla tiende a secarse y acumularse en la boquilla y en los conductos internos, por lo que la facilidad de desmontaje permite una limpieza exhaustiva después de cada sesión de trabajo. La boquilla estándar tiene un diámetro de 2,0 mm, pero se pueden instalar boquillas de 1,0 mm (para detalles más finos) hasta 3,0 mm (para impresión más rápida y piezas de mayor volumen). El cambio de boquilla requiere herramientas sencillas y unos minutos de trabajo.

### 3.4 Pantalla táctil TFT de 3,5 pulgadas

La interfaz de usuario se maneja a través de una pantalla táctil a color de 3,5 pulgadas ubicada en la parte frontal de la máquina. Desde ella se pueden controlar los tres ejes (X, Y, Z) de forma manual, nivelar la cama de impresión, iniciar y detener impresiones, ajustar la velocidad de impresión y la tasa de extrusión, cargar y descargar la arcilla, y acceder a la configuración del firmware Marlin. La pantalla es intuitiva y presenta iconos claros que facilitan la navegación incluso para estudiantes que no tienen experiencia previa con impresoras 3D.

### 3.5 Plataforma de impresión (cama)

La plataforma de impresión de la Moore 1 es una superficie rígida y plana que no cuenta con calefacción, ya que la arcilla no requiere una cama caliente para adherirse (de hecho, el calor podría acelerar el secado de la arcilla y causar grietas). La superficie es lisa y debe mantenerse limpia y nivelada para garantizar una correcta adhesión de la primera capa. Para mejorar la adherencia, se puede humedecer ligeramente la superficie con una esponja antes de iniciar la impresión.

### 3.6 Placa controladora y electrónica

La Moore 1 utiliza una placa controladora de 32 bits con firmware Marlin, lo que permite un control preciso de los motores paso a paso y del sistema de extrusión. La electrónica gestiona los movimientos de los ejes, la presión de extrusión, la temperatura del sistema (si aplica), y la comunicación con la pantalla táctil y los dispositivos de almacenamiento externo. La placa se encuentra protegida dentro de la carcasa de la máquina, pero es accesible si se necesita realizar mantenimiento o actualizaciones de firmware.

### 3.7 Puerto de alimentación y conexiones

En la parte posterior o lateral de la máquina se encuentran:
- **Conector de alimentación:** Entrada para el adaptador de corriente (100-240 V CA → 24 V / 4 A CC).
- **Puerto USB tipo B:** Para conexión directa a un computador y envío de comandos G-code en tiempo real.
- **Ranura para tarjeta TF (microSD):** Permite cargar archivos G-code directamente desde una tarjeta de memoria, sin necesidad de conectar un computador durante la impresión.
- **Puerto USB tipo A (U-disk):** Permite usar memorias USB para cargar archivos de impresión.

### 3.8 Accesorios incluidos de fábrica

- Cilindro/barril de arcilla
- Boquillas de repuesto (1,0 mm, 2,0 mm, 3,0 mm)
- Espátula y herramientas de limpieza
- Calibrador de láminas (feeler gauge) para nivelación
- Tarjeta TF con archivos de ejemplo
- Cable USB
- Adaptador de corriente
- Manual de usuario

---

## 4. Configuración y puesta en marcha

### 4.1 Desempaquetado e inspección

Al recibir las unidades de la Tronxy Moore 1, es importante realizar una inspección completa antes de la primera utilización. Dado que en el aula STEAM hay dos unidades, se recomienda etiquetar cada una como **Unidad 1** y **Unidad 2** para llevar un registro individualizado de uso y mantenimiento. Los pasos de inspección son los siguientes:

1. Retirar con cuidado la impresora del embalaje, verificando que no haya daños visibles en la estructura, los cables o los componentes mecánicos.
2. Confirmar la presencia de todos los accesorios listados en la sección 3.8: barril de arcilla, boquillas, herramientas de limpieza, tarjeta TF, cable USB, adaptador de corriente y manual.
3. Inspeccionar el barril de arcilla para asegurarse de que esté limpio y libre de residuos de fábrica.
4. Verificar que la pantalla táctil no tenga rayones ni defectos visibles.
5. Comprobar que los ejes se mueven libremente empujándolos suavemente con la mano (con la máquina apagada).
6. Registrar el número de serie de cada unidad en el inventario del aula.

### 4.2 Ubicación en el aula

La Moore 1 es una máquina diseñada para trabajar con arcilla húmeda, lo que implica que el área de trabajo se ensuciará inevitablemente. Al seleccionar la ubicación de las dos unidades en el aula STEAM, considere los siguientes criterios:

- Colocar las impresoras sobre mesas o superficies estables, resistentes al agua y fáciles de limpiar. Las mesas de trabajo con cubierta de acero inoxidable o plástico de alta densidad son ideales.
- Dejar al menos 20 cm de espacio libre alrededor de cada máquina para facilitar la ventilación y el acceso a los puertos posteriores.
- Ubicar las impresoras cerca de un tomacorriente accesible. Evitar el uso de extensiones múltiples o regletas sobrecargadas.
- Si es posible, colocar las impresoras cerca de un fregadero o área de lavado para facilitar la limpieza del barril, las boquillas y las herramientas después de cada sesión.
- Proteger la superficie de la mesa con un mantel de plástico o bandeja recolectora para capturar los goteos de arcilla.
- Mantener las impresoras alejadas de la luz solar directa y de fuentes de calor, ya que la arcilla se secaría prematuramente en el barril y en la boquilla.

### 4.3 Conexión eléctrica

1. Verificar que el interruptor de encendido (si lo hay) esté en posición OFF.
2. Conectar el adaptador de corriente al puerto de alimentación de la máquina.
3. Enchufar el adaptador a un tomacorriente con tensión de 100-240 V CA (compatible con la red eléctrica estándar en Colombia: 110 V CA, 60 Hz).
4. Encender la máquina. La pantalla táctil debería iluminarse y mostrar el menú principal de Marlin.

### 4.4 Nivelación de la cama

La nivelación de la cama es un paso crítico para la Moore 1, quizás aún más que en una impresora FDM convencional, porque la arcilla requiere una distancia precisa entre la boquilla y la superficie para que la primera capa se adhiera correctamente. Una boquilla demasiado alta producirá una primera capa que no se adherirá, y una boquilla demasiado baja obstruirá la salida de arcilla y puede dañar la plataforma. El procedimiento es el siguiente:

1. Desde la pantalla táctil, acceder al menú de nivelación (*Leveling* o *Bed Level*).
2. La máquina moverá el cabezal a las cuatro esquinas de la cama de forma secuencial.
3. En cada esquina, ajustar el tornillo de regulación correspondiente hasta que la distancia entre la boquilla y la superficie sea la correcta. Utilizar el calibrador de láminas incluido o el método del papel: deslizar una hoja de papel entre la boquilla y la cama; debe sentir una ligera resistencia pero el papel debe poder moverse sin rasgarse.
4. Repetir el proceso al menos dos veces, ya que ajustar una esquina puede afectar ligeramente las demás.
5. Confirmar la nivelación moviendo manualmente el cabezal a diferentes puntos de la cama y verificando la distancia con el papel.

> **Nota para el aula:** Se recomienda verificar la nivelación de la cama al inicio de cada sesión de trabajo, especialmente si la máquina fue movida o si se ha limpiado la plataforma recientemente.

### 4.5 Preparación de la arcilla

La preparación de la arcilla es posiblemente el paso más importante y delicado de todo el proceso. La consistencia de la arcilla determina en gran medida el éxito o fracaso de la impresión. Una arcilla demasiado espesa no fluirá adecuadamente por la boquilla y puede atascar el sistema; una arcilla demasiado líquida provocará que la pieza se desplome bajo su propio peso. El procedimiento recomendado es:

1. **Selección de arcilla:** Utilizar arcilla cerámica de calidad, preferiblemente de tipo *earthenware* (arcilla de alfarería) o *stoneware* (arcilla refractaria) con buena plasticidad. Evitar arcillas con partículas grandes o gruesas que puedan obstruir la boquilla.
2. **Hidratación:** Si se trabaja con arcilla seca en polvo, mezclarla con agua en una proporción aproximada de 2:1 (arcilla:agua en volumen) y dejar reposar de 2 a 3 horas hasta que la mezcla alcance una consistencia homogénea y suave, similar a la de una pasta densa o un puré espeso. Si se trabaja con arcilla húmeda preenvasada, puede ser necesario añadir un poco de agua para alcanzar la consistencia ideal.
3. **Amasado:** Amasar la arcilla vigorosamente con las manos o con una espátula para eliminar todas las burbujas de aire. Las burbujas de aire en la arcilla son el enemigo número uno de la impresión cerámica, ya que al pasar por la boquilla crean vacíos y discontinuidades en la pared de la pieza, lo que provoca roturas y deformaciones tanto durante la impresión como después de la cocción.
4. **Prueba de consistencia:** Una prueba sencilla es tomar un poco de arcilla con la mano y apretarla; debe mantener su forma sin desmoronarse ni escurrir agua. Si al golpear suavemente el recipiente la arcilla se nivela como un líquido, está demasiado líquida; si es difícil de mover con una espátula, está demasiado espesa.
5. **Tamizado (opcional pero recomendado):** Pasar la arcilla por un tamiz de malla fina para eliminar cualquier partícula grande o impureza que pueda obstruir la boquilla.

### 4.6 Carga de la arcilla en el barril

1. Retirar el barril cilíndrico de la máquina (generalmente se desliza o se gira para liberarlo).
2. Llenar el barril con la arcilla preparada, procurando no dejar espacios vacíos ni bolsas de aire. Una técnica eficaz es ir añadiendo la arcilla en capas pequeñas y presionar cada capa contra la anterior con una espátula antes de añadir la siguiente.
3. Una vez lleno el barril, insertar el émbolo por la parte superior y presionar firmemente para expulsar el aire atrapado. Es posible que algo de arcilla salga por la boquilla durante este proceso; esto es normal y deseable, ya que indica que el aire está siendo expulsado.
4. Volver a instalar el barril en la máquina, asegurándose de que quede firmemente acoplado.
5. Desde la pantalla táctil, usar la función de extrusión manual (*Extrude*) para verificar que la arcilla fluye de manera continua y uniforme por la boquilla. Si el flujo es intermitente o no sale material, puede haber una burbuja de aire o un atasco que debe resolverse antes de iniciar la impresión.

### 4.7 Instalación del software de laminado

La Moore 1 es compatible con los principales programas de laminado (*slicing*) del mercado. Para configurar Cura (el software más accesible y gratuito), siga estos pasos:

1. Descargar e instalar Ultimaker Cura desde [https://ultimaker.com/software/ultimaker-cura](https://ultimaker.com/software/ultimaker-cura).
2. Al abrir Cura por primera vez, añadir una impresora personalizada (*Custom Printer*) con las siguientes dimensiones: 180 × 180 × 180 mm.
3. Configurar el diámetro de la boquilla según la que esté instalada (2,0 mm por defecto).
4. Ajustar los parámetros de impresión específicos para arcilla (véase la sección 5 para detalles de configuración).
5. Para PrusaSlicer, seleccionar una impresora genérica FDM y modificar los parámetros de volumen de construcción y boquilla de manera similar.

> **Nota importante:** Los perfiles de laminado para arcilla difieren significativamente de los perfiles para plástico FDM. La velocidad de impresión debe ser más baja, el flujo de extrusión debe ajustarse empíricamente, y no se utilizan parámetros como temperatura del hotend o velocidad de retracción. Es recomendable guardar un perfil personalizado llamado "Moore1_Arcilla" una vez que se hayan encontrado los parámetros óptimos.

---

## 5. Guía de uso paso a paso

### 5.1 Diseño del modelo 3D

El primer paso en cualquier proyecto de impresión cerámica con la Moore 1 es diseñar o conseguir un modelo 3D adecuado. Se puede utilizar cualquier software de modelado 3D, como Tinkercad (ideal para principiantes), Fusion 360 (para diseño paramétrico), Blender (para formas orgánicas y artísticas) o SolidWorks (para ingeniería). Al diseñar para arcilla, se deben tener en cuenta las siguientes consideraciones específicas:

- **Paredes gruesas:** A diferencia del plástico FDM donde las paredes de 1,2 mm son comunes, la arcilla requiere paredes de al menos 3-5 mm de grosor para que la pieza tenga integridad estructural durante el secado y la cocción. Paredes demasiado delgadas se agrietarán o colapsarán.
- **Ángulos de sobrehang limitados:** La arcilla húmeda no puede sostener ángulos pronunciados sin soporte. Limitar los sobrehangs a un máximo de 30-40 grados respecto a la vertical. Para formas con voladizos mayores, considerar dividir el modelo en partes que se ensamblen después del secado.
- **Base amplia y estable:** Las piezas con base estrecha y centro de gravedad alto son propensas a volcarse durante la impresión. Diseñar con bases anchas y centros de gravedad bajos.
- **Evitar detalles muy finos:** Con una boquilla estándar de 2,0 mm, los detalles menores de 2 mm no se reproducirán con fidelidad. Los relieves y texturas deben ser proporcionales al diámetro de la boquilla.
- **Tener en cuenta la contracción:** La arcilla se contrae durante el secado (5-8%) y la cocción (8-12% adicional, dependiendo del tipo de arcilla). Escalar el modelo digital en un 15-20% para compensar la contracción total.

### 5.2 Exportación y preparación del archivo

1. Exportar el modelo 3D en formato .STL o .OBJ desde el software de diseño.
2. Abrir el archivo en el software de laminado (Cura o PrusaSlicer).
3. Posicionar el modelo en la plataforma virtual, preferiblemente centrado y con la cara más plana apoyada sobre la cama.

### 5.3 Configuración de parámetros de laminado para arcilla

Los siguientes parámetros son un punto de partida recomendado para imprimir con la boquilla estándar de 2,0 mm. Estos valores pueden requerir ajustes según la consistencia específica de la arcilla y el tipo de pieza:

| Parámetro | Valor recomendado |
|---|---|
| Altura de capa | 0,5 - 1,0 mm (iniciar con 0,5 mm) |
| Ancho de línea | 2,0 - 2,5 mm (1,0-1,25× el diámetro de boquilla) |
| Velocidad de impresión | 15 - 25 mm/s (iniciar con 20 mm/s) |
| Velocidad de la primera capa | 10 - 15 mm/s |
| Flujo de extrusión | 100 - 150% (ajustar empíricamente) |
| Temperatura del hotend | 0 °C (apagado, no se necesita calor) |
| Temperatura de la cama | 0 °C (apagado, no se necesita calor) |
| Retracción | Desactivada (la arcilla no permite retracción) |
| Enfriamiento | Desactivado (el ventilador puede secar la arcilla prematuramente) |
| Relleno | 0% (piezas huecas) o 5-10% para piezas que requieran soporte interno |
| Número de paredes | 2-3 perímetros |
| Soportes | Generalmente no necesarios; si se requieren, usar soportes de arcilla que se eliminen manualmente |
| Altura de la primera capa | 0,5 mm (igual o ligeramente menor que las capas superiores) |

### 5.4 Laminado y exportación del G-code

1. Una vez configurados los parámetros, hacer clic en *Slice* (Laminar) en Cura para generar el G-code.
2. Verificar la vista previa del laminado para confirmar que la trayectoria de la herramienta es correcta, que no hay movimientos cruzados innecesarios y que la primera capa cubre toda la base del modelo.
3. Exportar el archivo G-code a la tarjeta TF o a la memoria USB.
4. Insertar la tarjeta TF o memoria USB en el puerto correspondiente de la Moore 1.

### 5.5 Proceso de impresión

1. **Verificar la preparación:** Antes de iniciar la impresión, confirmar que la cama está nivelada, que la arcilla fluye correctamente por la boquilla (usando la extrusión manual) y que no hay burbujas de aire en el barril.
2. **Humedecer la cama:** Con una esponja ligeramente húmeda, pasar un paño sobre la superficie de la cama para crear una fina capa de humedad que ayude a la adhesión de la primera capa de arcilla. No empapar la superficie; solo humedecerla.
3. **Seleccionar el archivo:** Desde la pantalla táctil, navegar hasta el menú de archivos e seleccionar el archivo G-code correspondiente.
4. **Iniciar la impresión:** Pulsar *Start* o *Print* y la máquina comenzará el proceso. Observar la primera capa con atención: si la arcilla no se adhiere a la cama, pausar la impresión y ajustar la nivelación o el offset Z. Si la arcilla sale en exceso, reducir el flujo de extrusión.
5. **Monitoreo:** Durante la impresión, es aconsejable permanecer cerca de la máquina, especialmente en las primeras capas. La arcilla puede comportarse de manera impredecible si la consistencia no es la adecuada. Si se observan irregularidades, se puede pausar la impresión desde la pantalla táctil y hacer ajustes manuales (por ejemplo, limpiar la boquilla o ajustar el flujo).
6. **Finalización:** Una vez completada la impresión, la máquina detendrá automáticamente el extrusor y moverá el cabezal a la posición de reposo. Esperar unos minutos antes de manipular la pieza, ya que la arcilla húmeda es muy frágil y puede deformarse con facilidad.

### 5.6 Postprocesamiento de la pieza cerámica

El postprocesamiento es una parte integral del flujo de trabajo con la Moore 1 y distingue esta impresora de las impresoras FDM convencionales. Los pasos son:

1. **Secado natural:** Dejar la pieza impresa secar a temperatura ambiente, alejada de la luz solar directa y de corrientes de aire fuertes. El secado puede tardar de 24 horas a varios días dependiendo del tamaño y grosor de la pieza. No acelerar el secado con calor, ya que esto puede causar grietas.
2. **Alisado (opcional):** Mientras la pieza aún está húmeda o en estado *leather-hard* (cuando la arcilla ha perdido suficiente humedad para poder manipularse sin deformarse pero aún puede trabajarse), se puede alisar la superficie con una esponja húmeda, una espátula o los dedos para eliminar las líneas de capa visibles.
3. **Esmaltado:** Una vez que la pieza está completamente seca (estado *bone-dry*), aplicar esmalte cerámico según las instrucciones del fabricante del esmalte. El esmalte puede aplicarse por inmersión, pincelado o spraying.
4. **Cocción (horneado):** Introducir la pieza en un horno cerámico (kiln) y cocer según la curva de temperatura recomendada para el tipo de arcilla utilizado. Típicamente, las arcillas *earthenware* se cuecen a 950-1100 °C, y las *stoneware* a 1200-1300 °C. Si se ha aplicado esmalte, puede requerirse una segunda cocción a una temperatura ligeramente inferior.

### 5.7 Uso simultáneo de las dos unidades

Con dos unidades de la Moore 1 en el aula, se pueden implementar las siguientes estrategias de trabajo:

- **Impresión paralela:** Ambas unidades pueden imprimir simultáneamente, lo que permite que dos estudiantes o grupos trabajen en paralelo. Cada unidad debe tener su propia tarjeta TF con los archivos G-code correspondientes.
- **Diferenciación de boquillas:** Si se instalan boquillas de diferentes diámetros en cada unidad (por ejemplo, 1,5 mm en la Unidad 1 para detalles finos y 3,0 mm en la Unidad 2 para piezas grandes), se puede ofrecer más versatilidad sin necesidad de cambiar boquillas constantemente.
- **Materiales diferentes:** Si se trabaja con arcillas de diferentes colores o tipos, se puede asignar cada unidad a un material específico para evitar la contaminación cruzada y el tiempo de limpieza entre cambios.
- **Rotación de uso:** Si hay más de dos estudiantes que necesitan imprimir, establecer un sistema de turnos con tiempos definidos para cada uno.

---

## 6. Mantenimiento básico

### 6.1 Limpieza del barril de arcilla

La limpieza del barril es la tarea de mantenimiento más frecuente y más importante en la Moore 1. La arcilla residual que queda en el barril y en los conductos después de una sesión de impresión se secará y endurecerá, causando atascos y contaminando el siguiente lote de arcilla. El procedimiento de limpieza recomendado es:

1. Retirar el barril de la máquina inmediatamente después de cada sesión de uso.
2. Extraer la arcilla sobrante con una espátula de plástico o madera (nunca metálica, para no rayar las paredes del barril).
3. Enjuagar el barril con agua tibia, utilizando una esponja suave o un cepillo de cerdas suaves para eliminar los residuos.
4. Si la arcilla se ha secado y endurecido, remojar el barril en agua durante 30-60 minutos antes de limpiarlo.
5. Secar completamente el barril antes de guardarlo o recargarlo. El aluminio puede oxidarse si se almacena húmedo durante períodos prolongados.
6. Limpiar también el émbolo y las roscas de fijación del barril.

### 6.2 Limpieza de la boquilla

La boquilla debe limpiarse después de cada sesión de impresión para evitar que la arcilla se seque en su interior:

1. Con la máquina apagada y desconectada, retirar la boquilla del cabezal (generalmente se desenrosca con una llave adecuada).
2. Enjuagar la boquilla con agua tibia y usar un alambre o aguja de limpieza para desobstruir el conducto interno.
3. Si la arcilla está muy endurecida, remojar la boquilla en agua durante 15-30 minutos.
4. Para una limpieza profunda, se puede usar una solución de agua con vinagre blanco (proporción 10:1) para disolver los depósitos minerales de la arcilla.
5. Secar completamente antes de reinstalar.

### 6.3 Limpieza del cabezal de impresión

1. Desmontar el cabezal según las instrucciones del manual del fabricante.
2. Limpiar cualquier residuo de arcilla en las superficies de contacto y en los conductos internos con agua tibia y un cepillo suave.
3. Verificar que no haya partículas de arcilla seca en las roscas de fijación de la boquilla.
4. Volver a montar el cabezal y asegurar todas las conexiones.

### 6.4 Lubricación de guías lineales

Las guías lineales de los ejes X, Y y Z deben lubricarse periódicamente para garantizar un movimiento suave y preciso:

1. Utilizar grasa de litio o aceite de máquina de costura (no usar WD-40, ya que es un desplazador de humedad, no un lubricante permanente).
2. Aplicar una pequeña cantidad de lubricante en las varillas y desplazar los ejes manualmente varias veces para distribuirlo de manera uniforme.
3. Limpiar el exceso de lubricante con un paño limpio.
4. Frecuencia recomendada: cada 2-4 semanas de uso regular, o cada 50 horas de impresión.

### 6.5 Verificación de correas

Aunque la Moore 1 no utiliza correas en el mismo sentido que una impresora FDM tradicional (ya que emplea varilla push-rod para la extrusión), los ejes X e Y sí pueden tener correas o sistemas de transmisión. Verificar periódicamente:

- Que las correas no estén flojas ni excesivamente tensas.
- Que no haya desgaste visible en los dientes de las correas.
- Que las poleas estén firmemente fijadas a los ejes de los motores.

### 6.6 Actualización de firmware

El firmware Marlin de la Moore 1 puede actualizarse para corregir errores, mejorar la funcionalidad o agregar nuevas características. Para actualizar el firmware:

1. Descargar la última versión del firmware desde la página oficial de Tronxy o desde la comunidad de usuarios.
2. Copiar el archivo de firmware a una tarjeta TF.
3. Insertar la tarjeta TF en la máquina con la alimentación desconectada.
4. Encender la máquina mientras se mantiene presionado el botón de reset (si aplica) o seguir las instrucciones específicas de la versión de firmware.
5. Esperar a que la pantalla muestre el mensaje de actualización completada.

> **Precaución:** No apagar la máquina durante una actualización de firmware, ya que esto podría dejar la controladora inoperativa. Siempre verificar que la fuente de alimentación esté estable antes de iniciar una actualización.

### 6.7 Programa de mantenimiento preventivo

| Tarea | Frecuencia |
|---|---|
| Limpieza del barril y la boquilla | Después de cada sesión de uso |
| Limpieza del cabezal | Semanal o después de cada sesión prolongada |
| Limpieza de la plataforma de impresión | Después de cada pieza impresa |
| Verificación de nivelación de la cama | Al inicio de cada sesión |
| Lubricación de guías lineales | Cada 2-4 semanas / 50 horas |
| Inspección de correas y poleas | Mensualmente |
| Limpieza general de la máquina | Semanalmente |
| Actualización de firmware | Según disponibilidad de actualizaciones |
| Inspección de cables y conexiones | Mensualmente |

---

## 7. Solución de problemas comunes

### 7.1 La arcilla no fluye por la boquilla

**Causas posibles:**
- Burbuja de aire en el barril que impide la transmisión de presión.
- Arcilla demasiado espesa o seca.
- Boquilla obstruida con arcilla seca o partículas grandes.
- El sistema push-rod o el tornillo de extrusión no están activados o configurados correctamente.
- El émbolo no está bien posicionado dentro del barril.

**Soluciones:**
- Expulsar la arcilla manualmente desde la pantalla táctil (*Extrude*) para verificar que el sistema de presión funciona. Si la arcilla no sale, desmontar el barril y verificar que no haya burbujas de aire.
- Añadir agua a la arcilla en el barril (con cuidado, en pequeñas cantidades) y amasar para redistribuir la humedad.
- Desmontar y limpiar la boquilla con agua tibia y un alambre de limpieza.
- Verificar en la pantalla táctil que tanto el motor de extrusión como el tornillo sinfín estén habilitados y configurados correctamente. En la comunidad de usuarios se ha reportado que a veces solo está activado el motor sin el tornillo de extrusión.
- Volver a insertar el émbolo asegurándose de que esté en contacto directo con la arcilla, sin espacio de aire entre ellos.

### 7.2 La primera capa no se adhiere a la cama

**Causas posibles:**
- La boquilla está demasiado alta respecto a la cama (offset Z incorrecto).
- La cama no está nivelada.
- La superficie de la cama está sucia o seca.
- La arcilla es demasiado líquida y no mantiene la forma.

**Soluciones:**
- Ajustar el offset Z para reducir la distancia entre la boquilla y la cama. Usar el método del papel: la hoja debe sentir una ligera resistencia.
- Repetir el proceso de nivelación de la cama (sección 4.4).
- Humedecer ligeramente la superficie de la cama con una esponja antes de imprimir.
- Si la arcilla está demasiado líquida, dejarla reposar un tiempo para que pierda algo de humedad, o mezclar con arcilla más seca.

### 7.3 Las paredes de la pieza se desploman o colapsan

**Causas posibles:**
- Arcilla demasiado líquida que no tiene suficiente rigidez para sostener las capas superiores.
- Velocidad de impresión demasiado alta.
- Altura de capa excesiva.
- Pieza con paredes demasiado delgadas.

**Soluciones:**
- Dejar que la arcilla repose para que se espese ligeramente, o mezclar con arcilla más seca.
- Reducir la velocidad de impresión a 10-15 mm/s.
- Reducir la altura de capa a 0,5 mm o menos.
- Aumentar el grosor de las paredes en el modelo 3D a un mínimo de 3-5 mm.
- Considerar imprimir la pieza en dos o más partes y ensamblarlas después.

### 7.4 Aparecen grietas en la pieza durante el secado

**Causas posibles:**
- Secado demasiado rápido (exposición al sol, corriente de aire, calor).
- Paredes de grosor desigual que se secan a diferentes velocidades.
- Arcilla con bolsas de aire que crean puntos débiles.
- Contracción diferencial entre el interior y el exterior de la pieza.

**Soluciones:**
- Secar la pieza lentamente a temperatura ambiente, cubriéndola con una bolsa de plástico perforada para ralentizar la evaporación.
- Diseñar piezas con paredes de grosor uniforme.
- Asegurar un amasado exhaustivo de la arcilla para eliminar todas las burbujas de aire.
- Para piezas grandes o de paredes gruesas, envolver en plástico y dejar secar durante varios días, destapando gradualmente.

### 7.5 La pieza se deforma o se inclina durante la impresión

**Causas posibles:**
- La pieza tiene un centro de gravedad alto y una base estrecha.
- La primera capa no se adhirió correctamente a la cama.
- Vibración excesiva de la máquina durante la impresión.
- La mesa o superficie de apoyo no es estable.

**Soluciones:**
- Rediseñar la pieza con una base más amplia o añadir una base auxiliar (*raft*) en el laminador.
- Verificar la adherencia de la primera capa (ver problema 7.2).
- Asegurar que la máquina esté sobre una superficie estable y que las patas antideslizantes estén en buen estado.
- Reducir la velocidad de impresión.

### 7.6 El motor se detiene pero la boquilla sigue liberando arcilla

**Causas posibles:**
- Presión residual en el barril después de que el motor se detiene.
- El tornillo de extrusión no está sincronizado con el motor de la varilla push-rod.
- Configuración incorrecta del firmware para el sistema de extrusión dual.

**Soluciones:**
- Este es un problema conocido de la Moore 1 que se ha reportado en la comunidad de usuarios. La solución es asegurarse de que el firmware tenga configurado correctamente el sistema de extrusión dual (varilla push-rod + tornillo sinfín).
- Verificar en la configuración de Marlin que los parámetros de extrusión para ambos sistemas estén correctos.
- Si el problema persiste, buscar actualizaciones de firmware en la comunidad o en la página oficial de Tronxy.

### 7.7 La pantalla táctil no responde o se queda en blanco

**Causas posibles:**
- Cable de la pantalla suelto o mal conectado.
- Archivo de firmware corrupto en la tarjeta TF.
- Fallo de la placa controladora.

**Soluciones:**
- Verificar la conexión del cable de la pantalla a la placa controladora.
- Retirar la tarjeta TF y reiniciar la máquina.
- Si el problema persiste, flashear el firmware con una versión conocida y estable.
- Contactar al soporte técnico de Tronxy si la pantalla sigue sin responder.

### 7.8 Atasco severo en el sistema de extrusión

**Causas posibles:**
- Arcilla muy seca o con partículas grandes.
- Acumulación de arcilla seca en el conducto entre el barril y la boquilla.
- Piezas del sistema de extrusión desalineadas.

**Soluciones:**
- Desmontar completamente el sistema de extrusión: barril, cabezal y boquilla.
- Remojar todas las piezas en agua tibia durante 30-60 minutos.
- Usar un alambre rígido o una varilla de limpieza para desobstruir los conductos.
- Limpiar con una solución de agua con vinagre si hay depósitos minerales.
- Volver a montar verificando que todas las piezas estén correctamente alineadas.
- Cargar arcilla fresca y bien preparada, asegurándose de eliminar todas las burbujas.

---

## 8. Materiales, repuestos y accesorios

### 8.1 Materiales de impresión compatibles

La Tronxy Moore 1 trabaja exclusivamente con materiales viscosos y fluidos, no con filamentos sólidos de plástico. Los materiales principales son:

| Material | Descripción | Uso recomendado |
|---|---|---|
| **Arcilla de alfarería (earthenware)** | Arcilla roja o marrón, de baja temperatura de cocción (950-1100 °C). Es la más fácil de trabajar y la más adecuada para principiantes. | Piezas decorativas, macetas, objetos de uso diario |
| **Arcilla refractaria (stoneware)** | Arcilla gris o beige, de alta temperatura de cocción (1200-1300 °C). Más resistente y duradera tras la cocción. | Vajilla, piezas funcionales, escultura |
| **Porcelana roja** | Arcilla de porcelana con tonalidad rojiza, de alta temperatura de cocción. Produce piezas muy densas y resistentes. | Piezas de alta calidad, objetos decorativos finos |
| **Lodo cerámico (ceramics slurry)** | Mezcla de arcilla con alta proporción de agua, de consistencia más líquida. Requiere ajustes en la velocidad y el flujo. | Piezas de paredes muy delgadas, efectos decorativos |
| **Materiales fluidos experimentales** | Otros materiales viscosos como chocolate, masa de galletas, puré de papas, etc. (uso experimental). | Proyectos STEAM interdisciplinarios, experimentación |

### 8.2 Preparación y almacenamiento de la arcilla

- **Almacenamiento:** La arcilla húmeda debe almacenarse en recipientes herméticos (bolsas de plástico con cierre hermético o contenedores con tapa) para evitar que se seque. Si la arcilla se seca, puede rehidratarse añadiendo agua y amasando, pero el proceso es lento y la consistencia resultante puede no ser tan homogénea.
- **Tiempo de vida:** La arcilla húmeda almacenada correctamente puede durar varias semanas o meses. Si aparece moho en la superficie, retirar la capa afectada; la arcilla debajo sigue siendo utilizable (el moho puede incluso mejorar la plasticidad de algunas arcillas).
- **Preparación el día anterior:** Para una sesión de impresión programada, se recomienda preparar la arcilla el día anterior, dejándola reposar toda la noche en un recipiente hermético para que la humedad se distribuya de manera uniforme.

### 8.3 Boquillas de repuesto

Las boquillas son consumibles que eventualmente se desgastan o se dañan y necesitan ser reemplazadas. Se recomienda tener un stock de boquillas de cada diámetro disponible:

| Diámetro de boquilla | Uso | Vida útil estimada |
|---|---|---|
| 1,0 mm | Detalles finos, texto pequeño, ornamentación | 50-100 horas de impresión |
| 1,5 mm | Piezas de tamaño medio con buen nivel de detalle | 80-150 horas de impresión |
| 2,0 mm (estándar) | Uso general, equilibrio entre detalle y velocidad | 100-200 horas de impresión |
| 3,0 mm | Piezas grandes, impresión rápida, paredes gruesas | 150-300 horas de impresión |

### 8.4 Otros repuestos y consumibles

- **Émbolo/pistón de repuesto:** Se desgasta con el uso y puede necesitar reemplazo si pierde el sello hermético con las paredes del barril.
- **Tarjetas TF (microSD):** Tener varias tarjetas de repuesto, preferiblemente de capacidad de 8-32 GB y clase 10.
- **Cables USB tipo B:** Para conexión a computador.
- **Adaptador de corriente de repuesto:** 24 V / 4 A CC.
- **Calibrador de láminas (feeler gauge):** Para la nivelación precisa de la cama.
- **Herramientas de limpieza:** Espátulas de plástico, cepillos de cerdas suaves, alambres de limpieza para boquillas, esponjas.

### 8.5 Accesorios complementarios recomendados para el aula

- **Horno cerámico (kiln):** Necesario para la cocción de las piezas. Un horno de mesa de 120 V con capacidad de 10-15 L es adecuado para piezas del tamaño máximo de la Moore 1.
- **Esmaltes cerámicos:** Conjunto básico de esmaltes de diferentes colores para decoración.
- **Set de herramientas de alfarería:** Cinceles, bucles, esponjas, alambres de corte.
- **Báscula digital:** Para pesar las proporciones de arcilla y agua con precisión.
- **Tamiz de malla fina:** Para filtrar la arcilla antes de cargarla en el barril.
- **Contenedores herméticos:** Para almacenar arcilla preparada y sobrantes.
- **Delantales y guantes:** Para proteger la ropa de los estudiantes durante la manipulación de arcilla.

---

## 9. Normas de uso STEAM

### 9.1 Normas generales de seguridad

La Tronxy Moore 1 es una máquina relativamente segura en comparación con las impresoras FDM convencionales, ya que no tiene piezas a alta temperatura (hotend o cama caliente). Sin embargo, existen riesgos que deben ser gestionados en un entorno educativo:

- **Mecanismos de movimiento:** Los ejes X, Y y Z se mueven durante la impresión y pueden atrapar dedos, cabello suelto, ropa o joyas. Mantener las manos alejadas de las áreas de movimiento durante la operación. Recoger el cabello largo y evitar usar mangas anchas o collares cerca de la máquina.
- **Electricidad:** La máquina funciona con 24 V CC, pero el adaptador de corriente está conectado a la red eléctrica de 110 V CA. No manipular los cables o el adaptador con las manos mojadas. Desconectar la máquina antes de realizar cualquier mantenimiento interno.
- **Arcilla y agua:** El trabajo con arcilla implica el uso de agua y materiales húmedos. Las superficies alrededor de la máquina pueden volverse resbaladizas. Limpiar los derrames inmediatamente y mantener el área de trabajo seca y ordenada.
- **Polvo de arcilla:** La arcilla seca puede generar polvo fino que es perjudicial si se inhala en grandes cantidades. Evitar agitar o cepillar arcilla seca en espacios cerrados. Si es necesario lijar piezas secas, hacerlo al aire libre o con mascarilla de protección.

### 9.2 Protocolo de uso por sesiones

Para asegurar un uso ordenado y eficiente de las dos unidades en el aula, se establece el siguiente protocolo:

1. **Reserva:** Cada estudiante o grupo debe reservar un bloque de tiempo con la Moore 1 a través del sistema de reservas del aula (pizarra, hoja de cálculo o aplicación).
2. **Preparación previa:** Antes de la sesión, el estudiante debe tener listo su archivo G-code en la tarjeta TF y haber preparado la arcilla según las instrucciones de la sección 4.5.
3. **Chequeo inicial:** Al inicio de la sesión, verificar la nivelación de la cama, la limpieza del barril y la boquilla, y el estado general de la máquina. Reportar cualquier anomalía al coordinador del aula.
4. **Impresión:** Seguir los pasos descritos en la sección 5. Permanecer junto a la máquina durante al menos las primeras 3 capas para verificar la correcta adherencia.
5. **Limpieza final:** Al terminar la sesión, limpiar el barril, la boquilla y la plataforma de impresión según las instrucciones de la sección 6. Guardar la arcilla sobrante en un recipiente hermético.
6. **Registro:** Anotar en el registro del aula la fecha, el usuario, la unidad utilizada, el tiempo de impresión y cualquier incidencia.

### 9.3 Integración curricular STEAM

La Tronxy Moore 1 ofrece oportunidades únicas de integración interdisciplinaria en el aula STEAM:

**Ciencia (Science):**
- Estudio de las propiedades reológicas de la arcilla: viscosidad, plasticidad, contracción durante el secado y la cocción.
- Análisis de las transformaciones fisicoquímicas de la arcilla durante la cocción (deshidratación, descomposición de minerales, sinterización, vitrificación).
- Experimentación con diferentes formulaciones de arcilla y sus efectos en la impresión y en las propiedades del producto final.

**Tecnología (Technology):**
- Programación de G-code y comprensión de los comandos de control numérico computarizado (CNC).
- Uso de software de modelado 3D y laminado.
- Exploración del sistema de extrusión LDM y comparación con la tecnología FDM.
- Actualización y personalización del firmware Marlin.

**Ingeniería (Engineering):**
- Diseño paramétrico de piezas cerámicas con consideraciones de fabricabilidad.
- Optimización de parámetros de impresión (velocidad, flujo, altura de capa) mediante metodología de diseño experimental.
- Análisis de fallos y mejora iterativa de procesos.
- Estudio de la mecánica del sistema push-rod y tornillo de extrusión.

**Arte (Art):**
- Creación de esculturas, vasijas y objetos decorativos combinando técnicas digitales y tradicionales.
- Exploración de la estética de las líneas de capa y la textura impresa como recurso expresivo.
- Esmaltado y decoración cerámica.
- Experimentación con formas orgánicas y geométricas que serían imposibles o muy difíciles de realizar a mano.

**Matemáticas (Mathematics):**
- Cálculo de volúmenes, superficies y proporciones para el escalado de modelos (compensación de contracción).
- Geometría de las trayectorias de impresión y optimización de recorridos.
- Análisis estadístico de los resultados de impresión (tasa de éxito, variabilidad dimensional).
- Modelado de curvas de contracción en función de la humedad y la temperatura de cocción.

### 9.4 Proyectos STEAM sugeridos

1. **Vajilla personalizada:** Cada estudiante diseña e imprime una taza, plato o tazón con un motivo personal, integrando diseño 3D, impresión cerámica y técnicas de esmaltado.
2. **Mosaico cerámico colaborativo:** El grupo diseña un mosaico compuesto por múltiples piezas impresas que se ensamblan tras la cocción, explorando conceptos de partición espacial y diseño modular.
3. **Macetas con estructura interna optimizada:** Diseñar macetas con paredes internas que optimicen la retención de agua y el drenaje, combinando ingeniería de fluidos con diseño de productos.
4. **Réplicas de artefactos arqueológicos:** Utilizar escaneo 3D o modelado para recrear piezas cerámicas de culturas antiguas, integrando historia, antropología y tecnología.
5. **Sistemas de riego por capilaridad:** Diseñar e imprimir sistemas de arcilla porosa que permitan el riego lento de plantas, explorando principios de física de fluidos y sostenibilidad.
6. **Ladrillos cerámicos estructurales:** Imprimir ladrillos con geometrías internas novedosas (rejillas, celosías, estructuras tipo panal) y someterlos a pruebas de resistencia mecánica.

### 9.5 Normas de convivencia y trabajo en equipo

- Respetar los turnos de uso de las impresoras y los tiempos asignados.
- Compartir los hallazgos sobre parámetros de impresión con el resto del grupo (la arcilla puede variar entre lotes y las ajustes óptimos pueden cambiar).
- Colaborar en las tareas de limpieza y mantenimiento, ya que son esenciales para el funcionamiento continuo de las máquinas.
- No forzar los mecanismos de la máquina. Si algo no funciona correctamente, reportarlo al coordinador en lugar de intentar repararlo por cuenta propia.
- Documentar los proyectos (fotografías, notas de parámetros, resultados) para crear una base de conocimiento compartida del aula.

---

## 10. Enlaces y recursos adicionales

### 10.1 Sitios oficiales

- **Tronxy 3D Printers Official Store:** [https://www.tronxy3d.com/](https://www.tronxy3d.com/)
- **Página del producto Moore 1:** [https://www.tronxy3d.com/products/tronxy-moore-1-mini-clay-3d-printer](https://www.tronxy3d.com/products/tronxy-moore-1-mini-clay-3d-printer)
- **Manual oficial Moore Series:** [https://www.tronxy3d.com/pages/moore-series-moore-series-manual](https://www.tronxy3d.com/pages/moore-series-moore-series-manual)
- **Blog de Tronxy - Impresión cerámica:** [https://www.tronxy3d.com/blogs/news-center/3d-printing-ceramics-and-potteries-with-clay](https://www.tronxy3d.com/blogs/news-center/3d-printing-ceramics-and-potteries-with-clay)

### 10.2 Software

- **Ultimaker Cura:** [https://ultimaker.com/software/ultimaker-cura](https://ultimaker.com/software/ultimaker-cura)
- **PrusaSlicer:** [https://www.prusa3d.com/prusaslicer/](https://www.prusa3d.com/prusaslicer/)
- **Simplify3D:** [https://www.simplify3d.com/](https://www.simplify3d.com/)
- **Tinkercad (modelado 3D para principiantes):** [https://www.tinkercad.com/](https://www.tinkercad.com/)
- **Fusion 360 (diseño paramétrico):** [https://www.autodesk.com/products/fusion-360/](https://www.autodesk.com/products/fusion-360/)
- **Blender (modelado 3D avanzado):** [https://www.blender.org/](https://www.blender.org/)

### 10.3 Recursos de la comunidad

- **Reddit - Ceramic3Dprinting:** [https://www.reddit.com/r/Ceramic3Dprinting/](https://www.reddit.com/r/Ceramic3Dprinting/) (Comunidad activa con discusiones sobre la Moore 1 y otras impresoras de arcilla)
- **Tronxy Facebook Group:** Grupo oficial de usuarios de Tronxy en Facebook, con soporte comunitario y compartición de experiencias.
- **How Open Is This Gadget - Tronxy Moore 1 Review:** [https://HOITG.de/s048.htm](https://HOITG.de/s048.htm) (Revisión detallada de la Moore 1 con análisis de hardware y software)

### 10.4 Videos tutoriales y revisiones

- **"Printing in Clay With The Tronxy Moore 1" - YouTube:** [https://www.youtube.com/watch?v=ybUdVSQsNKQ](https://www.youtube.com/watch?v=ybUdVSQsNKQ) (Video de revisión completa del proceso de impresión con arcilla)
- **"Tronxy Moore 1 Clay 3D Printer: Pottery-making" - YouTube:** [https://www.youtube.com/watch?v=cVLFPKo4eEM](https://www.youtube.com/watch?v=cVLFPKo4eEM) (Video de Aurora Tech Channel demostrando la Moore 1)
- **"MOORE 1 Clay 3D printer: How to process the mud and leveling?" - YouTube:** [https://www.youtube.com/watch?v=IYRInfoaT5o](https://www.youtube.com/watch?v=IYRInfoaT5o) (Tutorial oficial de Tronxy sobre preparación de arcilla y nivelación)
- **"Review of the Tronxy Moore 1" - YouTube:** [https://www.youtube.com/watch?v=eyYPE1zEsVU](https://www.youtube.com/watch?v=eyYPE1zEsVU) (Revisión técnica detallada)
- **Playlist oficial "Moore Clay 3D Printer series":** [https://www.youtube.com/playlist?list=PLLZdP2vPsengt9rONyOQ8hOViYmtlDXDi](https://www.youtube.com/playlist?list=PLLZdP2vPsengt9rONyOQ8hOViYmtlDXDi)

### 10.5 Firmware y recursos técnicos

- **Búsqueda de firmware Tronxy Moore 1 en Reddit:** [https://www.reddit.com/r/Ceramic3Dprinting/comments/1b1g3fs/](https://www.reddit.com/r/Ceramic3Dprinting/comments/1b1g3fs/) (Discusión sobre firmware y modificaciones)
- **Marlin Firmware (oficial):** [https://marlinfw.org/](https://marlinfw.org/) (Documentación del firmware utilizado por la Moore 1)
- **Tronxy FAQ:** [https://www.tronxy3d.com/pages/faq](https://www.tronxy3d.com/pages/faq) (Preguntas frecuentes oficiales)

### 10.6 Proveedores de materiales y repuestos

- **Filament2Print (distribuidor europeo):** [https://filament2print.com/en/lam/2603-tronxy-moore-1-clayceramic-3d-printer.html](https://filament2print.com/en/lam/2603-tronxy-moore-1-clayceramic-3d-printer.html)
- **Arrowti3D (distribuidor colombiano):** [https://arrowti3d.com/impresora-3d-tronxy-moore-1-arcilla](https://arrowti3d.com/impresora-3d-tronxy-moore-1-arcilla)
- **Tronxy Online Store:** [https://www.tronxyonline.com/](https://www.tronxyonline.com/)

### 10.7 Recursos sobre cerámica y alfarería

- **Ceramic Arts Network:** [https://ceramicartsnetwork.org/](https://ceramicartsnetwork.org/) (Recursos educativos sobre técnicas cerámicas)
- **The American Ceramic Society:** [https://ceramics.org/](https://ceramics.org/) (Sociedad científica sobre cerámica)
- **Guía de esmaltes cerámicos (Digitalfire):** [https://digitalfire.com/](https://digitalfire.com/) (Base de datos de esmaltes y materiales cerámicos)

---

*Manual elaborado para el Aula STEAM. Basado en especificaciones oficiales de Tronxy, documentación de la comunidad de usuarios y experiencia práctica con la impresora de arcilla Moore 1.*
