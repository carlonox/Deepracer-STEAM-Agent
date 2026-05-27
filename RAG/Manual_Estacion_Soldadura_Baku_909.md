# Manual de Referencia — Estación de Soldadura Baku BK-909

> **Aula STEAM — Manual de consulta para estudiantes y asistente robótico**
> Unidades en el aula: **1**

---

## 1. Descripción general

La **Baku BK-909** (también referida como BK-909S) es una estación de soldadura multifuncional tipo **3 en 1** que integra en un solo equipo tres herramientas esenciales para el trabajo de electrónica: una **estación de soldadura con cautín** (soldering iron), una **estación de aire caliente** (hot air gun) para retrabajo SMD, y una **fuente de alimentación regulable** de corriente continua. Esta combinación la convierte en una de las estaciones más versátiles dentro de su gama, ya que permite al operador soldar componentes, desoldar y retrabajar componentes de montaje superficial (SMD), y alimentar circuitos de prueba o componentes individuales, todo desde una misma unidad central. Con una potencia total de 700 W y control microcomputarizado con tecnología PID, la BK-909 ofrece una temperatura precisa y estable tanto en el cautín como en la pistola de aire caliente, lo cual es fundamental para el trabajo con componentes electrónicos sensibles que requieren un control térmico estricto.

En el contexto del aula STEAM, la Baku BK-909 es una pieza fundamental del inventario de herramientas de electrónica. Permite a los estudiantes realizar soldadura de componentes through-hole y SMD, desoldar componentes para corrección de errores o reciclaje de placas, retrabajar conexiones en placas de circuito impreso, y probar circuitos mediante su fuente de alimentación incorporada. La estación utiliza un microprocesador interno que monitorea y ajusta la temperatura en tiempo real mediante un algoritmo PID (Proporcional-Integral-Derivativo), garantizando que las fluctuaciones térmicas sean mínimas (estabilidad de ±1 °C en condiciones ideales). Esta característica es especialmente importante en el trabajo educativo, donde los estudiantes están aprendiendo las técnicas de soldadura y necesitan condiciones predecibles y consistentes para desarrollar sus habilidades. La pantalla LED frontal muestra las temperaturas actuales de ambos canales (cautín y aire caliente), así como los valores de voltaje y corriente de la fuente de alimentación, proporcionando información completa del estado de la máquina en todo momento.

La Baku BK-909 pertenece a la familia de estaciones de retrabajo de la marca Baku, reconocida en el mercado latinoamericano por ofrecer equipos de electrónica con buena relación calidad-precio. La variante BK-909S es esencialmente el mismo modelo con ligeros cambios cosméticos o de stock; ambos se utilizan de manera idéntica. La estación incorpora un motor sin escobillas (brushless) para la generación de flujo de aire caliente, lo que garantiza una larga vida útil del ventilador y un funcionamiento silencioso (menos de 45 dB). El cautín utiliza un calentador cerámico de 75 W que alcanza la temperatura de trabajo en aproximadamente 8–10 segundos, y su punta cromada con recubrimiento de níquel ofrece buena transferencia de calor y resistencia a la corrosión. La fuente de alimentación DC integrada proporciona hasta 15 V y 1 A, suficiente para alimentar microcontroladores, LEDs, pequeños motores y circuitos de prueba, lo que complementa perfectamente la funcionalidad de soldadura y permite un flujo de trabajo integrado sin necesidad de equipos adicionales.

---

## 2. Especificaciones técnicas

| Parámetro | Valor |
|---|---|
| **Modelo** | Baku BK-909 / BK-909S |
| **Tipo** | Estación de retrabajo 3 en 1 (Cautín + Aire caliente + Fuente DC) |
| **Potencia total** | 700 W |
| **Voltaje de entrada** | AC 110 V / 220 V, 50/60 Hz (según versión) |
| **Control de temperatura** | Microcomputadora con chip PID |
| **Display** | Pantalla LED de 3 dígitos (temperaturas, voltaje, corriente) |

### 2.1 Especificaciones del cautín

| Parámetro | Valor |
|---|---|
| **Potencia del cautín** | 75 W |
| **Tipo de calentador** | Cerámico |
| **Rango de temperatura** | 200 °C – 480 °C |
| **Estabilidad de temperatura** | ±1 °C (en condiciones ideales) |
| **Tipo de punta** | Compatible con puntas serie 900M |
| **Longitud del mango (con cable)** | 120 cm |
| **Material del mango** | Silicona anti-quemadura |
| **Material de la punta** | Acero inoxidable 306, cromado, con capas de níquel |

### 2.2 Especificaciones de la pistola de aire caliente

| Parámetro | Valor |
|---|---|
| **Rango de temperatura del aire** | 100 °C – 480 °C |
| **Flujo de aire máximo** | 120 L/min |
| **Tipo de ventilador** | Motor sin escobillas (brushless) |
| **Tipo de bomba de aire** | Bomba de diafragma |
| **Cantidad de boquillas incluidas** | 3 boquillas intercambiables |
| **Función de aire frío** | Sí (cold air) |
| **Ruido** | < 45 dB |
| **Longitud del mango (con cable)** | 120 cm |
| **Sistema de suspensión automática** | Detección por magnetismo — al colocar la pistola en el soporte, el aire caliente se detiene automáticamente |

### 2.3 Especificaciones de la fuente de alimentación DC

| Parámetro | Valor |
|---|---|
| **Voltaje de salida** | 0 – 15 V DC (regulable) |
| **Corriente máxima** | 1 A |
| **Tipo de regulación** | Lineal, con perilla de ajuste |
| **Pantalla** | Voltaje y corriente en display LED |
| **Conectores de salida** | Terminales banana (para cable pulpo y cable caimán) |
| **Detección de señal GSD** | Sí |

### 2.4 Especificaciones físicas

| Parámetro | Valor |
|---|---|
| **Dimensiones de la unidad** | Aprox. 187 × 135 × 245 mm (base principal) |
| **Peso neto** | 3,5 – 4 kg (según variante) |
| **Peso del paquete** | Aprox. 5,6 kg |
| **Color** | Gris oscuro / negro (según lote) |
| **Material de la carcasa** | Aleación de aluminio y plástico ABS de alta resistencia |

---

## 3. Componentes y partes

### 3.1 Componentes principales

1. **Unidad base (estación principal)**: Es el cuerpo central de la máquina que aloja la electrónica de control, el microprocesador PID, los transformadores, la pantalla LED y los controles de ajuste. En el panel frontal se encuentran las perillas y botones de control para cada una de las tres funciones, así como los displays LED que muestran las temperaturas del cautín y del aire caliente, y los valores de voltaje y corriente de la fuente DC. En la parte superior de la base se ubican los conectores donde se insertan los cables del cautín y de la pistola de aire caliente, así como los terminales de salida de la fuente de alimentación.

