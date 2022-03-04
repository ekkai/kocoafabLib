// 아크릴램프 키트 - bluetooth_1.ino
// 오렌지보드 BLE에서 ATcommand 활용

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
