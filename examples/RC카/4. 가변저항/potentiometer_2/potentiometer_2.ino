// RC카 키트 - Potentiometer_2.ino
// 가변저항 값의 범위에 따른 LED 점등

// analogRead(A핀번호) : 해당 아날로그 입력핀에서 아날로그 값(0~1023)을 읽어 출력

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(A0);

  if(potValue > 512){
    digitalWrite(3, HIGH);
    Serial.println("LED ON (pot> 512)");
  }

else{
    digitalWrite(3, LOW);
    Serial.println("LOW OFF (pot< 512)");
  }
}
