#include "pessoa.h"

string Pessoa::getNome(){
    return this->nome;
}

void Pessoa::setNome(const string &nome){
    this->nome = nome;
}

string Pessoa::getTelefone(){
    return this->telefone;
}

void Pessoa::setTelefone(const string &telefone){
    this->telefone = telefone;
}

string Pessoa::getCpf(){
    return this->cpf;
}

void Pessoa::setCpf(const string &cpf){
    this->cpf = cpf;
}

Pessoa::Pessoa(Endereco* endereco){
    this->endereco = endereco;
}

Pessoa::Pessoa(Endereco* endereco, string nome){
    this->endereco = endereco;
    this->nome = nome;
}

void Pessoa::print(){
    cout << "Nome: " << nome << endl << "CPF: " << cpf << endl << "Telefone: " << telefone << endl;
    cout << "Rua: " << endereco->getRua() << endl << "Bairro: " << endereco->getBairro() << endl;
}

Endereco* Pessoa::getEndereco(){
    return endereco;
}

void Pessoa::setEndereco(Endereco* endereco){
    this->endereco = endereco;
}
