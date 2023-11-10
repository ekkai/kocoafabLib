#include <Kocoafab_SmartMobility.h>
#include <COCOCAM.h>
#include <Wire.h>

COCOCAM cococam;
cococamResult result;
Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();

int r1=3;
int g1=5;
int b1=6;
int r2=9;
int g2=10;
int b2=11;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  cococam.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION);
  
  pinMode(r1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(b2, OUTPUT);
  
  sm.begin();
  sm.setSpeed(75);
  sm.moveTo(2);
}

void loop() {
  cococam.request();
  while (cococam.available()) {  
    result = cococam.read();
    Serial.println(result.ID);
  
  if(result.ID==1){
  digitalWrite(r1, HIGH);
  digitalWrite(g1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(g2, LOW);
  digitalWrite(b2, LOW);
  sm.moveTo(5,3000);
  sm.moveTo(2,1500);
  }

if(result.ID==2){
  digitalWrite(r1, HIGH);
  digitalWrite(g1, HIGH);
  digitalWrite(b1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(g2, HIGH);
  digitalWrite(b2, LOW);

  sm.setSpeed(40);
  sm.moveTo(2,3000);
 }

if(result.ID==3){
  digitalWrite(r1, LOW);
  digitalWrite(g1, HIGH);
  digitalWrite(b1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(g2, HIGH);
  digitalWrite(b2, LOW);

  sm.setSpeed(100);
  sm.moveTo(2,2000);
  }
  digitalWrite(r1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(b2, LOW);
  sm.setSpeed(75);
  sm.moveTo(2);
  } 
}
