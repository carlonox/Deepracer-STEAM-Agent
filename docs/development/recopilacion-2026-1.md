# Recopilación del proyecto — 2026-1

## DeepRacer STEAM Agent

### 1. Propósito del proyecto

El proyecto busca transformar un vehículo AWS DeepRacer en una **mascota robótica y asistente para el aula STEAM de la Universidad Nacional de Colombia, sede Bogotá**. La visión integra movilidad, percepción del entorno e inteligencia artificial para que el robot pueda:

- responder preguntas sobre los equipos, herramientas y normas del aula;
- interactuar con estudiantes y visitantes mediante texto y, posteriormente, mediante voz;
- desplazarse de forma autónoma entre puntos de interés;
- guiar a una persona hasta una estación o equipo determinado;
- conservar mecanismos de control manual, supervisión y parada segura.

El sistema se concibe como una plataforma modular. El agente conversacional decide qué acción solicitar, mientras que los componentes de navegación, conexión y seguridad determinan cómo ejecutarla sin comprometer al vehículo ni a las personas.

## 2. Punto de partida

Al retomar el proyecto ya existía un sistema funcional para controlar el DeepRacer desde una aplicación web. Esta solución estaba dividida en dos componentes:

1. **Frontend:** interfaz web para visualizar la cámara y conducir el vehículo mediante teclado, control de Xbox o dispositivos de realidad virtual.
2. **Backend:** servicio intermediario entre la interfaz y la API local del DeepRacer. El backend inicia una sesión contra la interfaz web del vehículo, administra las cookies y el token CSRF, y expone una API propia para enviar órdenes de movimiento.

Esta base permitió desacoplar la interfaz de usuario de los detalles de autenticación del DeepRacer. Sin embargo, fue diseñada principalmente para conducción manual y requería mayor robustez, documentación e integración con los nuevos componentes de autonomía e inteligencia artificial.

### 2.1. Limitaciones identificadas en el sistema heredado

- Los errores de conexión o movimiento no siempre se comunican de manera clara. Si el vehículo no responde, resulta difícil diferenciar entre una sesión vencida, una falla de red, una batería de tracción apagada o descargada, y un servicio interno no disponible.
- La API del backend necesita una especificación estandarizada que describa endpoints, parámetros, respuestas, códigos de error y ejemplos de uso.
- La interfaz web no representa todavía todas las capacidades actuales del proyecto, como la navegación por marcadores, el sistema RAG o la interacción con Hermes.
- La lógica de seguridad, navegación y conexión aún presenta acoplamientos que dificultan las pruebas y el mantenimiento.

## 3. Evolución durante el semestre

Durante 2026-1 el proyecto evolucionó desde un sistema de teleoperación hacia una plataforma de asistencia robótica. El trabajo se concentró en dos líneas principales.

### 3.1. Navegación autónoma mediante visión por computador

Se desarrolló un prototipo de navegación interior basado en marcadores ArUco. Los marcadores representan puntos de interés del aula y permiten estimar la ubicación del vehículo mediante la cámara. El sistema puede:

- detectar e identificar marcadores ArUco;
- asociar cada identificador con un lugar del aula;
- calcular rutas entre lugares previamente definidos;
- recibir instrucciones de destino, por ejemplo, «ve a la impresora»;
- acercarse al marcador conservando una distancia objetivo;
- detener el vehículo manualmente o ante una condición de seguridad.

La implementación actual se concentra en `apps/navigation/src/controlcamara.py`. El controlador se comunica primero mediante un canal TCP local y utiliza la API HTTP del backend como mecanismo alternativo.

También se creó una capa `SafetyGate`, separada de la lógica de navegación, que permite:

- activar un freno manual;
- bloquear el avance cuando se detecte un obstáculo frontal;
- permitir la marcha atrás para liberar el vehículo;
- esperar un intervalo breve antes de reanudar el movimiento.

La interfaz para recibir una distancia frontal desde la ESP32 ya está prevista en el código, aunque la detección de distancia todavía requiere sensores adecuados y su integración física.

### 3.2. Agente conversacional y sistema de conocimiento

