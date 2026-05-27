# Manual de Equipo STEAM — Impresora 3D Creality Ender-3 S1

> **Aula STEAM · Manual de referencia para estudiantes y asistente robot**
> Última actualización: mayo 2026
> **Unidades en el aula: 2** (Una de ellas equipada con funda cerrada para retención de calor)

---

## 1. Descripción general

La **Creality Ender-3 S1** es una impresora 3D de escritorio tipo FDM (Fused Deposition Modeling, modelado por deposición fundida) fabricada por Creality 3D, una de las empresas líderes en el mercado de impresión 3D a nivel mundial. Lanzada a principios de 2022 como una evolución significativa de la exitosa línea Ender-3, la S1 incorporó de serie una serie de mejoras que la comunidad de usuarios llevaba tiempo demandando: un extrusor directo de doble engranaje denominado "Sprite", un sensor de auto-nivelación de cama CR Touch, doble husillo en el eje Z para mayor estabilidad, una placa base de 32 bits silenciosa y una superficie de impresión extraíble de acero con recubrimiento de policarbonato (PC). Todas estas características, que en modelos anteriores requerían modificaciones y compras adicionales por parte del usuario, vienen integradas de fábrica en la Ender-3 S1, lo que la convierte en una de las impresoras de entrada más completas del mercado.

El extrusor directo Sprite es posiblemente la mejora más notable respecto a las generaciones anteriores de la familia Ender-3. A diferencia del sistema Bowden utilizado en la Ender-3, Ender-3 V2 y Ender-3 Pro, donde el motor del extrusor está montado en el chasis y el filamento viaja a través de un tubo de PTFE hasta el hotend, el Sprite sitúa el motor de extrusión directamente sobre el bloque calefactor. Esta configuración reduce drásticamente la distancia entre el mecanismo de empuje y la boquilla, lo que se traduce en una alimentación de filamento más precisa y controlada, especialmente importante para filamentos flexibles como el TPU. El sistema de doble engranaje del Sprite proporciona una fuerza de extrusión de hasta 80 N, suficiente para empujar filamento a través de boquillas con restricciones sin que se produzcan deslizamientos ni sub-extrusión. El extrusor Sprite de la Ender-3 S1 base utiliza una carcasa de plástico y soporta temperaturas de boquilla de hasta 260 °C (a diferencia del Sprite Pro, de carcasa metálica y 300 °C, presente en la Ender-3 S1 Pro).

El sensor de auto-nivelación CR Touch representa otra mejora fundamental. Este dispositivo utiliza una sonda metálica que se extiende físicamente para tocar la superficie de la cama en múltiples puntos, compensando automáticamente las irregularidades de la superficie de impresión mediante la creación de una malla de compensación que ajusta la altura de la boquilla en tiempo real durante la impresión. A diferencia del sistema BLTouch que utiliza un pin magnético, el CR Touch emplea un pin mecánico de mayor durabilidad y precisión (≤ 0,04 mm de repetibilidad), lo que resulta en un nivelación más consistente y fiable. Esto es especialmente valioso en un entorno educativo como el aula STEAM, donde la cama puede sufrir desajustes por el uso frecuente y la manipulación constante de las piezas impresas.

En el contexto del aula STEAM, el salón cuenta con **dos unidades de la Creality Ender-3 S1**. Esta configuración dual permite que dos estudiantes o grupos de trabajo puedan imprimir simultáneamente, duplicando la capacidad de producción del laboratorio y reduciendo los tiempos de espera en proyectos que requieren múltiples piezas. Además, una de las dos unidades está equipada con una **funda cerrada (enclosure)** que rodea la estructura de la impresora para impedir la salida de calor, creando un ambiente térmico controlado alrededor del volumen de impresión. Esta funda resulta esencial para trabajar con filamentos que requieren temperaturas de cama elevadas o que son susceptibles al alabeo por cambios bruscos de temperatura, como el ABS, el ASA y, en ciertas condiciones, el PETG. La otra unidad opera sin funda, siendo ideal para filamentos de fácil impresión como PLA y TPU, que no requieren un entorno cerrado y de hecho se benefician de una mayor ventilación para disipar el calor.

---

## 2. Especificaciones técnicas

### 2.1 Información del producto

| Parámetro | Valor |
|---|---|
| **Producto** | Creality Ender-3 S1 |
| **Fabricante** | Creality 3D Technology Co., Ltd. |
| **Tipo de impresora** | FDM (Fused Deposition Modeling) |
| **Año de lanzamiento** | 2022 |
| **Peso neto** | Aprox. 7,8 kg |
| **Peso bruto (con embalaje)** | Aprox. 10,2 kg |
| **Dimensiones de la máquina** | 487 × 453 × 622 mm |
| **Dimensiones del embalaje** | Aprox. 510 × 510 × 305 mm |

### 2.2 Parámetros de impresión

| Parámetro | Valor |
|---|---|
| **Volumen de impresión** | 220 × 220 × 270 mm (X × Y × Z) |
| **Altura de capa** | 0,05 – 0,35 mm |
| **Precisión de impresión** | ± 0,1 mm |
| **Velocidad máxima de impresión** | Hasta 150 mm/s |
| **Velocidad recomendada** | 40 – 80 mm/s |
| **Diámetro de filamento** | 1,75 mm |
| **Diámetro de boquilla** | 0,4 mm (predeterminada; compatible con 0,2 / 0,3 / 0,6 mm) |

### 2.3 Temperaturas

| Parámetro | Valor |
|---|---|
| **Temperatura máxima de boquilla** | 260 °C |
| **Temperatura máxima de cama caliente** | 100 °C |
| **Temperatura ambiente operativa** | 10 – 35 °C (recomendada) |

### 2.4 Extrusor y sistema de alimentación

| Parámetro | Valor |
|---|---|
| **Tipo de extrusor** | "Sprite" directo de doble engranaje (direct drive) |
| **Material de la carcasa del extrusor** | Plástico (PC+ABS) |
| **Fuerza de extrusión** | Hasta 80 N |
| **Distancia de retracción recomendada** | 0,8 – 1,5 mm (por el extrusor directo) |
| **Compatible con filamento flexible** | Sí (TPU recomendado 95A) |

### 2.5 Nivelación de cama

| Parámetro | Valor |
|---|---|
| **Sistema de auto-nivelación** | CR Touch (sonda mecánica) |
| **Precisión del sensor** | ≤ 0,04 mm (repetibilidad) |
| **Puntos de sondeo** | Configurable (predeterminado: 16 puntos, 4 × 4) |
| **Compensación en tiempo real** | Sí (malla de compensación UBL/Bilinear) |

### 2.6 Electrónica y pantalla

| Parámetro | Valor |
|---|---|
| **Placa base** | 32 bits silenciosa (Creality v4.2.2 o v4.2.7, procesador ARM Cortex-M3) |
| **Pantalla** | 4,3 pulgadas, LCD a color con control por perilla rotativa |
| **Interfaz de pantalla** | Menú gráfico con selección por rotación y pulsación |
| **Idiomas de la interfaz** | Múltiples (incluyendo inglés y español) |
| **Conectividad** | Tarjeta MicroSD (ranura en la pantalla), puerto USB tipo B (para conexión a PC) |
| **Drivers de motor** | TMC2209 (modo UART, silenciosos) en placa v4.2.7; otros en v4.2.2 |

### 2.7 Estructura y mecánica

| Parámetro | Valor |
|---|---|
| **Eje Z** | Doble husillo de guía (dual Z-axis lead screw) con varilla de sincronización |
| **Superficie de impresión** | Placa de acero magnética con recubrimiento PC (policarbonato) |
| **Ejes X e Y** | Correa de sincronización GT2, perfil de aluminio extruido |
| **Chasis** | Perfil de aluminio de 40 × 40 mm |
| **Rodamientos** | Ruedas de POM (polioximetileno) en ejes X, Y y Z |
| **Potencia nominal** | 350 W |
| **Fuente de alimentación** | Mean Well LRS-350-24 (24 V / 14,6 A) |

### 2.8 Filamentos compatibles

| Filamento | Temperatura boquilla | Temperatura cama | Notas |
|---|---|---|---|
| **PLA** | 190 – 220 °C | 50 – 60 °C | Material de uso general, ideal para principiantes |
| **PLA+** | 200 – 230 °C | 50 – 60 °C | Mayor resistencia que el PLA estándar |
| **PETG** | 220 – 250 °C | 70 – 80 °C | Resistencia y resistencia al agua; recomendable usar funda |
| **TPU (95A)** | 210 – 230 °C | 50 – 60 °C | Filamento flexible; el extrusor directo lo maneja bien |
| **ABS** | 240 – 260 °C | 90 – 100 °C | **Requiere funda cerrada**; emite vapores tóxicos, usar con ventilación |
| **ASA** | 240 – 260 °C | 90 – 100 °C | Similar al ABS pero resistente a UV; requiere funda |
| **HIPS** | 220 – 250 °C | 80 – 100 °C | Disoluble en limoneno; útil como soporte soluble |

