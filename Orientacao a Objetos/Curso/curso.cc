#include "curso.h"

string Curso::getNome(){
	return this->nome;
}

void Curso::setNome(const string & temp){
	this->nome = temp;
}

string Curso::getContProg(){
	return this->contProg;
}

void Curso::setContProg(const string & temp){
	this->contProg = temp;
}

float Curso::getValor(){
	return this->valor;
}

void Curso::setValor(const float & temp){
	this->valor = temp;
}

int Curso::getCargaHoraria(){
	return this->cargaHoraria;
}

void Curso::setCargaHoraria(const int & temp){
	this->cargaHoraria = temp;
}