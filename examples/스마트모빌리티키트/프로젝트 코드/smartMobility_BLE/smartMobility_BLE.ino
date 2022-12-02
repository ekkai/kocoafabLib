// 스마트 모빌리티 키트 - smartMobility_ble.ino
// 블루투스 통신으로 모빌리티 제어하기

#include <Kocoafab_SmartMobility.h>
#include <SoftwareSerial.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();
SoftwareSerial BTSerial(4, 5);

char data;

void setup() {
  // 블루투스 통신과 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);
  BTSerial.begin(9600);

  // 모터 드라이브 연결
  if (!sm.begin())
  {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }

  // 스마트 모빌리티의 속도를 120으로 지정
  sm.setSpeed(120);
  // 시작 동작을 정지로 설정
  sm.moveTo(5);
}

void loop() {
  // 시리얼 모니터에서 입력된 데이터를 받아 이동 방향을 제어
  if (BTSerial.available())  {
    // 블루투스 통신으로 전달된 데이터를 Int 형태로 data 변수에 저장
    data = BTSerial.read();
    /*
        이동 방향 명령어
         1  2  3
         4  5  6
         7  8  9
    */
    //  read()로 읽어온 데이터에 48을 빼면 숫자값이 됨
    sm.moveTo(data - 48);
  }
}
