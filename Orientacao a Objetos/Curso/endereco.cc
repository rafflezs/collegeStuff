#include "endereco.h"

string Endereco::getRua(){
	return this->rua;
}

void Endereco::setRua(const string & temp){
	this->rua = temp;
}

string Endereco::getCep(){
	return this->cep;
}

void Endereco::setCep(const string & temp){
	this->cep = temp;
}

string Endereco::getLogradouro(){
	return this->logradouro;
}

void Endereco::setLogradouro(const string & temp){
	this->logradouro = temp;
}

string Endereco::getBairro(){
	return this->bairro;
}

void Endereco::setBairro(const string & temp){
	this->bairro = temp;
}

string Endereco::getCidade(){
	return this->cidade;
}

void Endereco::setCidade(const string & temp){
	this->cidade = temp;
}

