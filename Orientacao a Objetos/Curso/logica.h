#ifndef _LOGICA_H
#define _LOGICA_H

#include "aluno.h"

class Logica{
    private:
        vector<Aluno*> alunos;
        int menu();
    public:
        Aluno* criaAluno();
        void start();
        Aluno* buscaAluno(string mat);
        void alteraAluno(Aluno* aluno);
        void exlcuiAluno(Aluno* aluno);
    };

#endif // !_LOGICA_H