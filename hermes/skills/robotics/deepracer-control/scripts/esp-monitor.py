#!/usr/bin/env python3
"""esp_monitor.py — Escucha el ESP32 y logea eventos JSON."""
import serial, time

PORT = "/dev/ttyUSB0"
BAUD = 115200

ser = serial.Serial(PORT, BAUD, timeout=1)
ser.dtr = False
time.sleep(0.1)
ser.rts = False
time.sleep(0.5)
ser.reset_input_buffer()

while True:
    line = ser.readline()
    if line:
        text = line.decode(errors="replace").strip()
        if text:
            print(f"[ESP] {text}", flush=True)
    time.sleep(0.01)
