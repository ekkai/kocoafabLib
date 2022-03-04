// 미세먼지측정기(공기청정기) 키트 - LED_5.ino
// RGB LED 무작위 색상 제어 

// analogWrite(핀번호, PWM값) : 핀번호에 PWM값(0~255)만큼 출력
// random(시작값, 최대값) : 시작값에서 최대값보다 1작은 수 사이에 있는 무작위 숫자 출력

void setup() {
}

void loop() {
  analogWrite(9,random(0,256));
  analogWrite(10,random(0,256));
  analogWrite(11,random(0,256)); 
  delay(1000); 
}
