import { useEffect, useState } from 'react';

export default function useGamepadPresence() {
  const [connected, setConnected] = useState(false);

  useEffect(() => {
    const update = () => {
      const pads = navigator.getGamepads?.() ?? [];
      setConnected(Array.from(pads).some((pad) => pad?.connected));
    };

    update();
    window.addEventListener('gamepadconnected', update);
    window.addEventListener('gamepaddisconnected', update);
    return () => {
      window.removeEventListener('gamepadconnected', update);
      window.removeEventListener('gamepaddisconnected', update);
    };
  }, []);

  return connected;
}
