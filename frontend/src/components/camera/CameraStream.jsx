"use client";

export default function CameraStream() {
  return (
    <div className="w-full flex justify-center">
      <img
        src="http://localhost:5002/api/video_stream"
        alt="Camera Stream"
        className="rounded-xl shadow-lg max-w-full"
      />
    </div>
  );
}
