#include "Produto.h"

int Produto::getBarCode(){
    return this->barCode;
};

void Produto::setBarCode(const int &input){
    this->barCode = input;
};

std::string Produto::getDesc(){
return this->desc;
};

void Produto::setDesc(const std::string &input){
    this->desc = input;
};

float Produto::getPreco(){
return this->preco;
};

void Produto::setPreco(const float &input){
    this->preco = input;
};
