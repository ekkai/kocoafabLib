#include <COCOCAM.h>
#include <Wire.h>

COCOCAM cococam;
cococamResult result;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  cococam.writeAlgorithm
  (ALGORITHM_COLOR_RECOGNITION);
}
void loop() {
  cococam.request();
  while (cococam.available()) {
    result = cococam.read();
         Serial.print(result.ID);
         Serial.println("번째 색상이 인식되었습니다.");
  }
}
