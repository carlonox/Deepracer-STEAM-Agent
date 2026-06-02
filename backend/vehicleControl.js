// backend/vehicleControl.js
import https from "https";
import dotenv from "dotenv";
import { URLSearchParams } from "url";

dotenv.config();

// ===================== CONFIG =====================
const HOST = process.env.HOST;
const PORT = process.env.AWS_PORT;
const LOGIN_PATH = "/login";
const PASSWORD = process.env.PASSWORD;

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

// ===================== POST / PUT JSON =====================
async function postJson(path, jsonObj) {
  let { csrf, cookieHeader } = await ensureSession();
  const jsonData = JSON.stringify(jsonObj);

  const opts = {
    hostname: HOST,
    port: PORT,
    path,
    method: "PUT", // Mantenemos PUT porque el original lo exigía así
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

  try {
    const response = await requestOnce(opts, jsonData);
    if (response.res.statusCode === 401 || response.res.statusCode === 403) {
      throw new Error("Session expired");
    }
    return response;
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
    
    return await requestOnce(retryOpts, jsonData);
  }
}

// ===================== ACCIONES =====================
export async function startVehicle() {
  console.log("▶️ Poniendo drive_mode = manual ...");
  await postJson("/api/drive_mode", { drive_mode: "manual" });

  console.log("▶️ Poniendo start_stop = start ...");
  await postJson("/api/start_stop", { start_stop: "start" });

  console.log("✅ Vehículo listo.");
}

export async function stopVehicle() {
  console.log("🛑 Enviando start_stop = stop ...");
  await postJson("/api/start_stop", { start_stop: "stop" });
  console.log("✅ Vehículo detenido.");
}

export async function manualDrive(angle, throttle, max_speed) {
  const a = Math.max(-1, Math.min(1, angle));
  const t = Math.max(-1, Math.min(1, throttle));
  const m = Math.max(0, Math.min(1, max_speed));

  await postJson("/api/manual_drive", { angle: a, throttle: t, max_speed: m });
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