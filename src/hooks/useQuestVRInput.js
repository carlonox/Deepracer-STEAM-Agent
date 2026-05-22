import { useState, useRef, useCallback, useEffect } from "react";

export default function useQuestVRInput() {
  const [isSupported, setIsSupported] = useState(null); // null = checking, true/false = result
  const [supportInfo, setSupportInfo] = useState({
    hasNavigatorXR: false,
    immersiveVR: false,
    immersiveAR: false,
    inline: false,
    userAgent: "",
    error: null
  });
  const [isSessionActive, setIsSessionActive] = useState(false);
  const [leftController, setLeftController] = useState({
    stickX: 0,
    stickY: 0,
    trigger: 0,
    triggerPressed: false,
    grip: 0,
    gripPressed: false,
    buttonA: false,
    buttonB: false,
  });
  const [rightController, setRightController] = useState({
    stickX: 0,
    stickY: 0,
    trigger: 0,
    triggerPressed: false,
    grip: 0,
    gripPressed: false,
    buttonA: false,
    buttonB: false,
  });

  const sessionRef = useRef(null);

  // Check WebXR support on mount
  useEffect(() => {
    const checkSupport = async () => {
      const info = {
        hasNavigatorXR: !!navigator.xr,
        immersiveVR: false,
        immersiveAR: false,
        inline: false,
        userAgent: navigator.userAgent,
        error: null
      };

      if (!navigator.xr) {
        info.error = "navigator.xr no existe";
        setSupportInfo(info);
        setIsSupported(false);
        return;
      }

      try {
        // Check all session types
        info.immersiveVR = await navigator.xr.isSessionSupported("immersive-vr").catch(() => false);
        info.immersiveAR = await navigator.xr.isSessionSupported("immersive-ar").catch(() => false);
        info.inline = await navigator.xr.isSessionSupported("inline").catch(() => false);

        setSupportInfo(info);
        setIsSupported(info.immersiveVR || info.immersiveAR);
      } catch (e) {
        console.error("Error checking WebXR support:", e);
        info.error = e.message;
        setSupportInfo(info);
        setIsSupported(false);
      }
    };

    // Small delay to ensure browser is ready
    setTimeout(checkSupport, 100);
  }, []);

  const startSession = useCallback(async () => {
    if (!navigator.xr) {
      console.error("WebXR not available");
      return false;
    }

    try {
      // Try immersive-vr first, then immersive-ar
      let sessionType = "immersive-vr";
      let supported = await navigator.xr.isSessionSupported(sessionType);

      if (!supported) {
        sessionType = "immersive-ar";
        supported = await navigator.xr.isSessionSupported(sessionType);
      }

      if (!supported) {
        console.log('🥽 WebXR: No immersive session type supported');
        return false;
      }

      console.log(`🥽 WebXR: Starting ${sessionType} session...`);
      const session = await navigator.xr.requestSession(sessionType, {
        optionalFeatures: ['local-floor', 'bounded-floor', 'hand-tracking']
      });

      sessionRef.current = session;
      setIsSessionActive(true);
      console.log("✅ WebXR session started");

      session.addEventListener("end", () => {
        console.log("🥽 WebXR: Session ended");
        sessionRef.current = null;
        setIsSessionActive(false);
        setLeftController({
          stickX: 0, stickY: 0, trigger: 0, triggerPressed: false,
          grip: 0, gripPressed: false, buttonA: false, buttonB: false,
        });
        setRightController({
          stickX: 0, stickY: 0, trigger: 0, triggerPressed: false,
          grip: 0, gripPressed: false, buttonA: false, buttonB: false,
        });
      });

      // Need a reference space for the frame loop
      const refSpace = await session.requestReferenceSpace('local-floor').catch(() =>
        session.requestReferenceSpace('local')
      );

      const onFrame = (time, frame) => {
        if (!sessionRef.current) return;

        for (const source of session.inputSources) {
          if (!source.gamepad) continue;

          const { handedness, gamepad } = source;
          const { axes, buttons } = gamepad;

          // Debug first few frames
          if (time < 5000) {
            console.log(`Controller ${handedness}:`, { axes, buttons: buttons.map(b => ({ pressed: b.pressed, value: b.value })) });
          }

          const controllerData = {
            stickX: axes[2] ?? axes[0] ?? 0,
            stickY: axes[3] ?? axes[1] ?? 0,
            trigger: buttons[0]?.value ?? 0,
            triggerPressed: buttons[0]?.pressed ?? false,
            grip: buttons[1]?.value ?? 0,
            gripPressed: buttons[1]?.pressed ?? false,
            buttonA: buttons[4]?.pressed ?? false,
            buttonB: buttons[5]?.pressed ?? false,
          };

          // Log significant controller input
          if (Math.abs(controllerData.stickX) > 0.1 || Math.abs(controllerData.stickY) > 0.1 || 
              controllerData.triggerPressed || controllerData.gripPressed || 
              controllerData.buttonA || controllerData.buttonB) {
            console.log(`🥽 ${handedness} Controller: Stick(${controllerData.stickX.toFixed(2)}, ${controllerData.stickY.toFixed(2)}) Trigger=${controllerData.triggerPressed} Grip=${controllerData.gripPressed} A=${controllerData.buttonA} B=${controllerData.buttonB}`);
          }

          if (handedness === "left") {
            setLeftController(controllerData);
          } else if (handedness === "right") {
            setRightController(controllerData);
          }
        }

        session.requestAnimationFrame(onFrame);
      };

      session.requestAnimationFrame(onFrame);
      return true;
    } catch (e) {
      console.error("Error starting WebXR session:", e);
      return false;
    }
  }, []);

  const endSession = useCallback(async () => {
    if (sessionRef.current) {
      await sessionRef.current.end();
      sessionRef.current = null;
      setIsSessionActive(false);
    }
  }, []);

  return {
    isSupported,
    supportInfo,
    isSessionActive,
    leftController,
    rightController,
    startSession,
    endSession,
  };
}
