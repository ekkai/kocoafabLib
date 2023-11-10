#include <Kocoafab_SmartMobility.h>
Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();
char data;

void setup() {
  Serial.begin(9600);
  if (!sm.begin()) {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }
  sm.setSpeed(150);
  sm.moveTo(5);
}

void loop() {
  if (Serial.available()) {
    data = Serial. read();
    sm.moveTo(data - 48);
  }
}
