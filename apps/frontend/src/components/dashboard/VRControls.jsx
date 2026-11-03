import { Glasses } from 'lucide-react';
import SpeedControl from './SpeedControl';

export default function VRControls({
  maxSpeed,
  onSpeedChange,
  controlMode,
  onControlModeChange,
  display,
  onDisplayChange,
  input,
  leftController,
  rightController,
  isSupported,
  supportInfo,
  isSessionActive,
  xrStatus,
  padCount,
}) {
  const steering = input.steering;
  const throttle = input.throttle;

  return (
    <div className="mode-settings">
      <SpeedControl value={maxSpeed} onChange={onSpeedChange} />

      <section className="settings-card">
        <div className="settings-title"><h3>Esquema de control VR</h3></div>
        <div className="segmented-control">
          <button
            className={controlMode === 'joystick' ? 'segment-selected' : ''}
            onClick={() => onControlModeChange('joystick')}
            aria-pressed={controlMode === 'joystick'}
          >
            Joystick
          </button>
          <button
            className={controlMode === 'triggers' ? 'segment-selected' : ''}
            onClick={() => onControlModeChange('triggers')}
            aria-pressed={controlMode === 'triggers'}
          >
            Gatillos
          </button>
        </div>
        <p className="settings-help">
          {controlMode === 'joystick'
            ? 'Stick: dirección y marcha · Grip/A: freno'
            : 'RT: acelera · LT: frena/reversa · stick: dirección'}
          {!isSessionActive && ' · Entrada vía Gamepad API'}
        </p>
      </section>

      <section className="settings-card">
        <div className="settings-title"><h3>Vista del visor</h3></div>
        <div className="segmented-control">
          <button
            className={display === 'vr' ? 'segment-selected' : ''}
            onClick={() => onDisplayChange('vr')}
            aria-pressed={display === 'vr'}
          >
            Cámara VR
          </button>
          <button
            className={display === 'ar' ? 'segment-selected' : ''}
            onClick={() => onDisplayChange('ar')}
            disabled={Boolean(supportInfo && !supportInfo.immersiveAR && supportInfo.hasNavigatorXR)}
            title={supportInfo?.immersiveAR ? 'Vista passthrough' : 'Este navegador no anuncia AR'}
            aria-pressed={display === 'ar'}
          >
            Passthrough AR
          </button>
        </div>
        <p className="settings-help">AR muestra el entorno real con el HUD del vehículo superpuesto.</p>
      </section>

      <section className="settings-card vr-status-card">
        <div className="settings-title">
          <Glasses size={16} />
          <h3>Telemetría VR</h3>
          <span className="vr-session-state">{isSessionActive ? 'SESIÓN ACTIVA' : 'SIN SESIÓN XR'}</span>
        </div>
        <div className="vr-input-readout">
          <div className="input-visual" aria-label={`Dirección ${steering.toFixed(1)}, aceleración ${throttle.toFixed(1)}`}>
            <span
              style={{
                transform: `translate(calc(-50% + ${Math.max(-30, Math.min(30, steering * 1.5))}px), calc(-50% + ${Math.max(-30, Math.min(30, throttle * 1.5))}px))`,
              }}
            />
          </div>
          <dl className="input-values">
            <div><dt>Dirección</dt><dd>{steering.toFixed(1)}</dd></div>
            <div><dt>Aceleración</dt><dd>{throttle.toFixed(1)}</dd></div>
          </dl>
        </div>
        <div className="xr-diagnostics">
          <span>
            WebXR <b>{isSupported === null ? 'Verificando' : isSupported ? 'Disponible' : 'No disponible'}</b>
          </span>
          <span>AR <b>{supportInfo?.immersiveAR ? 'Disponible' : 'No disponible'}</b></span>
          <span>Gamepads <b>{padCount}</b></span>
          <span>Sesión <b>{isSessionActive ? 'Activa' : 'Inactiva'}</b></span>
          <p>{xrStatus}</p>
          <p>
            L: {leftController?.trigger?.toFixed(2) ?? '0.00'} / (
            {leftController?.stickX?.toFixed(2) ?? '0.00'}, {leftController?.stickY?.toFixed(2) ?? '0.00'})
            {' · '}
            R: {rightController?.trigger?.toFixed(2) ?? '0.00'} / (
            {rightController?.stickX?.toFixed(2) ?? '0.00'}, {rightController?.stickY?.toFixed(2) ?? '0.00'})
          </p>
          {isSupported === false && (
            <p className="diagnostic-warning">WebXR inmersivo no está disponible en este navegador.</p>
          )}
        </div>
      </section>
    </div>
  );
}
