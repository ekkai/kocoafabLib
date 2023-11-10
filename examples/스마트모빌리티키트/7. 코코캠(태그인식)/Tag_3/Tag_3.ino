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
  int tagNum = getTagNum(); 
  if (tagNum != 99) { 
     Serial.println("태그" + String(tagNum) + "가 인식되었습니다.");
  }
}

int getTagNum() {
  cococam.request();
  while (cococam.available()) {
    result = cococam.read();
    return result.ID; 
  }
  return 99;   //태그 인식이 안될 경우 99를 반환
}
