#include "Pessoa.h"

int Pessoa::getCpf() {
	return this->cpf;
};

void Pessoa::setCpf(const int& input) {
	this->cpf = input;
};

double Pessoa::atualizarDivida(int val1){

};

std::string Pessoa::getNome() {
	return this->nome;
};

void Pessoa::setNome(const std::string& input) {
	this->nome = input;
};

int Pessoa::getRg(){
	return this->rg;
};

void Pessoa::setRg(const int & input){
	this->rg = input;
};

Pedido* Pessoa::comprar(){
	Pedido* temp = new Pedido();
	std::string inp;
	temp->setData(inp);
	temp->setNum(stoi(inp));
	//temp->criaPedido();
}