#include "Pessoa.h"

Pessoa::Pessoa() {
	Endereco* temp = new Endereco();
	temp->atualizar();
	this->endereco = temp;
};

int Pessoa::getCpf() {
	return this->cpf;
};

void Pessoa::setCpf(const int& input) {
	this->cpf = input;
};

void Pessoa::atualizarDivida() {

};

int Pessoa::atualizarDivida(int val1) {

};

double Pessoa::atualizarDivida(int val1, int val2) {

};

std::string getNome() {

};

void setNome(const std::string&) {

};