import { Gamepad2, Glasses, Play, Settings2, Square } from 'lucide-react';
import ManualControls from './ManualControls';
import VRControls from './VRControls';

export default function ControlPanel({
  loading,
  status,
  manualMode,
  vrMode,
  onStartAuto,
  onStop,
  onActivateManual,
  onActivateVR,
  gamepadConnected,
  gamepadMode,
  onGamepadModeChange,
  maxSpeed,
  onSpeedChange,
  pressedKeys,
  onKeyPress,
  onKeyRelease,
  vrControlMode,
  onVRControlModeChange,
  vrDisplay,
  onVRDisplayChange,
  vrInput,
  leftController,
  rightController,
  isSupported,
  supportInfo,
  isSessionActive,
  xrStatus,
  padCount,
}) {
  const isAutoMode = status === 'Automático activo';

  return (
    <section className="panel control-panel">
      <div className="panel-heading">
        <span className="panel-icon"><Settings2 size={18} /></span>
        <div>
          <p className="eyebrow">VEHÍCULO</p>
          <h2>Controles</h2>
        </div>
      </div>

      <div className="action-grid">
        <button className="action-button action-auto" onClick={onStartAuto} disabled={loading}>
          <Play size={16} fill="currentColor" />
          <span>Automático</span>
        </button>
        <button className="action-button action-stop" onClick={onStop} disabled={loading}>
          <Square size={15} fill="currentColor" />
          <span>Detener</span>
        </button>
        <button
          className={`action-button action-manual ${manualMode ? 'action-selected' : ''}`}
          onClick={onActivateManual}
          disabled={loading || manualMode}
        >
          <Gamepad2 size={17} />
          <span>Manual</span>
        </button>
        <button
          className={`action-button action-vr ${vrMode ? 'action-selected' : ''}`}
          onClick={onActivateVR}
          disabled={loading || vrMode}
        >
          <Glasses size={17} />
          <span>Realidad virtual</span>
        </button>
      </div>

      {manualMode && (
        <ManualControls
          gamepadConnected={gamepadConnected}
          gamepadMode={gamepadMode}
          onGamepadModeChange={onGamepadModeChange}
          maxSpeed={maxSpeed}
          onSpeedChange={onSpeedChange}
          pressedKeys={pressedKeys}
          onKeyPress={onKeyPress}
          onKeyRelease={onKeyRelease}
        />
      )}

      {vrMode && (
        <VRControls
          maxSpeed={maxSpeed}
          onSpeedChange={onSpeedChange}
          controlMode={vrControlMode}
          onControlModeChange={onVRControlModeChange}
          display={vrDisplay}
          onDisplayChange={onVRDisplayChange}
          input={vrInput}
          leftController={leftController}
          rightController={rightController}
          isSupported={isSupported}
          supportInfo={supportInfo}
          isSessionActive={isSessionActive}
          xrStatus={xrStatus}
          padCount={padCount}
        />
      )}

      {!manualMode && !vrMode && (
        <div className="idle-message">
          <span className="idle-indicator" />
          <div>
            <strong>{isAutoMode ? 'Modo automático activo' : 'Vehículo detenido'}</strong>
            <p>
              {isAutoMode
                ? 'El control manual y VR están inactivos.'
                : 'Selecciona un modo para comenzar el control.'}
            </p>
          </div>
        </div>
      )}
    </section>
  );
}
