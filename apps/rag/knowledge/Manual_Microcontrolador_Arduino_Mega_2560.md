# Manual de Referencia — Placa Microcontroladora Arduino Mega 2560 Rev3

> **Aula STEAM — Manual de consulta para estudiantes y asistente robótico**
> Unidades en el aula: **2**

---

## 1. Descripción general

El **Arduino Mega 2560 Rev3** es una placa de desarrollo basada en el microcontrolador **ATmega2560** de la familia AVR de Microchip (anteriormente Atmel). Es la placa más grande y capaz de la familia Arduino clásica, diseñada para proyectos que requieren un alto número de pines de entrada/salida, abundante memoria para el programa y los datos, y múltiples puertos de comunicación serial. Con 54 pines digitales (de los cuales 15 proporcionan salida PWM), 16 entradas analógicas, 4 puertos UART de hardware, comunicación SPI e I2C, 256 KB de memoria Flash, 8 KB de SRAM y 4 KB de EEPROM, el Mega 2560 es la opción ideal cuando el Arduino Uno se queda corto en pines, memoria o puertos seriales. Su factor de forma ampliado (101,52 × 53,3 mm) mantiene la compatibilidad mecánica con la mayoría de los shields diseñados para el Arduino Uno, gracias a los headers adicionales que extienden la fila de pines estándar.

En el contexto del aula STEAM, los dos Arduino Mega 2560 disponibles son herramientas centrales para la enseñanza de programación embebida, electrónica digital, control de actuadores, lectura de sensores y prototipado rápido de sistemas interactivos. Su abundancia de pines los hace especialmente adecuados para proyectos que involucran múltiples sensores y actuadores simultáneamente, como estaciones meteorológicas completas, robots con múltiples grados de libertad, matrices de LEDs, sistemas de control industrial a escala, y proyectos de Internet de las Cosas (IoT) que requieren comunicación simultánea con varios dispositivos. Los 4 puertos UART de hardware son particularmente valiosos en el aula, ya que permiten comunicar el Mega con múltiples dispositivos seriales al mismo tiempo (por ejemplo, un módulo GPS, un módulo Bluetooth y una pantalla LCD serial) sin recurrir a librerías de SoftwareSerial que consumen recursos del procesador y tienen limitaciones de temporización.

La Rev3 (Revisión 3) es la versión actual de producción del Mega 2560 e introduce varias mejoras respecto a las revisiones anteriores: un pin IOREF que permite a los shields adaptarse automáticamente al voltaje de operación de la placa (5 V en el Mega), un pin de reset dedicado más accesible, y un circuito de protección mejorado en el puerto USB. El Mega 2560 Rev3 utiliza un microcontrolador ATmega16U2 como interfaz USB-to-serial (en lugar del chip FTDI de versiones anteriores), lo que permite reprogramar el firmware USB para implementar funcionalidades personalizadas como emulación de teclado o mouse HID. La placa puede alimentarse a través del puerto USB, del conector de barril DC (7–12 V recomendados) o de los pines VIN y GND, con un regulador de voltaje integrado que proporciona 5 V estables al microcontrolador y a los circuitos periféricos. Con dos unidades disponibles en el aula, es posible que dos equipos de estudiantes trabajen en proyectos independientes de forma simultánea, o que se utilicen ambos Megas en un proyecto que requiera comunicación entre dos microcontroladores.

---

## 2. Especificaciones técnicas

| Parámetro | Valor |
|---|---|
| **Modelo** | Arduino Mega 2560 Rev3 |
| **Código de producto** | A000067 |
| **Microcontrolador** | ATmega2560 |
| **Voltaje de operación** | 5 V |
| **Voltaje de entrada (recomendado)** | 7 – 12 V (conector de barril DC) |
| **Voltaje de entrada (límite)** | 6 – 20 V |
| **Pines digitales I/O** | 54 |
| **Pines PWM** | 15 (pines 2–13, 44–46) |
| **Pines de entrada analógica** | 16 (A0–A15) |
| **Resolución ADC** | 10 bits (0–1023) |
| **Corriente DC por pin I/O** | 20 mA |
| **Corriente máxima por pin I/O** | 40 mA (no exceder) |
| **Corriente DC para pin 3,3 V** | 50 mA |
| **Corriente DC para pin 5 V** | Hasta ~800 mA (dependiendo de la fuente) |
| **Memoria Flash** | 256 KB (8 KB usados por el bootloader) |
| **SRAM** | 8 KB |
| **EEPROM** | 4 KB |
| **Frecuencia de reloj** | 16 MHz |
| **Puertos UART (hardware)** | 4 (Serial, Serial1, Serial2, Serial3) |
| **Interfaz I2C** | SDA (pin 20), SCL (pin 21) |
| **Interfaz SPI** | MISO (pin 50), MOSI (pin 51), SCK (pin 52), SS (pin 53) |
| **Interrupciones externas** | 6 (pines 2, 3, 18, 19, 20, 21) |
| **Conector USB** | USB tipo B |
| **Conector de alimentación** | Barril DC 2,1 mm (centro positivo) |
| **Interfaz USB-to-Serial** | ATmega16U2 |
| **LED integrado** | Pin 13 |
| **Pines IOREF y RESET** | Sí (header de poder mejorado Rev3) |
| **Longitud** | 101,52 mm |
| **Ancho** | 53,3 mm |
| **Peso** | 37 g |

### 2.1 Comparación con otros Arduino (referencia)

| Característica | Arduino Uno Rev3 | Arduino Mega 2560 Rev3 | Arduino Due |
|---|---|---|---|
| Microcontrolador | ATmega328P | ATmega2560 | ATSAM3X8E (ARM Cortex-M3) |
| Voltaje de operación | 5 V | 5 V | 3,3 V |
| Pines digitales | 14 | 54 | 54 |
| Pines PWM | 6 | 15 | 12 |
| Entradas analógicas | 6 | 16 | 12 |
| Salidas analógicas (DAC) | No | No | 2 (12 bits) |
| Flash | 32 KB | 256 KB | 512 KB |
| SRAM | 2 KB | 8 KB | 96 KB |
| EEPROM | 1 KB | 4 KB | No (sin EEPROM nativa) |
| UART hardware | 1 | 4 | 4 |
| Frecuencia de reloj | 16 MHz | 16 MHz | 84 MHz |
| Precio aproximado | Bajo | Medio | Medio-alto |

### 2.2 Mapa de pines especiales

