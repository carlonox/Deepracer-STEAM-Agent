import { useState, useEffect, useRef } from 'react';
import { sendManualCommand } from '../services/api/vehicleApi';
import { getKeyboardCommand } from '../shared/utils/vehicleCommands';

/**
 * Custom hook for keyboard control
 * @param {boolean} enabled - Whether keyboard control is enabled
 * @param {number} maxSpeed - Maximum speed value
 * @returns {object} Keyboard state
 */
export default function useKeyboard(enabled, maxSpeed, onError) {
  const [pressedKeys, setPressedKeys] = useState(new Set());
  const activeKeysRef = useRef(new Set());

  useEffect(() => {
    if (!enabled) return;

    // Guardar la referencia al inicio del efecto
    const activeKeys = activeKeysRef.current;

    const handleKeyDown = async (e) => {
      if (activeKeys.has(e.key)) return;
      activeKeys.add(e.key);
      setPressedKeys(new Set(activeKeys));

      const { angle, throttle } = getKeyboardCommand(activeKeys);
      if (angle !== 0 || throttle !== 0) {
        sendManualCommand(angle, throttle, maxSpeed).catch((error) => onError?.(error));
      }
    };

    const handleKeyUp = async (e) => {
      activeKeys.delete(e.key);
      setPressedKeys(new Set(activeKeys));

      if (activeKeys.size > 0) {
        const { angle, throttle } = getKeyboardCommand(activeKeys);
        sendManualCommand(angle, throttle, maxSpeed).catch((error) => onError?.(error));
      } else {
        sendManualCommand(0, 0, maxSpeed).catch((error) => onError?.(error));
      }
    };
    const handleBlur = async () => {
      activeKeys.clear();
      setPressedKeys(new Set());
      sendManualCommand(0, 0, maxSpeed).catch((error) => onError?.(error));
    };

    const handleVisibilityChange = async () => {
      if (document.hidden) {
        activeKeys.clear();
        setPressedKeys(new Set());
        sendManualCommand(0, 0, maxSpeed).catch((error) => onError?.(error));
      }
    };

    window.addEventListener('keydown', handleKeyDown);
    window.addEventListener('keyup', handleKeyUp);
    window.addEventListener('blur', handleBlur);
    document.addEventListener('visibilitychange', handleVisibilityChange);

    return () => {
      window.removeEventListener('keydown', handleKeyDown);
      window.removeEventListener('keyup', handleKeyUp);
      window.removeEventListener('blur', handleBlur);
      document.removeEventListener('visibilitychange', handleVisibilityChange);
      activeKeys.clear();
      sendManualCommand(0, 0, maxSpeed).catch((error) => onError?.(error));
    };
  }, [enabled, maxSpeed, onError]);

  return { pressedKeys };
}
