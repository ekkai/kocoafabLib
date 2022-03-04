// 로봇팔 키트 - robot_arm_3.ino
// 사용자 정의 함수를 활용한 로봇팔 관절 제어

// 서보객채.attach(핀번호) : 서보객체에 해당 핀번호에 연결된 서보모터 설정
// 서보객채.write(각도값) : 각도값(0~180) 만큼 서보객채에 연결된 서보모터를 가동
// delay(밀리초) : 밀리초 만큼 대기
// arm1_Move(이전 각도, 이동할 각도) : arm1 서보모터를 '이전 각도(pre_D)'에서 '이동할 각도(after_D)'까지 연속 제어

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
  arm1_Move(30, 90); // 30도 위치에서 90도 위치로 이동
  delay(1000);
  arm1_Move(90, 30); // 90도 위치에서 30도 위치로 이동
  delay(1000);
}

// arm1_Move 함수 정의 
void arm1_Move(int pre_D, int after_D) {
  if (pre_D > after_D) { // '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 크거나 같다면
    for (int i = pre_D; i >= after_D; i--) { // 1도씩 감소
      arm1.write(i);
      delay(1);
    }
  }

  else { // '이전 각도(pre_D)'가 '이동할 각도(after_D)'보다 작거나 같다면
    for (int i = pre_D; i <= after_D; i++) { // 1도씩 증가
      arm1.write(i);
      delay(1);
    }
  }
}
