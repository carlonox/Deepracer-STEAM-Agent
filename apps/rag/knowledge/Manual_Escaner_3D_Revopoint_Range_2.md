# Manual de Referencia — Escáner 3D Revopoint RANGE 2

> **Aula STEAM — Manual de consulta para estudiantes y asistente robótico**
> Unidades en el aula: **1**

---

## 1. Descripción general

El **Revopoint RANGE 2** es un escáner 3D portátil de luz infrarroja estructurada diseñado para la digitalización de objetos de tamaño mediano a grande. Lanzado en enero de 2024 como evolución directa del RANGE original, este escáner se distingue por su mayor distancia de trabajo (400–1300 mm frente a los 300–800 mm del modelo anterior), su capacidad de escaneo de color mejorada con 4 LEDs flash blancos, y la incorporación de una luz de relleno infrarroja (IR fill light) que estabiliza la captura de datos en diversas condiciones de iluminación. Con una precisión de un solo cuadro de hasta 0,1 mm y una velocidad de escaneo de hasta 16 fps, el RANGE 2 logra un equilibrio excepcional entre precisión, velocidad y versatilidad.

La tecnología del RANGE 2 se basa en la proyección de patrones de luz infrarroja estructurada (Clase 1, segura para los ojos) sobre la superficie del objeto, que son capturados por un par de cámaras de profundidad de 2 MP. El software procesa la deformación de estos patrones para calcular la geometría tridimensional de la superficie punto por punto, generando una nube de puntos que luego se convierte en una malla 3D. Un sensor IMU de 9 ejes (acelerómetro, giroscopio y magnetómetro) integrado en el escáner estabiliza el seguimiento del movimiento durante el escaneo manual, reduciendo significativamente las distorsiones causadas por temblores de la mano y movimientos bruscos, lo que resulta en escaneos más limpios y precisos sin necesidad de una mano extraordinariamente firme.

En el contexto del aula STEAM, el RANGE 2 es una herramienta transformadora que cierra la brecha entre el mundo físico y el digital. Permite a los estudiantes capturar objetos reales — piezas mecánicas, esculturas, elementos orgánicos, artefactos culturales — y convertirlos en modelos 3D digitales que pueden ser modificados, impresos, analizados o integrados en proyectos de realidad virtual. Su distancia de trabajo ampliada lo hace especialmente adecuado para escanear objetos que van desde pequeñas piezas de 50 mm hasta grandes esculturas o muebles de hasta 4 metros, cubriendo prácticamente todas las necesidades de escaneo en un entorno educativo. Además, su peso de solo 253 g y su conectividad USB Type-C lo hacen extremadamente portátil, permitiendo su uso tanto en el aula como en trabajo de campo.

El RANGE 2 se complementa perfectamente con las impresoras 3D del aula: un objeto físico puede ser escaneado, procesado digitalmente, modificado según las necesidades del proyecto, y luego reimpreso en resina (con la Photon Mono 2) o en filamento (con la Ender-3 S1 o la Creality K1), creando un flujo de trabajo completo de escaneo → edición → impresión que es fundamental en ingeniería inversa, diseño iterativo y preservación digital.

---

## 2. Especificaciones técnicas

| Parámetro | Valor |
|---|---|
| **Tecnología de escaneo** | Luz infrarroja estructurada (dual-camera infrared) |
| **Fuente de luz** | Luz infrarroja Clase 1 (segura para los ojos) + 4 LEDs flash blancos + luz de relleno IR |
| **Precisión de un solo cuadro** | Hasta 0,1 mm |
| **Precisión volumétrica** | Hasta 0,03 mm + 0,05 mm × L(m) |
| **Resolución de cámara de profundidad / RGB** | 2 MP |
| **Velocidad de escaneo** | Hasta 16 fps |
| **Distancia de trabajo** | 400 – 1300 mm |
| **Área de captura única a distancia mínima** | 220 × 425 mm (a 400 mm) |
| **Área de captura única a distancia máxima** | 860 × 1380 mm (a 1300 mm) |
| **Volumen mínimo de escaneo** | 50 × 50 × 50 mm |
| **Volumen máximo de escaneo** | 4 × 4 × 4 m |
| **Sensores de posición** | IMU de 9 ejes (acelerómetro + giroscopio + magnetómetro) |
| **Chip de cálculo** | Depth Map Computing |
| **Modos de alineación** | Por características (Feature) y por marcadores (Marker) |
| **Entorno de escaneo** | Interior (indoor) — luz controlada o natural suave |
| **Conectividad** | USB Type-C |
| **Peso del escáner** | 253 g |
| **Sistemas operativos compatibles** | Windows 10/11, macOS, iOS (iPhone/iPad con chip A12+) |
| **Software** | Revo Scan 5 |
| **Formatos de exportación** | PLY, OBJ, STL, 3MF |

### Comparación con el RANGE original (referencia)

