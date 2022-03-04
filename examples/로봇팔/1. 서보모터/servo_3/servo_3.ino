// 로봇팔 키트 - servo_3.ino
// 2개의 서보모터 연속 제어 

// myservo.attach(핀번호) : myservo 객체에 해당 핀번호에 연결된 서보모터 설정
// myservo.write(각도값) : 각도값(0~180) 만큼 myservo 객체에 연결된 서보모터를 가동
// delay(밀리초) : 밀리초 만큼 대기

#include <Servo.h>

Servo myservo1;    //첫 번째 서보모터 myservo1
Servo myservo2;    //두 번째 서보모터 myservo2

int pos = 0;


void setup() {
  myservo1.attach(8); // 첫번째 모터 8번핀에 연결
  myservo2.attach(9); // 두번째 모터 9번핀에 연결
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) // 180회 동안 i(최초0)를 1씩 증가 반복
  { 
    myservo1.write(pos);
    myservo2.write(pos);
    delay(15);
  }

  for (pos = 180; pos >= 0; pos -= 1) // 180회 동안 i(최초180)를 1씩 감소 반복
  {
    myservo1.write(pos);
    myservo2.write(pos);
    delay(15);
  }
}
