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
  // Etapa de la sesión para el panel de diagnóstico (legible al salir del casco).
  const [xrStatus, setXrStatus] = useState("idle");
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
  const glRef = useRef(null);
  // Lo que el HUD dentro del casco muestra (App lo actualiza cada render).
  const hudRef = useRef({ mode: "triggers", steering: 0, throttle: 0 });

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

  const startSession = useCallback(async (display = "vr") => {
    if (!navigator.xr) {
      console.error("WebXR not available");
      setXrStatus("sin navigator.xr (¿HTTP?)");
      return false;
    }

    try {
      // AR primero solo si se pide: passthrough del cuarto, sin streaming.
      const order = display === "ar"
        ? ["immersive-ar", "immersive-vr"]
        : ["immersive-vr", "immersive-ar"];
      let sessionType = null;
      for (const t of order) {
        if (await navigator.xr.isSessionSupported(t).catch(() => false)) {
          sessionType = t;
          break;
        }
      }

      if (!sessionType) {
        console.log('🥽 WebXR: No immersive session type supported');
        setXrStatus("sin sesión inmersiva (vr/ar no soportado)");
        return false;
      }
      const isAR = sessionType === "immersive-ar";

      console.log(`🥽 WebXR: Starting ${sessionType} session...`);
      setXrStatus(`pidiendo ${sessionType}…`);
      const session = await navigator.xr.requestSession(sessionType, {
        optionalFeatures: ['local-floor', 'bounded-floor', 'hand-tracking']
      });

      sessionRef.current = session;
      setIsSessionActive(true);
      setXrStatus("sesión ok · montando GL…");
      console.log("✅ WebXR session started");

      session.addEventListener("end", () => {
        console.log("🥽 WebXR: Session ended");
        sessionRef.current = null;
        setXrStatus("sesión terminada");
        try { glRef.current?.getExtension("WEBGL_lose_context")?.loseContext(); } catch { /* noop */ }
        glRef.current = null;
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

      // Reference space para el frame loop
      const refSpace = await session.requestReferenceSpace('local-floor').catch(() =>
        session.requestReferenceSpace('local')
      );

      // Render mínimo: una sesión inmersiva SIN capa WebGL queda en negro.
      // Dibujamos la cámara del robot + un HUD (modo, gatillos, mando).
      const useProxy = import.meta.env.VITE_API_PROXY === "1";
      const awsHost = import.meta.env.VITE_AWS_HOST || "localhost";
      const camUrl = useProxy
        ? "/video/stream?topic=/camera_pkg/display_mjpeg&width=480&height=360&quality=85"
        : `http://${awsHost}:8080/stream?topic=/camera_pkg/display_mjpeg&width=480&height=360&quality=85`;
      // En AR no se carga la cámara: ves el cuarto directo (cero lag,
      // máxima nitidez) y solo flota el HUD.
      const camImg = new Image();
      if (!isAR) camImg.src = camUrl;
      const hudCanvas = document.createElement("canvas");
      hudCanvas.width = 512;
      hudCanvas.height = 168;
      const hud2d = hudCanvas.getContext("2d");

      let gl = null;
      let xrLayer = null;
      let texProg = null;
      let quadBuf = null;
      let camTex = null;
      let hudTex = null;
      try {
        const canvas = document.createElement("canvas");
        gl = canvas.getContext("webgl", { xrCompatible: true });
        if (!gl) throw new Error("WebGL no disponible");
        await gl.makeXRCompatible();
        xrLayer = new XRWebGLLayer(session, gl);
        session.updateRenderState({ baseLayer: xrLayer });
        texProg = initTexProgram(gl);
        quadBuf = initQuad(gl);
        camTex = initTexture(gl);
        hudTex = initTexture(gl);
        gl.disable(gl.DEPTH_TEST);
        gl.enable(gl.BLEND);
        gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);
        glRef.current = gl;
      } catch (e) {
        console.warn("🥽 XR sin render (el casco puede quedar en negro):", e?.message);
        setXrStatus("sesión ok · GL FALLÓ: " + (e?.message || "error"));
        gl = null;
      }

      let lastPushL = "";
      let lastPushR = "";
      let lastPushT = 0;
      let lastHudDraw = 0;
      let lastL = null;
      let lastR = null;
      let frames = 0;
      let poses = 0;
      let draws = 0;

      const onFrame = (time, frame) => {
        if (!sessionRef.current) return;
        session.requestAnimationFrame(onFrame);
        const srcs = frame ? frame.session.inputSources : session.inputSources;

        for (const source of srcs) {
          if (!source.gamepad) continue;

          const { handedness, gamepad } = source;
          const { axes, buttons } = gamepad;

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

          const key = `${controllerData.stickX.toFixed(2)}|${controllerData.stickY.toFixed(2)}|${controllerData.trigger.toFixed(2)}|${controllerData.triggerPressed}|${controllerData.gripPressed}`;

          if (handedness === "left") {
            lastL = controllerData;
            if (key !== lastPushL || time - lastPushT > 150) {
              lastPushL = key;
              setLeftController(controllerData);
            }
          } else if (handedness === "right") {
            lastR = controllerData;
            if (key !== lastPushR || time - lastPushT > 150) {
              lastPushR = key;
              setRightController(controllerData);
            }
          }
        }
        if (time - lastPushT > 150) lastPushT = time;

        if (gl && xrLayer && frame) {
          try {
            if (time - lastHudDraw > 400) {
              lastHudDraw = time;
              drawHud(hud2d, hudCanvas, hudRef.current, lastL, lastR);
            }
            uploadTex(gl, camTex, camImg);
            uploadTex(gl, hudTex, hudCanvas);
            const pose = frame.getViewerPose(refSpace);
            gl.bindFramebuffer(gl.FRAMEBUFFER, xrLayer.framebuffer);
            if (isAR) {
              // Fondo transparente: pasa el passthrough del Quest.
              gl.clearColor(0, 0, 0, 0);
            } else {
              gl.clearColor(0.02, 0.02, 0.04, 1.0);
            }
            gl.clear(gl.COLOR_BUFFER_BIT);
            frames++;
            if (pose) {
              poses++;
              // Letterbox por ojo: encuadre completo sin estirar ni recortar.
              const tw = camImg.naturalWidth || 480;
              const th = camImg.naturalHeight || 360;
              for (const view of pose.views) {
                const vp = xrLayer.getViewport(view);
                gl.viewport(vp.x, vp.y, vp.width, vp.height);
                const viewA = vp.width / Math.max(1, vp.height);
                const texA = tw / Math.max(1, th);
                let rect = [0, 0, 1, 1];
                if (viewA > texA) {
                  const w = texA / viewA;
                  rect = [(1 - w) / 2, 0, w, 1];
                } else {
                  const h = viewA / texA;
                  rect = [0, (1 - h) / 2, 1, h];
                }
                if (!isAR) drawQuad(gl, texProg, quadBuf, camTex, rect);
                // HUD flotante en ambos modos (en AR, sobre el passthrough)
                drawQuad(gl, texProg, quadBuf, hudTex, [0.05, 0.02, 0.9, 0.26]);
                draws++;
              }
            }
            if (frames % 90 === 0) {
              setXrStatus(`frames=${frames} poses=${poses} draws=${draws}`);
            }
          } catch {
            // Un frame malo no tumba la sesión
          }
        }
      };

      session.requestAnimationFrame(onFrame);
      setXrStatus(gl ? "sesión ok · GL ok · esperando frames…" : "sesión ok · SIN GL (negro esperado)");
      return true;
    } catch (e) {
      console.error("Error starting WebXR session:", e);
      setXrStatus("falló sesión: " + (e?.message || "error"));
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
    xrStatus,
    leftController,
    rightController,
    hudRef,
    startSession,
    endSession,
  };
}

// --- Render mínimo para la sesión inmersiva (cámara + HUD) ---

function compileShader(gl, type, src) {
  const sh = gl.createShader(type);
  gl.shaderSource(sh, src);
  gl.compileShader(sh);
  if (!gl.getShaderParameter(sh, gl.COMPILE_STATUS)) {
    throw new Error("shader: " + gl.getShaderInfoLog(sh));
  }
  return sh;
}

function initTexProgram(gl) {
  const vs = `attribute vec2 aPos; attribute vec2 aUV; varying vec2 vUV; uniform vec4 uRect;
    void main(){ vec2 ndc = (aPos * uRect.zw + uRect.xy) * 2.0 - 1.0; gl_Position = vec4(ndc, 0.0, 1.0); vUV = aUV; }`;
  const fs = `precision mediump float; varying vec2 vUV; uniform sampler2D uTex;
    void main(){ gl_FragColor = texture2D(uTex, vUV); }`;
  const prog = gl.createProgram();
  gl.attachShader(prog, compileShader(gl, gl.VERTEX_SHADER, vs));
  gl.attachShader(prog, compileShader(gl, gl.FRAGMENT_SHADER, fs));
  gl.linkProgram(prog);
  if (!gl.getProgramParameter(prog, gl.LINK_STATUS)) {
    throw new Error("link: " + gl.getProgramInfoLog(prog));
  }
  return {
    prog,
    aPos: gl.getAttribLocation(prog, "aPos"),
    aUV: gl.getAttribLocation(prog, "aUV"),
    uRect: gl.getUniformLocation(prog, "uRect"),
    uTex: gl.getUniformLocation(prog, "uTex"),
  };
}

function initQuad(gl) {
  // TRIANGLE_STRIP: (0,0) (1,0) (0,1) (1,1), con UVs (flipY se hace al subir)
  const buf = gl.createBuffer();
  gl.bindBuffer(gl.ARRAY_BUFFER, buf);
  gl.bufferData(gl.ARRAY_BUFFER, new Float32Array([
    0, 0, 0, 0,
    1, 0, 1, 0,
    0, 1, 0, 1,
    1, 1, 1, 1,
  ]), gl.STATIC_DRAW);
  return buf;
}

function initTexture(gl) {
  const tex = gl.createTexture();
  gl.bindTexture(gl.TEXTURE_2D, tex);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
  // Pixel 1x1 mientras llega la imagen real
  gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, 1, 1, 0, gl.RGBA, gl.UNSIGNED_BYTE,
    new Uint8Array([2, 2, 6, 255]));
  return tex;
}

function uploadTex(gl, tex, src) {
  if (!src) return;
  if (src instanceof HTMLImageElement && (!src.complete || !src.naturalWidth)) return;
  gl.bindTexture(gl.TEXTURE_2D, tex);
  gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
  gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, src);
}

