import { defineConfig } from "vite";
import react from "@vitejs/plugin-react";

export default defineConfig({
  plugins: [react()],
  envDir: "../..", // Configuración compartida desde el .env de la raíz.
  server: {
    host: '0.0.0.0', // Permitir conexiones desde cualquier IP
    port: 5173,
    hmr: {
      clientPort: 8081, // HMR a través de Nginx en puerto 8081
    }
  }
});
