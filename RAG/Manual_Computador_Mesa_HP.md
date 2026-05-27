# Manual de Referencia — Computador de Escritorio HP
## Aula STEAM — Guía Técnica Completa

---

## 1. Descripción general

El computador de escritorio HP del aula STEAM es una estación de trabajo de alto rendimiento diseñada para cubrir las necesidades más exigentes del entorno académico creativo y tecnológico. Equipado con un procesador Intel Core i9-14900 de 14.ª generación, 32 GB de memoria RAM DDR5 a 4400 MT/s, doble almacenamiento SSD NVMe de 1 TB cada uno y una tarjeta gráfica NVIDIA GeForce RTX 3050 OEM con 8 GB de VRAM dedicada, esta máquina constituye el nodo central del laboratorio para tareas de modelado 3D, desarrollo de videojuegos, programación avanzada, simulación de realidad virtual y contenido inmersivo.

La configuración de hardware refleja un equilibrio cuidadoso entre potencia de procesamiento multinúcleo y capacidad gráfica. El i9-14900, con sus 24 núcleos (8 de rendimiento y 16 de eficiencia) y 32 hilos, permite ejecutar simultáneamente entornos de desarrollo pesados como Unity o Visual Studio junto con herramientas de diseño como Autodesk Fusion o Blender sin degradación perceptible del rendimiento. Los dos SSD NVMe PCIe 4.0 ofrecen velocidades de lectura secuencial de hasta 7 000 MB/s en el Micron 3500 y 5 000 MB/s en el SK Hynix BC901, eliminando los cuellos de botella de almacenamiento que tradicionalmente limitaban los flujos de trabajo con archivos 3D de gran tamaño.

El equipo cuenta además con gráficos integrados Intel UHD Graphics 770, lo que permite manejar salidas de video duales o triples sin depender exclusivamente de la GPU dedicada. Esto resulta especialmente útil en el aula STEAM, donde se conecta una pantalla HP de 1080p a 75 Hz como monitor principal, pero se puede expandir la configuración multimonitor para proyectos que requieran mayor espacio de trabajo visual. La tarjeta gráfica RTX 3050 OEM, con sus 2 304 núcleos CUDA y soporte para ray tracing por hardware y DLSS, permite la ejecución de experiencias de PC VR a través de Meta Horizon Link, así como la aceleración por GPU en Blender, Unity y otras herramientas creativas.

El ecosistema de software instalado está cuidadosamente curado para el entorno STEAM. Incluye herramientas de modelado 3D e impresión (3D Builder, Autodesk Fusion, Blender), motores de desarrollo de videojuegos (Unity en dos versiones, Visual Studio Community 2026, VS Code, Node.js, .NET SDK), herramientas de control de versiones (Git, GitHub Desktop), software de realidad virtual y aumentada (Meta Horizon Link, Meta XR Simulator, Google Antigravity), utilidades de diagnóstico del sistema (CPU-Z, GPU-Z), y controladores específicos para periféricos del aula como la tableta Veikk. Esta combinación de hardware potente y software especializado convierte al computador HP en la pieza angular del aula STEAM para proyectos de ingeniería, diseño, desarrollo y creación de experiencias interactivas.

---

## 2. Especificaciones técnicas

### 2.1 Procesador

| Parámetro | Valor |
|---|---|
| Modelo | Intel Core i9-14900 (non-K) |
| Arquitectura | Raptor Lake Refresh (14.ª generación) |
| Socket | LGA 1700 |
| Núcleos totales | 24 (8 P-cores + 16 E-cores) |
| Hilos | 32 |
| Frecuencia base P-cores | 2.0 GHz |
| Frecuencia base E-cores | 1.5 GHz |
| Frecuencia turbo máxima | 5.8 GHz |
| Caché L3 (Intel Smart Cache) | 36 MB |
| Caché L2 total | 32 MB |
| Potencia base (PBP) | 65 W |
| Potencia turbo máxima (MTP) | 219 W |
| Litografía | Intel 7 (10 nm Enhanced) |
| Soporte de memoria | DDR5 hasta 5600 MT/s / DDR4 hasta 3200 MT/s |
| PCIe | 5.0 (hasta 16 lanes) |

### 2.2 Memoria RAM

| Parámetro | Valor |
|---|---|
| Capacidad total | 32 GB |
| Tipo | DDR5 |
| Velocidad | 4400 MT/s |
| Configuración | 2 x 16 GB (canal dual) |
| Ancho de banda teórico | 35.2 GB/s |

### 2.3 Almacenamiento principal — SSD SK Hynix BC901

| Parámetro | Valor |
|---|---|
| Modelo | SK Hynix BC901 HFS001TEJ9X108N |
| Capacidad | 1 TB |
| Interfaz | PCIe 4.0 x4 NVMe |
| Controlador | Silicon Motion SM2269XT |
| NAND | 176 capas TLC 3D (SK Hynix) |
| Caché DRAM | No |
| Lectura secuencial (máx.) | 5 000 MB/s |
| Escritura secuencial (máx.) | 4 500 MB/s |
| Lectura aleatoria (máx.) | 840K IOPS |
| Escritura aleatoria (máx.) | 890K IOPS |
| Formato | M.2 2280 |
| TBW (endurance) | 600 TB |

### 2.4 Almacenamiento secundario — SSD Micron 3500

| Parámetro | Valor |
|---|---|
| Modelo | Micron 3500 MTFDKBA1T0TGD-1BK1AABHA |
| Capacidad | 1 TB |
| Interfaz | PCIe 4.0 x4 NVMe 2.0c |
| NAND | 3D TLC de más de 200 capas (Micron) |
| Lectura secuencial (máx.) | 7 000 MB/s |
| Escritura secuencial (máx.) | 6 900 MB/s |
| Lectura aleatoria (máx.) | 1 050K IOPS |
| Escritura aleatoria (máx.) | 1 150K IOPS |
| Formato | M.2 2280 |
| TBW (endurance) | 600 TB |

### 2.5 Tarjeta gráfica dedicada — NVIDIA GeForce RTX 3050 OEM

| Parámetro | Valor |
|---|---|
| Modelo | NVIDIA GeForce RTX 3050 OEM |
| Arquitectura | Ampere (GA106) |
| Núcleos CUDA | 2 304 |
| Núcleos RT (Ray Tracing) | 20 |
| Núcleos Tensor | 72 |
| Frecuencia base | 1 510 MHz |
| Frecuencia boost | 1 760 MHz |
| Memoria VRAM | 8 GB GDDR6 |
| Bus de memoria | 128 bits |
| Velocidad de memoria | 14 Gbps |
| Ancho de banda de memoria | 224 GB/s |
| TDP | 130 W |
| Salidas de video | HDMI 2.0, DisplayPort 1.4a |
| Soporte DirectX | 12 Ultimate |
| Soporte OpenGL | 4.6 |
| Soporte Vulkan | 1.3 |
| Soporte NVENC/NVDEC | Sí (codificación/decodificación por hardware) |
| DLSS | Sí (Deep Learning Super Sampling) |

### 2.6 Gráficos integrados — Intel UHD Graphics 770

| Parámetro | Valor |
|---|---|
| Unidades de ejecución | 32 EU |
| Frecuencia base | 300 MHz |
| Frecuencia dinámica máxima | 1 650 MHz |
| Salidas soportadas | eDP 1.4b, DP 1.4a, HDMI 2.1 |
| Resolución máxima (DP) | 7 680 x 4 320 @ 60 Hz |
| Resolución máxima (HDMI) | 4 096 x 2 160 @ 60 Hz |
| Soporte Multi-Display | Hasta 3 pantallas (con GPU dedicada, hasta 4 total) |
| Quick Sync Video | Sí (codificación/decodificación por hardware) |

### 2.7 Monitor

| Parámetro | Valor |
|---|---|
| Marca | HP (incluido con el equipo) |
| Resolución | 1920 x 1080 (Full HD / 1080p) |
| Tasa de refresco | 75 Hz |
| Tipo de panel | IPS (típico en monitores HP de esta categoría) |

### 2.8 Conectividad y puertos (estimación basada en plataforma HP con i9-14900)

| Tipo | Cantidad / Detalle |
|---|---|
| USB-A 3.2 Gen 1 | 4 (típico) |
| USB-A 2.0 | 2 |
| USB-C (con DisplayPort) | 1 |
| HDMI | 1 (en GPU dedicada) |
| DisplayPort | 1 (en GPU dedicada) |
| RJ-45 Ethernet | 1 (Gigabit) |
| Audio (line-in, line-out, mic) | 3 conectores 3.5 mm |
| Lector de tarjetas SD | 1 (típico HP) |

### 2.9 Software instalado