| Función | Pines |
|---|---|
| **PWM** | 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 44, 45, 46 |
| **Interrupciones externas** | 2 (INT0), 3 (INT1), 18 (INT5), 19 (INT4), 20 (INT3), 21 (INT2) |
| **I2C (SDA/SCL)** | 20 (SDA), 21 (SCL) |
| **SPI (MOSI/MISO/SCK/SS)** | 51 (MOSI), 50 (MISO), 52 (SCK), 53 (SS) |
| **UART 0 (Serial)** | 0 (RX), 1 (TX) — USB-to-serial |
| **UART 1 (Serial1)** | 19 (RX1), 18 (TX1) |
| **UART 2 (Serial2)** | 17 (RX2), 16 (TX2) |
| **UART 3 (Serial3)** | 15 (RX3), 14 (TX3) |
| **LED integrado** | 13 |
| **IOREF** | Pin IOREF en header de poder |
| **Reset** | Pin RESET en header de poder + botón en la placa |
| **ARef** | Pin IOREF adyacente a A0 |

---

## 3. Componentes y partes

### 3.1 Componentes principales de la placa

1. **Microcontrolador ATmega2560**: El corazón de la placa. Es un microcontrolador AVR de 8 bits con arquitectura RISC modificada, 256 KB de memoria Flash para almacenar el programa, 8 KB de SRAM para variables y datos en tiempo de ejecución, y 4 KB de EEPROM para datos persistentes. Opera a 16 MHz con un voltaje de 5 V y ejecuta la mayoría de las instrucciones en un solo ciclo de reloj. El ATmega2560 tiene 86 pines de I/O generales, de los cuales el Arduino Mega expone 54 como pines digitales y 16 como entradas analógicas. Soporta 6 modos de reposo (sleep modes) para ahorro de energía y dispone de un watchdog timer, temporizadores de 8 y 16 bits, y un convertidor analógico-digital de 10 bits con multiplexor de 16 canales.

2. **Microcontrolador ATmega16U2 (interfaz USB)**: Este segundo microcontrolador actúa como puente USB-to-serial entre el puerto USB tipo B de la placa y los pines RX/TX del ATmega2560. Recibe los datos del ordenador a través del USB y los transfiere al ATmega2560 por UART serial, y viceversa. También gestiona el proceso de subida del programa (upload) mediante el protocolo STK500v2, reseteando automáticamente el ATmega2560 cuando el IDE envía un nuevo sketch. Los drivers de reset automático utilizan el flujo de datos DTR (Data Terminal Ready) del puerto serial virtual. El firmware del ATmega16U2 puede reprogramarse a través de su header ICSP para implementar funciones HID personalizadas (teclado, mouse, joystick).

3. **Puerto USB tipo B**: Conector hembra de tipo B (el conector cuadrado tradicional) que permite la conexión del Mega al ordenador mediante un cable USB A-B. Este puerto sirve para tres propósitos: alimentar la placa (5 V desde el USB), subir programas al ATmega2560, y comunicarse en serie con el ordenador (monitor serial del IDE). La conexión USB proporciona hasta 500 mA de corriente, suficientes para la placa y circuitos periféricos de bajo consumo.

4. **Conector de alimentación DC (barril)**: Conector de barril de 2,1 mm con centro positivo que permite alimentar la placa con un adaptador AC-DC externo de 7 a 12 V. El regulador de voltaje integrado reduce el voltaje de entrada a 5 V para el microcontrolador y los periféricos. Usar voltajes fuera del rango de 6–20 V puede dañar la placa. Cuando la placa recibe alimentación simultáneamente por USB y por el conector DC, la fuente con mayor voltaje tiene prioridad a través de un diodo de conmutación automática.

5. **Regulador de voltaje**: Circuito regulador lineal que convierte el voltaje de entrada del conector DC o del pin VIN a 5 V estables para la placa. También proporciona 3,3 V (hasta 50 mA) a través de un regulador secundario. El regulador puede disipar una cantidad limitada de energía como calor; si la placa se alimenta con voltajes altos (cerca de 20 V) y se consumen muchos amperios, el regulador puede sobrecalentarse.

6. **Botón de reset**: Pulsador que reinicia el microcontrolador ATmega2560, volviendo a ejecutar el sketch desde el principio. Es equivalente a desconectar y reconectar la alimentación. El botón de reset es útil cuando el programa se cuelga o cuando se desea reiniciar la ejecución manualmente.

7. **LED de encendido (PWR)**: LED verde que indica que la placa está recibiendo alimentación. Si este LED no se enciende al conectar la placa, verificar las conexiones de alimentación.

8. **LED integrado (pin 13)**: LED naranja conectado al pin digital 13 a través de una resistencia limitadora de corriente. Es útil para pruebas rápidas de funcionamiento (como el clásico sketch "Blink") sin necesidad de componentes externos. Cuando el pin 13 está en HIGH, el LED se enciende; cuando está en LOW, se apaga.

9. **LEDs de comunicación TX/RX**: Dos LEDs (TX y RX) que parpadean cuando se producen transmisiones o recepciones de datos seriales a través del puerto USB. Son útiles para verificar visualmente que la comunicación serial está activa, tanto durante la subida de programas como durante la comunicación en tiempo de ejecución.

10. **Headers de pines**: Conjunto de conectores hembra distribuidos a lo largo de los bordes de la placa que exponen todos los pines del microcontrolador. Incluyen: header de poder (VIN, GND, 5V, 3.3V, RESET, IOREF), header analógico (A0–A15), header digital bajo (pines 0–13 con PWM e interrupciones), header digital alto (pines 14–53 con UART, SPI e I2C), y header ICSP para programación in-system del ATmega2560.

11. **Header ICSP (ATmega2560)**: Conjunto de 6 pines (2×3) que permiten la programación directa del ATmega2560 mediante el protocolo SPI, sin pasar por el bootloader. Se usa con programadores externos como el AVR ISP, USBasp o Arduino as ISP. Es útil para grabar el bootloader en un chip nuevo o para programar la placa cuando el bootloader está dañado.

12. **Header ICSP (ATmega16U2)**: Conjunto de 6 pines similar para la programación del microcontrolador USB-to-serial. Solo se usa en casos muy específicos, como cuando se desea cambiar el firmware del ATmega16U2 para implementar funciones HID.

### 3.2 Accesorios incluidos típicamente

- Placa Arduino Mega 2560 Rev3
- Cable USB tipo A-B (para conexión al ordenador)

### 3.3 Shields y módulos compatibles (no incluidos)

