import { Joystick, Target } from 'lucide-react';

export default function GamepadSettings({ mode, onModeChange, isConnected }) {
  return (
    <div className="card bg-base-100 shadow-xl">
      <div className="card-body">
        <h2 className="card-title">Modo de Control del Gamepad</h2>
        <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
          <label 
            className={`card bg-base-200 cursor-pointer transition-all hover:bg-base-300 ${
              mode === 'joystick' ? 'ring-2 ring-primary' : ''
            } ${!isConnected ? 'opacity-50 pointer-events-none' : ''}`}
          >
            <input
              type="radio"
              name="gamepadMode"
              value="joystick"
              checked={mode === 'joystick'}
              onChange={(e) => onModeChange(e.target.value)}
              disabled={!isConnected}
              className="hidden"
            />
            <div className="card-body items-center text-center py-4">
              <Joystick className="w-10 h-10 mb-2" />
              <h3 className="font-semibold">Modo Joystick</h3>
              <p className="text-sm opacity-70">
                Un joystick controla dirección y velocidad
              </p>
            </div>
          </label>

          <label 
            className={`card bg-base-200 cursor-pointer transition-all hover:bg-base-300 ${
              mode === 'triggers' ? 'ring-2 ring-primary' : ''
            } ${!isConnected ? 'opacity-50 pointer-events-none' : ''}`}
          >
            <input
              type="radio"
              name="gamepadMode"
              value="triggers"
              checked={mode === 'triggers'}
              onChange={(e) => onModeChange(e.target.value)}
              disabled={!isConnected}
              className="hidden"
            />
            <div className="card-body items-center text-center py-4">
              <Target className="w-10 h-10 mb-2" />
              <h3 className="font-semibold">Modo Gatillos</h3>
              <p className="text-sm opacity-70">
                Gatillos = velocidad, Joystick = dirección
              </p>
            </div>
          </label>
        </div>
      </div>
    </div>
  );
}