2. **Cautín (soldering iron)**: El mango del cautín contiene el calentador cerámico de 75 W y la punta de soldadura intercambiable. El mango está recubierto de silicona térmicamente aislante que permite un agarre cómodo y seguro incluso durante sesiones prolongadas de trabajo. El cable de conexión al cuerpo principal tiene una longitud de 120 cm, lo que proporciona suficiente libertad de movimiento. La punta del cautín es del tipo 900M, ampliamente disponible en el mercado, lo que facilita su reposición y permite usar diferentes geometrías de punta según la tarea (cónica, en forma de cincel, en bisel, etc.).

3. **Pistola de aire caliente (hot air gun)**: La pistola de aire caliente genera un flujo de aire calentado que se utiliza principalmente para el retrabajo de componentes SMD (desoldar y resoldar chips, resistencias, condensadores de montaje superficial, etc.). El mango de la pistola incluye un sensor magnético que, al colocar la pistola en su soporte integrado, envía una señal a la estación para detener automáticamente la salida de aire caliente, prolongando la vida útil del calentador y ahorrando energía. La pistola viene con tres boquillas intercambiables de diferentes diámetros que se adaptan a distintos tamaños de componentes.

4. **Soporte para cautín**: Estructura metálica acoplada a la base de la máquina donde se coloca el cautín cuando no está en uso. El soporte incluye una esponja de limpieza (o esponja metálica) que permite retirar los restos de soldadura oxidada de la punta del cautín entre soldaduras. Es fundamental utilizar el soporte en todo momento cuando el cautín no está en la mano para evitar quemaduras y daños a la mesa de trabajo.

5. **Soporte para pistola de aire caliente**: Soporte integrado en la carcasa de la máquina donde se coloca la pistola cuando no está en uso. El soporte contiene un imán que activa el sensor de suspensión automática de la pistola. Es importante colocar siempre la pistola en su soporte después de usarla, no solo por la función de auto-suspensión, sino también porque la boquilla puede estar extremadamente caliente durante varios minutos después de su uso.

6. **Fuente de alimentación DC integrada**: Los terminales de salida de la fuente se encuentran en el panel frontal de la máquina, generalmente como conectores banana de color rojo (+) y negro (-). La fuente permite ajustar el voltaje de salida de 0 a 15 V con una corriente máxima de 1 A, lo que la hace adecuada para alimentar circuitos de prueba, microcontroladores (Arduino, ESP32, etc.), motores pequeños, LEDs y otros componentes de bajo consumo.

7. **Panel de control**: Conjunto de perillas rotatorias, botones y pantallas LED situados en la parte frontal de la máquina. Incluye: perilla de ajuste de temperatura del cautín, perilla de ajuste de temperatura del aire caliente, perilla de ajuste de voltaje de la fuente DC, pantalla LED para cada función, y botones de encendido/apagado para cada canal.

### 3.2 Accesorios incluidos en la caja

- Unidad base de la estación BK-909
- Cautín con punta semi-fina (tipo 900M)
- Pistola de aire caliente
- 3 boquillas intercambiables para aire caliente (diámetros pequeños, mediano y grande)
- Soporte para cautín con esponja de limpieza
- Cable pulpo (cable de prueba con conectores banana en un extremo y pinzas en el otro)
- Cable caimán (cable con pinzas cocodrilo para conexiones de prueba)
- Manual de usuario
- Cable de alimentación AC

### 3.3 Repuestos y consumibles

| Repuesto / Consumible | Descripción |
|---|---|
| Puntas de cautín serie 900M | Disponibles en múltiples geometrías: cónica, cincel, bisel, en forma de cuchillo |
| Boquillas para aire caliente | Diferentes diámetros para componentes de distintos tamaños |
| Esponja de limpieza para cautín | Esponja de celulosa o metálica para limpieza de la punta |
| Calentador cerámico de cautín (75 W) | Elemento calefactor de repuesto |
| Calentador de aire caliente | Elemento calefactor de repuesto para la pistola |
| Cable de cautín | Cable de conexión de repuesto (120 cm) |
| Cable de pistola de aire caliente | Cable de conexión de repuesto (120 cm) |
| Hilo de soldadura | Consumible — aleación Sn63/Pb37 o Sn60/Pb40 (con plomo) o SAC305 (libre de plomo) |
| Flux o pasta de soldar | Consumible — facilita la adherencia de la soldadura |
| Pasta termoconductora | Para retrabajo de componentes con disipadores |

---

## 4. Configuración y puesta en marcha

### 4.1 Preparación del espacio de trabajo

La estación de soldadura Baku BK-909 debe ubicarse en un lugar que cumpla con ciertos requisitos esenciales de seguridad y funcionalidad:

- **Ventilación**: La soldadura con plomo y los flux generan humos que contienen partículas y compuestos orgánicos volátiles (COV) perjudiciales para la salud. El área de trabajo debe estar bien ventilada, idealmente con un extractor de humos o una campana extractora. Si no se dispone de extracción mecánica, trabajar cerca de una ventana abierta o usar un ventilador que aleje los humos del rostro del operador. En el aula STEAM, designar una zona específica para soldadura con ventilación adecuada.

- **Superficie estable y resistente al calor**: La estación debe reposar sobre una superficie firme, nivelada y resistente al calor. Evitar superficies de plástico o madera sin protección, ya que las salpicaduras de soldadura caliente pueden dañarlas. Se recomienda usar una alfombrilla de silicona para soldadura o una superficie de trabajo de fibra de vidrio sobre la mesa.

- **Acceso a toma de corriente**: La máquina requiere una conexión a AC 110 V o 220 V según la versión. Asegurarse de que la toma esté accesible y que el cable no represente un riesgo de tropiezo. No usar extensiones de baja calidad ni sobrecargar la toma con múltiples equipos de alta potencia.

- **Área libre de materiales inflamables**: La soldadura y el aire caliente implican temperaturas de hasta 480 °C. Mantener lejos del área de trabajo materiales inflamables como papel, cartón, telas, solventes, alcohol isopropílico y aerosoles. Si se trabaja con IPA (por ejemplo, para limpieza), mantenerlo en un contenedor cerrado y lejos de la estación.

- **Iluminación adecuada**: La soldadura de componentes pequeños requiere buena visibilidad. Asegurarse de que el área esté bien iluminada. Si es posible, usar una lámpara de trabajo con luz blanca fría y, opcionalmente, una lupa o microscopio de soldadura para componentes SMD.

### 4.2 Desempaque e inspección