### 2.9 Software compatible

| Software | Función | Notas |
|---|---|---|
| **Creality Slicer** | Laminador (slicer) oficial | Basado en Cura, con perfiles preconfigurados para Ender-3 S1 |
| **Ultimaker Cura** | Laminador | Recomendado; amplio soporte de comunidad y perfiles disponibles |
| **PrusaSlicer** | Laminador | Alternativa de código abierto con excelente soporte |
| **Repetier-Host** | Laminador y control de impresión | Interfaz de control directo de la impresora |
| **Simplify3D** | Laminador (de pago) | Opción profesional con funciones avanzadas |

---

## 3. Componentes y partes

### 3.1 Estructura principal (chasis)

1. **Perfiles de aluminio del chasis base** — Cuatro perfiles verticales de aluminio de 40 × 40 mm que forman la estructura rectangular de la base de la impresora. Proporcionan rigidez y estabilidad al conjunto. Sobre ellos se montan la cama caliente, la fuente de alimentación y la placa base.
2. **Perfil superior transversal** — Barra horizontal de aluminio que conecta las dos columnas superiores del chasis, proporcionando soporte estructural y sirviendo como punto de anclaje para el cableado del eje X. En la Ender-3 S1, este perfil también soporta el soporte del carrete de filamento.
3. **Soporte del carrete (spool holder)** — Estructura montada en la parte superior del chasis que sostiene el carrete de filamento. Permite que el filamento se desenrolle de forma suave y continua hacia el extrusor Sprite. Debe estar correctamente instalado para evitar tirones o atascos en la alimentación.

### 3.2 Sistema de movimiento del eje X (portal/gantry)

4. **Perfil horizontal del eje X** — Barra de aluminio extruido que se mueve verticalmente sobre las dos columnas del eje Z. Sobre este perfil se desplaza el carro del extrusor Sprite de izquierda a derecha (movimiento X). La estabilidad de este perfil es crucial para la calidad de impresión.
5. **Extrusor Sprite (direct dual-gear)** — Unidad de extrusión directa montada sobre el perfil del eje X. Contiene el motor de extrusión con dos engranajes que agarran el filamento, el bloque calefactor (heat block), el disipador térmico (heat sink), el termistor y la boquilla. Todo el conjunto pesa aproximadamente 344 g, lo que es relativamente ligero para un extrusor directo y permite velocidades de impresión razonables sin comprometer la calidad.
6. **Ventilador de capa (part cooling fan)** — Ventilador situado en la parte frontal del extrusor Sprite que dirige un flujo de aire hacia la pieza en impresión para enfriar rápidamente el filamento depositado. Es esencial para lograr buena calidad en puentes (bridges), voladizos (overhangs) y detalles finos, especialmente con PLA.
7. **Ventilador del disipador (hotend fan)** — Ventilador que enfría el disipador térmico del hotend, evitando que el calor se propague hacia arriba y derrita el filamento antes de que llegue a la zona de fusión (lo que causaría un atasco o jam). Este ventilador debe estar siempre encendido cuando la boquilla supera los 50 °C.
8. **Sensor CR Touch** — Dispositivo de auto-nivelación montado en el lado derecho del extrusor Sprite. Consta de un pin metálico retráctil que se extiende para tocar la cama en múltiples puntos durante el proceso de nivelación automática. Se conecta a la placa base mediante un cable plano y su precisión de repetibilidad es de ≤ 0,04 mm.

### 3.3 Eje Z (movimiento vertical)

9. **Husillos de eje Z (doble)** — Dos tornillos de guía (lead screws) de paso 8 mm que convierten el movimiento rotacional de los motores en movimiento lineal vertical del portal del eje X. La Ender-3 S1 incorpora dos husillos independientes, uno a cada lado, a diferencia del diseño original de la Ender-3 que solo tenía uno. Esto proporciona mayor estabilidad y reduce la inclinación del portal (gantry tilt).
10. **Motores del eje Z** — Dos motores paso a paso que accionan cada husillo de forma independiente. La sincronización entre ambos se logra mediante la varilla de conexión o directamente desde la configuración del firmware. Si los dos lados del portal no están al mismo nivel, puede producirse un desnivel que afecte la calidad de la primera capa.
11. **Varilla de sincronización del eje Z (Z-axis coupling rod)** — Barra metálica que conecta los dos lados del mecanismo de accionamiento del eje Z para garantizar que ambos motores giren al mismo ritmo y el portal se mueva de forma paralela a la cama. Esta varilla es una característica distintiva de la Ender-3 S1 respecto a otros modelos con doble Z que no incluyen este mecanismo de sincronización.

### 3.4 Cama caliente y superficie de impresión

12. **Plataforma de la cama caliente** — Superficie calefactada de aluminio de 220 × 220 mm que calienta la base de impresión hasta 100 °C para asegurar la adherencia de la primera capa del filamento. La temperatura se controla mediante un termistor NTC de 100K integrado en la plataforma.
13. **Placa de acero magnética con recubrimiento PC** — Superficie extraíble de acero flexible con recubrimiento de policarbonato (PC) que se adhiere magnéticamente a la cama caliente. El recubrimiento PC proporciona una superficie con buena adherencia para PLA, PETG y TPU. Para retirar las piezas impresas, basta con flexionar la placa de acero y las piezas se desprenden fácilmente. Es importante no usar herramientas metálicas afiladas sobre la superficie para no dañar el recubrimiento.
14. **Resortes de suspensión de la cama** — Cuatro resortes de compresión ubicados en las esquinas de la cama que permiten ajustar manualmente la altura de cada esquina mediante las perillas de nivelación. Aunque el CR Touch compensa las irregularidades automáticamente, un ajuste manual previo de la cama (esquinas niveladas) mejora significativamente los resultados del auto-nivelación.
15. **Perillas de ajuste manual de la cama** — Cuatro ruedas de plástico situadas debajo de la plataforma en cada esquina que permiten ajustar la distancia entre la boquilla y la cama de forma manual. Se giran en sentido horario para acercar la cama a la boquilla y en sentido antihorario para alejarla.

### 3.5 Electrónica

16. **Placa base de 32 bits silenciosa** — Placa de circuito impreso situada debajo de la plataforma de la cama, dentro del chasis. Incorpora un procesador ARM de 32 bits que ejecuta el firmware de la impresora (generalmente Marlin). Los modelos con placa v4.2.7 incluyen drivers TMC2209 que reducen drásticamente el ruido de los motores paso a paso. Es importante identificar la versión de la placa antes de actualizar el firmware, ya que una versión incorrecta puede inutilizar la impresora.
17. **Fuente de alimentación (Mean Well LRS-350-24)** — Fuente de alimentación conmutada de 350 W que suministra 24 V / 14,6 A a todos los componentes de la impresora: motores, cama caliente, cartucho calefactor del hotend, ventiladores y electrónica. Está situada en la parte posterior del chasis, protegida por una cubierta metálica. La marca Mean Well es reconocida por su fiabilidad y seguridad, y es una mejora respecto a las fuentes genéricas utilizadas en modelos anteriores de la Ender-3.
18. **Pantalla LCD de 4,3 pulgadas** — Display a color con resolución suficiente para mostrar menús de navegación, ajustes de temperatura, controles de movimiento y progreso de impresión. Se controla mediante una perilla rotativa que funciona tanto como selector (girando) como botón de confirmación (pulsando). La pantalla se monta en un soporte atornillado al perfil izquierdo del chasis.
19. **Ranura para tarjeta MicroSD** — Conector situado en la pantalla LCD que permite insertar una tarjeta MicroSD con los archivos G-code generados por el laminador. Este es el método principal de carga de archivos de impresión en la Ender-3 S1 base (sin conexión WiFi o Ethernet de serie).
20. **Puerto USB tipo B** — Conector ubicado en la pantalla que permite conectar la impresora a un computador para enviar archivos G-code directamente o controlar la impresora en tiempo real mediante software como Pronterface o OctoPrint.

### 3.6 Funda cerrada (enclosure) — Solo en la Unidad 2

