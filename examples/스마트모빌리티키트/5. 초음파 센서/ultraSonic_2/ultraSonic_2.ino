#include <Kocoafab_SmartMobility.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();

// 초음파 센서의 trig, echo 핀 번호
int trig = 2;
int echo = 3;

void setup() {
  // 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);

  // 모터 드라이브 연결
  if (!sm.begin())
  {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }

  // 스마트 모빌리티키트에 연결된 초음파 센서의 핀 설정
  sm.setUltrasonic(trig, echo);
}

void loop() {
  // 스마트 모빌리티 키트에 연결된 초음파 센서의 거리를 측정
  float distance = sm.getDistance();

  // 측정된 거리를 시리얼모니터에 출력
  Serial.print(distance);
  Serial.println("cm");

  delay(200);
}
