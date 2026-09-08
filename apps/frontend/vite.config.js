import { defineConfig, loadEnv } from "vite";
import react from "@vitejs/plugin-react";
import fs from "node:fs";

export default defineConfig(({ mode }) => {
  // .env de la raíz (envDir). Sin secretos: solo rutas a un cert LOCAL
  // (nunca commitear .key/.crt) y flags de dev.
  const env = loadEnv(mode, "../..", "");
  const keyPath = env.VITE_HTTPS_KEY;
  const certPath = env.VITE_HTTPS_CERT;
  const https =
    keyPath && certPath && fs.existsSync(keyPath) && fs.existsSync(certPath)
      ? { key: fs.readFileSync(keyPath), cert: fs.readFileSync(certPath) }
      : undefined;
  // Proxy dev: con VITE_API_PROXY=1 el frontend llama a /api y /video en
  // mismo origen (evita mixed-content bajo HTTPS). Sin flag, todo igual.
  const awsHost = env.VITE_AWS_HOST || "localhost";

  return {
    plugins: [react()],
    envDir: "../..", // Configuración compartida desde el .env de la raíz.
    server: {
      host: '0.0.0.0', // Permitir conexiones desde cualquier IP
      port: 5173,
      https,
      proxy: {
        "/api": "http://127.0.0.1:5002",
        "/video": {
          target: `http://${awsHost}:8080`,
          changeOrigin: true,
          rewrite: (p) => p.replace(/^\/video/, ""),
        },
      },
      hmr: {
        clientPort: 8081, // HMR a través de Nginx en puerto 8081
      }
    }
  };
});