1. Retirar la máquina de la caja con cuidado. La unidad base, el cautín, la pistola de aire caliente y los accesorios suelen venir empaquetados por separado con espuma de protección.
2. Verificar que todos los componentes estén presentes: unidad base, cautín con punta, pistola de aire caliente, 3 boquillas, soporte para cautín, cable pulpo, cable caimán, cable de alimentación y manual de usuario.
3. Inspeccionar el cuerpo del cautín para confirmar que la punta esté correctamente instalada y que no haya daños visibles en el mango o el cable.
4. Verificar que la pistola de aire caliente no tenga obstrucciones en la salida de aire y que el cable esté en buen estado.
5. Comprobar que las pantallas LED de la unidad base no tengan rayones ni daños.
6. Inspeccionar los cables de alimentación y de conexión del cautín y la pistola para asegurar que no estén pelados, aplastados ni enroscados.

### 4.3 Montaje inicial

1. **Colocar la unidad base**: Posicionar la estación en la superficie de trabajo definitiva. Asegurarse de que esté nivelada y de que haya espacio suficiente alrededor para maniobrar el cautín y la pistola sin obstáculos.

2. **Instalar el soporte del cautín**: Acoplar el soporte metálico para el cautín en su posición correspondiente en la unidad base. Colocar la esponja de limpieza en la bandeja del soporte y humedecerla ligeramente con agua destilada (si es esponja de celulosa). La esponja metálica no requiere humedecimiento.

3. **Conectar el cautín**: Insertar el conector del cable del cautín en el receptáculo correspondiente de la unidad base (generalmente marcado con un ícono de cautín o la palabra "IRON"). Asegurarse de que el conector entre firmemente.

4. **Conectar la pistola de aire caliente**: Insertar el conector del cable de la pistola en el receptáculo correspondiente (marcado con "AIR" o un ícono de aire caliente). Verificar la conexión firme.

5. **Instalar las boquillas de aire caliente**: Seleccionar la boquilla de tamaño adecuado y deslizarla sobre la salida de aire de la pistola. Las boquillas deben ajustarse firmemente pero sin forzarlas. Si están muy holgadas, pueden vibrar durante el uso; si están muy apretadas, pueden ser difíciles de retirar cuando la pistola está caliente.

6. **Conectar la alimentación**: Conectar el cable de alimentación AC a la unidad base y luego a la toma de corriente. En este punto, la máquina aún no debe encenderse.

7. **Primera prueba de encendido**:
   - Encender la estación con el interruptor principal (generalmente en la parte posterior o lateral de la unidad).
   - Verificar que las pantallas LED se iluminen y muestren los valores de temperatura y voltaje.
   - Ajustar la temperatura del cautín a 250 °C y observar si la temperatura sube gradualmente hasta alcanzar el valor ajustado.
   - Ajustar la temperatura del aire caliente a 300 °C y verificar que la pistola comience a emitir aire caliente.
   - Probar la fuente DC ajustando el voltaje a 5 V y midiendo la salida con un multímetro para confirmar que el voltaje sea correcto.
   - Apagar la estación y permitir que se enfríe.

### 4.4 Configuración de la temperatura de trabajo

La temperatura adecuada depende del tipo de soldadura y los componentes:

| Tipo de soldadura | Temperatura del cautín | Temperatura del aire caliente |
|---|---|---|
| Soldadura con plomo (Sn63/Pb37) | 280 °C – 320 °C | 300 °C – 350 °C |
| Soldadura libre de plomo (SAC305) | 320 °C – 380 °C | 350 °C – 420 °C |
| Retrabajo SMD de componentes pequeños (0402, 0603) | 280 °C – 320 °C | 280 °C – 320 °C |
| Retrabajo SMD de componentes medianos (QFP, SOIC) | 300 °C – 350 °C | 300 °C – 380 °C |
| Retrabajo de chips grandes (QFP, BGA) | No aplicable | 350 °C – 450 °C |
| Encogimiento de tubo termoencogible | No aplicable | 120 °C – 200 °C |

---

## 5. Guía de uso paso a paso

### 5.1 Soldadura con cautín (soldering)

La soldadura con cautín es la función más utilizada de la estación y permite crear uniones eléctricas permanentes entre componentes y pistas de circuito impreso.

**Paso 1 — Preparación del cautín**
1. Encender la estación y ajustar la temperatura del cautín al valor adecuado según el tipo de soldadura (ver tabla en sección 4.4).
2. Esperar a que la pantalla LED indique que se ha alcanzado la temperatura objetivo (aproximadamente 8–10 segundos desde el encendido).
3. Limpiar la punta del cautín pasándola suavemente por la esponja húmeda o la esponja metálica del soporte para eliminar cualquier residuo de óxido o soldadura anterior.
4. Estañar la punta: aplicar una pequeña cantidad de soldadura fresca a la punta del cautín para cubrirla con una fina capa brillante. Esto mejora la transferencia de calor y protege la punta de la oxidación. La punta estañada debe verse brillante y uniforme, no opaca ni negra.

**Paso 2 — Preparación de la unión**
1. Asegurarse de que las superficies a soldar estén limpias y libres de oxidación. Si es necesario, usar un poco de flux o limpiar con alcohol isopropílico y un cepillo suave.
2. Aplicar una pequeña cantidad de flux a las zonas a soldar. El flux facilita la adherencia de la soldadura y previene la formación de puentes de soldadura no deseados.
3. Posicionar el componente en la placa de circuito impreso y asegurar que las patillas estén alineadas con las pistas o los agujeros.

**Paso 3 — Soldadura de componentes through-hole**
1. Sostener el cautín como un lápiz, con la punta en contacto simultáneo con la patilla del componente y la pista de cobre o la almohadilla del circuito impreso. La punta debe tocar ambas superficies para calentarlas uniformemente.
2. Mantener el cautín en posición durante 1–2 segundos para calentar la zona.
3. Aplicar el hilo de soldadura por el lado opuesto a la punta del cautín, no directamente sobre la punta. La soldadura debe fluir hacia la zona caliente por capilaridad.
4. Retirar el hilo de soldadura primero, luego retirar el cautín. El resultado debe ser una unión cónica y brillante (forma de "volcán" o "tienda de campaña") que cubra tanto la patilla como la almohadilla sin exceso de material.
5. Inspeccionar la soldadura visualmente: debe ser brillante (con soldadura con plomo) o ligeramente mate (con soldadura libre de plomo), sin grietas, sin puentes entre pistas adyacentes, y sin bordes redondeados que indiquen una unión fría.

**Paso 4 — Soldadura de componentes SMD**
1. Para componentes SMD de dos terminales (resistencias, condensadores, diodos): aplicar una pequeña cantidad de soldadura a una de las almohadillas con el cautín, colocar el componente con pinzas, y luego soldar la otra almohadilla. Volver a soldar la primera almohadilla si es necesario.
2. Para componentes con muchas patillas (ICs, QFPs): aplicar flux a las almohadillas, alinear el componente, soldar dos patillas en esquinas opuestas para fijar el componente, y luego soldar las patillas restantes arrastrando la punta del cautín con un poco de soldadura a lo largo de los pines. El flux ayudará a prevenir puentes.