| Shield / Módulo | Función | Compatibilidad |
|---|---|---|
| Arduino Ethernet Shield | Conectividad de red por cable (RJ-45) | Directa — mismo factor de forma |
| Arduino WiFi Shield / ESP8266 | Conectividad WiFi | Directa / vía serial |
| Arduino Motor Shield | Control de motores DC y paso a paso | Directa |
| Shield de relés | Control de cargas de potencia (CA/CD) | Directa |
| LCD Shield (16×2 o 20×4) | Pantalla de texto con botones | Directa |
| Módulo sensor de temperatura (DHT22, DS18B20) | Lectura de temperatura y humedad | Vía pin digital + librería |
| Módulo RFID (RC522) | Lectura de tarjetas y llaveros RFID | Vía SPI (pines 50–53) |
| Módulo GPS (NEO-6M) | Posicionamiento por satélite | Vía UART (Serial1/2/3) |
| Módulo Bluetooth (HC-05/HC-06) | Comunicación inalámbrica Bluetooth | Vía UART |
| Módulo microSD | Almacenamiento de datos en tarjeta SD | Vía SPI |
| Módulo de relés 4/8 canales | Control de múltiples cargas de potencia | Vía pines digitales |
| Servomotores (SG90, MG996R) | Control de posición angular | Vía pines PWM |
| Protoshield + breadboard | Prototipado directo sobre la placa | Directa |

---

## 4. Configuración y puesta en marcha

### 4.1 Requisitos del sistema

Para programar el Arduino Mega 2560 se necesita un ordenador con:

- **Sistema operativo**: Windows 10/11, macOS 10.14+ o Linux (Ubuntu, Debian, Fedora, etc.)
- **Puerto USB disponible**: Tipo A (para conectar el cable USB A-B)
- **Conexión a Internet**: Para descargar el Arduino IDE y las librerías (no necesario una vez instalado)
- **Espacio en disco**: Al menos 500 MB para el IDE y las librerías

### 4.2 Instalación del Arduino IDE

1. **Descargar el Arduino IDE**: Visitar [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software) y descargar la versión más reciente del Arduino IDE (versión 2.x recomendada por su interfaz mejorada con autocompletado y depuración serial avanzada, o versión 1.8.x si se prefiere la versión clásica y ligera).

2. **Instalar el IDE**:
   - **Windows**: Ejecutar el instalador (.exe) descargado y seguir el asistente. Aceptar la instalación de los drivers USB cuando el sistema lo solicite.
   - **macOS**: Copiar la aplicación Arduino.app a la carpeta Aplicaciones.
   - **Linux**: Descomprimir el archivo descargado y ejecutar el script `install.sh` desde la terminal, o ejecutar directamente el archivo `arduino` desde la carpeta descomprimida.

