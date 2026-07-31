// move_debug.js
import http from "http";
import https from "https";
import dotenv from "dotenv";
import path from "path";
import { fileURLToPath } from "url";
import { URLSearchParams } from "url";

//////// CONFIG ////////
const __dirname = path.dirname(fileURLToPath(import.meta.url));
dotenv.config({ path: path.resolve(__dirname, "../.env") });
const HOST = process.env.DEEPRACER_HOST;
const PORT = Number(process.env.DEEPRACER_API_PORT || 5001);
const USE_HTTPS = process.env.DEEPRACER_API_HTTPS !== "false";
const LOGIN_PATH = "/login";
const PASSWORD = process.env.DEEPRACER_API_PASSWORD;
const MOVE_DURATION_MS = 5000;
const MOVE_INTERVAL_MS = 100;
const MAX_RETRIES = 3;
////////////////////////

const CLIENT = USE_HTTPS ? https : http;

const COLORS = {
  reset: "\x1b[0m",
  red: "\x1b[31m",
  green: "\x1b[32m",
  yellow: "\x1b[33m",
  cyan: "\x1b[36m",
};
const log = {
  i: (m) => console.log(`${COLORS.cyan}â„¹ï¸ ${m}${COLORS.reset}`),
  s: (m) => console.log(`${COLORS.green}âœ… ${m}${COLORS.reset}`),
  w: (m) => console.log(`${COLORS.yellow}âš ï¸ ${m}${COLORS.reset}`),
  e: (m) => console.error(`${COLORS.red}âŒ ${m}${COLORS.reset}`),
};

function sleep(ms) { return new Promise(r => setTimeout(r, ms)); }

function mergeCookies(existing, newSetCookies) {
  const parsed = {};
  (existing || []).forEach(c => {
    const [pair] = c.split(";");
    const [k, v] = pair.split("=");
    parsed[k] = v;
  });
  (newSetCookies || []).forEach(raw => {
    const [pair] = raw.split(";");
    const idx = pair.indexOf("=");
    if (idx > 0) {
      const k = pair.slice(0, idx);
      const v = pair.slice(idx + 1);
      parsed[k] = v;
    }
  });
  return Object.entries(parsed).map(([k, v]) => `${k}=${v}`);
}

function cookieHeaderFromSetCookie(setCookieArray) {
  if (!setCookieArray) return "";
  // setCookieArray expected as ["k=v; ...", "k2=v2; ..."]
  return setCookieArray.map((c) => c.split(";")[0]).join("; ");
}

function short(str, n = 200) {
  if (!str) return "";
  return str.length > n ? str.slice(0, n) + "..." : str;
}

