// 아크릴램프 키트 - neopixel_1.ino
// 네오픽셀 LED 기초 제어 

// strip.begin() : 네오픽셀 LED 사용 설정
// strip.setPixelColor(위치, R, G, B) : 해당 위치의 LED의 R,G,B 색상 값 설정 (show()를 호출하기 전까진 보이지 않음) 
// strip.show() : 모든 네오픽셀 LED에 적용된 색상 보이기

#include <Adafruit_NeoPixel.h>

// 네오픽셀 객체 strip 선언 (LED 갯수, 핀번호, 네오픽셀 타입) 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); 
}

void loop() {
  strip.setPixelColor(0, 0, 0, 0); // 0번째 위치 LED 색상(0,0,0) 설정 
  strip.setPixelColor(1, 0, 0, 0); // 1번째 위치 LED 색상(0,0,0) 설정 
  strip.setPixelColor(2, 0, 0, 0); // 2번째 위치 LED 색상(0,0,0) 설정 
  strip.show(); // 모든 LED에 적용된 색상 보이기
  delay(1000); // 1000 밀리초 대기

  strip.setPixelColor(0, 255, 0, 0); // 0번째 위치 LED 색상(255,0,0) 설정 
  strip.setPixelColor(1, 255, 0, 0); // 1번째 위치 LED 색상(255,0,0) 설정 
  strip.setPixelColor(2, 255, 0, 0); // 2번째 위치 LED 색상(255,0,0) 설정 
  strip.show(); // 모든 LED에 적용된 색상 보이기
  delay(1000); // 1000 밀리초 대기
}
