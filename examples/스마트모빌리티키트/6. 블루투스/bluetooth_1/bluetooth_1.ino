#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5);

void setup() {
  // 블루투스 통신과 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // 블루투스를 통해 데이터가 들어오면 시리얼 모니터로 출력합니다.
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // 시리얼모니터를 통해 데이터가 들어오면 블루투스로 전송합니다.
  if (Serial.available())
    BTSerial.write(Serial.read());
}
