import { Loader2, AlertTriangle, Check, Play, Square, Info, Crosshair } from 'lucide-react';
import useQuestVRInput from "../../hooks/useQuestVRInput";

export default function QuestVRControls() {
  const {
    isSupported,
    supportInfo,
    isSessionActive,
    leftController,
    rightController,
    startSession,
    endSession,
  } = useQuestVRInput();

  if (isSupported === null) {
    return (
      <div className="alert alert-info">
        <Loader2 className="w-5 h-5 animate-spin" />
        <span>Verificando compatibilidad WebXR...</span>
      </div>
    );
  }

  const DebugInfo = () => (
    <div className="collapse collapse-arrow bg-base-200 mt-4">
      <input type="checkbox" />
      <div className="collapse-title text-sm font-medium">
        <Info className="w-4 h-4 inline mr-2" />
        Información de Debug
      </div>
      <div className="collapse-content text-sm font-mono">
        <div className="grid grid-cols-2 gap-2">
          <span>navigator.xr:</span>
          <span className={supportInfo.hasNavigatorXR ? 'text-success' : 'text-error'}>
            {supportInfo.hasNavigatorXR ? 'Sí' : 'No'}
          </span>
          <span>immersive-vr:</span>
          <span className={supportInfo.immersiveVR ? 'text-success' : 'text-error'}>
            {supportInfo.immersiveVR ? 'Sí' : 'No'}
          </span>
          <span>immersive-ar:</span>
          <span className={supportInfo.immersiveAR ? 'text-success' : 'text-error'}>
            {supportInfo.immersiveAR ? 'Sí' : 'No'}
          </span>
          <span>inline:</span>
          <span className={supportInfo.inline ? 'text-success' : 'text-error'}>
            {supportInfo.inline ? 'Sí' : 'No'}
          </span>
        </div>
        {supportInfo.error && (
          <div className="text-error mt-2">Error: {supportInfo.error}</div>
        )}
      </div>
    </div>
  );

  if (!isSupported) {
    return (
      <div className="space-y-4">
        <div className="alert alert-warning">
          <AlertTriangle className="w-5 h-5" />
          <div>
            <h3 className="font-bold">WebXR No Disponible</h3>
            <p className="text-sm">Para usar los controles de Quest necesitas:</p>
          </div>
        </div>
        <ul className="list-disc list-inside text-sm opacity-80 pl-4">
          <li>Abrir esta página en el navegador del <strong>Meta Quest</strong></li>
          <li>Usar <strong>HTTPS</strong> o <strong>localhost</strong></li>
          <li>Asegurarte de que WebXR está habilitado</li>
        </ul>
        <DebugInfo />
      </div>
    );
  }

  const ControllerDisplay = ({ name, data, isLeft }) => (
    <div className={`card bg-base-200 flex-1 min-w-[250px]`}>
      <div className="card-body p-4">
        <h4 className={`font-semibold ${isLeft ? 'text-error' : 'text-info'}`}>
          {name}
        </h4>
        
        {/* Joystick Visual */}
        <div className="flex items-center gap-4 mb-3">
          <div className="relative w-16 h-16 rounded-full bg-base-300 border-2 border-base-content/20">
            <div 
              className={`absolute w-4 h-4 rounded-full ${isLeft ? 'bg-error' : 'bg-info'}`}
              style={{
                top: '50%',
                left: '50%',
                transform: `translate(calc(-50% + ${data.stickX * 20}px), calc(-50% + ${data.stickY * 20}px))`,
              }}
            />
          </div>
          <div className="font-mono text-sm opacity-70">
            <div>X: {data.stickX.toFixed(2)}</div>
            <div>Y: {data.stickY.toFixed(2)}</div>
          </div>
        </div>

        {/* Trigger */}
        <div className="mb-2">
          <div className="flex justify-between text-sm mb-1">
            <span>Gatillo</span>
            <span className="font-mono">{(data.trigger * 100).toFixed(0)}%</span>
          </div>
          <progress 
            className={`progress ${data.triggerPressed ? 'progress-success' : isLeft ? 'progress-error' : 'progress-info'} w-full`} 
            value={data.trigger * 100} 
            max="100"
          />
        </div>

        {/* Grip */}
        <div className="mb-3">
          <div className="flex justify-between text-sm mb-1">
            <span>Grip</span>
            <span className="font-mono">{(data.grip * 100).toFixed(0)}%</span>
          </div>
          <progress 
            className={`progress ${data.gripPressed ? 'progress-success' : isLeft ? 'progress-error' : 'progress-info'} w-full`} 
            value={data.grip * 100} 
            max="100"
          />
        </div>

        {/* Buttons */}
        <div className="flex gap-2">
          <div className={`badge ${data.buttonA ? 'badge-success' : 'badge-ghost'} badge-lg`}>
            {isLeft ? 'X' : 'A'}
          </div>
          <div className={`badge ${data.buttonB ? 'badge-success' : 'badge-ghost'} badge-lg`}>
            {isLeft ? 'Y' : 'B'}
          </div>
        </div>
      </div>
    </div>
  );

  return (
    <div className="space-y-4">
      {!isSessionActive ? (
        <div className="text-center space-y-4">
          <div className="alert alert-success">
            <Check className="w-5 h-5" />
            <span>WebXR detectado. Inicia una sesión VR para leer los controles.</span>
          </div>
          <button onClick={startSession} className="btn btn-primary btn-lg gap-2">
            <Play className="w-5 h-5" />
            Iniciar Sesión VR
          </button>
          <DebugInfo />
        </div>
      ) : (
        <>
          <div className="flex justify-center">
            <button onClick={endSession} className="btn btn-error btn-sm gap-2">
              <Square className="w-4 h-4" />
              Terminar Sesión VR
            </button>
          </div>
          
          <div className="flex flex-wrap gap-4 justify-center">
            <ControllerDisplay
              name="Controlador Izquierdo"
              data={leftController}
              isLeft={true}
            />
            <ControllerDisplay
              name="Controlador Derecho"
              data={rightController}
              isLeft={false}
            />
          </div>
        </>
      )}
    </div>
  );
}
