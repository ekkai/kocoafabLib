char data;

void setup() {
  // 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);

  // 보드에 내장된 LED가 연결된 핀을 출력으로 설정
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    // 시리얼 모니터에서 입력된 문자를 변수에 저장합니다.
    data = Serial.read();

    // 입력된 문자가 1이면 LED를 켭니다.
    if (data == '1') {
      Serial.println("LED ON");
      digitalWrite(13, HIGH);
    }

    // 입력된 문자가 2면 LED를 끕니다.
    if (data == '2') {
      Serial.println("LED OFF");
      digitalWrite(13, LOW);
    }
  }
}
