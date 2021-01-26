#ifndef _PROFESSOR_H
#define _PROFESSOR_H

#include "pessoa.h"

class Professor : public Pessoa{
    private:
        string titulacao;
        float salario;
    public:
        string getTitulacao();
        void setTitulacao(const string &titualacao);

        float getSalario();
        void setSalario(const float &salario);

        float calcSalario(float salario);
        void print();

        Professor(Endereco* endereco);
        Professor(Endereco* endereco, string nome);
        ~Professor();
};

#endif // !_PROFESSOR_H