#include "empresario.h"

Empresario::Empresario() : (const Endereco& endereco) : Pessoa(endereco) {
}

float Empresario::getInvestimento() {
	return this->investimentoInicial;
}

void Empresario::setInvestimento(const float & input) {
	this->investimentoInicial = input;
}