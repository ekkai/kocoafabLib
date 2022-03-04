// 로봇팔 키트 - robot_arm_2.ino
// 로봇팔 관절별 연속 제어

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
  for (int i = 90; i > 49 ; i--) { // 50도에 도달할 때까지 1도씩 bottom 모터 제어 
    bottom.write(i);
    delay(10);
  }
  for (int i = 90; i < 121; i++) { // 120도에 도달할 때까지 1도씩 arm1 모터 제어 
    arm1.write(i);
    delay(10);
  }
  for (int i = 90; i > 69 ; i--) { // 70도에 도달할 때까지 1도씩 arm2 모터 제어 
    arm2.write(i);
    delay(10);
  }
  for (int i = 90; i < 131; i++) { // 130도에 도달할 때까지 1도씩 grip 모터 제어 
    grip.write(i);
    delay(10);
  }
  
  delay(1000);
  
  for (int i = 50; i < 91; i++) { // 원위치(90도)에 도달할 때까지 1도씩 bottom 모터 제어 
    bottom.write(i);
    delay(10);
  }
  for (int i = 120; i > 89; i--) { // 원위치(90도)에 도달할 때까지 1도씩 arm1 모터 제어 
    arm1.write(i);
    delay(10);
  }
  for (int i = 70; i < 91; i++) { // 원위치(90도)에 도달할 때까지 1도씩 arm2 모터 제어 
    arm2.write(i);
    delay(10);
  }
  for (int i = 130; i > 89; i--) { // 원위치(90도)에 도달할 때까지 1도씩 grip 모터 제어 
    grip.write(i);
    delay(10);
  }

  delay(1000);
  
}
