#include <Kocoafab_SmartMobility.h>
#include <COCOCAM.h>
#include <Wire.h>

COCOCAM cococam;
cococamResult result;
Kocoafab_SmartMobility sm = Kocoafab_SmartMobility();
int button = 7;
int ledR=9;
int ledG=10;
int ledB=11;
int myID=1; 
bool isChecked = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  cococam.begin(Wire);
  cococam.writeAlgorithm(ALGORITHM_FACE_RECOGNITION);
  sm.begin();
  pinMode(button, INPUT);
}
void loop() {
 cococam.request();
  while (cococam.available()) {
    result = cococam.read();
    Serial.println(result.ID);
  }
  if(result.ID!=myID){
  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
  sm.moveTo(5);
  isChecked= false;
 }
 else{
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledB, LOW);
  isChecked = true;
 }

if(isChecked)
 {
  sm.setSpeed(150);
  int buttonValue = digitalRead(button);
  if(!buttonValue)
   { 
      sm.moveTo(2);  
      delay(1000);
   }
     sm.moveTo(5);
   }
 }
