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
  // Proxy dev OPT-IN: solo con VITE_API_PROXY=1 Y https con ambas rutas
  // se registra server.proxy. Sin certs no hay proxy: servir comandos de
  // control por HTTP en 0.0.0.0 expondria el robot en cleartext (CWE-319).
  // WebXR (Quest) exige contexto seguro de todos modos. Sin flag, todo igual
  // (frontend ataca directo al backend y a la camara).
  const awsHost = env.VITE_AWS_HOST || "localhost";
  const useProxy = env.VITE_API_PROXY === "1" && Boolean(https);
  if (env.VITE_API_PROXY === "1" && !https) {
    console.warn(
      "[vite] VITE_API_PROXY=1 ignorado: faltan VITE_HTTPS_KEY/VITE_HTTPS_CERT validos. " +
      "El proxy solo corre sobre HTTPS para no exponer control en cleartext por LAN."
    );
  }

  return {
    plugins: [react()],
    envDir: "../..", // Configuración compartida desde el .env de la raíz.
    server: {
      host: '0.0.0.0', // Permitir conexiones desde cualquier IP
      port: 5173,
      https,
      ...(useProxy ? {
        proxy: {
          "/api": "http://127.0.0.1:5002",
          "/video": {
            target: `http://${awsHost}:8080`,
            changeOrigin: true,
            rewrite: (p) => p.replace(/^\/video/, ""),
          },
        },
      } : {}),
      hmr: {
        clientPort: 8081, // HMR a través de Nginx en puerto 8081
      }
    }
  };
});
