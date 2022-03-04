// 아크릴램프 키트 - bluetooth_2.ino
// 블루투스 통신을 활용한 네오픽셀 LED 색상 설정

#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>


SoftwareSerial BTSerial(4, 5);
Adafruit_NeoPixel strip =  Adafruit_NeoPixel(3, 6, NEO_GRB + NEO_KHZ800);

char data;

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
  strip.begin();
}

void loop() {
  // BLE모듈을 통해 전송된 데이터가 있을 때
  if (BTSerial.available()) {
    data = BTSerial.read();
    Serial.write(data);
    // data가 '1'이라면 
    if (data == '1') {
      for (int i = 0; i < 3; i++) {
        strip.setPixelColor(i, R, G, B); // R, G, B 위치에 각각 색상값 작성
        strip.show();
      }
    }
    // data가 '2'라면 
    if (data == '2') {
      for (int i = 0; i < 3; i++) {
        strip.setPixelColor(i, R, G, B); // R, G, B 위치에 각각 색상값 작성
        strip.show();
      }
    }
    // data가 '3'이라면 
    if (data == '3') {
      for (int i = 0; i < 3; i++) {
        strip.setPixelColor(i, R, G, B); // R, G, B 위치에 각각 색상값 작성
        strip.show();
      }
    }
    // data가 '4'라면 
    if (data == '4') {
      for (int i = 0; i < 3; i++) {
        strip.setPixelColor(i, 255, 255, 255); // 흰색으로 설정
        strip.show();
      }
    }
    // data가 '5'라면 
    if (data == '5') {
      for (int i = 0; i < 3; i++) {
        strip.setPixelColor(i, 0, 0, 0); // 0으로 설정(LED 끄기)
        strip.show();
      }
    }
  }
}
