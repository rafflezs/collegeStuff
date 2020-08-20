#include "capitulo.h"

int Capitulo::getAno(){
    return this->ano;
}

void Capitulo::setAno(const int & temp){
    this->ano = temp;
}

string Capitulo::getTitulo(){
    return this->titulo;
}

void Capitulo::setTitulo(const string & temp){
    this->titulo = temp;
}

int Capitulo::getCodigo(){
    return this->codigo;
}

void Capitulo::setCodigo(const int & temp){
    this->codigo = temp;
}

void Capitulo::print(){
    cout << "Titulo: " << getTitulo() << endl << "Codigo: " << getCodigo() << endl << "Ano: " << getAno() << endl;
}