import { useRef, useState, useEffect } from 'react';
import { Maximize2, Minimize2 } from 'lucide-react';
import { getCameraStreamUrl } from '../../config/frontend';

export default function CameraFeed({ onStatusChange }) {
  const containerRef = useRef(null);
  const [isFullscreen, setIsFullscreen] = useState(false);
  const [cameraStatus, setCameraStatus] = useState('connecting');
  const cameraUrl = getCameraStreamUrl();

  useEffect(() => {
    onStatusChange?.(cameraStatus);
  }, [cameraStatus, onStatusChange]);

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
        onLoad={() => setCameraStatus('connected')}
        onError={() => setCameraStatus('error')}
      />
      {cameraStatus !== 'connected' && (
        <p className="camera-message" role="status">
          {cameraStatus === 'error' ? 'No se pudo conectar con la cámara.' : 'Conectando con la cámara…'}
        </p>
      )}
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
