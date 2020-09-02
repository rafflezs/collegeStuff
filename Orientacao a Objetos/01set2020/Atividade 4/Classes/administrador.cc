#include "administrador.h"

void Administrador::setAjudaCusto(const float & input){
    this->ajudaCusto = input;
};
        
float Administrador::getAjudaCusto(){
    return this->ajudaCusto;
};

float Administrador::calcularSalario(){
    return (Empregado::calcularSalario() + this->getAjudaCusto());
};