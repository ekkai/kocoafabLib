// 로봇팔 키트 - servo_1.ino
// 서보모터 기초 제어 

// myservo.attach(핀번호) : myservo 객체에 해당 핀번호에 연결된 서보모터 설정
// myservo.write(각도값) : 각도값(0~180) 만큼 myservo 객체에 연결된 서보모터를 가동
// delay(밀리초) : 밀리초 만큼 대기

#include <Servo.h>

Servo myservo1;

void setup() {
  myservo1.attach(9);
}

void loop() {
    myservo1.write(0);
    delay(1000);
    
    myservo1.write(90);
    delay(1000);
    
    myservo1.write(180);
    delay(1000);
}
