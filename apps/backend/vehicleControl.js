// apps/backend/vehicleControl.js
import https from "https";
import dotenv from "dotenv";
import path from "path";
import { fileURLToPath } from "url";
import { URLSearchParams } from "url";

const __dirname = path.dirname(fileURLToPath(import.meta.url));
dotenv.config({ path: path.resolve(__dirname, "../../.env") });

// ===================== CONFIG =====================
const HOST = process.env.DEEPRACER_HOST;
const PORT = process.env.DEEPRACER_API_PORT;
const LOGIN_PATH = "/login";
const PASSWORD = process.env.DEEPRACER_API_PASSWORD;
const keepAliveAgent = new https.Agent({
  keepAlive: true,
  maxSockets: 4,
  rejectUnauthorized: false,
});

// Extraído para no repetir la cadena en múltiples lugares
const USER_AGENT = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/148.0.0.0 Safari/537.36";


// ===================== HELPERS =====================
function requestOnce(options, body = null) {
  return new Promise((resolve, reject) => {
    const req = https.request(options, (res) => {
      let data = "";
      res.on("data", (chunk) => (data += chunk));
      res.on("end", () => resolve({ res, data }));
    });
    req.on("error", reject);
    if (body) req.write(body);
    req.end();
  });
}

function cookieHeaderFromSetCookie(setCookieArray) {
  if (!setCookieArray || !setCookieArray.length) return "";
  return setCookieArray.map((c) => c.split(";")[0]).join("; ");
}

