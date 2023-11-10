#include <Kocoafab_SmartMobility.h>
#include <COCOCAM.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();
COCOCAM cococam;
cococamResult result;

int xCenter;   //화살표 중앙점의 x좌표
double gradient;  //화살표의 기울기

void setup() {
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  cococam.writeAlgorithm(ALGORITHM_LINE_TRACKING);

  if (!sm.begin()) {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }
  sm.setSpeed(100);  //스마트 모빌리티의 속도 세팅
  sm.moveTo(5);
}

void loop() {
  cococam.request();

  if (cococam.available()) {
    result = cococam.read();
    xCenter = (result.xTarget + result.xOrigin) / 2;
    gradient = (double)(result.yOrigin - result.yTarget) /
               (result.xTarget - result.xOrigin);
  }
  if (xCenter > 240) {  //화면 오른쪽에 라인이 있을 때
    sm.moveTo(6);
    delay(100);
  }
  else if (xCenter < 80) {  //화면 왼쪽에 라인이 있을 때
    sm.moveTo(4);
    delay(100);
  }
  else {//화면 중앙에 라인이 있을 때
    if (gradient > -1 && gradient < -0.25) {
      sm.moveTo(9);
      delay(100);
    }
    else if (gradient > -0.25 && gradient < 0) {
      sm.rotate(CCW);
      delay(200);
    }
    else if (gradient < 0.25 && gradient > 0) {
      sm.rotate(CW);
      delay(200);
    }
    else if (gradient < 1 && gradient > 0.25) {
      sm.moveTo(7);
      delay(100);
    }
    else {
      sm.moveTo(8);
      delay(100);
    }
  }
}
