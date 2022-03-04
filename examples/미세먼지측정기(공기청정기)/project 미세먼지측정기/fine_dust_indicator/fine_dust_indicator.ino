// 미세먼지측정기(공기청정기) 키트 - fine_dust_indicator.ino
// 미세먼지측정기 완성 코드

#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <emotion.h>
#include <dustSensor_kocoa.h>

#define DHTPIN 6                       //온습도 센서 핀 번호
#define DHTTYPE DHT11                  //온습도 센서 종류(DHT11타입)

dustSensor_kocoa PM;
LiquidCrystal_I2C lcd(/*I2C LCD 주소 입력*/, 16, 2);    //I2C LCD 주소 작성 필요(0x3F, 0x27 중 선택) 

DHT dht(DHTPIN, DHTTYPE);

void setEmoticon(float data) {
  if (data > 150) { //미세먼지 상태가 '매우 나쁨'일 때
    lcd.createChar(4, topAngry1);
    lcd.createChar(5, topAngry2);
    lcd.createChar(6, bottomAngry1);
    lcd.createChar(7, bottomAngry2);
    // 화난표정 생성
    
    analogWrite(9,255);
    analogWrite(10,0);
    analogWrite(11,0);
    // 빨간색 점등
  }
  else if (data > 80) { //미세먼지 상태가 '나쁨'일 때
    lcd.createChar(4, topAngry1);
    lcd.createChar(5, topAngry2);
    lcd.createChar(6, bottomAngry1);
    lcd.createChar(7, bottomAngry2);
    // 화난표정 생성
    
    analogWrite(9,255);
    analogWrite(10,50);
    analogWrite(11,0);
    // 주황색 점등
  }
  else if (data > 30) { //미세먼지 상태가 '보통'일 때
    lcd.createChar(4, topSoSo1);
    lcd.createChar(5, topSoSo2);
    lcd.createChar(6, bottomSoSo1);
    lcd.createChar(7, bottomSoSo2);
    // 무표정 생성
    
    analogWrite(9,255);
    analogWrite(10,255);
    analogWrite(11,0);
    // 노랑색 점등
  }

  else {  //미세먼지 상태가 '좋음'일 때
    lcd.createChar(4, topSmile1);
    lcd.createChar(5, topSmile2);
    lcd.createChar(6, bottomSmile1);
    lcd.createChar(7, bottomSmile2);
    // 웃는표정 생성
    
    analogWrite(9,0);
    analogWrite(10,255);
    analogWrite(11,0);
    // 녹색 점등
  }
}

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar((byte)0, temp); // 온도계 아이콘 생성
  lcd.createChar(1, humi); // 습도 아이콘 생성
  lcd.createChar(2, dust); // 먼지 아이콘 생성
  lcd.createChar(3, C); // 섭씨 단위 아이콘 생성

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);

  dht.begin();
  PM.begin(2, 3);
}

void loop() {
  float humi = dht.readHumidity(); // 온습도 센서 습도 값 저장
  float temp = dht.readTemperature(); // 온습도 센서 온도 값 저장

  if (isnan(humi) || isnan(temp) ) {
    Serial.println("Failed to read from DHT sensor!"); 
    return;
  }

  int data = PM.pm10Value(); // 미세먼지센서 미세먼지 값 저장

  Serial.println(data); 
  

  setEmoticon(data); // 미세먼지 값을 토대로 이모티콘 문자 생성 setEmoticon 함수 정의 참조

  // LCD에 문자 및 데이터 출력
  lcd.setCursor(0, 0);
  lcd.write(2);
  lcd.print(" ");
  lcd.print(data);

  if (data >= 100)
    lcd.print(" ug");
  else if (data >= 10)
    lcd.print(" ug ");
  else
    lcd.print(" ug  ");

  lcd.setCursor(0, 1);
  lcd.write((byte)0);
  lcd.print(" ");
  lcd.print((int)temp);
  lcd.write(3);

  lcd.print(" ");
  lcd.write(1);
  lcd.print(" ");
  lcd.print((int)humi);
  lcd.print("%");

  lcd.setCursor(13, 0);
  lcd.write(4);
  lcd.write(5);

  lcd.setCursor(13, 1);
  lcd.write(6);
  lcd.write(7);

  delay(500);
}
