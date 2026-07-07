# ESP32 DevKit V1 (30-pin) Pinout Reference

> The ESP32 development board with CP2102 USB bridge, commonly sold as "ESP32 DevKit V1".
> Confirmed on the DeepRacer STEAM Agent project.

## Board Layout (USB port faces up)

```
         ┌──────────────────────────────────┐
         │ USB Type-A (CP2102)              │
    ┌────┤                                  ├────┐
    │ EN │                                  │ D23│
    │ VP │                                  │ D22│
    │ VN │                                  │ TX0│
    │ D34│                                  │ RX0│
    │ D35│                                  │ D21│
    │ D32│                                  │ D19│
    │ D33│                                  │ D18│
    │ D25│                                  │ D5 │
    │ D26│                                  │ D17│
    │ D27│                                  │ D16│
    │ D14│                                  │ ⭐**D4**│ ← KY-037 OUT
    │ D12│                                  │ D0 │
    │ D13│                                  │ D2 │
    │ GND│                                  │ D15│
    │ VIN│                                  │ D8 │
    │ ⭐**3V3**│                              │ D7 │
    │ 3V3│                                  │ D6 │
    │ GND│                                  │ D9 │
    │ GND│                                  │ D10│
    │ GND│                                  │ D11│
    └────┴──────────────────────────────────┴────┘
```

**Labels are silkscreened on the board.** Most boards label pins as D4, D5, D23 (not GPIO4, GPIO5, etc.).

## Key Pins for the DeepRacer Project

| Pin Label | GPIO | Use |
|-----------|------|-----|
| **D4** | 4 | KY-037 sound sensor OUT |
| **3V3** (left row) | — | 3.3V power for KY-037 VCC |
| **GND** | — | Ground (any of 4 GND pins, e.g. right row near D15) |

## Pins to Avoid (strapping pins with boot-time behavior)

GPIO 0, 2, 5, 12, 15 — these affect boot mode or flash voltage. Do not use for sensors unless you understand the implications.

## Safe GPIOs for General Use

4, 13, 14, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33

## Common Sensor Wiring

| Sensor | VCC | GND | Signal |
|--------|-----|-----|--------|
| KY-037 | 3.3V | GND | OUT → D4 |
| HC-05 | 3.3V | GND | TX → D16(RX2), RX → D17(TX2) |
| HC-SR04 | 5V | GND | TRIG→D13, ECHO→D14 (use level shifter) |
