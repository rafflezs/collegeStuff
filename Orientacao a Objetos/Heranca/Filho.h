#ifndef _FILHO_H
#define _FILHO_H

#include "Pai.h"

class Filho : private Pai{
    private:
        std::string nome;
        std::string sobrenome;
    public:
        Filho(const std::string & input);
        void setNome(const std::string & input);
        std::string getNome();

        void setSobrenome(/* const std::string & input */);
        std::string getSobrenome();
};

#endif