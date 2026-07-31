#!/usr/bin/env python3
"""capture_photo.py - Captura una foto con la cámara del DeepRacer."""
import cv2

cam = cv2.VideoCapture(0)
if not cam.isOpened():
    print("FAIL: no se pudo abrir /dev/video0")
    exit(1)

ret, img = cam.read()
if ret:
    cv2.imwrite("/tmp/photo.jpg", img)
    print(f"OK: foto guardada ({img.shape[1]}x{img.shape[0]})")
else:
    print("FAIL: no se pudo capturar frame")

cam.release()
