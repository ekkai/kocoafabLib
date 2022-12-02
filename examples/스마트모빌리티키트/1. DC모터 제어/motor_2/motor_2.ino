#include <Kocoafab_SmartMobility.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();

void setup() {
  // 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);

  // 모터 드라이브 연결
  if (!sm.begin())
  {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }

  // 스마트 모빌리티의 속도를 200으로 지정
  sm.setSpeed(200);
  // 시작 동작을 정지로 설정
  sm.moveTo(5);
}

void loop() {
  // 1초간 전진
  sm.moveTo(2, 1000);

  // 2초간 정지
  sm.moveTo(5);
  delay(2000);
}
