// backend/server.js
import express from "express";
import cors from "cors";
import bodyParser from "body-parser";
import dotenv from "dotenv";
import path from "path";
import net from "net";
import { fileURLToPath } from "url";
import { startVehicle, stopVehicle, manualDrive, initSession, getVideoStream } from "./vehicleControl.js";
import { Client as SSHClient } from "ssh2";

const __dirname = path.dirname(fileURLToPath(import.meta.url));
dotenv.config({ path: path.resolve(__dirname, "../.env") });

const app = express();

const PORT = process.env.BACKEND_PORT || 5002;
const DRIVE_TCP_PORT = Number(process.env.DRIVE_TCP_PORT || 5003);
const ALLOWED_ORIGIN = process.env.ALLOWED_ORIGIN || "*";

app.disable("etag");
app.disable("x-powered-by");

app.use(
  cors({
    origin: ALLOWED_ORIGIN,
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
      console.log("▶️ /api/manual_drive init -> preparando vehículo para control manual...");
      try {
        await startVehicle();
        return res.json({ message: "Modo manual activado y vehículo habilitado (esperando comandos)" });
      } catch (err) {
        console.error("Error al activar modo manual:", err);
        return res.status(500).json({ error: "No se pudo activar modo manual" });
      }
    }

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

app.post("/api/exec", async (req, res) => {
  const { command } = req.body || {};
  if (!command) {
    return res.status(400).json({ error: "Falta el campo 'command'" });
  }

  const ssh = new SSHClient();
  const stdout = [];
  const stderr = [];

  ssh.on("ready", () => {
    ssh.exec(command, (err, stream) => {
      if (err) {
        ssh.end();
        return res.status(500).json({ error: `SSH exec error: ${err.message}` });
      }
      stream.on("data", (data) => stdout.push(data.toString()));
      stream.stderr.on("data", (data) => stderr.push(data.toString()));
      stream.on("close", (code) => {
        ssh.end();
        res.json({ stdout: stdout.join(""), stderr: stderr.join(""), exit: code });
      });
    });
  });

  ssh.on("error", (err) => {
    res.status(500).json({ error: `SSH connection error: ${err.message}` });
  });

  ssh.connect({
    host: process.env.DEEPRACER_HOST,
    port: parseInt(process.env.DEEPRACER_SSH_PORT) || 22,
    username: process.env.DEEPRACER_SSH_USER,
    password: process.env.DEEPRACER_SSH_PASSWORD,
    readyTimeout: 10000,
  });
});

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

    vehicleStream.pipe(res);

    res.on("close", () => {
      console.log("🔌 Cliente cerró el stream");
      try { vehicleStream.destroy(); } catch { }
    });

  } catch (err) {
    console.error("🔥 Error al obtener el stream:", err);
    res.status(500).json({
      error: "No se pudo obtener el stream de video",
      details: err.message,
    });
  }
});

app.listen(PORT, "0.0.0.0", () =>
  console.log(`Backend activo en http://0.0.0.0:${PORT}`)
);

async function handleDriveTcpCommand(command) {
  if (command.init) {
    await startVehicle();
    return { ok: true, message: "manual_ready" };
  }

  if (command.stop) {
    await stopVehicle();
    return { ok: true, message: "stopped" };
  }

  const { angle, throttle, max_speed } = command;
  if (angle === undefined || throttle === undefined || max_speed === undefined) {
    return { ok: false, error: "missing angle, throttle or max_speed" };
  }

  await manualDrive(angle, throttle, max_speed);
  return { ok: true, message: "drive_sent" };
}

const driveTcpServer = net.createServer((socket) => {
  socket.setNoDelay(true);
  socket.setKeepAlive(true);
  let buffer = "";
  let chain = Promise.resolve();

  socket.on("data", (chunk) => {
    buffer += chunk.toString("utf8");
    const lines = buffer.split("\n");
    buffer = lines.pop() || "";

    for (const line of lines) {
      const trimmed = line.trim();
      if (!trimmed) continue;
      chain = chain.then(async () => {
        try {
          const command = JSON.parse(trimmed);
          const result = await handleDriveTcpCommand(command);
          socket.write(`${JSON.stringify(result)}\n`);
        } catch (err) {
          socket.write(`${JSON.stringify({ ok: false, error: err.message })}\n`);
        }
      });
    }
  });

  socket.on("error", (err) => {
    console.warn(`Cliente TCP de manejo desconectado con error: ${err.message}`);
  });
});

driveTcpServer.listen(DRIVE_TCP_PORT, "127.0.0.1", () => {
  console.log(`Canal TCP de manejo activo en 127.0.0.1:${DRIVE_TCP_PORT}`);
});

driveTcpServer.on("error", (err) => {
  console.error(`Error en canal TCP de manejo: ${err.message}`);
});
