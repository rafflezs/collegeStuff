#include "cliente.h"

void Cliente::setPlafond(const float & input){
    this->plafond = input;
};

void Cliente::setValorDivida(const float & input){
    this->valorDivida = input;
};

float Cliente::getPlafond(){
    return this->plafond;
};

float Cliente::getValorDivida(){
    return this->valorDivida;
};

float Cliente::obterSaldo(){
    return (this->getPlafond() - this->getValorDivida());
};