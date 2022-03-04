#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <Servo.h>

SparkFun_APDS9960 apds = SparkFun_APDS9960();

uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;

Servo bottom;
Servo arm1;
Servo arm2;
Servo grip;

void setup() {
  Serial.begin(9600);
  apds.init();
  apds.enableLightSensor(false);
  
  bottom.attach(8);
  arm1.attach(9);
  arm2.attach(10);
  grip.attach(11);

  bottom.write(90);
  arm1.write(90);
  arm2.write(90);
  grip.write(90);
  delay(500);
}

void loop() {
  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  } 
  else {
    if (red_light > green_light && red_light > blue_light) {
      Serial.println("redColor");
      /*
       * ?칸에 적절한 위치 각도를 지정합니다. 
      arm1_move(90, ?);
      bottom_move(90,?);
      arm2_move(90, ?);
      grip_move(90,?);
      */
      
    }
    else if (green_light > red_light && green_light > blue_light) {
      Serial.println("greenColor");
      /*
       * ?칸에 적절한 위치 각도를 지정합니다. 
      arm1_move(90, ?);
      bottom_move(90,?);
      arm2_move(90, ?);
      grip_move(90,?);
      */
    }
    else if (blue_light > red_light && blue_light > red_light) {
      Serial.println("blueColor");
      /*
       * ?칸에 적절한 위치 각도를 지정합니다. 
      arm1_move(90, ?);
      bottom_move(90,?);
      arm2_move(90, ?);
      grip_move(90,?);
      */
    }
  }
  delay(1000);
}



void arm1_Move(int pre_D, int after_D) {
  if (pre_D > after_D) {
    for (int i = pre_D; i >= after_D; i--) {
      arm1.write(i);
      delay(1);
    }
  }

  else {
    for (int i = pre_D; i <= after_D; i++) {
      arm1.write(i);
      delay(1);
    }
  }
}

void bottom_Move(int pre_D, int after_D) {
  if (pre_D > after_D) {
    for (int i = pre_D; i >= after_D; i--) {
      bottom.write(i);
      delay(5);
    }
  }

  else {
    for (int i = pre_D; i <= after_D; i++) {
      bottom.write(i);
      delay(5);
    }
  }
}

void arm2_Move(int pre_D, int after_D) {
  if (pre_D > after_D) {
    for (int i = pre_D; i >= after_D; i--) {
      arm2.write(i);
      delay(1);
    }
  }

  else {
    for (int i = pre_D; i <= after_D; i++) {
      arm2.write(i);
      delay(1);
    }
  }
}

void grip_Move(int pre_D, int after_D) {
  if (pre_D > after_D) {
    for (int i = pre_D; i >= after_D; i--) {
      grip.write(i);
      delay(1);
    }
  }

  else {
    for (int i = pre_D; i <= after_D; i++) {
      grip.write(i);
      delay(1);
    }
  }
}
