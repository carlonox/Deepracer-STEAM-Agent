import { Keyboard, Wifi, WifiOff } from 'lucide-react';
import KeyboardControls from '../controls/KeyboardControls';
import SpeedControl from './SpeedControl';

export default function ManualControls({
  gamepadConnected,
  gamepadMode,
  onGamepadModeChange,
  maxSpeed,
  onSpeedChange,
  pressedKeys,
  onKeyPress,
  onKeyRelease,
}) {
  return (
    <div className="mode-settings">
      <div className={`connection-banner ${gamepadConnected ? 'connection-active' : ''}`}>
        {gamepadConnected ? <Wifi size={16} /> : <WifiOff size={16} />}
        <span>{gamepadConnected ? 'Gamepad conectado' : 'Gamepad desconectado'}</span>
        <span className="connection-dot" />
      </div>

      <SpeedControl value={maxSpeed} onChange={onSpeedChange} />

      <section className="settings-card">
        <div className="settings-title"><h3>Modo de gamepad</h3></div>
        <div className="segmented-control">
          <button
            className={gamepadMode === 'joystick' ? 'segment-selected' : ''}
            onClick={() => onGamepadModeChange('joystick')}
            disabled={!gamepadConnected}
            aria-pressed={gamepadMode === 'joystick'}
          >
            Joystick
          </button>
          <button
            className={gamepadMode === 'triggers' ? 'segment-selected' : ''}
            onClick={() => onGamepadModeChange('triggers')}
            disabled={!gamepadConnected}
            aria-pressed={gamepadMode === 'triggers'}
          >
            Gatillos
          </button>
        </div>
      </section>

      <section className="settings-card keyboard-card">
        <div className="settings-title">
          <Keyboard size={16} />
          <h3>Teclado</h3>
          <span className="keyboard-hint">W A S D</span>
        </div>
        <KeyboardControls
          pressedKeys={pressedKeys}
          onKeyPress={onKeyPress}
          onKeyRelease={onKeyRelease}
        />
      </section>
    </div>
  );
}
