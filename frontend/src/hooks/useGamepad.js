import { useState, useEffect, useRef } from 'react';
import { sendManualCommand } from '../services/vehicleApi';

/**
 * Custom hook for gamepad control
 * @param {boolean} enabled - Whether gamepad control is enabled
 * @param {string} mode - Control mode: 'joystick' or 'triggers'
 * @param {number} maxSpeed - Maximum speed value
 * @param {function} onSpeedChange - Callback to change speed (optional)
 * @returns {object} Gamepad state and controls
 */
export default function useGamepad(enabled, mode, maxSpeed, onSpeedChange) {
  const [isConnected, setIsConnected] = useState(false);
  const gamepadIndexRef = useRef(null);
  const animationIdRef = useRef(null);
  const lastCommandRef = useRef({ angle: 0, throttle: 0 });
  const lastBumperStateRef = useRef({ lb: false, rb: false });
  const lastButtonStateRef = useRef({ l3: false, r3: false, a: false, b: false, x: false, y: false });

  const AXIS_DEAD_ZONE = 0.15;
  const TRIGGER_DEAD_ZONE = 0.05;
  const SPEED_STEP = 0.05;

  useEffect(() => {
    const stopVehicle = async () => {
      await sendManualCommand(0, 0, maxSpeed);
    };
    if (!enabled) return;

    const handleConnect = (e) => {
      console.log('🎮 Control conectado - Modo:', mode);
      gamepadIndexRef.current = e.gamepad.index;
      setIsConnected(true);
      if (!animationIdRef.current) {
        startUpdateLoop();
      }
    };

    const handleDisconnect = () => {
      console.log('❌ Control desconectado');
      gamepadIndexRef.current = null;
      setIsConnected(false);
      if (animationIdRef.current) {
        cancelAnimationFrame(animationIdRef.current);
        animationIdRef.current = null;
      }
      stopVehicle();
    };

    const startUpdateLoop = () => {
      const update = () => {
        if (gamepadIndexRef.current === null) {
          animationIdRef.current = null;
          return;
        }

        const gp = navigator.getGamepads()[gamepadIndexRef.current];
        if (!gp) {
          animationIdRef.current = null;
          return;
        }

        let angle = 0;
        let throttle = 0;

        // D-PAD control (priority)
        const dpadUp = gp.buttons[12]?.pressed || false;
        const dpadDown = gp.buttons[13]?.pressed || false;
        const dpadLeft = gp.buttons[14]?.pressed || false;
        const dpadRight = gp.buttons[15]?.pressed || false;

        if (dpadUp || dpadDown || dpadLeft || dpadRight) {
          console.log(`🎮 D-PAD: Up=${dpadUp} Down=${dpadDown} Left=${dpadLeft} Right=${dpadRight}`);
          if (dpadUp && dpadRight) {
            angle = 45;
            throttle = -100;
          } else if (dpadUp && dpadLeft) {
            angle = -45;
            throttle = -100;
          } else if (dpadDown && dpadRight) {
            angle = 45;
            throttle = 100;
          } else if (dpadDown && dpadLeft) {
            angle = -45;
            throttle = 100;
          } else if (dpadUp) {
            throttle = -100;
          } else if (dpadDown) {
            throttle = 100;
          } else if (dpadLeft) {
            angle = -45;
            throttle = -100;
          } else if (dpadRight) {
            angle = 45;
            throttle = -100;
          }
        } else if (mode === 'joystick') {
          // Joystick mode
          const axisX = gp.axes[0];
          const axisY = gp.axes[1];

          if (Math.abs(axisX) > AXIS_DEAD_ZONE || Math.abs(axisY) > AXIS_DEAD_ZONE) {
            console.log(`🎮 Joystick Axis: X=${axisX.toFixed(2)} Y=${axisY.toFixed(2)}`);
          }

          if (Math.abs(axisX) > AXIS_DEAD_ZONE) {
            angle = axisX * 45;
          }

          if (Math.abs(axisY) > AXIS_DEAD_ZONE) {
            throttle = axisY * 100;
          }
        } else if (mode === 'triggers') {
          // Triggers mode
          const rightTrigger = gp.buttons[7]?.value || 0;
          const leftTrigger = gp.buttons[6]?.value || 0;
          const axisX = gp.axes[0];

          if (rightTrigger > TRIGGER_DEAD_ZONE || leftTrigger > TRIGGER_DEAD_ZONE) {
            console.log(`🎮 Triggers: RT=${rightTrigger.toFixed(2)} LT=${leftTrigger.toFixed(2)}`);
          }

          if (rightTrigger > TRIGGER_DEAD_ZONE) {
            throttle = -rightTrigger * 100;
          } else if (leftTrigger > TRIGGER_DEAD_ZONE) {
            throttle = leftTrigger * 100;
          }

          if (Math.abs(axisX) > AXIS_DEAD_ZONE) {
            angle = axisX * 45;
          }
        }

        // LB (button 4) and RB (button 5) for speed control
        const lbPressed = gp.buttons[4]?.pressed || false;
        const rbPressed = gp.buttons[5]?.pressed || false;

        if (onSpeedChange) {
          // RB increases speed (on press, not hold)
          if (rbPressed && !lastBumperStateRef.current.rb) {
            console.log(`🎮 RB pressed: Speed ${maxSpeed.toFixed(2)} -> ${Math.min(1, maxSpeed + SPEED_STEP).toFixed(2)}`);
            onSpeedChange(Math.min(1, maxSpeed + SPEED_STEP));
          }
          // LB decreases speed (on press, not hold)
          if (lbPressed && !lastBumperStateRef.current.lb) {
            console.log(`🎮 LB pressed: Speed ${maxSpeed.toFixed(2)} -> ${Math.max(0.1, maxSpeed - SPEED_STEP).toFixed(2)}`);
            onSpeedChange(Math.max(0.1, maxSpeed - SPEED_STEP));
          }
        }
        lastBumperStateRef.current = { lb: lbPressed, rb: rbPressed };

        // L3 (button 10) and R3 (button 11) - Joystick press
        const l3Pressed = gp.buttons[10]?.pressed || false;
        const r3Pressed = gp.buttons[11]?.pressed || false;
        
        if (l3Pressed && !lastButtonStateRef.current.l3) {
          console.log('🎮 L3 pressed (Left Stick Click)');
        }
        if (r3Pressed && !lastButtonStateRef.current.r3) {
          console.log('🎮 R3 pressed (Right Stick Click)');
        }

        // A (button 0), B (button 1), X (button 2), Y (button 3)
        const aPressed = gp.buttons[0]?.pressed || false;
        const bPressed = gp.buttons[1]?.pressed || false;
        const xPressed = gp.buttons[2]?.pressed || false;
        const yPressed = gp.buttons[3]?.pressed || false;

        if (aPressed && !lastButtonStateRef.current.a) {
          console.log('🎮 A button pressed');
        }
        if (bPressed && !lastButtonStateRef.current.b) {
          console.log('🎮 B button pressed');
        }
        if (xPressed && !lastButtonStateRef.current.x) {
          console.log('🎮 X button pressed');
        }
        if (yPressed && !lastButtonStateRef.current.y) {
          console.log('🎮 Y button pressed');
        }

        lastButtonStateRef.current = { l3: l3Pressed, r3: r3Pressed, a: aPressed, b: bPressed, x: xPressed, y: yPressed };

        // Send command if changed significantly
        const angleDiff = Math.abs(angle - lastCommandRef.current.angle);
        const throttleDiff = Math.abs(throttle - lastCommandRef.current.throttle);

        if (
          angleDiff > 2 ||
          throttleDiff > 5 ||
          (angle === 0 &&
            throttle === 0 &&
            (lastCommandRef.current.angle !== 0 || lastCommandRef.current.throttle !== 0))
        ) {
          console.log(`🎮 Gamepad: Angle=${angle.toFixed(1)}° Throttle=${throttle.toFixed(1)}% Mode=${mode}`);
          lastCommandRef.current = { angle, throttle };
          sendManualCommand(angle, throttle, maxSpeed);
        }

        animationIdRef.current = requestAnimationFrame(update);
      };

      requestAnimationFrame(update);
    };

    window.addEventListener('gamepadconnected', handleConnect);
    window.addEventListener('gamepaddisconnected', handleDisconnect);

    // Check for already connected gamepad
    const gamepads = navigator.getGamepads();
    for (let i = 0; i < gamepads.length; i++) {
      if (gamepads[i]) {
        gamepadIndexRef.current = i;
        setIsConnected(true);
        console.log('🎮 Gamepad ya conectado - Modo:', mode);
        startUpdateLoop();
        break;
      }
    }

    return () => {
      window.removeEventListener('gamepadconnected', handleConnect);
      window.removeEventListener('gamepaddisconnected', handleDisconnect);
      if (animationIdRef.current) {
        cancelAnimationFrame(animationIdRef.current);
      }
      if (gamepadIndexRef.current !== null) {
        stopVehicle();
      }
    };
  }, [enabled, mode, maxSpeed]);

  return { isConnected };
}
