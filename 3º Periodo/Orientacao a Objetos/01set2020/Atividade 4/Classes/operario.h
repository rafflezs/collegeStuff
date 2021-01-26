#ifndef _OPERARIO_H
#define _OPERARIO_H

#include "empregado.h"

class Operario : public Empregado{
    private:
        float valorProducao;
        float comissao;
    public:
        void setValorProducao(const float & input);
        void setComissao(const float & input);
        
        float getValorProducao();
        float getComissao();

        float calcularSalario();

};

#endif