| Programa | Versión | Categoría |
|---|---|---|
| 3D Builder (Microsoft) | — | Modelado 3D / Impresión 3D |
| Antigravity (Google) | 1.22.2 | IDE orientado a agentes de IA |
| Autodesk Access | 2.21.0.559 | Gestión de cuenta Autodesk |
| Autodesk Desktop Connector | 17.10 | Sincronización en la nube Autodesk |
| Autodesk Fusion | 2701.1.27 | CAD/CAM/CAE |
| Blender | 5.0.0 | Modelado 3D / Animación / Render |
| CPUID CPU-Z | 2.20.1 | Diagnóstico de hardware |
| Git | 2.53.0.3 | Control de versiones |
| GitHub Desktop | 3.5.8 | Interfaz gráfica para Git |
| Meta Horizon Link | 1.115.0 | PC VR / Conexión con Meta Quest |
| Meta XR Simulator | — | Simulación de realidad extendida |
| Microsoft .NET SDK | 10.0.300 | Desarrollo .NET |
| Microsoft Visual Studio Code | 1.120.0 | Editor de código |
| Node.js | 24.14.1 | Entorno de ejecución JavaScript |
| NVIDIA Drivers | 591.74 | Controladores de GPU |
| TechPowerUp GPU-Z | 2.69.0 | Diagnóstico de GPU |
| Unity 6000.0.70f1 | LTS | Motor de videojuegos (versión LTS) |
| Unity 6000.3.10f1 | Latest | Motor de videojuegos (última) |
| Unity Hub | 3.16.3 | Gestor de versiones Unity |
| Veikk Tablet Driver | 3.5.9.13 | Controlador de tableta gráfica |
| Visual Studio Community 2026 | 18.6.0 | IDE completo para desarrollo |

---

## 3. Componentes y partes

### 3.1 Gabinete exterior

El computador HP viene en un gabinete de torre media diseñado para ofrecer un flujo de aire eficiente y acceso relativamente sencillo a los componentes internos. La carcasa exterior está fabricada en acero con paneles laterales, uno de los cuales puede ser de cristal templado en configuraciones orientadas a gaming o estaciones de trabajo visuales. El panel frontal incluye el botón de encendido con indicador LED de estado, puertos USB de acceso rápido, conectores de audio y, en algunos modelos, un lector de tarjetas SD. Los paneles laterales se desmontan con tornillos de mariposa o mecanismo de liberación rápida, facilitando el acceso para mantenimiento y actualizaciones.

La parte posterior del gabinete alberga el panel de puertos de la placa madre (USB, Ethernet, audio, salidas de video de la GPU integrada) y las salidas de video de la tarjeta gráfica dedicada (HDMI y DisplayPort). También se encuentra aquí la fuente de alimentación con su conector de corriente y el interruptor de encendido de la fuente. Las rejillas de ventilación trasera y superior permiten la evacuación del aire caliente generado por los componentes internos, mientras que las entradas de aire frontal e inferior suministran aire fresco al sistema.

### 3.2 Procesador y disipador

El Intel Core i9-14900 está montado en el socket LGA 1700 de la placa madre. Dado que se trata de la versión non-K (no desbloqueada para overclock), el disipador incluido de fábrica por HP suele ser un cooler de torre con heatpipes de cobre y ventilador de 92 mm, suficiente para las frecuencias stock del procesador. El disipador se sujeta al socket mediante un sistema de anclaje de cuatro puntos. La pasta térmica preaplicada entre el IHS del procesador y la base del disipador garantiza la transferencia térmica adecuada.

El procesador en sí es un chip de considerable tamaño que integra los 24 núcleos (8 P-cores con Hyper-Threading y 16 E-cores sin HT), 36 MB de caché L3 compartida y el controlador de memoria dual-channel DDR4/DDR5. La versión non-K opera con un PBP (Processor Base Power) de 65 W, significativamente menor que los 125 W de la variante K, lo que reduce las exigencias térmicas y de energía del sistema completo. Sin embargo, bajo carga turbo sostenida, el procesador puede consumir hasta 219 W (MTP), momento en el cual el disipador debe disipar calor de manera eficiente para evitar el thermal throttling.

### 3.3 Memoria RAM

Los módulos de memoria DDR5 están instalados en los slots DIMM de la placa madre, ocupando probablemente dos de las cuatro ranuras disponibles con módulos de 16 GB cada uno para un total de 32 GB a 4400 MT/s. La DDR5 opera a un voltaje de 1.1 V (comparado con los 1.2 V de DDR4), lo que contribuye a un menor consumo energético. Los módulos cuentan con disipadores de calor metálicos que ayudan a mantener temperaturas operativas estables, especialmente importante cuando la memoria trabaja a velocidades elevadas. La configuración en canal dual duplica el ancho de banda disponible respecto a un solo módulo, beneficiando especialmente las tareas que involucran transferencias intensivas de datos como la edición de video, renderizado 3D y compilación de código.

### 3.4 Unidades de almacenamiento SSD

#### SSD principal — SK Hynix BC901 (1 TB)

Este SSD NVMe M.2 2280 está instalado en el slot M.2 primario de la placa madre, conectado directamente a través de la interfaz PCIe 4.0 x4. Aloja el sistema operativo Windows y las aplicaciones principales. Su controlador Silicon Motion SM2269XT y la NAND TLC de 176 capas de SK Hynix ofrecen un rendimiento sólido con lecturas de hasta 5 000 MB/s. Al carecer de caché DRAM dedicada, utiliza el mecanismo HMB (Host Memory Buffer) para tomar prestada una pequeña porción de la RAM del sistema como caché de mapeo, lo que resulta transparente para el usuario. En la práctica, este disco maneja de forma fluida los tiempos de arranque del sistema, la carga de aplicaciones pesadas como Unity y Blender, y la lectura de archivos de proyecto de gran tamaño.

#### SSD secundario — Micron 3500 (1 TB)

El segundo SSD NVMe M.2 2280 ocupa el slot M.2 secundario de la placa madre. Al ser un Micron 3500 con NAND TLC de más de 200 capas y soporte NVMe 2.0c, ofrece el rendimiento más alto del sistema con lecturas de hasta 7 000 MB/s y escrituras de hasta 6 900 MB/s. Este disco se utiliza preferentemente como unidad de proyectos y datos: aquí se almacenan los archivos de Unity, las escenas de Blender, los proyectos de Fusion 360, los repositorios de Git y cualquier otro dato de trabajo que se beneficie de la máxima velocidad de transferencia. La separación de sistema y datos en dos SSD físicos distintos es una práctica recomendada que mejora tanto el rendimiento como la seguridad de los datos.

### 3.5 Tarjeta gráfica dedicada

La NVIDIA GeForce RTX 3050 OEM es una tarjeta de video de doble slot que se instala en el slot PCIe x16 principal de la placa madre. La variante OEM se diferencia de la versión retail en que cuenta con 2 304 núcleos CUDA (frente a los 2 560 de la versión de venta al público), operando a frecuencias ligeramente inferiores. No obstante, mantiene los 8 GB de memoria GDDR6 en un bus de 128 bits, lo que la hace completamente funcional para renderizado por GPU en Blender (Cycles), edición de video con aceleración NVENC, ejecución de experiencias PC VR a través de Meta Horizon Link, y aceleración de IA en aplicaciones compatibles con Tensor Cores.

La tarjeta requiere alimentación adicional desde la fuente de poder mediante un conector PCIe de 6+2 pines (8 pines). Sus salidas de video —un HDMI 2.0 y un DisplayPort 1.4a— permiten conectar el monitor principal y opcionalmente un segundo monitor o visor VR. El ventilador axial de la tarjeta se encarga de disipar los hasta 130 W de TDP, expulsando el calor hacia el interior del gabinete, de donde debe ser evacuado por los ventiladores del chasis.

### 3.6 Fuente de alimentación

La fuente de alimentación incluida en el equipo HP es una PSU de formato ATX con potencia nominal estimada entre 500 W y 600 W, suficiente para alimentar el procesador (hasta 219 W en turbo), la GPU dedicada (130 W), los dos SSD NVMe, los módulos RAM, los ventiladores del chasis y los periféricos conectados por USB. La fuente cuenta con protección contra sobretensión, subtensión, sobrecorriente y cortocircuitos. El cableado incluye los conectores ATX de 24 pines para la placa madre, el conector EPS de 8 pines para el CPU, el conector PCIe de 8 pines para la GPU, y los conectores SATA para unidades adicionales si fuesen necesarias.

### 3.7 Monitor HP 1080p 75 Hz

La pantalla HP conectada al equipo ofrece una resolución Full HD de 1920 x 1080 píxeles con una tasa de refresco de 75 Hz, una mejora respecto al estándar de 60 Hz que proporciona una experiencia visual más suave, especialmente apreciable en animaciones, navegación por la interfaz del sistema operativo y uso interactivo de herramientas de diseño. El panel IPS garantiza ángulos de visión amplios de 178 grados tanto horizontal como verticalmente, así como una reproducción de color fiel con cobertura típica del espacio sRGB superior al 99%, lo que resulta esencial para trabajos de diseño gráfico y modelado 3D donde la precisión cromática importa. El monitor se conecta a la GPU dedicada mediante cable HDMI o DisplayPort y puede ajustarse en inclinación para adaptarse a la postura del usuario.

