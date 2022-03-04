// RC카 키트 - self_driving_RC_car.ino
// 초음파센서를 활용한 자율주행 RC카


// 핀설정
int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;

int trig = 2;
int echo = 3;

int LSpeed = 255;
int RSpeed = 255;


void setup() {
  Serial.begin(9600);
  // 초음파센서 설정
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

  // 초음파센서 거리측정 
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // 측정 거리 저장 
  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration / 29.0 / 2.0;
  Serial.println(distance);

  // 근접 판단 (거리가 8cm 미만이라면)
  if (distance < 8) {
    //정지
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
    delay(700);

    //후진
    analogWrite(in1, 0);
    analogWrite(in2, RSpeed);
    analogWrite(in3, LSpeed);
    analogWrite(in4, 0);
    delay(500);

    //좌회전
    analogWrite(in1, RSpeed);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
    delay(800);
  }
  
  // 근접 대상 없음(측정거리 8cm 이상)
  else { 
    // 직진
    analogWrite(in1, RSpeed);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, LSpeed);
  }
}