| Característica | RANGE | RANGE 2 |
|---|---|---|
| Distancia de trabajo | 300–800 mm | 400–1300 mm |
| Luz de relleno IR | No | Sí |
| LEDs flash blancos | No | 4 LEDs |
| Precisión de un solo cuadro | 0,1 mm | 0,1 mm |
| Velocidad de escaneo | Hasta 12 fps | Hasta 16 fps |
| Peso | ~280 g | 253 g |
| Escaneo de color | Básico | Mejorado con flash LED |

---

## 3. Componentes y partes

### 3.1 Componentes principales

1. **Escáner RANGE 2 (cuerpo principal)**: Dispositivo portátil con forma de barra compacta que alberga todos los sensores y el sistema óptico. En su frente se encuentran el emisor de luz infrarroja estructurada y las dos cámaras de profundidad de 2 MP, además de los 4 LEDs flash blancos para iluminación de color y la luz de relleno IR. El cuerpo está diseñado para ser sostenido cómodamente con una mano durante el escaneo manual.

2. **Cable USB Type-C**: Cable de conexión entre el escáner y el computador (o dispositivo iOS). Este cable transmite tanto los datos como la alimentación eléctrica del escáner, por lo que no se necesita batería interna ni fuente de alimentación adicional. Es importante usar el cable original o un cable USB-C de alta calidad que soporte transmisión de datos (no solo carga).

3. **Calibration board (tablero de calibración)**: Placa de calibración con un patrón de puntos/marcadores de alta precisión que se utiliza para calibrar el escáner antes de su uso. La calibración es esencial para mantener la precisión anunciada de 0,1 mm. El RANGE 2 incluye una hoja de calibración de gran tamaño (large calibration-board sheet).

4. **Marcadores de escaneo (marker points)**: Pequeños puntos adhesivos que se colocan sobre la superficie de objetos sin características geométricas distinguibles (superficies lisas, cilindros, esferas) para facilitar el seguimiento y la alineación durante el escaneo. Los marcadores proporcionan puntos de referencia que el software utiliza para "enganchar" los sucesivos cuadros de escaneo entre sí.

5. **Soporte/trípode para escáner** (en paquete premium): Soporte que permite montar el escáner de forma fija mientras el objeto gira sobre una plataforma giratoria (turntable). Este modo de escaneo fijo produce resultados más precisos y consistentes que el escaneo manual, especialmente para objetos pequeños y medianos.

6. **Plataforma giratoria / Turntable** (en paquete premium): Base rotatoria motorizada sobre la cual se coloca el objeto. El escáner montado en el trípode captura el objeto mientras gira, produciendo un escaneo completo de 360° sin necesidad de mover el escáner manualmente.

### 3.2 Accesorios incluidos (paquete estándar)

- Escáner RANGE 2
- Cable USB Type-C
- Hoja de calibración grande
- Marcadores de escaneo (hoja de puntos adhesivos)
- Soporte de mano (hand grip)
- Estuche de transporte
- Manual de inicio rápido

### 3.3 Accesorios del paquete premium (adicionales al estándar)

- Trípode/soporte para escáner
- Plataforma giratoria (turntable) motorizada
- Cable adicional
- Base magnética

### 3.4 Repuestos y consumibles

| Repuesto / Consumible | Descripción |
|---|---|
| Hoja de calibración de repuesto | Reemplazo para la hoja original si se daña o pierde |
| Marcadores de escaneo (hojas) | Puntos adhesivos consumibles — se usan en cada escaneo de objetos lisos |
| Cable USB Type-C de repuesto | Cable de datos de alta calidad; usar solo cables que soporten transmisión de datos |
| Spray de escaneo (scanning spray) | Spray temporal para cubrir superficies reflectantes o transparentes |
| Estuche de transporte de repuesto | Si el original se desgasta |

---

## 4. Configuración y puesta en marcha

### 4.1 Requisitos del sistema

Antes de utilizar el RANGE 2, verificar que el computador cumpla con los siguientes requisitos mínimos:

- **Sistema operativo**: Windows 10/11 (64 bits) o macOS 10.15+
- **Procesador**: Intel i5 de 8ª generación o superior / AMD Ryzen 5 equivalente
- **RAM**: Mínimo 8 GB (16 GB recomendado para escaneos grandes)
- **GPU**: Tarjeta gráfica dedicada con soporte OpenGL 4.0+ (NVIDIA GTX 1060 o superior recomendada)
- **USB**: Puerto USB 3.0 Type-A o Type-C (USB 2.0 puede funcionar pero con menor velocidad de transferencia)
- **Almacenamiento**: Al menos 10 GB de espacio libre para software y datos de escaneo
- **Pantalla**: Resolución mínima de 1920 × 1080

Para dispositivos iOS:
- **iPhone**: iPhone XS o posterior (chip A12+)
- **iPad**: iPad Pro (3ª gen+), iPad Air (3ª gen+), iPad mini (5ª gen+) con chip A12+
- **Sistema**: iOS 15.0 o posterior

### 4.2 Instalación del software Revo Scan 5

