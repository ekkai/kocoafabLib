// 미세먼지측정기(공기청정기) 키트 - integrated_control_airpurifier.ino
// 프로젝트3 - 통합제어 모드 공기청정기

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

#define encoderA 2
#define encoderB 3
#define encoderSW 7

#define motorA 11
#define motorB 12
#define motorEn 5

dustSensor_kocoa PM;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

boolean mode;
// 모터속도 및 로터리 엔코더 데이터 저장 변수
int motorSpeed = 0;

boolean prevA=HIGH;
boolean prevSW;

// 미세먼지 센서 데이터 저장 변수
int data;
int pData;

// 온습도 센서 데이터 저장 변수
float humi = 0;
float temp = 0;
byte level = 0;

void setup() {
  Serial.begin(9600);

  pinMode(encoderA, INPUT);
  pinMode(encoderB, INPUT);
  pinMode(encoderSW, INPUT_PULLUP);

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

  // 공기청정기 시작 시 기본 제어 모드 설정 
  // Auto = 1, Manual = 0
  mode=0; 
} 

void loop() {
  // 온습도 및 미세먼지 측정
  getAirInformation();

  // Auto 모드일 시 미세먼지 값에 따라 자동으로 팬모터의 속도 조절
  if(mode == 0)
  {
    attachInterrupt(0, manualMotorControl, CHANGE);
  }
  else if (mode == 1) {
    detachInterrupt(0);
    autoMotorControl(data);
  }

  // 모터 속도에 따라 게이지 바 세팅
  setGauge();
  
  // 측정된 결과를 LCD에 출력
  displayLCD();

  // 로터리 버튼이 눌려지면 Auto <ㅡ> Manual 모드로 변경한다.
  checkButton();

}

// 온습도 및 미세먼지 측정 함수
void getAirInformation()
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

void manualMotorControl()
{
  int interval = 5;
  motorSpeed += interval * getEncoder();
  motorSpeed = constrain(motorSpeed, 0, 255);
  analogWrite(motorEn, motorSpeed);
  level = motorSpeed / 64;
  Serial.print("Motor: ");
  Serial.println(motorSpeed);
}

// 로터리 인코더 회전 방향 확인 함수
int getEncoder() {
  int result = 0;
  int newA = digitalRead(encoderA);
  if (prevA != newA) {
    int newB = digitalRead(encoderB);
    if(newB != newA)
    {
      result = 1;
    } 
    else{
      result -= 1;
    }
  }
  prevA=newA;
  return result;
}

// 자동 모드시 모터 회전을 제어하는 함수
void autoMotorControl(int data) {
  // 기준은 환경부 초미세먼지 환경기준으로 분류
  if (data > 75) {
    motorSpeed = 255;
    level = 3;
  }
  else if (data > 35) {
    motorSpeed = 170;
    level = 2;
  }
  else if (data > 15) {
    motorSpeed = 85;
    level = 1;
  }
  else {
    motorSpeed = 0;
    level = 0;
  }
  analogWrite(motorEn, motorSpeed);
}

// 모터 속도의 따라 LCD에 게이지 바를 출력할 때 출력 될 특수문자를 정해주는 함수
//  _f는 차있는 게이지, _e는 비어있는 게이지
void setGauge() {
  
  if (level == 0) {
    lcd.createChar(4, gauge1_e);
    lcd.createChar(5, gauge2_e);
    lcd.createChar(6, gauge3_e);
  }
  else if (level == 1) {
    lcd.createChar(4, gauge1_f);
    lcd.createChar(5, gauge2_e);
    lcd.createChar(6, gauge3_e);
  }
  else if (level == 2) {
    lcd.createChar(4, gauge1_f);
    lcd.createChar(5, gauge2_f);
    lcd.createChar(6, gauge3_e);
  }
  else if (level == 3) {
    lcd.createChar(4, gauge1_f);
    lcd.createChar(5, gauge2_f);
    lcd.createChar(6, gauge3_f);
  }
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
  lcd.print("  ");
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

  // 현재 조작 모드 출력 
  lcd.setCursor(10, 0);
  if(mode == 0)
  {
    lcd.print("M");
  }
  else if(mode == 1)
  {
    lcd.print("A");
  }
  
  // 모터 스피드 % 출력
  int percent = map(motorSpeed, 0, 255, 0, 100);
  lcd.setCursor(12, 0);
  if (percent < 10) { // %가 1의 자리일때 공백 2칸 추가
  lcd.print("  ");
}
  else if (percent < 100) { // %가 10의 자리일때 공백 1칸 추가
    lcd.print(" ");
  }
  lcd.print(percent);
  lcd.print("%");
  
  // 모터 스피드 게이지 표시 출력
  lcd.setCursor(12, 1);
  lcd.write(4); 
  lcd.write(5);
  lcd.write(6);
  lcd.print("P");
}

void checkButton()
{
  boolean newSW = digitalRead(encoderSW);
  if (prevSW == HIGH && newSW == LOW) {
    changeMode();
  }
  prevSW=newSW;
}


void changeMode()
{
  mode = !mode;
  Serial.print("Mode : ");
  Serial.println(mode);
}
