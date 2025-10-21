// Optimized RPM Sensor for EFI Lawn Mower Engine - Arduino Uno
// Hall effect sensor with interrupt-based measurement

const byte RPM_PIN = 2;             // Interrupt pin (2 or 3 on Uno)
const byte PULSES_PER_REV = 1;

volatile uint16_t pulseCount = 0;
uint32_t lastCalcTime = 0;
const uint16_t CALC_INTERVAL = 1000; // 1-second update interval
uint16_t currentRPM = 0;

void setup() {
  Serial.begin(115200);              // Faster baud rate
  pinMode(RPM_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RPM_PIN), countPulse, FALLING);
  Serial.println(F("RPM Sensor Ready")); // F() saves RAM
}

void loop() {
  uint32_t now = millis();

  if (now - lastCalcTime >= CALC_INTERVAL) {
    noInterrupts();
    uint16_t pulses = pulseCount;
    pulseCount = 0;
    interrupts();

    // Calculate RPM: (pulses * 60) / PULSES_PER_REV
    currentRPM = (pulses * 60UL) / PULSES_PER_REV;

    Serial.print(F("RPM: "));
    Serial.println(currentRPM);

    lastCalcTime = now;
  }

  // Engine stall detection
  if (now - lastCalcTime > 2000 && currentRPM > 0) {
    currentRPM = 0;
    Serial.println(F("Engine Stopped"));
  }
}

void countPulse() {
  pulseCount++;
}

uint16_t getRPM() {
  return currentRPM;
}
