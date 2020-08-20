#include "autor.h"

string Autor::getFormacao(){
    return this->formacao;
}

void Autor::setFormacao(const string & temp){
    this->formacao = temp;
}

Autor::Autor(Endereco* endereco, string nome) : Pessoa(endereco, nome){
    
}