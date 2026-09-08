/**
 * API Service for vehicle control
 */

const API_PORT = 5002;

// Con VITE_API_PROXY=1 (p. ej. frontend en HTTPS y backend en HTTP) las
// llamadas van al mismo origen (/api/...) y vite las proxea al backend.
// Sin el flag, comportamiento original: http://<host>:5002/api/...
const USE_PROXY = import.meta.env.VITE_API_PROXY === "1";

/**
 * Make a POST request to the vehicle API.
 *
 * Anti-lag (red saturada del aula): los acelerones son lossy con
 * latest-wins y un solo vuelo a la vez; el STOP es prioritario
 * (aborta lo en vuelo, vacía la cola y reintenta hasta ACK).
 * @param {string} path - API endpoint path
 * @param {object} body - Request body
 * @returns {Promise<object|null>} Response data or null on error
 */
let flightCtrl = null;
let queuedThrottle = null;
let pumping = false;
const FETCH_TIMEOUT_MS = 1500;
const STOP_RETRIES = 8;
const STOP_RETRY_MS = 150;

async function postRaw(url, body, signal) {
  const res = await fetch(url, {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(body),
    signal,
  });
  const data = await res.json().catch(() => ({}));
  if (!res.ok) throw new Error(data.error || res.statusText);
  return data;
}

function timeoutSignal(ms, outer) {
  const ctrl = new AbortController();
  const t = setTimeout(() => ctrl.abort(new Error("timeout")), ms);
  const done = () => clearTimeout(t);
  if (outer) {
    if (outer.aborted) ctrl.abort(outer.reason);
    else outer.addEventListener("abort", () => { done(); ctrl.abort(outer.reason); }, { once: true });
  }
  return { signal: ctrl.signal, done };
}

async function pumpThrottles() {
  if (pumping) return;
  pumping = true;
  try {
    while (queuedThrottle) {
      const job = queuedThrottle;
      queuedThrottle = null;
      flightCtrl = new AbortController();
      const ts = timeoutSignal(FETCH_TIMEOUT_MS, flightCtrl.signal);
      try {
        await postRaw(job.url, job.body, ts.signal);
      } catch (err) {
        if (err?.name !== "AbortError") console.error("API error:", err);
      } finally {
        ts.done();
        flightCtrl = null;
      }
    }
  } finally {
    pumping = false;
  }
}

function isStopLike(path, body) {
  if (path === "stop") return true;
  return (
    path === "manual_drive" &&
    !body.init &&
    Number(body.angle) === 0 &&
    Number(body.throttle) === 0
  );
}

export const apiPost = async (path, body = {}) => {
  try {
    const apiHost = window.location.hostname;
    const url = USE_PROXY
      ? `/api/${path}`
      : `http://${apiHost}:${API_PORT}/api/${path}`;

    if (isStopLike(path, body)) {
      // El stop salta la cola: aborta, vacía y reintenta hasta ACK.
      try { flightCtrl?.abort(); } catch { /* noop */ }
      queuedThrottle = null;
      let lastErr = new Error("stop no confirmado");
      for (let i = 0; i < STOP_RETRIES; i++) {
        const ts = timeoutSignal(FETCH_TIMEOUT_MS);
        try {
          const data = await postRaw(url, body, ts.signal);
          ts.done();
          return data;
        } catch (err) {
          ts.done();
          lastErr = err;
          await new Promise((r) => setTimeout(r, STOP_RETRY_MS));
        }
      }
      throw lastErr;
    }

    if (body.init || path === "start") {
      const ts = timeoutSignal(FETCH_TIMEOUT_MS);
      try {
        return await postRaw(url, body, ts.signal);
      } finally {
        ts.done();
      }
    }

    // Acelerón: latest-wins, fire-and-forget (el pump manda de a uno).
    queuedThrottle = { url, body };
    pumpThrottles();
    return null;
  } catch (err) {
    console.error("API error:", err);
    throw err;
  }
};

/**
 * Start autonomous mode
 */
export const startAutoMode = async () => {
  return await apiPost("start");
};

/**
 * Stop the vehicle
 */
export const stopVehicle = async () => {
  return await apiPost("stop");
};

/**
 * Initialize manual control mode
 */
export const activateManualMode = async () => {
  return await apiPost("manual_drive", { init: true });
};

/**
 * Send manual drive command
 * @param {number} angle - Steering angle (-45 to 45)
 * @param {number} throttle - Throttle (-100 to 100)
 * @param {number} maxSpeed - Maximum speed (0.1 to 1.0)
 */
export const sendManualCommand = async (angle, throttle, maxSpeed) => {
  return await apiPost("manual_drive", {
    angle: Math.round(angle),
    throttle: Math.round(throttle),
    max_speed: maxSpeed,
  });
};
