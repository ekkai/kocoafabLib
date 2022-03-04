// RC카 키트 - Piezo_2.ino
// 저장된 멜로디를 피에조에 출력

// tone(핀번호, 주파수, 딜레이) : 해당 핀에 연결된 피에조 부저에 지정된 딜레이 간격으로 주파수의 음정을 출력
// int notes[16] : 0~15번째 위치에 각각 int형 변수를 저장 할 수 있는 16칸 크기의 int형 배열 

int c  = 262;
int d  = 294;
int e  = 330;
int f  = 349;
int g  = 392;
int a  = 440;
int b  = 494;
int c1  = 523;

int notes[16] = {c, d, e, f, g, a, b, c1, c1, b, a, g, f, e, d, c };

void setup() {
}

void loop() {
  for (int i = 0; i < 8; i++) {
    tone (8, notes[i], 200);
    delay(300);
  }

  delay(100);

  for (int i = 8; i < 16; i++) {
    tone (8, notes[i], 200);
    delay(300);
  }
}