**Paso 5 — Limpieza de la punta después de soldar**
1. Después de cada soldadura o cada pocas soldaduras, limpiar la punta del cautín en la esponja húmeda o metálica.
2. Volver a estañar la punta con una pequeña cantidad de soldadura fresca antes de dejar el cautín en el soporte. La capa de estaño protege la punta de la oxidación durante los periodos de inactividad.
3. Nunca dejar el cautín encendido a alta temperatura sin usar durante periodos prolongados (más de 5–10 minutos), ya que esto acelera la oxidación y el desgaste de la punta. Si no se va a usar por un rato, reducir la temperatura o apagar el cautín.

### 5.2 Desoldadura y retrabajo con aire caliente (hot air rework)

La pistola de aire caliente es la herramienta principal para desoldar y resoldar componentes de montaje superficial (SMD) sin dañarlos ni dañar la placa.

**Paso 1 — Selección de la boquilla**
1. Seleccionar la boquilla adecuada según el tamaño del componente:
   - **Boquilla pequeña (diámetro ~5 mm)**: Para componentes discretos pequeños (0402, 0603, SOT-23, etc.).
   - **Boquilla mediana (diámetro ~8 mm)**: Para componentes de tamaño medio (SOIC, SOT-223, condensadores tántalo, etc.).
   - **Boquilla grande (diámetro ~12 mm o rectangular)**: Para chips grandes (QFP, QFN, BGA, etc.). Algunas boquillas rectangulares se adaptan a la forma del chip para calentarlo uniformemente.
2. Instalar la boquilla en la pistola de aire caliente empujándola firmemente sobre la salida de aire.

**Paso 2 — Configuración de la temperatura y el flujo de aire**
1. Encender la estación y ajustar la temperatura del aire caliente al valor adecuado (ver tabla en sección 4.4). Para la mayoría de los trabajos SMD, 300 °C – 350 °C es un buen punto de partida.
2. Ajustar el flujo de aire (si la estación lo permite, mediante una perilla separada). Un flujo bajo es preferible para componentes pequeños, ya que un flujo alto puede soplar componentes fuera de posición. Para chips grandes, se puede usar un flujo mayor.
3. Esperar a que la pantalla LED indique que la temperatura objetivo ha sido alcanzada.

**Paso 3 — Aplicación de flux**
1. Aplicar flux líquido o en gel a las patillas del componente que se va a desoldar. El flux reduce la tensión superficial de la soldadura fundida, facilitando su remoción y evitando puentes.
2. Para componentes SMD de dos terminales, aplicar flux a ambos lados.
3. Para ICs con muchas patillas, aplicar flux a lo largo de todos los lados del componente.

**Paso 4 — Desoldadura del componente**
1. Sostener la pistola de aire caliente a una distancia de 2–5 cm de la superficie del componente. No tocar el componente ni la placa con la boquilla.
2. Mover la pistola en círculos lentos y uniformes alrededor del componente para calentar todas las patillas de manera pareja. Evitar mantener el aire caliente en un solo punto por mucho tiempo, ya que esto puede quemar la placa o el componente.
3. Después de 10–30 segundos (dependiendo del tamaño del componente y la temperatura), la soldadura de todas las patillas debería estar fundida. Se puede notar un brillo metálico en las patillas cuando la soldadura está líquida.
4. Usando pinzas antiestáticas o un ventoso (suction tool), levantar suavemente el componente de la placa. No forzar; si el componente no se desprende fácilmente, aplicar más calor unos segundos más.
5. Colocar el componente retirado en una superficie resistente al calor para que se enfríe.

**Paso 5 — Resoldadura del componente**
1. Limpiar las almohadillas de la placa de restos de soldadura vieja usando una malla de desoldar (solder wick) y el cautín, o applying fresh solder and then removing it with a desoldering pump.
2. Alinear el nuevo componente en las almohadillas usando pinzas. Para ICs, verificar que la patilla 1 (marcada con un punto o muesca) esté correctamente orientada.
3. Aplicar flux a las almohadillas y las patillas.
4. Soldar dos patillas en esquinas opuestas con el cautín para fijar el componente.
5. Aplicar aire caliente con la pistola para soldar el resto de las patillas simultáneamente, o soldar patilla por patilla con el cautín si se prefiere mayor control.

**Paso 6 — Función de aire frío**
1. Después de completar el retrabajo, se puede usar la función de aire frío (cold air) para acelerar el enfriamiento de la zona trabajada. Esto es útil cuando se necesita hacer varias operaciones consecutivas en la misma zona y no se puede esperar a que se enfríe naturalmente.
2. Activar la función de aire frío (generalmente mediante un botón o interruptor en la pistola o en el panel de control). El ventilador funcionará sin activar el calentador, emitiendo aire a temperatura ambiente.
3. No apagar la estación inmediatamente después de usar aire caliente; permitir que el calentador se enfríe gradualmente con la función de aire frío durante 30–60 segundos antes de apagar. Esto prolonga la vida útil del calentador.

### 5.3 Uso de la fuente de alimentación DC

La fuente de alimentación integrada proporciona energía regulada para pruebas y alimentación de circuitos.

**Paso 1 — Conexión de los cables**
1. Insertar el cable pulpo o el cable caimán en los terminales de salida de la fuente en el panel frontal. El conector rojo va al terminal positivo (+) y el negro al terminal negativo (-).
2. Conectar el otro extremo de los cables al circuito o componente a alimentar, respetando la polaridad.

**Paso 2 — Ajuste del voltaje**
1. Antes de conectar el circuito, ajustar el voltaje de salida al valor deseado usando la perilla de ajuste de voltaje. Siempre empezar con un voltaje bajo e incrementar gradualmente.
2. Verificar el voltaje de salida en la pantalla LED antes de conectar el circuito para evitar sobretensiones que puedan dañar componentes sensibles.
3. Para microcontroladores como Arduino (5 V) o ESP32 (3,3 V), ajustar con precisión el voltaje y verificar con un multímetro antes de la conexión.

**Paso 3 — Monitoreo de la corriente**
1. La pantalla LED muestra la corriente consumida por el circuito conectado. Si la corriente alcanza o supera 1 A (límite máximo), la fuente puede entrar en modo de protección y cortar la salida.
2. Si el circuito no funciona y la corriente es cero, verificar las conexiones y asegurarse de que el circuito esté completo.
3. Si la corriente es inusualmente alta al conectar el circuito, desconectar inmediatamente y buscar cortocircuitos o componentes dañados.

**Paso 4 — Desconexión**
1. Apagar o reducir el voltaje de la fuente antes de desconectar los cables del circuito.
2. Retirar los cables del circuito y luego de los terminales de la fuente.

---

## 6. Mantenimiento básico

### 6.1 Mantenimiento de la punta del cautín

