#include <COCOCAM.h>
#include <Wire.h>

COCOCAM cococam;
cococamResult result;

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
    if (result.command == COMMAND_RETURN_ARROW) {
      Serial.println("=====");
      if (result.xOrigin > result.xTarget) {
        Serial.println("Pointing to the Left");
      }

      else if (result.xOrigin < result.xTarget) {
        Serial.println("Pointing to the Right");
      }
    }
  }
}
