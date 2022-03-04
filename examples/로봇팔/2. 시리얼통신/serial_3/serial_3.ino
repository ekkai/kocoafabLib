// 로봇팔 키트 - serial_3.ino
// serial 전송 값 만큼 서보모터 각도 제어

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.available() : 시리얼통신을 통해 유효한 값이 전송 되었을 때 true
// Serial.parseInt() : 시리얼통신을 통해 전송 받은 값을 읽어 저장 변수에 저장
// Serial.print(ln)("문장" or 변수) : 변수 데이터를 시리얼 통신을 통해 출력
// constrain(변수, 최소값, 최대값) : 해당 변수의 값이 최소값보다 작을땐 최소값으로, 최대값 보다 클땐 최대값으로 고정하여 출력

#include <Servo.h>

Servo myservo;

int data;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    data = Serial.parseInt();
    if (data < 0 || data > 180)
    {
      Serial.println("minimum is 0, maximum is 180");
      data = constrain(data, 0, 180);
    }
    myservo.write(data);

  }
}
