char data;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop() {
  if (Serial.available()) {
    data = Serial.read();
    if (data == '1') {
      Serial.println("LED ON");
      digitalWrite(13, HIGH);
    }
    if (data == '2') {
      Serial.println("LED OFF");
      digitalWrite(13, LOW);
    }
  }
}
