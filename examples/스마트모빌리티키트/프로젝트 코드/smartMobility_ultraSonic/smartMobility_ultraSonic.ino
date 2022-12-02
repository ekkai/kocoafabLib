// 스마트 모빌리티 키트 - smartMobility_ultraSonic.ino
// 블루투스 통신으로 모빌리티 제어하기

#include <Kocoafab_SmartMobility.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();

// 초음파센서 trig핀 2번, echo핀 3번에 연결
int trig = 2;
int echo = 3;

void setup() {
  Serial.begin(9600);

  // 모터 드라이브 연결
  if (!sm.begin())
  {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }

  // 스마트 모빌리티의 속도를 100으로 지정
  sm.setSpeed(100);
  // 시작 동작을 정지로 설정
  sm.moveTo(5);

  // 스마트 모빌리티키트에 연결된 초음파 센서의 핀 설정
  sm.setUltrasonic(trig, echo);
}

void loop() {
  // 스마트 모빌리티 키트에 연결된 초음파 센서의 거리를 측정
  float distance = sm.getDistance();
  Serial.println(distance);

  // 장애물과의 거리가 가까우면(< 15cm) 오른쪽으로 이동
  if (distance < 15) {
    sm.moveTo(6);
    delay(700);
  }

  // 장애물과의 거리가 멀면 직진
  else {
    sm.moveTo(2);
  }
  delay(100);
}
