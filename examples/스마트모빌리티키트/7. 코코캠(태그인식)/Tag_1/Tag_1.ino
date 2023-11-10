#include <COCOCAM.h>
#include <Wire.h>

COCOCAM cococam;
cococamResult result;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  cococam.writeAlgorithm(ALGORITHM_TAG_RECOGNITION);
}

void loop() {
  cococam.request();

  while (cococam.available()) {
    result = cococam.read();
    Serial.println(result.ID);
  }
}