La punta del cautín es el componente más sometido a desgaste y el que más mantenimiento requiere. Una punta en mal estado produce soldaduras de mala calidad, transfiere el calor de forma ineficiente y puede dañar los componentes:

- **Estañado continuo**: La regla más importante para el cuidado de la punta es mantenerla siempre estañada. Después de cada uso, aplicar una pequeña cantidad de soldadura fresca a la punta antes de colocarla en el soporte. Esta capa de estaño actúa como barrera protectora contra la oxidación. Una punta seca y caliente se oxida en cuestión de segundos, volviéndose negra e inutilizable.

- **Limpieza con esponja**: Usar la esponja húmeda (celulosa) o la esponja metálica del soporte para limpiar la punta entre soldaduras. La esponja de celulosa debe estar húmeda pero no empapada; el exceso de agua puede causar choque térmico en la punta. Pasar la punta suavemente por la esponja con un movimiento rotatorio. No frotar con fuerza ni usar materiales abrasivos.

- **No usar limas ni papel de lija**: Nunca limar o lijar la punta del cautín para retirar óxido. Las puntas modernas tienen un recubrimiento de hierro/cromo/níquel que, si se elimina, expone el cobre interior que se desgasta rápidamente. Si la punta está tan oxidada que no se puede recuperar con estaño fresco y flux, debe reemplazarse.

- **Activación de puntas oxidadas**: Si la punta está ligeramente oxidada (color gris oscuro pero no negra), se puede intentar reactivarla aplicando flux activo y estaño fresco a la temperatura de trabajo, frotando suavemente contra la esponja metálica. Los limpiadores de punta comerciales (tip activator/tinner) también son eficaces para recuperar puntas moderadamente oxidadas.

- **Temperatura de reposo**: Si se va a pausar el trabajo por 2–5 minutos, no apagar el cautín sino reducir la temperatura a 200 °C – 250 °C. Muchos ciclos de calentamiento y enfriamiento aceleran el desgaste de la punta más que mantenerla a temperatura moderada.

### 6.2 Mantenimiento de la pistola de aire caliente

- **Limpieza de la boquilla**: Después de cada uso, retirar la boquilla cuando se haya enfriado y limpiar cualquier residuo de flux o soldadura con IPA y un paño suave. Las boquillas sucias pueden obstruir el flujo de aire y distribuir el calor de forma desigual.

- **Limpieza del filtro de aire**: Algunos modelos de la BK-909 incluyen un filtro de entrada de aire en la parte posterior de la máquina. Si el filtro está sucio, limpiarlo con aire comprimido o reemplazarlo. Un filtro obstruido reduce el flujo de aire y puede causar sobrecalentamiento.

- **Inspección del calentador**: Si la pistola tarda más de lo habitual en alcanzar la temperatura o no llega a la temperatura máxima, el calentador interno puede estar degradado. El reemplazo del calentador requiere desmontar la pistola y debe ser realizado por el coordinador o un técnico.

- **Almacenamiento**: Siempre colocar la pistola en su soporte cuando no esté en uso. Nunca dejar la pistola encendida y desatendida sobre la mesa de trabajo. La función de auto-suspensión al colocar la pistola en el soporte es una característica de seguridad y ahorro de energía que debe utilizarse siempre.

### 6.3 Mantenimiento de la fuente de alimentación DC

- **Limpieza de los terminales**: Los terminales banana del panel frontal pueden acumular suciedad u óxido con el tiempo. Limpiar periódicamente con un hisopo de algodón e IPA para garantizar una buena conexión eléctrica.

- **Verificación de calibración**: Comprobar periódicamente la precisión del voltaje de salida con un multímetro digital. Si el voltaje mostrado en la pantalla difiere significativamente del medido (más de ±0,2 V), puede ser necesario recalibrar la fuente.

- **No sobrecargar**: La fuente tiene un límite de 1 A. Nunca intentar extraer más corriente de la permitida, ya que esto puede dañar la fuente y el circuito conectado. Si el circuito requiere más de 1 A, usar una fuente de alimentación externa de mayor capacidad.

### 6.4 Mantenimiento general de la estación

- **Limpieza exterior**: Limpiar la carcasa de la máquina con un paño suave ligeramente humedecido con agua. No usar solventes agresivos (acetona, lejía, alcohol concentrado) que puedan dañar el plástico o las etiquetas.

- **Inspección de cables**: Verificar periódicamente que los cables del cautín, la pistola y la alimentación AC no estén pelados, aplastados ni enroscados. Los cables dañados deben reemplazarse inmediatamente.

- **Almacenamiento**: Cuando la estación no se vaya a usar durante periodos prolongados (vacaciones, etc.), apagarla, desconectarla de la corriente y cubrirla con una funda protectora para evitar la acumulación de polvo.

### 6.5 Calendario de mantenimiento sugerido

| Frecuencia | Tarea |
|---|---|
| **Después de cada uso** | Limpiar y estañar la punta del cautín, limpiar la boquilla de la pistola, colocar todo en sus soportes |
| **Semanal** | Inspección visual de cables, verificación de la esponja de limpieza, limpieza de terminales de la fuente |
| **Mensual** | Verificación de calibración de temperatura (cautín y aire), calibración del voltaje de la fuente con multímetro, limpieza del filtro de aire |
| **Trimestral** | Inspección completa de todas las puntas de cautín, reemplazo de puntas desgastadas, limpieza interior del soporte del cautín |
| **Semestral** | Revisión general de la estación, verificación de conexiones internas, evaluación del estado del calentador cerámico y del calentador de aire |

---

## 7. Solución de problemas comunes

### 7.1 El cautín no calienta o no alcanza la temperatura

**Causas posibles:**
- Conexión floja del cable del cautín a la unidad base
- Calentador cerámico dañado o fundido
- Punta del cautín mal instalada o sucia
- Problema con la electrónica de control del canal del cautín
- Ajuste de temperatura muy bajo en el panel de control

**Soluciones:**
1. Verificar que el cable del cautín esté firmemente conectado al receptáculo de la unidad base. Desconectar y volver a conectar.
2. Comprobar que la temperatura ajustada sea la adecuada (mínimo 200 °C para que la soldadura se funda).
3. Si la pantalla muestra la temperatura pero la punta no se calienta, el calentador cerámico puede estar dañado. Reemplazar el calentador o el cautín completo.
4. Si la pantalla no muestra temperatura, puede haber un problema con el sensor térmico o la conexión interna. Contactar al coordinador o soporte técnico.

### 7.2 La punta del cautín se oxida rápidamente

**Causas posibles:**
- Falta de estañado después del uso
- Temperatura de trabajo excesivamente alta
- Uso de soldadura de baja calidad o con poco flux
- Punta vieja con el recubrimiento protector desgastado
- Ambiente de trabajo con alta humedad

