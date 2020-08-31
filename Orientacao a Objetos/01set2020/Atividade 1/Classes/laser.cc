#include "laser.h"

void Laser::setCapacidadeToner(const float& input) {
	this->capacidadeToner = input;
}

int Laser::getCapacidadeToner() {
	return this->capacidadeToner;
}

void Laser::setFrenteVerso(const bool& input){
	this->frenteVerso = input;
}

bool Laser::isFrenteVerso() {
	return this->frenteVerso;
}