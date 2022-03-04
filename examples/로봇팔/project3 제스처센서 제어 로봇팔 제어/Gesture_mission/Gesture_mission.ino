#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <Servo.h>

Servo bottom;
Servo arm1;
Servo arm2;
Servo grip;

int Interrupt = 2;

int bottom_Val = 90;
int arm1_Val = 90;
int arm2_Val = 90;
int grip_Val = 90;

SparkFun_APDS9960 sensor = SparkFun_APDS9960();

int isr_flag = 0;
int Sensitivity = 30;

void setup() {
  Serial.begin(9600);

  pinMode(Interrupt, INPUT);
  attachInterrupt(0, interruptRoutine, FALLING);

  sensor.init();
  sensor.enableGestureSensor(true);

  bottom.attach(8);
  arm1.attach(9);
  arm2.attach(10);
  grip.attach(11);

  bottom.write(bottom_Val);
  arm1.write(arm1_Val);
  arm2.write(arm2_Val);
  grip.write(grip_Val);
}

void loop() {
  if ( isr_flag == 1 ) {

    if ( sensor.isGestureAvailable() ) {
      switch ( sensor.readGesture() ) {
        case DIR_UP:
          Serial.println("UP");
          arm1_Val -= Sensitivity;
          break;
          
        case DIR_DOWN:
          Serial.println("DOWN");
          arm1_Val += Sensitivity;
          break;
          
        case DIR_LEFT:
          Serial.println("LEFT");
          bottom_Val += Sensitivity;
          break;
          
        case DIR_RIGHT:
          Serial.println("RIGHT");
          bottom_Val -= Sensitivity;
          break;
          
        case DIR_NEAR:
          Serial.println("NEAR");
          arm2_Val -= Sensitivity;
          break;
          
        case DIR_FAR:
          Serial.println("FAR");
          arm2_Val += Sensitivity;
          break;
          
        default:
          Serial.println("NONE");
      }
    }

    isr_flag = 0;
  }

  bottom_Val = constrain(bottom_Val,20,160);
  arm1_Val = constrain(arm1_Val, 50, 130);
  arm2_Val = constrain(arm2_Val, 20, 160);
  grip_Val = constrain(grip_Val, 90, 130);

  bottom.write(bottom_Val);
  arm1.write(arm1_Val);
  arm2.write(arm2_Val);
  grip.write(grip_Val);

}

void interruptRoutine() {
  isr_flag = 1;
}
