import { useState } from 'react';
import {
  activateManualMode,
  startAutoMode,
  stopVehicle,
} from '../../services/api/vehicleApi';

const MODE_STATUS = {
  stopped: 'Detenido',
  auto: 'Automático activo',
  manual: 'Control manual activo',
  vr: 'Control VR activo',
};

export default function useVehicleControl(notify) {
  const [mode, setMode] = useState('stopped');
  const [loading, setLoading] = useState(false);

  const runAction = async (action, nextMode, errorMessage) => {
    setLoading(true);
    notify('Enviando comando al vehículo…', 'info');
    try {
      await action();
      setMode(nextMode);
      notify(`Estado del vehículo: ${MODE_STATUS[nextMode]}`, 'success');
      return true;
    } catch (error) {
      notify(`${errorMessage}: ${error.message}`);
      return false;
    } finally {
      setLoading(false);
    }
  };

  return {
    mode,
    status: MODE_STATUS[mode],
    loading,
    manualMode: mode === 'manual',
    vrMode: mode === 'vr',
    startAuto: () => runAction(startAutoMode, 'auto', 'No se pudo iniciar el modo automático'),
    stop: () => runAction(stopVehicle, 'stopped', 'No se pudo detener el vehículo'),
    activateManual: () => runAction(activateManualMode, 'manual', 'No se pudo activar el modo manual'),
    activateVR: () => runAction(activateManualMode, 'vr', 'No se pudo activar el control VR'),
  };
}