21. **Estructura de la funda** — Carcasa cerrada que rodea completamente la estructura de la impresora, formada por paneles laterales, panel posterior, panel superior y puerta frontal con ventana transparente (generalmente de acrílico o policarbonato). La funda está diseñada para ajustarse al chasis de la Ender-3 S1, reteniendo el calor generado por la cama caliente y el hotend en el interior del volumen de impresión.
22. **Ventana frontal transparente** — Panel de acrílico o policarbonato transparente en la puerta frontal de la funda que permite observar el progreso de la impresión sin necesidad de abrir la puerta, manteniendo la temperatura interior estable.
23. **Sistema de ventilación/cierre** — La funda puede incluir aberturas o ventilaciones regulables que permiten controlar el flujo de aire en el interior. Para materiales como ABS, las ventilaciones deben estar prácticamente cerradas para mantener una temperatura ambiente interna de 40–50 °C; para PETG, pueden abrirse parcialmente para evitar un sobrecalentamiento excesivo.

### 3.7 Accesorios incluidos de fábrica

24. **Tarjeta MicroSD** — Tarjeta de memoria con los archivos de ejemplo y el firmware de la impresora. Se utiliza para transferir los archivos G-code desde el computador a la impresora.
25. **Lector de tarjetas MicroSD a USB** — Adaptador que permite conectar la tarjeta MicroSD al computador para copiar los archivos G-code generados por el laminador.
26. **Herramientas de ensamblaje** — Juego de llaves Allen (hex) y destornilladores necesarios para el montaje inicial y el mantenimiento de la impresora.
27. **Aguja de limpieza de boquilla** — Aguja metálica fina (0,4 mm) utilizada para desatascar la boquilla cuando se produce una obstrucción interna.
28. **Espátula/raedera** — Herramienta de plástico o metal con borde afilado utilizada para retirar las piezas impresas de la superficie de impresión y para limpiar residuos de la cama.
29. **Cable USB tipo B** — Cable para conectar la impresora al computador mediante el puerto USB de la pantalla.
30. **Carrete de filamento PLA de muestra** — Pequeño carrete de filamento PLA incluido para realizar las primeras pruebas de impresión.
31. **Guía de inicio rápido** — Folleto impreso con las instrucciones básicas de ensamblaje y puesta en marcha.

---

## 4. Configuración y puesta en marcha

### 4.1 Desembalaje y verificación de componentes

Antes de iniciar el ensamblaje, es fundamental verificar que todos los componentes están presentes y en buen estado. El embalaje de la Ender-3 S1 viene protegido con espuma de polietileno y cinta de sujeción para minimizar los daños durante el transporte. Proceda de la siguiente manera:

1. Abra la caja con cuidado y retire las capas de espuma protectora. Identifique los componentes principales: base preensamblada (chasis inferior con cama caliente, fuente de alimentación y placa base montados), portal del eje X con extrusor Sprite preinstalado, pantalla LCD, soporte del carrete, tornillería y herramientas.
2. Verifique que no hay piezas sueltas o dañadas en el interior del embalaje. Revise especialmente los cables y conectores de la cama caliente, el extrusor Sprite y los motores del eje Z. Cualquier cable pelado o conector roto debe ser reportado antes de continuar.
3. Retire las bridas de plástico (zip ties) que sujetan los cables durante el transporte. Hágalo con cuidado, usando unas tijeras o un cortante, evitando cortar accidentalmente los cables.
4. Compruebe que la tarjeta MicroSD y el lector de tarjetas USB están incluidos, así como las herramientas de ensamblaje y la aguja de limpieza de boquilla.

### 4.2 Ensamblaje de la impresora

La Ender-3 S1 viene parcialmente preensamblada, lo que reduce significativamente el tiempo de montaje respecto a modelos anteriores. El proceso de ensamblaje consiste en unir las principales sub-unidades preconstruidas:

1. **Montaje del portal del eje X**: Levante el portal del eje X (que ya tiene el extrusor Sprite, los ventiladores y el sensor CR Touch montados) y colóquelo sobre las dos columnas verticales del chasis. Deslice los carros con ruedas de POM por los perfiles de aluminio del eje Z hasta que el portal quede centrado y a la altura adecuada. Asegure los carros con los tornillos proporcionados.
2. **Conexión de los cables del portal**: Conecte los cables del extrusor Sprite, los ventiladores y el sensor CR Touch a la placa base según el esquema de cableado. Los conectores están codificados por color y forma para evitar conexiones incorrectas. Asegúrese de que los cables no quedan atrapados ni tirantes.
3. **Montaje de la pantalla LCD**: Atornille el soporte de la pantalla al perfil izquierdo del chasis y conecte el cable plano (ribbon cable) desde la pantalla hasta la placa base. El cable debe tener suficiente holgura para permitir el movimiento del portal del eje X sin tensión.
4. **Montaje del soporte del carrete**: Atornille el soporte del carrete en la parte superior del chasis e inserte el eje portacarrete. Verifique que el carrete puede girar libremente sin obstrucciones.
5. **Ajuste de las ruedas de POM**: Verifique que todas las ruedas de POM (ejes X, Y y Z) giran suavemente sin holgura excesiva ni agarrotamiento. Las ruedas excéntricas (las que tienen un disco descentrado) permiten ajustar la presión contra el perfil de aluminio: gírelas con una llave hasta lograr un deslizamiento suave pero sin juego lateral.
6. **Verificación de la correa del eje X**: Compruebe que la correa GT2 del eje X está tensada de forma uniforme. Debe ceder ligeramente al presionarla con el dedo (aprox. 5–10 mm de deflexión con fuerza moderada), pero no debe estar floja ni excesivamente tensa.
7. **Instalación de la placa de impresión**: Coloque la placa de acero magnético con recubrimiento PC sobre la cama caliente. Los imanes integrados la mantendrán en posición. Verifique que la placa queda plana y bien adherida en toda su superficie.

### 4.3 Instalación de la funda cerrada (solo Unidad 2)

Si la impresora que se está configurando es la que llevará la funda cerrada, el proceso de instalación de la funda debe realizarse después del ensamblaje completo de la impresora y la verificación de su correcto funcionamiento sin funda:

1. Ensamble los paneles laterales, posterior y superior de la funda según las instrucciones del fabricante de la funda. La mayoría de las fundas para la Ender-3 S1 constan de un marco de aluminio o plástico con paneles acrílicos que se atornillan o se encastran.
2. Deslice la impresora ya ensamblada al interior de la funda, asegurándose de que los pies de la impresora apoyan firmemente sobre la base de la funda y de que no hay contacto entre los paneles de la funda y las partes móviles de la impresora.
3. Instale la puerta frontal con ventana transparente. Verifique que la puerta cierra correctamente y que el mecanismo de cierre (imanes o pestillo) mantiene la puerta sellada durante la impresión.
4. Asegure el paso de cables: los cables de alimentación y USB deben salir por las aberturas previstas en la parte posterior o inferior de la funda sin quedar aplastados ni doblados bruscamente.
5. Verifique que la pantalla LCD es visible y accesible a través de la ventana frontal, o bien que la funda permite el acceso a la perilla de control.

### 4.4 Calibración inicial de la cama (nivelación manual)

Antes de usar el auto-nivelación del CR Touch, es necesario realizar una nivelación manual preliminar de la cama. Esto asegura que la cama está razonablemente plana antes de que el sensor realice la compensación fina:

1. Encienda la impresora y, desde el menú de la pantalla, seleccione **Preparar → Mover eje → Mover Z → Inicio (Home)** para enviar la boquilla a la posición de origen (home).
2. Desde el menú, desactive los steppers: **Preparar → Desactivar steppers** (Disable steppers). Esto permite mover manualmente la cama y el portal.
3. Coloque una hoja de papel normal (aprox. 0,1 mm de grosor) entre la boquilla y la superficie de impresión en la primera esquina (esquina delantera izquierda).
4. Ajuste la perilla de nivelación de esa esquina hasta que la hoja de papel se deslice con una ligera fricción debajo de la boquilla. Debe sentir una resistencia suave pero la hoja debe poder moverse sin quedar atrapada.
5. Repita el procedimiento en las otras tres esquinas, moviendo manualmente la cama (eje Y) y el portal (eje X) para posicionar la boquilla sobre cada perilla.
6. Repita el proceso completo (las cuatro esquinas) al menos dos o tres veces, ya que el ajuste de una esquina afecta ligeramente a las demás. La cama se considera nivelada cuando la fricción del papel es uniforme en las cuatro esquinas y en el centro.

### 4.5 Auto-nivelación con CR Touch

Una vez nivelada la cama manualmente, ejecute el proceso de auto-nivelación del CR Touch para que la impresora cree una malla de compensación:

