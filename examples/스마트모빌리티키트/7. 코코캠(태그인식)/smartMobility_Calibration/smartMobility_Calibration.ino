#include <Kocoafab_SmartMobility.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();

int sensorLValue = 0;
int sensorLMin = 1023;
int sensorLMax = 0;
int averageL;

int sensorRValue = 0;
int sensorRMin = 1023;
int sensorRMax = 0;
int averageR;

void setup() {
  Serial.begin(9600);

  if (!sm.begin()) {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }
  sm.setSpeed(50);
  sm.moveTo(5);
}

void loop() {
  int valL = analogRead(A0);
  int valR = analogRead(A1);

  Serial.println("========================================");
  Serial.println("valL=" + String(valL) + "////" + "valR=" + String(valR));
  Serial.println(String(averageL) + "////" + String(averageR));

  if (valL > sensitivityL(valL) && valR > sensitivityL(valR)) {
    sm.moveTo(2);
  }

  else if (valL > sensitivityL(valL) && valR < sensitivityL(valR)) {
    sm.rotate(CCW);
  }
  else if (valL < sensitivityL(valL) && valR > sensitivityL(valR)) {
    sm.rotate(CW);
  }

  else {
    sm.moveTo(2);
  }
  delay(10);
}

int sensitivityL(int ReadL) {
  sensorLValue = ReadL;
  if (sensorLValue > sensorLMax) {
    sensorLMax = sensorLValue;
  }
  if (sensorLValue < sensorLMin) {
    sensorLMin = sensorLValue;
  }
  averageL = (sensorLMax + sensorLMin) / 2;
  return averageL;
}

int sensitivityR(int ReadR) {
  sensorRValue = ReadR;
  if (sensorRValue > sensorRMax) {
    sensorRMax = sensorRValue;
  }
  if (sensorRValue < sensorRMin) {
    sensorRMin = sensorRValue;
  }
  averageR = (sensorRMax + sensorRMin) / 2;
  return averageR;
}
