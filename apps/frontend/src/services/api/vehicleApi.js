import { getApiUrl } from '../../config/frontend';

const FETCH_TIMEOUT_MS = 1500;
const STOP_RETRIES = 8;
const STOP_RETRY_MS = 150;

let activeThrottleController = null;
let queuedThrottle = null;
let pendingStops = 0;

async function request(url, body, signal) {
  const response = await fetch(url, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify(body),
    signal,
  });
  const data = await response.json().catch(() => ({}));
  if (!response.ok) throw new Error(data.error || response.statusText || `HTTP ${response.status}`);
  return data;
}

function timeoutSignal(ms, outerSignal) {
  const controller = new AbortController();
  const timer = setTimeout(() => controller.abort(new Error('timeout')), ms);
  const abort = () => controller.abort(outerSignal.reason);
  const done = () => {
    clearTimeout(timer);
    outerSignal?.removeEventListener('abort', abort);
  };

  if (outerSignal?.aborted) abort();
  else outerSignal?.addEventListener('abort', abort, { once: true });

  return { signal: controller.signal, done };
}

async function requestWithTimeout(url, body, outerSignal) {
  const timeout = timeoutSignal(FETCH_TIMEOUT_MS, outerSignal);
  try {
    return await request(url, body, timeout.signal);
  } finally {
    timeout.done();
  }
}

function pumpThrottleQueue() {
  if (activeThrottleController || !queuedThrottle || pendingStops) return;

  const job = queuedThrottle;
  queuedThrottle = null;
  const controller = new AbortController();
  activeThrottleController = controller;

  requestWithTimeout(job.url, job.body, controller.signal)
    .then(job.resolve)
    .catch((error) => {
      if (error?.name === 'AbortError') job.resolve(null);
      else job.reject(error);
    })
    .finally(() => {
      if (activeThrottleController === controller) activeThrottleController = null;
      pumpThrottleQueue();
    });
}

function isStopCommand(path, body) {
  return path === 'stop' || (
    path === 'manual_drive' &&
    !body.init &&
    Number(body.angle) === 0 &&
    Number(body.throttle) === 0
  );
}

async function sendPriorityStop(url, body) {
  pendingStops += 1;
  activeThrottleController?.abort();
  queuedThrottle?.resolve(null);
  queuedThrottle = null;

  try {
    let lastError = new Error('No se confirmó la detención');
    for (let attempt = 0; attempt < STOP_RETRIES; attempt += 1) {
      try {
        return await requestWithTimeout(url, body);
      } catch (error) {
        lastError = error;
        if (attempt < STOP_RETRIES - 1) {
          await new Promise((resolve) => setTimeout(resolve, STOP_RETRY_MS));
        }
      }
    }
    throw lastError;
  } finally {
    pendingStops -= 1;
    pumpThrottleQueue();
  }
}

export async function apiPost(path, body = {}) {
  const url = getApiUrl(path);
  try {
    if (isStopCommand(path, body)) return await sendPriorityStop(url, body);
    if (body.init || path === 'start') return await requestWithTimeout(url, body);
    if (pendingStops) throw new Error('Comando manual descartado mientras se confirma la detención');

    queuedThrottle?.resolve(null);
    const result = new Promise((resolve, reject) => {
      queuedThrottle = { url, body, resolve, reject };
    });
    pumpThrottleQueue();
    return await result;
  } catch (error) {
    console.error('Vehicle API error:', error);
    throw error;
  }
}

export const startAutoMode = () => apiPost('start');
export const stopVehicle = () => apiPost('stop');
export const activateManualMode = () => apiPost('manual_drive', { init: true });

export const sendManualCommand = (angle, throttle, maxSpeed) => apiPost('manual_drive', {
  angle: Math.round(angle),
  throttle: Math.round(throttle),
  max_speed: maxSpeed,
});
