#ifndef _ALUNO_H
#define _ALUNO_H

#include "pessoa.h"
#include "disciplina.h"

#include <vector>

class Aluno : public Pessoa{
    private:
        string matricula;
        vector <Disciplina*> disc;
    public:
        Aluno(Endereco* endereco, vector <Disciplina*> disc);
        Aluno(Endereco* endereco, vector <Disciplina*> disc, string nome);

        void add(Disciplina* disciplina);
        void print();


};

#endif // !_ALUNO_H