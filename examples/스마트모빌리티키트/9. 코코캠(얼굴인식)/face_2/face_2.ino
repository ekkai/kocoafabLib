#include <COCOCAM.h>
#include <Wire.h>

COCOCAM cococam;
cococamResult result;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  cococam.writeAlgorithm
  (ALGORITHM_FACE_RECOGNITION);
}
void loop() {
  cococam.request();
  while (cococam.available()) {
    result = cococam.read();
       if (result.ID == 0) {
         Serial.println("새로운 얼굴이 인식 되었습니다 학습버튼을 눌러주세요.");
       }
       if (result.ID > 0) {
         Serial.println(result.ID);
         Serial.println("번째 얼굴이 인식되었습니다.");
       }
  }
}
