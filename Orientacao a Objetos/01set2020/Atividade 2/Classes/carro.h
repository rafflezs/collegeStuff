#ifndef _CARRO_H
#define _CARRO_H

#include "veiculo.h"

class Carro : public Veiculo {

    private:
        int numPortas;
        string placa;

    public:
        void setNumPortas(const int &);
        void setPlaca(const string &);

        int getNumPortas();
        string getPlaca();

};

#endif