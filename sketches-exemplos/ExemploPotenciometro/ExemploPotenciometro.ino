
int leds[] = { 11, 10, 9 };
int pot = A0;

int valorAnterior = 0;

void setup() {
  for (int i = 0; i < sizeof(leds); i++) {
    pinMode(leds[i], OUTPUT);
    analogWrite(leds[i], LOW);
  }

  Serial.begin(9600);
}

void loop() {
  int valorPot = analogRead(pot);

  // if (isNovoValor(valorPot)) {
  if (true) {
    valorAnterior = valorPot;

    Serial.print("Valor: ");
    Serial.println(valorPot);

    // controlarLeds(valorPot);
    controlarLeds2(valorPot);
  }

  delay(100);
}

bool isNovoValor(int valorPot) {
  if ((valorPot > valorAnterior) || (valorPot < valorAnterior)) {
    valorAnterior = valorPot;

    return true;
  }

  return false;
}

void controlarLeds2(int valor) {
  int novoValor = map(valor, 0, 1023, 0, 1000);

  for (int i = 0; i < sizeof(leds); i++) {
    digitalWrite(leds[i], HIGH);
  }

  delay(novoValor);

  for (int i = 0; i < sizeof(leds); i++) {
    digitalWrite(leds[i], LOW);
  }

  delay(novoValor);
}

void controlarLeds(int valor) {
  int novoValor = map(valor, 0, 1023, 0, 255);

  for (int i = 0; i < sizeof(leds); i++) {
    analogWrite(leds[i], novoValor);
  }
}
