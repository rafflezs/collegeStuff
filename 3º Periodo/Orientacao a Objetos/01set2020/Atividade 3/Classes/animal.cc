#include "animal.h"

void Animal::setRaca(const string & input){
    this->raca = input;
};

void Animal::setCor(const string & input){
    this->cor = input;
};

void Animal::setNasc(const string & input){
    this->nascimento = input;
};

void Animal::setPreco(const float & input){
    this->preco = input;
};

string Animal::getRaca(){
    return this->raca;
};

string Animal::getCor(){
    return this->cor;
};

string Animal::getNasc(){
    return this->nascimento;
};

float Animal::getPreco(){
    return this->preco;
};
