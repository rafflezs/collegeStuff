#include "disciplina.h"

string Disciplina::getNome(){
    return this->nome;
}

void Disciplina::setNome(const string & nome){
    this->nome = nome;
}

float Disciplina::getNota(){
    return this->nota;
}

void Disciplina::setNota(const float & nota){
    this->nota = nota;
}

int Disciplina::getCargaHoraria(){
    return this->cargaHoraria;
}

void Disciplina::setCargaHoraria(const int & cargaHoraria){
    this->cargaHoraria = cargaHoraria;
}

void Disciplina::print(){
    cout << "Disciplina: " << nome << endl << "Nota: " << nota << endl << "Carga Horaria: " << cargaHoraria << endl;
}