// 로봇팔 키트 - robot_arm_1.ino
// 로봇팔 특정 동작 반복 제어

// 서보객채.attach(핀번호) : 서보객체에 해당 핀번호에 연결된 서보모터 설정
// 서보객채.write(각도값) : 각도값(0~180) 만큼 서보객채에 연결된 서보모터를 가동
// delay(밀리초) : 밀리초 만큼 대기

#include <Servo.h>

Servo bottom;
Servo arm1;
Servo arm2;
Servo grip;

// 각 서보모터에 핀번호 부여 및 기본 각도(90도) 설정
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
  bottom.write(50); // 좌회전
  arm1.write(120); // 앞으로 숙이기
  arm2.write(70); // 아래로 숙이기
  grip.write(130); // 집게 열기

  delay(1000);

  bottom.write(90); // 원위치
  arm1.write(90);  // 원위치
  arm2.write(90); // 원위치
  grip.write(90); // 원위치

  delay(1000);
}
