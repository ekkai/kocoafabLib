// RC카 키트 - LED_1.ino
// LED 디지털 제어 

// pinMode(핀번호, 모드) : 해당 핀번호를 입력 or 출력 모드로 설정
// digitalWrite(핀번호, 상태) : 핀번호에 HIGH/LOW 신호 출력
// delay(밀리초) : 밀리초 만큼 대기

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
  delay(1000);
}
