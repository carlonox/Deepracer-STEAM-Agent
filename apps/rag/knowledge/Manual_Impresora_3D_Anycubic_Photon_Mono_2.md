# Manual de Referencia — Impresora 3D Resina Anycubic Photon Mono 2

> **Aula STEAM — Manual de consulta para estudiantes y asistente robótico**
> Unidades en el aula: **2**

---

## 1. Descripción general

La **Anycubic Photon Mono 2** es una impresora 3D de resina (tecnología LCD/SLA) diseñada como opción de entrada para quienes desean iniciarse en la impresión 3D con fotopolímeros. Lanzada en abril de 2023, esta máquina se posiciona como la primera elección para principiantes gracias a su equilibrio entre calidad de impresión, facilidad de uso y precio accesible. A diferencia de las impresoras FDM (como la Creality Ender-3 S1 o la Creality K1 que también se encuentran en el aula), la Photon Mono 2 utiliza un proceso de curado por luz UV a través de una pantalla LCD monocromática de 6,6 pulgadas con resolución 4K+ (4096 × 2560 píxeles), lo que le permite lograr detalles extraordinariamente finos con un tamaño de píxel de aproximadamente 34–35 µm.

El sistema de luz de la Photon Mono 2 emplea la tecnología **LightTurbo**, una fuente de luz matricial paralela mejorada que reduce significativamente las líneas de capa y los patrones de rejilla visibles en las impresiones, produciendo resultados más suaves y de aspecto profesional. Esta mejora en la uniformidad de la iluminación se traduce en piezas con superficies más limpias y menor necesidad de postprocesado intensivo. La plataforma de impresión está fabricada en aleación de aluminio con grabado láser, lo que garantiza una excelente adherencia de las capas iniciales y facilita la remoción de las piezas terminadas.

En el contexto del aula STEAM, la Photon Mono 2 resulta especialmente valiosa para proyectos que requieren alta precisión y detalle fino, como la fabricación de miniaturas, joyería, prototipos pequeños con detalles intrincados, moldes para fundición y piezas mecánicas de precisión. Su volumen de impresión de 165 × 89 × 143 mm (HWD) con una capacidad máxima de 2,09 litros la hace ideal para piezas de tamaño pequeño a mediano. Las dos unidades disponibles en el aula permiten que múltiples estudiantes trabajen de forma simultánea o que se realicen impresiones en paralelo con diferentes resinas, optimizando así el tiempo de producción durante las sesiones de clase.

Es importante destacar que la impresión con resina implica consideraciones de seguridad específicas que no se presentan en la impresión FDM: los fotopolímeros son químicos que requieren manipulación con guantes, mascarilla y en áreas ventiladas, y el postprocesado incluye lavado y curado UV de las piezas. Estas particularidades hacen que la Photon Mono 2 sea también una excelente herramienta pedagógica para enseñar sobre química de materiales, seguridad en el laboratorio y procesos de fabricación fotopolimérica.

---

## 2. Especificaciones técnicas

| Parámetro | Valor |
|---|---|
| **Tecnología de impresión** | LCD/SLA (estereolitografía enmascarada) |
| **Pantalla LCD** | 6,6" monocromática, resolución 4096 × 2560 px (4K+) |
| **Vida útil de la pantalla LCD** | Aprox. 2 000 horas |
| **Tamaño de píxel (resolución XY)** | ~34–35 µm |
| **Precisión eje Z** | 10 µm (0,01 mm) |
| **Volumen de impresión** | 165 × 89 × 143 mm (HWD) |
| **Volumen máximo de impresión** | 2,09 L |
| **Grosor de capa sugerido** | 0,01 – 0,15 mm |
| **Velocidad de impresión** | ≤ 50 mm/h (eje Z) |
| **Fuente de luz** | LightTurbo — matriz paralela UV 405 nm |
| **Plataforma de impresión** | Aleación de aluminio con grabado láser |
| **Pantalla táctil** | 2,8" pantalla táctil |
| **Conectividad** | USB Tipo-A 2.0 |
| **Fuente de alimentación** | 48 W nominales |
| **Dimensiones de la máquina** | 390 × 229 × 235 mm (HWD) |
| **Peso neto** | ~4,5 kg |
| **Material de impresión** | Resina fotopolimérica UV 405 nm |
| **Software de laminado** | Anycubic Photon Workshop (incluido); compatible con CHITUBOX, Lychee Slicer, VoxelDance Tango |
| **Formato de archivo de impresión** | .pwma (Photon Workshop), .ctb (CHITUBOX), .lys/.lyt (Lychee) |
| **Sistema operativo compatible** | Windows 7/10/11, macOS |

### Parámetros de impresión recomendados por Anycubic (resinas más comunes)

| Parámetro | Standard Resin | Plant-Based Resin | Water-Wash Resin+ | ABS-Like Resin V2 | High Clear Resin | High Speed Resin |
|---|---|---|---|---|---|---|
| **Grosor de capa** | 0,05 mm | 0,05 mm | 0,05 mm | 0,05 mm | 0,05 mm | 0,05 mm |
| **Tiempo de exposición** | 2,5 s | 2,5 s | 2,5 s | 2,5 s | 4,5 s | 2,5 s |
| **Tiempo de apagado de luz** | 1 s | 1 s | 1 s | 1 s | 1 s | 1 s |
| **Exposición base** | 25 s | 25 s | 25 s | 25 s | 25 s | 25 s |
| **Capas base** | 5 | 5 | 5 | 5 | 5 | 5 |
| **Distancia de elevación Z** | 6 mm | 6 mm | 6 mm | 6 mm | 6 mm | 6 mm |
| **Velocidad de elevación Z** | 4 mm/s | 4 mm/s | 4 mm/s | 4 mm/s | 4 mm/s | 4 mm/s |
| **Velocidad de retracción Z** | 6 mm/s | 6 mm/s | 6 mm/s | 6 mm/s | 6 mm/s | 6 mm/s |
| **Nivel de anti-aliasing** | 1 | 1 | 1 | 1 | 1 | 1 |

> **Nota:** Si la temperatura del entorno de impresión es inferior a 20 °C, se recomienda aumentar el tiempo de exposición en un 30 % y reducir la velocidad de elevación Z en un 30 %. Los datos provienen del laboratorio de Anycubic y son solo de referencia; los resultados pueden variar según las condiciones específicas de impresión y postprocesado.

---

## 3. Componentes y partes

### 3.1 Componentes principales

1. **Carcasa / cuerpo principal**: Estructura rectangular compacta de plástico y metal que alberga todos los componentes internos. En su parte superior dispone de una tapa/cover de protección transparente o tintada que bloquea parcialmente la luz UV y protege la cubeta de resina de la luz ambiental. Es fundamental mantener esta tapa cerrada durante la impresión para evitar la curado prematuro de la resina y la emisión de olores.

