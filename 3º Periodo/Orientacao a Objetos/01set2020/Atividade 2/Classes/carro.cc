#include "carro.h"

void Carro::setNumPortas(const int &input){
    this->numPortas = input;
};

void Carro::setPlaca(const string &input){
    this->placa = input;
};

int Carro::getNumPortas(){
    return this->numPortas;
};

string Carro::getPlaca(){
    return this->placa;
};