1. Visitar la página de soporte de Revopoint: https://www.revopoint3d.com/pages/support-range2
2. Descargar **Revo Scan 5** para el sistema operativo correspondiente (Windows, macOS o iOS).
3. Ejecutar el instalador y seguir las instrucciones en pantalla.
4. Una vez instalado, abrir Revo Scan 5 y verificar que reconozca el escáner cuando se conecte vía USB.
5. Revo Scan 5 permite: captura de nubes de puntos, postprocesado (filtrado, suavizado, llenado de agujeros), alineación de múltiples escaneos, y exportación en formatos PLY, OBJ, STL y 3MF.

### 4.3 Conexión del escáner

1. Conectar el cable USB Type-C al escáner RANGE 2 (puerto en la parte posterior del dispositivo).
2. Conectar el otro extremo del cable a un puerto USB 3.0 del computador.
3. El escáner se alimentará a través del cable USB — no necesita batería ni fuente de alimentación externa.
4. Abrir Revo Scan 5. El software debería detectar automáticamente el escáner. Si no lo detecta, desconectar y reconectar el cable, o reiniciar el software.
5. Verificar que la vista previa de la cámara se muestre correctamente en la interfaz del software.

### 4.4 Calibración del escáner

La calibración es un paso crítico que debe realizarse periódicamente para mantener la precisión del escáner. Se recomienda calibrar:
- Antes de la primera uso
- Cuando los resultados de escaneo parecen imprecisos o distorsionados
- Después de un cambio importante de temperatura ambiente
- Cada 2–4 semanas si se usa regularmente

**Procedimiento de calibración:**

1. Colocar la hoja de calibración sobre una superficie plana y estable, a una distancia aproximada de 400–500 mm del escáner.
2. En Revo Scan 5, navegar a **Calibración** (Calibration).
3. Sostener el escáner apuntando hacia la hoja de calibración a la distancia indicada por el software.
4. El software guiará el proceso, solicitando que se mueva lentamente el escáner alrededor de la hoja de calibración o que se capturen imágenes desde diferentes ángulos.
5. Seguir las instrucciones en pantalla hasta que el software confirme que la calibración se ha completado exitosamente.
6. El valor de distancia entre puntos (point distance) después de la calibración debe ser igual o mejor que el valor anunciado. Si la calibración falla repetidamente, limpiar las lentes del escáner y verificar la iluminación del entorno.

### 4.5 Preparación del entorno de escaneo

El entorno de escaneo afecta significativamente la calidad de los resultados:

- **Iluminación**: Evitar la luz solar directa y las fuentes de luz intensa o con parpadeo. La luz suave y difusa es ideal. Si se necesita escaneo de color, asegurar una iluminación uniforme del objeto. Los 4 LEDs flash del RANGE 2 ayudan con la captura de color, pero no reemplazan una buena iluminación ambiental.
- **Fondo**: Un fondo neutro y sin texturas complejas facilita el seguimiento del escáner. Evitar fondos con patrones que puedan confundir al algoritmo de alineación.
- **Superficie de apoyo**: Si se usa la plataforma giratoria, asegurar que esté nivelada y que el objeto esté centrado y estable.
- **Temperatura**: El escáner funciona mejor a temperatura ambiente (15–30 °C). Cambios bruscos de temperatura pueden afectar la calibración.
- **Vibraciones**: Evitar mesas inestables o superficies que vibren durante el escaneo con trípode/turntable.

---

## 5. Guía de uso paso a paso

### 5.1 Selección del modo de alineación

Antes de iniciar un escaneo, es fundamental seleccionar el modo de alineación correcto según las características del objeto:

- **Modo Feature (por características)**: Ideal para objetos con geometría compleja, esquinas, bordes, texturas y detalles distinguibles. El software utiliza las características geométricas del objeto para alinear los cuadros consecutivos. Funciona bien con la mayoría de objetos cotidianos.

- **Modo Marker (por marcadores)**: Necesario para objetos con superficies lisas, uniformes o repetitivas (cilindros, esferas, superficies planas sin detalles). Se colocan marcadores adhesivos sobre el objeto y el software utiliza estos puntos como referencia para la alineación. Se requiere que al menos 4–5 marcadores sean visibles en cada cuadro.

**Recomendación**: Si el objeto tiene suficientes características geométricas, usar el modo Feature. Si el objeto es predominantemente liso o simétrico, usar el modo Marker. En casos mixtos, se puede intentar primero con Feature y cambiar a Marker si el seguimiento se pierde frecuentemente.

### 5.2 Preparación del objeto

1. **Limpiar la superficie**: Eliminar polvo, grasa y suciedad del objeto, ya que estas partículas pueden interferir con la captura de la luz estructurada.

2. **Tratar superficies problemáticas**: Los siguientes tipos de superficies son difíciles de escanear con luz infrarroja y requieren tratamiento previo:
   - **Objetos transparentes o translúcidos** (vidrio, plástico transparente): Cubrir con spray de escaneo (scanning spray) opaco o con talco/polvo blanco.
   - **Objetos altamente reflectantes** (metal pulido, espejos, cromo): Cubrir con spray de escaneo mate o aplicar una capa delgada de pintura en aerosol temporal.
   - **Objetos muy oscuros o negros**: La luz infrarroja puede ser absorbada por superficies muy oscuras. Aplicar spray de escaneo claro o polvo blanco.
   - **Objetos con superficies muy brillantes/brillantes**: Reducir la reflectancia con spray mate.

