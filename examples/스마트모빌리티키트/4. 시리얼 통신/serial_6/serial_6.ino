#include <Kocoafab_SmartMobility.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();
int data;

void setup() {
  // 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);

  if (!sm.begin()) {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }

  // 스마트 모빌리티의 속도를 100으로 지정
  sm.setSpeed(150);
  // 시작 동작을 정지로 설정
  sm.moveTo(5);
}

void loop() {
  if (Serial.available()) {
    // 시리얼 모니터에서 입력된 문자를 변수에 저장합니다.
    data = Serial.read();
    
    // 입력된 문자값에 48을 빼면 해당 문자를 숫자값으로 바꿀 수 있습니다.
    // 입력된 숫자값에 맞는 방향으로 스마트 모빌리티를 움직입니다.
    sm.moveTo(data - 48);
  }
}
