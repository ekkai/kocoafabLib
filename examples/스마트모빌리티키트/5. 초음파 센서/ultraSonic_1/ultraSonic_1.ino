// 초음파 센서의 trig, echo 핀 번호
int trig = 2;
int echo = 3;

void setup() {
  // 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);

  // trig 핀을 출력으로 echo핀을 입력으로 설정
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // 초음파가 반사되어 올때까지의 시간 측정
  unsigned long duration = pulseIn(echo, HIGH);

  // 거리 = 왕복 시간 / 29 / 2
  float distance = duration / 29.0 / 2.0;

  // 측정된 거리를 시리얼 모니터에 출력
  Serial.print(distance);
  Serial.println("cm");

  delay(200);
}