1. Desde la pantalla LCD, seleccione **Preparar → Nivelación automática** (o **Auto Home** seguido de **Bed Leveling → Level Bed**).
2. La boquilla se moverá al centro de la cama y luego el sensor CR Touch descenderá su pin para tocar la superficie en múltiples puntos (típicamente 16 puntos en una cuadrícula de 4 × 4).
3. Espere a que el proceso se complete. La pantalla mostrará los valores de compensación medidos en cada punto.
4. Si los valores muestran una desviación mayor de ±0,3 mm entre esquinas, ajuste las perillas de nivelación manual y repita el proceso de auto-nivelación.
5. Guarde la configuración de nivelación seleccionando **Preparar → Guardar configuración** (Store Settings) para que la malla de compensación se conserve tras apagar la impresora.

### 4.6 Ajuste del Z-Offset

El Z-Offset es la distancia entre la posición donde el sensor CR Touch detecta la superficie de la cama y la punta de la boquilla. Un Z-Offset incorrecto es la causa más común de problemas de adherencia en la primera capa:

1. Desde la pantalla, seleccione **Preparar → Z-Offset** (o acceda durante una impresión de prueba).
2. Imprima un patrón de prueba de primera capa (un cuadrado de una sola capa o un patrón de nivelación) y observe cómo se deposita el filamento.
3. Si la primera capa está demasiado alta (el filamento no se adhiere, forma hilos redondos en lugar de planos), reduzca el Z-Offset en incrementos de 0,05 mm.
4. Si la primera capa está demasiado baja (el filamento se aplasta excesivamente, se rasga o la boquilla raspa la superficie), aumente el Z-Offset en incrementos de 0,05 mm.
5. El ajuste ideal produce una primera capa lisa y uniforme, con el filamento ligeramente aplanado pero sin marcas de la boquilla sobre la superficie.
6. Guarde el Z-Offset ajustado en la memoria de la impresora (**Preparar → Guardar configuración**).

### 4.7 Instalación del software laminador (slicer)

El laminador convierte el modelo 3D (archivos STL, OBJ o 3MF) en instrucciones G-code que la impresora puede ejecutar. Se recomienda instalar Ultimaker Cura por su amplia compatibilidad y facilidad de uso:

1. Descargue Ultimaker Cura desde `https://ultimaker.com/software/ultimaker-cura` e instálelo en el computador.
2. Al iniciar Cura por primera vez, el asistente de configuración solicitará añadir una impresora. Seleccione **Add a non-networked printer** (Añadir una impresión sin red) → **Creality3D** → **Ender-3 S1**.
3. Cura cargará automáticamente los ajustes predeterminados para la Ender-3 S1: volumen de impresión 220 × 220 × 270 mm, diámetro de boquilla 0,4 mm, temperatura de extrusión 200 °C y temperatura de cama 60 °C (para PLA).
4. Verifique que los ajustes de diámetro de filamento están configurados en 1,75 mm.

Alternativamente, puede utilizar **Creality Slicer** (basado en Cura), que viene incluido en la tarjeta MicroSD de la impresora y ya contiene perfiles optimizados específicamente para la Ender-3 S1.

---

## 5. Guía de uso paso a paso

### 5.1 Preparación del modelo 3D

Antes de imprimir, es necesario preparar el modelo 3D en el laminador:

1. Abra el laminador (Cura o Creality Slicer) y cargue el archivo del modelo 3D (STL, OBJ o 3MF) arrastrándolo a la ventana del programa o seleccionando **Archivo → Abrir archivo**.
2. Posicione el modelo sobre la cama virtual haciendo clic derecho → **Posicionar en el centro** (Lay Flat / Center). Verifique que el modelo no supera las dimensiones del volumen de impresión (220 × 220 × 270 mm).
3. Ajuste la orientación del modelo si es necesario. La orientación afecta tanto la calidad superficial como la resistencia de la pieza: las superficies que apoyan sobre la cama suelen tener mejor acabado, y las capas se depositan paralelas a la cama, por lo que la resistencia a la tracción es mayor en el plano XY que en el eje Z.
4. Configure los parámetros de impresión según el material y la complejidad del modelo (consulte la sección 5.3 para ajustes recomendados por filamento).
5. Haga clic en **Laminar** (Slice) para generar el G-code. El laminador mostrará una estimación del tiempo de impresión, la cantidad de filamento necesaria y el peso de la pieza.
6. Guarde el archivo G-code en la tarjeta MicroSD (conecte el lector de tarjetas USB al computador, inserte la MicroSD y guarde el archivo en la raíz de la tarjeta).

### 5.2 Encendido y preparación de la impresora

1. Verifique que la impresora está conectada a la corriente eléctrica y que el interruptor posterior (en la fuente de alimentación) está en posición ON.
2. Cargue el filamento en el extrusor Sprite: introduzca el extremo del filamento por la entrada del extrusor (parte superior), presione la palanca de liberación y empuje el filamento hacia abajo hasta que salga filamento fundido por la boquilla. Suelte la palanca para que los engranajes agarren el filamento.
3. Precaliente la boquilla y la cama: desde la pantalla LCD, seleccione **Preparar → Precalentar PLA** (o el perfil correspondiente al material). Espere a que las temperaturas alcancen los valores objetivo (aprox. 2–4 minutos).
4. Limpie la boquilla: una vez alcanzada la temperatura de extrusión, empuje manualmente un poco de filamento y verifique que sale un hilo uniforme y continuo por la boquilla. Límpielo con la espátula o unas pinzas.
5. Inserte la tarjeta MicroSD con el archivo G-code en la ranura de la pantalla LCD.

### 5.3 Ajustes recomendados por tipo de filamento

#### PLA (uso general, principiantes)

| Parámetro | Valor recomendado |
|---|---|
| Temperatura de boquilla | 200 – 210 °C |
| Temperatura de cama | 55 – 60 °C |
| Velocidad de impresión | 50 – 60 mm/s |
| Ventilador de capa | 100 % a partir de la capa 2 |
| Retracción | 1,0 mm a 25 mm/s |
| Unidad recomendada | Cualquiera (sin funda o con funda) |

#### PETG (resistencia y uso en exteriores)

| Parámetro | Valor recomendado |
|---|---|
| Temperatura de boquilla | 230 – 245 °C |
| Temperatura de cama | 70 – 80 °C |
| Velocidad de impresión | 40 – 50 mm/s |
| Ventilador de capa | 30 – 50 % (reducir para mejor adherencia entre capas) |
| Retracción | 1,0 mm a 25 mm/s |
| Unidad recomendada | **Unidad 2 (con funda cerrada)** — la funda ayuda a mantener la temperatura ambiente estable y reduce el alabeo |

#### TPU (filamento flexible)

| Parámetro | Valor recomendado |
|---|---|
| Temperatura de boquilla | 210 – 225 °C |
| Temperatura de cama | 50 – 60 °C |
| Velocidad de impresión | 20 – 30 mm/s (velocidad baja para evitar enredos) |
| Ventilador de capa | 50 – 80 % |
| Retracción | 0,5 – 1,0 mm a 15 mm/s (mínima retracción) |
| Unidad recomendada | Cualquiera (sin funda preferiblemente para mejor ventilación) |

#### ABS (alta resistencia térmica, requiere funda)

| Parámetro | Valor recomendado |
|---|---|
| Temperatura de boquilla | 245 – 255 °C |
| Temperatura de cama | 95 – 100 °C |
| Velocidad de impresión | 40 – 50 mm/s |
| Ventilador de capa | 0 – 10 % (casi apagado para evitar agrietamiento) |
| Retracción | 1,0 mm a 25 mm/s |
| Unidad recomendada | **Obligatoria: Unidad 2 (con funda cerrada)** — sin funda, el ABS se alabeará y agrietará irremediablemente |

### 5.4 Inicio de la impresión

1. Desde la pantalla LCD, seleccione **Imprimir** (Print) y elija el archivo G-code deseado de la tarjeta MicroSD.
2. La impresora iniciará el proceso de calentamiento de la boquilla y la cama. Espere a que ambas temperaturas alcancen los valores objetivo.
3. La impresora ejecutará la rutina de auto-nivelación (si está configurada para ejecutarse antes de cada impresión) y luego la boquilla se moverá al punto de inicio definido en el G-code.
4. Observe la deposición de la primera capa. Es el momento más crítico de la impresión: verifique que el filamento se adhiere correctamente a la superficie de la cama en toda su extensión. Si la primera capa no se adhiere o presenta irregularidades, pause la impresión (botón de la pantalla o perilla), ajuste el Z-Offset y reinicie la impresión.
5. Una vez confirmado que la primera capa es correcta, deje que la impresión continúe de forma autónoma. Periódicamente (cada 15–30 minutos), verifique visualmente el progreso de la impresión para detectar posibles problemas como desprendimiento (warping), deshilachado (stringing) o desplazamiento de capas (layer shift).

### 5.5 Retirada de la pieza impresa

