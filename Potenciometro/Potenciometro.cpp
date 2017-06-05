#include "Potenciometro.h"

Potenciometro::Potenciometro(byte pino) {
	this -> pino = pino;
	setSetores(3);
	setDescricaoSetores(new String[3] { "Low", "Medium", "High" });
}

Potenciometro::Potenciometro(byte pino, int setores) {
	this -> pino = pino;
	setSetores(setores);
}

Potenciometro::Potenciometro(byte pino, String descricaoSetores[]) {
	this -> pino = pino;
	setSetores(sizeof(descricaoSetores));
	setDescricaoSetores(descricaoSetores);
}

// 0 - 1023
int Potenciometro::getValor() {
	return analogRead(this -> pino);
}

// MINIMO - MAXIMO
int Potenciometro::getValor(int minimo, int maximo) {
	return map(getValor(), MIN_VALUE, MAX_VALUE, minimo, maximo);
}

// 0 - 1023
// 0 - 341,3 - 682,6 - 1024
int Potenciometro::getSetor() {
	int setor = getValor() / (MAX_VALUE / this -> setores);

	if (setor >= this -> setores) {
		setor = this -> setores - 1;
	}

	return setor;
}

void Potenciometro::setSetores(int setores) {
	if (setores > MIN_VALUE && setores < MAX_VALUE) {
		this -> setores = setores;
	}
}

String Potenciometro::getDescricaoSetor() {
	return this -> descricaoSetores[getSetor()];
}

void Potenciometro::setDescricaoSetores(String descricaoSetores[]) {
	this -> descricaoSetores = descricaoSetores;
}