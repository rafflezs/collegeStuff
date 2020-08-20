#include "professor.h"

string Professor::getTitulacao(){
    return this->titulacao;
}

void Professor::setTitulacao(const string &titualacao){
    this->titulacao = titualacao;
}

float Professor::getSalario(){
    return this->salario;
}

void Professor::setSalario(const float &salario){
    calcSalario(salario);
}

Professor::Professor(Endereco* endereco) : Pessoa(endereco){

}

Professor::Professor(Endereco* endereco, string nome) : Pessoa(endereco, nome){

}

float Professor::calcSalario(float salario){
    this->salario = salario - (salario * 0.3);
}

void Professor::print(){
    Pessoa::print();

    cout << "Titulacao: " << titulacao << endl << "Salario: " << salario << endl;
}