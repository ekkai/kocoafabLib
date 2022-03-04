// 미세먼지측정기(공기청정기) 키트 - manual_control_airpurifier.ino
// 수동제어 모드 공기청정기

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include <dustSensor_kocoa.h>
#include <GUI.h>

// 핀 번호 설정
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


// 모터 및 로터리 엔코더 데이터 저장 변수

int motorSpeed = 0;

boolean prevA= HIGH;
int data;
int pData;

// 온습도 센서 데이터 저장 변수
float humi = 0;
float temp = 0;

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

  attachInterrupt(0, setMotorSpeed, CHANGE);
}

void loop() {
  // 온습도 및 미세먼지 측정
  getAirInformation();
  Serial.print("Motor: ");
  Serial.println(motorSpeed);
  // 측정된 결과를 LCD에 출력
  displayLCD(); 
}

// 로터리 인코더 회전 방향 확인 함수
int getEncoder() {
  int result=0;
  int newA = digitalRead(encoderA);

  // 로터리 인코더의 회전 방향에 따라 모터의 속도를 5단위로 조절
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
  prevA = newA;

  return result;
 
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
void displayLCD()
{
  // LCD에 온습도 및 미세먼지 값 출력(아이콘도 같이 출력)
  lcd.setCursor(0, 0);
  lcd.write(2);
  lcd.print(" ");

  lcd.print(data);

  lcd.print(" ug");
  lcd.print("  ");

  lcd.setCursor(0, 1);
  lcd.write((byte)0);
  lcd.print(" ");
  lcd.print((int)temp);
  lcd.write(3);

  lcd.print(" ");
  lcd.write(1);
  lcd.print(" ");
  lcd.print((int)humi);
  lcd.print("% ");
  
  //모터 출력 퍼센테이지 출력
  
  int value = map(motorSpeed, 0, 255, 0, 100);
  lcd.setCursor(13, 0);
  lcd.print("FAN");
  lcd.setCursor(12, 1);
   //값이 1의자리일 때
  if (value < 10) {
    lcd.print("  ");
  }
  //값이 10의자리일 때
  else if (value < 100) {
    lcd.print(" ");
  }
  lcd.print(value);
  lcd.print("%");
  lcd.setCursor(12, 1);
}

//엔코더 방향값을 토대로 모터 속도 설정 함수
void setMotorSpeed()
{
  int interval = 5;
  motorSpeed += interval * getEncoder();
  motorSpeed = constrain(motorSpeed, 0, 255);
  analogWrite(motorEn, motorSpeed);
}
