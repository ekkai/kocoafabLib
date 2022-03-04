int left_X = A0; 
int left_Y = A1;
int right_X = A2;
int right_Y = A3;

void setup() {
 Serial.begin(9600);
}

void loop() {
 Serial.print("Lx:"); Serial.print(analogRead(left_X)); 
 Serial.print(" Ly:"); Serial.print(analogRead(left_Y));
 Serial.print(" / ");
 Serial.print("Rx:"); Serial.print(analogRead(right_X)); 
 Serial.print(" Ry:"); Serial.println(analogRead(right_Y));
 delay(10);
}
