import { useCallback, useEffect, useRef, useState } from 'react';
import { sendManualCommand } from '../services/vehicleApi';
import useQuestVRInput from './useQuestVRInput';

export default function useVRDrive({ enabled, controlMode, display, maxSpeed }) {
  const xr = useQuestVRInput();
  const [vrInput, setVrInput] = useState({ steering: 0, throttle: 0 });
  const [padCount, setPadCount] = useState(0);
  const lastSendTime = useRef(0);
  const lastVRSent = useRef({ angle: 0, throttle: 0 });
  const stopTimers = useRef([]);
  const lastDriveRx = useRef(0);
  const lastVRFwd = useRef(false);

  useEffect(() => {
    xr.hudRef.current = {
      mode: controlMode,
      display,
      steering: vrInput.steering,
      throttle: vrInput.throttle,
    };
  }, [controlMode, display, vrInput, xr.hudRef]);

  const sendVRCommand = useCallback(async (dirX, dirY, forceStop = false) => {
    const now = Date.now();
    if (!forceStop && now - lastSendTime.current < 50) return;
    lastSendTime.current = now;

    const threshold = 12;
    const isUp = dirY < -threshold;
    const isDown = dirY > threshold;
    const isLeft = dirX < -threshold;
    const isRight = dirX > threshold;
    let angle = 0;
    let throttle = 0;

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
    } else if (isUp) {
      throttle = -100;
    } else if (isDown) {
      throttle = 100;
    } else if (isLeft) {
      angle = -45;
    } else if (isRight) {
      angle = 45;
    }

    if (angle !== 0 || throttle !== 0 || forceStop) {
      try {
        await sendManualCommand(angle, throttle, maxSpeed);
      } catch (error) {
        console.error('Error sending VR command:', error);
      }
    }
  }, [maxSpeed]);

  const sendVRStop = useCallback(() => {
    lastVRSent.current = { active: false };
    lastVRFwd.current = false;
    setVrInput({ steering: 0, throttle: 0 });
    sendVRCommand(0, 0, true);
    stopTimers.current.forEach(clearTimeout);
    stopTimers.current = [120, 350].map((ms) =>
      setTimeout(() => {
        sendManualCommand(0, 0, maxSpeed).catch((error) => {
          console.error('Error reinforcing VR stop:', error);
        });
      }, ms)
    );
  }, [maxSpeed, sendVRCommand]);

  useEffect(() => () => stopTimers.current.forEach(clearTimeout), []);

  useEffect(() => {
    if (!enabled) return undefined;
    const id = setInterval(() => {
      if (lastVRSent.current.active && Date.now() - lastDriveRx.current > 500) {
        sendVRStop();
      }
    }, 250);
    return () => clearInterval(id);
  }, [enabled, sendVRStop]);

  useEffect(() => {
    if (!enabled) return;
    const rt = xr.rightController?.trigger ?? 0;
    const lt = xr.leftController?.trigger ?? 0;
    const stickX = xr.rightController?.stickX || xr.leftController?.stickX || 0;
    const stickY = xr.rightController?.stickY || xr.leftController?.stickY || 0;
    const sX = Math.abs(stickX) >= 0.15 ? stickX : 0;
    const sY = Math.abs(stickY) >= 0.15 ? stickY : 0;
    const grip = Math.max(xr.rightController?.grip ?? 0, xr.leftController?.grip ?? 0);
    const btnA = xr.rightController?.buttonA || xr.leftController?.buttonA || false;
    let dirX = 0;
    let dirY = 0;
    let active = false;
    let brake = false;

    if (controlMode === 'joystick') {
      brake = grip > 0.3 || btnA;
      active = brake || Math.abs(stickX) >= 0.15 || Math.abs(stickY) >= 0.15;
      if (!active) {
        if (lastVRSent.current.active) sendVRStop();
        return;
      }
      dirX = brake ? 0 : sX * 20;
      dirY = brake ? 0 : sY * 20;
    } else {
      const rtOn = rt >= 0.08;
      const ltOn = lt >= 0.08;
      brake = grip > 0.3 || btnA || (ltOn && !rtOn && lastVRFwd.current);
      active = brake || rtOn || ltOn || Math.abs(stickX) >= 0.15;
      if (!active) {
        if (lastVRSent.current.active) sendVRStop();
        return;
      }
      dirX = brake ? 0 : sX * 20;
      dirY = brake ? 0 : (lt - rt) * 20;
    }

    lastVRSent.current = { active: true };
    lastDriveRx.current = Date.now();
    if (!brake) lastVRFwd.current = dirY < -12;
    setVrInput({ steering: dirX, throttle: dirY });
    if (brake) sendVRCommand(0, 0, true);
    else sendVRCommand(dirX, dirY);
  }, [
    enabled,
    controlMode,
    xr.leftController,
    xr.rightController,
    sendVRCommand,
    sendVRStop,
  ]);

  useEffect(() => {
    if (!enabled || xr.isSessionActive) return undefined;
    let raf = 0;
    const axisDeadZone = 0.15;
    const triggerDeadZone = 0.05;

    const loop = () => {
      const pads = navigator.getGamepads ? navigator.getGamepads() : [];
      setPadCount(Array.from(pads).filter((pad) => pad?.connected).length);
      const pad = Array.from(pads).find(
        (candidate) => candidate?.connected && (candidate.axes.length >= 2 || candidate.buttons.length >= 8)
      );

      if (pad) {
        let dirX = 0;
        let dirY = 0;
        let active = false;
        let brake = false;

        if (controlMode === 'joystick') {
          const axisX = pad.axes[0] ?? 0;
          const axisY = pad.axes[1] ?? 0;
          const x = Math.abs(axisX) >= axisDeadZone ? axisX : 0;
          const y = Math.abs(axisY) >= axisDeadZone ? axisY : 0;
          brake = pad.buttons[0]?.pressed || false;
          active = brake || x !== 0 || y !== 0;
          if (active) {
            dirX = brake ? 0 : x * 20;
            dirY = brake ? 0 : y * 20;
          }
        } else {
          const rightTrigger = pad.buttons[7]?.value ?? 0;
          const leftTrigger = pad.buttons[6]?.value ?? 0;
          const axisX = pad.axes[0] ?? 0;
          const x = Math.abs(axisX) >= axisDeadZone ? axisX : 0;
          const rtOn = rightTrigger > triggerDeadZone;
          const ltOn = leftTrigger > triggerDeadZone;
          brake = pad.buttons[0]?.pressed || (ltOn && !rtOn && lastVRFwd.current);
          active = brake || rtOn || ltOn || x !== 0;
          if (active) {
            dirX = brake ? 0 : x * 20;
            dirY = brake ? 0 : (leftTrigger - rightTrigger) * 20;
          }
        }

        if (!active) {
          if (lastVRSent.current.active) sendVRStop();
        } else {
          lastVRSent.current = { active: true };
          lastDriveRx.current = Date.now();
          if (!brake) lastVRFwd.current = dirY < -12;
          setVrInput({ steering: dirX, throttle: dirY });
          if (brake) sendVRCommand(0, 0, true);
          else sendVRCommand(dirX, dirY);
        }
      }

      raf = requestAnimationFrame(loop);
    };

    raf = requestAnimationFrame(loop);
    return () => cancelAnimationFrame(raf);
  }, [enabled, controlMode, xr.isSessionActive, sendVRCommand, sendVRStop]);

  return { ...xr, vrInput, padCount };
}
