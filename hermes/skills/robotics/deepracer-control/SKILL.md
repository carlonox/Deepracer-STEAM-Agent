---
name: deepracer-control
description: "AWS DeepRacer control — router skill. Movement: deepracer-motor-control. Calibration: deepracer-calibration. Vision: deepracer-vision. Diagnostics: deepracer-troubleshooting."
version: 3.0.0
author: Hermes Agent
platforms: [linux, macos, windows]
metadata:
  hermes:
    tags: [deepracer, robotics, hardware-control]
---

# AWS DeepRacer Control (router)

Split 2026-09-08 (Fase 6): this skill is now an index. Load the focused
skill for the task — each holds its section verbatim from v2.35.0:

| Task | Skill |
|---|---|
| Drive, watchdog, daemon, explorer, safety, LEDs, backend proxy | `deepracer-motor-control` |
| Dead zone, steering trim, speeds, direction test | `deepracer-calibration` |
| Camera, obstacle thresholds, ArUco, LiDAR status | `deepracer-vision` |
| SSH, firewall/Tailscale, dashboards, ROS2 topics, reboot checklist, issues, ESP32 archive | `deepracer-troubleshooting` |

Shared files (unchanged, still here): `references/`, `scripts/`, `templates/`.

**Safety rule (all skills):** ALL driving goes through the Node backend
(`apps/backend`, port 5002) — NEVER SSH for movement. Physical tests need
explicit authorization, operator present, clear zone, limited speed.
