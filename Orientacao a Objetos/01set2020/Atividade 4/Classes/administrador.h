#ifndef _ADMINISTRADOR_H
#define _ADMINISTRADOR_H

#include "empregado.h"

class Administrador : public Empregado{
    private:
        float ajudaCusto;
    public:
        void setAjudaCusto(const float & input);
        
        float getAjudaCusto();

        float calcularSalario();

};

#endif