1. Espere a que la impresión finalice completamente. La pantalla mostrará un mensaje de "Impresión completada" y las temperaturas comenzarán a descender.
2. Espere a que la cama caliente se enfríe a temperatura ambiente (o al menos por debajo de 40 °C) antes de retirar la pieza. Retirar la pieza con la cama caliente puede causar deformación, especialmente con PLA, y aumenta el riesgo de quemaduras.
3. Retire la placa de acero magnético de la cama tirando de una esquina hacia arriba.
4. Flexione la placa de acero suavemente para despegar la pieza impresa. La flexión rompe la adherencia entre el filamento y el recubrimiento PC, permitiendo que la pieza se desprenda fácilmente. No utilice fuerza excesiva ni herramientas metálicas afiladas, ya que pueden dañar la superficie de impresión.
5. Si la pieza no se despega con la flexión, utilice la espátula de plástico incluida para deslizarla por debajo de la pieza con cuidado, trabajando desde los bordes hacia el centro.

### 5.6 Uso de la funda cerrada (Unidad 2)

La funda cerrada es una herramienta indispensable para ciertos materiales y tipos de impresión. A continuación se detallan las pautas de uso:

- **Cuándo usar la funda cerrada**: Utilice la Unidad 2 con funda para imprimir con ABS, ASA y otros materiales que requieren temperaturas de cama elevadas (≥90 °C) y son susceptibles al alabeo por cambios bruscos de temperatura. También es beneficiosa para piezas grandes de PETG que tienden a alabearse en las esquinas.
- **Cuándo NO usar la funda**: Para PLA y TPU, la funda no es necesaria e incluso puede ser contraproducente, ya que el exceso de calor en el interior puede causar ablandamiento del filamento antes de que llegue a la boquilla, resultando en atascos y mala calidad de extrusión. Para estos materiales, utilice la Unidad 1 sin funda.
- **Gestión de la temperatura interior**: Al imprimir con ABS, la temperatura interior de la funda debe alcanzar entre 40 °C y 50 °C para evitar el agrietamiento (cracking). Si la funda incluye ventilaciones, manténgalas cerradas o apenas abiertas. Monitoree la temperatura interior si la funda incluye un termómetro.
- **Seguridad con la funda**: La puerta de la funda debe permanecer cerrada durante la impresión con ABS para contener los vapores de estireno, que son irritantes y potencialmente nocivos con exposición prolongada. Asegúrese de que el aula STEAM tiene ventilación adecuada o utilice un sistema de extracción de humos cuando imprima con ABS en la Unidad 2. Nunca abra la puerta de la funda con las manos desnudas si la temperatura interior es alta; use guantes o espere a que se enfríe.
- **Mantenimiento de la funda**: Limpie periódicamente la ventana frontal transparente con un paño suave y limpiador de acrílico para mantener la visibilidad. Verifique que los cierres y bisagras funcionan correctamente y que no hay grietas en los paneles acrílicos.

---

## 6. Mantenimiento básico

### 6.1 Limpieza de la boquilla

La boquilla es uno de los componentes más susceptibles a obstrucciones y residuos de filamento. Una limpieza regular previene atascos y garantiza una extrusión uniforme:

- **Limpieza en caliente**: Caliente la boquilla a la temperatura de extrusión del último filamento utilizado (por ejemplo, 200 °C para PLA). Con la espátula o unas pinzas, retire cuidadosamente los residuos de filamento fundido que se acumulan alrededor de la punta de la boquilla. Tenga cuidado de no quemarse con las partes calientes.
- **Limpieza con aguja**: Si sospecha de una obstrucción parcial en el interior de la boquilla, caliente la boquilla a 200–220 °C e inserte la aguja de limpieza incluida por la parte inferior de la boquilla. Muévala suavemente hacia arriba y abajo para desalojar el material obstruido. Retire la aguja y extruya filamento para verificar que fluye libremente.
- **Limpieza con filamento (cold pull)**: Para una limpieza más profunda, caliente la boquilla a 200 °C, inserte filamento y luego baje la temperatura a 150 °C (para PLA) o 180 °C (para PETG). Cuando la temperatura alcance ese valor, tire del filamento firmemente hacia arriba. El filamento arrastrará consigo los residuos carbonizados acumulados en el interior del hotend. Este método es especialmente útil si ha cambiado de un filamento de alta temperatura (como PETG o ABS) a uno de baja temperatura (como PLA).

### 6.2 Limpieza de la superficie de impresión

La placa de acero con recubrimiento PC debe mantenerse limpia para garantizar una buena adherencia de la primera capa:

- **Limpieza regular**: Después de cada impresión, limpie la superficie con un paño de microfibra o papel absorbente humedecido con alcohol isopropílico (IPA) al 70 % o superior. Esto elimina los residuos de grasa, aceites de las manos y restos de filamento que pueden afectar la adherencia.
- **Limpieza profunda**: Si la adherencia disminuye notablemente, lave la placa con agua tibia y jabón suave, frotando suavemente con una esponja no abrasiva. Séquela completamente antes de volver a colocarla en la impresora.
- **Evitar daños**: Nunca use herramientas metálicas afiladas (cúters, cuchillos, raspadores metálicos) directamente sobre la superficie de impresión, ya que rayarán el recubrimiento PC y deteriorarán la adherencia permanentemente. Utilice siempre la espátula de plástico incluida.
- **Reemplazo**: Si la superficie de PC está muy desgastada, rayada o pierde adherencia de forma consistente incluso después de limpiarla, es momento de reemplazarla. Las placas de repuesto están disponibles en la tienda oficial de Creality y en distribuidores autorizados.

### 6.3 Lubricación de las guías y husillos

Las guías de aluminio y los husillos del eje Z requieren una lubricación periódica para mantener un movimiento suave y preciso:

- **Husillos del eje Z**: Aplique una pequeña cantidad de grasa de litio o aceite de máquina ligero a los husillos del eje Z cada 2–3 meses (o cada 200 horas de impresión). Desplace manualmente el portal del eje X arriba y abajo varias veces para distribuir la lubricación de forma uniforme. Elimine el exceso de lubricante con un paño.
- **Perfiles de aluminio (guías de las ruedas de POM)**: Las ruedas de POM no requieren lubricación (el POM es un material autolubricante). Sin embargo, los perfiles deben mantenerse limpios de polvo y residuos. Límpielos con un paño seco o ligeramente humedecido cuando acumulen suciedad visible.
- **Correas de transmisión**: Las correas GT2 no requieren lubricación. Manténgalas limias de polvo y residuos de filamento. Verifique periódicamente su tensión: una correa floja produce impresiones con desplazamiento de capas (layer shift), y una correa excesivamente tensa acelera el desgaste de los rodamientos y los motores.

### 6.4 Verificación de las conexiones eléctricas

Las vibraciones constantes de la impresora pueden aflojar los conectores y tornillos con el tiempo:

- **Conectores de la placa base**: Cada 3–6 meses, con la impresora apagada y desconectada de la corriente, abra la cubierta inferior y verifique que todos los conectores de la placa base están firmemente insertados. Preste especial atención a los conectores de la cama caliente, el cartucho calefactor y los motores, que son los que más corriente transportan y más se calientan.
- **Tornillería general**: Revise y apriete los tornillos del chasis, el portal del eje X, los soportes de los motores y el soporte de la pantalla. Los tornillos que se aflojan con más frecuencia son los de las ruedas excéntricas y los del extrusor Sprite.
- **Cables**: Verifique que no hay cables desgastados, pelados o pellizcados por partes móviles. El cable de la cama caliente es especialmente vulnerable a la fatiga por flexión constante, ya que la cama se mueve hacia adelante y hacia atrás en cada capa.

### 6.5 Calibración periódica

La calibración de la impresora tiende a desviarse con el uso, especialmente la nivelación de la cama:

- **Nivelación manual**: Repita el proceso de nivelación manual de la cama (sección 4.4) cada 2–3 semanas o después de mover la impresora de ubicación.
- **Auto-nivelación CR Touch**: Ejecute el proceso de auto-nivelación antes de cada impresión importante o si nota problemas de adherencia en la primera capa. El proceso tarda aproximadamente 2 minutos y puede ahorrar horas de impresión fallida.
- **Z-Offset**: Verifique el Z-Offset cada vez que cambie de tipo de filamento o de superficie de impresión, ya que diferentes materiales y superficies pueden requerir ajustes sutiles.
- **Pasos por milímetro (E-steps)**: Si observa que la impresora sub-extruye o sobre-extruye de forma consistente (las paredes de las piezas son más finas o más gruesas de lo esperado), puede ser necesario calibrar los E-steps del extrusor. Mida 120 mm de filamento desde la entrada del extrusor, solicite a la impresora que extruya 100 mm y mida el filamento restante. Ajuste los E-steps en el firmware según la fórmula: `E-steps nuevos = E-steps actuales × (100 / filamento realmente extruido)`.

