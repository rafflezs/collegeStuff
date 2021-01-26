#include "veiculo.h"

void Veiculo::setModelo(const string &input){
    this->modelo = input;
};

void Veiculo::setNumLugares(const int &input){
    this->numLugares = input;
};

void Veiculo::setComprimento(const int &input){
    this->comprimento = input;
};

void Veiculo::setAno(const int &input){
    this->ano = input;
};

void Veiculo::setCor(const string &input){
    this->cor = input;
};

string Veiculo::getModelo(){
    return this->modelo;
};

int Veiculo::getNumLugares(){
    return this->numLugares;
};

int Veiculo::getComprimento(){
    return this->comprimento;
};

int Veiculo::getAno(){
    return this->ano;
};

string Veiculo::getCor(){
    return this->cor;
};