3. **Instalación alternativa — Arduino Web Editor**: También es posible usar el Arduino Web Editor a través de [https://create.arduino.cc/editor](https://create.arduino.cc/editor), que no requiere instalación local pero sí el plugin Arduino Create Agent para la comunicación USB.

### 4.3 Conexión y primeros pasos

1. **Conectar el Arduino Mega al ordenador**: Usar el cable USB tipo A-B. Conectar el extremo tipo B al conector USB de la placa y el extremo tipo A a un puerto USB del ordenador.

2. **Verificar la alimentación**: El LED verde de encendido (PWR) debe iluminarse, y el LED naranja del pin 13 puede parpadear brevemente si la placa tiene el sketch de prueba de fábrica cargado.

3. **Seleccionar la placa en el IDE**:
   - Abrir el Arduino IDE.
   - Ir a **Herramientas → Placa → Arduino AVR Boards → Arduino Mega or Mega 2560**.
   - Si la opción no aparece, ir a **Herramientas → Placa → Gestor de placas** y buscar "Arduino AVR Boards" para instalarlo.

4. **Seleccionar el procesador**: En **Herramientas → Procesador**, seleccionar **ATmega2560 (Mega 2560)**. Esta opción es importante porque el IDE también soporta el Mega con el ATmega1280 (versión anterior).

5. **Seleccionar el puerto serial**: Ir a **Herramientas → Puerto** y seleccionar el puerto COM (Windows) o /dev/ttyUSBx / /dev/ttyACMx (Linux/macOS) que corresponda al Arduino Mega. Si no aparece ningún puerto, verificar la conexión USB y los drivers.

6. **Subir el sketch de prueba "Blink"**:
   - Ir a **Archivo → Ejemplos → 01.Basics → Blink**.
   - Hacer clic en el botón **Subir** (flecha derecha →) en la barra de herramientas.
   - Observar los LEDs TX/RX durante la subida (parpadearán rápidamente).
   - Una vez completada la subida, el LED naranja del pin 13 debe parpadear con un intervalo de 1 segundo (encendido 1 s, apagado 1 s).

### 4.4 Alimentación de la placa

El Arduino Mega puede alimentarse de tres formas:

| Fuente | Voltaje | Corriente máxima | Notas |
|---|---|---|---|
| **USB** | 5 V | ~500 mA | Suficiente para la placa y circuitos de bajo consumo |
| **Conector de barril DC** | 7 – 12 V (recomendado) | Depende del regulador | Permite alimentar cargas mayores a 500 mA en el pin 5V |
| **Pin VIN** | 7 – 12 V (recomendado) | Depende del regulador | Conectar a la fuente externa positiva; GND al pin de tierra |

- **Regla práctica**: Si el proyecto solo involucra la placa y componentes de bajo consumo (LEDs, sensores, pequeños displays), la alimentación por USB es suficiente. Si se controlan servomotores, motores DC, relés o múltiples LEDs de alta potencia, usar alimentación externa por el conector de barril o VIN.

- **No exceder las capacidades**: El regulador de 5 V de la placa puede proporcionar aproximadamente 800 mA cuando se alimenta con 7 V, pero esta capacidad disminuye a medida que aumenta el voltaje de entrada (mayor disipación de calor). Nunca solicitar más de 20 mA por pin digital individual ni más de 40 mA en circunstancias extremas.

---

## 5. Guía de uso paso a paso

### 5.1 Estructura de un sketch de Arduino

Todo programa de Arduino (llamado "sketch") tiene al menos dos funciones obligatorias:

```cpp
void setup() {
  // Se ejecuta una sola vez al iniciar o resetear la placa
  // Aquí se configuran los pines, se inicializan librerías y se establecen
  // los parámetros de comunicación
}

void loop() {
  // Se ejecuta repetidamente después de setup()
  // Aquí va la lógica principal del programa
}
```

### 5.2 Configuración de pines digitales

**Pines como salida (OUTPUT)**:
```cpp
void setup() {
  pinMode(13, OUTPUT);    // Configura el pin 13 como salida
}

void loop() {
  digitalWrite(13, HIGH); // Enciende (5 V)
  delay(1000);            // Espera 1 segundo
  digitalWrite(13, LOW);  // Apaga (0 V)
  delay(1000);            // Espera 1 segundo
}
```

**Pines como entrada (INPUT) con resistencia pull-up interna**:
```cpp
void setup() {
  pinMode(2, INPUT_PULLUP);  // Pin 2 como entrada con pull-up interna
  pinMode(13, OUTPUT);       // Pin 13 como salida (LED)
}

void loop() {
  int estadoBoton = digitalRead(2);  // Lee el estado del pin 2
  if (estadoBoton == LOW) {          // Botón presionado (conecta a GND)
    digitalWrite(13, HIGH);          // Enciende LED
  } else {
    digitalWrite(13, LOW);           // Apaga LED
  }
}
```

### 5.3 Lectura de entradas analógicas

Las 16 entradas analógicas (A0–A15) convierten un voltaje entre 0 y 5 V en un valor digital entre 0 y 1023 (resolución de 10 bits):

```cpp
void setup() {
  Serial.begin(9600);  // Inicia comunicación serial a 9600 baudios
}

void loop() {
  int valorSensor = analogRead(A0);        // Lee el valor analógico (0-1023)
  float voltaje = valorSensor * (5.0 / 1023.0);  // Convierte a voltaje
  Serial.print("Valor: ");
  Serial.print(valorSensor);
  Serial.print(" | Voltaje: ");
  Serial.print(voltaje, 2);
  Serial.println(" V");
  delay(500);
}
```

### 5.4 Salida PWM (modulación por ancho de pulso)

Los 15 pines PWM pueden generar una señal cuadrada con ciclo de trabajo variable, útil para controlar la intensidad de LEDs, la velocidad de motores DC y la posición de servomotores:

```cpp
void setup() {
  // No se necesita pinMode para analogWrite
}

void loop() {
  // Fade in: incrementa la intensidad gradualmente
  for (int brillo = 0; brillo <= 255; brillo++) {
    analogWrite(9, brillo);  // PWM en pin 9, valor 0-255
    delay(10);
  }
  // Fade out: decrementa la intensidad gradualmente
  for (int brillo = 255; brillo >= 0; brillo--) {
    analogWrite(9, brillo);
    delay(10);
  }
}
```

### 5.5 Comunicación serial (UART)

El Mega 2560 tiene 4 puertos UART de hardware, lo que lo diferencia del Uno (que solo tiene 1):

| Objeto | Pines RX/TX | Uso típico |
|---|---|---|
| `Serial` | 0 (RX) / 1 (TX) | Comunicación con el ordenador vía USB |
| `Serial1` | 19 (RX1) / 18 (TX1) | Dispositivo serial externo 1 |
| `Serial2` | 17 (RX2) / 16 (TX2) | Dispositivo serial externo 2 |
| `Serial3` | 15 (RX3) / 14 (TX3) | Dispositivo serial externo 3 |

**Ejemplo: Comunicación con módulo Bluetooth en Serial1**:
```cpp
void setup() {
  Serial.begin(9600);     // Puerto USB para monitor serial
  Serial1.begin(9600);    // Puerto Serial1 para Bluetooth HC-05
}

void loop() {
  // Leer del Bluetooth y enviar al monitor serial
  if (Serial1.available()) {
    char dato = Serial1.read();
    Serial.print("BT dice: ");
    Serial.println(dato);
  }
  // Leer del monitor serial y enviar al Bluetooth
  if (Serial.available()) {
    char dato = Serial.read();
    Serial1.print(dato);
  }
}
```

### 5.6 Comunicación I2C

El bus I2C permite comunicarse con múltiples dispositivos usando solo 2 pines (SDA y SCL):

```cpp
#include <Wire.h>

void setup() {
  Wire.begin();        // Inicia como maestro I2C
  Serial.begin(9600);
}

void loop() {
  // Escanear dispositivos I2C conectados
  Serial.println("Escaneando...");
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo encontrado en 0x");
      Serial.println(addr, HEX);
    }
  }
  delay(5000);
}
```

### 5.7 Control de servomotores

El Mega 2560 puede controlar hasta 48 servomotores simultáneamente con la librería Servo:

```cpp
#include <Servo.h>

Servo miServo;

void setup() {
  miServo.attach(9);  // Conecta el servo al pin 9 (PWM)
}

void loop() {
  miServo.write(0);    // Posición 0°
  delay(1000);
  miServo.write(90);   // Posición 90°
  delay(1000);
  miServo.write(180);  // Posición 180°
  delay(1000);
}
```

### 5.8 Interrupciones externas

Las interrupciones permiten ejecutar una función inmediatamente cuando se detecta un cambio en un pin, sin necesidad de estar consultando continuamente (polling):

```cpp
volatile bool botonPresionado = false;

void setup() {
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), botonISR, FALLING);
  pinMode(13, OUTPUT);
}

void loop() {
  if (botonPresionado) {
    digitalWrite(13, !digitalRead(13));  // Alterna LED
    botonPresionado = false;
  }
}

void botonISR() {
  botonPresionado = true;
}
```

---

## 6. Mantenimiento básico

### 6.1 Cuidado físico de la placa

- **Manipulación**: Siempre manipular la placa por los bordes, evitando tocar los componentes electrónicos, las pistas de cobre o los pines con los dedos. La electricidad estática del cuerpo humano puede dañar los componentes sensibles. Antes de manipular la placa, tocar una superficie metálica conectada a tierra para descargarse.

- **Almacenamiento**: Guardar las placas en bolsas antiestáticas o en cajas de plástico con espuma antiestática cuando no estén en uso. No apilar las placas directamente unas sobre otras, ya que los pines de la placa inferior pueden rayar o cortocircuitar las pistas de la placa superior.

- **Limpieza**: Si la placa acumula polvo, limpiarla con un pincel suave o aire comprimido. Para manchas de flux o residuos de soldadura, usar alcohol isopropílico (IPA) al 90 %+ con un cepillo suave. Nunca sumergir la placa en líquido ni usar limpiadores abrasivos.

- **Protección contra ESD**: Cuando se trabaje con la placa fuera del aula o en condiciones de baja humedad, usar una pulsera antiestática conectada a tierra. Las descargas electrostáticas pueden destruir el ATmega2560 o el ATmega16U2 sin señales visibles de daño.

### 6.2 Inspección periódica

- **Pines doblados o rotos**: Verificar que todos los pines del header estén rectos y firmes. Los pines doblados pueden causar conexiones intermitentes o cortocircuitos. Enderezar los pines doblados con alicates de punta plana con cuidado de no quebrarlos.

- **Conector USB flojo**: El conector USB tipo B puede aflojarse con el uso repetido. Si el cable USB no se mantiene firmemente conectado, el conector puede estar desgastado. No forzar el cable; si la conexión es inestable, puede ser necesario soldar los puntos de anclaje del conector o reemplazar la placa.

- **Conector de barril DC**: Verificar que el conector de alimentación no esté suelto ni tenga holgura excesiva. Un conector flojo puede causar reinicios aleatorios de la placa.

- **Regulador de voltaje**: Si el regulador se siente excesivamente caliente al tacto durante el funcionamiento (no se puede mantener el dedo sobre él), la placa está consumiendo demasiada corriente o el voltaje de entrada es demasiado alto. Reducir la carga o el voltaje de alimentación.

### 6.3 Mantenimiento del bootloader

El bootloader del ATmega2560 es un pequeño programa residente en los primeros 8 KB de la memoria Flash que permite la subida de sketches a través del puerto USB sin necesidad de un programador externo. Si el bootloader se corrompe (por ejemplo, por un sketch que escribe incorrectamente en la memoria Flash o por una interrupción durante la subida), la placa no podrá recibir nuevos programas por USB:

- **Síntomas de bootloader dañado**: El IDE muestra errores como "avrdude: stk500v2_ReceiveMessage(): timeout" o "not in sync" al intentar subir un sketch. Los LEDs TX/RX no parpadean durante el intento de subida.

- **Solución**: Grabar el bootloader usando un programador externo (Arduino as ISP, AVR ISP, USBasp) conectado al header ICSP del ATmega2560. En el IDE, seleccionar **Herramientas → Quemar bootloader** con el programador adecuado conectado.

### 6.4 Calendario de mantenimiento sugerido

| Frecuencia | Tarea |
|---|---|
| **Después de cada uso** | Desconectar la alimentación, retirar cables y componentes, guardar en bolsa antiestática |
| **Semanal** | Inspección visual de pines y conectores, verificación de funcionamiento con sketch Blink |
| **Mensual** | Limpieza con aire comprimido, inspección del conector USB, prueba de comunicación serial |
| **Trimestral** | Verificación de todos los pines digitales y analógicos con sketch de prueba, comprobación del bootloader |
| **Semestral** | Revisión completa de la placa, verificación de los reguladores de voltaje, actualización del IDE y las librerías |

---

## 7. Solución de problemas comunes

### 7.1 No se puede subir el sketch al Arduino

**Causas posibles:**
- Placa o procesador incorrecto seleccionado en el IDE
- Puerto serial incorrecto o no detectado
- Cable USB defectuoso o de solo carga (sin datos)
- Bootloader dañado o ausente
- Otro programa usando el puerto serial (monitor serial abierto en otra aplicación)
- Driver USB no instalado (especialmente en Windows)

**Soluciones:**
1. Verificar que la placa seleccionada sea **Arduino Mega or Mega 2560** y el procesador sea **ATmega2560**.
2. En **Herramientas → Puerto**, seleccionar el puerto que corresponda al Mega (COMx en Windows, /dev/ttyACMx o /dev/ttyUSBx en Linux/macOS).
3. Probar con otro cable USB. Muchos cables de carga solo tienen conductores de energía y no de datos.
4. Cerrar cualquier programa que pueda estar usando el puerto serial (otra instancia del IDE, monitor serial, Processing, etc.).
5. En Windows, verificar en el Administrador de dispositivos que el Arduino aparezca bajo "Puertos (COM y LPT)" como "Arduino Mega 2560". Si aparece con un signo de exclamación amarillo, instalar los drivers manualmente.
6. Si el problema persiste, intentar grabar el bootloader mediante un programador ICSP.

### 7.2 La placa no enciende o se reinicia aleatoriamente

**Causas posibles:**
- Alimentación insuficiente (cable USB defectuoso, hub USB sin potencia, adaptador DC inadecuado)
- Cortocircuito en el circuito conectado a la placa
- Regulador de voltaje dañado por sobretensión o sobrecorriente
- Condensadores dañados

**Soluciones:**
1. Probar la placa sin ningún circuito conectado (solo alimentación USB). Si funciona, el problema está en el circuito externo.
2. Probar con otro cable USB y otro puerto USB del ordenador (preferiblemente directo, no a través de hub).
3. Si se usa alimentación DC, verificar que el adaptador suministre 7–12 V y la corriente suficiente.
4. Medir el voltaje entre los pines 5V y GND con un multímetro. Debe leer aproximadamente 5 V. Si es significativamente menor, el regulador puede estar dañado.
5. Buscar cortocircuitos en las conexiones del circuito externo. Un pin conectado accidentalmente a GND mientras está configurado como salida HIGH puede dañar el pin.

### 7.3 Los pines digitales no funcionan como se espera

**Causas posibles:**
- Pin configurado incorrectamente (INPUT en lugar de OUTPUT o viceversa)
- Pin dañado por sobrecorriente o cortocircuito previo
- Conflicto con funciones alternativas (pines 0 y 1 usados por Serial, pines 20 y 21 por I2C, pines 50-53 por SPI)
- Uso incorrecto de `digitalWrite` en pines configurados como `INPUT`

**Soluciones:**
1. Verificar que el pin esté correctamente configurado con `pinMode()` en el `setup()`.
2. Evitar usar los pines 0 y 1 (RX/TX del Serial USB) como pines digitales generales, ya que interfieren con la comunicación serial.
3. Si se usan librerías que emplean I2C, SPI o UART, los pines asociados no deben usarse como I/O general.
4. Probar el pin sospechoso con un sketch simple (Blink para salidas, lectura de botón para entradas). Si el pin no responde, puede estar dañado y debe reasignarse a otro pin.

### 7.4 Las lecturas analógicas son inestables o incorrectas

**Causas posibles:**
- Ruido eléctrico en el circuito de entrada
- Voltaje de referencia (AREF) inestable
- Sensor no conectado correctamente o con impedancia de salida muy alta
- Interferencia de pines digitales switching cercanos a las entradas analógicas

**Soluciones:**
1. Agregar un condensador de desacople de 100 nF (0,1 µF) entre la entrada analógica y GND, lo más cerca posible del pin, para filtrar el ruido de alta frecuencia.
2. Usar `analogReference(DEFAULT)` para confirmar que la referencia sea el voltaje de alimentación (5 V), o `analogReference(INTERNAL)` para usar la referencia interna de 1,1 V del ATmega2560 (más estable pero rango limitado).
3. Hacer múltiples lecturas y promediar para reducir el ruido:
   ```cpp
   long suma = 0;
   for (int i = 0; i < 10; i++) {
     suma += analogRead(A0);
     delay(5);
   }
   int promedio = suma / 10;
   ```
4. Conectar el pin AREF a 5V a través de un condensador de 100 nF si se usa referencia externa.
5. Mantener las pistas de las señales analógicas alejadas de las señales digitales de alta frecuencia (PWM, SPI).

### 7.5 El monitor serial no muestra datos o muestra caracteres extraños

**Causas posibles:**
- Velocidad de baudios diferente entre el sketch y el monitor serial
- Puerto serial incorrecto seleccionado
- Sketch que envía datos demasiado rápido para el monitor
- Problema con el driver USB

**Soluciones:**
1. Verificar que la velocidad del monitor serial coincida con la del `Serial.begin()`. Si el sketch usa `Serial.begin(9600)`, el monitor debe estar configurado a 9600 baudios.
2. Seleccionar el puerto serial correcto en **Herramientas → Puerto**.
3. Agregar `delay()` entre envíos de datos al monitor serial si se envían datos continuamente.
4. Cerrar y reabrir el monitor serial. A veces el monitor pierde la conexión y necesita reiniciarse.
5. Si los caracteres son ilegibles, probar diferentes velocidades de baudios (9600, 115200) hasta encontrar la correcta.

### 7.6 El sketch funciona en el Uno pero no en el Mega

**Causas posibles:**
- Diferencias en el mapeo de pines PWM, SPI o I2C entre el Uno y el Mega
- Librería no compatible con el ATmega2560
- Pines de interrupción diferentes (el Uno tiene pines 2, 3; el Mega tiene pines 2, 3, 18, 19, 20, 21)
- Uso de SoftwareSerial (que puede tener problemas de temporización en el Mega)

**Soluciones:**
1. Verificar el mapeo de pines específico del Mega 2560. Los pines SPI en el Mega son 50–53 (no 10–13 como en el Uno). Los pines I2C son 20 y 21 (igual que en el Uno).
2. En lugar de SoftwareSerial, usar los puertos UART hardware adicionales del Mega (Serial1, Serial2, Serial3) para comunicación serial con dispositivos externos.
3. Verificar que las librerías utilizadas sean compatibles con el ATmega2560. La mayoría lo son, pero algunas librerías antiguas pueden tener problemas.
4. Consultar la documentación específica del Mega para las diferencias de pines.

### 7.7 La placa se sobrecalienta

**Causas posibles:**
- Consumo excesivo a través del pin 5V o de los pines digitales
- Voltaje de alimentación DC demasiado alto (cerca de 20 V)
- Cortocircuito en el circuito externo
- Regulador de voltaje defectuoso

**Soluciones:**
1. Desconectar inmediatamente la alimentación si la placa está muy caliente.
2. Medir la corriente total de consumo con un multímetro. No debe exceder los 800 mA del pin 5V.
3. Si se controlan motores, relés u otras cargas de alta corriente, usar una fuente de alimentación separada para estas cargas y conectarlas a través de transistores, MOSFETs o drivers, no directamente desde los pines del Arduino.
4. Reducir el voltaje de alimentación DC a 7–9 V para minimizar la disipación del regulador.
5. Nunca exceder 20 mA por pin digital. Para cargas mayores, usar un transistor o driver como intermediario.

### 7.8 Error de memoria insuficiente (SRAM o Flash)

**Causas posibles:**
- Sketch demasiado grande para la memoria Flash disponible (248 KB útiles)
- Uso excesivo de variables globales, arreglos grandes o cadenas de texto que agotan la SRAM (8 KB)
- Librerías pesadas que consumen mucha memoria
- Fragmentación de la memoria dinámica (heap)

**Soluciones:**
1. Usar la macro `F()` para almacenar cadenas de texto en la memoria Flash en lugar de la SRAM:
   ```cpp
   Serial.println(F("Texto almacenado en Flash, no en SRAM"));
   ```
2. Reducir el tamaño de los arreglos y usar tipos de datos más pequeños (`byte` en lugar de `int` cuando el rango lo permita).
3. Usar `PROGMEM` para almacenar tablas y datos constantes en la memoria Flash.
4. Verificar el uso de memoria al compilar: el IDE muestra el porcentaje de Flash y SRAM utilizados después de la compilación.
5. Si se agota la SRAM, considerar usar el tipo `byte` (1 byte) en lugar de `int` (2 bytes) o `long` (4 bytes) cuando los rangos de valores lo permitan.
6. Para proyectos que excedan significativamente la capacidad del Mega, considerar migrar a un Arduino Due (96 KB SRAM, 84 MHz) o a un ESP32 (520 KB SRAM, WiFi integrado).

---

## 8. Materiales, repuestos y accesorios

### 8.1 Consumibles principales

| Consumible | Especificación | Frecuencia de reposición |
|---|---|---|
| **Cable USB A-B** | Cable de datos USB tipo A a tipo B, mínimo 1 m | Reemplazar si la conexión es inestable |
| **Adaptador DC** | 7–12 V DC, centro positivo, conector 2,1 mm, mínimo 1 A | Reposición si se pierde o daña |
| **Batería / pack de baterías** | 7,2–12 V (6×AA NiMH o pack LiPo 2S–3S) | Para proyectos portátiles |
| **Protoboards (breadboard)** | 830 puntos (estándar) o 400 puntos (media) | Uso continuo — reemplazar cuando los contactos se aflojen |
| **Cables puente (jumpers)** | MM, MH, HH — varios colores y longitudes | Consumible continuo — se pierden y desgastan |
| **Resistencias** | Varios valores (220 Ω, 1 kΩ, 4,7 kΩ, 10 kΩ, etc.) | Consumible básico |
| **LEDs** | 5 mm, varios colores (rojo, verde, amarillo, azul, blanco) | Consumible básico |
| **Condensadores de desacople** | 100 nF (0,1 µF) cerámicos | Para filtrado de ruido en entradas analógicas |

### 8.2 Repuestos y componentes de protección

| Repuesto | Referencia | Notas |
|---|---|---|
| Arduino Mega 2560 Rev3 (placa completa) | A000067 | En caso de daño irreparable |
| ATmega2560 (chip suelto) | ATMEGA2560-16AU | Solo para reparación avanzada (requiere soldadura SMD) |
| ATmega16U2 (chip USB) | ATMEGA16U2-MU | Solo para reparación avanzada |
| Protoshield para Mega | Varios fabricantes | Para prototipado permanente |
| Carcasa / caja protectora para Mega | Varios fabricantes (acrílico, plástico) | Protección contra daños físicos |

### 8.3 Módulos y sensores recomendados para el aula

| Módulo / Sensor | Función | Interfaz | Pines usados |
|---|---|---|---|
| Sensor ultrasónico HC-SR04 | Medición de distancia | Digital | 2 pines (Trigger + Echo) |
| Sensor de temperatura DHT22 | Temperatura y humedad | OneWire | 1 pin digital |
| Sensor de temperatura DS18B20 | Temperatura precisa | OneWire | 1 pin digital |
| Módulo RTC DS3231 | Reloj en tiempo real | I2C | SDA (20), SCL (21) |
| Pantalla LCD 16×2 / 20×4 | Visualización de texto | I2C o paralelo | I2C: 2 pines; Paralelo: 6–12 pines |
| Pantalla OLED 0,96" / 1,3" | Visualización gráfica | I2C o SPI | I2C: 2 pines; SPI: 4 pines |
| Módulo RFID RC522 | Lectura de tarjetas RFID | SPI | 50–53 + 1 pin digital |
| Módulo microSD | Almacenamiento de datos | SPI | 50–53 + 1 pin digital (CS) |
| Módulo GPS NEO-6M | Posicionamiento GPS | UART | Serial1/2/3 (2 pines) |
| Módulo Bluetooth HC-05 | Comunicación Bluetooth | UART | Serial1/2/3 (2 pines) |
| Módulo WiFi ESP8266/ESP-01 | Conectividad WiFi | UART | Serial1/2/3 (2 pines) |
| Driver motor L298N | Control de 2 motores DC o 1 paso a paso | Digital | 6 pines (4 dirección + 2 PWM) |
| Módulo de relés 4 canales | Control de cargas de potencia | Digital | 4 pines |
| Celda de carga + HX711 | Báscula digital / fuerza | Digital | 2 pines (SCK + DT) |
| Acelerómetro/giroscopio MPU6050 | Orientación y movimiento | I2C | SDA (20), SCL (21) |

### 8.4 Accesorios complementarios recomendados para el aula

| Accesorio | Función | Prioridad |
|---|---|---|
| **Kit de sensores (37 en 1)** | Amplia variedad de sensores para experimentación | Media |
| **Set de protoboards** | Para prototipado sin soldadura | Alta |
| **Caja organizadora de componentes** | Organizar resistencias, LEDs, sensores y cables | Alta |
| **Multímetro digital** | Medición de voltaje, corriente y continuidad | Alta |
| **Pulsera antiestática** | Protección ESD al manipular las placas | Alta |
| **Programador AVR ISP** | Para grabar bootloader en caso de daño | Media |
| **Carcasas protectoras** | Proteger las placas durante uso y almacenamiento | Media |
| **Fuente de alimentación ajustable** | Para proyectos que requieren voltajes específicos | Media |
| **Oscilosccopio USB** | Para análisis de señales en proyectos avanzados | Baja |

---

## 9. Normas de uso STEAM

### 9.1 Normas generales de seguridad

El Arduino Mega 2560 opera a 5 V y es intrínsecamente seguro en términos de riesgo eléctrico, pero el uso de fuentes de alimentación externas y el control de cargas de potencia sí presentan riesgos:

1. **Alimentación segura**: Nunca conectar voltajes superiores a 5 V directamente a los pines del Arduino. Las señales de entrada a los pines digitales y analógicos no deben exceder los 5 V (ni ser negativas respecto a GND). Voltajes superiores pueden destruir el microcontrolador instantáneamente.

2. **Fuentes de alimentación externas**: Cuando se usen motores, relés, electroimanes u otras cargas de alta corriente, usar una fuente de alimentación separada para estas cargas. Nunca alimentar motores directamente desde los pines 5V o los pines digitales del Arduino. Usar drivers, transistores MOSFET o shields de motor como intermediarios.

3. **Protección ESD**: El ATmega2560 es sensible a descargas electrostáticas. Antes de manipular la placa, tocar una superficie metálica conectada a tierra. Usar pulsera antiestática cuando sea posible. No manipular la placa sobre alfombras o superficies que generen estática.

4. **Cuidado con los cortocircuitos**: Un pin configurado como OUTPUT en HIGH conectado accidentalmente a GND puede consumir más de 40 mA y dañar el pin permanentemente. Siempre verificar las conexiones antes de alimentar la placa.

5. **Cargas inductivas**: Los relés, motores y electroimanes generan picos de voltaje inverso (flyback) cuando se desactivan. Estos picos pueden dañar los pines del Arduino o los transistores de control. Usar siempre diodos de protección (diodo flyback 1N4007 o similar) en paralelo con cargas inductivas.

6. **Cableado ordenado**: Mantener el cableado del prototipo ordenado y etiquetado. Un cable suelto puede causar un cortocircuito o una conexión intermitente que sea muy difícil de diagnosticar.

### 9.2 Normas de operación

1. **Autorización**: Solo estudiantes que hayan completado la capacitación básica de Arduino pueden usar las placas de forma autónoma. Los estudiantes nuevos deben ser supervisados.

2. **Registro de uso**: Anotar en el cuadro de control cada sesión de uso, incluyendo: fecha, operador, placa utilizada (Mega 1 o Mega 2), tipo de proyecto y observaciones.

3. **Identificación de las placas**: Las dos placas Arduino Mega del aula deben estar claramente identificadas (por ejemplo, con una etiqueta "MEGA-1" y "MEGA-2") para rastrear su uso y detectar problemas específicos de cada unidad.

4. **Desconexión antes de modificar el circuito**: Siempre desconectar la alimentación (USB y/o DC) antes de hacer cambios en el cableado del prototipo. Conectar o desconectar componentes con la placa encendida puede causar cortocircuitos o daños.

5. **No forzar los conectores**: Los pines del header hembra del Arduino no deben forzarse. Si un cable o componente no entra suavemente, verificar que el pin esté alineado correctamente. Forzar un pin puede doblarlo o arrancarlo de la placa.

6. **Subida de sketches con cuidado**: Antes de subir un sketch, verificar que los pines configurados como OUTPUT no estén conectados a cargas que puedan activarse inesperadamente (motores, relés, calentadores). Un pin puede cambiar de estado brevemente durante el reset del microcontrolador.

### 9.3 Normas de uso con dos unidades

Con dos Arduino Mega disponibles en el aula, se establecen las siguientes normas para su uso eficiente:

1. **Asignación por proyecto**: Cada proyecto de mediana complejidad puede usar un Arduino Mega. Proyectos muy complejos que requieran más de 54 pines o más de 4 UART pueden usar ambos Megas comunicándose entre sí por UART, I2C o SPI.

2. **Rotación equitativa**: Si hay más de dos equipos de estudiantes, establecer un sistema de rotación para el uso de las placas, de modo que todos los equipos tengan acceso equitativo.

3. **Comunicación entre placas**: Para proyectos que usen ambos Megas, definir claramente el protocolo de comunicación. UART es la opción más simple (conectar TX de uno al RX del otro y viceversa, con GND común). I2C permite conectar un Mega como maestro y otro como esclavo.

4. **Almacenamiento separado**: Cada placa debe guardarse en su propia bolsa antiestática con su cable USB, claramente etiquetada. Los prototipos en curso pueden dejarse montados en la protoboard, pero la placa debe desconectarse de la alimentación al final de la sesión.

5. **Mantenimiento individual**: Si una placa presenta problemas, no intercambiarla por la otra sin diagnosticar el problema primero. Una placa con un pin dañado puede causar confusión si se usa en un proyecto que intente usar ese pin.

### 9.4 Uso eficiente en el contexto del aula

1. **Proyectos por niveles**: Se recomienda una progresión de proyectos: nivel básico (LEDs, botones, sensores simples), nivel intermedio (pantallas, motores, comunicación serial), nivel avanzado (multi-sensor, control PID, comunicación entre dos Megas, IoT).

2. **Aprovechar los 4 UART**: A diferencia del Arduino Uno, el Mega tiene 4 puertos seriales de hardware. En proyectos que requieran comunicación con múltiples dispositivos seriales (GPS + Bluetooth + pantalla serial), usar los diferentes UART en lugar de SoftwareSerial.

3. **Planificación de pines**: Antes de cablear un proyecto, hacer un mapa de asignación de pines que considere las funciones especiales (PWM, interrupciones, I2C, SPI, UART). Esto evita conflictos y facilita la depuración.

4. **Modularidad**: Diseñar los proyectos de forma modular, con cada sensor o actuador encapsulado en una función. Esto facilita la reutilización de código entre proyectos y la depuración de problemas.

5. **Documentación**: Los estudiantes deben documentar sus proyectos, incluyendo: diagrama de cableado, lista de pines usados, librerías necesarias y notas de funcionamiento. Esta documentación es invaluable para los estudiantes que usen el proyecto después.

### 9.5 Protocolo de emergencia

1. **Placa humeante o con olor a quemado**: Desconectar inmediatamente la alimentación USB y DC. No tocar los componentes calientes. Dejar enfriar la placa durante al menos 10 minutos antes de inspeccionarla. Identificar el componente dañado (generalmente el regulador de voltaje o un pin de I/O) y notificar al coordinador.

2. **Cortocircuito en el prototipo**: Si se detecta un cortocircuito (la placa se reinicia, el LED de encendido parpadea o se apaga), desconectar inmediatamente la alimentación y revisar el cableado antes de reconectar.

3. **Cable USB dañado**: Si el cable USB presenta cable expuesto, conector flojo o calentamiento anormal, desecharlo inmediatamente y reemplazarlo. Un cable dañado puede causar un cortocircuito en el puerto USB del ordenador.

4. **Componente conectado incorrectamente**: Si se conecta un componente con polaridad invertida (por ejemplo, un condensador electrolítico o un LED al revés), desconectar inmediatamente antes de que el componente se dañe o explote.

---

## 10. Enlaces y recursos adicionales

### 10.1 Documentación oficial

- **Arduino — Documentación oficial Mega 2560 Rev3**: [https://docs.arduino.cc/hardware/mega-2560](https://docs.arduino.cc/hardware/mega-2560)
- **Arduino — Tienda oficial Mega 2560 Rev3**: [https://store-usa.arduino.cc/products/arduino-mega-2560-rev3](https://store-usa.arduino.cc/products/arduino-mega-2560-rev3)
- **Arduino — Esquema del Mega 2560 Rev3 (PDF)**: [https://www.arduino.cc/en/uploads/Main/arduino-mega2560_R3-sch.pdf](https://www.arduino.cc/en/uploads/Main/arduino-mega2560_R3-sch.pdf)
- **ATmega2560 — Hoja de datos completa (PDF)**: [https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf)

### 10.2 Referencia de programación

- **Arduino Language Reference**: [https://www.arduino.cc/reference/en/](https://www.arduino.cc/reference/en/) — Referencia completa de funciones, variables y estructuras del lenguaje Arduino.
- **Arduino Built-in Examples**: [https://www.arduino.cc/en/Tutorial/BuiltInExamples](https://www.arduino.cc/en/Tutorial/BuiltInExamples) — Ejemplos incluidos en el IDE, organizados por categoría.
- **Arduino Mega Pinout Reference**: [https://pcbsync.com/arduino-mega-2560-pinout](https://pcbsync.com/arduino-mega-2560-pinout) — Guía completa de pines con funciones especiales.

### 10.3 Tutoriales y cursos

- **Arduino — Getting Started with Mega 2560** (YouTube): Tutorial oficial de configuración inicial.
- **Paul McWhorter — Arduino Tutorial Series** (YouTube): Serie completa de tutoriales desde cero hasta avanzado, altamente recomendada para el aula.
- **Arduino Project Hub**: [https://create.arduino.cc/projecthub](https://create.arduino.cc/projecthub) — Repositorio comunitario de proyectos con instrucciones paso a paso.
- **Instructables — Arduino**: [https://www.instructables.com/circuits/arduino/](https://www.instructables.com/circuits/arduino/) — Proyectos detallados con fotografías y código.

### 10.4 Librerías recomendadas

| Librería | Función | Instalación |
|---|---|---|
| **Servo** | Control de servomotores | Incluida en el IDE |
| **Wire** | Comunicación I2C | Incluida en el IDE |
| **SPI** | Comunicación SPI | Incluida en el IDE |
| **LiquidCrystal** | Pantallas LCD 16×2 / 20×4 | Incluida en el IDE |
| **Adafruit_Sensor** | Base para sensores Adafruit | Gestor de librerías |
| **DHT** | Sensores de temperatura/humedad DHT | Gestor de librerías |
| **OneWire** | Comunicación OneWire (DS18B20) | Gestor de librerías |
| **DallasTemperature** | Sensor DS18B20 | Gestor de librerías |
| **MFRC522** | Lector RFID RC522 | Gestor de librerías |
| **HX711** | Celda de carga / báscula | Gestor de librerías |
| **Adafruit_GFX + SSD1306** | Pantallas OLED | Gestor de librerías |
| **RTClib** | Módulos RTC DS3231/DS1307 | Gestor de librerías |
| **PID** | Control PID | Gestor de librerías |
| **AccelStepper** | Control avanzado de motores paso a paso | Gestor de librerías |

### 10.5 Simuladores y herramientas

- **Tinkercad Circuits**: [https://www.tinkercad.com/circuits](https://www.tinkercad.com/circuits) — Simulador online gratuito de Arduino con capacidad de programar y simular circuitos en 3D. Ideal para pruebas antes de cablear.
- **Wokwi**: [https://wokwi.com/](https://wokwi.com/) — Simulador online de Arduino y ESP32 con soporte para múltiples placas, pantallas y sensores. Permite compartir proyectos.
- **Fritzing**: [https://fritzing.org/](https://fritzing.org/) — Software de diseño de circuitos con representación visual de breadboard, esquemático y PCB. Útil para documentar proyectos.
- **Arduino IDE 2.x**: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software) — IDE oficial con autocompletado, depuración serial mejorada y gestión de librerías integrada.
