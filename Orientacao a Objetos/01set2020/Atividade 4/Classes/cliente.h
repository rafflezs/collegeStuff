#ifndef _CLIENTE_H
#define _CLIENTE_H

#include "pessoa.h"

class Cliente : public Pessoa{
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