### 6.6 Reemplazo de la boquilla

La boquilla de latón se desgasta con el uso, especialmente si se imprimen filamentos abrasivos (como los cargados con fibra de carbono, metal o madera). Una boquilla desgastada produce extrusión irregular y pérdida de precisión:

1. Precaliente la boquilla a 220 °C para ablandar cualquier filamento residual.
2. Con una llave de 7 mm (o la llave incluida en el kit de herramientas), afloje la boquilla girándola en sentido antihorario. Tenga cuidado de no quemarse con el bloque calefactor caliente.
3. Retire la boquilla vieja y coloque la nueva, enroscándola a mano primero y luego ajustándola firmemente con la llave. No apriete en exceso para no dañar las roscas del bloque calefactor.
4. Realice una extrusión de prueba y ajuste el Z-Offset si es necesario, ya que la nueva boquilla puede tener una longitud ligeramente diferente.

---

## 7. Solución de problemas comunes

### 7.1 Problemas de adherencia en la primera capa

| Síntoma | Causa probable | Solución |
|---|---|---|
| La primera capa no se adhiere a la cama; el filamento flota o se enrolla | Cama sucia (grasa, polvo, residuos) | Limpie la superficie de la placa con alcohol isopropílico al 70–90 %. Lávese las manos antes de manipular la placa. |
| La primera capa se adhiere en el centro pero no en las esquinas | Cama desnivelada o combada | Nivele manualmente las esquinas de la cama (sección 4.4) y ejecute el auto-nivelación CR Touch. Si la cama está combada, considere usar una malla de compensación más densa (ubi-leveling). |
| El filamento se aplasta excesivamente o la boquilla raspa la cama | Z-Offset demasiado bajo (boquilla demasiado cerca) | Aumente el Z-Offset en incrementos de 0,05 mm hasta lograr una primera capa lisa pero sin raspar. |
| La primera capa forma hilos redondos que no se aplanan sobre la cama | Z-Offset demasiado alto (boquilla demasiado lejos) | Reduzca el Z-Offset en incrementos de 0,05 mm. El filamento debe quedar ligeramente aplanado contra la cama. |
| La primera capa se despega durante la impresión (warping) | Temperatura de cama insuficiente o corrientes de aire | Aumente la temperatura de cama en 5 °C. Evite corrientes de aire. Para ABS/ASA, use la Unidad 2 con funda cerrada. |

### 7.2 Atascos de filamento (clogging)

| Síntoma | Causa probable | Solución |
|---|---|---|
| El motor del extrusor gira pero no sale filamento por la boquilla | Atasco en la boquilla o el heat break | Caliente la boquilla a 220 °C y use la aguja de limpieza por la parte inferior. Si no funciona, realice un cold pull. |
| El filamento se desliza entre los engranajes del extrusor; se escucha un "clic" | Filamento desgastado por los engranajes (stripped filament) | Corte el extremo dañado del filamento, afloje ligeramente la tensión del extrusor y vuelva a alimentar. |
| Atasco recurrente después de cambiar de filamento | Restos del filamento anterior carbonizados en el hotend | Realice un cold pull completo. Caliente a 200 °C, inserte filamento nuevo, baje a 150 °C y tire firmemente. Repita hasta que el filamento salga limpio. |
| Atasco al imprimir con filamento flexible (TPU) | Tensión excesiva del extrusor o retracción demasiado larga | Reduzca la distancia de retracción a 0,5 mm y la velocidad de retracción a 15 mm/s. Reduzca la velocidad de impresión a 20–30 mm/s. |
| Filamento se ablanda y se enrolla antes de llegar a la boquilla | Ventilador del disipador (hotend fan) no funciona | Verifique que el ventilador del disipador gira cuando la boquilla supera los 50 °C. Reemplace el ventilador si está defectuoso. Esto es especialmente importante en la Unidad 2 con funda, donde la temperatura ambiente es más alta. |

### 7.3 Problemas de calidad de impresión

| Síntoma | Causa probable | Solución |
|---|---|---|
| Líneas visibles entre capas (banding) | Temperatura de extrusión demasiado baja o velocidad excesiva | Aumente la temperatura de boquilla en 5 °C. Reduzca la velocidad de impresión. |
| Hilos de filamento entre partes de la pieza (stringing) | Retracción insuficiente o temperatura excesiva | Aumente la distancia de retracción (0,2 mm adicionales) y la velocidad de retracción. Reduzca la temperatura de boquilla en 5 °C. Active la opción "Retracción al cambiar de capa" (retraction at layer change). |
| Superficie superior con huecos o relleno visible | Porcentaje de relleno demasiado bajo o número de capas superior insuficiente | Aumente el porcentaje de relleno o el número de capas superiores (top layers). Un mínimo de 4 capas superiores es recomendable. |
| Desplazamiento de capas (layer shift) | Correa floja o tensión insuficiente en las ruedas de POM | Verifique la tensión de las correas GT2. Ajuste las ruedas excéntricas para eliminar la holgura. Verifique que los conectores de los motores están firmes. |
| Efecto de piel de elefante (elephant foot) | Primera capa demasiado aplastada o cama excesivamente caliente | Aumente ligeramente el Z-Offset. Reduzca la temperatura de la cama en 5 °C. Use la opción "Babystepping" durante la primera capa. |
| Superficie rugosa o con grumos | Filamento húmedo o de mala calidad | Seque el filamento en un horno a 50 °C durante 4–6 horas o utilice un secador de filamento. Cambie a un filamento de mejor calidad. |

### 7.4 Problemas del sensor CR Touch

| Síntoma | Causa probable | Solución |
|---|---|---|
| El CR Touch no desciende el pin | Conector suelto o cable dañado | Verifique la conexión del CR Touch a la placa base. Revise el cable en busca de cortes o dobleces. |
| La nivelación automática da valores inconsistentes | Pin del CR Touch sucio o dañado | Limpie el pin con alcohol isopropílico. Si el pin está doblado, reemplace el sensor. |
| La boquilla choca contra la cama después de la nivelación | Z-Offset no calibrado correctamente | Recalibre el Z-Offset (sección 4.6). Verifique que el sensor CR Touch está montado a la altura correcta: la punta del pin debe estar aproximadamente 2–3 mm por debajo de la punta de la boquilla. |
| Error "Probing failed" en la pantalla | Superficie de la cama reflectante o demasiado oscura para la detección | Limpie la superficie de impresión. Si el problema persiste, verifique el firmware y la configuración del sensor. |

### 7.5 Problemas de la tarjeta MicroSD

| Síntoma | Causa probable | Solución |
|---|---|---|
| La impresora no detecta la tarjeta MicroSD | Tarjeta mal insertada o ranura sucia | Retire y vuelva a insertar la tarjeta. Limpie los contactos de la tarjeta con alcohol isopropílico. |
| El archivo G-code no aparece en la lista | Archivo en formato incorrecto o con nombre incompatible | Verifique que el archivo tiene extensión `.gcode`. Renómbrelo con un nombre corto y sin caracteres especiales (solo letras, números y guion bajo). |
| La impresión se detiene a mitad y vuelve al menú | Tarjeta MicroSD dañada o con sectores defectuosos | Formatee la tarjeta en FAT32 (no exFAT ni NTFS). Si el problema persiste, reemplace la tarjeta por una nueva de clase 10. |
| Error al leer la tarjeta tras actualizar firmware | Formato de archivo incompatible con la nueva versión | Reformatee la tarjeta y vuelva a copiar los archivos G-code. |

### 7.6 Problemas específicos del uso con funda cerrada

| Síntoma | Causa probable | Solución |
|---|---|---|
| Atascos frecuentes al imprimir PLA con la funda | Temperatura ambiente interior demasiado alta | Abra la puerta de la funda o las ventilaciones para permitir la disipación del calor. Para PLA, es preferible usar la Unidad 1 sin funda. |
| El filamento se ablanda en el extrusor antes de la boquilla | El ventilador del hotend no disipa suficiente calor en el ambiente cálido | Verifique que el ventilador del disipador funciona correctamente. Considere añadir ventilación forzada en la funda. |
| La pieza se deforma al retirarla de la funda cerrada | Retirada de la pieza con la cama aún caliente | Espere a que la cama se enfríe a temperatura ambiente antes de abrir la funda y retirar la pieza. |
| Condensación en la ventana de la funda | Diferencia de temperatura entre el interior y el exterior | Esto es normal durante impresiones con temperaturas de cama altas. La condensación no afecta la impresión pero puede reducir la visibilidad. |

---

## 8. Materiales, repuestos y accesorios

### 8.1 Boquillas de repuesto

