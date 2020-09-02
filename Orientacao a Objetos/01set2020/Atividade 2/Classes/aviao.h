#ifndef _AVIAO_H
#define _AVIAO_H

#include "veiculo.h"

class Aviao : public Veiculo {

    private:
        int numTurbinas;
        string prefixo;

    public:
        void setNumTurbinas(const int & input);
        void setPrefixo(const string & input);

        int getNumTurbinas();
        string getPrefixo();

};

#endif