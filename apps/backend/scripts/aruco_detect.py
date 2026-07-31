#!/usr/bin/env python3
"""
ArUco marker detection for AWS DeepRacer
Captures frame from web_video_server (port 8080) and detects ArUco markers.
Calculates estimated distance using marker size and focal length.

Usage:
    python3 aruco_detect.py [--calibrate] [--marker-size CM] [--focal-length PX]

Requirements:
    - opencv-contrib-python (for cv2.aruco)
    - numpy
    - ffmpeg (for frame capture)

Author: OWL
Date: 2026-01-17
"""

import cv2
import numpy as np
import subprocess
import sys
import os
import json
import argparse

# === CONFIGURATION ===
STREAM_URL = "http://localhost:8080/stream?topic=/camera_pkg/display_mjpeg"
FRAME_PATH = "/tmp/aruco_frame.jpg"
MARKER_SIZE_CM = 10.0  # Default marker size in cm

# Camera calibration values (update after calibration)
# These are estimated defaults for the DeepRacer camera
# Run with --calibrate to get accurate values
FOCAL_LENGTH_PX = None  # Will be calculated during calibration
IMAGE_WIDTH = 640
IMAGE_HEIGHT = 480


def capture_frame(stream_url=STREAM_URL, output_path=FRAME_PATH):
    """Capture a single frame from the MJPEG stream using ffmpeg."""
    cmd = [
        "ffmpeg", "-i", stream_url,
        "-frames:v", "1",
        "-y", output_path
    ]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=10)
    if result.returncode != 0:
        print(f"Error capturing frame: {result.stderr[-200:]}")
        return False
    if not os.path.exists(output_path):
        print("Frame not saved")
        return False
    return True


def calibrate_focal_length(marker_size_cm, known_distance_cm, marker_size_pixels):
    """
    Calculate focal length using a marker at known distance.
    
    Formula: focal_length = (marker_size_px * known_distance_cm) / marker_size_cm
    
    Args:
        marker_size_cm: Real marker size in cm
        known_distance_cm: Known distance to marker in cm
        marker_size_pixels: Marker size in pixels in the image
    
    Returns:
        Focal length in pixels
    """
    focal_length = (marker_size_pixels * known_distance_cm) / marker_size_cm
    return focal_length


def estimate_distance(marker_size_cm, focal_length_px, marker_size_pixels):
    """
    Estimate distance to marker.
    
    Formula: distance = (marker_size_cm * focal_length_px) / marker_size_pixels
    
    Args:
        marker_size_cm: Real marker size in cm
        focal_length_px: Focal length in pixels
        marker_size_pixels: Marker size in pixels in the image
    
    Returns:
        Estimated distance in cm
    """
    if marker_size_pixels <= 0:
        return float('inf')
    distance = (marker_size_cm * focal_length_px) / marker_size_pixels
    return distance


def get_marker_size_pixels(corners):
    """
    Calculate the average side length of a marker in pixels from its corners.
    
    Args:
        corners: numpy array of shape (1, 4, 2) with corner coordinates
    
    Returns:
        Average side length in pixels
    """
    pts = corners[0]  # shape (4, 2)
    # Calculate distances between consecutive corners
    side_lengths = []
    for i in range(4):
        p1 = pts[i]
        p2 = pts[(i + 1) % 4]
        length = np.linalg.norm(p2 - p1)
        side_lengths.append(length)
    return np.mean(side_lengths)


def detect_aruco(frame_path, marker_size_cm=MARKER_SIZE_CM, focal_length_px=FOCAL_LENGTH_PX):
    """
    Detect ArUco markers in an image and estimate distances.
    
    Args:
        frame_path: Path to the image file
        marker_size_cm: Real marker size in cm
        focal_length_px: Focal length in pixels (None if not calibrated)
    
    Returns:
        dict with detection results
    """
    # Read image
    frame = cv2.imread(frame_path)
    if frame is None:
        return {"error": f"Could not read image: {frame_path}"}
    
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    # Set up ArUco detector (OpenCV 4.13+ API)
    dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
    parameters = cv2.aruco.DetectorParameters()
    detector = cv2.aruco.ArucoDetector(dictionary, parameters)
    
    # Detect markers
    corners, ids, rejected = detector.detectMarkers(gray)
    
    results = {
        "markers_found": 0,
        "markers": [],
        "image_size": {"width": frame.shape[1], "height": frame.shape[0]},
        "focal_length_px": focal_length_px,
        "marker_size_cm": marker_size_cm
    }
    
    if ids is None or len(ids) == 0:
        results["status"] = "sin marcadores visibles"
        return results
    
    results["markers_found"] = len(ids)
    results["status"] = "marcadores detectados"
    
    for i in range(len(ids)):
        marker_id = int(ids[i][0])
        marker_corners = corners[i]
        avg_side_px = get_marker_size_pixels(marker_corners)
        
        marker_info = {
            "id": marker_id,
            "avg_side_px": round(avg_side_px, 2),
            "corners": marker_corners[0].tolist()
        }
        
        # Calculate distance if focal length is known
        if focal_length_px is not None:
            distance = estimate_distance(marker_size_cm, focal_length_px, avg_side_px)
            marker_info["distance_cm"] = round(distance, 2)
        else:
            marker_info["distance_cm"] = None
            marker_info["note"] = "Focal length not calibrated. Run with --calibrate"
        
        results["markers"].append(marker_info)
    
    return results