La segunda línea busca convertir el vehículo en un asistente del aula. Para ello se configuró Hermes como agente y se construyó una base documental con manuales de los equipos disponibles. Mediante un sistema de generación aumentada por recuperación —RAG, por sus siglas en inglés— el agente puede localizar información relevante antes de responder.

Los avances de esta línea incluyen:

- una colección de manuales en Markdown sobre equipos del aula;
- herramientas de indexación y consulta del conocimiento;
- configuración de Hermes, su personalidad, memorias y habilidades;
- scripts experimentales para consultar el DeepRacer y ejecutar acciones;
- servicios independientes de conversión de voz a texto y de texto a voz.

La integración aún no está completa. En particular, algunas herramientas de Hermes controlan el vehículo mediante conexiones alternativas, en vez de usar exclusivamente la API del backend. Esto duplica responsabilidades y dificulta aplicar una política de seguridad común.

### 3.3. Exploración de hardware y ESP32

Se identificó y configuró una ESP32 como plataforma de expansión. El dispositivo fue cargado con MicroPython y se probó su comunicación serial con el DeepRacer. También se integró de forma experimental un sensor de sonido KY-037.

Por tanto, la ESP32 ya no debe considerarse un componente completamente pendiente. Su estado actual es:

- comunicación serial básica operativa;
- firmware MicroPython probado;
- detección experimental de eventos de sonido;
- integración con sensores de distancia aún pendiente;
- comunicación inalámbrica y operación como subsistema de seguridad aún en exploración.

El DeepRacer dispone del software asociado a LiDAR, pero no cuenta actualmente con el sensor LiDAR físico. La prevención de colisiones no debe darse por resuelta hasta seleccionar, instalar, calibrar y validar sensores de distancia.

## 4. Estado actual del sistema

El repositorio contiene los siguientes subsistemas:

| Subsistema | Estado | Función principal |
| --- | --- | --- |
| Backend de control | Funcional, requiere fortalecimiento | Autenticación y comunicación con la API del DeepRacer |
| Interfaz web | Funcional para control manual | Cámara y conducción por teclado, gamepad o VR |
| Navegación ArUco | Prototipo funcional | Detección de lugares y ejecución de rutas predefinidas |
| Capa de seguridad | Parcial | Freno manual y preparación para sensores frontales |
| Hermes | Configurado, integración parcial | Razonamiento, conversación y uso de herramientas |
| Sistema RAG | En desarrollo | Consulta de manuales y conocimiento del aula |
| Voz | Prototipos separados | Conversión de voz a texto y de texto a voz |
| ESP32 | Prototipo funcional | Expansión de sensores y comunicación serial |
| Prevención física de colisiones | Pendiente | Detección confiable de obstáculos y frenado independiente |

## 5. Arquitectura propuesta

Para reducir el acoplamiento y facilitar el trabajo de futuros equipos, se propone reorganizar el proyecto por responsabilidades.

### 5.1. Agente

Debe contener la configuración de Hermes, el sistema RAG y las herramientas que permiten conversar o solicitar acciones. El agente no debería enviar órdenes de bajo nivel directamente al vehículo. En su lugar, debe invocar operaciones explícitas, como:

- consultar información del aula;
- solicitar un desplazamiento a un destino;
- consultar el estado del robot;
- detener una tarea en curso.

### 5.2. Navegación autónoma

Debe encargarse de transformar un destino en una trayectoria segura. Este módulo incluiría:

- detección de marcadores ArUco;
- localización aproximada;
- grafo de lugares y cálculo de rutas;
- control de aproximación a cada marcador;
- gestión de pérdida de referencia visual;
- estados de navegación: inactivo, localizando, en movimiento, bloqueado, detenido y destino alcanzado.

El módulo debe poder funcionar y probarse sin depender de Hermes.

### 5.3. Conexión y control del vehículo

El backend debe ser la única puerta de entrada al hardware del DeepRacer. Su responsabilidad es:

