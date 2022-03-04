// RC카 키트 - serial_5.ino
// serial 전송 값을 판별하여 LED 점등

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.available() : 시리얼통신을 통해 유효한 값이 전송 되었을 때 true
// Serial.read() : 시리얼통신을 통해 전송 받은 값을 읽어 저장 변수에 저장
// Serial.print(ln)("문장" or 변수) : 변수 데이터를 시리얼 통신을 통해 출력

char data;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}
void loop() {
  if (Serial.available()) {
    data = Serial.read();
    if (data == '1') {
      Serial.println("LED ON");
      digitalWrite(3, HIGH);
    }

    if (data == '2') {
      Serial.println("LED OFF");
      digitalWrite(3, LOW);     
    }
  }
}
