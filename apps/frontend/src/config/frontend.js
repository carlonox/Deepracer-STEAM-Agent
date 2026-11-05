const env = import.meta.env;

export const useApiProxy = env.VITE_API_PROXY === '1';
export const awsHost = env.VITE_AWS_HOST || 'localhost';

export function getApiUrl(path) {
  const endpoint = `/api/${path}`;
  if (useApiProxy) return endpoint;
  return `http://${window.location.hostname}:5002${endpoint}`;
}

export function getCameraStreamUrl({ width = 480, height = 360, quality = 85 } = {}) {
  const endpoint = `/stream?topic=/camera_pkg/display_mjpeg&width=${width}&height=${height}&quality=${quality}`;
  return useApiProxy
    ? `/video${endpoint}`
    : `http://${awsHost}:8080${endpoint}`;
}