**Soluciones:**
1. Estañar siempre la punta después de cada sesión de soldadura. La capa de estaño es la protección contra la oxidación.
2. No trabajar a temperaturas más altas de las necesarias. Una temperatura de 320 °C es suficiente para la mayoría de las soldaduras con plomo; temperaturas superiores a 380 °C aceleran drásticamente la oxidación.
3. Usar soldadura de buena calidad con núcleo de flux. El flux ayuda a mantener la punta limpia durante la soldadura.
4. Si la punta está muy oxidada, intentar reactivarla con un limpiador/activador de puntas comercial. Si no se recupera, reemplazar la punta.
5. Almacenar el cautín con la punta estañada en el soporte. No dejar la punta descubierta de estaño durante periodos de inactividad.

### 7.3 La pistola de aire caliente no emite aire o no calienta

**Causas posibles:**
- La pistola no está correctamente conectada a la unidad base
- Motor sin escobillas (brushless) dañado
- Calentador de la pistola fundido
- Boquilla obstruida
- Función de auto-suspensión activada (la pistola está en el soporte)

**Soluciones:**
1. Verificar que el cable de la pistola esté firmemente conectado al receptáculo de la unidad base.
2. Retirar la pistola del soporte para desactivar la función de auto-suspensión. La pistola solo emite aire caliente cuando está fuera del soporte.
3. Comprobar que la boquilla no esté obstruida por residuos de flux o soldadura. Retirar la boquilla (cuando esté fría) e inspeccionar.
4. Si la pistola no emite aire pero el display muestra temperatura, el motor puede estar dañado. Requiere reparación técnica.
5. Si la pistola emite aire frío pero no caliente, el calentador interno puede estar fundido. Reemplazar el calentador.

### 7.4 Soldaduras frías o que no se adhieren

**Causas posibles:**
- Temperatura del cautín insuficiente
- Superficie sucia, oxidada o con residuos
- Falta de flux
- Punta del cautín sucia o desgastada
- Tipo de soldadura inadecuado (libre de plomo a temperatura baja)

**Soluciones:**
1. Aumentar la temperatura del cautín en incrementos de 20 °C y verificar si la soldadura fluye mejor.
2. Limpiar las superficies a soldar con IPA y aplicar flux fresco antes de soldar.
3. Limpiar la punta del cautín en la esponja y volver a estañarla. Una punta sucia no transfiere el calor eficazmente.
4. Si se usa soldadura libre de plomo, aumentar la temperatura a 320 °C – 350 °C, ya que su punto de fusión es más alto (aprox. 217 °C vs 183 °C de la aleación con plomo).
5. Asegurarse de que la punta del cautín esté en contacto simultáneo con ambas superficies (patilla y almohadilla) durante al menos 1–2 segundos antes de aplicar la soldadura.

### 7.5 Puentes de soldadura entre patillas

**Causas posibles:**
- Exceso de soldadura aplicada
- Falta de flux
- Punta del cautín demasiado grande para el componente
- Soldadura de mala calidad que no fluye bien

**Soluciones:**
1. Usar una punta de cautín más fina (cónica o tipo cincel pequeño) para componentes de paso fino.
2. Aplicar flux antes de soldar. El flux ayuda a que la soldadura fluya solo hacia las zonas metálicas y no forme puentes.
3. Para retirar puentes existentes, usar malla de desoldar (solder wick): colocar la malla sobre el puente, aplicar el cautín encima de la malla, y la soldadura excesiva será absorbida por capilaridad.
4. Aplicar menos soldadura. Es mejor aplicar poca y agregar más si es necesario que aplicar demasiado y tener que retirar el exceso.

### 7.6 La fuente DC no proporciona voltaje o corriente

**Causas posibles:**
- Conexiones flojas en los terminales
- Cortocircuito en el circuito conectado
- Protección contra sobrecorriente activada
- Fusible interno de la fuente fundido
- Perilla de voltaje en posición mínima

**Soluciones:**
1. Verificar que las conexiones en los terminales banana estén firmes y que los cables no estén dañados.
2. Desconectar el circuito y verificar si la fuente muestra voltaje sin carga. Si muestra voltaje sin carga pero cae a cero al conectar, hay un cortocircuito en el circuito.
3. Si la protección de sobrecorriente se ha activado, desconectar la carga, apagar la fuente, esperar unos segundos y volver a encender.
4. Ajustar la perilla de voltaje y verificar que no esté en la posición mínima (0 V).
5. Si la fuente no muestra voltaje alguno en la pantalla, el fusible interno puede estar fundido. Requiere reparación por el coordinador o técnico.

### 7.7 La pantalla LED muestra valores incorrectos

**Causas posibles:**
- Necesidad de calibración
- Sensor de temperatura defectuoso
- Interferencia electromagnética de equipos cercanos
- Problema con la electrónica de control

**Soluciones:**
1. Verificar la temperatura real del cautín con un medidor de temperatura externo (termopar o pirómetro). Si la diferencia es superior a ±10 °C, es necesario recalibrar la estación.
2. Para calibrar, algunos modelos de la BK-909 tienen potenciómetros de ajuste internos. Este procedimiento debe realizarlo el coordinador del aula o un técnico calificado.
3. Alejar la estación de fuentes de interferencia electromagnética (motores, transformadores grandes, equipos de radiofrecuencia).
4. Si el problema persiste, puede haber un fallo en la electrónica de control. Contactar soporte técnico de Baku.

### 7.8 El componente SMD se desplaza durante el retrabajo con aire caliente

**Causas posibles:**
- Flujo de aire excesivo para el tamaño del componente
- Componente no sujeto o mal alineado
- Temperatura del aire demasiado baja (la soldadura no se funde de manera uniforme)
- Flux insuficiente

**Soluciones:**
1. Reducir el flujo de aire (si la estación permite ajuste independiente). Para componentes pequeños (0402, 0603), usar el flujo más bajo posible.
2. Usar una boquilla de diámetro más pequeño para concentrar el aire en el componente sin afectar los vecinos.
3. Aumentar ligeramente la temperatura del aire para que la soldadura se funda más rápido y el componente no se mueva por las vibraciones del aire.
4. Aplicar más flux; el flux ayuda a mantener el componente en su lugar por tensión superficial mientras la soldadura está fundida.
5. Sujetar el componente suavemente con pinzas antiestáticas mientras se aplica el aire caliente.

---

## 8. Materiales, repuestos y accesorios

### 8.1 Consumibles principales

| Consumible | Especificación | Frecuencia de reposición |
|---|---|---|
| **Hilo de soldadura con plomo** | Sn63/Pb37, diámetro 0,6–1,0 mm, con núcleo de flux | Reposición continua |
| **Hilo de soldadura libre de plomo** | SAC305 (Sn96,5/Ag3,0/Cu0,5), diámetro 0,6–1,0 mm | Reposición continua |
| **Flux líquido o en gel** | Flux RMA o no limpiable (no-clean) | Reposición continua |
| **Malla de desoldar (solder wick)** | Anchos de 1,5 mm, 2,5 mm y 3,5 mm | Reposición continua |
| **Esponja de limpieza para cautín** | Esponja de celulosa o metálica | Reemplazar cada 2–3 meses |
| **Limpiador/activador de puntas** | Paste de reactivación de puntas de cautín | Reemplazar cuando se agote |
| **Alcohol isopropílico (IPA)** | 90 %+ de pureza, para limpieza de placas | Reposición continua |

