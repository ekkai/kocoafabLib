#include <Kocoafab_SmartMobility.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();

// 초음파 센서의 trig, echo 핀 번호
int trig = 2;
int echo = 3;

// 피에조 부저 핀 번호
int piezo = 7;

void setup() {
  Serial.begin(9600);

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

  // 장애물이 15cm 이하로 인식됐을 때 경보 울림
  if (distance < 15) {
    tone(piezo, 2048);
    delay(distance * 10);
    noTone(piezo);
    delay(distance * 10);
  }

  // 장애물이 인식되지 않으면 경보 끔
  else {
    noTone(piezo);
  }
}