- administrar la sesión con la API local del vehículo;
- validar y limitar los comandos recibidos;
- exponer el estado de conexión, batería y servicios;
- centralizar registros y mensajes de error;
- aplicar tiempos de espera y reautenticación;
- ofrecer una API documentada y estable para los demás módulos.

La ESP32 y sus sensores también deberían integrarse mediante esta capa o mediante un servicio de hardware claramente definido.

### 5.4. Interfaz de usuario

La interfaz web debe reunir las capacidades del sistema sin duplicar su lógica. Además del control manual existente, podría incluir:

- chat con Hermes;
- estado de conexión y baterías;
- video en tiempo real;
- selección de destino;
- progreso de la navegación;
- alertas de obstáculos y fallos;
- botón de parada de emergencia siempre visible;
- historial de acciones y diagnósticos.

### 5.5. Seguridad

La seguridad debe ser una responsabilidad transversal, pero independiente del agente. Ninguna decisión de un modelo de lenguaje debería omitir las restricciones de movimiento. Se recomienda una cadena de autorización como la siguiente:

**Agente o usuario → solicitud de alto nivel → navegación → validación de seguridad → backend → DeepRacer**

La parada de emergencia y el bloqueo por proximidad deben tener prioridad sobre cualquier orden de movimiento.

## 6. Retos prioritarios

### 6.1. Robustez y observabilidad

- Definir estados y errores homogéneos para todos los servicios.
- Implementar verificaciones de conectividad, sesión, batería y disponibilidad del vehículo.
- Registrar las acciones con fecha, origen de la orden y resultado.
- Incorporar mecanismos de recuperación ante pérdida de red o vencimiento de sesión.
- Garantizar una detención segura cuando un componente falle.

### 6.2. Documentación de la API

- Adoptar OpenAPI como especificación del backend.
- Documentar entradas, salidas, errores y ejemplos.
- Diferenciar errores del cliente, del backend, de red y del vehículo.
- Generar documentación legible tanto para desarrolladores como para herramientas automáticas y agentes.

### 6.3. Organización del repositorio

- Separar código estable, prototipos, documentación histórica y evidencia de pruebas.
- Consolidar documentos duplicados o contradictorios.
- Mantener las credenciales fuera del repositorio y utilizar variables de entorno.
- Definir un documento principal de instalación y otro de arquitectura.
- Agregar pruebas automatizadas para las interfaces entre módulos.

### 6.4. Navegación confiable

- Mejorar la calidad y estabilidad de la imagen.
- Calibrar la cámara y validar la estimación de distancia.
- Definir una ubicación física consistente para los marcadores.
- Manejar marcadores no visibles, rutas bloqueadas y cambios de iluminación.
- Comparar la navegación visual con alternativas basadas en recorridos predefinidos o fusión de sensores.

### 6.5. Integración segura del agente

- Crear habilidades de Hermes con contratos claros y parámetros limitados.
- Evitar accesos directos por SSH para operaciones que ya ofrece el backend.
- Restringir velocidad, duración, destinos y frecuencia de las órdenes.
- Exigir confirmación para acciones de mayor riesgo.
- Limitar las respuestas del RAG a fuentes disponibles y mostrar la procedencia de la información.

### 6.6. Interacción por voz

- Seleccionar y conectar un micrófono apto para el ruido del aula.
- Integrar los servicios de reconocimiento y síntesis de voz con Hermes.
- Definir un mecanismo de activación que evite escuchas o comandos accidentales.
- Evaluar latencia, precisión en español y funcionamiento sin conexión.
- Instalar un sistema de salida de audio adecuado; la ESP32 puede controlarlo, pero no necesariamente debe ejecutar la síntesis.

## 7. Hoja de ruta propuesta

### Fase 1. Estabilización

- Reorganizar el repositorio por responsabilidades.
- Eliminar credenciales y consolidar la documentación.
- Estandarizar errores, estados y registros.
- Completar la especificación OpenAPI del backend.

**Resultado esperado:** una base reproducible, documentada y fácil de diagnosticar.

### Fase 2. Integración de servicios

- Hacer que navegación, interfaz y Hermes usen exclusivamente el backend.
- Definir contratos de alto nivel para consultar estado, detener y solicitar destinos.
- Integrar el estado de la ESP32 sin acoplarlo al agente.

