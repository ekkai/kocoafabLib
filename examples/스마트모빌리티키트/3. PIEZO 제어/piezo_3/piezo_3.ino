int c = 262;
int d = 294; 
int e = 330; 
int f = 349;
int g = 392; 
int a = 440; 
int b = 494; 

int notes[25] = { g, g, a, a, g, g, e, g, g, e, e, d, g, g, a, a, g, g, e, g, e, d, e, c }; 

void setup() { 
} 

void loop() { 
  for (int i = 0; i < 12; i++) { 
    tone (8, notes[i], 200); 
    delay (300); 
  } 
  delay(100);

  for (int i = 12; i < 25; i++) { 
    tone (8, notes[i], 200); 
    delay(300); 
  } 
}
