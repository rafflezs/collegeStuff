#include "pessoa.h"

void Pessoa::setNome(const string &input){
    this->nome = input;
};

void Pessoa::setNumContribuinte(const string &input){
    this->numContribuinte = input;
};

void Pessoa::setIdade(const int &input){
    this->idade = input;
};

string Pessoa::getNome(){
    return this->nome;
};

string Pessoa::getNumContribuinte(){
    return this->numContribuinte;
};

int Pessoa::getIdade(){
    return this->idade;
};
