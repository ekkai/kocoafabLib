#include <Kocoafab_SmartMobility.h>
#include <COCOCAM.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();
COCOCAM cococam;
cococamResult result;

int sensitivity = 50;

int leftLED = 5;
int rightLED = 10;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  cococam.writeAlgorithm(ALGORITHM_TAG_RECOGNITION);

  if (!sm.begin())
  {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }
  sm.setSpeed(50);
  sm.moveTo(5);

  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
}

void loop() {
  cococam.request();

  while (cococam.available()) {
    result = cococam.read();
  }
  if (result.ID == 0) { //태그가 0일 때(우측 회전)
    sm.rotate(CW);  //우측으로 90도 회전
    delay(2680);       //딜레이값 조절 필요
    sm.moveTo(2);   //1초간 전진
    delay(1000);
    result.ID = 99;
  }
  if (result.ID == 1) {  //태그가 1일 때(좌측 회전)
    sm.rotate(CCW); //좌측으로 90도 회전
    delay(2680);         //딜레이값 조절 필요
    sm.moveTo(2);     //1초간 전진
    delay(1000);
    result.ID = 99;
  }
  if (result.ID == 2) {  //태그가 2일 때
    sm.moveTo(5);    //1초간 정지
    delay(1000);
    sm.moveTo(2);    //1초간 전진
    delay(1000);
    result.ID = 99;
  }
}