**Resultado esperado:** un solo canal de control con reglas consistentes.

### Fase 3. Seguridad física

- Seleccionar sensores de distancia.
- Integrarlos con la ESP32 y la capa `SafetyGate`.
- Implementar frenado independiente de la navegación.
- Probar obstáculos estáticos, objetos inesperados y pérdida de comunicación.

**Resultado esperado:** el vehículo no avanza cuando una condición insegura está presente.

### Fase 4. Navegación autónoma

- Calibrar la cámara y los marcadores.
- Definir el mapa de puntos de interés del aula.
- Validar rutas repetibles en diferentes condiciones.
- Incorporar recuperación ante pérdida de marcador o ruta bloqueada.

**Resultado esperado:** desplazamientos supervisados y repetibles entre estaciones.

### Fase 5. Asistente conversacional

- Consolidar el RAG y evaluar sus respuestas.
- Crear las habilidades de Hermes para consultar estado y solicitar navegación.
- Integrar el chat en la interfaz web.
- Añadir referencias a las fuentes utilizadas en cada respuesta.

**Resultado esperado:** un asistente que responde sobre el aula y solicita acciones sin acceder directamente al hardware.

### Fase 6. Interacción por voz y experiencia de usuario

- Integrar micrófono, reconocimiento de voz, síntesis y altavoz.
- Incorporar señales visuales o sonoras sobre el estado del robot.
- Realizar pruebas con usuarios en el aula.

**Resultado esperado:** interacción multimodal clara, comprensible y segura.

## 8. Criterios de éxito

Para evaluar el avance de manera objetiva se proponen los siguientes indicadores:

- porcentaje de intentos de conexión exitosos;
- tiempo medio de recuperación después de perder la sesión;
- porcentaje de rutas completadas sin intervención;
- número de frenados correctos ante obstáculos y número de falsos positivos;
- precisión de llegada y tiempo de recorrido por ruta;
- latencia desde una solicitud hasta el inicio de la acción;
- porcentaje de respuestas del agente respaldadas por una fuente del RAG;
- tasa de reconocimiento correcto de comandos de voz;
- número de incidentes que requieren una parada manual.

Antes de operar con público, deben definirse umbrales mínimos para los indicadores de seguridad y navegación.

## 9. Riesgos y consideraciones

- **Seguridad física:** el DeepRacer puede moverse con suficiente fuerza para golpear personas u objetos. Las pruebas deben realizarse en un área despejada, con supervisión y un mecanismo de parada accesible.
- **Dependencia de red:** una conexión inestable puede interrumpir comandos. El comportamiento predeterminado ante pérdida de comunicación debe ser detenerse.
- **Alucinaciones del agente:** el modelo puede producir respuestas incorrectas. El RAG debe aportar fuentes y el sistema debe reconocer cuándo no dispone de información.
- **Privacidad:** la interacción por voz y cámara debe respetar las políticas institucionales y evitar almacenar datos personales sin autorización.
- **Mantenibilidad:** los prototipos y scripts experimentales pueden acelerar la exploración, pero deben migrarse a módulos probados antes de considerarse parte del sistema estable.
- **Consistencia arquitectónica:** ningún componente debe crear un canal alternativo de movimiento que evite la API y las reglas de seguridad.

## 10. Conclusión

Durante 2026-1 el proyecto avanzó desde el control remoto del AWS DeepRacer hacia una plataforma de robótica social con navegación visual, consulta de conocimiento e integración experimental de sensores. Ya existen componentes valiosos: una interfaz de teleoperación, un backend de control, navegación por ArUco, una capa inicial de seguridad, una base RAG, Hermes y prototipos de voz y ESP32.

El principal reto para la siguiente etapa no es añadir más funciones aisladas, sino **integrar y estabilizar lo construido**. La prioridad debe ser consolidar una arquitectura modular, establecer un único canal de control, incorporar seguridad física independiente del agente y definir pruebas medibles. Sobre esa base será posible construir un asistente del aula que resulte útil, mantenible y seguro.
