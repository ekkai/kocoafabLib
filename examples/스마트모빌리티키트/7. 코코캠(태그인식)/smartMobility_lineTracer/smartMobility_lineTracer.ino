#include <Kocoafab_SmartMobility.h>

Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();

int sensitivity = 50;

int leftLED = 5;
int rightLED = 10;

void setup() {
  Serial.begin(9600);

  if (!sm.begin()) {
    Serial.println("모터 쉴드 연결을 다시 확인해주세요.");
    while (1);
  }
  sm.setSpeed(100);
  sm.moveTo(5);

  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
}

void loop() {
  if (analogRead(A0) > sensitivity && analogRead(A1) > sensitivity) {
    sm.moveTo(2);

    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, LOW);
  }

  else if (analogRead(A0) > sensitivity && analogRead(A1) < sensitivity) {
    sm.rotate(CCW);
    digitalWrite(leftLED, HIGH);
    digitalWrite(rightLED, LOW);
  }
  else if (analogRead(A0) < sensitivity && analogRead(A1) > sensitivity) {
    sm.rotate(CW);
    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, HIGH);
  }

  else if (analogRead(A0) < sensitivity && analogRead(A1) < sensitivity) {
    sm.moveTo(2);

    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, LOW);
  }
  delay(10);
}
