export default function VehicleStatus({
  status,
  maxSpeed,
  gamepadConnected,
  xrSupported,
  cameraStatus,
}) {
  return (
    <dl className="status-summary" aria-label="Estado del sistema">
      <div>
        <dt>Vehículo</dt>
        <dd>{status}</dd>
      </div>
      <div>
        <dt>Velocidad máxima</dt>
        <dd>{Math.round(maxSpeed * 100)}%</dd>
      </div>
      <div>
        <dt>Gamepad</dt>
        <dd>{gamepadConnected ? 'Conectado' : 'Desconectado'}</dd>
      </div>
      <div>
        <dt>Soporte XR</dt>
        <dd>{xrSupported === null ? 'Verificando' : xrSupported ? 'Disponible' : 'No disponible'}</dd>
      </div>
      <div>
        <dt>Cámara</dt>
        <dd>{cameraStatus === 'connected' ? 'Conectada' : cameraStatus === 'error' ? 'Sin señal' : 'Conectando'}</dd>
      </div>
    </dl>
  );
}
