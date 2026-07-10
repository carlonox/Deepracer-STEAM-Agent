#!/usr/bin/env python3
"""brake-led.py — Throttle-reactive LED control for DeepRacer.

Subscribes to /webserver_pkg/manual_drive (ServoCtrlMsg) and sets LED color
based on throttle value at 100Hz using fire-and-forget ROS2 service calls.

⚠️ The ROS2 CLI (`ros2 topic info /webserver_pkg/manual_drive`) may report
"Publisher count: 0" even though the topic IS being published to. This is a
ROS2 Foxy daemon bug where DDS discovery gets out of sync. Do NOT trust the
CLI — DDS subscriptions work regardless. Test with an actual rclpy subscriber
before claiming the topic is dead.

CONVENTION: Web API positive throttle = forward (check project's drive_test.py).

LED logic:
  throttle > 0.01  → FORWARD      → 🟢 GREEN
  throttle < -0.01 → REVERSE       → 🟠 ORANGE
  throttle = 0     → BRAKING flash → 🔴 RED (0.5s) → 🟣 PURPLE
  stopped          →                → 🟣 PURPLE

c2 (/servo_pkg/set_led_state) is optional — node works with just c1 (/ctrl_pkg/set_car_led).
spin_once(0.05) gives DDS enough time to deliver queued service requests.

Usage:
  # 1. Start drive daemon first
  nohup python3 /tmp/drive-daemon.py > /tmp/drive_daemon.log 2>&1 &
  # 2. Start brake LED node
  source /opt/ros/foxy/setup.bash
  source /opt/aws/deepracer/lib/setup.bash
  nohup python3 /tmp/brake-led.py > /tmp/brake_led.log 2>&1 &
"""

import rclpy
from rclpy.node import Node
from rclpy.executors import SingleThreadedExecutor
from deepracer_interfaces_pkg.msg import ServoCtrlMsg
from deepracer_interfaces_pkg.srv import SetLedCtrlSrv
import time
import signal
import sys

MAX_PWM = 9999825  # Full brightness (255 is very dim)


class BrakeLedNode(Node):
    def __init__(self):
        super().__init__("brake_led")
        # c1 is primary and required
        self.cli1 = self.create_client(SetLedCtrlSrv, "/ctrl_pkg/set_car_led")
        if self.cli1.wait_for_service(10):
            self.get_logger().info("c1 ready")
        else:
            self.get_logger().error("c1 NOT available")
        self.cli2 = self.create_client(SetLedCtrlSrv, "/servo_pkg/set_led_state")
        if self.cli2.wait_for_service(3):
            self.get_logger().info("c2 ready")

        self.req = SetLedCtrlSrv.Request()
        self.current_throttle = 0.0
        self.is_reversing = False
        self.was_moving_forward = False
        self.brake_until = 0.0

        # Subscribe to the drive command topic — DDS works even if CLI says 0 publishers
        self.sub = self.create_subscription(
            ServoCtrlMsg, "/webserver_pkg/manual_drive", self.drive_callback, 10
        )
        self.get_logger().info("BrakeLED started (topic subscription)")

    def drive_callback(self, msg):
        t = msg.throttle
        self.current_throttle = t
        if t > 0.01:
            self.is_reversing = False
            self.was_moving_forward = True
        elif t < -0.01:
            self.is_reversing = True
            self.was_moving_forward = False
        else:
            self.is_reversing = False
            if self.was_moving_forward and self.brake_until == 0:
                # Just stopped from forward — start 0.5s brake timer
                self.brake_until = time.time() + 0.5
                self.was_moving_forward = False

    def set_led(self):
        now = time.time()
        if now < self.brake_until:
            # 🔴 BRAKING (red for 0.5s)
            self.req.red, self.req.green, self.req.blue = MAX_PWM, 0, 0
        elif self.is_reversing:
            # 🟠 REVERSE
            self.req.red, self.req.green, self.req.blue = MAX_PWM, MAX_PWM // 2, 0
        elif self.current_throttle > 0.01:
            # 🟢 FORWARD
            self.req.red, self.req.green, self.req.blue = 0, MAX_PWM, 0
        else:
            # 🟣 IDLE / STOPPED
            self.req.red, self.req.green, self.req.blue = MAX_PWM, 0, MAX_PWM
            self.brake_until = 0  # reset timer

        # Fire & forget — no waiting for service responses
        for cli in (self.cli1, self.cli2):
            if cli and cli.service_is_ready():
                try:
                    cli.call_async(self.req)
                except Exception:
                    pass


def main():
    rclpy.init()
    node = BrakeLedNode()
    executor = SingleThreadedExecutor()
    executor.add_node(node)
    running = True

    def shutdown(sig, frame):
        nonlocal running
        running = False

    signal.signal(signal.SIGINT, shutdown)
    signal.signal(signal.SIGTERM, shutdown)

    try:
        while running and rclpy.ok():
            executor.spin_once(timeout_sec=0.05)  # 50ms for DDS delivery
            node.set_led()
            time.sleep(0.01)  # ~100Hz loop
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
