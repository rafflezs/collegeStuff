#include "cachorro.h"

void Cachorro::setFaro(const float & input){
    this->distanciaFaro = input;
};

void Cachorro::setLatido(const float & input){
    this->intensidadeLatido = input;
};

float Cachorro::getFaro(){
    return this->distanciaFaro;
};

float Cachorro::getLatido(){
    return this->intensidadeLatido;
};