### 3.8 Periféricos y accesorios del aula

El computador HP funciona como hub central para varios periféricos del aula STEAM. La tableta gráfica Veikk se conecta por USB y utiliza su controlador dedicado (versión 3.5.9.13) para proporcionar entrada de dibujo con presión y inclinación en Blender, Fusion y otras herramientas creativas. El visor Meta Quest, cuando se utiliza para PC VR, se conecta a través del software Meta Horizon Link ya sea por cable USB-C o de forma inalámbrica mediante Air Link, aprovechando la RTX 3050 para el renderizado de las experiencias virtuales. Teclado y ratón estándar completan la configuración básica de entrada, conectados por USB o de forma inalámbrica.

---

## 4. Configuración y puesta en marcha

### 4.1 Ubicación física y ergonomía

Antes de encender el equipo por primera vez, es fundamental seleccionar una ubicación adecuada que garantice tanto el rendimiento óptimo del hardware como la comodidad del usuario. El computador debe colocarse sobre una superficie firme y nivelada, preferiblemente un escritorio con espacio suficiente para el gabinete, el monitor, el teclado, el ratón y la tableta gráfica Veikk. Debe existir un mínimo de 10 cm de holgura alrededor del gabinete, especialmente en la parte frontal e inferior donde se encuentran las entradas de aire, y en la parte trasera y superior donde se expulsa el aire caliente. No se debe colocar el gabinete en espacios cerrados como compartimentos de escritorio sin ventilación, ya que esto provoca recirculación de aire caliente y aumenta significativamente las temperaturas internas.

El monitor debe situarse a una distancia de entre 50 y 70 cm de los ojos del usuario, con el borde superior de la pantalla a la altura de la línea de visión natural o ligeramente por debajo. La inclinación del monitor debe ajustarse para minimizar los reflejos de fuentes de luz ambientales. La tableta Veikk se ubica preferiblemente frente al teclado o a un lado, según la preferencia del usuario y el tipo de trabajo que esté realizando. Todos los cables deben organizarse de manera que no obstruyan el flujo de aire ni representen un riesgo de tropiezo.

### 4.2 Conexiones iniciales

El proceso de conexión física del equipo sigue un orden lógico para evitar daños:

1. **Monitor**: Conectar el cable HDMI o DisplayPort desde la tarjeta gráfica dedicada (no desde los puertos de la placa madre) hasta el monitor HP. Si se conecta por error a los puertos de video de la placa madre, el sistema utilizará la GPU integrada UHD 770 en lugar de la RTX 3050, resultando en un rendimiento gráfico drásticamente inferior.

2. **Periféricos**: Conectar el teclado y ratón a los puertos USB traseros del gabinete. Conectar la tableta Veikk a un puerto USB-A disponible.

3. **Red**: Conectar el cable Ethernet al puerto RJ-45 de la placa madre para acceso a red cableada. Alternativamente, configurar Wi-Fi a través del sistema operativo si la placa madre incluye adaptador inalámbrico.

4. **Alimentación**: Conectar el cable de corriente a la fuente de alimentación en la parte trasera del gabinete y luego a un enchufe o regleta con protección contra sobretensiones. Verificar que el interruptor de la fuente esté en la posición I (encendido).

5. **Visor VR** (cuando se use): Conectar el Meta Quest por cable USB-C al puerto USB-C del gabinete o configurar Air Link por Wi-Fi tras instalar Meta Horizon Link.

### 4.3 Primer encendido y configuración de Windows

Al encender el equipo por primera vez presionando el botón de encendido frontal, el sistema arrancará y mostrará el logo de HP seguido de la pantalla de configuración inicial de Windows. Durante este proceso se deben completar los siguientes pasos:

- **Idioma y región**: Seleccionar Español y la región correspondiente a la ubicación del aula.
- **Cuenta de usuario**: Crear una cuenta local o iniciar sesión con una cuenta Microsoft institucional, según las políticas del aula.
- **Actualizaciones**: Permitir que Windows Update descargue e instale todas las actualizaciones disponibles. Esto puede tardar entre 20 minutos y una hora dependiendo de la cantidad de parches pendientes.
- **Controladores**: Windows Update debería detectar e instalar automáticamente los controladores de la RTX 3050 y otros dispositivos. Sin embargo, es recomendable instalar manualmente los drivers de NVIDIA (versión 591.74 o superior) desde el sitio oficial para asegurar el rendimiento óptimo y el acceso a funciones como DLSS y NVENC.
- **Resolución del monitor**: Verificar que la resolución esté configurada en 1920 x 1080 y la tasa de refresco en 75 Hz en Configuración > Sistema > Pantalla > Configuración de pantalla avanzada.

### 4.4 Configuración del almacenamiento dual

Con dos SSD NVMe instalados, es importante establecer una organización lógica del almacenamiento:

- **Disco C: (SK Hynix BC901 — 1 TB)**: Reservado para el sistema operativo Windows y las aplicaciones instaladas. Este disco maneja el arranque del sistema y la carga de programas, beneficiándose de sus 5 000 MB/s de lectura secuencial. Se recomienda mantener al menos un 20% de espacio libre (200 GB) para asegurar el rendimiento sostenido del SSD y permitir las operaciones de recolección de basura y nivelación de desgaste del controlador.

- **Disco D: (Micron 3500 — 1 TB)**: Destinado a proyectos, datos de trabajo y archivos de usuario. Al ser el SSD más rápido del sistema con 7 000 MB/s de lectura y 6 900 MB/s de escritura, es ideal para almacenar los proyectos de Unity (que pueden ocupar varios GB cada uno), las escenas de Blender con texturas de alta resolución, los repositorios de Git con historial extenso, y los archivos de exportación de Fusion 360. Igualmente, se debe mantener un 20% de espacio libre para rendimiento óptimo.

Para mover las carpetas predeterminadas del usuario (Documentos, Descargas, Escritorio) al disco D:, hacer clic derecho sobre cada carpeta en el Explorador de archivos, seleccionar Propiedades > Ubicación > Mover, y elegir la ruta correspondiente en D:.

### 4.5 Configuración del software esencial

#### Controladores y utilidades del sistema

1. **NVIDIA Drivers 591.74**: Ya instalados. Verificar ejecutando GPU-Z y confirmando que la RTX 3050 aparece con la versión de driver correcta. En el Panel de Control de NVIDIA, configurar el modo de gestión de energía a "Preferir rendimiento máximo" para las aplicaciones 3D y VR.

2. **Veikk Tablet Driver 3.5.9.13**: Instalar desde el sitio oficial de Veikk o desde el ejecutable proporcionado. Tras la instalación, abrir la configuración del controlador para calibrar la presión del lápiz y mapear el área activa de la tableta al monitor.

3. **CPU-Z y GPU-Z**: Herramientas de diagnóstico ya instaladas que permiten verificar que todos los componentes están siendo reconocidos correctamente. Ejecutar CPU-Z y confirmar que el i9-14900 muestra 24 núcleos y 32 hilos, y que la RAM opera a 4400 MT/s. Ejecutar GPU-Z y confirmar la RTX 3050 con 8 GB GDDR6 y los drivers correctos.

#### Herramientas de desarrollo

4. **Git 2.53.0.3**: Verificar la instalación abriendo una terminal y ejecutando `git --version`. Configurar el nombre de usuario y correo con `git config --global user.name "Nombre"` y `git config --global user.email "correo@institucion.edu"`.

5. **GitHub Desktop 3.5.8**: Iniciar sesión con la cuenta de GitHub institucional. Configurar la ruta predeterminada de clonación de repositorios al disco D: para aprovechar el SSD Micron más rápido.

6. **Visual Studio Code 1.120.0**: Instalar las extensiones necesarias para el flujo de trabajo del aula: C# (para Unity), Python, Blender Development, GitLens, y cualquier otra que el proyecto requiera. Configurar la terminal integrada para usar Git Bash.

7. **Visual Studio Community 2026 18.6.0**: Durante la primera ejecución, seleccionar las cargas de trabajo necesarias: "Desarrollo para Unity", "Desarrollo de escritorio .NET", y "Desarrollo de juegos con C++". Esto instalará los SDK, compiladores y herramientas de depuración requeridos por Unity y el desarrollo .NET.

8. **Node.js 24.14.1**: Verificar con `node --version` y `npm --version`. Configurar la ruta de paquetes globales al disco D: para evitar llenar el disco C: con módulos npm.

9. **Microsoft .NET SDK 10.0.300**: Verificar con `dotnet --version`. Este SDK es necesario para proyectos .NET y para herramientas de línea de comandos que Unity puede requerir.

#### Herramientas de diseño 3D y creativas

10. **Autodesk Fusion 2701.1.27**: Al iniciar sesión con la cuenta Autodesk educativa, el software se activará con la licencia institucional. Verificar que Autodesk Access y Desktop Connector estén funcionando para la sincronización de proyectos en la nube.

