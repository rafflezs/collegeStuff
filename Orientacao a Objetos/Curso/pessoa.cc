#include "pessoa.h"

string Pessoa::getNome(){
	return this->nome;
}

void Pessoa::setNome(const string & temp){
	this->nome = temp;
}

string Pessoa::getRg(){
	return this->rg;
}

void Pessoa::setRg(const string & temp){
	this->rg = temp;
}

string Pessoa::getCpf(){
	return this->cpf;
}

void Pessoa::setCpf(const string & temp){
	this->cpf = temp;
}

string Pessoa::getDataNasc(){
	return this->dataNasc;
}

void Pessoa::setDataNasc(const string & temp){
	this->dataNasc = temp;
}

vector <Telefone*> Pessoa::getTelefone(){
	return this->telefones;
}

void Pessoa::setTelefone(Telefone* telefone){
	this->telefones.push_back(telefone);
}

Pessoa::Pessoa(Endereco* endereco){
	this->endereco = endereco;
}