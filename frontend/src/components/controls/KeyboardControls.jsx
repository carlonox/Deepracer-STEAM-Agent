import { ChevronUp, ChevronDown, ChevronLeft, ChevronRight } from 'lucide-react';

export default function KeyboardControls({ pressedKeys, onKeyPress, onKeyRelease }) {
  const isPressed = (keys) => keys.some((k) => pressedKeys.has(k));

  const KeyButton = ({ keys, icon: Icon, label }) => {
    const pressed = isPressed(keys);
    return (
      <button
        className={`btn btn-square btn-lg ${pressed ? 'btn-primary' : 'btn-outline'} transition-all`}
        onMouseDown={(e) => { e.preventDefault(); onKeyPress(keys[0]); }}
        onMouseUp={(e) => { e.preventDefault(); onKeyRelease(keys[0]); }}
        onMouseLeave={(e) => { e.preventDefault(); onKeyRelease(keys[0]); }}
        onTouchStart={(e) => { e.preventDefault(); onKeyPress(keys[0]); }}
        onTouchEnd={(e) => { e.preventDefault(); onKeyRelease(keys[0]); }}
        onTouchCancel={(e) => { e.preventDefault(); onKeyRelease(keys[0]); }}
      >
        <div className="flex flex-col items-center gap-1">
          <Icon className="w-5 h-5" />
          <span className="text-xs">{label}</span>
        </div>
      </button>
    );
  };

  return (
    <div className="flex flex-col items-center gap-2">
      <div className="flex justify-center">
        <KeyButton keys={['ArrowUp', 'w', 'W']} icon={ChevronUp} label="W" />
      </div>
      <div className="flex gap-2">
        <KeyButton keys={['ArrowLeft', 'a', 'A']} icon={ChevronLeft} label="A" />
        <KeyButton keys={['ArrowDown', 's', 'S']} icon={ChevronDown} label="S" />
        <KeyButton keys={['ArrowRight', 'd', 'D']} icon={ChevronRight} label="D" />
      </div>
    </div>
  );
}
