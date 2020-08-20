#ifndef _LOGICA_H
#define _LOGICA_H

#include <iostream>
#include <vector>
#include <string>

#include "aluno.h"
#include "professor.h"

class Logica{
    private:
        vector <Professor*> professores;
        vector <Aluno*> alunos;
        int menu();
    public:
        void start();

        Endereco* criaEnd();
        Disciplina* criaDisc();
        Aluno* criaAluno(string temp);
        Professor* criaProf(string temp);

        Aluno* buscaAluno(string temp);
        Professor* buscaProf(string temp);
        void altera(Aluno* al);
        void altera(Professor* prof);
        void deleta(Aluno* al);
        void deleta(Professor* prof);
        void printa(int a = 0);
        void printa(int b = 1);


};

#endif // !_LOGICA_H