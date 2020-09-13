#include "Pedido.h"

int Pedido::getNum(){
    return this->num;
};

void Pedido::setNum(const int &input){
    this->num = input;
};

std::string Pedido::getData(){
    return this->data;
};

void Pedido::setData(const std::string &input){
    this->data = input;
};

int Pedido::getQtd(){
    return this-> qtdItens;
};

void Pedido::setQtd(const int &input){
    this->qtdItens = input;
};

void Pedido::criaPedido(Produto* prod){
    this->lista.push_back(prod);
}