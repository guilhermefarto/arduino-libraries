#include <Potenciometro.h>

Potenciometro potenciometro = Potenciometro(A0);
// Potenciometro potenciometro(A0);

// Potenciometro potenciometro = Potenciometro(A0, 10);
// Potenciometro potenciometro(A0, 10);

// Potenciometro potenciometro = Potenciometro(A0, new String[2] {"Sim", "Não"});
// Potenciometro potenciometro(A0, new String[2] {"Sim", "Não"});

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Valor: ");
  Serial.println(potenciometro.getValor() , DEC);

  Serial.print("Valor: ");
  Serial.println(potenciometro.getValor(0, 255) , DEC);

  Serial.print("Setor: ");
  Serial.println(potenciometro.getSetor() , DEC);

  Serial.print("Setor: ");
  Serial.println(potenciometro.getDescricaoSetor());

  Serial.println();

  delay(1000);
}
