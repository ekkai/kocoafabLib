// 아크릴램프 키트 - neopixel_2.ino
// 반복문을 활용한 다수의 네오픽셀 LED 제어

// strip.begin() : 네오픽셀 LED 사용 설정
// strip.setPixelColor(위치, R, G, B) : 해당 위치의 LED의 R,G,B 색상 값 설정 (show()를 호출하기 전까진 보이지 않음) 
// strip.show() : 모든 네오픽셀 LED에 적용된 색상 보이기

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
   for (int i = 0; i < 3; i++) { // i값이 0일때부터 3회간 1씩 증가 반복
    strip.setPixelColor(i, 0, 0, 0); // i 번째(0,1,2) 네오픽셀 LED에 색상(0,0,0) 설정
  }
  strip.show(); 
  delay(1000); 

 for (int i = 0; i < 3; i++) { // i값이 0일때부터 3회간 1씩 증가 반복
    strip.setPixelColor(i, 255, 0, 0); // i 번째(0,1,2) 네오픽셀 LED에 색상(0,0,0) 설정
  }
  strip.show(); 
  delay(1000);
}
