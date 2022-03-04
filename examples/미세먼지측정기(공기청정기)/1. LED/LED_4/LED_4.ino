// 미세먼지측정기(공기청정기) 키트 - LED_4.ino
// RGBLED 아날로그 제어 

// analogWrite(핀번호, PWM값) : 핀번호에 PWM값(0~255)만큼 출력
// delay(밀리초) : 밀리초 만큼 대기

void setup() {
}

void loop() {
  analogWrite(9,255);
  analogWrite(10,0);
  analogWrite(11, 0); 
  delay(1000); 

  analogWrite(9,255);
  analogWrite(10,255);
  analogWrite(11, 0); 
  delay(1000);  

  analogWrite(9,255);
  analogWrite(10,0);
  analogWrite(11, 255); 
  delay(1000);
}
