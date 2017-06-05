
#ifndef Potenciometro_H
#define Potenciometro_H

#if defined(ARDUINO) && ARDUINO < 100
#include "WProgram.h"
#else
#include "Arduino.h"
#endif

const int MIN_VALUE = 0;
const int MAX_VALUE = 1024;

class Potenciometro {
	public:
		Potenciometro(byte pino);
		Potenciometro(byte pino, int setores);
		Potenciometro(byte pino, String descricaoSetores[]);
			
		int getValor();
		int getValor(int minimo, int maximo);
		// pot1.getValor(0, 255);
		// pot2.getValor();
		// pot3.getValor(-100, 100);
		// pot4.getValor(0, 360);

		int getSetor();
		void setSetores(int setores);		
			
		String getDescricaoSetor();
		void setDescricaoSetores(String descricaoSetores[]);
		
	private:
		byte pino;
		int setores;
		String *descricaoSetores;
};

#endif