function extractCsrfFromHtml(html) {
  if (!html) return null;
  const patterns = [
    /name=["']csrf_token["']\s+value=["']([^"']+)["']/i,
    /value=["']([^"']+)["']\s+name=["']csrf_token["']/i,
    /name=["']csrfmiddlewaretoken["']\s+value=["']([^"']+)["']/i,
    /name=["']_csrf["']\s+value=["']([^"']+)["']/i,
    /<meta[^>]*name=["']csrf-token["'][^>]*content=["']([^"']+)["'][^>]*>/i,
    /window\.__CSRF_TOKEN__\s*=\s*["']([^"']+)["']/i,
    /"csrf_token"\s*:\s*"([^"]+)"/i,
  ];
  for (const r of patterns) {
    const m = html.match(r);
    if (m && m[1]) return m[1];
  }
  return null;
}

function base64UrlDecode(str) {
  if (!str) return null;
  str = str.replace(/-/g, "+").replace(/_/g, "/");
  const pad = 4 - (str.length % 4);
  if (pad !== 4) str += "=".repeat(pad);
  try { return Buffer.from(str, "base64").toString("utf8"); } catch { return null; }
}

function extractCsrfFromSessionCookie(setCookieArray) {
  if (!setCookieArray?.length) return null;
  for (const raw of setCookieArray) {
    const m = raw.match(/\bsession=([^;]+)/);
    if (!m) continue;
    const parts = m[1].split(".");
    if (!parts[0]) continue;
    const decoded = base64UrlDecode(parts[0]);
    if (!decoded) continue;
    try {
      const obj = JSON.parse(decoded);
      const keys = ["csrf_token", "csrf", "_csrf", "csrfmiddlewaretoken"];
      for (const k of keys) if (obj[k]) return obj[k];
      for (const v of Object.values(obj)) {
        if (typeof v === "object") for (const k of keys) if (v[k]) return v[k];
      }
    } catch {
      const r = decoded.match(/csrf[_-]?token["']?\s*[:=]\s*["']([^"']+)["']/i);
      if (r && r[1]) return r[1];
    }
  }
  return null;
}

/** requestOnce: hace la peticiÃ³n y sigue 1 redirect si viene Location */
function requestOnce(options, body = null, followRedirectsLeft = 3) {
  return new Promise((resolve, reject) => {
    const req = CLIENT.request(options, (res) => {
      let data = "";
      res.on("data", (chunk) => (data += chunk));
      res.on("end", async () => {
        const setCookie = res.headers["set-cookie"] || [];
        // si hay redirect y followRedirectsLeft>0, hacer nueva peticiÃ³n
        if ((res.statusCode === 301 || res.statusCode === 302 || res.statusCode === 307 || res.statusCode === 308)
            && res.headers.location && followRedirectsLeft > 0) {
          // construir nueva path desde location (si es absoluto o relativo)
          const loc = res.headers.location;
          const newPath = loc.startsWith("http") ? new URL(loc).pathname + (new URL(loc).search || "") : loc;
          const newOptions = {
            ...options,
            path: newPath,
            headers: { ...(options.headers || {}), Cookie: cookieHeaderFromSetCookie(setCookie) || options.headers?.Cookie },
            method: "GET", // follow redirect with GET
          };
          log.w(`Redirect ${res.statusCode} -> ${newPath}. Seguir redirect (${followRedirectsLeft - 1} left).`);
          try {
            const r2 = await requestOnce(newOptions, null, followRedirectsLeft - 1);
            // combinar cookies entre la primera y la siguiente
            r2.setCookie = mergeCookies(setCookie, r2.setCookie || []);
            resolve(r2);
            return;
          } catch (err) {
            reject(err);
            return;
          }
        }

        resolve({ res, data, setCookie });
      });
    });
    req.on("error", (err) => reject(new Error(`Error de red: ${err.message}`)));
    if (body) req.write(body);
    req.end();
  });
}

async function findCsrf() {
  log.i(`Solicitando ${LOGIN_PATH} para detectar CSRF...`);
  const getOpts = {
    hostname: HOST,
    port: PORT,
    path: LOGIN_PATH,
    method: "GET",
    headers: { Accept: "text/html", "User-Agent": "Node-CSRF-Detector" },
  };
  const { res, data, setCookie } = await requestOnce(getOpts);
  log.i(`GET ${LOGIN_PATH} => ${res.statusCode}`);
  const csrf = extractCsrfFromHtml(data) || extractCsrfFromSessionCookie(setCookie);
  if (!csrf) {
    log.w("No se encontrÃ³ CSRF en HTML ni en cookies. Muestra truncada de respuesta:");
    console.log(short(data, 800));
  } else {
    log.s(`CSRF detectado inicial: ${csrf.substring(0, 12)}...`);
  }
  return { csrf, setCookie: setCookie || [] };
}

async function loginAndExecute() {
  try {
    let { csrf, setCookie } = await findCsrf();
    if (!csrf) throw new Error("No se pudo obtener token CSRF del login inicial.");

    let cookieJar = mergeCookies([], setCookie); // array like ["k=v"]
    log.i(`Cookies iniciales: ${cookieHeaderFromSetCookie(cookieJar) || "(ninguna)"}`);

    const form = new URLSearchParams({ csrf_token: csrf, password: PASSWORD }).toString();
    const postOpts = {
      hostname: HOST,
      port: PORT,
      path: LOGIN_PATH,
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded",
        "Content-Length": Buffer.byteLength(form),
        Cookie: cookieHeaderFromSetCookie(cookieJar),
        "User-Agent": "Node-CSRF-Detector",
        "X-CSRF-Token": csrf,
        "X-Requested-With": "XMLHttpRequest",
      },
    };

    const { res: postRes, data: postBody, setCookie: postSetCookie } = await requestOnce(postOpts, form);
    log.i(`POST ${LOGIN_PATH} => ${postRes.statusCode}`);
    log.i(`Respuesta login (trunc): ${short(postBody, 400)}`);

    if (postRes.statusCode >= 400) {
      throw new Error(`Login fallÃ³: ${postRes.statusCode} ${short(postBody, 400)}`);
    }

    // Merge cookies after login
    cookieJar = mergeCookies(cookieJar, postSetCookie);
    log.s(`Login OK. Cookies ahora: ${cookieHeaderFromSetCookie(cookieJar)}`);

    // Intenta extraer CSRF nuevo si el body lo trae
    const newCsrfFromBody = extractCsrfFromHtml(postBody) || (function(){
      try {
        const j = JSON.parse(postBody || "{}");
        if (j && (j.csrf || j.csrf_token)) return j.csrf || j.csrf_token;
      } catch {}
      return null;
    })();
    if (newCsrfFromBody) {
      csrf = newCsrfFromBody;
      log.i(`CSRF actualizado desde respuesta del login: ${csrf.substring(0,12)}...`);
    } else {
      const cookieBased = extractCsrfFromSessionCookie(postSetCookie || []);
      if (cookieBased) {
        csrf = cookieBased;
        log.i(`CSRF actualizado desde cookie de sesiÃ³n: ${csrf.substring(0,12)}...`);
      }
    }

    async function postJson(path, jsonObj, attempt = 1) {
      const jsonData = JSON.stringify(jsonObj);
      const opts = {
        hostname: HOST,
        port: PORT,
        path,
        method: "POST",
        headers: {
          "Content-Type": "application/json",
          "Content-Length": Buffer.byteLength(jsonData),
          Cookie: cookieHeaderFromSetCookie(cookieJar),
          "User-Agent": "Node-CSRF-Detector",
          "X-CSRF-Token": csrf,
          "X-Requested-With": "XMLHttpRequest",
        },
      };
      try {
        const { res, data, setCookie: respSetCookie } = await requestOnce(opts, jsonData);
        log.i(`POST ${path} => ${res.statusCode} (${short(data,120)})`);
        if (respSetCookie && respSetCookie.length) {
          cookieJar = mergeCookies(cookieJar, respSetCookie);
          log.i(`Cookies actualizadas tras ${path}: ${cookieHeaderFromSetCookie(cookieJar)}`);
        }
        // intenta actualizar csrf si aparece en respuesta
        const maybe = extractCsrfFromHtml(data) || (function(){
          try { const j = JSON.parse(data || "{}"); return j?.csrf || j?.csrf_token || null; } catch { return null; }
        })();
        if (maybe) {
          csrf = maybe;
          log.i(`CSRF actualizado desde respuesta de ${path}: ${csrf.substring(0,12)}...`);
        }

        if (res.statusCode >= 400) {
          throw new Error(`Status ${res.statusCode} en ${path}: ${short(data,200)}`);
        }
        return { res, data };
      } catch (err) {
        if (attempt < MAX_RETRIES) {
          log.w(`Error en ${path}: ${err.message}. Reintentando (${attempt + 1}/${MAX_RETRIES})...`);
          await sleep(200 * attempt);
          return postJson(path, jsonObj, attempt + 1);
        }
        throw err;
      }
    }

    // pasos: drive_mode -> start -> movimiento contÃ­nuo -> stop
    log.i("Activando modo manual...");
    await postJson("/api/drive_mode", { drive_mode: "manual" });

    log.i("Iniciando start_stop (start)...");
    await postJson("/api/start_stop", { start_stop: "start" });

    log.i("Enviando movimiento continuo...");
    const start = Date.now();
    while (Date.now() - start < MOVE_DURATION_MS) {
      try {
        const { data } = await postJson("/api/manual_drive", {
          angle: 0.0,
          throttle: 0.6,
          max_speed: 1.0,
        });
        // opcional: revisar si la respuesta contiene un campo que indique estado (ej. {"ok": true})
        try {
          const j = JSON.parse(data || "{}");
          if (j && j.error) log.w(`Respuesta de manual_drive contiene error: ${j.error}`);
        } catch {}
      } catch (err) {
        log.w(`Fallo al enviar comando de movimiento: ${err.message}`);
      }
      await sleep(MOVE_INTERVAL_MS);
    }

    log.i("Deteniendo (start_stop: stop)...");
    await postJson("/api/start_stop", { start_stop: "stop" });
    log.s("Movimiento finalizado correctamente.");
  } catch (err) {
    log.e(err.stack || err.message || String(err));
  }
}

loginAndExecute();
