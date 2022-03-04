// RC카 키트 - Ultrasonic_2.ino
// 초음파센서를 활용한 일정 거리 이내 인식

// delayMicroseconds(마이크로초) : 마이크로초 만큼 딜레이
// PulseIn(핀번호, 상태) : HIGH or LOW의 상태동안 해당 핀의 펄스를 읽음


int trig = 2;
int echo = 3;
int piezo = 7;

void setup() {
  Serial.begin(9600);
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

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration / 29.0 / 2.0;

  if (distance < 15) {
    tone(piezo, 2048);
    delay(distance * 10);
    noTone(piezo);
    delay(distance * 10);
  }

  else {
    noTone(piezo);
  }
}
