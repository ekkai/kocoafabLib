// RC카 키트 - Piezo_4.ino
// 버튼이 눌리면 피에조 멜로디 연주 

// tone(핀번호, 주파수, 딜레이) : 해당 핀에 연결된 피에조 부저에 지정된 딜레이 간격으로 주파수의 음정을 출력.
// noTone(핀번호) : 해당 핀번호에 연결된 피에조의 연주를 멈춥니다. 


int numTones = 8;
int tones[] = {261, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
}

void loop() {
  if (digitalRead(7) == LOW) {
    for (int i = 0; i < numTones; i++) {
      tone(8, tones[i]);
      delay(500);
    }
    noTone(8);
  }
}
