#include "matricial.h"

void Matricial::setNumAgulhas(const int& input) {
	this->numAgulhas = input;
}

int Matricial::getNumAgulhas() {
	return numAgulhas;
}

void Matricial::setImprimeVias(const bool& input) {
	this->imprimeVias = input;
}

bool Matricial::doesImprimeVias() {
	return imprimeVias;
}
