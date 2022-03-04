// RC카 키트 - LED_2.ino
// LED 아날로그 제어 

// analogWrite(핀번호, PWM값) : 핀번호에 PWM값(0~255)만큼 출력
// delay(밀리초) : 밀리초 만큼 대기

void setup(){
}

void loop(){
  analogWrite(3, 255);
  delay(500);
  analogWrite(3, 128);
  delay(500);
  analogWrite(3, 0); 
  delay(500); 
}
