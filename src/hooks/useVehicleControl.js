import { useState } from 'react';
import { startAutoMode, stopVehicle, activateManualMode } from '../services/vehicleApi';

/**
 * Custom hook for vehicle control operations
 * @returns {object} Vehicle control functions and state
 */
export default function useVehicleControl() {
  const [loading, setLoading] = useState(false);
  const [status, setStatus] = useState('Detenido');
  const [manualMode, setManualMode] = useState(false);

  const startAuto = async () => {
    setLoading(true);
    try {
      await startAutoMode();
      setStatus('Automático activo');
      setManualMode(false);
    } catch (error) {
      alert('Error al iniciar modo automático: ' + error.message);
    } finally {
      setLoading(false);
    }
  };

  const stop = async () => {
    setLoading(true);
    try {
      await stopVehicle();
      setStatus('Detenido');
      setManualMode(false);
    } catch (error) {
      alert('Error al detener vehículo: ' + error.message);
    } finally {
      setLoading(false);
    }
  };

  const activateManual = async () => {
    setLoading(true);
    try {
      await activateManualMode();
      setManualMode(true);
      setStatus('Control manual activo');
    } catch (error) {
      alert('Error al activar modo manual: ' + error.message);
    } finally {
      setLoading(false);
    }
  };

  return {
    loading,
    status,
    manualMode,
    setManualMode,
    startAuto,
    stop,
    activateManual,
  };
}