11. **Blender 5.0.0**: Al ejecutar Blender por primera vez, seleccionar el modo de renderizado Cycles y verificar que la GPU RTX 3050 aparece como dispositivo de cálculo en Editar > Preferencias del sistema > Cycles Render Devices. Activar OptiX para aceleración de ray tracing por hardware.

12. **3D Builder (Microsoft)**: Aplicación de la Microsoft Store que no requiere configuración adicional. Útil para preparar modelos 3D para impresión, reparar mallas y escalar objetos.

13. **Unity Hub 3.16.3**: Iniciar sesión con la cuenta de Unity. Instalar las dos versiones de Unity disponibles (6000.0.70f1 LTS y 6000.3.10f1) a través del Hub. Configurar la ubicación de proyectos predeterminada en el disco D:. Activar la licencia educativa de Unity si está disponible.

#### Herramientas de realidad virtual y extendida

14. **Meta Horizon Link 1.115.0**: Tras la instalación, abrir la aplicación y seguir el asistente de configuración para vincular el visor Meta Quest. Configurar la calidad de renderizado según las capacidades de la RTX 3050. Para uso por cable, conectar el Quest al puerto USB-C; para uso inalámbrico, asegurarse de que el computador y el visor estén en la misma red Wi-Fi de 5 GHz.

15. **Meta XR Simulator**: Herramienta de desarrollo que permite probar aplicaciones XR sin necesidad de un visor físico. Útil para depurar y validar interacciones de realidad extendida directamente en el escritorio antes de desplegar al visor.

16. **Antigravity 1.22.2 (Google)**: IDE orientado a agentes de IA que permite desarrollar y desplegar aplicaciones inteligentes. Al iniciarlo por primera vez, se puede configurar con las credenciales de Google y ajustar las preferencias del entorno de desarrollo.

---

## 5. Guía de uso paso a paso

### 5.1 Encendido y arranque del sistema

El procedimiento de encendido del computador HP es directo pero merece atención a los detalles para asegurar un arranque limpio:

1. Verificar que el cable de corriente esté conectado y el interruptor de la fuente en posición I.
2. Presionar el botón de encendido frontal del gabinete. El LED indicador se iluminará y los ventiladores comenzarán a girar.
3. Esperar a que aparezca el logo de HP y posteriormente la pantalla de inicio de sesión de Windows. El tiempo de arranque desde un SSD NVMe es típicamente de 10 a 20 segundos hasta la pantalla de login.
4. Iniciar sesión con las credenciales del aula.
5. Verificar que la resolución de pantalla esté en 1920 x 1080 y la tasa de refresco en 75 Hz (clic derecho en el escritorio > Configuración de pantalla).

Es importante no apagar el computador mediante el interruptor de la fuente de alimentación o desconectando el cable de corriente, ya que esto puede causar corrupción de datos en los SSD. Siempre utilizar el proceso de apagado de Windows: Inicio > Encendido > Apagar.

### 5.2 Flujo de trabajo para modelado 3D con Autodesk Fusion

Fusion 360 es la herramienta primaria de diseño CAD/CAM en el aula STEAM. El flujo de trabajo típico para crear un modelo 3D para impresión es el siguiente:

1. **Inicio de sesión**: Abrir Autodesk Fusion desde el menú Inicio o el acceso directo del escritorio. La aplicación cargará y solicitará inicio de sesión con la cuenta educativa Autodesk. Si Autodesk Access ya está autenticado, Fusion abrirá directamente.

2. **Creación del proyecto**: En el panel de datos, crear un nuevo proyecto o seleccionar uno existente. Los proyectos se sincronizan automáticamente con la nube de Autodesk a través de Desktop Connector, lo que permite acceder a ellos desde otros dispositivos.

3. **Diseño**: Utilizar las herramientas de sketch (borde, rectángulo, círculo, arco) para crear el perfil 2D base. Aplicar restricciones geométricas y dimensionales para parametrizar el diseño. Luego, usar operaciones de extrusión, revolución, barrido y solevado para generar el modelo 3D. Fusion soporta modelado paramétrico, por lo que cualquier cambio en las dimensiones del sketch se propaga automáticamente al modelo 3D.

4. **Preparación para impresión**: Una vez finalizado el modelo, exportarlo en formato STL o 3MF desde Archivo > Exportar. Guardar el archivo en el disco D: en la carpeta del proyecto correspondiente.

5. **Post-procesamiento en 3D Builder**: Opcionalmente, abrir el modelo STL en 3D Builder para reparar mallas, escalar el objeto y verificar que sea imprimible. 3D Builder puede corregir automáticamente mallas no-manifold, huecos y normales invertidas que causarían fallos en la impresión.

### 5.3 Flujo de trabajo para modelado y animación con Blender

Blender 5.0.0 es la herramienta de modelado orgánico, escultura, animación y renderizado del aula. A diferencia de Fusion, que está orientado al diseño paramétrico de ingeniería, Blender ofrece libertad artística total:

1. **Configuración del renderizador**: Al abrir Blender, ir a Editar > Preferencias del sistema > Cycles Render Devices y asegurarse de que la RTX 3050 está seleccionada con OptiX activado. Esto habilita la aceleración de ray tracing por hardware, reduciendo los tiempos de renderizado significativamente (hasta 3-5 veces más rápido que renderizado en CPU).

2. **Modelado**: Utilizar las herramientas de malla (extrusión, subdivisión, bucles de borde, modificador espejo, etc.) para crear la geometría del objeto. Para escultura, cambiar al modo Sculpt y usar los pinceles de arcilla, agarre, suavizado y máscara. La presión del lápiz de la tableta Veikk se mapea automáticamente a la intensidad del pincel, proporcionando un control natural y preciso.

3. **Texturizado y materiales**: En el panel de Shading, crear materiales basados en nodos. Blender soporta PBR (Physically Based Rendering) de forma nativa, permitiendo texturas de albedo, rugosidad, metalicidad, normales y emisión. Aplicar las texturas mediante mapeo UV.

4. **Iluminación**: Configurar luces de punto, sol, área o spot. Para iluminación basada en imágenes (IBL), cargar un HDR en el nodo Environment del World.

5. **Renderizado**: Configurar las propiedades de renderizado en el panel de Output (resolución, fotogramas, formato de salida). Para animaciones, renderizar como secuencia de imágenes PNG o EXR para máxima calidad. Para imágenes estáticas, renderizar directamente a PNG o JPEG. Con la RTX 3050 y OptiX, una imagen de 1080p con iluminación global moderada puede renderizarse en minutos en lugar de horas.

### 5.4 Flujo de trabajo para desarrollo de videojuegos con Unity

Unity es el motor de desarrollo principal del aula STEAM para la creación de videojuegos y experiencias interactivas. El flujo de trabajo completo es:

1. **Gestión de versiones**: Abrir Unity Hub y seleccionar la versión de Unity adecuada para el proyecto. La versión 6000.0.70f1 (LTS) se recomienda para proyectos estables y de largo plazo, mientras que la 6000.3.10f1 ofrece las características más recientes para experimentación. Crear el proyecto seleccionando la plantilla 3D o 3D (URP) según las necesidades.

2. **Configuración del editor**: En Edit > Project Settings > Player, configurar el nombre de la compañía, la resolución del juego y la plataforma objetivo. En Quality Settings, ajustar los niveles de calidad según el hardware objetivo. Para desarrollo VR, instalar el paquete Meta XR SDK desde el Package Manager.

3. **Importación de assets**: Los modelos 3D creados en Fusion o Blender se exportan como FBX u OBJ y se importan a Unity arrastrándolos a la ventana Project. Las texturas, materiales y animaciones se importan de manera similar. Organizar los assets en carpetas lógicas (Models, Textures, Materials, Scripts, Prefabs, Scenes).

4. **Scripting**: Abrir los scripts de C# en Visual Studio Community o VS Code. El flujo típico es crear un script MonoBehaviour, declarar variables públicas para exponerlas en el Inspector, y implementar los métodos Start(), Update() y eventos como OnCollisionEnter(). Compilar y verificar que no haya errores en la Consola de Unity.

5. **Pruebas y depuración**: Utilizar el modo Play del Editor para probar la lógica del juego. Para pruebas VR, usar el Meta XR Simulator para validar interacciones sin visor, o conectar el Meta Quest mediante Horizon Link para probar en el dispositivo real.

6. **Build**: Al completar el proyecto, generar el ejecutable desde File > Build Settings. Seleccionar la plataforma (Windows, Android para Quest, WebGL para web) y configurar las opciones de build. El resultado se guarda en el disco D: en la carpeta de builds del proyecto.

### 5.5 Flujo de trabajo para realidad virtual con Meta Quest

La conexión del visor Meta Quest al computador HP permite ejecutar experiencias de PC VR que aprovechan la potencia de la RTX 3050:

1. **Preparación del visor**: Encender el Meta Quest y asegurarse de que esté cargado al menos al 50%. En el visor, ir a Configuración > Experimental > y activar la función de enlace (Link/Air Link según la versión de software del visor).

