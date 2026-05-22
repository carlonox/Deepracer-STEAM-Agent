// backend/server.js
import express from "express";
import cors from "cors";
import bodyParser from "body-parser";
import { startVehicle, stopVehicle, manualDrive, initSession, getVideoStream } from "./vehicleControl.js";

const app = express();
app.disable("etag");
app.disable("x-powered-by");

app.use(
  cors({
    origin: "*",
    methods: ["GET", "POST", "OPTIONS"],
    allowedHeaders: ["Content-Type", "X-CSRF-Token"],
  })
);
app.use(bodyParser.json());

app.post("/api/start", async (req, res) => {
  try {
    await startVehicle();
    res.json({ message: "Vehículo preparado (drive_mode/manual + start_stop/start)" });
  } catch (err) {
    console.error("Error en /api/start:", err);
    res.status(500).json({ error: "Error al preparar el vehículo" });
  }
});

app.post("/api/stop", async (req, res) => {
  try {
    await stopVehicle();
    res.json({ message: "Vehículo detenido" });
  } catch (err) {
    console.error("Error en /api/stop:", err);
    res.status(500).json({ error: "Error al detener el vehículo" });
  }
});

app.post("/api/manual_drive", async (req, res) => {
  try {
    const { init, angle, throttle, max_speed } = req.body || {};

    if (init) {
      // init: preparar vehículo al modo manual y habilitar, SIN moverlo
      console.log("▶️ /api/manual_drive init -> preparando vehículo para control manual...");
      try {
        await startVehicle(); // startVehicle ya no hace movimiento automático
        return res.json({ message: "Modo manual activado y vehículo habilitado (esperando comandos)" });
      } catch (err) {
        console.error("Error al activar modo manual:", err);
        return res.status(500).json({ error: "No se pudo activar modo manual" });
      }
    }

    // Para comandos normales requerimos parámetros normalizados
    if (angle === undefined || throttle === undefined || max_speed === undefined) {
      return res.status(400).json({ error: "Faltan parámetros: angle, throttle o max_speed" });
    }

    console.log(`➡️ /api/manual_drive -> angle=${angle}, throttle=${throttle}, max_speed=${max_speed}`);
    await manualDrive(angle, throttle, max_speed);
    return res.json({ message: "Comando manual enviado" });
  } catch (err) {
    console.error("Error en /api/manual_drive:", err);
    res.status(500).json({ error: "Error en control manual" });
  }
});

(async () => {
  try {
    console.log("🔐 Inicializando sesión...");
    await initSession();
    console.log("🔐 Sesión lista.");
  } catch (err) {
    console.warn("⚠️ No se pudo inicializar sesión aún. Se intentará más tarde.", err);
  }
})();

app.get("/api/video_stream", async (req, res) => {
  console.log("📡 Cliente solicitó el stream de video");

  try {
    const vehicleStream = await getVideoStream();

    res.writeHead(200, {
      "Content-Type": vehicleStream.headers["content-type"] ||
        "multipart/x-mixed-replace;boundary=boundarydonotcross",
      "Cache-Control": "no-store, no-cache, must-revalidate, max-age=0",
      Pragma: "no-cache",
      Connection: "keep-alive",
      "X-Content-Type-Options": "nosniff",
    });

    // EL MÉTODO CORRECTO PARA MJPEG
    vehicleStream.pipe(res);

    res.on("close", () => {
      console.log("🔌 Cliente cerró el stream");
      try { vehicleStream.destroy(); } catch {}
    });

  } catch (err) {
    console.error("🔥 Error al obtener el stream:", err);
    res.status(500).json({
      error: "No se pudo obtener el stream de video",
      details: err.message,
    });
  }
});

const PORT = 5002;
app.listen(PORT, "0.0.0.0", () =>
  console.log(`Backend activo en http://0.0.0.0:${PORT}`)
);
