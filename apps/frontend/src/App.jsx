import { useState } from 'react';
import { Camera, Radio } from 'lucide-react';
import CameraFeed from './components/camera/CameraFeed';
import ControlPanel from './components/dashboard/ControlPanel';
import DashboardHeader from './components/dashboard/DashboardHeader';
import useGamepad from './hooks/useGamepad';
import useKeyboard from './hooks/useKeyboard';
import useVehicleControl from './hooks/useVehicleControl';
import useVRDrive from './hooks/useVRDrive';
import { activateManualMode } from './services/vehicleApi';
import './styles/dashboard.css';

function App() {
  const { loading, status, manualMode, setManualMode, startAuto, stop, activateManual } = useVehicleControl();
  const [maxSpeed, setMaxSpeed] = useState(0.5);
  const [gamepadMode, setGamepadMode] = useState('joystick');
  const [vrMode, setVrMode] = useState(false);
  const [vrControlMode, setVrControlMode] = useState('triggers');
  const [vrDisplay, setVrDisplay] = useState('vr');

  const { isConnected: gamepadConnected } = useGamepad(manualMode, gamepadMode, maxSpeed, setMaxSpeed);
  const { pressedKeys } = useKeyboard(true, maxSpeed);
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
  } = useVRDrive({ enabled: vrMode, controlMode: vrControlMode, display: vrDisplay, maxSpeed });

  const activateVR = async () => {
    setManualMode(false);
    setVrMode(true);

    try {
      await activateManualMode();
    } catch (error) {
      console.error('Error initializing VR mode:', error);
    }

    try {
      await startXRSession(vrDisplay);
    } catch (error) {
      console.error('Error starting XR session:', error);
    }
  };

  const handleActivateManual = async () => {
    setVrMode(false);
    await activateManual();
  };

  const handleStop = async () => {
    setVrMode(false);
    try {
      await endXRSession();
    } catch (error) {
      console.error('Error ending XR session:', error);
    }
    await stop();
  };

  const dispatchKey = (type, key) => {
    window.dispatchEvent(new KeyboardEvent(type, { key, bubbles: true }));
  };

  return (
    <div className="app-shell" data-theme="dark">
      <DashboardHeader status={status} />

      <main className="dashboard-layout">
        <section className="camera-column" aria-labelledby="camera-title">
          <div className="section-heading">
            <div className="section-icon"><Camera size={18} /></div>
            <div>
              <p className="eyebrow">VISIÓN EN DIRECTO</p>
              <h2 id="camera-title">Cámara del vehículo</h2>
            </div>
            <span className="live-indicator"><span /> EN VIVO</span>
          </div>

          <div className="camera-panel">
            <CameraFeed />
          </div>

          <div className="camera-footer">
            <span><Radio size={14} /> DeepRacer · Transmisión MJPEG</span>
            <span>Vista remota</span>
          </div>
        </section>

        <aside className="control-column" aria-label="Controles del vehículo">
          <ControlPanel
            loading={loading}
            manualMode={manualMode}
            vrMode={vrMode}
            onStartAuto={startAuto}
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
