// RC카 키트 - Potentiometer_1.ino
// 가변저항 기초 활용

// analogRead(A핀번호) : 해당 아날로그 입력핀에서 아날로그 값(0~1023)을 읽어 출력

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(A0);

  Serial.print("pot =  ");
  Serial.println(potValue);
  
  delay(200);
}
