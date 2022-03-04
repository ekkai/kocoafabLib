// 로봇팔 키트 - serial_2.ino
// serial 전송 값을 판별하여 서보모터 각도 제어

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.available() : 시리얼통신을 통해 유효한 값이 전송 되었을 때 true
// Serial.read() : 시리얼통신을 통해 전송 받은 값을 읽어 저장 변수에 저장
// Serial.print(ln)("문장" or 변수) : 변수 데이터를 시리얼 통신을 통해 출력

#include <Servo.h>

Servo myservo;
char data;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();

    if (data == '1') { // 전송 받은 값이 '1'이라면 모터를 0도로 이동
      myservo.write(0);
    }

    if (data == '2') { // 전송 받은 값이 '2'이라면 모터를 90도로 이동
      myservo.write(90);
    }

    if (data == '3') { // 전송 받은 값이 '3'이라면 모터를 180도로 이동
      myservo.write(180);
    } 
  }
}
