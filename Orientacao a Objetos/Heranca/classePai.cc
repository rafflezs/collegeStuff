#include "Pai.h"

Pai::Pai(){
    setSobrenome("Satanas");
}

void Pai::setNome(const std::string & input){
    this->nome = input;
}

std::string Pai::getNome(){
    return this->nome;
}

void Pai::setSobrenome(const std::string & input){
    this->sobrenome = input;
}

std::string Pai::getSobrenome(){
    return this->sobrenome;
}