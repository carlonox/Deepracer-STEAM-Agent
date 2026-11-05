import { X } from 'lucide-react';

export default function ToastRegion({ toast, onDismiss }) {
  if (!toast) return null;

  return (
    <div
      className={`toast-message toast-${toast.type}`}
      role={toast.type === 'error' ? 'alert' : 'status'}
      aria-live={toast.type === 'error' ? 'assertive' : 'polite'}
    >
      <span>{toast.message}</span>
      <button type="button" onClick={onDismiss} aria-label="Cerrar mensaje">
        <X size={16} />
      </button>
    </div>
  );
}
