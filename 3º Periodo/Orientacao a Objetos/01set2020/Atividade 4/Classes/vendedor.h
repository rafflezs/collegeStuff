#ifndef _VENDEDOR_H
#define _VENDEDOR_H

#include "empregado.h"

class Vendedor : public Empregado{
    private:
        float valorVendas;
        float comissao;
    public:
        void setValorVendas(const float & input);
        void setComissao(const float & input);
        
        float getValorVendas();
        float getComissao();

        float calcularSalario();

};

#endif
