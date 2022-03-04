// RC카 키트 - serial_1.ino
// serial 통신의 기본 구조

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.print("문장" or 변수) : " "안의 문장 또는 변수 값을 시리얼 통신으로 출력

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Hello World");
}
