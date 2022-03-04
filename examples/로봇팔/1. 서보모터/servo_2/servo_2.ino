// 로봇팔 키트 - servo_2.ino
// 반복문을 활용한 서보모터 연속 제어 

// myservo.attach(핀번호) : myservo 객체에 해당 핀번호에 연결된 서보모터 설정
// myservo.write(각도값) : 각도값(0~180) 만큼 myservo 객체에 연결된 서보모터를 가동
// delay(밀리초) : 밀리초 만큼 대기

#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(9);
}

void loop() {  
  
  for(int pos=0, i<180; i++)// 180회 동안 i(최초0)를 1씩 증가 반복
  {
    myservo.write(pos);
    delay(15);
  }


   for(int pos=180, i>0; i--)// 180회 동안 i(최초180)를 1씩 감소 반복
  {
    myservo.write(pos);
    delay(15);
  }

}
