#ifndef _CACHORRO_H
#define _CACHORRO_H

#include "animal.h"

class Cachorro : public Animal{

    private:
        float intensidadeLatido;
        float distanciaFaro;
    public:
        void setFaro(const float & input);
        void setLatido(const float & input);

        float getFaro();
        float getLatido();

};

#endif