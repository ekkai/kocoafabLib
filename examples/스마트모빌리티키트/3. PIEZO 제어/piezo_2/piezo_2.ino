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
