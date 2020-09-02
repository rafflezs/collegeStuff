#include "fornecedor.h"

void Fornecedor::setPlafond(const float & input){
    this->plafond = input;
};

void Fornecedor::setValorDivida(const float & input){
    this->valorDivida = input;
};

float Fornecedor::getPlafond(){
    return this->plafond;
};

float Fornecedor::getValorDivida(){
    return this->valorDivida;
};

float Fornecedor::obterSaldo(){
    return (this->getPlafond() - this->getValorDivida());
};