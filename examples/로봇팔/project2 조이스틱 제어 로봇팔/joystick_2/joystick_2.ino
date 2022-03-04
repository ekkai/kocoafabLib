int left_B = 6;
int right_B = 7;

void setup() {
  Serial.begin(9600);
  pinMode(left_B, INPUT_PULLUP);
  pinMode(right_B, INPUT_PULLUP);
}

void loop() {
  Serial.print("Lb:"); Serial.print(digitalRead(left_B));
  Serial.print(" / ");
  Serial.print("Rb:"); Serial.println(digitalRead(right_B));
  delay(10);
}
