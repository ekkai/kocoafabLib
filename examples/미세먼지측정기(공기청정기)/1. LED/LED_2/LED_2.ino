// 미세먼지측정기(공기청정기) 키트 - LED_2.ino
// LED 아날로그 제어 

// analogWrite(핀번호, PWM값) : 핀번호에 PWM값(0~255)만큼 출력
// delay(밀리초) : 밀리초 만큼 대기


void setup(){
}

void loop(){
  analogWrite(9, 255);
  delay(500);
  analogWrite(9, 128);
  delay(500);
  analogWrite(9, 0); 
  delay(500); 
}
