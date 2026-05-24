# Índice de Documentación - SpeedRacer v.2

## Propósito
Este documento indexa y clasifica toda la documentación del proyecto SpeedRacer v.2 (2025) para facilitar su análisis contra la visión del nuevo proyecto STEAM Agent (2026).

---

## Directorio Raíz (`SpeedRacerv.2/`)

| Archivo | Tipo | Resumen | Relevancia |
|---------|------|---------|------------|
| `.gitattributes` | Config | Normalización de line endings LF | Baja |
| `Formulación del proyecto conducción autónoma mediante machine learning.pdf` | PDF | Documento de formulación inicial del proyecto | Media - Contexto histórico |
| `Formulación del proyecto conducción autónoma mediante machine learning.docx` | DOCX | Versión editable de la formulación | Media - Contexto histórico |

---

## Carpeta `Avances/`

### Archivos raíz de Avances

| Archivo | Tipo | Resumen | Relevancia |
|---------|------|---------|------------|
| `Actividades.docx` | DOCX | Documento de actividades del proyecto | Media |
| `ayuda_proximo_avance.md` | MD (493 líneas) | Código Python ROS2 para control por teclado, gamepad y joystick; ejemplos completos de publicación a `/cmd_vel` | **Alta** - Código de control ROS2 reutilizable |

---

## Carpeta `Avances/Avance 3/`

### Subcarpeta `aws/` - Configuración del DeepRacer

| Archivo | Tipo | Resumen | Relevancia |
|---------|------|---------|------------|
| `calibration.json` | JSON (20 líneas) | Calibración motor/servo: valores PWM para max/mid/min, polaridad | **Alta** - Parámetros de control PWM |
| `led_values.json` | JSON (8 líneas) | Valores PWM para LEDs RGB del vehículo | Media |
| `password.txt` | TXT | Hash/token para autenticación | **Alta** - Credencial de acceso |
| `sensor_configuration.json` | JSON (25 líneas) | Configuración LiDAR: ángulos, distancias, sectores | Media |
| `software_update_status.json` | JSON | Estado de actualización: `false` | Baja |
| `start_ros.sh` | SH (22 líneas) | Script de arranque ROS2 Foxy: sourcing de entornos y lanzamiento del launcher | **Alta** - Script de inicio ROS2 |
| `token.txt` | TXT (1 línea) | UUID: `***REMOVED***` | Media |

### Subcarpeta `foxy/` - Instalación ROS2 Foxy

| Archivo | Tipo | Resumen | Relevancia |
|---------|------|---------|------------|
| `setup.sh`, `setup.bash`, `setup.zsh` | SH | Scripts de setup del workspace ROS2 | Baja - Estándar ROS2 |
| `local_setup.sh`, `local_setup.bash`, `local_setup.zsh` | SH | Setup local sin source completo | Baja - Estándar ROS2 |
| `_local_setup_util.py` | PY (396 líneas) | Utilidad de configuración del entorno | Baja - Estándar ROS2 |

**Nota**: La carpeta `foxy/` contiene ~5,916 archivos que conforman una instalación estándar de ROS2 Foxy. No requieren extracción individual - son dependencias del sistema.

---

## Carpeta `Avances/Repositorio/`

| Archivo | Tipo | Resumen | Relevancia |
|---------|------|---------|------------|
| `README.md` | MD (67 líneas) | Descripción del proyecto en inglés, objetivos y alcance | **Alta** - Visión general del proyecto original |
| `README.pdf` | PDF | Versión PDF del README | Baja |

### Subcarpeta `1_Operating_System_Access_And_SSH/`

| Archivo | Tipo | Resumen | Relevancia |
|---------|------|---------|------------|
| `README.md` | MD (61 líneas) | Guía completa para acceso SSH al DeepRacer: credenciales `deepracer/Steambog1$`, habilitación de SSH, comandos de conexión | **Alta** - Credenciales SSH y guía de acceso |
| `README.pdf` | PDF | Versión PDF de la guía SSH | Baja |
| `media/` | IMG | 5 imágenes: car_connected.gif, login.jpg, enable_ssh.jpg, ssh_status.jpg, ssh_access.png | Ilustrativas |

---

## Avances 2, 4, 6, 7, 8, 9, 10, 11

| Archivo | Tipo | Resumen | Relevancia |
|---------|------|---------|------------|
| `Avance 2/Actividades.docx` | DOCX | Avance 2 del proyecto | Baja - No extraído |
| `Avance 4/Documentación sobre la API encontrada.docx` | DOCX | Documentación de API | Media |
| `Avance 6/Archivo de Python para mover el carro.docx` | DOCX | Código Python de movimiento | Media - Posible código útil |
| `Avance 7/Conectar desde API.docx` | DOCX | Conexión API | Media |
| `Avance 8/Manejo del vehículo por teclado.docx` | DOCX | Control por teclado | Media |
| `Avance 9/Avanve 9.docx` | DOCX | Avance 9 | Baja - No extraído |
| `Avance 10/Control por Gamepad.docx` | DOCX | Control por gamepad | Media |
| `Avance 11/Integración cámara.docx` | DOCX | Integración de cámara | Media |

---

## 📌 Recomendaciones para el nuevo proyecto

### Archivos/Fragmentos a extraer o copiar

1. **Credenciales SSH** (de `1_Operating_System_Access_And_SSH/README.md`):
   - Usuario: `deepracer`
   - Contraseña: `Steambog1$`
   - IP: obtener vía `ip addr` en el dispositivo

2. **Ejemplos de control ROS2** (de `ayuda_proximo_avance.md`):
   - Código para publicar a `/cmd_vel` con mensajes `Twist`
   - Control por teclado (pynput)
   - Control por joystick (pygame)
   - Control por voz (requests a API local)

3. **Script `start_ros.sh`** (de `Avance 3/aws/start_ros.sh`):
   - Ubicar en `scripts/` del nuevo proyecto
   - Modificar para integración con agente IA

4. **Configuración sensor LiDAR** (de `sensor_configuration.json`):
   - Parámetros de clipping, ángulos, distancias
   - Útiles para navegación y detección de obstáculos

5. **Calibración motor/servo** (de `calibration.json`):
   - Valores PWM para control preciso
   - `mid`, `max`, `min` con polaridad definida

### No reutilizar

- **`foxy/`**: Instalación estándar de ROS2 - no contiene código personalizado
- **Documentos .docx/.pdf**: Contenido del proyecto anterior obsoleto, no alineado con la nueva visión de robot recepcionista
- **`software_update_status.json`**: Estado `false` indica que no se completó la actualización

---

## Conclusión

La documentación del proyecto SpeedRacer v.2 contiene información técnica valiosa para el nuevo proyecto STEAM Agent, particularmente:

- Código de control ROS2 listo para adaptar
- Credenciales de acceso SSH al hardware
- Configuraciones de sensores y calibración
- Arquitectura del workspace ROS2 Foxy

El nuevo proyecto debe enfocarse en transformar esta base técnica en un agente de IA conversacional con navegación autónoma, priorizando el funcionamiento local sobre dependencias cloud.