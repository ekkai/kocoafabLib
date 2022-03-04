// RC카 키트 - Motor_1.ino
// 모터 드라이버를 활용한 DC모터 기초 제어

int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
