#!/bin/bash
# led-rainbow.sh — Rainbow animation for DeepRacer rear LED strip
#
# Usage:  bash led-rainbow.sh [duration_seconds=30]
#
# Beats the web server's 1 Hz LED override loop by sending commands
# at ~100 Hz. Requires ROS2 env sourcing (handled inside).
# Run from SSH on the robot.

set -e

DURATION="${1:-30}"

cat > /tmp/led_rainbow.py << 'PYEOF'
import rclpy, math, time, sys
from rclpy.node import Node
from deepracer_interfaces_pkg.srv import SetLedCtrlSrv

duration = int(sys.argv[1]) if len(sys.argv) > 1 else 30
max_val = int(sys.argv[2]) if len(sys.argv) > 2 else 9999825  # full brightness

rclpy.init()
node = Node("rainbow")
c1 = node.create_client(SetLedCtrlSrv, "/ctrl_pkg/set_car_led")
c2 = node.create_client(SetLedCtrlSrv, "/servo_pkg/set_led_state")
c1.wait_for_service(3)
c2.wait_for_service(3)

req = SetLedCtrlSrv.Request()
t = 0.0
start = time.time()

print(f"RAINBOW {duration}s (max={max_val})")
while time.time() - start < duration:
    req.red   = int(max_val * (math.sin(t)      * 0.5 + 0.5))
    req.green = int(max_val * (math.sin(t + 2.094) * 0.5 + 0.5))
    req.blue  = int(max_val * (math.sin(t + 4.189) * 0.5 + 0.5))
    c1.call_async(req)
    c2.call_async(req)
    t += 0.15
    time.sleep(0.01)

# Fade back to green
req.red, req.green, req.blue = 0, max_val, 0
for _ in range(100):
    c1.call_async(req); c2.call_async(req)
    time.sleep(0.01)
print("GREEN")

node.destroy_node()
rclpy.shutdown()
PYEOF

source /opt/ros/foxy/setup.bash
source /opt/aws/deepracer/lib/setup.bash
python3 /tmp/led_rainbow.py "$DURATION" 9999825
