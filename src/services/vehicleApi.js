/**
 * API Service for vehicle control
 */

const API_PORT = 5002;

/**
 * Make a POST request to the vehicle API
 * @param {string} path - API endpoint path
 * @param {object} body - Request body
 * @returns {Promise<object|null>} Response data or null on error
 */
export const apiPost = async (path, body = {}) => {
  try {
    const apiHost = window.location.hostname;
    const res = await fetch(`http://${apiHost}:${API_PORT}/api/${path}`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(body),
    });
    const data = await res.json().catch(() => ({}));
    if (!res.ok) throw new Error(data.error || res.statusText);
    return data;
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
