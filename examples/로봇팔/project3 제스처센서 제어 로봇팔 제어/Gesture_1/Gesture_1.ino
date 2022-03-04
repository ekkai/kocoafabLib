#include <Wire.h>
#include <SparkFun_APDS9960.h>

int interrupt = 2;

SparkFun_APDS9960 sensor = SparkFun_APDS9960();

int isr_flag = 0;

void setup() {
  Serial.begin(9600);

  pinMode(interrupt, INPUT);
  attachInterrupt(0, interruptRoutine, FALLING);

  sensor.init();
  sensor.enableGestureSensor(true);
}

void loop() {
  if ( isr_flag == 1 ) {
    if ( sensor.isGestureAvailable() ) {
      switch ( sensor.readGesture() ) {
        case DIR_UP:
          Serial.println("UP");
          break;
        case DIR_DOWN:
          Serial.println("DOWN");
          break;
        case DIR_LEFT:
          Serial.println("LEFT");
          break;
        case DIR_RIGHT:
          Serial.println("RIGHT");
          break;
        case DIR_NEAR:
          Serial.println("NEAR");
          break;
        case DIR_FAR:
          Serial.println("FAR");
          break;
        default:
          Serial.println("NONE");
      }
    }
    isr_flag = 0;
  }
}

void interruptRoutine() {
  isr_flag = 1;
}
