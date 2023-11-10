#include <COCOCAM.h>
#include <Wire.h>

COCOCAM cococam;
cococamResult result;

int xCenter;
int yCenter;
double gradient;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  cococam.writeAlgorithm(ALGORITHM_LINE_TRACKING);
}
void loop() {
  cococam.request();
  while (cococam.available()) {
    result = cococam.read();
    xCenter = (result.xTarget + result.xOrigin) / 2;
    yCenter = (result.yTarget + result.yOrigin) / 2;
    gradient = (double)(result.yOrigin - result.yTarget) / (result.xTarget - result.xOrigin);
    Serial.println(String() + F("xCenter=") + xCenter +
                   F(", yCenter=") + yCenter + F(", gradient=") + gradient);
  }
}
