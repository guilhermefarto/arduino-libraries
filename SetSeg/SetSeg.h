
#ifndef SetSeg_H
#define SetSeg_H

#if defined(ARDUINO) && ARDUINO < 100
#include "WProgram.h"
#else
#include "Arduino.h"
#endif

const int SECOND = 1000;
const int DEFAULT_DELAY = 1 * SECOND;

const int DEFAULT_PERIOD_PORT = 9;
const int DEFAULT_NUMBER_SEGS = 7;

const boolean T = true;
const boolean F = false;

const int CATODO = 0;
const int ANODO = 1;

const byte digitos[2][DEFAULT_NUMBER_SEGS] = {
    { T,T,T,T,T,T,F }, // = 1
    { T,F,T,T,F,T,T }  // = 5
};

const char alfabeto[] = {'a', 'b', 'c', 'd', 'e'};

const byte caracteres[5][DEFAULT_NUMBER_SEGS] = {
    { T,T,T,F,T,T,T }, // = A
    { F,F,T,T,T,T,T }, // = b
	{ T,F,F,T,T,T,F }, // = C
	{ F,T,T,T,T,F,T }, // = d
	{ T,F,F,T,T,T,T }  // = E
};

const int SIZE_DIGITOS = 2;
// const int SIZE_DIGITOS = sizeof(digitos) / sizeof(byte);
// const int SIZE_DIGITOS = sizeof(digitos) / sizeof(digitos[0]);
// const int SIZE_DIGITOS = sizeof(digitos) / sizeof(*(digitos[0]));

const int SIZE_ALFABETO = 5;
// const int SIZE_ALFABETO = sizeof(alfabeto) / sizeof(char);
// const int SIZE_ALFABETO = sizeof(alfabeto) / sizeof(*(alfabeto));

class SetSeg {
	public:
		SetSeg(int pinos[], int tipo);

		void init();

		void configurarTipo(int tipo);

		void limpar();

		void imprimirNumero(int numero);

		void contar();

		void imprimirCaractere(char caractere);

		void imprimirAlfabeto();
		void imprimirTexto(String texto);
		void imprimirTexto(String texto, int delay);

		void controlarPonto(byte valor);

	private:
		int pinos[DEFAULT_NUMBER_SEGS + 1];
		byte estadoOn;
		byte estadoOff;
};

#endif