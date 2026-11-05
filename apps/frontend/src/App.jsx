import { useCallback, useState } from 'react';
import { Camera, Radio } from 'lucide-react';
import CameraFeed from './components/camera/CameraFeed';
import ControlPanel from './components/dashboard/ControlPanel';
import DashboardHeader from './components/dashboard/DashboardHeader';
import useVehicleControl from './features/vehicle/useVehicleControl';
import useGamepad from './hooks/useGamepad';
import useKeyboard from './hooks/useKeyboard';
import useVRDrive from './hooks/useVRDrive';
import useGamepadPresence from './shared/hooks/useGamepadPresence';
import useToast from './shared/hooks/useToast';
import ToastRegion from './shared/components/ToastRegion';
import VehicleStatus from './shared/components/VehicleStatus';
import './styles/dashboard.css';

function App() {
  const { toast, notify, dismiss } = useToast();
  const { loading, status, manualMode, vrMode, startAuto, stop, activateManual, activateVR: activateVRMode } = useVehicleControl(notify);
  const [maxSpeed, setMaxSpeed] = useState(0.5);
  const [gamepadMode, setGamepadMode] = useState('joystick');
  const [vrControlMode, setVrControlMode] = useState('triggers');
  const [vrDisplay, setVrDisplay] = useState('vr');
  const [cameraStatus, setCameraStatus] = useState('connecting');

  const gamepadConnected = useGamepadPresence();
  const reportControlError = useCallback(
    (error) => notify(`Error de control: ${error.message}`),
    [notify],
  );
  useGamepad(manualMode, gamepadMode, maxSpeed, setMaxSpeed, reportControlError);
  const { pressedKeys } = useKeyboard(true, maxSpeed, reportControlError);
  const {
    leftController,
    rightController,
    isSupported,
    supportInfo,
    isSessionActive,
    xrStatus,
    vrInput,
    padCount,
    startSession: startXRSession,
    endSession: endXRSession,
  } = useVRDrive({
    enabled: vrMode,
    controlMode: vrControlMode,
    display: vrDisplay,
    maxSpeed,
    onError: reportControlError,
  });

  const activateVR = async () => {
    if (!(await activateVRMode())) return;
    const started = await startXRSession(vrDisplay);
    if (!started) {
      notify('No se pudo iniciar WebXR. El control VR seguirá disponible mediante Gamepad API.', 'info');
    }
  };

  const handleActivateManual = async () => {
    if (vrMode) await endXRSession().catch(reportControlError);
    await activateManual();
  };

  const handleStartAuto = async () => {
    if (vrMode) await endXRSession().catch(reportControlError);
    await startAuto();
  };

  const handleStop = async () => {
    await endXRSession().catch(reportControlError);
    await stop();
  };

  const dispatchKey = (type, key) => {
    window.dispatchEvent(new KeyboardEvent(type, { key, bubbles: true }));
  };

  return (
    <div className="app-shell" data-theme="dark">
      <DashboardHeader status={status} />
      <VehicleStatus
        status={status}
        maxSpeed={maxSpeed}
        gamepadConnected={gamepadConnected}
        xrSupported={isSupported}
        cameraStatus={cameraStatus}
      />
      <ToastRegion toast={toast} onDismiss={dismiss} />

      <main className="dashboard-layout">
        <section className="camera-column" aria-labelledby="camera-title">
          <div className="section-heading">
            <div className="section-icon"><Camera size={18} /></div>
            <div>
              <p className="eyebrow">VISIÓN EN DIRECTO</p>
              <h2 id="camera-title">Cámara del vehículo</h2>
            </div>
            <span className={`live-indicator ${cameraStatus === 'error' ? 'camera-offline' : ''}`}>
              <span /> {cameraStatus === 'connected' ? 'EN VIVO' : cameraStatus === 'error' ? 'SIN SEÑAL' : 'CONECTANDO'}
            </span>
          </div>

          <div className="camera-panel">
            <CameraFeed onStatusChange={setCameraStatus} />
          </div>

          <div className="camera-footer">
            <span><Radio size={14} /> DeepRacer · Transmisión MJPEG</span>
            <span>Vista remota</span>
          </div>
        </section>

        <aside className="control-column" aria-label="Controles del vehículo">
          <ControlPanel
            loading={loading}
            status={status}
            manualMode={manualMode}
            vrMode={vrMode}
            onStartAuto={handleStartAuto}
            onStop={handleStop}
            onActivateManual={handleActivateManual}
            onActivateVR={activateVR}
            gamepadConnected={gamepadConnected}
            gamepadMode={gamepadMode}
            onGamepadModeChange={setGamepadMode}
            maxSpeed={maxSpeed}
            onSpeedChange={setMaxSpeed}
            pressedKeys={pressedKeys}
            onKeyPress={(key) => dispatchKey('keydown', key)}
            onKeyRelease={(key) => dispatchKey('keyup', key)}
            vrControlMode={vrControlMode}
            onVRControlModeChange={setVrControlMode}
            vrDisplay={vrDisplay}
            onVRDisplayChange={setVrDisplay}
            vrInput={vrInput}
            leftController={leftController}
            rightController={rightController}
            isSupported={isSupported}
            supportInfo={supportInfo}
            isSessionActive={isSessionActive}
            xrStatus={xrStatus}
            padCount={padCount}
          />
        </aside>
      </main>
    </div>
  );
}

export default App;