3. **Colocar marcadores (si usa modo Marker)**: Distribuir los marcadores adhesivos de manera aleatoria sobre la superficie del objeto. No colocarlos en filas rectas ni en patrones regulares, ya que el software necesita puntos de referencia únicos e identificables. Asegurar que al menos 4–5 marcadores sean visibles desde cualquier ángulo de escaneo.

4. **Posicionar el objeto**: Colocar el objeto sobre la plataforma giratoria (si se usa) o sobre una superficie estable a la distancia de trabajo adecuada (400–1300 mm del escáner).

### 5.3 Proceso de escaneo manual (handheld)

1. **Iniciar Revo Scan 5** y conectar el escáner.
2. **Crear un nuevo proyecto**: Seleccionar "Nuevo escaneo" (New Scan).
3. **Configurar parámetros**:
   - Seleccionar modo de alineación: **Feature** o **Marker**.
   - Ajustar la distancia de trabajo según el tamaño del objeto (más cerca para pequeños, más lejos para grandes).
   - Activar o desactivar la captura de color (RGB) según necesidad.
4. **Iniciar el escaneo**: Presionar el botón de inicio en el software. La vista previa mostrará lo que el escáner está capturando.
5. **Mover el escáner lentamente** alrededor del objeto, manteniendo una distancia constante dentro del rango de trabajo (400–1300 mm). Seguir estas pautas:
   - Mover el escáner a una velocidad moderada — no demasiado rápido ni demasiado lento.
   - Mantener una superposición de al menos **50 %** entre cuadros consecutivos. Esto significa que cada nueva captura debe cubrir al menos la mitad del área del cuadro anterior.
   - Si el seguimiento se pierde (el software muestra una alerta o la nube de puntos deja de crecer), volver a una zona ya escaneada para recuperar el rastreo y luego continuar.
   - Escanear el objeto desde múltiples ángulos para capturar todas las caras. Un escaneo de 360° completo típicamente requiere rodear el objeto completamente.
6. **Pausar y reanudar**: Si es necesario reposicionar el objeto o descansar, se puede pausar el escaneo y reanudarlo después.
7. **Finalizar el escaneo**: Presionar el botón de finalización cuando se haya capturado toda la geometría deseada.

### 5.4 Proceso de escaneo con trípode y plataforma giratoria (turntable)

1. Montar el escáner en el trípode/soporte, apuntando hacia la plataforma giratoria.
2. Colocar el objeto centrado en la plataforma giratoria.
3. Ajustar la distancia entre el escáner y el objeto (dentro del rango 400–1300 mm).
4. En Revo Scan 5, seleccionar el modo de alineación apropiado y configurar los parámetros.
5. Iniciar el escaneo y luego iniciar la rotación de la plataforma. La velocidad de rotación debe ser lenta y constante.
6. El escáner capturará el objeto a medida que gira. Dependiendo de la complejidad del objeto, puede ser necesario hacer múltiples pasadas a diferentes alturas o ángulos para capturar todos los detalles.
7. Para objetos complejos que no pueden ser completamente capturados en una sola sesión rotacional, realizar múltiples escaneos desde diferentes ángulos y luego alinearlos en el postprocesado.

### 5.5 Modo Single-shot (captura única)

El RANGE 2 también soporta un modo de captura única (single-shot) donde se captura un solo cuadro a la vez. Este modo es útil para:
- Capturar un lado específico de un objeto sin necesidad de un escaneo completo.
- Documentar rápidamente la forma de una superficie.
- Crear escaneos de baja resolución para planificación antes de un escaneo completo.

Para usar el modo single-shot: en Revo Scan 5, seleccionar "Single-shot" y presionar capturar. Asegurarse de que al menos el 50 % del cuadro anterior esté visible si se van a unir múltiples capturas.

### 5.6 Postprocesado en Revo Scan 5

Después del escaneo, el modelo crudo (nube de puntos) requiere postprocesado para convertirse en un modelo 3D utilizable:

1. **Filtrado de ruido**: Eliminar puntos aislados y ruido de la nube de puntos. El software ofrece herramientas de filtrado automático y manual.
2. **Suavizado**: Suavizar la superficie del modelo para eliminar irregularidades menores causadas por el movimiento de la mano o el ruido del sensor.
3. **Llenado de agujeros (hole filling)**: Rellenar pequeños huecos en la malla donde no se capturaron datos. El software puede rellenar automáticamente agujeros pequeños.
4. **Alineación de múltiples escaneos**: Si se realizaron múltiples escaneos del mismo objeto desde diferentes ángulos, estos deben alinearse y fusionarse. Revo Scan 5 ofrece herramientas de alineación manual y semiautomática.
5. **Optimización de malla**: Simplificar la malla (reducir el número de triángulos) para facilitar la manipulación y la impresión 3D, manteniendo el nivel de detalle necesario.
6. **Exportación**: Exportar el modelo final en el formato deseado:
   - **STL**: Para impresión 3D (el formato más universal).
   - **OBJ**: Para edición en software de modelado 3D (incluye coordenadas de textura/color).
   - **PLY**: Para intercambio de nubes de puntos con información de color.
   - **3MF**: Formato moderno que incluye color y material.

