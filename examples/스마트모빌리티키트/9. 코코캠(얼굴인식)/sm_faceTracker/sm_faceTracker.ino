#include <COCOCAM.h>
#include <Kocoafab_SmartMobility.h>
#include <SoftwareSerial.h>

COCOCAM cococam;
Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();
SoftwareSerial BTSerial(4, 5);

void printResult(cococamResult result);
cococamResult result;

void setup() {

  // 블루투스 통신과 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  sm.begin();

  // 스마트 모빌리티의 속도를 120으로 지정
  sm.setSpeed(50);
  // 시작 동작을 정지로 설정
  sm.moveTo(5);
  cococam.writeAlgorithm(ALGORITHM_FACE_RECOGNITION);
}
void loop() {
  cococam.request();

  // 인식 결과 출력
  while (cococam.available()) {
    result = cococam.read();
    if (result.xCenter > 120 && result.xCenter < 200 && result.width < 100) {
      sm.moveTo(2);
    }
    else if (result.xCenter > 120 && result.xCenter < 200 && result.width > 120) {
      sm.moveTo(8);
    }
    else if (result.xCenter < 120 && result.width > 100 && result.width < 120)  {
      sm.moveTo(4);
    }
    else if (result.xCenter > 200 && result.width > 100 && result.width < 120)  {
      sm.moveTo(6);
    }
    else if (result.xCenter < 120 && result.width < 100) {
      sm.moveTo(1);
    }
    else if (result.xCenter < 120 && result.width > 120) {
      sm.moveTo(7);
    }
    else if (result.xCenter > 200 && result.width < 100) {
      sm.moveTo(3);
    }
    else if (result.xCenter > 200 && result.width > 120) {
      sm.moveTo(9);
    }
    else {
      sm.moveTo(5);
    }
  }
}
