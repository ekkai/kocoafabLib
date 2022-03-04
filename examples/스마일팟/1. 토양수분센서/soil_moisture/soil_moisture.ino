// 스마일팟 키트 - soil_moisture.ino
// 토양 수분 센서 값 확인하기

// analogRead(A핀번호) : 해당 '아날로그 핀번호'의 센서 값 출력

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);
  
  Serial.print("read sensor value : ");
  Serial.println(value);

  delay(1000);
}
