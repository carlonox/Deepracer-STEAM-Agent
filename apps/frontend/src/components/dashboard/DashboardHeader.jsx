import { Activity, Gauge } from 'lucide-react';

export default function DashboardHeader({ status }) {
  const isStopped = status === 'Detenido';
  const isManual = status.includes('manual');

  return (
    <header className="topbar">
      <a className="brand" href="/" aria-label="DeepRacer Control, inicio">
        <span className="brand-mark"><Gauge size={21} strokeWidth={2.2} /></span>
        <span>
          <strong>DeepRacer</strong>
          <small>CONTROL STATION</small>
        </span>
      </a>
      <div className="topbar-meta">
        <span className="system-label"><Activity size={15} /> SISTEMA DE CONTROL</span>
        <div className={`status-pill ${isStopped ? 'status-stopped' : isManual ? 'status-manual' : 'status-auto'}`}>
          <span className="status-dot" />
          {status}
        </div>
      </div>
    </header>
  );
}