// ===================== LOGIN Y CSRF =====================
async function findCsrf() {
  const getOpts = {
    hostname: HOST,
    port: PORT,
    path: LOGIN_PATH,
    method: "GET",
    agent: keepAliveAgent,
    rejectUnauthorized: false,
    headers: { Accept: "text/html", "User-Agent": USER_AGENT },
  };
  
  const { res: getRes, data: html } = await requestOnce(getOpts);
  const setCookie = getRes.headers["set-cookie"] || [];
  const csrfMatch = html && (html.match(/name=["']csrf_token["']\s+value=["']([^"']+)["']/i) || html.match(/<meta[^>]*name=["']csrf-token["'][^>]*content=["']([^"']+)["'][^>]*>/i));
  
  return { csrf: csrfMatch ? csrfMatch[1] : null, setCookie };
}

async function authenticate() {
  const { csrf, setCookie } = await findCsrf();
  if (!csrf) return { csrf: null, cookieHeader: cookieHeaderFromSetCookie(setCookie) };

  const cookieHeader = cookieHeaderFromSetCookie(setCookie);
  const form = new URLSearchParams({ csrf_token: csrf, password: PASSWORD }).toString();

  const postOpts = {
    hostname: HOST,
    port: PORT,
    path: LOGIN_PATH,
    method: "POST",
    agent: keepAliveAgent,
    rejectUnauthorized: false,
    headers: {
      "Content-Type": "application/x-www-form-urlencoded",
      "Content-Length": Buffer.byteLength(form),
      Cookie: cookieHeader,
      "User-Agent": USER_AGENT,
      "X-CSRF-Token": csrf,
    },
  };

  const { res: postRes } = await requestOnce(postOpts, form);
  const allCookies = [...setCookie, ...(postRes.headers["set-cookie"] || [])];
  
  return { csrf, cookieHeader: cookieHeaderFromSetCookie(allCookies) };
}

// ===================== SESSION =====================
let session = null;

async function ensureSession() {
  if (!session) session = await authenticate();
  return session;
}

export async function initSession() {
  session = await authenticate();
}

// ===================== PUT JSON =====================
async function putJson(path, jsonObj) {
  let { csrf, cookieHeader } = await ensureSession();
  const jsonData = JSON.stringify(jsonObj);

  const opts = {
    hostname: HOST,
    port: PORT,
    path,
    method: "PUT",
    agent: keepAliveAgent,
    rejectUnauthorized: false,
    headers: {
      Accept: "*/*",
      "Accept-Language": "es,es-ES;q=0.9,en;q=0.8",
      "Content-Type": "application/json;charset=UTF-8",
      "Content-Length": Buffer.byteLength(jsonData),
      Origin: `https://${HOST}`,
      Referer: `https://${HOST}/home`,
      "X-Requested-With": "XMLHttpRequest",
      Cookie: cookieHeader,
      "User-Agent": USER_AGENT,
      ...(csrf ? { "X-CSRF-Token": csrf } : {}),
    },
  };

  const assertOk = (response) => {
    const status = response.res.statusCode;
    if (status === 401 || status === 403) {
      throw new Error("Session expired");
    }
    if (status < 200 || status >= 300) {
      throw new Error(`DeepRacer ${path} respondio HTTP ${status}: ${response.data}`);
    }
    return response;
  };

  try {
    return assertOk(await requestOnce(opts, jsonData));
  } catch (err) {
    console.warn("⚠️ Error con sesión actual, reautenticando...");
    session = await authenticate();
    
    const retryOpts = {
      ...opts,
      headers: {
        ...opts.headers,
        Cookie: session.cookieHeader,
        ...(session.csrf ? { "X-CSRF-Token": session.csrf } : {}),
      },
    };
    
    return assertOk(await requestOnce(retryOpts, jsonData));
  }
}

// ===================== ACCIONES =====================
export async function startVehicle() {
  console.log("▶️ Poniendo drive_mode = manual ...");
  await putJson("/api/drive_mode", { drive_mode: "manual" });

  console.log("▶️ Poniendo start_stop = start ...");
  await putJson("/api/start_stop", { start_stop: "start" });

  console.log("✅ Vehículo listo.");
}

export async function stopVehicle() {
  console.log("🛑 Enviando start_stop = stop ...");
  await putJson("/api/start_stop", { start_stop: "stop" });
  console.log("✅ Vehículo detenido.");
}

// ===================== CALIBRACIÓN DE THROTTLE (zona muerta) =====================
// Los consumidores envían throttle normalizado [-1, 1]: 0 = parada, |v| > 0 = movimiento.
// Este robot tiene una zona muerta (~|0.5|): valores entre 0 y ~0.5 NO mueven los
// motores (verificado en vivo 2026-07-31: 0.45 no mueve, 0.50 sí).
// Esta capa estira el rango (0, 1] al intervalo real [THROTTLE_DEAD_ZONE, 1]
// preservando el signo (dirección) y el 0 (parada explícita del watchdog).
// Configurable vía env THROTTLE_DEAD_ZONE (por defecto 0.5; sube con batería baja).
const THROTTLE_DEAD_ZONE = Math.max(0, Math.min(0.95, parseFloat(process.env.THROTTLE_DEAD_ZONE || "0.5")));

// ===================== CALIBRACIÓN DE DIRECCIÓN (trim del servo) =====================
// Compensa la deriva de dirección: con angle=0 este robot gira ~4.4° a la derecha
// por cada ~1.9 m (verificado 2026-07-31: 14.5 cm de desvío en 190.5 cm de avance).
// STRAIGHT_ANGLE_OFFSET se SUMA al ángulo del consumidor (negativo = compensa deriva
// a la derecha; ej. -0.11). Configurable vía env (valor inicial) y en vivo vía
// POST /api/calibration (setCalibration). Por defecto 0 (sin trim).
let straightAngleOffset = Math.max(-1, Math.min(1, parseFloat(process.env.STRAIGHT_ANGLE_OFFSET || "0")));

export function calibrateAngle(angle) {
  const a = Math.max(-1, Math.min(1, angle));
  return Math.max(-1, Math.min(1, a + straightAngleOffset));
}

export function setCalibration({ angleOffset } = {}) {
  if (typeof angleOffset === "number" && Number.isFinite(angleOffset)) {
    straightAngleOffset = Math.max(-1, Math.min(1, angleOffset));
  }
  return getCalibration();
}

export function getCalibration() {
  return {
    straightAngleOffset,
    throttleDeadZone: THROTTLE_DEAD_ZONE,
  };
}

export function calibrateThrottle(throttle) {
  const sign = Math.sign(throttle);
  const mag = Math.min(Math.abs(throttle), 1);
  if (mag < 1e-6) return 0;
  const real = THROTTLE_DEAD_ZONE + (1 - THROTTLE_DEAD_ZONE) * mag;
  return sign * Math.min(real, 1);
}

export async function manualDrive(angle, throttle, max_speed) {
  const a = calibrateAngle(angle);
  const t = calibrateThrottle(throttle);
  const m = Math.max(0, Math.min(1, max_speed));

  await putJson("/api/manual_drive", { angle: a, throttle: t, max_speed: m });
}

// ===================== VIDEO STREAM =====================
export async function getVideoStream() {
  let { csrf, cookieHeader } = await ensureSession();

  return new Promise((resolve, reject) => {
    const opts = {
      hostname: HOST,
      port: PORT,
      path: "/route?topic=/camera_pkg/display_mjpeg&width=480&height=360",
      method: "GET",
      agent: keepAliveAgent,
      rejectUnauthorized: false,
      headers: {
        Accept: "image/avif,image/webp,image/apng,image/*,*/*;q=0.8",
        "Cache-Control": "no-cache",
        Connection: "keep-alive",
        Cookie: cookieHeader,
        "User-Agent": USER_AGENT,
        ...(csrf ? { "X-CSRF-Token": csrf } : {}),
      },
    };

    const req = https.request(opts, (res) => {
      if (res.statusCode === 401 || res.statusCode === 403) {
        console.warn("⚠️ Sesión expirada, reautenticando…");
        authenticate()
          .then(() => getVideoStream().then(resolve).catch(reject))
          .catch(reject);
        return;
      }

      if (res.statusCode !== 200) {
        return reject(new Error(`Error obteniendo stream: ${res.statusCode}`));
      }

      resolve(res);
    });

    req.on("error", reject);
    req.end();
  });
}
