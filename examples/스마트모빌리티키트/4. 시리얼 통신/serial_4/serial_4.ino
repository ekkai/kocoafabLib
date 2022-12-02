char data;

void setup() {
  // 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // 시리얼 모니터에서 입력된 문자를 변수에 저장합니다.
    data = Serial.read();

    // 저장된 문자를 시리얼 모니터에 "Input : 문자" 형태로 출력합니다.
    Serial.print("Input : ");
    Serial.println(data);
  }
}