def calibrate_from_frame(frame_path, marker_size_cm, known_distance_cm):
    """
    Calibrate focal length using a detected marker at known distance.
    
    Args:
        frame_path: Path to image with marker
        marker_size_cm: Real marker size in cm
        known_distance_cm: Known distance to marker in cm
    
    Returns:
        dict with calibration results
    """
    frame = cv2.imread(frame_path)
    if frame is None:
        return {"error": f"Could not read image: {frame_path}"}
    
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
    parameters = cv2.aruco.DetectorParameters()
    detector = cv2.aruco.ArucoDetector(dictionary, parameters)
    
    corners, ids, rejected = detector.detectMarkers(gray)
    
    if ids is None or len(ids) == 0:
        return {"error": "No markers found for calibration"}
    
    # Use first detected marker
    avg_side_px = get_marker_size_pixels(corners[0])
    focal_length = calibrate_focal_length(marker_size_cm, known_distance_cm, avg_side_px)
    
    return {
        "focal_length_px": round(focal_length, 2),
        "marker_id": int(ids[0][0]),
        "marker_side_px": round(avg_side_px, 2),
        "marker_size_cm": marker_size_cm,
        "known_distance_cm": known_distance_cm,
        "image_size": {"width": frame.shape[1], "height": frame.shape[0]}
    }


def draw_markers(frame_path, output_path, results):
    """Draw detected markers on image and save."""
    frame = cv2.imread(frame_path)
    if frame is None:
        return False
    
    for marker in results.get("markers", []):
        corners = np.array([marker["corners"]], dtype=np.float32)
        marker_id = marker["id"]
        
        # Draw marker outline
        cv2.aruco.drawDetectedMarkers(frame, [corners.astype(np.int32)], np.array([[marker_id]]))
        
        # Draw distance text
        if marker.get("distance_cm") is not None:
            text = f"ID:{marker_id} {marker['distance_cm']:.1f}cm"
        else:
            text = f"ID:{marker_id}"
        
        # Position text at marker center
        center = corners[0].mean(axis=0).astype(int)
        cv2.putText(frame, text, tuple(center), cv2.FONT_HERSHEY_SIMPLEX,
                    0.5, (0, 255, 0), 2)
    
    cv2.imwrite(output_path, frame)
    return True


def main():
    parser = argparse.ArgumentParser(description="ArUco marker detection for DeepRacer")
    parser.add_argument("--calibrate", action="store_true",
                        help="Calibrate focal length (requires --known-distance)")
    parser.add_argument("--known-distance", type=float, default=None,
                        help="Known distance to marker in cm (for calibration)")
    parser.add_argument("--marker-size", type=float, default=MARKER_SIZE_CM,
                        help=f"Marker size in cm (default: {MARKER_SIZE_CM})")
    parser.add_argument("--focal-length", type=float, default=FOCAL_LENGTH_PX,
                        help="Focal length in pixels (if already calibrated)")
    parser.add_argument("--stream-url", type=str, default=STREAM_URL,
                        help="MJPEG stream URL")
    parser.add_argument("--output", type=str, default="/tmp/aruco_result.jpg",
                        help="Output image path with drawn markers")
    parser.add_argument("--json", action="store_true",
                        help="Output results as JSON")
    
    args = parser.parse_args()
    
    # Step 1: Capture frame
    if not capture_frame(args.stream_url):
        print(json.dumps({"error": "Failed to capture frame"}))
        sys.exit(1)
    
    # Step 2: Calibrate or detect
    if args.calibrate:
        if args.known_distance is None:
            print("Error: --calibrate requires --known-distance <cm>")
            sys.exit(1)
        
        results = calibrate_from_frame(FRAME_PATH, args.marker_size, args.known_distance)
        if "error" in results:
            print(json.dumps(results))
            sys.exit(1)
        
        print(json.dumps(results, indent=2))
        
        # Save calibration to file
        calib_path = "/tmp/aruco_calibration.json"
        with open(calib_path, "w") as f:
            json.dump(results, f, indent=2)
        print(f"\nCalibration saved to {calib_path}")
        print(f"Use: --focal-length {results['focal_length_px']}")
        
    else:
        focal = args.focal_length
        results = detect_aruco(FRAME_PATH, args.marker_size, focal)
        
        # Draw and save annotated image
        if results["markers_found"] > 0:
            draw_markers(FRAME_PATH, args.output, results)
            results["annotated_image"] = args.output
        
        if args.json:
            print(json.dumps(results, indent=2))
        else:
            print(f"Status: {results['status']}")
            print(f"Markers found: {results['markers_found']}")
            for m in results["markers"]:
                dist_str = f"{m['distance_cm']:.1f} cm" if m.get("distance_cm") else "N/A (no focal length)"
                print(f"  Marker ID {m['id']}: side={m['avg_side_px']:.1f}px, distance={dist_str}")


if __name__ == "__main__":
    main()
