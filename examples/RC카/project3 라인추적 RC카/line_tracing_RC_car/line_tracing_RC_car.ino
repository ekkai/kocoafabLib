// RC카 키트 - line_tracing_RC_car.ino
// 라인검출 센서를 활용한 라인트레이싱 RC카

int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;

int R = 12;
int L = 13;

int RSpeed = 255;
int LSpeed = 255;

void setup() {
  pinMode(L, INPUT);
  pinMode(R, INPUT);
}

void loop() {
  if (digitalRead(R) == HIGH && digitalRead(L) == LOW) {
    //우회전
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed);
  }

  if (digitalRead(R) == LOW && digitalRead(L) == HIGH) {
    //좌회전
      analogWrite(in1, RSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
  }

  if (digitalRead(R) == HIGH && digitalRead(L) == HIGH) {
    //직진
      analogWrite(in1, RSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed); 
  }

  if (digitalRead(R) == LOW && digitalRead(L) == LOW) {
    //직진
      analogWrite(in1, RSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed); 
  }
}
