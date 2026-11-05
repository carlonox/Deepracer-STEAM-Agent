import { ChevronUp, ChevronDown, ChevronLeft, ChevronRight } from 'lucide-react';

export default function KeyboardControls({ pressedKeys, onKeyPress, onKeyRelease }) {
  const isPressed = (keys) => keys.some((k) => pressedKeys.has(k));

  const KeyButton = ({ keys, icon, label }) => {
    const pressed = isPressed(keys);
    return (
      <button
        type="button"
        className={`keyboard-key ${pressed ? 'key-pressed' : ''}`}
        aria-label={`Control ${label}`}
        aria-pressed={pressed}
        onMouseDown={(e) => { e.preventDefault(); onKeyPress(keys[0]); }}
        onMouseUp={(e) => { e.preventDefault(); onKeyRelease(keys[0]); }}
        onMouseLeave={(e) => { e.preventDefault(); onKeyRelease(keys[0]); }}
        onTouchStart={(e) => { e.preventDefault(); onKeyPress(keys[0]); }}
        onTouchEnd={(e) => { e.preventDefault(); onKeyRelease(keys[0]); }}
        onTouchCancel={(e) => { e.preventDefault(); onKeyRelease(keys[0]); }}
      >
        <div className="flex flex-col items-center gap-1">
          {icon}
          <span className="text-xs">{label}</span>
        </div>
      </button>
    );
  };

  return (
    <div className="keyboard-pad">
      <div className="keyboard-row">
        <KeyButton keys={['ArrowUp', 'w', 'W']} icon={<ChevronUp className="w-5 h-5" />} label="W" />
      </div>
      <div className="keyboard-row">
        <KeyButton keys={['ArrowLeft', 'a', 'A']} icon={<ChevronLeft className="w-5 h-5" />} label="A" />
        <KeyButton keys={['ArrowDown', 's', 'S']} icon={<ChevronDown className="w-5 h-5" />} label="S" />
        <KeyButton keys={['ArrowRight', 'd', 'D']} icon={<ChevronRight className="w-5 h-5" />} label="D" />
      </div>
    </div>
  );
}
