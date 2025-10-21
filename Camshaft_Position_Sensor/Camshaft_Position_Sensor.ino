volatile bool magnetDetected = false;
volatile unsigned long triggerTime = 0;

const int camSensorPin = 2;   // SS41K output -> Arduino pin 2 (INT0)
const int injectorPin = 9;    // Injector or LED output
const float angleOffset = 30.0; // Degrees between sensor trigger and intake valve open
const unsigned long injectionDuration = 4000; // In microseconds (4 ms)

// Example: Assume engine runs at 3000 RPM -> cam runs at 1500 RPM
// 1500 rev/min = 25 rev/sec = 40ms per revolution = 8.33ms per 30 degrees
float camRPM = 1500.0;

void setup() {
  pinMode(camSensorPin, INPUT_PULLUP);
  pinMode(injectorPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(camSensorPin), camTrigger, FALLING); // Active LOW output from SS41K

  Serial.begin(115200);
  Serial.println("Camshaft injection timing initialized...");
}

void loop() {
  if (magnetDetected) {
    magnetDetected = false;

    // Calculate time per degree based on cam RPM
    float revPeriod = (60.0 / camRPM) * 1000000.0; // Microseconds per cam revolution
    float timePerDegree = revPeriod / 360.0;

    // Compute delay from magnet to intake valve opening
    unsigned long delayTime = angleOffset * timePerDegree;

    // Schedule injector pulse
    delayMicroseconds(delayTime);
    fireInjector();
  }
}

void camTrigger() {
  triggerTime = micros();
  magnetDetected = true;
}

void fireInjector() {
  digitalWrite(injectorPin, HIGH);
  delayMicroseconds(injectionDuration);
  digitalWrite(injectorPin, LOW);

  Serial.print("Injector fired at: ");
  Serial.print(micros());
  Serial.println(" µs");
}
