#include "Endereco.h"

std::string Endereco::getCep() {
	return this->cep;
};

void Endereco::setCep(const std::string& input) {
	this->cep = input;
};

std::string Endereco::getBairro() {
	return this->bairro;
};

void Endereco::setBairro(const std::string& input) {
	this->bairro = input;
};

int Endereco::getNum() {
	return this->numero;
};

void Endereco::setNum(const int& input) {
	this->numero = input;
};

std::string Endereco::getRua() {
	return this->rua;
};

void Endereco::setRua(const std::string& input) {
	this->rua = input;
};

std::string Endereco::getComp() {
	return this->complemento;
};

void Endereco::setComp(const std::string& input) {
	this->complemento = input;
};

void Endereco::atualizar() {

	std::string input;

	setCep(input);
	setBairro(input);
	setRua(input);
	setNum(stoi(input));
	setComp(input);

};