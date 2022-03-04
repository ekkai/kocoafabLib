// 미세먼지측정기(공기청정기) 키트 - dust_1.ino
// 미세먼지측정 센서 기초 활용

// dust.begin(핀번호1, 핀번호2) : 센서의 다섯번째 핀은 핀번호1에 네번째 핀은 핀번호2에 연결하여 센서 초기화
// dust.pm10Value() : 센서로부터 측정된 pm10 단위의 미세먼지 수치 출력
// dust.pm25Value() : 센서로부터 측정된 pm2.5 단위의 초미세먼지 수치 출력 
// dust.pm1Value() : 센서로부터 측정된 pm1 단위의 초미세먼지 수치 출력 

#include <dustSensor_kocoa.h>

dustSensor_kocoa dust;

int pm10;
int pm25;
int pm1;

void setup() {
  Serial.begin(9600);
  dust.begin(2, 3);          
}

void loop() {
  pm10 = dust.pm10Value();
  pm25 = dust.pm25Value();
  pm1 = dust.pm1Value();
  
  Serial.print("PM10 Dust : ");
  Serial.println(pm10);
  Serial.print("PM2.5 Dust : ");
  Serial.println(pm25);
  Serial.print("PM1 Dust : ");
  Serial.println(pm1);
  Serial.println();
}