---

## 6. Mantenimiento básico

### 6.1 Limpieza de las lentes

Las lentes del escáner (emisor IR, cámaras de profundidad, cámara RGB) son los componentes más delicados y deben mantenerse limpios para un rendimiento óptimo:

- **Limpieza regular**: Usar un paño de microfibra limpio y seco para eliminar el polvo de las lentes. No aplicar presión excesiva.
- **Manchas o residuos**: Si las lentes tienen manchas, usar un paño de microfibra ligeramente humedecido con agua destilada o solución limpiadora de lentes ópticas. Nunca usar alcohol, acetona ni solventes agresivos que puedan dañar los recubrimientos ópticos.
- **Frecuencia**: Limpiar las lentes antes de cada sesión de escaneo si se han acumulado polvo, y después de cada uso en entornos polvorientos.

### 6.2 Almacenamiento

- **Estuche protector**: Guardar siempre el escáner en su estuche de transporte cuando no esté en uso. Esto lo protege del polvo, la humedad y los golpes.
- **Temperatura**: Almacenar el escáner a temperatura ambiente (10–35 °C). Evitar la exposición a temperaturas extremas, tanto altas como bajas, ya que pueden afectar la calibración.
- **Humedad**: Evitar almacenar el escáner en ambientes muy húmedos. Si es inevitable, usar bolsas de gel de sílice en el estuche.
- **Cable**: Enrollar el cable USB suavemente sin dobleces pronunciados que puedan dañar los conductores internos.

### 6.3 Cuidado de la hoja de calibración

- **Mantener plana**: La hoja de calibración debe mantenerse perfectamente plana. No doblarla ni arrugarla. Guardarla en una carpeta rígida o entre cartones.
- **Limpia y seca**: Evitar que la hoja se manche, se moje o se raye. Cualquier daño al patrón de calibración puede comprometer la calidad de la calibración.
- **Reemplazo**: Si la hoja se daña, solicitar una de repuesto a Revopoint. No intentar imprimir una nueva, ya que la precisión de impresión de una impresora doméstica no es suficiente para reproducir los marcadores con la exactitud requerida.

### 6.4 Verificación periódica de la calibración

- **Prueba de calibración**: Periódicamente (cada 2–4 semanas), realizar un escaneo de prueba de un objeto con dimensiones conocidas (por ejemplo, un cubo calibrado) y verificar que las medidas del modelo escaneado coincidan con las reales dentro de la tolerancia esperada.
- **Recalibrar si es necesario**: Si las medidas están fuera de tolerancia, recalibrar el escáner usando la hoja de calibración. Un escáner mal calibrado producirá artefactos, distorsiones y medidas imprecisas.
- **Verificar con modo Marker**: Una forma rápida de verificar la calibración es usar el modo Marker — si el escáner tiene dificultades para reconocer los marcadores, puede necesitar recalibración.

### 6.5 Calendario de mantenimiento sugerido

| Frecuencia | Tarea |
|---|---|
| **Antes de cada uso** | Limpiar las lentes, verificar conexión USB |
| **Después de cada uso** | Guardar en estuche, verificar que no haya daños |
| **Cada 2–4 semanas** | Verificar calibración con escaneo de prueba |
| **Mensual** | Limpieza profunda de lentes, inspección del cable USB |
| **Trimestral** | Recalibración completa, verificar actualizaciones de software |
| **Semestral** | Inspección completa del equipo, verificar estado de la hoja de calibración |

---

## 7. Solución de problemas comunes

### 7.1 El escáner pierde el seguimiento (tracking lost) durante el escaneo

**Causas posibles:**
- Movimiento demasiado rápido o errático del escáner
- Superficie del objeto sin suficientes características (Feature mode) o sin suficientes marcadores visibles (Marker mode)
- Distancia de trabajo fuera del rango (menos de 400 mm o más de 1300 mm)
- Iluminación inadecuada (demasiada luz directa o insuficiente)
- Escáner mal calibrado

**Soluciones:**
1. Reducir la velocidad de movimiento del escáner. Moverlo de forma lenta y constante.
2. Asegurar una superposición de al menos 50 % entre cuadros consecutivos.
3. Si se usa Feature mode y el objeto es liso, cambiar a Marker mode y colocar marcadores adhesivos.
4. Si se usa Marker mode, verificar que al menos 4–5 marcadores sean visibles en cada cuadro. Añadir más marcadores si es necesario.
5. Ajustar la distancia al objeto para estar dentro del rango 400–1300 mm.
6. Mejorar la iluminación del entorno — luz suave y difusa es ideal.
7. Recalibrar el escáner si el problema persiste.

### 7.2 El modelo escaneado tiene distorsiones o artefactos

**Causas posibles:**
- Calibración incorrecta o desactualizada
- Movimiento brusco o temblores excesivos durante el escaneo
- Superficie reflectante o transparente que distorsiona la luz estructurada
- Interferencia de luz externa (luz solar directa, luces parpadeantes)

