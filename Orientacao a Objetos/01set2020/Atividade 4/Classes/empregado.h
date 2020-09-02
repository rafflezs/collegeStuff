#ifndef _EMPREGADO_H
#define _EMPREGADO_H

#include "pessoa.h"

class Empregado : public Pessoa{
    private:
        string numeroSecao;
        float salarioBase;
        float irs;
    public:
        void setSalarioBase(const float & input);
        void setIrs(const float & input);
        void setNumeroSecao(const string & input);

        float getSalarioBase();
        float getIrs();
        string getNumeroSecao();

        float calcularSalario();
};

#endif