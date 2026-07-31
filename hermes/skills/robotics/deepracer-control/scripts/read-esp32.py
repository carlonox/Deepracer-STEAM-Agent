#!/usr/bin/env python3
"""
read-esp32.py — Read serial data from an ESP32 on the DeepRacer.

Usage:
  python3 read-esp32.py                    # Read from /dev/ttyUSB1, 115200 baud
  python3 read-esp32.py /dev/ttyUSB1 9600  # Custom port and baud rate

Requires:
  - pyserial: pip3 install pyserial (or apt install python3-serial)
  - User in dialout group OR sudo access (password: ${DEEPRACER_SSH_PASSWORD})

⚠️  DTR/RTS must be disabled when opening the ESP32 serial port,
    otherwise the chip resets immediately (CP2102 bridges DTR to EN).
    This script handles this automatically.

The ESP32 typically sends data over USB-serial (CH340/CP210x).
This script reads lines and optionally publishes them to a ROS2 topic.
"""

import sys
import time
import argparse

SERIAL_PORT = "/dev/ttyUSB1"  # After 8266 removal, ESP32 is at ttyUSB1; check `ls /dev/ttyUSB*`
BAUD_RATE = 115200

def main():
    parser = argparse.ArgumentParser(description="Read ESP32 serial data on DeepRacer")
    parser.add_argument("port", nargs="?", default=SERIAL_PORT, help=f"Serial port (default: {SERIAL_PORT})")
    parser.add_argument("baud", nargs="?", type=int, default=BAUD_RATE, help=f"Baud rate (default: {BAUD_RATE})")
    parser.add_argument("--ros", action="store_true", help="Publish to ROS2 topic /esp32/data")
    parser.add_argument("--timeout", type=int, default=0, help="Exit after N seconds (0 = run forever)")
    args = parser.parse_args()

    # Try to import pyserial
    try:
        import serial
    except ImportError:
        print("ERROR: pyserial not installed. Run: pip3 install pyserial", file=sys.stderr)
        sys.exit(1)

    # Open serial port
    try:
        ser = serial.Serial(args.port, args.baud, timeout=1)
        ser.dtr = False  # CRITICAL: prevent ESP32 reset on open
        time.sleep(0.1)
        ser.rts = False
        time.sleep(0.5)
        ser.reset_input_buffer()
        print(f"Connected to {args.port} @ {args.baud} baud (DTR=0, RTS=0)", flush=True)
    except serial.SerialException as e:
        print(f"ERROR: Cannot open {args.port}: {e}", file=sys.stderr)
        print("HINT: Add user to dialout group or use sudo.", file=sys.stderr)
        sys.exit(1)

    # Optional ROS2 publisher
    pub = None
    if args.ros:
        try:
            import rclpy
            from rclpy.node import Node
            from std_msgs.msg import String

            rclpy.init()
            node = Node("esp32_bridge")
            pub = node.create_publisher(String, "/esp32/data", 10)
            print("Publishing to ROS2 topic: /esp32/data", flush=True)
        except ImportError:
            print("WARNING: ROS2 not available, printing only", flush=True)

    # Read loop
    start = time.time()
    try:
        while True:
            if args.timeout and (time.time() - start) > args.timeout:
                break

            line = ser.readline()
            if line:
                text = line.decode(errors="replace").strip()
                if text:
                    timestamp = time.strftime("%H:%M:%S")
                    print(f"[{timestamp}] {text}", flush=True)

                    if pub:
                        msg = String()
                        msg.data = text
                        pub.publish(msg)

    except KeyboardInterrupt:
        print("\nStopped by user", flush=True)
    finally:
        ser.close()
        if pub:
            node.destroy_node()
            rclpy.shutdown()


if __name__ == "__main__":
    main()
