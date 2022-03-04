// 로봇팔 키트 - set_degree.ino
// 로봇팔 4개의 서보모터 기본 각도 세팅

// myservo.attach(핀번호) : myservo 객체에 해당 핀번호에 연결된 서보모터 설정
// myservo.write(각도값) : 각도값(0~180) 만큼 myservo 객체에 연결된 서보모터를 가동

#include <Servo.h>

Servo bottom;
Servo arm1;
Servo arm2;
Servo grip;

void setup() {
  bottom.attach(8);
  arm1.attach(9);
  arm2.attach(10);
  grip.attach(11);

  bottom.write(90);
  arm1.write(90);
  arm2.write(90);
  grip.write(90);
}

void loop() {
  
}