| Tipo de boquilla | Diámetro | Material | Código / Referencia | Uso recomendado |
|---|---|---|---|---|
| **Boquilla estándar** | 0,4 mm | Latón | M6 × 7,5 mm (estándar Creality) | Uso general, PLA, PETG, TPU |
| **Boquilla fina** | 0,2 mm | Latón | M6 × 7,5 mm | Detalles finos, miniaturas, joyería |
| **Boquilla gruesa** | 0,6 mm | Latón | M6 × 7,5 mm | Impresión rápida, piezas grandes |
| **Boquilla resistente** | 0,4 mm | Acero inoxidable | M6 × 7,5 mm | Filamentos abrasivos (fibra de carbono, madera, metal) |
| **Boquilla de alta conductividad** | 0,4 mm | Cobre con revestimiento | M6 × 7,5 mm | Impresión a alta velocidad, requiere menor temperatura |

### 8.2 Superficies de impresión de repuesto

| Superficie | Código / Referencia | Características |
|---|---|---|
| **Placa de acero con PC (original)** | Ender-3 S1 PC Spring Steel | Superficie de fábrica, adherencia media-alta para PLA y PETG, se retira magnéticamente |
| **Placa de acero con PEI** | Creality PEI Spring Steel | Mejor adherencia que la PC, compatible con más materiales, superficie lisa por un lado y texturizada por el otro |
| **Placa de vidrio** | Creality Glass Bed 235 × 235 mm | Superficie extremadamente plana, excelente acabado en la primera capa, requiere adherentes (pegamento barrador) para algunos materiales |

### 8.3 Filamentos recomendados

| Filamento | Marca recomendada | Precio aprox. (1 kg) | Notas |
|---|---|---|---|
| **PLA** | Polymaker PolyLite PLA, eSUN PLA+ | $20 – $30 USD | Material de uso diario, fácil de imprimir |
| **PETG** | Polymaker PolyLite PETG, Overture PETG | $22 – $35 USD | Resistencia y durabilidad, usar con funda si es posible |
| **TPU 95A** | Overture TPU, SainSmart TPU | $25 – $35 USD | Filamento flexible, el extrusor directo lo maneja bien |
| **ABS** | Polymaker PolyLite ABS, eSUN ABS | $20 – $30 USD | Solo imprimir en la Unidad 2 con funda cerrada |
| **PLA Silk** | eSUN Silk PLA, Sunlu Silk PLA | $25 – $35 USD | Efecto metálico decorativo, ideal para proyectos STEAM |

### 8.4 Accesorios y repuestos comunes

| Accesorio / Repuesto | Referencia | Descripción |
|---|---|---|
| **Kit de limpieza de boquilla** | Genérico (agujas 0,4 mm + cepillo de latón) | Incluye agujas de diferentes diámetros y un cepillo de cerdas de latón para limpiar el exterior de la boquilla |
| **Correa GT2 de repuesto** | GT2 6 mm, longitud adecuada | Correa de transmisión de repuesto para los ejes X e Y. Verifique la longitud necesaria antes de comprar. |
| **Resortes de cama de repuesto** | Creality Ender-3 S1 bed springs | Juego de 4 resortes de repuesto para la cama caliente. Alternativamente, puede actualizarse a resortes de silicona (silicone bed mounts) para mayor estabilidad. |
| **Tubo de PTFE** | Tubo PTFE 4 × 3 mm | Aunque el Sprite es de extrusión directa, un segmento corto de tubo PTFE se utiliza entre la entrada del extrusor y el heat break. Reemplácelo si está desgastado o deformado. |
| **Tarjeta MicroSD de repuesto** | MicroSDHC 8–32 GB, clase 10 | Tarjeta de memoria de alta velocidad para reemplazar la original en caso de fallo. Debe estar formateada en FAT32. |
| **Ventilador de capa (4010)** | Ventilador axial 40 × 40 × 10 mm, 24 V | Ventilador de repuesto para el part cooling fan. Verifique el voltaje (24 V para la Ender-3 S1). |
| **Ventilador del hotend (4010)** | Ventilador axial 40 × 40 × 10 mm, 24 V | Ventilador de repuesto para el hotend fan. Debe estar siempre operativo durante la impresión. |
| **Pantalla LCD de repuesto** | Creality Ender-3 S1 4.3″ LCD | Pantalla de reemplazo en caso de fallo de la pantalla original. Incluye cable plano y perilla rotativa. |

### 8.5 Accesorios opcionales de mejora

| Accesorio | Función | Notas |
|---|---|---|
| **Resortes de silicona para cama** | Sustituyen los resortes metálicos, mantienen la nivelación por más tiempo | Recomendado para el aula STEAM; reducen la frecuencia de re-nivelación |
| **Soporte de filamento con rodamientos** | Permite que el carrete gire con menor resistencia | Reduce la tensión en el extrusor y previene deslizamientos de filamento |
| **Raspberry Pi + OctoPrint** | Control de la impresora vía WiFi, monitoreo remoto con cámara | Permite enviar archivos desde el computador sin tarjeta MicroSD y monitorear impresiones en progreso |
| **Adaptador de placa PEI** | Superficie de impresión mejorada | Mejor adherencia y durabilidad que la placa PC original |
| **Cepillo de limpieza de boquilla** | Cepillo de cerdas de latón montado en el eje X | Se programa en el G-code para limpiar la boquilla automáticamente antes de cada impresión |

---

## 9. Normas de uso STEAM

### 9.1 Normas generales de seguridad

1. **Superficies calientes**: la boquilla alcanza temperaturas de hasta 260 °C y la cama caliente hasta 100 °C. Nunca toque estas superficies durante o inmediatamente después de una impresión. Espere al menos 15 minutos tras finalizar la impresión antes de manipular la boquilla o la cama. Utilice las pinzas incluidas para retirar hilos de filamento de la boquilla en caliente.
2. **Partes móviles**: durante la impresión, el portal del eje X se mueve verticalmente, la cama se desplaza horizontalmente y el extrusor se desplaza lateralmente. No introduzca las manos ni objetos en el área de impresión mientras la máquina está en funcionamiento. Si necesita intervenir, pause la impresión primero desde la pantalla LCD.
3. **Ventilación**: al imprimir con materiales que emiten vapores (especialmente ABS y ASA), asegúrese de que el aula STEAM cuenta con ventilación adecuada. La Unidad 2 con funda cerrada contiene parcialmente los vapores, pero estos se liberan al abrir la puerta. Para ABS, se recomienda imprimir con la funda cerrada y ventilar el aula al finalizar la impresión.
4. **No dejar la impresora desatendida por largos periodos**: aunque las impresoras FDM están diseñadas para funcionar de forma autónoma, los fallos pueden provocar sobrecalentamiento, derrames de filamento fundido o, en casos extremos, riesgo de incendio. Si la impresión va a durar más de 4 horas, designe a un estudiante para que la supervise periódicamente o utilice un sistema de monitoreo remoto (OctoPrint con cámara).

### 9.2 Normas de uso de los filamentos

1. **Almacenamiento del filamento**: guarde los carretes de filamento en bolsas herméticas con bolsitas de gel de sílice (sílice gel) cuando no estén en uso. El filamento absorbe humedad del ambiente, lo que provoca burbujas, chasquidos durante la extrusión y mala calidad de impresión. El PLA es especialmente higroscópico.
2. **Selección de la unidad según el material**: utilice la Unidad 1 (sin funda) para PLA, TPU y otros filamentos de baja temperatura que se benefician de la ventilación. Utilice la Unidad 2 (con funda cerrada) para ABS, ASA, PETG (piezas grandes) y cualquier material que requiera temperaturas de cama superiores a 80 °C o que sea susceptible al alabeo.
3. **No mezclar tipos de filamento**: evite cambiar entre filamentos de temperaturas muy diferentes (por ejemplo, de PLA a ABS) sin una limpieza completa del hotend. Los residuos de PLA carbonizados a temperaturas de ABS pueden causar obstrucciones. Realice un cold pull completo al cambiar de tipo de filamento.
4. **Etiquetado de los carretes**: cada carrete en el aula STEAM debe estar etiquetado con el tipo de material, la marca, la temperatura recomendada y la fecha de apertura. Esto facilita la selección del material correcto y ayuda a identificar los carretes que pueden haber absorbido demasiada humedad.

### 9.3 Normas de asignación de las dos unidades

