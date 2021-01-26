#ifndef _PAI_H
#define _PAI_H

#include <string>

class Pai{
    private:
        std::string nome;
        std::string sobrenome;
    public:
        Pai();

        void setNome(const std::string & input);
        std::string getNome();

        void setSobrenome(const std::string & input);
        std::string getSobrenome();
};

#endif