**Soluciones:**
1. Recalibrar el escáner antes de la siguiente sesión.
2. Mover el escáner más lentamente y con movimientos más suaves. Considerar usar el trípode y la plataforma giratoria para mayor estabilidad.
3. Cubrir superficies reflectantes o transparentes con spray de escaneo mate.
4. Escanear en un entorno con iluminación controlada — evitar la luz solar directa y las luces fluorescentes que parpadean.
5. En el postprocesado, usar las herramientas de suavizado y filtrado de ruido para reducir artefactos menores.

### 7.3 Los colores del modelo escaneado son incorrectos o deslavados

**Causas posibles:**
- Iluminación desigual del objeto durante el escaneo
- LEDs flash blancos no activados
- Superficie del objeto muy reflectante
- Configuración de balance de blancos incorrecta

**Soluciones:**
1. Asegurar una iluminación uniforme y suave del objeto. Evitar sombras pronunciadas y reflejos directos.
2. Verificar que los 4 LEDs flash blancos del RANGE 2 estén activados en la configuración del software.
3. Si el objeto es reflectante, tratar la superficie con spray mate para reducir los reflejos.
4. Si es posible, escanear con iluminación de temperatura de color neutra (~5000 K) para obtener colores más precisos.

### 7.4 El escáner no es detectado por el software

**Causas posibles:**
- Cable USB desconectado o defectuoso
- Puerto USB del computador inactivo o insuficiente (USB 2.0 en lugar de 3.0)
- Software Revo Scan 5 no actualizado
- Controladores USB del computador desactualizados

**Soluciones:**
1. Desconectar y reconectar el cable USB. Probar con otro puerto USB (preferiblemente USB 3.0).
2. Probar con otro cable USB Type-C que soporte transmisión de datos (no solo carga).
3. Verificar que se está usando un puerto USB 3.0 (generalmente marcado con un conector azul o la etiqueta "SS").
4. Actualizar Revo Scan 5 a la última versión disponible.
5. Reiniciar el computador y el software.
6. En Windows, verificar el Administrador de dispositivos para confirmar que el escáner sea reconocido como dispositivo USB.

### 7.5 Escaneo de objetos negros o muy oscuros falla

**Causas posibles:**
- La luz infrarroja es absorbada por superficies muy oscuras, impidiendo la detección del patrón proyectado

**Soluciones:**
1. Aplicar spray de escaneo blanco o gris claro sobre la superficie oscura del objeto. El spray crea una capa temporal opaca que refleja la luz infrarroja.
2. Usar talco o polvo blanco como alternativa económica al spray de escaneo.
3. Aumentar la iluminación del entorno y reducir la distancia de trabajo (acercarse más al objeto, dentro del rango permitido).
4. Si es posible, pintar temporalmente el objeto con un aerosol de color claro que pueda retirarse después.

### 7.6 Escaneo de objetos reflectantes (metal, vidrio) falla

**Causas posibles:**
- La luz infrarroja se refleja especularmente en superficies brillantes, creando puntos ciegos y distorsiones

**Soluciones:**
1. Aplicar spray de escaneo mate (scanning spray) sobre la superficie reflectante. Existen sprays específicos para escaneo 3D que se evaporan después de unas horas sin dejar residuo.
2. Como alternativa, usar polvo de talco o aerosol de tiza temporal.
3. Escanear desde múltiples ángulos para minimizar las zonas de reflejo directo.
4. Reducir la intensidad de la iluminación ambiental para minimizar los reflejos especulares.

### 7.7 La calibración falla repetidamente

**Causas posibles:**
- Hoja de calibración dañada, arrugada o sucia
- Lentes del escáner sucias
- Iluminación inadecuada durante la calibración
- Distancia incorrecta a la hoja de calibración

**Soluciones:**
1. Verificar que la hoja de calibración esté plana, limpia y sin daños. Si está dañada, solicitar un reemplazo.
2. Limpiar las lentes del escáner con un paño de microfibra.
3. Realizar la calibración en un entorno con iluminación suave y uniforme, sin sombras sobre la hoja.
4. Sostener el escáner a la distancia indicada por el software (típicamente 400–500 mm de la hoja).
5. Mover el escáner lentamente y de forma constante durante el proceso de calibración, siguiendo las instrucciones del software.

---

## 8. Materiales, repuestos y accesorios

### 8.1 Sprays de escaneo recomendados

| Producto | Características | Uso |
|---|---|---|
| **AESUB Blue/Orange Scanning Spray** | Spray evaporable (se elimina solo en horas), no deja residuo, cobertura uniforme | Superficies reflectantes, transparentes y oscuras |
| **Sublime Scanning Spray** | Spray evaporable, aplicación uniforme, alta opacidad | Objetos brillantes, vidrio, metal pulido |
| **Krylon Chalky Finish** (alternativa económica) | Pintura en aerosol mate, debe limpiarse después | Proyectos donde se puede pintar el objeto temporalmente |
| **Talco / polvo de bebé** (alternativa económica) | Polvo blanco aplicado con brocha o aerosol, muy económico | Pruebas rápidas, objetos que no requieren alta precisión |

