#include "endereco.h"

string Endereco::getRua(){
    return this->rua;
}

void Endereco::setRua(const string & rua){
    this->rua = rua;
}

string Endereco::getCep(){
    return this->cep;
}

void Endereco::setCep(const string & cep){
    this->cep = cep;
}

string Endereco::getBairro(){
    return this->bairro;
}

void Endereco::setBairro(const string & bairro){
    this->bairro = bairro;
}

string Endereco::getCidade(){
    return this->cidade;
}

void Endereco::setCidade(const string & cidade){
    this->cidade = cidade;
}

int Endereco::getNumero(){
    return this->numero;
}

void Endereco::setNumero(const int & numero){
    this->numero = numero;
}