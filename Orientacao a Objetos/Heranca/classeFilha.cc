#include "Filho.h"

Filho::Filho(const std::string & input) : Pai(){
    setNome(input);
    setSobrenome();
}

std::string Filho::getNome(){
    return this->nome;
}

void Filho::setNome(const std::string & input){
    this->nome = input;
}

std::string Filho::getSobrenome(){
    return this->sobrenome;
}

void Filho::setSobrenome(){
    this->sobrenome = Pai::getSobrenome();
}