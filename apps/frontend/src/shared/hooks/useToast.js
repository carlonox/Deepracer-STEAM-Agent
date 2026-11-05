import { useCallback, useEffect, useRef, useState } from 'react';

export default function useToast() {
  const [toast, setToast] = useState(null);
  const timeoutRef = useRef(null);

  const dismiss = useCallback(() => {
    clearTimeout(timeoutRef.current);
    setToast(null);
  }, []);

  const notify = useCallback((message, type = 'error') => {
    clearTimeout(timeoutRef.current);
    setToast({ message, type });
    timeoutRef.current = setTimeout(() => setToast(null), 5000);
  }, []);

  useEffect(() => () => clearTimeout(timeoutRef.current), []);

  return { toast, notify, dismiss };
}
