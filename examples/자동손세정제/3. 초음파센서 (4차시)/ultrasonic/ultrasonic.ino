// 자동 손소독제 키트 - ultrasonic.ino
// 초음파센서를 활용해 서보모터 제어

// delayMicroseconds(마이크로초) : 마이크로초 만큼 딜레이
// pulseIn(핀번호, 상태) : HIGH or LOW의 상태동안 해당 핀의 펄스를 읽음

#include <Servo.h>

Servo myservo;

void setup() {
  //시리얼 통신 초기화 및 핀 설정
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  myservo.attach(9);
}

void loop() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration / 29.0 / 2.0;
  // 초음파센서를 활용한 대상과의 거리(distance) 측정 
  
  if(distance < 30){ // 대상이 30cm 이내에 있다면
    myservo.write(0); // 모터를 0도로 이동 
    delay(1000);    
  }
  else if(distance < 60){ // 대상이 60cm 이내에 있다면
    myservo.write(90); // 모터를 90도로 이동 
    delay(1000); 
  }
  else{ // 대상이 60cm 밖에 있다면
    myservo.write(180); // 모터를 180도로 이동
    delay(1000); 
  }
  // 시리얼 모니터에 대상과의 거리 출력
  Serial.print(distance);
  Serial.println("cm");

  delay(200); // 200밀리초 대기
}
