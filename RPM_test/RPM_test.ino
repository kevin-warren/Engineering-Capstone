void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(2));
  delay(100);
}
