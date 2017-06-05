
// API = Application Program Interface

byte portas[] = {2, 3, 4, 5, 6, 7, 8, 9};

/*
  Arduino Pin 2   =   Seg Pin 7
  Arduino Pin 3   =   Seg Pin 6
  Arduino Pin 4   =   Seg Pin 4
  Arduino Pin 5   =   Seg Pin 2
  Arduino Pin 6   =   Seg Pin 1
  Arduino Pin 7   =   Seg Pin 9
  Arduino Pin 8   =   Seg Pin 10
  Arduino Pin 9   =   Seg Pin 5
  Arduino GND     =   Seg Pin 3 and Pin 8
*/

void setup() {
  for (int i=0; i<sizeof(portas); i++) {
    pinMode(portas[i], OUTPUT);
  }
}

void loop() {
  controlar7Seg(HIGH);

  delay(1000);

  controlar7Seg(LOW);
}

void controlar7Seg(byte valor) {
  for (int i=0; i<sizeof(portas); i++) {
    digitalWrite(portas[i], valor);
    
    delay(100);
  }
}
