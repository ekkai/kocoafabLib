// 미세먼지측정기(공기청정기) 키트 - auto_control_airpurifier.ino
// 프로젝트2 - 자동제어 모드 공기청정기

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include <dustSensor_kocoa.h>
#include <GUI.h>

// 입출력 장치 핀 번호 설정
#define DHTPIN 6
#define DHTTYPE DHT11

#define dustA 8
#define dustB 9

#define motorA 11
#define motorB 12
#define motorEn 5

dustSensor_kocoa PM;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

// 모터속도 및 로터리 엔코더 데이터 저장 변수
int motorSpeed = 0;

boolean prevA;
boolean prevSW;

// 미세먼지 센서 데이터 저장 변수
int data;
int pData;

// 온습도 센서 데이터 저장 변수
float humi = 0;
float temp = 0;

byte phase = 0;

void setup() {
  Serial.begin(9600);

  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);

  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);
  analogWrite(motorEn, 0);
    
  dht.begin();
  PM.begin(8, 9);

  lcd.init();
  lcd.backlight();

  // LCD에 출력될 온/습도, 미세먼지 아이콘
  lcd.createChar((byte)0, _temp);
  lcd.createChar(1, _humi);
  lcd.createChar(2, _dust);
  lcd.createChar(3, C);
} 

void loop() {
  // 온습도 및 미세먼지 측정
  getAirInfo();

  // Auto 모드일 시 미세먼지 값에 따라 자동으로 팬모터의 속도 조절
  autoMotorControl();
 
  // 측정된 결과를 LCD에 출력
  displayLCD();
}

// 온습도 및 미세먼지 측정 함수
void getAirInfo()
{
  // 온습도 및 미세먼지 측정(미세먼지 2.5pm 기준)
  humi = dht.readHumidity();
  temp = dht.readTemperature();
  data = PM.pm25Value();
  
  if(data>0){
    pData = data;
  }
  else
  {
    data=pData;
  }
  if (isnan(humi) || isnan(temp) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}
// 자동 모드시 모터 회전을 제어하는 함수
void autoMotorControl() {
  // 기준은 환경부 초미세먼지 환경기준으로 분류
  if (data > 75) {
    motorSpeed = 255;
  }
  else if (data > 35) {
    motorSpeed = 170;
  }
  else if (data > 15) {
    motorSpeed = 85;
  }
  else {
    motorSpeed = 0;
  }
  analogWrite(motorEn, motorSpeed);
}

void displayLCD()
{
   // LCD에 온습도 및 미세먼지 값 출력(아이콘도 같이 출력)
  // 미세먼지 출력
  lcd.setCursor(0, 0);
  lcd.write(2);
  lcd.print(" ");
  lcd.print(data);
  lcd.print(" ug");

  // 온도 출력
  lcd.setCursor(0, 1);
  lcd.write((byte)0);
  lcd.print(" ");
  lcd.print((int)temp);
  lcd.write(3);
  // 습도 출력
  lcd.print(" ");
  lcd.write(1);
  lcd.print(" ");
  lcd.print((int)humi);
  lcd.print("% ");

  lcd.setCursor(8, 0);
  lcd.print("Auto");
  
  //모터 출력 퍼센테이지 출력
  int percent = map(motorSpeed, 0, 255, 0, 100);  
  lcd.setCursor(13, 0);
  lcd.print("FAN");
  lcd.setCursor(12, 1);
   //값이 1의자리일 때
  if (percent < 10) {
    lcd.print("  ");
  }
  //값이 10의자리일 때
  else if (percent < 100) {
    lcd.print(" ");
  }
  lcd.print(percent);
  lcd.print("%");
  lcd.setCursor(12, 1);
}
