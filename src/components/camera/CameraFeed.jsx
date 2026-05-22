import { useRef, useState, useEffect } from 'react';
import { Maximize2, Minimize2 } from 'lucide-react';

export default function CameraFeed() {
  const containerRef = useRef(null);
  const [isFullscreen, setIsFullscreen] = useState(false);
  const cameraUrl = `http://${window.location.hostname}:8080/stream?topic=/camera_pkg/display_mjpeg&width=1280&height=720`;

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
      className={`relative group ${
        isFullscreen ? 'w-screen h-screen bg-black flex items-center justify-center' : 'flex justify-center'
      }`}
    >
      <img
        src={cameraUrl}
        alt="DeepRacer Camera Feed"
        className={isFullscreen 
          ? 'max-w-full max-h-full object-contain' 
          : 'rounded-xl shadow-lg max-w-full'
        }
        style={isFullscreen ? { width: '100%', height: '100%', objectFit: 'contain' } : {}}
      />
      <button 
        onClick={toggleFullscreen}
        className={`absolute top-2 right-2 btn btn-sm btn-circle btn-ghost bg-base-100/70 transition-opacity ${
          isFullscreen ? 'opacity-100' : 'opacity-0 group-hover:opacity-100'
        }`}
        title={isFullscreen ? "Salir de pantalla completa" : "Pantalla completa"}
      >
        {isFullscreen ? <Minimize2 className="w-4 h-4" /> : <Maximize2 className="w-4 h-4" />}
      </button>
    </div>
  );
}
