#include "vendedor.h"

void Vendedor::setValorVendas(const float & input){
    this->valorVendas = input;
};

void Vendedor::setComissao(const float & input){
    this->comissao = (this->valorVendas * 0.1);
};

float Vendedor::getValorVendas(){
    return this->valorVendas;
};

float Vendedor::getComissao(){
    return this->comissao;
};

float Vendedor::calcularSalario(){
    return (Empregado::calcularSalario() + this->getComissao());
};
