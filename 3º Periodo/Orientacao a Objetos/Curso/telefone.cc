#include "telefone.h"

int Telefone::getDDD(){
	return this->ddd;
}

void Telefone::setDDD(const int & temp){
	this->ddd = temp;
}

string Telefone::getNumero(){
	return this->numero;
}

void Telefone::setNumero(const string & temp){
	this->numero = temp;
}