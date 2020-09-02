#include "empregado.h"

void Empregado::setSalarioBase(const float & input){
    this->salarioBase = input;
};

void Empregado::setIrs(const float & input){
    this->irs = input;
};

void Empregado::setNumeroSecao(const string & input){
    this->numeroSecao = input;
};

float Empregado::getSalarioBase(){
    return this->salarioBase;
};

float Empregado::getIrs(){
    return this->irs;
};

string Empregado::getNumeroSecao(){
    return this->numeroSecao;
};

float Empregado::calcularSalario(){
    return (this->getSalarioBase() * this->getIrs());
};
