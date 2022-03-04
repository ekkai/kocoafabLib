// RC카 키트 - Motor_2.ino
// PWM을 활용한 모터 회전 속도 제어

int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;

int LSpeed = 255;
int RSpeed = 255;

void setup() {
}

void loop() {
  analogWrite(in1, RSpeed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, LSpeed);
}
