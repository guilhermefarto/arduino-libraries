#include <SetSeg.h>

int portas[] = {2, 3, 4, 5, 6, 7, 8, 9};

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

SetSeg display7(portas, CATODO);

void setup() {
  Serial.begin(9600);
  
  display7.init();
  
  display7.controlarPonto(LOW);
}

void loop() {
  display7.imprimirNumero(0); // 0

  delay(DEFAULT_DELAY);
  
  display7.imprimirNumero(1); // 5
  
  delay(DEFAULT_DELAY);
  
  display7.imprimirCaractere('a'); // A

  delay(DEFAULT_DELAY);
  
  display7.imprimirCaractere('d'); // D
  
  delay(DEFAULT_DELAY);
  
  display7.contar();
  
  display7.limpar();

  delay(DEFAULT_DELAY);

  display7.imprimirAlfabeto();
  
  display7.limpar();

  delay(DEFAULT_DELAY);

  display7.imprimirTexto("EDcbA");
  
  display7.limpar();

  delay(DEFAULT_DELAY);
}
