# Habilidades de Hermes

Conocimiento operativo que Hermes carga para entender y controlar el proyecto.

| Ruta | Propósito |
|---|---|
| `robotics/deepracer-control/` | Índice router del DeepRacer (apunta a las 4 skills). |
| `robotics/deepracer-motor-control/` | Movimiento: backend, watchdog, daemon, explorer, LEDs. |
| `robotics/deepracer-calibration/` | Calibración medida 2026-07-31: dead zone, trim, speeds. |
| `robotics/deepracer-vision/` | Cámara, obstáculos, ArUco, LiDAR (sin hardware). |
| `robotics/deepracer-troubleshooting/` | SSH, firewall/Tailscale, dashboards, checklist, issues. |
| `aruco_detection.md` | Conocimiento sobre detección ArUco. |
| `connection_report.md` | Estado y diagnóstico de conectividad. |
| `drive_rules.md` | Reglas de movimiento seguro. |
| `hermes-v18-bugs.md` | Problemas conocidos de Hermes v0.18. |
| `ros2_topics.md` | Referencia de topics ROS2. |
| `tests/` | Tests de contrato de skills (p. ej. split de deepracer). |

Las habilidades son contenido mantenible. Cachés o skills instaladas
automáticamente deben distinguirse antes de versionarse.
