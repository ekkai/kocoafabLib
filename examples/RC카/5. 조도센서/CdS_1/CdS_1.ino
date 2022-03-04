// RC카 키트 - CdS_1.ino
// 조도센서 기초 활용

// analogRead(A핀번호) : 해당 아날로그 입력핀에서 아날로그 값(0~1023)을 읽어 출력


void setup() {
  Serial.begin(9600); 
}

void loop() {
  int cdsValue = analogRead(A0);

  Serial.print("Light =  ");
  Serial.println(cdsValue);

  delay(200);
}