### 8.2 Accesorios opcionales y recomendados

| Accesorio | Función | Prioridad |
|---|---|---|
| **Plataforma giratoria (turntable)** | Rotación automática del objeto para escaneos de 360° con trípode | Alta — mejora significativamente la calidad y consistencia |
| **Trípode/soporte para escáner** | Montaje fijo del escáner para escaneo con turntable | Alta — necesario junto con la plataforma |
| **Marcadores de escaneo (hojas adicionales)** | Puntos adhesivos para objetos lisos — consumible | Alta — se agotan con el uso |
| **Cable USB-C de alta calidad (repuesto)** | Conexión alternativa si el original falla | Media |
| **Kit de limpieza óptica** | Paños de microfibra, solución limpiadora de lentes, pera de aire | Media |
| **Cubo de calibración / esfera de referencia** | Objeto con dimensiones conocidas para verificar precisión | Media |
| **Luz de relleno LED (softbox/panel)** | Iluminación uniforme para escaneos de color | Baja — los LEDs del escáner suelen ser suficientes |
| **Fondo negro/curtido (photo backdrop)** | Fondo neutro para reducir interferencias | Baja |

### 8.3 Software complementario

| Software | Función | Uso en el aula |
|---|---|---|
| **Revo Scan 5** | Captura y postprocesado de escaneos | Esencial — incluido con el escáner |
| **Blender** (gratuito) | Edición avanzada de mallas, reparación, esculpido | Avanzado — para modificar modelos escaneados |
| **MeshLab** (gratuito) | Procesamiento de nubes de puntos y mallas | Medio — para limpieza y optimización de mallas |
| **CloudCompare** (gratuito) | Comparación de nubes de puntos, alineación fina | Avanzado — para verificación de precisión |
| **Meshmixer** (gratuito, Autodesk) | Reparación de mallas, soportes para impresión | Medio — para preparar modelos para impresión 3D |
| **Fusion 360** (gratuito para educación) | Diseño paramétrico, ingeniería inversa | Medio — para convertir escaneos en modelos CAD |

---

## 9. Normas de uso STEAM

### 9.1 Normas generales de seguridad

1. **Luz infrarroja Clase 1**: El RANGE 2 utiliza luz infrarroja Clase 1, que es segura para los ojos y la piel bajo uso normal. No obstante, no se debe apuntar el escáner directamente a los ojos de ninguna persona a corta distancia durante periodos prolongados.

2. **Cuidado con el cable**: El cable USB conecta el escáner al computador. Tener cuidado de no tropezar con el cable ni tirar de él bruscamente durante el escaneo, ya que esto puede dañar el conector del escáner o el puerto USB del computador.

3. **Spray de escaneo**: Si se usa spray de escaneo, usarlo en un área ventilada. Algunos sprays contienen propulsores que pueden ser irritantes si se inhalan en espacios cerrados. Seguir las instrucciones del fabricante del spray.

4. **No desmontar el escáner**: Los estudiantes no deben abrir ni desmontar el escáner. Los componentes ópticos internos son delicados y están calibrados de fábrica. Cualquier manipulación interna puede anular la garantía y dañar permanentemente el dispositivo.

5. **Manipulación cuidadosa**: El escáner pesa solo 253 g pero contiene óptica de precisión. Evitar golpes, caídas y vibraciones excesivas. Siempre guardarlo en su estuche después de usarlo.

### 9.2 Normas de operación

1. **Autorización**: Solo estudiantes que hayan completado la capacitación de uso del RANGE 2 pueden operarlo. Los estudiantes nuevos deben ser supervisados por el coordinador o un estudiante experimentado.

2. **Registro de uso**: Anotar en el cuadro de control cada sesión de uso, incluyendo: fecha, operador, objeto escaneado, modo utilizado (Feature/Marker), y observaciones sobre la calidad del escaneo.

3. **Calibración antes de usar**: Verificar la calibración antes de cada sesión importante. Si el escáner no ha sido usado en más de dos semanas, realizar una recalibración completa.

4. **Preparación del objeto**: Dedicar tiempo a preparar el objeto adecuadamente (limpieza, aplicación de spray o marcadores) antes de iniciar el escaneo. Un objeto bien preparado produce un escaneo significativamente mejor que uno sin preparación.

5. **No forzar el escaneo**: Si el escaneo no está funcionando bien (pérdida frecuente de seguimiento, datos ruidosos), detenerse y diagnosticar el problema antes de continuar. Insistir en un escaneo defectuoso solo produce malos resultados y desperdicia tiempo.

6. **Guardar los datos**: Después de cada escaneo, guardar el proyecto y exportar el modelo en al menos dos formatos (STL para impresión, OBJ para edición). Organizar los archivos en carpetas con nombres descriptivos.

### 9.3 Normas específicas para el aula

1. **Zona de escaneo**: Designar un área del aula como "zona de escaneo" con condiciones de iluminación controladas, fondo neutro y suficiente espacio para maniobrar el escáner alrededor de los objetos.

