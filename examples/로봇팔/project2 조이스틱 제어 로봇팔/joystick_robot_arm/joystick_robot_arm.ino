#include <Servo.h>

Servo bottom;
Servo arm1;
Servo arm2;
Servo grip;

int Sensitivity = 1;

int bottom_Val = 90;
int arm1_Val = 90;
int arm2_Val = 90;
int grip_Val = 90;

int left_X = A0;
int left_Y = A1;
int right_X = A2;
int right_Y = A3;

int left_B = 6;
int right_B = 7;

void setup() {
  bottom.attach(8);
  arm1.attach(9);
  arm2.attach(10);
  grip.attach(11);

  bottom.write(bottom_Val);
  arm1.write(arm1_Val);
  arm2.write(arm2_Val);
  grip.write(grip_Val);

  pinMode(left_B, INPUT_PULLUP);
  pinMode(right_B, INPUT_PULLUP);
}

void loop()
{
  //Bottom 서보모터 & L조이스틱 X축
  if (analogRead(left_X) > 800) { //L조이스틱을 좌측으로 움직였을때
    bottom_Val += Sensitivity;
  }

  if (analogRead(left_X) < 200) {//L조이스틱을 우측으로 움직였을때
    bottom_Val -= Sensitivity;
  }

  bottom_Val = constrain(bottom_Val, 10, 170);


  //Arm1 서보모터 & L조이스틱 Y축
  if (analogRead(left_Y) > 800) { //L조이스틱을 아래로 움직였을때
    arm1_Val -= Sensitivity;
  }

  if (analogRead(left_Y) < 200) {//L조이스틱을 위로 움직였을때
    arm1_Val += Sensitivity;
  }

  arm1_Val = constrain(arm1_Val, 30, 140);

  //Arm2 서보모터 & R조이스틱 Y축
  if (analogRead(right_X) > 800) { //L조이스틱을 아래로 움직였을때
    arm2_Val -= Sensitivity;
  }

  if (analogRead(right_X) < 200) {//L조이스틱을 위로 움직였을때
    arm2_Val += Sensitivity;
  }

  arm2_Val = constrain(arm2_Val, 30, 150);

  //grip 서보모터 & R조이스틱 X축
  if (analogRead(right_Y) > 800) { //L조이스틱을 좌측으로 움직였을때
    grip_Val += Sensitivity;
  }

  if (analogRead(right_Y) < 200) {//L조이스틱을 우측으로 움직였을때
    grip_Val -= Sensitivity;
  }

  grip_Val = constrain(grip_Val, 90, 130);

  bottom.write(bottom_Val);
  arm1.write(arm1_Val);
  arm2.write(arm2_Val);
  grip.write(grip_Val);

  delay(10);
}
