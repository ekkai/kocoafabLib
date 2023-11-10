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
    if (result.ID == 2) {
      Serial.println("태그 2가 인식되었습니다.");
    }
    if (result.ID == 4) {
      Serial.println("태그 4가 인식되었습니다.");
    }
  }
}
