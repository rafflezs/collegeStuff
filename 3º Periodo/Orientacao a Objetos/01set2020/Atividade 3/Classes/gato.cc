#include "gato.h"

void Gato::setAlturaPulo(const float & input){
    this->alturaPulo = input;
};

void Gato::setPeloLongo(const bool & input){
    this->peloLongo = input;
};

int Gato::getAlturaPulo(){
    return this->alturaPulo;
};

bool Gato::hasPeloLongo(){
    return this->peloLongo;
};
