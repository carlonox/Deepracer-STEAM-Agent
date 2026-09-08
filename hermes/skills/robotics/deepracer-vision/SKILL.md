---
name: deepracer-vision
description: "See with an AWS DeepRacer: MJPEG camera streams, obstacle detection thresholds, ArUco navigation notes, LiDAR status (no hardware). Movement is in deepracer-motor-control."
version: 1.0.0
author: Hermes Agent
platforms: [linux, macos, windows]
metadata:
  hermes:
    tags: [deepracer, robotics, vision, camera, aruco]
---

# DeepRacer Vision

Perception side of `deepracer-control` (split 2026-09-08, Fase 6).
Verbatim move. The camera is this robot's ONLY perception sensor (no IMU —
not soldered on this revision; no LiDAR hardware). Movement procedures are
in `deepracer-motor-control`; calibrations in `deepracer-calibration`.

## Camera / Video

The DeepRacer camera does **not** publish a ROS2 topic. Instead, `web_video_server` (a ROS2 node) captures frames from the camera and serves them as an HTTP MJPEG stream on port 8080. This avoids saturating the ROS2 bus with video data during ML inference.

Two stream sources:

| Option | URL | Resolution | Notes |
|--------|-----|------------|-------|
| Backend proxy | `http://localhost:5002/api/video_stream` | 480×360 | Works without extra ports |
| Direct ROS stream | `http://<IP>:8080/stream_viewer?topic=/camera_pkg/display_mjpeg` | 480×360 | Uses `web_video_server` |
| Direct ROS snapshot | `http://<IP>:8080/snapshot?topic=/camera_pkg/display_mjpeg` | Still frame | Single JPEG capture |

The ROS `web_video_server` on port 8080 serves a topic list page at `http://<IP>:8080/` with links to all available streams, including the sensor fusion LiDAR overlay.

**Available ROS image topics on port 8080:**
- `/camera_pkg/display_mjpeg` — Camera MJPEG stream
- `/sensor_fusion_pkg/overlay_msg` — Camera + LiDAR overlay (shows LiDAR data overlaid on camera feed)

The ROS `web_video_server` on port 8080 serves a topic list page at `http://<IP>:8080/` with links to all available streams:

- `/camera_pkg/display_mjpeg` — Raw camera stream
- `/sensor_fusion_pkg/overlay_msg` — Camera + LiDAR overlay (if LiDAR connected)

Single photo capture via SSH on the robot:
```bash
ffmpeg -f v4l2 -i /dev/video1 -frames:v 1 /tmp/photo.jpg -y
```

### Camera Obstacle Detection (Single ROI with Gray Floor Fix)

The `analyze_view(img)` function splits the 160x120 camera into three vertical zones and checks each independently via OpenCV (4.13.0):

```python
obs = (m < 60) or (m < 110 and s < 15) or ed > 0.35
```
Where:
1. **Very dark** (`m < 60`) — close dark obstacle (wall, furniture leg)
2. **Uniform medium-bright** (`m < 110 and std < 15`) — catches light-colored objects (blue suitcase, box) that aren't dark but uniformly cover the center zone
3. **High edge density** (`ed > 0.35`) — Canny edges > 35% of ROI = textured obstacle

**Blue detection** uses HSV with **saturation > 50** to avoid the gray floor trap:
```python
cv2.inRange(hsv, [80, 50, 30], [145, 255, 255])
```
Gray floors have saturation ~0 but arbitrary hue. A range with `S >= 20` (as in v3) falsely detects gray at 29% blue coverage. Requiring `S >= 50` eliminates this entirely.

**Gray floor (HSV saturation) fix — the session's biggest camera breakthrough:**

The original HSV blue range `[80,20,20]-[145,255,255]` with S>=20 caught gray floors at 29% coverage because gray pixels have arbitrary hue in OpenCV's HSV space but low saturation. The floor triggered `bp > 0.15` constantly, making the robot believe there was an obstacle in every direction.

**Fix:** Require saturation > 50:
```python
cv2.inRange(hsv, np.array([80, 50, 30]), np.array([145, 255, 255]))
```
With this range, gray floors measure `blue=0-2%` instead of `blue=29%`. Only genuine blue objects (the actual blue suitcase) exceed 15% coverage.

**Typical floor values (gray tile/carpet):** blue=0-2%, bright=130-160, std=10-20, edges=4-8%. None trigger the obstacle conditions.

