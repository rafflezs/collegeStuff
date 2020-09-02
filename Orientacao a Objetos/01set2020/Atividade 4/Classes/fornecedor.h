#ifndef _FORNECEDOR_H
#define _FORNECEDOR_H

#include "pessoa.h"

class Fornecedor : public Pessoa{
    private:
        float plafond;
        float valorDivida;
    public:
        void setPlafond(const float & input);
        void setValorDivida(const float & input);

        float getPlafond();
        float getValorDivida();

        float obterSaldo();
};

#endif