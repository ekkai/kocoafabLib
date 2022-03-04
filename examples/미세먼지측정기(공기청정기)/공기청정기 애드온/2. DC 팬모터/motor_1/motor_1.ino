// 미세먼지측정기(공기청정기) 키트 - motor_1.ino
// 모터드라이버를 활용한 팬 모터 제어 

int motorA = 10;
int motorB = 11;

// motorA, motorB 핀 출력모드 설정
void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
}

// 팬모터는 역방향 회전이 불가능 하기 때문에 직진 motorA에 PWM 값을 입력하고 motorB엔 0을 유지
void loop() {
  analogWrite(motorA, 50);
  analogWrite(motorB, 0);
  delay(3000);

  analogWrite(motorA, 150);
  analogWrite(motorB, 0);
  delay(3000);

  analogWrite(motorA, 255);
  analogWrite(motorB, 0);
  delay(3000);
}
