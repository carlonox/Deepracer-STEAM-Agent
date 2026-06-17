import { useState, useEffect, useRef, useCallback } from 'react';
import { 
  Play, 
  Square, 
  Gamepad2, 
  Gauge, 
  Camera, 
  Keyboard, 
  Settings,
  Wifi,
  WifiOff,
  Glasses
} from 'lucide-react';
import CameraFeed from './components/camera/CameraFeed';
import KeyboardControls from './components/controls/KeyboardControls';
import useVehicleControl from './hooks/useVehicleControl';
import useGamepad from './hooks/useGamepad';
import useKeyboard from './hooks/useKeyboard';
import { sendManualCommand, activateManualMode } from './services/vehicleApi';

function App() {
  const { loading, status, manualMode, setManualMode, startAuto, stop, activateManual } = useVehicleControl();
  const [maxSpeed, setMaxSpeed] = useState(0.5);
  const [gamepadMode, setGamepadMode] = useState('joystick');
  const [vrMode, setVrMode] = useState(false);
  const [vrInput, setVrInput] = useState({ steering: 0, throttle: 0 });
  const lastSendTime = useRef(0);
  
  const { isConnected: gamepadConnected } = useGamepad(manualMode, gamepadMode, maxSpeed, setMaxSpeed);
  const { pressedKeys } = useKeyboard(true, maxSpeed); // TODO: cambiar a manualMode

  // Mouse/Pointer/Touch event logging - capture ALL event info
  useEffect(() => {
    const logEvent = (emoji, name, e) => {
      const info = {
        type: e.type,
        button: e.button,
        buttons: e.buttons,
        clientX: e.clientX,
        clientY: e.clientY,
        screenX: e.screenX,
        screenY: e.screenY,
        movementX: e.movementX,
        movementY: e.movementY,
        pointerType: e.pointerType,
        pointerId: e.pointerId,
        pressure: e.pressure,
        width: e.width,
        height: e.height,
        tiltX: e.tiltX,
        tiltY: e.tiltY,
        twist: e.twist,
        isPrimary: e.isPrimary,
        detail: e.detail,
        which: e.which,
        deltaX: e.deltaX,
        deltaY: e.deltaY,
        deltaZ: e.deltaZ,
        deltaMode: e.deltaMode,
      };
      // Filter out undefined values
      const filtered = Object.fromEntries(Object.entries(info).filter(([_, v]) => v !== undefined));
      console.log(`${emoji} ${name}:`, filtered);
    };

    // Mouse events
    const handleMouseDown = (e) => logEvent('�️', 'mousedown', e);
    const handleMouseUp = (e) => logEvent('�️', 'mouseup', e);
    const handleClick = (e) => logEvent('�️', 'click', e);
    const handleDblClick = (e) => logEvent('�️', 'dblclick', e);
    const handleContextMenu = (e) => logEvent('�️', 'contextmenu', e);
    const handleAuxClick = (e) => logEvent('🖱️', 'auxclick', e);

    // Pointer events (more detailed than mouse)
    const handlePointerDown = (e) => logEvent('👆', 'pointerdown', e);
    const handlePointerUp = (e) => logEvent('👆', 'pointerup', e);
    const handlePointerEnter = (e) => logEvent('👆', 'pointerenter', e);
    const handlePointerLeave = (e) => logEvent('👆', 'pointerleave', e);
    const handlePointerCancel = (e) => logEvent('👆', 'pointercancel', e);

    // Touch events
    const handleTouchStart = (e) => {
      const touches = Array.from(e.touches).map(t => ({
        id: t.identifier,
        clientX: t.clientX,
        clientY: t.clientY,
        force: t.force,
        radiusX: t.radiusX,
        radiusY: t.radiusY,
        rotationAngle: t.rotationAngle,
      }));
      console.log('✋ touchstart:', { touchCount: e.touches.length, touches });
    };
    const handleTouchEnd = (e) => {
      const changed = Array.from(e.changedTouches).map(t => ({
        id: t.identifier,
        clientX: t.clientX,
        clientY: t.clientY,
      }));
      console.log('✋ touchend:', { changed });
    };
    const handleTouchCancel = (e) => console.log('✋ touchcancel');

    // Wheel event
    const handleWheel = (e) => logEvent('🎡', 'wheel', e);

    // Add all listeners
    window.addEventListener('mousedown', handleMouseDown);
    window.addEventListener('mouseup', handleMouseUp);
    window.addEventListener('click', handleClick);
    window.addEventListener('dblclick', handleDblClick);
    window.addEventListener('contextmenu', handleContextMenu);
    window.addEventListener('auxclick', handleAuxClick);
    
    window.addEventListener('pointerdown', handlePointerDown);
    window.addEventListener('pointerup', handlePointerUp);
    window.addEventListener('pointerenter', handlePointerEnter);
    window.addEventListener('pointerleave', handlePointerLeave);
    window.addEventListener('pointercancel', handlePointerCancel);
    
    window.addEventListener('touchstart', handleTouchStart);
    window.addEventListener('touchend', handleTouchEnd);
    window.addEventListener('touchcancel', handleTouchCancel);
    
    window.addEventListener('wheel', handleWheel);

    return () => {
      window.removeEventListener('mousedown', handleMouseDown);
      window.removeEventListener('mouseup', handleMouseUp);
      window.removeEventListener('click', handleClick);
      window.removeEventListener('dblclick', handleDblClick);
      window.removeEventListener('contextmenu', handleContextMenu);
      window.removeEventListener('auxclick', handleAuxClick);
      
      window.removeEventListener('pointerdown', handlePointerDown);
      window.removeEventListener('pointerup', handlePointerUp);
      window.removeEventListener('pointermove', handlePointerMove);
      window.removeEventListener('pointerenter', handlePointerenter);
      window.removeEventListener('pointerleave', handlePointerLeave);
      window.removeEventListener('pointercancel', handlePointerCancel);
      
      window.removeEventListener('touchstart', handleTouchStart);
      window.removeEventListener('touchend', handleTouchEnd);
      window.removeEventListener('touchcancel', handleTouchCancel);
      
      window.removeEventListener('wheel', handleWheel);
    };
  }, []);

  // VR Mode: Use wheel events from Meta Quest joystick to simulate keyboard
  const sendVRCommand = useCallback(async (dirX, dirY, forceStop = false) => {
    const now = Date.now();
    if (now - lastSendTime.current < 50) return; // Throttle to 20Hz
    lastSendTime.current = now;
    
    // Simulate keyboard-like controls based on joystick direction
    // deltaX: negative = left, positive = right (range ~-20 to ~20)
    // deltaY: negative = up/forward, positive = down/backward (range ~-20 to ~20)
    let angle = 0;
    let throttle = 0;
    
    // Higher threshold = less sensitivity (need to move joystick more)
    const threshold = 12;
    
    const isUp = dirY < -threshold;      // Joystick forward (deltaY negative)
    const isDown = dirY > threshold;     // Joystick backward (deltaY positive)
    const isLeft = dirX < -threshold;    // Joystick left (deltaX negative)
    const isRight = dirX > threshold;    // Joystick right (deltaX positive)
    
    // Combine directions like keyboard does
    if (isUp && isRight) {
      angle = 45;
      throttle = -100;
    } else if (isUp && isLeft) {
      angle = -45;
      throttle = -100;
    } else if (isDown && isRight) {
      angle = 45;
      throttle = 100;
    } else if (isDown && isLeft) {
      angle = -45;
      throttle = 100;
    } else {
      if (isUp) throttle = -100;
      else if (isDown) throttle = 100;
      else if (isLeft) {
        angle = -45;
        throttle = 0;
      } else if (isRight) {
        angle = 45;
        throttle = 0;
      }
    }
    
    // Send command if there's movement OR if we need to force stop
    if (angle !== 0 || throttle !== 0 || forceStop) {
      console.log(`🥽 VR Command: Angle=${angle}° Throttle=${throttle}% Speed=${maxSpeed}${forceStop ? ' (STOP)' : ''}`);
      try {
        await sendManualCommand(angle, throttle, maxSpeed);
      } catch (error) {
        console.error('Error sending VR command:', error);
      }
    }
  }, [maxSpeed]);

  // VR wheel event listener (only when VR mode is active)
  useEffect(() => {
    if (!vrMode) return;
    
    let isMoving = false;
    let decayInterval;

    const handleWheel = (e) => {
      e.preventDefault();
      
      // Get joystick direction from wheel deltas
      const dirX = e.deltaX;
      const dirY = e.deltaY;
      
      console.log(`🥽 VR Wheel: deltaX=${dirX.toFixed(1)} deltaY=${dirY.toFixed(1)}`);
      isMoving = true;
      setVrInput({ steering: dirX, throttle: dirY });
      sendVRCommand(dirX, dirY);
    };

    // Check periodically if joystick was released (no wheel events = stopped)
    decayInterval = setInterval(async () => {
      const timeSinceLastInput = Date.now() - lastSendTime.current;
      if (timeSinceLastInput > 150 && isMoving) {
        isMoving = false;
        setVrInput({ steering: 0, throttle: 0 });
        console.log('🥽 VR: Joystick released - sending stop');
        try {
          await sendManualCommand(0, 0, maxSpeed);
        } catch (error) {
          console.error('Error sending stop command:', error);
        }
      }
    }, 100);

    window.addEventListener('wheel', handleWheel, { passive: false });

    return () => {
      window.removeEventListener('wheel', handleWheel);
      clearInterval(decayInterval);
    };
  }, [vrMode, sendVRCommand]);

  // Activate VR mode (deactivates manual mode but initializes backend for manual control)
  const activateVR = async () => {
    console.log('🥽 Activating VR Mode...');
    setManualMode(false);
    setVrMode(true);
    // Initialize backend for manual drive commands (same as manual mode)
    try {
      await activateManualMode();
      console.log('🥽 VR Mode: Backend initialized successfully');
    } catch (error) {
      console.error('Error initializing VR mode:', error);
    }
  };

  // Activate manual mode wrapper (deactivates VR mode)
  const handleActivateManual = async () => {
    console.log('🎮 Activating Manual Mode...');
    setVrMode(false);
    await activateManual();
  };

  // Deactivate VR mode (stop also deactivates)
  const handleStop = async () => {
    console.log('🛑 Stopping vehicle...');
    setVrMode(false);
    await stop();
  };

  const handleKeyPress = (key) => {
    console.log(`📱 Virtual Key Press: ${key}`);
    window.dispatchEvent(new KeyboardEvent('keydown', { key, bubbles: true }));
  };

  const handleKeyRelease = (key) => {
    console.log(`📱 Virtual Key Release: ${key}`);
    window.dispatchEvent(new KeyboardEvent('keyup', { key, bubbles: true }));
  };

  const getStatusBadge = () => {
    if (status === 'Detenido') return 'badge-error';
    if (status.includes('manual')) return 'badge-success';
    return 'badge-info';
  };

  return (
    <div className="min-h-screen bg-base-200" data-theme="dark">
      {/* Navbar */}
      <div className="navbar bg-base-100 shadow-lg px-4">
        <div className="flex-1">
          <span className="text-xl font-bold">DeepRacer Control</span>
        </div>
        <div className="flex-none gap-2">
          <div className={`badge ${getStatusBadge()} gap-2`}>
            <span className={`w-2 h-2 rounded-full ${status !== 'Detenido' ? 'bg-current animate-pulse' : 'bg-current'}`}></span>
            {status}
          </div>
        </div>
      </div>

      <div className="container mx-auto p-4">
        {/* Main Layout: Camera + Controls side by side */}
        <div className="flex flex-col lg:flex-row gap-4">
          {/* Camera Feed - Left Side - Sticky on mobile */}
          <div className="lg:flex-1 sticky top-0 z-10 lg:static lg:z-auto">
            <div className="card bg-base-100 shadow-xl">
              <div className="card-body p-4">
                <h2 className="card-title text-sm">
                  <Camera className="w-4 h-4" />
                  Cámara en Vivo
                </h2>
                <CameraFeed />
              </div>
            </div>
          </div>

          {/* Controls - Right Side */}
          <div className="w-full lg:w-80 xl:w-96 space-y-4 flex-shrink-0">
            {/* Main Controls */}
            <div className="card bg-base-100 shadow-xl">
              <div className="card-body p-4">
                <h2 className="card-title text-sm">
                  <Settings className="w-4 h-4" />
                  Control
                </h2>
                <div className="flex flex-col gap-2">
                  <button 
                    className={`btn btn-primary btn-sm ${loading ? 'loading' : ''}`}
                    onClick={startAuto}
                    disabled={loading}
                  >
                    <Play className="w-4 h-4" />
                    Automático
                  </button>
                  <button 
                    className={`btn btn-error btn-sm ${loading ? 'loading' : ''}`}
                    onClick={handleStop}
                    disabled={loading}
                  >
                    <Square className="w-4 h-4" />
                    Detener
                  </button>
                  <button 
                    className={`btn btn-success btn-sm ${loading ? 'loading' : ''}`}
                    onClick={handleActivateManual}
                    disabled={loading || manualMode}
                  >
                    <Gamepad2 className="w-4 h-4" />
                    Manual
                  </button>
                  <button 
                    className={`btn btn-secondary btn-sm ${loading ? 'loading' : ''}`}
                    onClick={activateVR}
                    disabled={loading || vrMode}
                  >
                    <Glasses className="w-4 h-4" />
                    VR
                  </button>
                </div>
              </div>
            </div>

            {/* Manual Mode Controls */}
            {manualMode && (
              <div className="space-y-4">
                {/* Gamepad Status */}
                <div className={`alert alert-sm ${gamepadConnected ? 'alert-success' : 'alert-warning'}`}>
                  {gamepadConnected ? (
                    <>
                      <Wifi className="w-4 h-4" />
                      <span className="text-sm">Gamepad conectado</span>
                    </>
                  ) : (
                    <>
                      <WifiOff className="w-4 h-4" />
                      <span className="text-sm">Sin gamepad</span>
                    </>
                  )}
                </div>

                {/* Speed Control */}
                <div className="card bg-base-100 shadow-xl">
                  <div className="card-body p-4">
                    <h2 className="card-title text-sm">
                      <Gauge className="w-4 h-4" />
                      Velocidad
                    </h2>
                    <div className="flex items-center gap-2">
                      <input 
                        type="range" 
                        min="0.1" 
                        max="1" 
                        step="0.01"
                        value={maxSpeed} 
                        onChange={(e) => setMaxSpeed(parseFloat(e.target.value))}
                        className="range range-primary range-sm flex-1" 
                      />
                      <div className="badge badge-primary font-mono">
                        {maxSpeed.toFixed(2)}
                      </div>
                    </div>
                  </div>
                </div>

                {/* Gamepad Mode */}
                <div className="card bg-base-100 shadow-xl">
                  <div className="card-body p-4">
                    <h2 className="card-title text-sm mb-2">Modo Gamepad</h2>
                    <div className="flex gap-2">
                      <button 
                        className={`btn btn-sm flex-1 ${gamepadMode === 'joystick' ? 'btn-primary' : 'btn-ghost'}`}
                        onClick={() => setGamepadMode('joystick')}
                        disabled={!gamepadConnected}
                      >
                        Joystick
                      </button>
                      <button 
                        className={`btn btn-sm flex-1 ${gamepadMode === 'triggers' ? 'btn-primary' : 'btn-ghost'}`}
                        onClick={() => setGamepadMode('triggers')}
                        disabled={!gamepadConnected}
                      >
                        Gatillos
                      </button>
                    </div>
                  </div>
                </div>

                {/* Keyboard Controls */}
                <div className="card bg-base-100 shadow-xl">
                  <div className="card-body p-4">
                    <h2 className="card-title text-sm">
                      <Keyboard className="w-4 h-4" />
                      Teclado
                    </h2>
                    <KeyboardControls
                      pressedKeys={pressedKeys}
                      onKeyPress={handleKeyPress}
                      onKeyRelease={handleKeyRelease}
                    />
                  </div>
                </div>
              </div>
            )}

            {/* VR Mode Status */}
            {vrMode && (
              <div className="space-y-4">
                {/* Speed Control */}
                <div className="card bg-base-100 shadow-xl">
                  <div className="card-body p-4">
                    <h2 className="card-title text-sm">
                      <Gauge className="w-4 h-4" />
                      Velocidad
                    </h2>
                    <div className="flex items-center gap-2">
                      <input 
                        type="range" 
                        min="0.1" 
                        max="1" 
                        step="0.01"
                        value={maxSpeed} 
                        onChange={(e) => setMaxSpeed(parseFloat(e.target.value))}
                        className="range range-secondary range-sm flex-1" 
                      />
                      <div className="badge badge-secondary font-mono">
                        {maxSpeed.toFixed(2)}
                      </div>
                    </div>
                  </div>
                </div>

                {/* VR Joystick Status */}
                <div className="card bg-base-100 shadow-xl">
                  <div className="card-body p-4">
                    <h2 className="card-title text-sm">
                      <Glasses className="w-4 h-4" />
                      Modo VR Activo
                    </h2>
                    <p className="text-sm opacity-70 mb-3">Usa el joystick del Meta Quest para controlar</p>
                    
                    {/* Visual joystick indicator */}
                    <div className="flex items-center justify-center gap-4">
                      <div className="relative w-20 h-20 rounded-full bg-base-300 border-2 border-secondary">
                        <div 
                          className="absolute w-5 h-5 rounded-full bg-secondary transition-transform duration-75"
                          style={{
                            top: '50%',
                            left: '50%',
                            transform: `translate(calc(-50% + ${Math.max(-30, Math.min(30, vrInput.steering * 1.5))}px), calc(-50% + ${Math.max(-30, Math.min(30, vrInput.throttle * 1.5))}px))`,
                          }}
                        />
                      </div>
                      <div className="font-mono text-sm">
                        <div className="flex justify-between gap-2">
                          <span className="opacity-70">Dirección:</span>
                          <span className={vrInput.steering < 0 ? 'text-warning' : vrInput.steering > 0 ? 'text-info' : ''}>
                            {vrInput.steering.toFixed(1)}
                          </span>
                        </div>
                        <div className="flex justify-between gap-2">
                          <span className="opacity-70">Aceleración:</span>
                          <span className={vrInput.throttle > 0 ? 'text-success' : vrInput.throttle < 0 ? 'text-error' : ''}>
                            {vrInput.throttle.toFixed(1)}
                          </span>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            )}
          </div>
        </div>
      </div>
    </div>
  );
}

export default App;
