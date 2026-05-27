// backend/vehicleControl.js
import http from "http";
import https from "https";
import dotenv from "dotenv";
import { URLSearchParams } from "url";

dotenv.config();

// ===================== CONFIG =====================
const USE_HTTPS = false;
const CLIENT = USE_HTTPS ? https : http;
const HOST = process.env.HOST || "localhost"; // dirección del servidor del vehículo
const PORT = process.env.AWS_PORT || 5001; // puerto del servidor del vehículo
const LOGIN_PATH = "/login";
const PASSWORD = process.env.PASSWORD;
// Nota: ya no usamos MOVE_INTERVAL_MS / MOVE_DURATION_MS en startVehicle
// porque NO queremos que startVehicle provoque movimiento por sí mismo.

// ===================== HELPERS =====================
function requestOnce(options, body = null) {
  return new Promise((resolve, reject) => {
    const req = CLIENT.request(options, (res) => {
      let data = "";
      res.on("data", (chunk) => (data += chunk));
      res.on("end", () => resolve({ res, data }));
    });
    req.on("error", (err) => reject(err));
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
    headers: { Accept: "text/html", "User-Agent": "Node-CSRF-Detector" },
  };
  const { res: getRes, data: html } = await requestOnce(getOpts);
  const setCookie = getRes.headers["set-cookie"] || [];
  // intenta extraer CSRF (si hay)
  const csrfMatch = html && (html.match(/name=["']csrf_token["']\s+value=["']([^"']+)["']/i) || html.match(/<meta[^>]*name=["']csrf-token["'][^>]*content=["']([^"']+)["'][^>]*>/i));
  const csrf = csrfMatch ? csrfMatch[1] : null;
  return { csrf, setCookie };
}

async function authenticate() {
  const { csrf, setCookie } = await findCsrf();
  if (!csrf) {
    // Si no existe CSRF tal vez el servidor no lo requiere: igual devolvemos cookies
    return { csrf: null, cookieHeader: cookieHeaderFromSetCookie(setCookie) };
  }

  const cookieHeader = cookieHeaderFromSetCookie(setCookie);
  const form = new URLSearchParams({ csrf_token: csrf, password: PASSWORD }).toString();

  const postOpts = {
    hostname: HOST,
    port: PORT,
    path: LOGIN_PATH,
    method: "POST",
    headers: {
      "Content-Type": "application/x-www-form-urlencoded",
      "Content-Length": Buffer.byteLength(form),
      Cookie: cookieHeader,
      "User-Agent": "Node-CSRF-Detector",
      "X-CSRF-Token": csrf,
    },
  };

  const { res: postRes } = await requestOnce(postOpts, form);
  const postSetCookie = postRes.headers["set-cookie"] || [];
  const allCookies = [...setCookie, ...postSetCookie];
  return { csrf, cookieHeader: cookieHeaderFromSetCookie(allCookies) };
}


// sesión guardada
let session = null;

async function ensureSession() {
  // si la sesión expiró, reautenticar
  if (!session) session = await authenticate();
  return session;
}

export async function initSession() {
  session = await authenticate();
}


async function postJson(path, jsonObj) {
  let { csrf, cookieHeader } = await ensureSession();
  const jsonData = JSON.stringify(jsonObj);

  const opts = {
    hostname: HOST,
    port: PORT,
    path,
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "Content-Length": Buffer.byteLength(jsonData),
      Cookie: cookieHeader,
      "User-Agent": "Node-CSRF-Detector",
      ...(csrf ? { "X-CSRF-Token": csrf } : {}),
    },
  };

  try {
    return await requestOnce(opts, jsonData);
  } catch (err) {
    console.warn("⚠️ Error con sesión actual, reautenticando...", err);
    session = await authenticate();    // renovar
    csrf = session.csrf;
    cookieHeader = session.cookieHeader;

    // reintentar
    const retryOpts = {
      ...opts,
      headers: {
        ...opts.headers,
        Cookie: cookieHeader,
        ...(csrf ? { "X-CSRF-Token": csrf } : {}),
      },
    };

    return await requestOnce(retryOpts, jsonData);
  }
}


// ===================== ACCIONES =====================

// startVehicle: SOLO prepara vehículo (modo manual y habilita start), NO envía movimiento
export async function startVehicle() {
  console.log("▶️ Poniendo drive_mode = manual ...");
  await postJson("/api/drive_mode", { drive_mode: "manual" });

  console.log("▶️ Poniendo start_stop = start ...");
  await postJson("/api/start_stop", { start_stop: "start" });

  console.log("✅ Vehículo listo (no hay movimiento automático).");
}

// stopVehicle: para el vehículo
export async function stopVehicle() {
  console.log("🛑 Enviando start_stop = stop ...");
  await postJson("/api/start_stop", { start_stop: "stop" });
  console.log("✅ Vehículo detenido.");
}

// manualDrive: envía valores ya normalizados en [-1,1] para angle y throttle, max_speed 0..1
export async function manualDrive(angle, throttle, max_speed) {
  // En este punto asumimos que `angle` y `throttle` ya están en [-1,1] y max_speed en [0,1]
  // Si no lo están, el backend/vehicle server rechazará.
  // Hacemos una validación ligera por si acaso:
  const a = Math.max(-1, Math.min(1, angle));
  const t = Math.max(-1, Math.min(1, throttle));
  const m = Math.max(0, Math.min(1, max_speed));

  await postJson("/api/manual_drive", { angle: a, throttle: t, max_speed: m });
}

export async function getVideoStream() {
  let { csrf, cookieHeader } = await ensureSession();

  return new Promise((resolve, reject) => {
    const opts = {
      hostname: "10.203.139.55",
      port: 443,
      path: "/route?topic=/camera_pkg/display_mjpeg&width=480&height=360",
      method: "GET",
      rejectUnauthorized: false, // IMPORTANTE: certificado inseguro
      headers: {
        Accept: "image/avif,image/webp,image/apng,image/*,*/*;q=0.8",
        "Cache-Control": "no-cache",
        Connection: "keep-alive",
        Cookie: cookieHeader,    // mantener sesión
        "User-Agent": "Mozilla/5.0",
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
        return reject(
          new Error(`Error obteniendo stream: ${res.statusCode}`)
        );
      }

      resolve(res); // devolvemos el stream directo
    });

    req.on("error", reject);
    req.end();
  });
}
