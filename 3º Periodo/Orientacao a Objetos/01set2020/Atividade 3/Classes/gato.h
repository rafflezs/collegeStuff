#ifndef _GATO_H
#define _GATO_H

#include "animal.h"

class Gato : public Animal{

    private:
        float alturaPulo;
        bool peloLongo;
    public:
        void setAlturaPulo(const float & input);
        void setPeloLongo(const bool & input);

        int getAlturaPulo();
        bool hasPeloLongo();
};

#endif