#ifndef _LANCHA_H
#define _LANCHA_H

#include "veiculo.h"

class Lancha : public Veiculo {

    private:
        int numMotores;

    public:
        void setNumMotores(const int & input);

        int getNumMotores();

};

#endif