// 스마트 모빌리티 키트 - smartMobility_lineTracer.ino
// 라인트레이싱 센서를 활용해 라인트레이서 만들기

#include <Kocoafab_SmartMobility.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();

// 라인 센서 기준값 설정(기본값 100)
int level = 100;

int leftLine = A0;
int rightLine = A1;

int leftVal;
int rightVal;

//  LED 2개 pin 번호 설정
int leftLED = 5;
int rightLED = 10;

void setup() {
  Serial.begin(9600);

  // 모터 드라이브 연결
  sm.begin();
  // 스마트 모빌리티의 속도를 100으로 지정
  sm.setSpeed(100);
  // 시작 동작을 정지로 설정
  sm.moveTo(5);

  // LED 2개의 핀모드 설정
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
}

void loop() {

  leftVal = analogRead(leftLine);
  rightVal = analogRead(rightLine);
    
  // 두 센서 모두 라인이 인식되면
  if (leftVal > level && rightVal > level) {
    // 정지
    sm.moveTo(5);

    // LED 소등
    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, LOW);
  }

  // 왼쪽에 라인이 인식되면
  else if (leftVal > level && rightVal < level) {
    // 왼쪽(반시계방향) 회전
    sm.rotate(CCW);

    // 왼쪽 LED 점등
    digitalWrite(leftLED, HIGH);
    digitalWrite(rightLED, LOW);
  }

  // 오른쪽에 라인이 인식되면
  else if (leftVal < level && rightVal > level) {
    // 오른쪽(시계방향) 회전
    sm.rotate(CW);

    // 오른쪽 LED 점등
    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, HIGH);
  }

  // 라인이 인식되지 않으면
  else if (leftVal < level && rightVal < level) {
    // 전진
    sm.moveTo(2);

    // LED 모두 소등
    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, LOW);
  }
  delay(10);
}
