#include "SetSeg.h"

SetSeg::SetSeg(int pinos[], int tipo) {
	for (int i = 0; i < DEFAULT_NUMBER_SEGS + 1; i++) {
		this -> pinos[i] = pinos[i];
	}
	
	configurarTipo(tipo);
	
	controlarPonto(this -> estadoOff);
	limpar();
}

void SetSeg::init() {
	for (int i = 0; i < DEFAULT_NUMBER_SEGS + 1; i++) {
		pinMode(this -> pinos[i], OUTPUT);
		digitalWrite(this -> pinos[i], this -> estadoOff);
	}
}

void SetSeg::configurarTipo(int tipo) {
	// CATODO
	this -> estadoOn = HIGH;
	this -> estadoOff = LOW;

	if (tipo == ANODO) {
		this -> estadoOn = LOW;
		this -> estadoOff = HIGH;
	}
}

void SetSeg::limpar() {
	for (int i = 0; i < DEFAULT_NUMBER_SEGS + 1; i++) {
		digitalWrite(this -> pinos[i], this -> estadoOff);
    }
}

void SetSeg::imprimirNumero(int numero) {
	for (int contador = 0; contador < DEFAULT_NUMBER_SEGS; contador++) {
		byte estadoSegmento = digitos[numero][contador] ? estadoOn : estadoOff;
		
		digitalWrite(this -> pinos[contador], estadoSegmento);
    }
}

void SetSeg::contar() {
	for (int i = 0; i < SIZE_DIGITOS; i++) {
		imprimirNumero(i);
		
		delay(DEFAULT_DELAY);
	}
}

int encontrarPosicaoCaractere(char caractere) {
	for (int i = 0; i < SIZE_ALFABETO; i++) {
		// if (caractere == alfabeto[i]) {
		if (String(caractere).equalsIgnoreCase(String(alfabeto[i]))) {
			return i;
		}
	}

	return -1;
}

void SetSeg::imprimirCaractere(char caractere) {
	int indexCaractere = encontrarPosicaoCaractere(caractere);
	
	if (indexCaractere != -1) {
		for (int contador = 0; contador < DEFAULT_NUMBER_SEGS; contador++) {
			byte estadoSegmento = caracteres[indexCaractere][contador] ? estadoOn : estadoOff;
			
			digitalWrite(this -> pinos[contador], estadoSegmento);
		}
	}
}

void SetSeg::imprimirAlfabeto() {
	for (int i = 0; i < SIZE_ALFABETO; i++) {
		imprimirCaractere(alfabeto[i]);
		
		delay(DEFAULT_DELAY);
	}
}

void SetSeg::imprimirTexto(String texto) {
	imprimirTexto(texto, SECOND);
}

void SetSeg::imprimirTexto(String texto, int delayInSeconds) {
	int customDelay = delayInSeconds == SECOND ? SECOND : delayInSeconds * SECOND;
	
	for (int i = 0; i < texto.length(); i++) {
		imprimirCaractere(texto.charAt(i));
		
		delay(customDelay);
	}
}

void SetSeg::controlarPonto(byte valor) {
	digitalWrite(DEFAULT_PERIOD_PORT, valor);
}