2. **Conexión por cable (Link)**: Conectar el cable USB-C de alta velocidad al puerto USB-C del computador y al visor. Abrir Meta Horizon Link en el PC. El visor mostrará un prompt de conexión; aceptar para iniciar la sesión de PC VR.

3. **Conexión inalámbrica (Air Link)**: En Meta Horizon Link, ir a Configuración > Beta > Air Link y activarlo. En el visor, ir a Configuración > Experimental > Air Link y seleccionar el computador de la lista de dispositivos disponibles. Aceptar la conexión en ambos extremos.

4. **Configuración de calidad**: En Meta Horizon Link, ajustar la resolución de renderizado y la tasa de refresco. Para la RTX 3050, se recomienda un render resolution de 1.0x y una tasa de refresco de 72 Hz para un buen equilibrio entre calidad visual y fluidez. Subir a 90 Hz si la experiencia lo permite sin perder frames.

5. **Ejecución de experiencias**: Una vez conectado, el escritorio de Windows aparece en el visor. Se pueden lanzar aplicaciones VR desde la biblioteca de SteamVR o directamente desde los accesos directos del escritorio. Para probar proyectos de Unity en VR, usar la función de Build and Run con la plataforma Android (Quest) seleccionada.

### 5.6 Flujo de trabajo para programación y control de versiones

El entorno de desarrollo del computador HP está preparado para proyectos de cualquier escala:

1. **Configuración del repositorio**: Abrir GitHub Desktop y crear un nuevo repositorio o clonar uno existente. Establecer la ruta de clonación en D:\Repos para aprovechar el SSD Micron 3500.

