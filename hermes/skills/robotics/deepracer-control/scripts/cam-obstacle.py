#!/usr/bin/env python3
"""cam_obstacle.py — Detecta obstáculos con la cámara frontal via OpenCV."""
import cv2, numpy as np, urllib.request, json, sys, time

CAM_URL = "http://localhost:8080/snapshot?topic=/camera_pkg/display_mjpeg"

def check_obstacle():
    """Toma foto y analiza si hay obstáculo al frente.
    Returns: (bool, str, float) - (obstacle, description, confidence)"""
    try:
        resp = urllib.request.urlopen(CAM_URL, timeout=3)
        img_data = resp.read()
        img = cv2.imdecode(np.frombuffer(img_data, np.uint8), cv2.IMREAD_COLOR)
        if img is None:
            return False, "No se pudo capturar imagen", 0.0
        
        h, w = img.shape[:2]
        cx, cy = w // 2, h // 2
        roi_size = min(w, h) // 3
        x1, x2 = cx - roi_size // 2, cx + roi_size // 2
        y1, y2 = cy - roi_size // 2, cy + roi_size // 2
        roi = img[y1:y2, x1:x2]
        
        gray = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)
        mean_val = np.mean(gray)
        std_val = np.std(gray)
        
        is_dark = mean_val < 80
        is_uniform = std_val < 20
        
        if is_dark and is_uniform:
            return True, "Obstáculo muy cerca (oscuro y uniforme)", 0.9
        elif is_dark:
            return True, "Posible obstáculo (oscuro)", 0.6
        elif mean_val < 100:
            return True, "Algo al frente (sombra)", 0.4
        else:
            return False, f"Despejado (brillo={mean_val:.0f})", 0.8
    except Exception as e:
        return False, f"Error: {e}", 0.0

if __name__ == "__main__":
    obstacle, desc, conf = check_obstacle()
    result = {"obstacle": obstacle, "desc": desc, "confidence": round(conf, 2)}
    print(json.dumps(result))
