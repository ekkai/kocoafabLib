// RC카 키트 - CdS_2.ino
// 조도센서 측정값을 기준으로 LED 점등

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  int cdsValue = analogRead(A0);

  Serial.print("cds =  ");
  Serial.println(cdsValue);

  if (cdsValue > 300) {
    digitalWrite(3, HIGH);
    Serial.println("LED ON (cds > 300)");
  }

  else {
    digitalWrite(3, LOW);
    Serial.println("LED OFF (cds <=300)");
  }

  delay(200);
}