2. **Desarrollo en VS Code**: Abrir la carpeta del repositorio en VS Code. El editor detectará automáticamente el tipo de proyecto y sugerirá extensiones relevantes. Utilizar la terminal integrada (Ctrl+`) para ejecutar comandos de Git, npm, dotnet o cualquier otra herramienta de línea de comandos.

3. **Compromiso y sincronización**: Realizar commits frecuentes con mensajes descriptivos usando GitHub Desktop. Hacer push al repositorio remoto al final de cada sesión de trabajo para asegurar que el código esté respaldado. Para trabajo colaborativo, crear ramas (branches) para cada funcionalidad o corrección y usar pull requests para integrar cambios.

4. **Desarrollo con .NET**: Para proyectos .NET, usar Visual Studio Community 2026. Crear el proyecto desde la plantilla deseada (consola, WPF, ASP.NET Core), desarrollar en C# y ejecutar con F5 para depuración. El SDK .NET 10.0.300 proporciona acceso a las últimas características del lenguaje y del framework.

5. **Desarrollo con Node.js**: Para aplicaciones JavaScript/TypeScript, usar VS Code con la terminal integrada. Inicializar proyectos con `npm init`, instalar dependencias con `npm install`, y ejecutar con `npm start` o `npm run dev`. Node.js 24.14.1 soporta las últimas características ECMAScript.

### 5.7 Uso de Google Antigravity

Google Antigravity es un IDE de nueva generación orientado al desarrollo basado en agentes de IA. Su uso en el aula STEAM permite explorar paradigmas de programación asistida por inteligencia artificial:

1. **Apertura**: Ejecutar Antigravity desde el menú Inicio. La interfaz presenta un entorno de desarrollo integrado con un panel de chat para interactuar con el agente de IA.

2. **Creación de proyectos**: Solicitar al agente que genere la estructura base de un proyecto describiendo en lenguaje natural lo que se desea construir. El agente puede generar código, configurar archivos y proponer arquitecturas.

3. **Iteración**: Refinar el código generado mediante instrucciones adicionales. El agente puede modificar archivos existentes, agregar funcionalidades y corregir errores basándose en la retroalimentación del usuario.

4. **Integración**: Los proyectos generados en Antigravity pueden exportarse y abrirse en VS Code o Visual Studio para desarrollo manual adicional, o integrarse con repositorios Git para control de versiones.

---

## 6. Mantenimiento básico

### 6.1 Limpieza física del gabinete

El polvo es el enemigo silencioso de cualquier computador de escritorio. Se acumula gradualmente en las rejillas de ventilación, los disipadores de calor, los ventiladores y las aletas del radiador, reduciendo la eficiencia térmica y forzando a los ventiladores a girar más rápido (y con más ruido) para compensar. Para un equipo que funciona en un aula con múltiples usuarios y actividad constante, la limpieza física debe realizarse cada 3 a 4 meses.

El procedimiento es el siguiente: apagar completamente el equipo y desconectar el cable de corriente. Retirar el panel lateral del gabinete (generalmente atornillado o con liberación rápida). Utilizar aire comprimido en lata para soplar el polvo acumulado en los ventiladores del chasis, el disipador del CPU, la tarjeta gráfica y la fuente de alimentación. Mantener la lata en posición vertical para evitar que el propelente líquido entre en contacto con los componentes. Sostener los ventiladores con la mano mientras se les aplica aire comprimido para evitar que giren libremente, lo que podría dañar los rodamientos. Utilizar un pincel suave de cerdas antiestáticas para limpiar las aletas del disipador del CPU y las rejillas de ventilación. Rearmar el gabinete y reconectar todo antes de encender.

### 6.2 Mantenimiento del almacenamiento SSD

Los SSD NVMe modernos no requieren desfragmentación; de hecho, desfragmentar un SSD reduce innecesariamente su vida útil al incrementar las escrituras. Sin embargo, sí requieren atención en los siguientes aspectos:

- **Espacio libre**: Mantener al menos un 20% de espacio libre en cada SSD. Cuando un SSD se llena más allá del 80%, el controlador tiene menos bloques disponibles para la nivelación de desgaste y las operaciones de recolección de basura, lo que degrada el rendimiento de escritura significativamente. Si el disco C: (SK Hynix) se acerca a este límite, desinstalar aplicaciones innecesarias o mover datos al disco D:. Si el disco D: (Micron) se llena, archivar proyectos antiguos en almacenamiento externo.

- **TRIM**: Verificar que TRIM esté habilitado, lo cual permite al sistema operativo informar al SSD qué bloques de datos ya no están en uso y pueden ser borrados internamente. Abrir una terminal como administrador y ejecutar `fsutil behavior query DisableDeleteNotify`. Si el resultado es 0, TRIM está activo. Si es 1, ejecutar `fsutil behavior set DisableDeleteNotify 0` para activarlo.

- **Monitoreo de salud**: Utilizar herramientas como CPU-Z o software específico del fabricante para verificar la temperatura y el estado de salud de los SSD. Las temperaturas operativas normales están entre 30°C y 70°C. Si un SSD supera consistentemente los 70°C, considerar mejorar la ventilación del gabinete o instalar un disipador M.2.

### 6.3 Actualización de controladores

Los controladores (drivers) son el software que permite al sistema operativo comunicarse con el hardware. Mantenerlos actualizados es esencial para la estabilidad, el rendimiento y la seguridad:

- **NVIDIA Drivers**: Verificar periódicamente si hay nuevas versiones en el sitio de NVIDIA o a través de la aplicación NVIDIA App. Las actualizaciones de drivers pueden incluir optimizaciones de rendimiento para nuevos juegos y aplicaciones, correcciones de errores y parches de seguridad. Actualmente instalada la versión 591.74; si hay una versión más reciente estable, se puede actualizar descargándola desde nvidia.com/drivers.

- **Controlador de tableta Veikk**: Revisar el sitio de Veikk periódicamente para actualizaciones del driver que puedan mejorar la compatibilidad con nuevas versiones de Blender o corregir problemas de sensibilidad a la presión.

- **Windows Update**: Configurar Windows Update para que descargue e instale actualizaciones automáticamente, al menos las actualizaciones de seguridad. Las actualizaciones de calidad mensuales de Windows incluyen parches de seguridad y correcciones de errores que son importantes para la estabilidad del sistema.

### 6.4 Mantenimiento del monitor

La pantalla HP 1080p requiere cuidados mínimos pero importantes. Limpiar la pantalla únicamente con un paño de microfibra ligeramente humedecido con agua destilada. Nunca rociar líquido directamente sobre la pantalla ni utilizar limpiadores con alcohol, amoníaco o disolventes, ya que pueden dañar el recubrimiento antirreflectante. Limpiar con movimientos suaves y circulares desde el centro hacia los bordes. No ejercer presión excesiva sobre el panel, ya que esto puede causar daño permanente a los cristales líquidos. Revisar periódicamente los cables de conexión para asegurar que estén firmemente insertados y sin dobleces pronunciados.

### 6.5 Gestión de temperatura del sistema

Dado que el i9-14900 puede consumir hasta 219 W bajo carga turbo sostenida y la RTX 3050 aporta otros 130 W, la gestión térmica es crucial para el rendimiento a largo plazo. Se recomienda:

- **Monitoreo**: Instalar y ejecutar ocasionalmente herramientas como HWMonitor o HWiNFO para verificar las temperaturas del CPU, GPU, SSD y VRM bajo carga. Las temperaturas aceptables son: CPU hasta 95°C (throttling a 100°C), GPU hasta 83°C, SSD hasta 70°C.

- **Ventilación del gabinete**: Asegurar que los ventiladores del chasis funcionen correctamente. La configuración ideal es dos ventiladores frontales como intake (entrada de aire fresco) y un ventilador trasero más uno superior como exhaust (salida de aire caliente). Si el gabinete tiene filtros de polvo en la entrada frontal, limpiarlos mensualmente.

- **Perfil de energía del CPU**: Dado que el i9-14900 non-K tiene un PBP de 65 W, en la mayoría de las cargas de trabajo del aula (modelado 3D, programación, navegación) no se acercará al límite de 219 W. Sin embargo, en sesiones de compilación prolongadas o renderizado intensivo, es normal que el consumo suba. Si se observa throttling térmico excesivo, se puede limitar el MTP en la BIOS a 150 W o 180 W, sacrificando marginalmente el rendimiento máximo pero mejorando significativamente las temperaturas y el ruido del ventilador.

### 6.6 Respaldo de datos

La pérdida de datos en un entorno académico puede ser devastadora, especialmente cuando involucra proyectos de grado o trabajos de investigación de meses de duración. Se recomienda implementar una estrategia de respaldo 3-2-1:

- **3 copias** de los datos importantes: la copia de trabajo en el SSD, una copia local en un disco externo USB, y una copia en la nube.
- **2 medios** diferentes: SSD local y disco externo o almacenamiento en la nube.
- **1 copia fuera del sitio**: almacenamiento en la nube (Google Drive, OneDrive institucional, Autodesk Cloud para proyectos de Fusion).

Utilizar GitHub como respaldo adicional para todo el código fuente y los proyectos de Unity. Realizar commits y push al final de cada sesión de trabajo. Para archivos grandes que exceden el límite de Git LFS (modelos 3D pesados, texturas de alta resolución), utilizar el almacenamiento en la nube institucional.

---

## 7. Solución de problemas comunes

### 7.1 El equipo no enciende

Si al presionar el botón de encendido no ocurre nada (sin luces, sin sonido de ventiladores):

- **Verificar la conexión de corriente**: Asegurar que el cable de alimentación esté firmemente conectado tanto a la fuente del computador como al enchufe o regleta. Probar con otro enchufe para descartar problemas del tomacorriente.
- **Interruptor de la fuente**: Verificar que el interruptor en la parte trasera de la fuente de alimentación esté en la posición I (encendido). Si estaba en O, cambiarlo a I, esperar 10 segundos y presionar el botón de encendido frontal.
- **Regleta o UPS**: Si el equipo está conectado a una regleta con protector de sobretensiones o un UPS, verificar que la regleta esté encendida y funcionando. Algunas regletas tienen un botón de reset que debe presionarse tras una fluctuación de voltaje.
- **Fuente de alimentación dañada**: Si todo lo anterior falla, la fuente de alimentación puede haberse dañado por una sobretensión. Esto requiere intervención técnica profesional.

### 7.2 La pantalla se ve borrosa o con resolución incorrecta

Si la imagen del monitor no se ve nítida o los elementos de la interfaz aparecen demasiado grandes o pequeños:

- **Verificar la conexión del cable**: Asegurar que el cable de video (HDMI o DisplayPort) esté conectado a la tarjeta gráfica dedicada (puertos en la zona horizontal inferior trasera del gabinete) y no a los puertos de la placa madre (zona vertical superior). Si está conectado a la placa madre, el sistema utiliza la GPU integrada UHD 770 con rendimiento drásticamente inferior.
- **Ajustar resolución**: Clic derecho en el escritorio > Configuración de pantalla. Verificar que la resolución sea 1920 x 1080 (recomendada). Si aparece una resolución menor, seleccionar 1080p de la lista.
- **Ajustar tasa de refresco**: En Configuración de pantalla > Configuración de pantalla avanzada > Propiedades del adaptador de pantalla > Monitor, verificar que la tasa de refresco sea 75 Hz. Si solo aparece 60 Hz, puede ser necesario actualizar los drivers de NVIDIA o usar un cable DisplayPort en lugar de HDMI.
- **Escala de Windows**: En Configuración de pantalla, verificar que la escala esté en 100% (recomendada) o 125% según la preferencia visual del usuario.

### 7.3 Rendimiento lento o el equipo se congela

Si el computador presenta lentitud general, aplicaciones que no responden o congelamientos del sistema:

- **Verificar el uso de recursos**: Abrir el Administrador de Tareas (Ctrl+Shift+Esc) y revisar las pestañas de CPU, Memoria y Disco. Si la CPU está al 100%, identificar el proceso que consume más recursos y cerrarlo si no es esencial. Si la memoria está al 90% o más con 32 GB, es probable que haya demasiadas aplicaciones abiertas simultáneamente; cerrar las que no se necesiten. Si el disco está al 100%, puede ser que Windows esté realizando mantenimiento en segundo plano (indexación, Windows Update, antivirus); esperar unos minutos o pausar estas tareas.
- **Temperatura elevada (thermal throttling)**: Si el CPU se está ralentizando debido a temperaturas altas, el rendimiento caerá significativamente. Verificar las temperaturas con HWMonitor. Si el CPU supera los 90°C constantemente, limpiar el polvo del disipador, verificar que los ventiladores del chasis funcionen y considerar reaplicar pasta térmica.
- **SSD casi lleno**: Si el disco C: tiene menos del 15% de espacio libre, el rendimiento general del sistema se degradará notablemente. Liberar espacio desinstalando aplicaciones innecesarias, vaciando la papelera de reciclaje y ejecutando el Liberador de espacio en disco.
- **Malware**: Ejecutar un análisis completo con Windows Defender para descartar infecciones que puedan consumir recursos en segundo plano.

### 7.4 La tarjeta gráfica no es detectada

Si las aplicaciones 3D (Blender, Unity, juegos) no reconocen la RTX 3050 o el rendimiento gráfico es inusualmente bajo:

- **Verificar en el Administrador de dispositivos**: Abrir el Administrador de dispositivos (Win+X > Administrador de dispositivos) y expandir la sección "Adaptadores de pantalla". Deben aparecer tanto "NVIDIA GeForce RTX 3050" como "Intel UHD Graphics 770". Si la RTX 3050 aparece con un icono de advertencia amarillo, hay un problema con el controlador.
- **Reinstalar drivers**: Descargar los últimos drivers de NVIDIA desde nvidia.com/drivers y realizar una instalación limpia (seleccionar "Instalación personalizada" > "Realizar una instalación limpia"). Esto elimina los drivers anteriores y reemplaza completamente los archivos.
- **Verificar la alimentación PCIe**: La RTX 3050 requiere un conector de alimentación PCIe de 8 pines desde la fuente. Si este conector está suelto o no conectado, la tarjeta puede aparecer en el Administrador de dispositivos pero no funcionar correctamente. Apagar el equipo, abrir el gabinete y verificar que el conector esté firmemente insertado.
- **Reasiento de la tarjeta**: En casos extremos, la tarjeta gráfica puede haberse desplazado ligeramente de su slot PCIe x16. Apagar el equipo, desconectar la corriente, abrir el gabinete, liberar el seguro del slot PCIe, retirar la tarjeta, limpiar los contactos con alcohol isopropílico y volver a insertarla firmemente hasta que el seguro haga clic.

### 7.5 Blender no utiliza la GPU para renderizado

Si los renders en Blender tardan excesivamente o el renderizador Cycles solo usa la CPU:

- **Verificar la configuración de Cycles**: En Editar > Preferencias del sistema > Cycles Render Devices, asegurar que la RTX 3050 está seleccionada y que la opción OptiX está marcada. OptiX aprovecha los núcleos RT de la tarjeta para acelerar el trazado de rayos por hardware.
- **Propiedades de renderizado**: En el panel de Properties > Render Properties, seleccionar Cycles como motor de renderizado. En la sección de Device, seleccionar "GPU Compute". Si solo aparece "CPU", la configuración de Preferencias del sistema no se ha guardado correctamente; cerrar y reabrir Blender.
- **Memoria VRAM insuficiente**: Si la escena excede los 8 GB de VRAM de la RTX 3050, Blender puede revertir automáticamente al renderizado por CPU. Reducir la complejidad de la escena (menos polígonos, texturas más pequeñas, menos muestras de luz) o activar la opción "Out of Memory" en las preferencias de Cycles para manejo de memoria excedida.

### 7.6 Problemas de conexión con Meta Quest

Si el visor Meta Quest no se conecta al PC o la experiencia VR es inestable:

- **Conexión por cable**: Usar un cable USB-C de alta velocidad que soporte transferencia de datos y alimentación simultáneamente (el cable oficial Meta Link o un cable USB 3.0 de calidad). Verificar que el puerto USB-C del PC sea de tipo USB 3.0 o superior (los puertos USB 2.0 no proporcionan suficiente ancho de banda). En Meta Horizon Link, ir a Configuración > Dispositivos y verificar que el Quest aparezca como conectado.
- **Conexión inalámbrica (Air Link)**: Asegurar que el PC y el Quest estén en la misma red Wi-Fi de 5 GHz. La red 2.4 GHz no proporciona suficiente ancho de banda para VR fluida. Verificar que no haya obstáculos significativos entre el router y el visor. Si la conexión es inestable, acercarse al router o considerar un enlace por cable.
- **Rendimiento VR bajo**: Si la experiencia se ve entrecortada o con lag, reducir la resolución de renderizado en Meta Horizon Link y la tasa de refresco a 72 Hz. Cerrar aplicaciones en segundo plano que consuman GPU. Verificar que los drivers de NVIDIA estén actualizados.
- **Meta Horizon Link no detecta el visor**: Reiniciar la aplicación Meta Horizon Link, reiniciar el visor Quest (mantener presionado el botón de encendido > Reiniciar) y reconectar. Si el problema persiste, desinstalar y reinstalar Meta Horizon Link.

### 7.7 Unity no abre o muestra errores de licencia

Si Unity muestra errores de licencia o no se abre:

- **Verificar la licencia**: Abrir Unity Hub > Configuración (engranaje) > Licenses. Verificar que haya una licencia activa (Personal si no se tiene licencia Pro). Si la licencia expiró, reactivarla seleccionando "Activate New License" > "Personal" > "I don't use Unity in a professional capacity".
- **Versión de Unity corrupta**: Si una versión específica de Unity no se abre, abrir Unity Hub > Installs, eliminar la versión problemática y reinstalarla. Los proyectos no se eliminan al desinstalar una versión de Unity.
- **Falta de módulos**: Si al abrir un proyecto faltan módulos (por ejemplo, soporte para Android/Quest), abrir Unity Hub > Installs > seleccionar la versión > Add Modules e instalar los módulos necesarios (Android Build Support, Windows Build Support, etc.).

### 7.8 La tableta Veikk no responde

Si la tableta gráfica Veikk no detecta el lápiz o no se mueve el cursor:

- **Verificar la conexión USB**: Desconectar y reconectar el cable USB de la tableta. Probar en otro puerto USB. Evitar hubs USB pasivos que pueden no proporcionar suficiente energía.
- **Reinstalar el controlador**: Desinstalar el controlador Veikk desde Configuración > Aplicaciones, reiniciar el PC e instalar la versión 3.5.9.13 desde el sitio oficial de Veikk. Es importante reiniciar el PC entre la desinstalación y la reinstalación.
- **Conflicto con otros controladores de tableta**: Si se instalaron previamente controladores de otra tableta (Wacom, Huion), pueden entrar en conflicto con el driver Veikk. Desinstalar todos los controladores de tableta anteriores antes de instalar el de Veikk.
- **Calibración**: Abrir la configuración del controlador Veikk y verificar que el área activa esté correctamente mapeada al monitor. Si el cursor no llega a los bordes de la pantalla, puede ser necesario recalibrar el mapeo de la tableta.

---

## 8. Materiales, repuestos y accesorios

### 8.1 Repuestos recomendados

| Componente | Especificación | Notas |
|---|---|---|
| Pasta térmica | Noctua NT-H1 o Arctic MX-6 | Para reaplicación en el CPU cada 2-3 años |
| Cable HDMI 2.0 | 1.5 a 2 m | Repuesto para la conexión del monitor |
| Cable DisplayPort 1.4 | 1.5 a 2 m | Alternativa superior al HDMI para 1080p 75 Hz |
| Cable USB-C (Link) | USB 3.2 Gen 2, 3-5 m | Para conexión del Meta Quest por cable |
| Batería CR2032 | 3 V | Para la pila de la BIOS de la placa madre (vida útil ~5 años) |

### 8.2 Accesorios complementarios

| Accesorio | Función en el aula STEAM |
|---|---|
| Hub USB 3.0 (4-7 puertos) | Expandir conectividad para múltiples periféricos simultáneos |
| Disco duro externo USB 3.0 (2-4 TB) | Respaldo de proyectos y archivos pesados |
| Segundo monitor 1080p o 1440p | Ampliar el espacio de trabajo para diseño 3D y desarrollo |
| Alfombrilla de mesa grande | Superficie estable para ratón y tableta Veikk |
| Regleta con protección contra sobretensiones | Proteger el equipo de picos de voltaje |
| UPS (Sistema de alimentación ininterrumpida) 600-800 VA | Evitar pérdida de datos por cortes de energía repentinos |
| Soporte para monitor (VESA) | Mejorar la ergonomía del puesto de trabajo |
| Mando de Xbox o controlador genérico | Para pruebas de juegos desarrollados en Unity |

### 8.3 Actualizaciones posibles

El computador HP tiene un potencial de actualización considerable gracias a la plataforma LGA 1700 y la fuente de alimentación con margen:

- **Memoria RAM**: La placa madre probablemente tiene 4 slots DIMM. Si actualmente están ocupados 2 slots con módulos de 16 GB cada uno, se pueden agregar otros 2 módulos de 16 GB DDR5 4400 MT/s para alcanzar 64 GB totales. Esto beneficia enormemente los flujos de trabajo con escenas 3D complejas en Blender y proyectos grandes de Unity.

- **Tarjeta gráfica**: El slot PCIe x16 y la fuente de alimentación permiten una futura actualización a una RTX 4060, RTX 4070 o superior, siempre que la fuente tenga potencia suficiente (verificar que la PSU sea de al menos 650 W para una RTX 4070). Una GPU más potente mejoraría significativamente el rendimiento en PC VR, renderizado GPU y modelado interactivo de escenas complejas.

- **Almacenamiento**: Los slots M.2 adicionales (si están disponibles en la placa madre) o los puertos SATA permiten agregar más almacenamiento. Si los dos SSD M.2 de 1 TB se llenan, se puede agregar un SSD SATA de 2 TB como unidad de archivado o instalar un tercer SSD NVMe M.2 si la placa madre tiene un slot libre.

- **Refrigeración**: Si se experimentan temperaturas altas bajo carga sostenida, se puede reemplazar el disipador de stock por un cooler de torre de mayor capacidad (Noctua NH-U12A, be quiet! Dark Rock 4) o incluso un sistema de refrigeración líquida AIO de 240 mm, siempre que el gabinete lo permita.

---

## 9. Normas de uso STEAM

### 9.1 Normas generales de operación

El computador de escritorio HP es un recurso compartido del aula STEAM y su uso está sujeto a las siguientes normas obligatorias:

1. **Reserva y turno de uso**: Dado que existe un solo equipo de estas características en el aula, los estudiantes deben reservar su turno de uso a través del sistema de coordinación del aula. Cada sesión tiene una duración máxima de 2 horas, renovable si no hay otros estudiantes en espera. Al finalizar la sesión, se debe cerrar sesión en Windows y dejar el escritorio limpio y ordenado.

2. **No instalar software no autorizado**: El software instalado ha sido curado para las necesidades del aula. No se debe instalar aplicaciones adicionales sin autorización del coordinador. Esto incluye extensiones de navegador, plugins no verificados y especialmente software de dudosa procedencia que podría comprometer la seguridad del equipo.

3. **No modificar la configuración del sistema**: No se deben cambiar configuraciones críticas del sistema como las opciones de energía de la BIOS, la configuración de red, los controladores de hardware o las particiones de disco sin autorización. Si se necesita un ajuste específico para un proyecto, consultar al coordinador.

4. **Cuidado con los archivos**: No eliminar archivos o carpetas de otros usuarios. Cada estudiante debe trabajar en su propia carpeta dentro de D:\Proyectos con su nombre o equipo. Los archivos en C: son de sistema y aplicaciones; no deben modificarse.

5. **Uso responsable de recursos**: Evitar ejecutar procesos que consuman recursos excesivos (como renders largos) durante las horas pico de uso del aula. Programar renders intensivos para momentos de baja demanda o utilizar las opciones de renderizado en segundo plano con prioridad baja.

### 9.2 Normas de seguridad eléctrica

6. **No desconectar cables con el equipo encendido**: Excepto los periféricos USB diseñados para conexión en caliente (teclado, ratón, tableta), no desconectar cables de video, alimentación o red mientras el equipo está encendido.

7. **No colocar líquidos cerca del equipo**: Bebidas, agua y otros líquidos deben mantenerse a distancia segura del gabinete, el monitor y los periféricos. Un derrame sobre el teclado o el gabinete puede causar cortocircuitos costosos.

8. **Apagado correcto**: Siempre apagar el equipo a través de Windows (Inicio > Apagar). Nunca usar el botón de encendido prolongadamente (forzar apagado) a menos que el sistema esté completamente congelado y no responda a ninguna otra acción. Nunca desconectar el cable de corriente mientras el equipo está encendido.

9. **Protección contra sobretensiones**: El equipo debe estar conectado a una regleta con protector contra sobretensiones o, idealmente, a un UPS. Esto protege los componentes sensibles (SSD, RAM, placa madre) de daños por picos de voltaje.

### 9.3 Normas de uso de software por categoría

10. **Herramientas de diseño 3D (Fusion, Blender, 3D Builder)**:
    - Guardar el trabajo frecuentemente (Ctrl+S). Blender no guarda automáticamente por defecto; activar el auto-guardado en Editar > Preferencias > Guardar y cargar > Auto Save.
    - No renderizar escenas de alta resolución durante las horas de uso intensivo del aula. Programar renders para momentos de baja demanda.
    - Al terminar la sesión, cerrar Blender y Fusion para liberar la memoria VRAM y RAM para el siguiente usuario.

11. **Herramientas de desarrollo (Unity, VS Code, Visual Studio, Git)**:
    - No almacenar repositorios Git de gran tamaño sin necesidad. Clonar solo los repositorios necesarios para el proyecto actual y eliminar los que ya no se usen.
    - Hacer commit y push de los cambios al repositorio remoto al final de cada sesión. No dejar cambios sin commitear que puedan perderse.
    - Cerrar Unity antes de abandonar el equipo. Unity consume recursos significativos incluso cuando el editor está en segundo plano.

12. **Herramientas de VR (Meta Horizon Link, Meta XR Simulator)**:
    - No alterar la configuración de calidad de renderizado de Meta Horizon Link sin consultar al coordinador. Una configuración inadecuada puede hacer que la experiencia VR sea inutilizable para los siguientes usuarios.
    - Al terminar la sesión de VR, desconectar el visor y cerrar Meta Horizon Link completamente. El software de VR en ejecución consume recursos de GPU incluso cuando no se está usando activamente.
    - Manipular el visor Meta Quest con cuidado: no dejarlo caído, no exponer las lentes a la luz solar directa y limpiarlas solo con el paño de microfibra incluido.

13. **Herramientas de IA (Antigravity)**:
    - Utilizar Antigravity de forma responsable y académica. El código generado por agentes de IA debe ser revisado y comprendido antes de integrarse en proyectos de curso.
    - No ingresar datos sensibles o personales en el agente de IA.

### 9.4 Normas de convivencia y coordinación

14. **Comunicación de incidencias**: Si el equipo presenta cualquier anomalía (ruidos extraños, pantallazos azules, lentitud inusual, errores de software), reportarlo inmediatamente al coordinador del aula a través del canal establecido (formulario, correo electrónico o sistema de tickets). No intentar reparar problemas de hardware sin autorización.

15. **Limpieza del puesto de trabajo**: Al finalizar la sesión, recoger todos los objetos personales, organizar los cables de periféricos y dejar la mesa libre para el siguiente usuario. Si se usó la tableta Veikk, guardar el lápiz en su soporte y cubrir la tableta si tiene funda protectora.

16. **No almacenar archivos personales permanentemente**: Los archivos de proyectos deben respaldarse en medios personales (USB, nube) y eliminarse del disco D: una vez finalizado el proyecto del semestre. El coordinador realizará una limpieza de archivos huérfanos al final de cada período académico.

17. **Uso prioritario**: En caso de demanda concurrente, el uso del computador HP tiene prioridad para proyectos que requieran su capacidad específica (renderizado GPU, VR, modelado 3D pesado) sobre tareas que puedan realizarse en equipos de menores especificaciones (navegación web, procesamiento de texto, programación ligera).

---

## 10. Enlaces y recursos adicionales

### 10.1 Documentación oficial de hardware

| Recurso | Enlace |
|---|---|
| Intel Core i9-14900 — Especificaciones oficiales | https://www.intel.com/content/www/us/en/products/sku/236793/intel-core-i9-processor-14900-36m-cache-up-to-5-80-ghz/specifications.html |
| NVIDIA GeForce RTX 3050 — Página oficial | https://www.nvidia.com/en-us/geforce/graphics-cards/30-series/rtx-3050 |
| NVIDIA Drivers — Descarga | https://www.nvidia.com/drivers |
| Intel UHD Graphics 770 — Información | https://www.intel.com/content/www/us/en/support/articles/000057657/graphics.html |
| SK Hynix BC901 — Base de datos TechPowerUp | https://www.techpowerup.com/ssd-specs/sk-hynix-bc901-1-tb.d2375 |
| Micron 3500 NVMe SSD — Página oficial | https://www.micron.com/products/storage/ssd/client-ssd/3500-ssd |
| Micron 3500 — Base de datos TechPowerUp | https://www.techpowerup.com/ssd-specs/micron-3500-1-tb.d1798 |

### 10.2 Documentación de software

| Recurso | Enlace |
|---|---|
| Autodesk Fusion — Documentación | https://help.autodesk.com/view/fusion360/ESP/ |
| Blender 5.0 — Manual oficial | https://docs.blender.org/manual/en/latest/ |
| Unity 6000 — Documentación | https://docs.unity3d.com/6000.0/Documentation/Manual/ |
| Unity Hub — Guía | https://docs.unity3d.com/hub/manual/ |
| Visual Studio Code — Documentación | https://code.visualstudio.com/docs |
| Visual Studio 2026 — Documentación | https://learn.microsoft.com/en-us/visualstudio/ |
| Node.js — Documentación | https://nodejs.org/docs/latest/api/ |
| Microsoft .NET SDK — Documentación | https://learn.microsoft.com/en-us/dotnet/ |
| Git — Documentación oficial | https://git-scm.com/doc |
| GitHub Desktop — Guía | https://docs.github.com/en/desktop |
| Meta Horizon Link — Centro de ayuda | https://www.meta.com/help/quest/1517439565442928/ |
| Meta XR Simulator — Documentación para desarrolladores | https://developer.meta.com/resources/xr-simulator/ |
| Google Antigravity — Primeros pasos | https://codelabs.developers.google.com/getting-started-google-antigravity |
| 3D Builder — Soporte de Microsoft | https://support.microsoft.com/ |
| Veikk — Soporte y drivers | https://www.veikk.com/support |

### 10.3 Tutoriales y cursos recomendados

| Recurso | Descripción |
|---|---|
| Blender Guru (YouTube) | Tutoriales de Blender desde principiante hasta avanzado, incluyendo la serie "Donut" |
| Unity Learn (learn.unity.com) | Plataforma oficial de aprendizaje de Unity con proyectos guiados |
| Autodesk Fusion 360 Academy | Cursos oficiales de Autodesk para aprender modelado CAD/CAM |
| NVIDIA DLSS / RTX — Guías de desarrollador | Documentación técnica para integrar DLSS y ray tracing en proyectos Unity |
| Meta Developer Hub | Recursos para desarrollo de aplicaciones XR para Meta Quest |
| The Cherno (YouTube) | Tutoriales de C++, OpenGL y desarrollo de motores de juego |
| Freecodecamp — C# y .NET | Cursos gratuitos de programación en C# y el ecosistema .NET |

### 10.4 Herramientas de diagnóstico y monitoreo

| Herramienta | Función | Enlace |
|---|---|---|
| CPU-Z | Información detallada del CPU, RAM y placa madre | https://www.cpuid.com/softwares/cpu-z.html |
| GPU-Z | Información detallada de la GPU y monitoreo de sensores | https://www.techpowerup.com/gpuz/ |
| HWMonitor | Monitoreo de temperaturas, voltajes y ventiladores | https://www.cpuid.com/softwares/hwmonitor.html |
| HWiNFO | Diagnóstico avanzado del hardware con reportes detallados | https://www.hwinfo.com/ |
| CrystalDiskInfo | Salud y estado de los SSD (SMART) | https://crystalmark.info/en/software/crystaldiskinfo/ |
| CrystalDiskMark | Benchmark de velocidad de almacenamiento | https://crystalmark.info/en/software/crystaldiskmark/ |
| NVIDIA-SMI | Monitoreo de GPU desde la línea de comandos | Incluido con los drivers NVIDIA |

### 10.5 Comunidad y soporte

| Recurso | Descripción |
|---|---|
| Foro oficial de Blender | Comunidad de usuarios de Blender para resolver dudas y compartir conocimientos |
| Unity Forums | Foro oficial de la comunidad Unity con secciones para principiantes y expertos |
| Stack Overflow | Preguntas y respuestas sobre programación en C#, Python, JavaScript y más |
| GitHub Community | Foro de la comunidad de GitHub para dudas sobre Git y colaboración |
| Reddit r/blender | Subreddit activo con tutoriales, obras y ayuda técnica |
| Reddit r/Unity3D | Subreddit para discusiones sobre desarrollo en Unity |
| Intel Community | Foro de soporte de Intel para procesadores y gráficos integrados |
| NVIDIA GeForce Forums | Foro oficial para dudas sobre drivers, rendimiento y configuración de GPU |

---

*Manual elaborado para el aula STEAM — Equipo de cómputo de escritorio HP con Intel Core i9-14900, RTX 3050 OEM y doble SSD NVMe. Documento de referencia interna para estudiantes y coordinadores.*
