import { useState, useEffect, useRef } from 'react';
import { sendManualCommand } from '../services/vehicleApi';

/**
 * Custom hook for keyboard control
 * @param {boolean} enabled - Whether keyboard control is enabled
 * @param {number} maxSpeed - Maximum speed value
 * @returns {object} Keyboard state
 */
export default function useKeyboard(enabled, maxSpeed) {
  const [pressedKeys, setPressedKeys] = useState(new Set());
  const activeKeysRef = useRef(new Set());

  const calculateCommand = (keys) => {
    let angle = 0;
    let throttle = 0;

    const isUp = keys.has('ArrowUp') || keys.has('w') || keys.has('W');
    const isDown = keys.has('ArrowDown') || keys.has('s') || keys.has('S');
    const isLeft = keys.has('ArrowLeft') || keys.has('a') || keys.has('A');
    const isRight = keys.has('ArrowRight') || keys.has('d') || keys.has('D');

    if (isUp && isRight) {
      angle = 45;
      throttle = -100;
    } else if (isUp && isLeft) {
      angle = -45;
      throttle = -100;
    } else if (isDown && isRight) {
      angle = 45;
      throttle = 100;
    } else if (isDown && isLeft) {
      angle = -45;
      throttle = 100;
    } else {
      if (isUp) throttle = -100;
      else if (isDown) throttle = 100;
      else if (isLeft) {
        angle = -45;
        throttle = 0;
      } else if (isRight) {
        angle = 45;
        throttle = 0;
      }
    }
    console.log(`⌨️ Calculated command from keys [${[...keys].join(', ')}]: Angle=${angle}° Throttle=${throttle}%`);
    return { angle, throttle };
  };

  useEffect(() => {
    if (!enabled) return;

    // Guardar la referencia al inicio del efecto
    const activeKeys = activeKeysRef.current;

    const handleKeyDown = async (e) => {
      if (activeKeys.has(e.key)) return;
      activeKeys.add(e.key);
      setPressedKeys(new Set(activeKeys));

      const { angle, throttle } = calculateCommand(activeKeys);
      console.log(`⌨️ KeyDown: ${e.key} | Keys: [${[...activeKeys].join(', ')}] | Angle=${angle}° Throttle=${throttle}%`);
      if (angle !== 0 || throttle !== 0) {
        await sendManualCommand(angle, throttle, maxSpeed);
      }
    };

    const handleKeyUp = async (e) => {
      activeKeys.delete(e.key);
      setPressedKeys(new Set(activeKeys));
      console.log(`⌨️ KeyUp: ${e.key} | Keys: [${[...activeKeys].join(', ')}]`);

      if (activeKeys.size > 0) {
        const { angle, throttle } = calculateCommand(activeKeys);
        await sendManualCommand(angle, throttle, maxSpeed);
      } else {
        await sendManualCommand(0, 0, maxSpeed);
      }
    };

    const handleBlur = async () => {
      console.log('⌨️ Window blur - clearing keys');
      activeKeys.clear();
      setPressedKeys(new Set());
      await sendManualCommand(0, 0, maxSpeed);
    };

    const handleVisibilityChange = async () => {
      if (document.hidden) {
        console.log('⌨️ Document hidden - clearing keys');
        activeKeys.clear();
        setPressedKeys(new Set());
        await sendManualCommand(0, 0, maxSpeed);
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
      sendManualCommand(0, 0, maxSpeed);
    };
  }, [enabled, maxSpeed]);

  return { pressedKeys };
}
