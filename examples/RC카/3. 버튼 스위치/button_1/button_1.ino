// RC카 키트 - Button_1.ino
// 버튼 스위치 기초 활용

// digitalRead(핀번호) : 해당핀에서 디지털 신호를 읽어 true or false 출력

void setup(){
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop(){
 Serial.println(digitalRead(8));
 delay(100);
}
