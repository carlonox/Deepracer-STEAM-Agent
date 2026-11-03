import { useRef, useState, useEffect } from 'react';
import { Maximize2, Minimize2 } from 'lucide-react';


export default function CameraFeed() {
  const containerRef = useRef(null);
  const [isFullscreen, setIsFullscreen] = useState(false);
  const AWS_HOST = import.meta.env.VITE_AWS_HOST || "localhost";
  // Con VITE_API_PROXY=1 el MJPEG va por mismo origen (/video/...) y vite
  // lo proxea al robot (evita mixed-content bajo HTTPS).
  const cameraUrl =
    import.meta.env.VITE_API_PROXY === "1"
      ? `/video/stream?topic=/camera_pkg/display_mjpeg&width=480&height=360&quality=85`
      : `http://${AWS_HOST}:8080/stream?topic=/camera_pkg/display_mjpeg&width=480&height=360&quality=85`;

  useEffect(() => {
    const handleFullscreenChange = () => {
      setIsFullscreen(!!document.fullscreenElement);
    };
    document.addEventListener('fullscreenchange', handleFullscreenChange);
    return () => document.removeEventListener('fullscreenchange', handleFullscreenChange);
  }, []);

  const toggleFullscreen = () => {
    if (!document.fullscreenElement) {
      containerRef.current?.requestFullscreen();
    } else {
      document.exitFullscreen();
    }
  };

  return (
    <div
      ref={containerRef}
      className={`camera-feed ${isFullscreen ? 'camera-fullscreen' : ''}`}
    >
      <img
        src={cameraUrl}
        alt="DeepRacer Camera Feed"
      />
      <button
        type="button"
        onClick={toggleFullscreen}
        className="camera-fullscreen-button"
        title={isFullscreen ? "Salir de pantalla completa" : "Pantalla completa"}
        aria-label={isFullscreen ? "Salir de pantalla completa" : "Pantalla completa"}
      >
        {isFullscreen ? <Minimize2 className="w-4 h-4" /> : <Maximize2 className="w-4 h-4" />}
      </button>
    </div>
  );
}