2. **Pantalla LCD monocromática 4K+ (6,6")**: Componente central del sistema de impresión. Esta pantalla de 4096 × 2560 píxeles actúa como máscara que controla qué áreas de cada capa son expuestas a la luz UV. Al ser monocromática, permite tiempos de exposición más cortos y tiene una vida útil significativamente mayor (~2 000 horas) comparada con las pantallas RGB utilizadas en impresoras más antiguas. Se recomienda protegerla con la película anti-rayas incluida.

3. **Sistema de fuente de luz LightTurbo**: Conjunto de LEDs UV (405 nm) dispuestos en una matriz paralela debajo de la pantalla LCD. Este sistema garantiza una distribución uniforme de la luz a través de toda el área de impresión, reduciendo las variaciones de curado entre el centro y los bordes. La tecnología LightTurbo minimiza las líneas de capa y los patrones de rejilla que pueden aparecer en las impresiones con sistemas de luz menos sofisticados.

4. **Cubeta de resina (resin vat)**: Contenedor de metal con una película FEP (Fluorinated Ethylene Propylene) en su base, a través de la cual la luz UV cura la resina. La cubeta tiene patas de posicionamiento que encajan en orificios de la base de la impresora y se fija con dos perillas roscadas. La película FEP es un componente consumible que eventualmente necesitará reemplazo tras un uso prolongado o si sufre daños.

5. **Plataforma de impresión (build plate)**: Superficie de aleación de aluminio con grabado láser donde se adhieren las piezas durante la impresión. El grabado láser proporciona una textura que mejora la adherencia de las primeras capas. La plataforma se fija al brazo del eje Z mediante una única perilla central y se nivela manualmente con cuatro tornillos de ajuste en sus esquinas.

6. **Eje Z (husillo de bolas)**: Sistema de movimiento vertical compuesto por un motor paso a paso, un husillo de bolas (lead screw) y una varilla guía lineal. Este conjunto controla el movimiento vertical de la plataforma con una precisión de 10 µm, lo que permite capas extremadamente delgadas y una alta calidad superficial. El husillo debe mantenerse limpio y lubricado para un funcionamiento óptimo.

7. **Pantalla táctil (2,8")**: Interfaz de usuario ubicada en la parte frontal de la impresora. Permite controlar las funciones principales: iniciar/detener impresiones, acceder a las herramientas (nivelación, detección de exposición, limpieza de residuos, movimiento del eje Z), ajustar configuraciones y seleccionar archivos desde la memoria USB.

8. **Puerto USB Tipo-A 2.0**: Conector ubicado en el lateral de la impresora para conectar una memoria USB con los archivos de impresión laminados. Es el único método de transferencia de datos; la Photon Mono 2 no cuenta con conectividad Wi-Fi ni Ethernet.

### 3.2 Accesorios incluidos en la caja

- Memoria USB (con software Photon Workshop y manual de usuario)
- Kit de herramientas: espátula metálica, raspador plástico, guantes
- Película protectora anti-rayas para la pantalla LCD
- Papel de nivelación
- Adaptador de corriente y cable de alimentación
- Manual de usuario impreso
- Cubeta de resina con película FEP preinstalada
- Plataforma de impresión

### 3.3 Repuestos y consumibles clave

| Repuesto / Consumible | Descripción |
|---|---|
| Película FEP de repuesto | Reemplazo para la base de la cubeta; necesario cuando la película se nubla, raya o perfora |
| Película anti-rayas para LCD | Protege la pantalla LCD de derrames de resina y arañazos |
| Pantalla LCD de repuesto | Componente de reemplazo cuando la pantalla alcanza el final de su vida útil (~2 000 h) o se daña |
| Plataforma de impresión de repuesto | Superficie de aluminio grabado láser de reemplazo |
| Resina fotopolimérica 405 nm | Consumible principal: Standard, Plant-Based, Water-Wash, ABS-Like, High Clear, etc. |
| Filtros de resina | Filtros de malla para colar la resina usada y eliminar partículas curadas |
- Papel toalla o paños sin pelusa
- Alcohol isopropílico (IPA) al 90 % o superior
- Guantes de nitrilo
- Mascarilla con filtro para vapores orgánicos
- Cubeta de lavado o máquina Wash & Cure
- Estación de curado UV o luz UV de cura

---

## 4. Configuración y puesta en marcha

### 4.1 Preparación del espacio de trabajo

Antes de desempaquetar la impresora, es fundamental preparar un espacio de trabajo adecuado. La impresión con resina requiere condiciones específicas que difieren significativamente de la impresión FDM:

- **Ventilación**: Ubicar la impresora en un área bien ventilada o bajo una campana extractora. Los vapores de resina pueden ser irritantes y potencialmente perjudiciales con la exposición prolongada. En el aula STEAM, se recomienda ubicar las dos Photon Mono 2 cerca de una ventana o en una zona con extractor de aire.
- **Temperatura**: La temperatura ambiente ideal para la impresión con resina está entre 20 °C y 30 °C. Temperaturas inferiores a 20 °C pueden causar fallos de impresión, ya que la resina se vuelve más viscosa y no fluye correctamente entre capas. Si el aula está fría, considerar un calentador o una carcasa con control de temperatura.
- **Superficie estable**: Colocar la impresora sobre una mesa o superficie firme, nivelada y que pueda soportar aproximadamente 5 kg por unidad sin vibraciones excesivas.
- **Protección contra UV**: Evitar la luz solar directa sobre la impresora, ya que puede curar la resina dentro de la cubeta. Trabajar en un espacio con luz indirecta o iluminación controlada.
- **Zona de postprocesado**: Preparar un área separada con alcohol isopropílico, guantes, papel toalla y una estación de curado UV para el lavado y curado de las piezas terminadas.

### 4.2 Desempaque e inspección

1. Retirar con cuidado la impresora de la caja, sosteniéndola por la base — nunca por la tapa protectora ni por el brazo del eje Z.
2. Verificar que todos los accesorios incluidos estén presentes (memoria USB, kit de herramientas, película anti-rayas, adaptador de corriente, etc.).
3. Inspeccionar la película FEP de la cubeta en busca de perforaciones, arrugas o manchas. Cualquier daño en la FEP puede causar fugas de resina hacia la pantalla LCD, lo cual es una de las averías más costosas en este tipo de impresoras.
4. Comprobar que la plataforma de impresión no tenga residuos ni marcas de fábrica.
5. Retirar las cintas y protecciones de transporte del cuerpo de la impresora, especialmente las que fijan el eje Z durante el envío.

### 4.3 Instalación de la película anti-rayas

Antes de la primera impresión, es muy recomendable instalar la película anti-rayas sobre la pantalla LCD. Esta película protege la pantalla de derrames de resina accidentales, que pueden dañar irreversiblemente la LCD. Para instalarla:

1. Encender la impresora y navegar a **Herramientas → Mover eje Z**, elevar la plataforma al menos 100 mm para dejar la pantalla expuesta.
2. Apagar la impresora y retirar la plataforma si estaba instalada.
3. Limpiar la superficie de la pantalla LCD con el paño incluido o con un paño de microfibra limpio. Asegurarse de que no haya polvo ni partículas.
4. Despegar la película protectora de la película anti-rayas (lado adhesivo) con cuidado.
5. Alinear la película con la pantalla, comenzando por un borde, y aplicar gradualmente evitando burbujas de aire. Usar una tarjeta rígida para alisar mientras se aplica.
6. Una vez instalada, verificar que no haya burbujas o arrugas significativas que puedan afectar la calidad de impresión.

### 4.4 Nivelación de la plataforma

La nivelación es un paso crítico que debe realizarse correctamente antes de la primera impresión y debe revisarse periódicamente. Un mal nivelado es una de las causas más comunes de fallos de impresión en resina.

1. Encender la impresora.
2. Aflojar los **cuatro tornillos** de la plataforma de impresión.
3. Colocar la plataforma en su posición sobre el brazo del eje Z y apretar la perilla central para fijarla.
4. Navegar a **Herramientas → Nivelación** en la pantalla táctil.
5. Colocar la **hoja de nivelación** (papel de calibración incluido) sobre la pantalla LCD / película anti-rayas.
6. Presionar el botón **Home** en la pantalla. La plataforma descenderá hasta tocar la hoja de nivelación.
7. Con la plataforma en posición, presionar firmemente la parte superior de la plataforma con ambas manos para asegurar un contacto uniforme con la hoja de nivelación.
8. Mientras se mantiene la presión, **apretar los cuatro tornillos** de la plataforma en un patrón de X (diagonalmente opuestos) de manera gradual y uniforme.
9. Retirar la hoja de nivelación. Debe sentir una ligera resistencia al deslizarla — ni demasiado apretada ni demasiado suelta.
10. Confirmar la nivelación en la pantalla táctil y establecer el **cero** (set zero).

### 4.5 Verificación de la exposición (exposure detection)

Después de la nivelación, se recomienda realizar una prueba de exposición para verificar que la pantalla LCD y la fuente de luz funcionan correctamente:

1. Navegar a **Herramientas → Detección de exposición**.
2. La impresora mostrará un patrón de prueba en la pantalla LCD. Verificar que la iluminación sea uniforme y que no haya píxeles muertos o zonas oscuras.
3. Si se detectan anomalías, consultar la sección de solución de problemas de este manual.

### 4.6 Instalación de la cubeta de resina

1. Asegurarse de que la cubeta esté limpia y la película FEP en buen estado.
2. Colocar la cubeta en la base de la impresora, alineando las patas de posicionamiento con los orificios correspondientes.
3. Fijar la cubeta apretando las **dos perillas** de sujeción.
4. No verter la resina en este momento — primero se debe verificar la nivelación con una prueba de impresión pequeña.

### 4.7 Instalación del software Photon Workshop

1. Insertar la memoria USB incluida en un computador.
2. Copiar el instalador de **Anycubic Photon Workshop** al computador.
3. Ejecutar el instalador y seguir las instrucciones en pantalla.
4. Una vez instalado, abrir Photon Workshop y configurar la impresora seleccionando **Anycubic Photon Mono 2** como modelo de impresora. Esto cargará automáticamente los parámetros correctos de resolución y volumen de impresión.
5. Alternativamente, se pueden instalar slicers compatibles como **CHITUBOX** (versión gratuita o Pro) o **Lychee Slicer** (versión gratuita o Pro), seleccionando el perfil de la Photon Mono 2 en la configuración de la aplicación.

---

## 5. Guía de uso paso a paso

### 5.1 Preparación del modelo 3D

1. **Obtener o diseñar el modelo**: Descargar un archivo STL u OBJ de un repositorio (Thingiverse, Printables, Cults3D) o crear uno propio en software de modelado 3D (Blender, Fusion 360, Tinkercad, ZBrush).
2. **Verificar el modelo**: Asegurarse de que el modelo sea "manifold" (watertight), es decir, que no tenga agujeros en la malla ni caras invertidas. Los modelos no manifold provocan errores durante el laminado. Herramientas como Meshmixer o Netfabb pueden reparar modelos problemáticos.
3. **Considerar las dimensiones**: Verificar que el modelo quepa dentro del volumen de impresión de la Photon Mono 2 (165 × 89 × 143 mm). Si el modelo es más grande, considere escalarlo o dividirlo en partes.

### 5.2 Laminado (slicing) con Photon Workshop

1. Abrir **Anycubic Photon Workshop** en el computador.
2. Importar el archivo STL u OBJ (Archivo → Abrir o arrastrar y soltar).
3. **Posicionar el modelo**: Colocar el modelo en la plataforma virtual. En impresión con resina, a diferencia de FDM, las piezas se imprimen **invertidas** (colgadas de la plataforma), por lo que la orientación es fundamental:
   - Inclinar las piezas planas entre 30° y 45° respecto a la plataforma para minimizar la superficie de contacto con la película FEP y reducir las marcas de soporte en las caras planas.
   - Evitar orientaciones que creen grandes superficies planas paralelas a la plataforma, ya que generan una fuerte fuerza de succión que puede causar desprendimiento.
   - Posicionar los detalles más importantes orientados hacia arriba (lejos de la plataforma) cuando sea posible, ya que la cara superior de cada capa tendrá mejor calidad superficial.
4. **Generar soportes (supports)**: Utilizar la función de soportes automáticos o añadir soportes manualmente. Los soportes en resina son estructuras finas que sostienen las partes voladizas de la pieza. Es crucial:
   - Asegurar que todas las islas (islands) — regiones de la pieza que no están conectadas a la plataforma ni a otras partes soportadas — tengan soportes adecuados.
   - Ajustar la densidad y grosor de los soportes según el tamaño y peso de la pieza.
   - Verificar que la base de los soportes sea lo suficientemente ancha para adherirse firmemente a la plataforma.
5. **Configurar parámetros de impresión**: Ajustar los valores según la resina utilizada (consultar la tabla de la sección 2). Los parámetros más críticos son:
   - **Grosor de capa**: 0,05 mm es el estándar; 0,025–0,03 mm para máxima calidad; 0,08–0,1 mm para impresión más rápida.
   - **Tiempo de exposición normal**: Típicamente 2,5 s para resinas estándar. Aumentar para resinas transparentes (4,5 s) o si se observan fallos de adherencia entre capas.
   - **Exposición de capas base**: 25 s por capa durante las primeras 5 capas, para garantizar una adherencia sólida a la plataforma.
   - **Velocidad de elevación y retracción**: 4 mm/s y 6 mm/s respectivamente para configuración estándar.
6. **Exportar el archivo**: Guardar el archivo laminado en formato **.pwma** (Photon Workshop) o **.ctb** (si se usa CHITUBOX) directamente en la memoria USB. El archivo debe estar en la raíz de la memoria USB, no dentro de carpetas.

### 5.3 Preparación de la impresora

1. **Vestir el equipo de protección**: Ponerse guantes de nitrilo, mascarilla con filtro orgánico y gafas de protección antes de manipular resina.
2. **Agitar la resina**: Agitar suavemente la botella de resina durante 1–2 minutos para mezclar los pigmentos y componentes que pueden asentarse con el tiempo. No agitar en exceso para evitar la formación de burbujas.
3. **Verificar la cubeta**: Asegurarse de que la película FEP esté limpia y sin daños. Si hay residuos de resina curada de impresiones anteriores, limpiarlos con cuidado utilizando el raspador plástico (nunca metálico).
4. **Verificar la nivelación**: Si es la primera impresión o si se han observado problemas de adherencia, verificar la nivelación de la plataforma antes de continuar (ver sección 4.4).
5. **Verificar la película anti-rayas**: Comprobar que la película protectora de la LCD esté en su lugar y en buen estado.

### 5.4 Carga de resina e inicio de impresión

1. **Verter la resina**: Con la cubeta instalada y fijada, verter la resina lentamente en la cubeta. No llenar por encima de la marca de nivel máximo de la cubeta. Como regla general, verter suficiente resina para cubrir el fondo de la cubeta con al menos 5–10 mm de profundidad, añadiendo más si la impresión es alta.
2. **Insertar la memoria USB**: Conectar la memoria USB con el archivo laminado al puerto USB de la impresora.
3. **Seleccionar el archivo**: En la pantalla táctil, navegar al explorador de archivos y seleccionar el archivo .pwma o .ctb deseado.
4. **Iniciar la impresión**: Presionar **Imprimir**. La plataforma descenderá hasta la posición inicial y comenzará el proceso de curado capa por capa.
5. **Cerrar la tapa protectora**: Asegurarse de que la tapa esté completamente cerrada durante toda la impresión. Esto protege la resina de la luz UV ambiental y reduce la emisión de olores.
6. **Monitorear las primeras capas**: Es buena práctica observar las primeras capas de la impresión para verificar que la resina se está curando correctamente y que las capas base se adhieren a la plataforma. Si se detecta un problema temprano, se puede cancelar la impresión y ahorrar resina.

### 5.5 Finalización de la impresión

1. **Esperar a que termine**: Una vez completada la impresión, la pantalla mostrará un mensaje de finalización y la plataforma se elevará a la posición superior.
2. **Escurrir la pieza**: Dejar que la pieza escurra el exceso de resina durante 5–10 minutos con la plataforma en posición elevada y la tapa cerrada. Esto permite que la resina excedente regrese a la cubeta por gravedad.
3. **Retirar la plataforma**: Con los guantes puestos, aflojar la perilla central y retirar cuidadosamente la plataforma de impresión de la máquina.
4. **No exponer la pieza a luz UV directa** hasta después del lavado, ya que la resina sin curar en la superficie puede curarse de forma desigual, afectando la calidad del acabado.

### 5.6 Postprocesado: lavado y curado

El postprocesado es una etapa esencial en la impresión con resina que no existe en la impresión FDM. Las piezas recién impresas están cubiertas de resina sin curar que debe eliminarse y luego la pieza debe curarse completamente bajo luz UV.

**Lavado:**
1. Sumergir la pieza (con o sin soportes) en alcohol isopropílico (IPA) al 90 % o superior. Se puede usar un contenedor o una máquina de lavado como la **Anycubic Wash & Cure**.
2. Agitar suavemente o hacer girar la pieza en el IPA durante 2–5 minutos hasta que la superficie esté limpia y no pegajosa.
3. Para piezas con detalles intrincados o huecos, usar un cepillo suave empapado en IPA para limpiar las áreas de difícil acceso.
4. Retirar la pieza del IPA y dejarla secar al aire o secarla con aire comprimido/paño sin pelusa.

**Curado UV:**
1. Una vez que la pieza esté completamente seca, exponerla a luz UV durante 5–30 minutos, dependiendo del tamaño de la pieza y del tipo de resina. Se puede usar una estación de curado como la **Anycubic Wash & Cure** o luz solar directa (menos controlable).
2. Las resinas estándar típicamente requieren 5–10 minutos de curado UV. Las resinas transparentes y de alta resistencia pueden necesitar más tiempo.
3. Rotar la pieza durante el curado para garantizar una exposición uniforme por todos los lados.
4. Evitar el sobre-curado, que puede hacer que las piezas se vuelvan quebradizas o se deformen.

**Remoción de soportes:**
1. Retirar los soportes después del lavado pero **antes** del curado final, cuando la resina de los soportes aún está relativamente blanda. Esto facilita la remoción y reduce las marcas en la pieza.
2. Usar alicates de corte o una espátula para cortar los soportes cerca de la base de contacto con la pieza.
3. Si quedan marcas o rebabas, lijar suavemente con papel de lija de grano fino (400–800) o usar un pequeño quemador de calor para suavizar la superficie.

### 5.7 Limpieza y almacenamiento post-impresión

1. **Filtrar la resina sobrante**: Si no se va a imprimir de nuevo inmediatamente, verter la resina restante de la cubeta de vuelta a la botella utilizando un filtro de malla (incluido en algunos kits o disponible por separado). Esto elimina las partículas de resina curada que podrían causar fallos en la siguiente impresión.
2. **Limpiar la cubeta**: Si queda resina en la cubeta, cubrirla con la tapa o con una bolsa oscura para protegerla de la luz UV. Para limpieza profunda, retirar la cubeta y limpiar la FEP con IPA y un paño suave.
3. **Limpiar la plataforma**: Limpiar la plataforma con IPA y papel toalla. Eliminar cualquier residuo de resina curada.
4. **Almacenar la resina**: Cerrar herméticamente la botella de resina y almacenarla en un lugar fresco y oscuro. La resina tiene una vida útil limitada una vez abierta (típicamente 6–12 meses si se almacena correctamente).

---

## 6. Mantenimiento básico

### 6.1 Limpieza de la película FEP

La película FEP es el componente más delicado de la cubeta y requiere atención regular. Con el uso, la FEP puede acumular residuos de resina curada, nublarse o rayarse, lo que afecta la calidad de impresión y puede causar fallos.

- **Limpieza regular**: Después de cada sesión de impresión, si queda resina en la cubeta, colarla de vuelta a la botella. Si la FEP tiene residuos, limpiarla suavemente con IPA y un paño de microfibra por el lado inferior (el que no está en contacto con la resina).
- **Eliminación de residuos curados**: Si se encuentran trozos de resina curada en la FEP, NEVER usar herramientas metálicas para retirarlos. Utilizar el raspador plástico incluido o una espátula de plástico. Aplicar una presión suave y constante para no perforar la película.
- **Inspección visual**: Antes de cada impresión, inspeccionar la FEP en busca de perforaciones, arrugas o zonas muy nubladas. Una FEP perforada causará fugas de resina hacia la pantalla LCD, lo que puede dañar permanentemente la pantalla.
- **Reemplazo de la FEP**: La película FEP debe reemplazarse cuando presente perforaciones, deformaciones severas o nubosidad excesiva que no se limpia. El proceso de reemplazo implica desmontar la cubeta, retirar la película vieja y pegar la nueva con cuidado de evitar burbujas y arrugas.

### 6.2 Limpieza de la pantalla LCD

La pantalla LCD es el componente más costoso de reemplazar y requiere un cuidado especial:

- **Película anti-rayas**: Siempre mantener la película anti-rayas instalada sobre la LCD. Si se daña o se ensucia con resina, reemplazarla de inmediato.
- **Derrames de resina**: Si la resina llega a la pantalla LCD, limpiarla inmediatamente con IPA y un paño suave. La resina curada sobre la LCD puede causar píxeles muertos y daños permanentes.
- **Limpieza de la función "Residue Cleaning"**: La impresora tiene una función de limpieza de residuos accesible desde la pantalla táctil (Herramientas → Limpieza de residuos). Esta función enciende la pantalla LCD completamente para curar cualquier residuo de resina que haya quedado sobre ella, facilitando su remoción con el raspador plástico. **Nunca usar herramientas punzantes o metálicas** sobre la superficie de la LCD.
- **Inspección de píxeles muertos**: Periódicamente, ejecutar la prueba de detección de exposición para verificar que no haya píxeles muertos. Los píxeles muertos se manifiestan como pequeños puntos o líneas donde la pieza no se cura correctamente.

### 6.3 Mantenimiento del eje Z

El eje Z con husillo de bolas requiere un mantenimiento mínimo pero importante:

- **Lubricación**: Cada 2–3 meses (o más frecuentemente si se usa intensivamente), limpiar el husillo con un paño para eliminar polvo y residuos, y aplicar una pequeña cantidad de grasa de litio o aceite de máquina de coser en las roscas del husillo.
- **Inspección visual**: Verificar periódicamente que el husillo no tenga juego excesivo (wobble). Si la plataforma se mueve lateralmente más de lo esperado, puede ser necesario ajustar la tuerca del husillo o reemplazar componentes desgastados.
- **Limpieza de la varilla guía**: Limpiar la varilla guía lineal con un paño seco y aplicar una gota de aceite ligero para mantener el movimiento suave.

### 6.4 Almacenamiento y conservación de la resina

- **Almacenamiento**: Guardar las botellas de resina en un lugar fresco (15–25 °C), oscuro y fuera del alcance de los estudiantes. La exposición a la luz UV, el calor o el frío extremo puede degradar la resina.
- **Vida útil**: La resina sin abrir típicamente tiene una vida útil de 1–2 años. Una vez abierta, debe usarse dentro de 6–12 meses si se almacena correctamente.
- **Resina en la cubeta**: Si se planea imprimir de nuevo en las próximas 24–48 horas, la resina puede permanecer en la cubeta con la tapa cerrada. Para periodos más largos, verter la resina de vuelta a la botella a través de un filtro. Nunca dejar resina en la cubeta por más de una semana sin usar, ya que puede curarse parcialmente con la luz ambiental.
- **Resina caducada**: No usar resina que haya superado su fecha de caducidad o que presente un olor inusualmente fuerte, cambio de color significativo o grumos. La resina degradada produce impresiones de mala calidad y puede ser más tóxica.

### 6.5 Calendario de mantenimiento sugerido

| Frecuencia | Tarea |
|---|---|
| **Después de cada impresión** | Limpiar la plataforma, filtrar la resina sobrante, inspeccionar la FEP |
| **Semanal** | Limpiar la FEP con IPA, verificar la nivelación si hay fallos |
| **Mensual** | Inspeccionar la película anti-rayas de la LCD, ejecutar prueba de exposición |
| **Trimestral** | Limpiar y lubricar el husillo del eje Z, limpiar la varilla guía |
| **Semestral** | Inspección completa de la FEP (reemplazar si es necesario), verificar conexiones eléctricas |
| **Anual** | Evaluar el estado general de la pantalla LCD, reemplazar si se acerca a las 2 000 horas |

---

## 7. Solución de problemas comunes

### 7.1 La pieza no se adhiere a la plataforma (platform empty after printing)

**Causas posibles:**
- Nivelación incorrecta de la plataforma
- Exposición de las capas base insuficiente
- Primera capa demasiado delgada
- Superficie de la plataforma sucia o con residuos
- Película FEP nublada o sucia que reduce la transmisión de luz UV

**Soluciones:**
1. Re-nivelar la plataforma siguiendo el procedimiento de la sección 4.4. Asegurarse de que los cuatro tornillos estén apretados uniformemente mientras se mantiene presión sobre la plataforma.
2. Aumentar el tiempo de exposición base de 25 s a 30–45 s.
3. Aumentar el número de capas base de 5 a 7–8.
4. Limpiar la plataforma con IPA antes de imprimir. Si la superficie grabada está muy desgastada, lijar ligeramente con papel de lija de grano 400 para restaurar la textura.
5. Limpiar o reemplazar la película FEP si está nublada.

### 7.2 La pieza se adhiere a la FEP en lugar de a la plataforma

**Causas posibles:**
- Tiempo de exposición insuficiente para las capas normales
- Resina fría o viscosa
- Orientación del modelo con superficies planas grandes paralelas a la FEP
- Ángulo de elevación Z demasiado rápido (la succión despega la capa de la plataforma)

**Soluciones:**
1. Aumentar el tiempo de exposición normal en incrementos de 0,3–0,5 s (por ejemplo, de 2,5 s a 3,0 s).
2. Calentar la resina o el ambiente de impresión a 20–25 °C. Se puede usar un calentador de botella de resina o una almohadilla térmica.
3. Reorientar el modelo para evitar grandes superficies planas paralelas a la plataforma. Inclinar 30°–45°.
4. Reducir la velocidad de elevación Z de 4 mm/s a 2–3 mm/s para reducir la fuerza de succión.
5. Aumentar la distancia de elevación Z de 6 mm a 8 mm para permitir que la resina fluya de vuelta bajo la pieza más completamente.

### 7.3 Solo se imprimen los soportes pero no la pieza

**Causas posibles:**
- Tiempo de exposición insuficiente para las capas del modelo
- Los soportes son más gruesos que el modelo y se curan primero
- Grosor de capa demasiado grueso para el nivel de detalle del modelo
- Pantalla LCD con zonas dañadas

**Soluciones:**
1. Aumentar el tiempo de exposición normal. Los soportes al ser más gruesos se curan con menos exposición, pero las paredes delgadas del modelo pueden necesitar más tiempo.
2. Reducir el grosor de capa (por ejemplo, de 0,05 mm a 0,03 mm) para mejorar la resolución del detalle.
3. Ejecutar una prueba de exposición para verificar la integridad de la pantalla LCD.
4. Aumentar el tamaño de la punta de contacto de los soportes (support tip diameter) en el slicer.

### 7.4 Capas desalineadas o desplazadas (layer shifting)

**Causas posibles:**
- Juego excesivo en el husillo del eje Z
- Velocidad de retracción Z demasiado alta
- Resina muy viscosa (temperatura baja)
- Piezas pesadas o mal soportadas que generan fuerzas asimétricas

**Soluciones:**
1. Inspeccionar el husillo del eje Z y ajustar o reemplazar si hay juego excesivo.
2. Reducir la velocidad de retracción Z de 6 mm/s a 3–4 mm/s.
3. Calentar el ambiente de impresión o la resina.
4. Añadir más soportes a la pieza, especialmente en las zonas con mayor volumen o peso.
5. Aumentar la distancia de elevación Z para asegurar una separación completa entre la pieza y la FEP.

### 7.5 Superficie de la pieza con líneas de capa visibles o patrón de rejilla

**Causas posibles:**
- Sistema de luz desalineado o con distribución no uniforme
- Película FEP sucia o rayada
- Configuración de anti-aliasing incorrecta

**Soluciones:**
1. La tecnología LightTurbo de la Photon Mono 2 minimiza este problema, pero si persiste, verificar que no haya obstrucciones entre la fuente de luz y la LCD.
2. Limpiar la FEP por ambos lados con IPA y paño de microfibra.
3. Ajustar el nivel de anti-aliasing en el slicer (probar entre 1 y 2).
4. Verificar que la película anti-rayas no tenga arrugas que proyecten sombras.

### 7.6 Piezas quebradizas o fracturadas tras el curado

**Causas posibles:**
- Sobre-curado UV excesivo
- Resina inadecuada para la aplicación (por ejemplo, resina estándar en lugar de ABS-Like para piezas funcionales)
- Tiempo de exposición demasiado alto durante la impresión
- Lavado insuficiente (resina sin curar residual que se cura de forma desigual)

**Soluciones:**
1. Reducir el tiempo de curado UV post-impresión. Las resinas estándar típicamente necesitan solo 5–10 minutos.
2. Cambiar a una resina más resistente como ABS-Like Resin V2 o Tough Resin para piezas que requieran mayor durabilidad mecánica.
3. Verificar que el tiempo de exposición normal sea el recomendado; tiempos excesivamente altos pueden crear piezas más frágiles.
4. Asegurar un lavado completo antes del curado para eliminar toda la resina sin curar de la superficie.

### 7.7 La impresora no reconoce la memoria USB

**Causas posibles:**
- Formato de la memoria USB incompatible
- Archivo dentro de una carpeta en lugar de la raíz
- Memoria USB con capacidad excesiva o dañada
- Archivo en formato no compatible

**Soluciones:**
1. Formatear la memoria USB en **FAT32** (no exFAT ni NTFS).
2. Colocar el archivo de impresión (.pwma o .ctb) en la raíz de la memoria USB, no dentro de subcarpetas.
3. Usar una memoria USB de capacidad pequeña (8–32 GB) y de buena calidad. Algunas memorias USB de alta capacidad pueden no ser reconocidas.
4. Verificar que el archivo esté en un formato compatible (.pwma para Photon Workshop, .ctb para CHITUBOX).
5. Probar con otra memoria USB para descartar un problema con la memoria específica.

### 7.8 Pantalla LCD con píxeles muertos o zonas oscuras

**Causas posibles:**
- Daño por derrame de resina curada sobre la LCD
- Desgaste natural de la pantalla (acercándose a las 2 000 horas de vida útil)
- Daño por sobrecalentamiento

**Soluciones:**
1. Ejecutar la prueba de detección de exposición para evaluar la extensión del daño.
2. Si los píxeles muertos son pocos y están en zonas periféricas, pueden no afectar las impresiones significativamente. Se puede intentar colocar los modelos evitando las zonas afectadas.
3. Si el daño es extenso, es necesario reemplazar la pantalla LCD. Este es un procedimiento que requiere desmontar parcialmente la impresora y reconectar cables delicados — se recomienda consultar el servicio técnico de Anycubic o un técnico experimentado.
4. Prevenir futuros daños manteniendo siempre la película anti-rayas instalada y limpiando derrames de inmediato.

### 7.9 Resina con burbujas que causan pequeños agujeros en la pieza

**Causas posibles:**
- Resina agitada vigorosamente antes de verter
- Resina fría y viscosa que atrapa aire
- Velocidad de retracción Z demasiado rápida que genera succión y cavitación

**Soluciones:**
1. Agitar la resina suavemente, sin movimientos bruscos, y dejarla reposar 5–10 minutos antes de verter en la cubeta.
2. Calentar la resina a temperatura ambiente adecuada (20–25 °C) antes de usarla.
3. Reducir la velocidad de retracción Z y aumentar la distancia de elevación Z.
4. Dejar la resina en la cubeta reposando 10–15 minutos antes de iniciar la impresión para que las burbujas suban a la superficie.

---

## 8. Materiales, repuestos y accesorios

### 8.1 Resinas compatibles

La Photon Mono 2 es compatible con cualquier resina fotopolimérica UV 405 nm del mercado. A continuación se listan las resinas oficiales de Anycubic y otras marcas populares:

**Resinas oficiales Anycubic:**

| Resina | Características | Uso recomendado |
|---|---|---|
| Standard Resin / Standard Resin V2 | Equilibrio entre calidad y precio; buena resolución de detalle | Prototipos, figuras decorativas, piezas de exhibición |
| Standard Resin+ | Versión mejorada con mayor resistencia | Prototipos que requieren algo más de durabilidad |
| Plant-Based Resin / Plant-Based Resin+ | Base de plantas; menor olor; más ecológica | Proyectos educativos con énfasis ambiental; uso en espacios cerrados |
| Water-Wash Resin+ | Se limpia con agua en lugar de IPA; menor olor | Proyectos escolares donde se quiere minimizar el uso de solventes |
| ABS-Like Resin V2 / ABS-Like Pro / ABS-Like Pro 2 | Alta resistencia al impacto; algo flexible; similar al ABS | Piezas funcionales, carcasas, piezas mecánicas |
| High Clear Resin | Alta transparencia; aspecto similar al vidrio | Lentes, ventanas de modelo, prototipos ópticos |
| High Speed Resin | Diseñada para tiempos de exposición más cortos; impresión rápida | Producción en serie de piezas pequeñas |
| Tough Resin 2.0 / Tough Resin Ultra | Resistencia mecánica superior; tolerancia a cargas | Engranajes, piezas sometidas a esfuerzo mecánico |
| DLP Craftsman Resin | Alta resolución de detalle; para artesanos y joyeros | Joyería, miniaturas de alta gama, detalles finísimos |
| Bio Resin | Fórmula con menor toxicidad; menos irritante | Entornos educativos donde la seguridad es prioritaria |

**Otras marcas compatibles:**
- Elegoo (Standard, Water-Wash, ABS-Like, High Detail)
- Siraya Tech (Fast, Tenacious, Build, Blu)
- Liqcreate (Standard, Tough-X, Flexible, Bone Bio)
- Phrozen (Aqua, TR300, ABS-Like)
- Monocure 3D (Rapid, Clear, Flex)

> **Aviso importante:** Siempre consultar la ficha técnica del fabricante de la resina para los parámetros de impresión recomendados. Los valores pueden diferir de los de Anycubic. Realizar pruebas de calibración (como el test de exposición "Cones of Calibration" o "XP Validation Matrix") al cambiar de marca o tipo de resina.

### 8.2 Repuestos originales

| Repuesto | Código / Referencia | Notas |
|---|---|---|
| Película FEP para Photon Mono 2 | Consultar tienda Anycubic | Reemplazo periódico; 1–2 unidades de respaldo recomendadas |
| Película anti-rayas para LCD | Consultar tienda Anycubic | Mantener siempre un repuesto disponible |
| Pantalla LCD 6,6" 4K+ monocromática | Consultar tienda Anycubic | Componente costoso; solo reemplazar por técnico calificado |
| Plataforma de impresión de aluminio | Consultar tienda Anycubic | Si la superficie grabada se desgasta excesivamente |
| Cubeta de resina completa | Consultar tienda Anycubic | Cubeta de reemplazo con FEP preinstalada |
| Motor del husillo (eje Z) | Consultar tienda Anycubic | Para reemplazo en caso de fallo del motor |
| Memoria USB Anycubic | Universal | Cualquier USB FAT32 de 8–32 GB funciona |
| Fuente de alimentación 48 W | Consultar tienda Anycubic | Reemplazo en caso de fallo eléctrico |

### 8.3 Accesorios recomendados para el aula STEAM

| Accesorio | Función | Prioridad |
|---|---|---|
| **Anycubic Wash & Cure** o similar | Máquina combinada de lavado (IPA) y curado UV | Alta — ahorra tiempo y mejora la consistencia del postprocesado |
| **Alcohol isopropílico (IPA) 90 %+** | Solvente para lavado de piezas | Alta — consumible esencial |
| **Guantes de nitrilo (talla S/M/L)** | Protección al manipular resina | Alta — consumible continuo |
| **Mascarilla con filtro orgánico** | Protección respiratoria durante impresión y postprocesado | Alta |
| **Filtros de resina (malla fina)** | Colar resina usada para reutilización | Alta — previene fallos por partículas curadas |
| **Gafas de seguridad** | Protección ocular contra salpicaduras | Media |
| **Contenedores herméticos oscuros** | Almacenar resina y piezas sin curar | Media |
| **Papel de lija (grano 400–2000)** | Acabado de piezas post-curado | Media |
| **Calentador de botella de resina** | Mantener resina a temperatura óptima en climas fríos | Baja — solo si el aula es fría |
| **Bata o delantal de protección** | Protección de la ropa | Media |
| **Papel toalla sin pelusa** | Limpieza general | Alta — consumible continuo |
| **Cubeta de lavado con tapa** | Contenedor para lavar piezas en IPA | Alta |
| **Lámpara UV de curado portátil** | Curado UV de piezas pequeñas o detalladas | Media — alternativa a la Wash & Cure |

---

## 9. Normas de uso STEAM

### 9.1 Normas generales de seguridad

La impresión con resina implica riesgos específicos que no están presentes en la impresión FDM. Estas normas son **obligatorias** para todos los usuarios de las impresoras Photon Mono 2 en el aula STEAM:

1. **Protección personal obligatoria**: Todo usuario debe usar guantes de nitrilo, mascarilla con filtro orgánico y gafas de seguridad al manipular resina, piezas sin curar o alcohol isopropílico. No se permite la operación de la impresora sin el equipo de protección adecuado.

2. **Ventilación**: Las impresoras deben estar ubicadas en un área bien ventilada. Si el aula no tiene ventilación natural suficiente, se debe usar un extractor o campana extractora. Nunca operar las impresoras en espacios cerrados sin ventilación.

3. **Prohibido comer y beber**: No se permite consumir alimentos ni bebidas en la zona de impresión con resina. Las manos deben lavarse completamente después de manipular resina, incluso si se usaron guantes.

4. **Contacto con la piel**: Si la resina entra en contacto con la piel, lavar inmediatamente con abundante agua y jabón. No usar solventes en la piel. Si se produce irritación o reacción alérgica, buscar atención médica.

5. **Contacto con los ojos**: Si la resina salpica los ojos, enjuagar con agua durante al menos 15 minutos y buscar atención médica inmediatamente.

6. **Inhalación**: Si se experimenta mareo, náuseas o irritación respiratoria, alejarse del área de inmediato y buscar aire fresco. Reportar el incidente al coordinador.

### 9.2 Normas de operación

1. **Autorización**: Solo estudiantes que hayan recibido la capacitación completa de seguridad y operación pueden usar las impresoras de resina. Los estudiantes nuevos deben ser supervisados por el coordinador o un estudiante experimentado certificado.

2. **Reserva de uso**: Dado que hay dos unidades, se debe utilizar el sistema de reservas del aula para programar el uso de las impresoras. Cada estudiante o grupo debe registrar su impresión en el cuadro de control, indicando: fecha, hora de inicio, resina utilizada, archivo y nombre del responsable.

3. **Supervisión**: Las impresoras de resina no deben operarse sin supervisión prolongada. Si una impresión va a durar varias horas, el responsable debe verificar periódicamente su progreso o hacer los arreglos para que otro estudiante monitoree.

4. **No modificar la configuración de fábrica**: Los estudiantes no deben modificar la configuración interna de la impresora (firmware, calibración de luz) sin autorización expresa del coordinador. Los parámetros de impresión se ajustan en el slicer, no en la impresora.

5. **Limpieza obligatoria post-impresión**: Cada usuario es responsable de limpiar completamente la plataforma, la cubeta (si corresponde) y el área de trabajo después de cada sesión. No dejar resina expuesta, piezas sin curar ni herramientas sucias.

### 9.3 Normas de postprocesado

1. **Zona designada**: El lavado y curado de piezas debe realizarse exclusivamente en la zona de postprocesado designada, equipada con contenedores de IPA, estación de curado UV y material de limpieza.

2. **Desecho de residuos**: La resina sobrante filtrada se devuelve a su botella original. Los residuos de resina curada, guantes usados, papel toalla contaminado y IPA usado se depositan en los contenedores de residuos peligrosos señalizados — nunca en la basura común ni por el desagüe.

3. **Curado de residuos**: Los residuos de resina líquida (como la que queda en el filtro) deben curarse bajo luz UV antes de desecharse, para convertirlos en sólido inerte.

4. **Manejo del IPA**: El alcohol isopropílico usado es inflamable y tóxico. Almacenar en contenedores metálicos o de plástico resistente, lejos de fuentes de calor. Nunca verter IPA por el desagüe.

### 9.4 Gestión de las dos unidades

Con dos unidades de Photon Mono 2 en el aula, se establecen las siguientes directrices:

1. **Uso paralelo**: Las dos impresoras pueden operar simultáneamente para maximizar la productividad del aula. Se recomienda designar cada impresora con una etiqueta (Unidad A / Unidad B) y mantener un registro de uso independiente para cada una.

2. **Resinas diferenciadas**: Si es posible, mantener diferentes tipos de resina en cada unidad para evitar el cambio frecuente de resina, que genera desperdicio y requiere limpieza extensa. Por ejemplo: Unidad A con Standard Resin para proyectos generales, Unidad B con ABS-Like para piezas funcionales.

3. **Rotación de mantenimiento**: Cuando una unidad requiera mantenimiento (limpieza profunda, reemplazo de FEP, etc.), la otra puede seguir operando. Esto minimiza el tiempo de inactividad del área de impresión con resina.

4. **Registro de horas**: Llevar un registro aproximado de las horas de uso de cada pantalla LCD para anticipar su reemplazo. Con una vida útil de ~2 000 horas, si cada unidad imprime un promedio de 10 horas semanales, las pantallas necesitarán reemplazo aproximadamente cada 3–4 años.

5. **Kit de emergencia compartido**: Mantener un kit de emergencia (paños absorbentes, IPA extra, papel toalla, guantes adicionales) accesible para ambas unidades en caso de derrames.

### 9.5 Integración curricular STEAM

La Photon Mono 2 se integra de forma transversal en múltiples áreas del currículo STEAM:

- **Ciencia (S)**: Estudio de fotopolimerización, reacciones químicas inducidas por UV, propiedades de los materiales, toxicología básica de resinas, y principios de óptica (longitud de onda UV, transmisión de luz a través de la FEP).
- **Tecnología (T)**: Laminado digital, sistemas de control de motores paso a paso, tecnología LCD como máscara digital, software CAD/CAM, y formatos de archivo de impresión 3D.
- **Ingeniería (E)**: Diseño de piezas con tolerancias, optimización de soportes, selección de materiales según requisitos mecánicos, y procesos de postprocesado y acabado.
- **Arte (A)**: Escultura digital, diseño de miniaturas y joyería, modelado orgánico en ZBrush o Blender, y acabado y pintura de piezas impresas en resina.
- **Matemáticas (M)**: Cálculo de volúmenes y costos de resina, resolución píxel y su relación con la calidad de impresión, ángulos de inclinación óptimos, y análisis de tiempos de impresión.

---

## 10. Enlaces y recursos adicionales

### 10.1 Documentación oficial

- **Anycubic Photon Mono 2 — Página oficial del producto**: https://store.anycubic.com/products/photon-mono-2-3d-printer
- **Anycubic Wiki — Photon Mono 2**: https://wiki.anycubic.com/en/resin-3d-printer/photon-mono-2
- **Anycubic Wiki — Photon Mono 2 FAQ**: https://wiki.anycubic.com/en/resin-3d-printer/photon-mono-2/photon-mono-2-faq
- **Anycubic Wiki — Configuración de resinas**: https://wiki.anycubic.com/en/filament-and-resin/resin-settings
- **Guía de inicio rápido oficial — Unboxing y configuración**: https://store.anycubic.com/blogs/3d-printing-guides/getting-started-with-your-anycubic-photon-mono-2-unboxing-and-setting-up
- **Descarga de Photon Workshop**: Disponible en la memoria USB incluida o en el sitio de soporte de Anycubic

### 10.2 Software de laminado

- **Anycubic Photon Workshop** (gratuito): https://www.anycubic.com/software-downloads
- **CHITUBOX** (gratuito / Pro): https://www.chitubox.com
- **Lychee Slicer** (gratuito / Pro): https://mango3d.io/lychee-slicer/
- **VoxelDance Tango** (gratuito): https://www.voxeldance.com/tango

### 10.3 Recursos de aprendizaje

- **Tom's Hardware — Anycubic Photon Mono 2 Review**: https://www.tomshardware.com/reviews/anycubic-photon-mono-2
- **TechGearLab — Anycubic Photon Mono 2 Review**: https://www.techgearlab.com/reviews/cool-gadgets/3d-printer/anycubic-photon-mono-2
- **Age of Miniatures — Photon Mono 2 Review**: https://ageofminiatures.com/photon-mono-2-review
- **Liqcreate — Resin Settings for Photon Mono 2**: https://www.liqcreate.com/supportarticles/photon-mono2-resin-settings-4k
- **AmeraLabs — Resin 3D Printing Troubleshooting Guide**: https://ameralabs.com/blog/resin-3d-printing-troubleshooting/

### 10.4 Comunidad y soporte

- **Reddit — r/AnycubicPhoton**: https://www.reddit.com/r/AnycubicPhoton/
- **Facebook — Anycubic Photon Mono 2 Group**: Comunidad activa de usuarios
- **Soporte de Anycubic**: https://www.anycubic.com/support
- **Anycubic en YouTube**: Tutoriales y guías oficiales en video

### 10.5 Modelos y bibliotecas

- **Thingiverse**: https://www.thingiverse.com
- **Printables**: https://www.printables.com
- **Cults3D**: https://cults3d.com
- **MyMiniFactory**: https://www.myminifactory.com
- **NIH 3D Print Exchange** (modelos científicos): https://3dprint.nih.gov

### 10.6 Pruebas de calibración recomendadas

- **Cones of Calibration** (TableFlip Foundry): Prueba para validar la exposición correcta — ajustar el tiempo de exposición hasta que todos los conos se impriman correctamente.
- **XP Validation Matrix** (Photonsters): Matriz de validación para ajustar la exposición de forma precisa y sistemática.
- **Phrozen Finder Test**: Prueba rápida para evaluar la exposición óptima en pocas capas.
- **Anycubic Photon Test**: Modelo de prueba incluido en la memoria USB de la impresora.

---

> **Nota final**: Este manual es un documento de referencia para el aula STEAM y debe ser consultado antes de cada sesión de impresión con resina. La seguridad es la prioridad absoluta al trabajar con fotopolímeros. Ante cualquier duda, consultar siempre al coordinador del aula antes de proceder.

