#ifndef _DISCIPLINA_H
#define _DISCIPLINA_H

#include <string>
#include <iostream>

using namespace std;

class Disciplina{
    private:
        string nome;
        float nota;
        int cargaHoraria;

    public:
        string getNome();
        void setNome(const string & nome);

        float getNota();
        void setNota(const float & nota);

        int getCargaHoraria();
        void setCargaHoraria(const int & cargaHoraria);

        void print();
    };

#endif // !_DISCIPLINA_H