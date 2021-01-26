#include "operario.h"

void Operario::setValorProducao(const float & input){
    this->valorProducao = input;
};

void Operario::setComissao(const float & input){
    this->comissao = (this->valorProducao * 0.1);
};

float Operario::getValorProducao(){
    return this->valorProducao;
};

float Operario::getComissao(){
    return this->comissao;
};

float Operario::calcularSalario(){
    return (Empregado::calcularSalario() + this->getComissao());
};
