#include "aluno.h"

Aluno::Aluno(Endereco* endereco, const vector <Disciplina*> disc):Pessoa(endereco){
    this->disc = disc;
}

Aluno::Aluno(Endereco* endereco, const vector <Disciplina*> disc, string nome):Pessoa(endereco, nome){
    this->disc = disc;
}

void Aluno::add(Disciplina* disciplina){
    disc.push_back(disciplina);
}

void Aluno::print(){
    Pessoa::print();

    cout << "Matricula: " << matricula << endl;
    for(auto it = disc.begin(); it != disc.end(); it++)
        (*it)->print();
}