### 8.2 Repuestos disponibles

| Repuesto | Referencia / Fuente | Notas |
|---|---|---|
| Punta de cautín 900M (cónica) | Baku 900M-C / genérica | La más usada para trabajo general |
| Punta de cautín 900M (cincel) | Baku 900M-D / genérica | Para soldadura de mayor área |
| Punta de cautín 900M (bisel) | Baku 900M-B / genérica | Para soldadura de componentes SMD |
| Punta de cautín 900M (cuchillo) | Baku 900M-K / genérica | Para soldadura de pines de ICs |
| Calentador cerámico 75 W | Baku / genérico | Para el cautín |
| Calentador de aire caliente | Baku / genérico | Para la pistola de aire |
| Boquillas para aire caliente | Baku / genéricas | Diferentes tamaños y formas |
| Cable de cautín (120 cm) | Baku | Conector específico |
| Cable de pistola (120 cm) | Baku | Conector específico |

### 8.3 Tipos de puntas de cautín serie 900M

| Tipo | Forma | Uso recomendado |
|---|---|---|
| **900M-C** (Cónica) | Punta en forma de cono | Trabajo general, soldadura de componentes through-hole, aplicación precisa de estaño |
| **900M-D** (Cincel) | Punta plana en forma de cincel | Soldadura de áreas más amplias, transferencia de calor eficiente |
| **900M-B** (Bisel) | Punta inclinada en ángulo | Soldadura de componentes SMD, trabajo en espacios reducidos |
| **900M-K** (Cuchillo) | Punta en forma de cuchilla | Soldadura de filas de pines (ICs), retrabajo rápido |
| **900M-I** (Mini cónica) | Punta cónica muy fina | Soldadura de componentes muy pequeños (0402, 0603) |

### 8.4 Accesorios complementarios recomendados para el aula

| Accesorio | Función | Prioridad |
|---|---|---|
| **Extractor de humos con filtro de carbón** | Eliminar humos de soldadura del área de trabajo | Alta |
| **Alfombrilla de silicona para soldadura** | Proteger la mesa de trabajo del calor y las salpicaduras | Alta |
| **Pinzas antiestáticas** | Manipular componentes SMD con precisión | Alta |
| **Lupa o microscopio de soldadura** | Inspeccionar soldaduras SMD de paso fino | Media |
| **Multímetro digital** | Verificar voltajes de la fuente y continuidad de soldaduras | Alta |
| **Desoldador de pera (suction pump)** | Retirar soldadura de agujeros through-hole | Media |
| **Ventosas de componentes SMD** | Levantar chips después de desoldar con aire caliente | Media |
| **Cinta Kapton** | Proteger zonas adyacentes durante retrabajo con aire caliente | Media |
| **Gafas de seguridad** | Protección contra salpicaduras de soldadura | Alta — obligatorio |
| **Soporte magnético para PCB** | Sujetar la placa de circuito durante la soldadura | Media |

---

## 9. Normas de uso STEAM

### 9.1 Normas generales de seguridad

La estación de soldadura Baku BK-909 implica riesgos significativos de quemaduras, inhalación de humos tóxicos y daño eléctrico. Las siguientes normas son de cumplimiento obligatorio:

1. **Equipo de protección personal (EPP)**: Todo usuario debe usar gafas de seguridad para proteger los ojos de salpicaduras de soldadura. Se recomienda encarecidamente el uso de mascarilla con filtro de carbón activado o trabajo bajo extractor de humos para evitar la inhalación de humos de soldadura y flux. No se requiere guantes específicos para soldadura (la destreza es más importante), pero sí para la limpieza con IPA u otros solventes.

2. **Nunca tocar la punta del cautín ni la boquilla de la pistola**: La punta del cautín alcanza temperaturas de hasta 480 °C y la boquilla de la pistola de aire caliente puede alcanzar temperaturas similares. El contacto directo con la piel causará quemaduras graves de manera casi instantánea. Siempre usar el soporte para depositar el cautín o la pistola cuando no estén en la mano.

3. **Nunca dejar la estación encendida desatendida**: Si es necesario alejarse del puesto de trabajo, apagar la estación o al menos reducir la temperatura a modo de reposo. Una estación encendida sin supervisión es un riesgo de incendio.

4. **Ventilación obligatoria**: Los humos de la soldadura (especialmente la con plomo) y del flux contienen sustancias perjudiciales. Nunca soldar en espacios cerrados sin ventilación. Siempre usar extractor de humos o trabajar en área ventilada.

5. **Higiene personal**: La soldadura con plomo contiene plomo, un metal pesado tóxico. Aunque el plomo no se absorbe por la piel, puede transferirse a la boca por las manos. Lavarse siempre las manos con agua y jabón después de soldar, especialmente antes de comer o beber. No comer, beber ni fumar en el área de soldadura.

6. **Ropa adecuada**: Usar ropa de algodón o fibras naturales (no sintéticas, que pueden derretirse con las salpicaduras de soldadura). Evitar mangas anchas o accesorios colgantes que puedan entrar en contacto con la punta caliente.

7. **Protección contra ESD**: Cuando se trabaje con componentes sensibles a descargas electrostáticas (ICs, MOSFETs, etc.), usar pulsera antiestática conectada a tierra. La estación de soldadura debe estar conectada a una toma con tierra (grounding).

### 9.2 Normas de operación

1. **Autorización**: Solo estudiantes que hayan completado la capacitación de seguridad y operación de la estación de soldadura pueden usar la máquina. Los estudiantes nuevos deben ser supervisados por el coordinador o un estudiante experimentado designado.

2. **Registro de uso**: Anotar en el cuadro de control cada sesión de uso, incluyendo: fecha, operador, funciones utilizadas (cautín/aire caliente/fuente), temperatura de trabajo y observaciones.

3. **Inspección previa**: Antes de cada uso, verificar que los cables no estén dañados, que las puntas del cautín y las boquillas de la pistola estén en buen estado, que la esponja de limpieza esté húmeda (si es de celulosa), y que la pantalla LED funcione correctamente.

4. **Secuencia de apagado**: Al terminar la sesión: a) Apagar la salida de aire caliente y esperar 30–60 segundos con aire frío para enfriar el calentador. b) Apagar el cautín. c) Estañar la punta del cautín antes de que se enfríe. d) Apagar la estación con el interruptor principal. e) Desconectar el cable de alimentación de la toma.

