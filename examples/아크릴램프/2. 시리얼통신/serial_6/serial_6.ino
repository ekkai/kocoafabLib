// 아크릴램프 키트 - serial_6.ino
// serial 전송 값을 판별하여 네오픽셀 LED 점등

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.available() : 시리얼통신을 통해 유효한 값이 전송 되었을 때 true
// Serial.read() : 시리얼통신을 통해 전송 받은 값을 읽어 저장 변수에 저장
// Serial.print(ln)("문장" or 변수) : 변수 데이터를 시리얼 통신을 통해 출력

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, 6, NEO_GRB + NEO_KHZ800);

char data;

void setup() {
  Serial.begin(9600);
  strip.begin();
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();

    if (data == '1') {
      Serial.println("LED ON");
      for (int i = 0; i < 3; i++) {
        strip.setPixelColor(i, 255, 255, 255);
        strip.show();
      }
    }

    if (data == '2') {
      Serial.println("LED OFF");
      for (int i = 0; i < 3; i++) {
        strip.setPixelColor(i, 0, 0, 0);
        strip.show();
      }
    }
  }
}
