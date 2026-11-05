import { Gauge } from 'lucide-react';

export default function SpeedControl({ value, onChange }) {
  return (
    <section className="settings-card">
      <div className="settings-title">
        <Gauge size={16} />
        <h3>Límite de velocidad</h3>
        <output htmlFor="max-speed">{Math.round(value * 100)}%</output>
      </div>
      <input
        id="max-speed"
        className="speed-range"
        type="range"
        min="0.1"
        max="1"
        step="0.01"
        value={value}
        onChange={(event) => onChange(Number.parseFloat(event.target.value))}
        aria-label="Límite de velocidad"
      />
      <div className="range-labels"><span>10%</span><span>100%</span></div>
    </section>
  );
}
