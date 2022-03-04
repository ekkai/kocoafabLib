#include <Wire.h>
#include <SparkFun_APDS9960.h>

SparkFun_APDS9960 apds = SparkFun_APDS9960();

uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;

void setup() {
  Serial.begin(9600);
  apds.init();
  apds.enableLightSensor(false);
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
    }
    else if (green_light > red_light && green_light > blue_light) {
      Serial.println("greenColor");
    }
    else if (blue_light > red_light && blue_light > red_light) {
      Serial.println("blueColor");
    }
  }
  delay(1000);
}