function drawQuad(gl, P, buf, tex, rect) {
  gl.useProgram(P.prog);
  gl.bindBuffer(gl.ARRAY_BUFFER, buf);
  gl.enableVertexAttribArray(P.aPos);
  gl.vertexAttribPointer(P.aPos, 2, gl.FLOAT, false, 16, 0);
  gl.enableVertexAttribArray(P.aUV);
  gl.vertexAttribPointer(P.aUV, 2, gl.FLOAT, false, 16, 8);
  gl.activeTexture(gl.TEXTURE0);
  gl.bindTexture(gl.TEXTURE_2D, tex);
  gl.uniform1i(P.uTex, 0);
  gl.uniform4f(P.uRect, rect[0], rect[1], rect[2], rect[3]);
  gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
}

function drawHud(ctx, canvas, hud, L, R) {
  const W = canvas.width;
  const H = canvas.height;
  ctx.clearRect(0, 0, W, H);
  ctx.fillStyle = "rgba(0,0,0,0.55)";
  ctx.fillRect(0, 0, W, H);
  ctx.fillStyle = "#ffffff";
  ctx.font = "bold 26px monospace";
  const mode = hud?.mode === "joystick" ? "JOYSTICK" : "GATILLOS";
  ctx.fillText(`${hud?.display === "ar" ? "AR" : "VR"} ${mode}  dir=${(hud?.steering ?? 0).toFixed(0)} ace=${(hud?.throttle ?? 0).toFixed(0)}`, 16, 36);
  ctx.font = "22px monospace";
  ctx.fillText(`L trg=${(L?.trigger ?? 0).toFixed(2)} stk=(${(L?.stickX ?? 0).toFixed(2)},${(L?.stickY ?? 0).toFixed(2)})`, 16, 72);
  ctx.fillText(`R trg=${(R?.trigger ?? 0).toFixed(2)} stk=(${(R?.stickX ?? 0).toFixed(2)},${(R?.stickY ?? 0).toFixed(2)})`, 16, 104);
  ctx.fillStyle = "#9fd8ff";
  ctx.fillText(hud?.mode === "joystick" ? "stick = marcha, grip/A = freno" : "RT acelera, LT frena/reversa", 16, 140);
}
