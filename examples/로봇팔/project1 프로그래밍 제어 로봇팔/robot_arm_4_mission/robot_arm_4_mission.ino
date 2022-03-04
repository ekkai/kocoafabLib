// 로봇팔 키트 - robot_arm_4.ino
// 사용자 정의 함수를 활용한 로봇팔의 각 관절 제어

// 서보객채.attach(핀번호) : 서보객체에 해당 핀번호에 연결된 서보모터 설정
// 서보객채.write(각도값) : 각도값(0~180) 만큼 서보객채에 연결된 서보모터를 가동
// delay(밀리초) : 밀리초 만큼 대기

// bottom_Move(이전 각도, 이동할 각도) : bottom 서보모터를 '이전 각도(pre_D)'에서 '이동할 각도(after_D)'까지 연속 제어
// arm1_Move(이전 각도, 이동할 각도) : arm1 서보모터를 '이전 각도(pre_D)'에서 '이동할 각도(after_D)'까지 연속 제어
// arm2_Move(이전 각도, 이동할 각도) : arm2 서보모터를 '이전 각도(pre_D)'에서 '이동할 각도(after_D)'까지 연속 제어
// grip_Move(이전 각도, 이동할 각도) : grip 서보모터를 '이전 각도(pre_D)'에서 '이동할 각도(after_D)'까지 연속 제어


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
  arm1_Move(90, 60); // arm1 서보모터를 90도 위치에서 60도 위치로 이동
  delay(1000);
  arm1_Move(60, 90); // arm1 서보모터를 60도 위치에서 90도 위치로 이동
  delay(1000);

  bottom_Move(90, 135); // bottom 서보모터를 90도 위치에서 135도 위치로 이동
  delay(1000);
  bottom_Move(135, 90); // bottom 서보모터를 135도 위치에서 90도 위치로 이동
  delay(1000);


  arm2_Move(90, 150); // arm2 서보모터를 90도 위치에서 150도 위치로 이동
  delay(1000);
  arm2_Move(150, 90); // arm2 서보모터를 150도 위치에서 90도 위치로 이동
  delay(1000);

  grip_Move(90, 120); // grip 서보모터를 90도 위치에서 120도 위치로 이동
  delay(1000);
  grip_Move(120, 90); // grip 서보모터를 120도 위치에서 90도 위치로 이동 
  delay(1000);
}

// arm1_Move 함수 정의 
void arm1_Move(int pre_D, int after_D) { 
  if (pre_D > after_D) { // arm1 모터의 '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 크거나 같다면
    for (int i = pre_D; i >= after_D; i--) {
      arm1.write(i);
      delay(1);
    }
  }

  else {  // arm1 모터의 '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 작거나 같다면
    for (int i = pre_D; i <= after_D; i++) {
      arm1.write(i);
      delay(1);
    }
  }
}

// bottom_Move 함수 정의 
void bottom_Move(int pre_D, int after_D) {
  if (pre_D > after_D) {  // bottom 모터의 '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 크거나 같다면
    for (int i = pre_D; i >= after_D; i--) {
      bottom.write(i);
      delay(5);
    }
  }

  else {  // bottom 모터의 '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 작거나 같다면
    for (int i = pre_D; i <= after_D; i++) {
      bottom.write(i);
      delay(5);
    }
  }
}

// arm2_Move 함수 정의 
void arm2_Move(int pre_D, int after_D) {
  if (pre_D > after_D) { // arm2 모터의 '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 크거나 같다면
    for (int i = pre_D; i >= after_D; i--) {
      arm2.write(i);
      delay(1);
    }
  }

  else {  // arm2 모터의 '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 작거나 같다면
    for (int i = pre_D; i <= after_D; i++) {
      arm2.write(i);
      delay(1);
    }
  }
}

// grip_Move 함수 정의 
void grip_Move(int pre_D, int after_D) {
  if (pre_D > after_D) { // grip 모터의 '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 크거나 같다면
    for (int i = pre_D; i >= after_D; i--) {
      grip.write(i);
      delay(1);
    }
  }

  else {  // grip 모터의 '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 작거나 같다면
    for (int i = pre_D; i <= after_D; i++) {
      grip.write(i);
      delay(1);
    }
  }
}
