# Deepracer-STEAM-Agent

## Visión del nuevo proyecto (2026)

###  Objetivo General

Transformar el AWS DeepRacer en una **mascota robótica autónoma del aula STEAM** de la Universidad Nacional (sede Bogotá). El robot actuará como recepcionista y guía, capaz de:

- Saludar y conversar con los estudiantes mediante un agente de IA.
- Responder preguntas detalladas sobre cualquier dispositivo del aula (impresoras 3D, VR, escáneres, etc.) usando un sistema RAG.
- Guiar físicamente a los visitantes hasta la estación solicitada, navegando con marcadores visuales.
- (Futuro) Alertar con una alarma sonora cuando finalice el tiempo de asesoría (~2 horas).

###  Componentes principales

1.  **Agente de IA conversacional**: Cerebro del robot. Se ejecutará inicialmente en la nube a través de **OpenRouter** (modelos gratuitos como Gemini Flash o Llama 3 8B), eliminando la dependencia de un PC local encendido todo el día.
2.  **Sistema RAG (Generación Aumentada por Recuperación)**: Base de conocimiento local indexada con FAISS/Chroma que contiene manuales detallados de cada equipo del aula, información de los asesores humanos y normas del espacio. La recuperación de información se ejecuta en el propio DeepRacer.
3.  **Navegación visual autónoma**: Al carecer de LiDAR (modelo original), se usarán **marcadores ArUco** ubicados en las estaciones. La cámara monocular del vehículo detectará los marcadores para corregir la posición y permitir un guiado preciso.
4.  **Interacción por voz local**: Micrófono y parlante USB conectados directamente al DeepRacer. El reconocimiento de voz (STT) se hará con Vosk (modelo español ligero) y la síntesis de voz (TTS) con Piper TTS, ambos 100% offline.
5.  **Alarma de tiempo (futuro)**: Sistema de notificación sonora que se active automáticamente para avisar a los estudiantes cuando sus 2 horas de asesoría hayan concluido.

###  Estado actual del código heredado

Se heredó una interfaz web funcional para el DeepRacer, desarrollada por el equipo anterior, que incluye:

- Control manual por teclado, gamepad y mandos VR (Meta Quest 3).
- Visualización de la cámara en tiempo real mediante streaming MJPEG.
- Backend Node.js que se comunica con la API REST local del vehículo.

**Esta interfaz se conserva como base de comunicación con el hardware**, pero será extendida para recibir comandos del agente de IA y devolver respuestas de voz.

###  Diferencias con el proyecto original

| Proyecto anterior (2025)                | Nuevo proyecto (2026)                        |
| --------------------------------------- | -------------------------------------------- |
| Control remoto manual (teclado/VR)      | Control autónomo por voz                     |
| Dependencia de servicios en la nube AWS | Funcionamiento completamente local           |
| Sin capacidad de conversación           | Agente de IA con RAG y conocimiento del aula |
| Enfoque en conducción autónoma ML       | Enfoque en robótica social y asistencia      |
| Sin navegación en interiores            | Navegación visual con marcadores ArUco       |

###  Roadmap (próximos pasos)

1.  **Fase 1 – Conocimiento**: Generar los manuales Markdown de cada dispositivo del aula (¡ya en progreso!).
2.  **Fase 2 – Índice**: Analizar la documentación histórica (`docs/SpeedRacerv.2`) para extraer información técnica valiosa (credenciales, API, ejemplos de control ROS2).
3.  **Fase 3 – Cerebro**: Construir el agente de IA local con RAG y probar el flujo de voz (STT → FAISS → OpenRouter → TTS).
4.  **Fase 4 – Movimiento**: Integrar el agente con el backend Node.js para que el robot se mueva a la estación solicitada al recibir un comando de voz.
5.  **Fase 5 – Visión**: Implementar la detección de marcadores ArUco y la navegación por waypoints.
6.  **Fase 6 – Alarma**: Añadir el sistema de notificación por tiempo de asesoría.



Este proyecto es la evolución natural del trabajo iniciado en 2025. Si eres estudiante del aula STEAM y quieres ayudar:

- Revisa los `docs/` para entender el historial.
- Elige una fase del roadmap y abre un issue en GitHub.
- Asegúrate de que todo nuevo desarrollo sea local-first y no dependa de servicios externos.



_Documento creado el 23 de mayo de 2026 como punto de partida de la nueva iteración._
