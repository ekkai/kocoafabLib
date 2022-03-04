// 자동 손소독제 키트 - auto_hand_sanitizing_machine.ino
// 자동 손소독제 최종 코드

// millis() : 현재 시각을 밀리초 단위로 출력

#include <Servo.h>

Servo servo;

// 핀 설정
int piezoPin = 11;
int echoPin = 3;
int trigPin = 2;
int servoPin = 6;

unsigned long currentTime = 0;
boolean flag = 0;


// 초음파 센서의 손 측정 시간 설정 변수
int checkTime = 2000;

// 손소독제 크기에 따른 모터의 각도 조절 변수
int pushAngle = 40;
int currentAngle = 90;

void setup() {
  servo.attach(servoPin);
  servo.write(currentAngle);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration / 29.0 / 2.0;
  // 초음파센서 거리 측정 
  
  if (distance <= 10) { // 거리가 10cm 이내라면
    if (flag == 0) { // flag가 0일때 
      currentTime = millis(); // 측정 순간의 시각을 currentTime에 저장 
      flag = 1; // flag가 1이 되며 이 조건을 다시 실행하지 않도록 함 
    }

    if (millis() >= currentTime + checkTime) { // 현재 측정 시각(millis())이 currentTIme(위에서 측정한 시각)보다 2000밀리초(2초) 더 지난 시점이라면 

      // 피에조부저에 멜로디 출력
      tone(piezoPin, 1046, 200); 
      delay(200);
      tone(piezoPin, 1175, 200);
      delay(200);
      tone(piezoPin, 1319, 200);
      delay(800);

      // 서보모터가 일정 각도(pushAngle)만큼 이동 후 제 위치(currentAngle)로 이동
      servo.write(pushAngle);
      delay(1000);
      servo.write(currentAngle);
      delay(1000);

      // 모든 과정이 끝난 후 flag 다시 0
      flag = 0;
    }
  }

  else { // 거리가 10cm 밖이라면
    flag = 0; // flag 0 유지
    noTone(piezoPin); // 피에조부저 소리 끔
  }

  delay(100);
}
