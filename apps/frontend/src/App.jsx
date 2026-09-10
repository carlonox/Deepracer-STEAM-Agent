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
import useQuestVRInput from './hooks/useQuestVRInput';
import { sendManualCommand, activateManualMode } from './services/vehicleApi';

function App() {
  const { loading, status, manualMode, setManualMode, startAuto, stop, activateManual } = useVehicleControl();
  const [maxSpeed, setMaxSpeed] = useState(0.5);
  const [gamepadMode, setGamepadMode] = useState('joystick');
  const [vrMode, setVrMode] = useState(false);
  const [vrControlMode, setVrControlMode] = useState('triggers');
  const [vrDisplay, setVrDisplay] = useState('vr'); // 'vr' = cámara stream, 'ar' = passthrough
  const [vrInput, setVrInput] = useState({ steering: 0, throttle: 0 });
  const lastSendTime = useRef(0);
  
  const { isConnected: gamepadConnected } = useGamepad(manualMode, gamepadMode, maxSpeed, setMaxSpeed);
  const { pressedKeys } = useKeyboard(true, maxSpeed); // TODO: cambiar a manualMode
  const { leftController, rightController, isSupported, supportInfo, isSessionActive, xrStatus, hudRef, startSession: startXRSession, endSession: endXRSession } = useQuestVRInput();
  const [padCount, setPadCount] = useState(0);

  // HUD dentro del casco: modo + mando actual para la sesión XR
  useEffect(() => {
    if (hudRef) hudRef.current = { mode: vrControlMode, display: vrDisplay, steering: vrInput.steering, throttle: vrInput.throttle };
  }, [vrControlMode, vrDisplay, vrInput, hudRef]);
  const lastVRSent = useRef({ angle: 0, throttle: 0 });

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
      const filtered = Object.fromEntries(Object.entries(info).filter(([, v]) => v !== undefined));
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
    const handleTouchCancel = () => console.log('✋ touchcancel');

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
      window.removeEventListener('pointerenter', handlePointerEnter);
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
    // El STOP siempre pasa: un stop throttled = robot desbocado.
    if (!forceStop && now - lastSendTime.current < 50) return; // Throttle to 20Hz
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

  // STOP con reintentos: un solo POST perdido = robot desbocado.
  // Marca inactivo + manda stop ya + 2 refuerzos (120/350 ms).
  const stopTimers = useRef([]);
  const lastDriveRx = useRef(0);
  const lastVRFwd = useRef(false); // marcha adelante vigente (para freno LT)
  const sendVRStop = useCallback((reason) => {
    lastVRSent.current = { active: false };
    lastVRFwd.current = false;
    setVrInput({ steering: 0, throttle: 0 });
    console.log(`🥽 VR stop (${reason})`);
    sendVRCommand(0, 0, true);
    stopTimers.current.forEach(clearTimeout);
    stopTimers.current = [120, 350].map((ms) =>
      setTimeout(() => { sendManualCommand(0, 0, maxSpeed).catch(() => {}); }, ms)
    );
  }, [maxSpeed, sendVRCommand]);

  useEffect(() => () => stopTimers.current.forEach(clearTimeout), []);

  // Dead-man: si VR queda "activo" sin comandos frescos (>500 ms), parar.
  useEffect(() => {
    if (!vrMode) return;
    const id = setInterval(() => {
      if (lastVRSent.current.active && Date.now() - lastDriveRx.current > 500) {
        sendVRStop('dead-man');
      }
    }, 250);
    return () => clearInterval(id);
  }, [vrMode, sendVRStop]);
  // VR drive desde controles WebXR reales (reemplaza el hack de rueda).
  // triggers: RT adelante, LT atrás, stick X gira.
  // joystick: stick derecho manda aceleración + giro.
  useEffect(() => {
    if (!vrMode) return;
    const rt = rightController?.trigger ?? 0;
    const lt = leftController?.trigger ?? 0;
    const stickX = rightController?.stickX || leftController?.stickX || 0;
    const stickY = rightController?.stickY || leftController?.stickY || 0;
    // Deadzone con corte real: sin esto el reposo del stick filtra ±3° fantasma.
    const sX = Math.abs(stickX) >= 0.15 ? stickX : 0;
    const sY = Math.abs(stickY) >= 0.15 ? stickY : 0;
    const grip = Math.max(rightController?.grip ?? 0, leftController?.grip ?? 0);
    const btnA = rightController?.buttonA || leftController?.buttonA || false;
    let dirX = 0;
    let dirY = 0;
    let active = false;
    let brake = false;
    if (vrControlMode === 'joystick') {
      // Grip o A = freno dedicado
      brake = grip > 0.3 || btnA;
      active = brake || Math.abs(stickX) >= 0.15 || Math.abs(stickY) >= 0.15;
      if (!active) {
        if (lastVRSent.current.active) sendVRStop('suelta joystick');
        return;
      }
      dirX = brake ? 0 : sX * 20;
      dirY = brake ? 0 : sY * 20;
    } else {
      // Arcade: RT acelera; LT con marcha adelante = freno, si no = reversa
      const rtOn = rt >= 0.08;
      const ltOn = lt >= 0.08;
      brake = grip > 0.3 || btnA || (ltOn && !rtOn && lastVRFwd.current);
      active = brake || rtOn || ltOn || Math.abs(stickX) >= 0.15;
      if (!active) {
        if (lastVRSent.current.active) sendVRStop('suelta gatillos');
        return;
      }
      dirX = brake ? 0 : sX * 20;
      dirY = brake ? 0 : (lt - rt) * 20;
    }
    lastVRSent.current = { active: true };
    lastDriveRx.current = Date.now();
    if (!brake) lastVRFwd.current = dirY < -12;
    setVrInput({ steering: dirX, throttle: dirY });
    if (brake) sendVRCommand(0, 0, true);
    else sendVRCommand(dirX, dirY);
  }, [vrMode, vrControlMode, leftController, rightController, sendVRCommand, sendVRStop]);

  // VR fallback: sin sesión XR (p. ej. HTTP en LAN, sin HTTPS) el Quest
  // expone los controles por Gamepad API. Mismo mapeo que modo Manual.
  useEffect(() => {
    if (!vrMode || isSessionActive) return;
    let raf = 0;
    const AXIS_DEAD = 0.15;
    const TRIG_DEAD = 0.05;
    const loop = async () => {
      const pads = navigator.getGamepads ? navigator.getGamepads() : [];
      let count = 0;
      for (const p of pads) { if (p && p.connected) count++; }
      setPadCount(count);
      let pad = null;
      for (const p of pads) {
        if (p && p.connected && (p.axes.length >= 2 || p.buttons.length >= 8)) { pad = p; break; }
      }
      if (pad) {
        let dirX = 0;
        let dirY = 0;
        let active = false;
        let brake = false;
        if (vrControlMode === 'joystick') {
          const axRaw = pad.axes[0] ?? 0;
          const ayRaw = pad.axes[1] ?? 0;
          const ax = Math.abs(axRaw) >= AXIS_DEAD ? axRaw : 0;
          const ay = Math.abs(ayRaw) >= AXIS_DEAD ? ayRaw : 0;
          brake = pad.buttons[0]?.pressed || false; // A = freno
          active = brake || ax !== 0 || ay !== 0;
          if (active) { dirX = brake ? 0 : ax * 20; dirY = brake ? 0 : ay * 20; }
        } else {
          const rtv = pad.buttons[7]?.value ?? 0;
          const ltv = pad.buttons[6]?.value ?? 0;
          const axRaw = pad.axes[0] ?? 0;
          const ax = Math.abs(axRaw) >= AXIS_DEAD ? axRaw : 0;
          const rtOn = rtv > TRIG_DEAD;
          const ltOn = ltv > TRIG_DEAD;
          brake = (pad.buttons[0]?.pressed || false) || (ltOn && !rtOn && lastVRFwd.current);
          active = brake || rtOn || ltOn || ax !== 0;
          if (active) { dirX = brake ? 0 : ax * 20; dirY = brake ? 0 : (ltv - rtv) * 20; }
        }
        if (!active) {
          if (lastVRSent.current.active) sendVRStop('suelta fallback');
        } else {
          lastVRSent.current = { active: true };
          lastDriveRx.current = Date.now();
          if (!brake) lastVRFwd.current = dirY < -12;
          setVrInput({ steering: dirX, throttle: dirY });
          if (brake) sendVRCommand(0, 0, true);
          else sendVRCommand(dirX, dirY);
        }
      }
      raf = requestAnimationFrame(loop);
    };
    raf = requestAnimationFrame(loop);
    return () => cancelAnimationFrame(raf);
  }, [vrMode, vrControlMode, isSessionActive, sendVRCommand, sendVRStop]);

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
    // Best effort: open the WebXR session so controller state flows.
    // Driving still works without it only if the browser exposes gamepads.
    try {
      const xrOk = await startXRSession(vrDisplay);
      if (!xrOk) console.warn('🥽 WebXR session not started: triggers/sticks unavailable in VR mode');
    } catch (error) {
      console.error('Error starting XR session:', error);
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
    try { await endXRSession(); } catch (error) { console.error('Error ending XR session:', error); }
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

                {/* VR Control Mode */}
                <div className="card bg-base-100 shadow-xl">
                  <div className="card-body p-4">
                    <h2 className="card-title text-sm mb-2">Modo VR</h2>
                    <div className="flex gap-2">
                      <button
                        className={`btn btn-sm flex-1 ${vrControlMode === 'joystick' ? 'btn-primary' : 'btn-ghost'}`}
                        onClick={() => setVrControlMode('joystick')}
                      >
                        Joystick
                      </button>
                      <button
                        className={`btn btn-sm flex-1 ${vrControlMode === 'triggers' ? 'btn-primary' : 'btn-ghost'}`}
                        onClick={() => setVrControlMode('triggers')}
                      >
                        Gatillos
                      </button>
                    </div>
                    <p className="text-xs opacity-70 mt-2">
                      {vrControlMode === 'joystick'
                        ? 'Stick: arriba = adelante, X = giro · Grip/A = freno'
                        : 'RT = acelera · LT = frena/reversa · stick = giro · Grip/A = freno'}
                      {!isSessionActive && ' (sin sesion XR: via Gamepad API)'}
                    </p>
                    <h2 className="card-title text-sm mb-2 mt-3">Vista</h2>
                    <div className="flex gap-2">
                      <button
                        className={`btn btn-sm flex-1 ${vrDisplay === 'vr' ? 'btn-primary' : 'btn-ghost'}`}
                        onClick={() => setVrDisplay('vr')}
                      >
                        VR cámara
                      </button>
                      <button
                        className={`btn btn-sm flex-1 ${vrDisplay === 'ar' ? 'btn-primary' : 'btn-ghost'}`}
                        onClick={() => setVrDisplay('ar')}
                        disabled={supportInfo && !supportInfo.immersiveAR && supportInfo.hasNavigatorXR}
                        title={supportInfo?.immersiveAR ? 'Passthrough: ves el cuarto directo' : 'Este navegador no anuncia AR'}
                      >
                        AR real
                      </button>
                    </div>
                    <p className="text-xs opacity-70 mt-2">
                      AR = ves el cuarto y el robot directo (cero lag, nitidez total) + HUD flotante.
                    </p>
                  </div>
                </div>

                {/* VR Joystick Status */}
                <div className="card bg-base-100 shadow-xl">
                  <div className="card-body p-4">
                    <h2 className="card-title text-sm">
                      <Glasses className="w-4 h-4" />
                      Modo VR Activo
                    </h2>
                    <p className="text-sm opacity-70 mb-3">Usa los controles del Meta Quest para conducir</p>
                    
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
                    {/* Diagnóstico visible en casco (sin F12) */}
                    <div className="font-mono text-xs mt-3 space-y-1 border-t border-base-300 pt-2">
                      <div>Seguro: {window.isSecureContext ? 'sí' : 'NO (http)'} · XR: {supportInfo.hasNavigatorXR ? 'sí' : 'no'} · inmersivo: {supportInfo.immersiveVR ? 'sí' : 'no'} · sesión: {isSessionActive ? 'activa' : 'no'} · pads: {padCount}</div>
                      <div>XR: {xrStatus}</div>
                      <div>L trg={ (leftController?.trigger ?? 0).toFixed(2)} stk=({(leftController?.stickX ?? 0).toFixed(2)},{(leftController?.stickY ?? 0).toFixed(2)}) · R trg={(rightController?.trigger ?? 0).toFixed(2)} stk=({(rightController?.stickX ?? 0).toFixed(2)},{(rightController?.stickY ?? 0).toFixed(2)})</div>
                      {isSupported === false && <div className="text-warning">Sin WebXR inmersivo: aprieta gatillos y mira si cambian trg/pads arriba.</div>}
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