1. **Designación de unidades**: la **Unidad 1** (sin funda) se usará preferiblemente para impresiones con PLA, TPU y otros materiales de baja temperatura. La **Unidad 2** (con funda cerrada) se usará para impresiones con ABS, ASA y PETG que requieran control de temperatura. Si ambas unidades están disponibles y el material es PLA, el estudiante puede elegir cualquiera de las dos, pero debe retirar la funda de la Unidad 2 si va a imprimir PLA (o al menos abrir las ventilaciones completamente).
2. **Sistema de reservas**: dado que hay dos unidades, el coordinador del aula STEAM debe implementar un sistema de reservas o turnos para evitar conflictos. Cada impresora puede ser reservada por bloques de tiempo (por ejemplo, bloques de 2 horas). Las impresiones que superen el bloque asignado deben ser planificadas para iniciarse al inicio del bloque siguiente.
3. **Prioridad de la Unidad 2**: si un estudiante necesita imprimir con ABS o un material que requiere la funda, tiene prioridad sobre la Unidad 2, incluso si otro estudiante la está usando para PLA. El estudiante que esté usando la Unidad 2 con PLA deberá pausar su impresión y reanudarla en la Unidad 1 o esperar a que la Unidad 1 esté disponible.
4. **Reporte de estado**: al finalizar una sesión de impresión, cada estudiante debe reportar el estado de la impresora: si la cama está limpia, si hay algún atasco, si los filamentos fueron retirados y guardados, y si la impresora se apagó correctamente.

### 9.4 Normas de operación

1. **No modificar el firmware sin autorización**: la actualización o modificación del firmware de la impresora (por ejemplo, instalar Marlin personalizado o Klipper) solo debe realizarla el coordinador del aula o un estudiante avanzado bajo supervisión directa. Un firmware incorrecto puede inutilizar la impresora (brickear la placa base), lo que requeriría reemplazar la placa o flashearla mediante un programador externo.
2. **No desmontar componentes electrónicos**: los estudiantes no deben desmontar la fuente de alimentación, la placa base ni los módulos electrónicos. Si se sospecha de un fallo electrónico, repórtelo al coordinador del aula para que lo revise.
3. **Velocidades de impresión respetuosas**: aunque la Ender-3 S1 puede imprimir a velocidades de hasta 150 mm/s, las velocidades altas comprometen la calidad de impresión y aumentan el riesgo de fallos. Se recomienda mantener velocidades de 50–60 mm/s para PLA y 40–50 mm/s para PETG y ABS, especialmente en un entorno educativo donde la calidad y la fiabilidad son más importantes que la velocidad.
4. **No forzar los mecanismos**: si algo no se mueve o no funciona correctamente, no fuerce las piezas. Los motores paso a paso tienen un par limitado y forzarlos puede dañar los engranajes, las correas o los rodamientos. Si el portal del eje X está atascado, verifique que no hay obstrucciones físicas, que las ruedas de POM no están excesivamente apretadas y que los husillos están lubricados.

### 9.5 Normas de limpieza y orden

1. **Limpieza de la cama**: después de cada impresión, limpie la superficie de impresión con alcohol isopropílico. Si quedan residuos de filamento adheridos, retírelos con la espátula de plástico antes de limpiar con alcohol.
2. **Retirada de filamento**: al finalizar la sesión, retire el filamento del extrusor si no se va a usar la impresora en las próximas 24 horas. Esto evita que el filamento se deforme o se atasque en el hotend. Corte el extremo del filamento en ángulo de 45° antes de guardarlo en su bolsa hermética.
3. **Limpieza del área de trabajo**: retire los restos de filamento, las piezas fallidas y las herramientas del área alrededor de la impresora. Mantenga el espacio libre de obstáculos para facilitar el acceso y reducir el riesgo de accidentes.
4. **Apagado correcto**: apague la impresora desde el interruptor posterior de la fuente de alimentación una vez que las temperaturas de la boquilla y la cama hayan descendido a valores seguros (por debajo de 50 °C). No desconecte la impresora de la corriente mientras está en funcionamiento.

### 9.6 Protocolo de reporte de incidencias

1. Si durante una impresión se produce un fallo que el estudiante no puede resolver con las soluciones descritas en la sección 7 (por ejemplo, un atasco persistente, un fallo del sensor CR Touch, un error en la pantalla o un comportamiento errático de los motores), el estudiante debe detener la impresión inmediatamente, apagar la impresora y reportar la incidencia al coordinador del aula.
2. El reporte debe incluir: la unidad afectada (Unidad 1 o Unidad 2), la descripción del problema, el material que se estaba usando, la temperatura de impresión y cualquier acción que se haya tomado para intentar resolver el problema.
3. No intente desmontar o reparar componentes electrónicos, reemplazar la placa base o actualizar el firmware sin la autorización y supervisión del coordinador del aula STEAM.

---

## 10. Enlaces y recursos adicionales

### 10.1 Sitios oficiales

| Recurso | URL | Descripción |
|---|---|---|
| **Página oficial del producto** | `https://www.creality.com/products/creality-ender-3-s1-3d-printer` | Ficha del producto, especificaciones oficiales y galería de imágenes |
| **Creality Wiki — Ender-3 S1** | `https://wiki.creality.com/en/ender-series/ender-3-s1` | Guías de usuario, tutoriales de servicio y vídeos de mantenimiento |
| **Creality Cloud** | `https://www.crealitycloud.com/` | Plataforma de modelos 3D y comunidad de usuarios Creality |
| **Tienda oficial de repuestos** | `https://store.creality.com/` | Repuestos originales, accesorios y consumibles |

### 10.2 Software

| Software | URL | Descripción |
|---|---|---|
| **Ultimaker Cura** | `https://ultimaker.com/software/ultimaker-cura` | Laminador recomendado, gratuito y de código abierto |
| **PrusaSlicer** | `https://www.prusa3d.com/prusaslicer/` | Laminador alternativo, excelente soporte para impresoras Creality |
| **Creality Slicer** | Incluido en la tarjeta MicroSD | Laminador oficial basado en Cura, con perfiles optimizados |
| **OctoPrint** | `https://octoprint.org/` | Servidor de control de impresión vía web (requiere Raspberry Pi) |

### 10.3 Recursos educativos y comunidad

| Recurso | URL | Descripción |
|---|---|---|
| **Subreddit r/Ender3S1** | `https://www.reddit.com/r/Ender3S1/` | Comunidad de usuarios de la Ender-3 S1 en Reddit |
| **Foro oficial de Creality** | `https://forum.creality.com/` | Foro de soporte técnico oficial de Creality |
| **Creality Experts** | `https://www.crealityexperts.com/` | Guías detalladas, comparaciones y tutoriales para impresoras Creality |
| **All3DP — Ender-3 S1** | `https://all3dp.com/1/creality-ender-3-s1-review-3d-printer/` | Reseñas detalladas y guías de configuración |
| **3D Print Beginner** | `https://3dprintbeginner.com/creality-ender-3-s1-pro-review` | Análisis técnico detallado de la serie Ender-3 S1 |
| **Thingiverse** | `https://www.thingiverse.com/` | Biblioteca de modelos 3D gratuitos para imprimir |
| **Printables** | `https://www.printables.com/` | Biblioteca de modelos 3D de Prusa, con excelente sistema de búsqueda |

### 10.4 Vídeos tutoriales recomendados

| Recurso | URL / Referencia | Descripción |
|---|---|---|
| **Ender-3 S1 Assembly** | YouTube: "Creality Ender-3 S1 Assembly" | Guía completa de ensamblaje paso a paso |
| **Ender-3 S1 Setup & First Print** | YouTube: "Creality Ender-3 S1 Unbox & Setup" | Configuración inicial y primera impresión |
| **CR Touch Leveling Guide** | YouTube: "Ender-3 S1 CR Touch Setup" | Configuración detallada del auto-nivelación |
| **Nozzle Cleaning Tutorial** | Creality Cloud: Service Tutorial Ender-3 S1 | Tutorial oficial de limpieza de boquilla |
| **50 Common Problems — Ender-3 S1** | `https://store.creality.com/blogs/all/ender-3-s1-50-common-printer-problems-and-how-to-solve` | Artículo extenso con 50 problemas comunes y sus soluciones |

### 10.5 Firmware y actualizaciones

| Recurso | URL | Descripción |
|---|---|---|
| **Firmware oficial de Creality** | `https://www.creality.com/pages/download` | Descargas oficiales de firmware para todos los modelos Creality |
| **Creality Wiki — Firmware** | `https://wiki.creality.com/en/ender-series/ender-3-s1/firmware` | Instrucciones de actualización de firmware específicas para la Ender-3 S1 |
| **Marlin Firmware** | `https://marlinfw.org/` | Firmware de código abierto alternativo con funciones avanzadas |

> **⚠️ Advertencia importante sobre firmware**: Antes de actualizar o cambiar el firmware, identifique la versión exacta de su placa base (v4.2.2 o v4.2.7) mirando la etiqueta en la placa. Instalar un firmware incorrecto puede inutilizar la impresora. Solo el coordinador del aula STEAM debe realizar actualizaciones de firmware.