5. **No desmontar la estación**: Los estudiantes no deben abrir la carcasa de la máquina ni intentar reparar componentes internos. Cualquier reparación debe ser realizada por el coordinador o un técnico autorizado.

### 9.3 Normas de higiene y gestión de residuos

1. **Zona de soldadura designada**: Toda la soldadura y retrabajo debe realizarse en la zona designada del aula, equipada con extractor de humos, EPP, alfombrilla de silicona, y contenedores de residuos.

2. **Separación de residuos**: Los restos de soldadura, las puntas de cautín usadas, la malla de desoldar contaminada y los hisopos usados se depositan en los contenedores de residuos electrónicos. La soldadura con plomo es un residuo peligroso y no debe desecharse en la basura común.

3. **Limpieza del área**: Después de cada sesión, limpiar la zona de trabajo de restos de soldadura, recortes de componentes y salpicaduras de flux. Mantener la mesa de trabajo ordenada y libre de materiales innecesarios.

4. **Lavado de manos**: Obligatorio después de cada sesión de soldadura, especialmente si se usó soldadura con plomo. Usar agua y jabón, frotando durante al menos 20 segundos.

### 9.4 Uso eficiente en el contexto del aula

1. **Acumular tareas de soldadura**: Para optimizar el consumo de energía y el desgaste de las puntas, se recomienda planificar las sesiones de soldadura y agrupar varias tareas en una sola sesión en lugar de encender y apagar la estación múltiples veces.

2. **Rotación de puntas**: Mantener un juego de puntas de distintas geometrías disponible. Usar la punta adecuada para cada tarea reduce el tiempo de soldadura, mejora la calidad y prolonga la vida útil de las puntas. La punta cónica (900M-C) es la más versátil para trabajo general, mientras que la bisel (900M-B) es preferible para componentes SMD.

3. **Temperatura mínima necesaria**: Trabajar siempre a la temperatura más baja que permita una soldadura fluida. Temperaturas innecesariamente altas aceleran el desgaste de las puntas, aumentan la emisión de humos y aumentan el riesgo de dañar componentes sensibles al calor.

4. **Capacitación progresiva**: Se recomienda que los estudiantes principiantes empiecen soldando componentes through-hole con soldadura con plomo (más fácil de trabajar), antes de pasar a componentes SMD y soldadura libre de plomo. El uso de la pistola de aire caliente debe reservarse para estudiantes con más experiencia.

5. **Coordinación con otros equipos**: La estación de soldadura se usa frecuentemente en conjunto con otros equipos del aula. Por ejemplo: soldar componentes en placas diseñadas para el Dobot MG-400, soldar conexiones en los circuitos de los vehículos AWS DeepRacer, o realizar reparaciones en las impresoras 3D. Coordinar el uso de la estación con las necesidades de los proyectos en curso.

### 9.5 Protocolo de emergencia

1. **Quemaduras**: En caso de quemadura leve, enfriar la zona con agua corriente durante al menos 10 minutos. No aplicar hielo directamente ni cremas. Si la quemadura es extensa o profunda, buscar atención médica.

2. **Incendio**: Si se produce un pequeño incendio en la mesa de trabajo (por ejemplo, papel o componente que se enciende), usar el extintor de clase ABC disponible en el aula. Nunca usar agua para extinguir un fuego eléctrico. Si el fuego no se puede controlar rápidamente, evacuar el área y llamar a emergencias.

3. **Contacto con los ojos**: Si salpicaduras de soldadura o flux entran en contacto con los ojos, enjuagar inmediatamente con agua abundante durante al menos 15 minutos y buscar atención médica.

4. **Inhalación excesiva de humos**: Si alguien experimenta mareos, náuseas o dificultad para respirar durante la soldadura, trasladar a la persona a un área con aire fresco inmediatamente. Si los síntomas persisten, buscar atención médica.

---

## 10. Enlaces y recursos adicionales

### 10.1 Sitio oficial y soporte

- **Baku Tool (sitio oficial)**: [https://www.bakutool.com/](https://www.bakutool.com/)
- **Baku BA-909A+ (modelo relacionado)**: [https://www.bakutool.com/2-in-1-soldering-station-ba-909a](https://www.bakutool.com/2-in-1-soldering-station-ba-909a)
- **Baku BA-909D+ (modelo 3 en 1 con separador de pantalla)**: [https://www.bakutool.com/ba-909d-plus](https://www.bakutool.com/ba-909d-plus)

### 10.2 Tutoriales y videos educativos

- **Cómo usar la Estación de Calor Baku 909 3 en 1** (YouTube — Academia de las Nuevas Tecnologías): Tutorial completo en español sobre el uso de las tres funciones de la estación BK-909.
- **Cómo Calibrar una Estación de Calor Baku 909** (YouTube): Guía paso a paso para la calibración de temperatura del aire caliente y el cautín.
- **How to use or what is the Baku 909 heat station** (YouTube): Tutorial en inglés sobre el funcionamiento general de la estación.

### 10.3 Recursos sobre técnicas de soldadura

- **MITERS — Soldering Guide**: Guía completa de técnicas de soldadura para principiantes e intermedios.
- **SparkFun — How to Solder**: Tutorial interactivo con imágenes y videos sobre soldadura through-hole y SMD.
- **Adafruit — Guide to Excellent Soldering**: Guía detallada sobre técnicas de soldadura, selección de puntas y solución de problemas.
- **IPC Standards**: Normas internacionales sobre aceptabilidad de soldaduras (IPC-A-610), útiles como referencia para evaluar la calidad de las soldaduras en el aula.

### 10.4 Distribuidores y repuestos

- **Didácticas Electrónicas I+D** (Colombia): [https://www.didacticaselectronicas.com/](https://www.didacticaselectronicas.com/) — Distribuidor de la Baku BK-909 y repuestos en Colombia.
- **MundoReballing** (Chile): [https://www.mundoreballing.cl/](https://www.mundoreballing.cl/) — Distribuidor de estaciones de soldadura y accesorios de retrabajo.
- **Sonyvideo** (Colombia): [https://sonyvideo.net/](https://sonyvideo.net/) — Repuestos y boquillas para la estación Baku 909.
- **AliExpress / Amazon**: Puntas 900M, boquillas, calentadores y cables de repuesto genéricos compatibles.

### 10.5 Seguridad y normativas

- **Hoja de datos de seguridad (SDS) de la soldadura con plomo**: Consultar la SDS del fabricante de la soldadura utilizada en el aula para información sobre riesgos y primeros auxilios.
- **OSHA — Soldering Safety**: Guía de seguridad ocupacional para operaciones de soldadura en electrónica.
- **Normativa local sobre gestión de residuos electrónicos**: Consultar las regulaciones de la universidad y las autoridades locales para la correcta eliminación de residuos de soldadura con plomo y componentes electrónicos.
