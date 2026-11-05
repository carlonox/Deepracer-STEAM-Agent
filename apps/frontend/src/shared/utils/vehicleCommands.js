export function getDirectionalCommand({
  forward = false,
  reverse = false,
  left = false,
  right = false,
  steeringThrottle = 0,
}) {
  if (forward && right) return { angle: 45, throttle: -100 };
  if (forward && left) return { angle: -45, throttle: -100 };
  if (reverse && right) return { angle: 45, throttle: 100 };
  if (reverse && left) return { angle: -45, throttle: 100 };
  if (forward) return { angle: 0, throttle: -100 };
  if (reverse) return { angle: 0, throttle: 100 };
  if (left) return { angle: -45, throttle: steeringThrottle };
  if (right) return { angle: 45, throttle: steeringThrottle };
  return { angle: 0, throttle: 0 };
}

export function getKeyboardCommand(keys) {
  return getDirectionalCommand({
    forward: keys.has('ArrowUp') || keys.has('w') || keys.has('W'),
    reverse: keys.has('ArrowDown') || keys.has('s') || keys.has('S'),
    left: keys.has('ArrowLeft') || keys.has('a') || keys.has('A'),
    right: keys.has('ArrowRight') || keys.has('d') || keys.has('D'),
  });
}