**⚠️ Critical: always test what the camera actually sees before trusting thresholds.** Run this on the robot:
```python
import urllib.request, cv2, numpy as np
r = urllib.request.urlopen("http://localhost:8080/snapshot?topic=/camera_pkg/display_mjpeg", timeout=3)
img = cv2.imdecode(np.frombuffer(r.read(), np.uint8), cv2.IMREAD_COLOR)
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
h,w = img.shape[:2]
blue = cv2.inRange(hsv, np.array([80,50,30]), np.array([145,255,255]))
bp = np.count_nonzero(blue) / (h*w)
roi = gray[h//3:2*h//3, w//3:2*w//3]
m = np.mean(roi); s = np.std(roi)
edges = cv2.Canny(roi, 50, 150)
ed = np.count_nonzero(edges) / (roi.shape[0] * roi.shape[1])
print(f"blue={bp:.0%} bright={m:.0f} std={s:.0f} edges={ed:.0%}")
```

### Camera Stream Verification

To verify the camera is working from the Docker container:

```bash
# Check the ROS web_video_server topic list is reachable
curl -s -o /dev/null -w '%{http_code}' http://<ROBOT_IP>:8080/
# Expected: 200

# Capture a single JPEG frame
curl -s -o /tmp/snapshot.jpg http://<ROBOT_IP>:8080/snapshot?topic=/camera_pkg/display_mjpeg
python3 -c "import struct; f=open('/tmp/snapshot.jpg','rb'); h=f.read(4); print('JPEG OK' if h[:2]==b'\\xff\\xd8' else 'NOT JPEG')"
```

Port 8080 (ROS web_video_server) is typically reachable from the Docker container even when port 5001 (web API) is not. The snapshot endpoint returns 160×120 JPEG frames by default. The MJPEG stream is at `http://<IP>:8080/stream_viewer?topic=/camera_pkg/display_mjpeg`.

Two topics available on port 8080:
- `/camera_pkg/display_mjpeg` — Raw camera MJPEG stream
- `/sensor_fusion_pkg/overlay_msg` — Camera + LiDAR overlay (if LiDAR connected)

## ArUco Navigation

Classroom navigation uses printed ArUco markers (`DICT_6X6_250`) and the
monocular camera — no LiDAR, no ESP32. IDs, place names and routes live in
`apps/navigation/src/controlcamara.py` (`ARUCO_PLACES`, `ARUCO_ROUTES`,
`MARKER_SIZE` = printed side in meters). The step-by-step activity (print,
measure, name, define routes, test detection without moving, controlled
movement, validation) is `docs/plans/actividad-aruco.md`.

## LiDAR Status (RPLIDAR) — no hardware on this robot

The DeepRacer ships with **software support for RPLIDAR** (models A1/A2/A3/S1) but the actual **hardware module may or may not be physically connected**.

### Software (installed)
| Component | Location |
|-----------|----------|
| ROS2 package | `/opt/aws/deepracer/lib/rplidar_ros/` |
| Node binary | `rplidarNode` (C++, x86-64) |
| Launch files | 10 variants (generic, A3, S1, S1-TCP, test, view) |
| Launch integration | Included in `deepracer_launcher.py` (line 98-102) |
| ROS2 service | `lidar_config_srv` in `deepracer_interfaces_pkg` |
| Sensor fusion | `sensor_fusion_node` running at ~4.4% CPU |
| Sample model | `/opt/aws/deepracer/artifacts/Sample_lidar_stereo_cam/model.pb` (24MB) |

### Problem: rplidarNode fails at runtime
The `rplidarNode` binary is **included in the main launch file** but fails to start because the ROS2 shared libraries are not in `LD_LIBRARY_PATH` when it runs:

```
libsensor_msgs__rosidl_typesupport_cpp.so → not found
librclcpp.so → not found
```

This is a launch environment issue — the `deepracer_launcher.py` presumably sources the ROS2 setup.bash but the binary's runtime linker can't find the `.so` files. Fixing this requires checking the `LD_LIBRARY_PATH` in the launch environment and potentially adding explicit library paths.

### Hardware (not detected in this robot)
No physical LiDAR was detected:
- No `/dev/ttyUSB*` or `/dev/ttyACM*` serial devices
- No RPLIDAR in USB device tree (only camera + mouse)
- Conclusion: the robot in this project does **not** have a physical RPLIDAR module

### To add a LiDAR later
1. Connect an RPLIDAR (A1/A2/A3/S1) to a USB port on the robot
2. Confirm it appears as a serial device: `ls /dev/ttyUSB*`
3. Fix the ROS2 library path issue in the launch environment
4. Launch the appropriate node: `rplidarNode` or use a model-specific launch file from `/opt/aws/deepracer/lib/rplidar_ros/share/rplidar_ros/launch/`
5. View LiDAR data: `http://<IP>:8080/stream_viewer?topic=/sensor_fusion_pkg/overlay_msg`