2. **Uso compartido**: Dado que hay una sola unidad, se debe coordinar su uso entre los estudiantes que lo necesiten. Establecer un sistema de reservas si la demanda es alta.

3. **Compatibilidad con impresoras 3D**: El flujo de trabajo completo (escaneo → postprocesado → impresión) es uno de los usos más valiosos del RANGE 2 en el aula. Los estudiantes deben familiarizarse con todo el proceso, desde la captura hasta la impresión del modelo en la Photon Mono 2 o la Ender-3 S1.

4. **Documentación de proyectos**: Se recomienda documentar cada proyecto de escaneo con fotografías del objeto original, capturas de pantalla del proceso de escaneo y postprocesado, y fotos de la pieza impresa resultante. Esta documentación es valiosa para el portafolio del estudiante y para futuras referencias.

### 9.4 Integración curricular STEAM

El RANGE 2 es una de las herramientas más transversales del aula STEAM, conectando el mundo físico y el digital:

- **Ciencia (S)**: Digitalización de especímenes biológicos para estudio; análisis morfológico comparativo; documentación de artefactos arqueológicos; medición y comparación dimensional.
- **Tecnología (T)**: Principios de luz estructurada y sensores de profundidad; procesamiento de nubes de puntos; algoritmos de alineación y registro; formatos de archivo 3D.
- **Ingeniería (E)**: Ingeniería inversa de piezas mecánicas; diseño iterativo (escanear → modificar → reimprimir); control de calidad dimensional; prototipado rápido.
- **Arte (A)**: Digitalización de esculturas y obras de arte; preservación digital de patrimonio cultural; creación de modelos para animación y realidad virtual; modificación artística de objetos escaneados.
- **Matemáticas (M)**: Geometría de nubes de puntos y mallas triangulares; cálculo de volúmenes y áreas superficiales; análisis de precisión y tolerancias; transformaciones geométricas (traslación, rotación, escala).

---

## 10. Enlaces y recursos adicionales

### 10.1 Documentación oficial

- **Revopoint RANGE 2 — Página de soporte**: https://www.revopoint3d.com/pages/support-range2
- **Revopoint RANGE 2 — Guía de inicio rápido (PDF)**: https://download.revopoint3d.com/support/download/range2/range2-quickstartguide-en-v3.1-20260106.pdf
- **Revopoint RANGE 2 — Folleto/Brochure (PDF)**: https://download.revopoint3d.com/zy/range2/range2-brochure-en.pdf
- **Descarga de Revo Scan 5**: Disponible en la página de soporte de Revopoint

### 10.2 Tutoriales y guías en video

- **Revopoint RANGE 2 — Playlist de tutoriales oficiales (YouTube)**: https://www.youtube.com/playlist?list=PLN8UlQmwKrZK4s6FRTv22GURGWQznkLP2
- **Revopoint RANGE 2 — Standard Package First Use Tutorial**: Tutorial completo de primera configuración
- **Revopoint RANGE 2 — How to Scan Feature Rich or Featureless Objects**: Guía de selección de modo de alineación
- **Revopoint RANGE 2 — How to Use Single-shot**: Tutorial del modo de captura única
- **Revo Scan 5 Tutorial**: Guía completa del software

### 10.3 Comunidad y foro

- **Foro oficial de Revopoint**: https://forum.revopoint3d.com
- **Reddit — r/Revopoint**: https://www.reddit.com/r/Revopoint/
- **Facebook — Revopoint Users Group**: Grupo activo de usuarios
- **Revopoint en YouTube**: Canal oficial con tutoriales y demostraciones

### 10.4 Reseñas y análisis

- **3D Printing Industry — Revopoint RANGE 2 Announcement**: https://3dprintingindustry.com/news/revopoint-unveils-its-new-revopoint-range-2-3d-scanner-technical-specifications-and-pricing-227571
- **All3DP — Revopoint RANGE 2 Overview**: https://all3dp.com/4/revopoints-new-range-2-3d-scanner-tackles-large-projectsad
- **YouTube — RANGE 2 Review Videos**: Múltiples creadores de contenido han publicado reseñas en video con comparativas y pruebas prácticas

### 10.5 Software complementario (descargas)

- **Blender**: https://www.blender.org
- **MeshLab**: https://www.meshlab.net
- **CloudCompare**: https://www.cloudcompare.org
- **Autodesk Meshmixer**: https://www.meshmixer.com
- **Fusion 360 (educación)**: https://www.autodesk.com/education/edu-software/overview

### 10.6 Productos relacionados Revopoint

- **Revopoint RANGE**: Modelo anterior, distancia de trabajo más corta (300–800 mm)
- **Revopoint POP 3 / POP 4**: Escáner portátil de propósito general, menor distancia de trabajo, mayor versatilidad
- **Revopoint MINI 2**: Escáner de alta precisión (0,02 mm) para objetos pequeños, luz azul
- **Revopoint INSPIRE 2**: Escáner de entrada con láser infrarrojo y luz estructurada
- **Revopoint MIRACO**: Escáner inalámbrico independiente (todo-en-uno) con procesamiento integrado
