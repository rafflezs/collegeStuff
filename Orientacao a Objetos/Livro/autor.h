#ifndef _AUTOR_H
#define _AUTOR_H

#include "pessoa.h"

class Autor : public Pessoa{
    private:
        string formacao;
    public:

        string getFormacao();
        void setFormacao(const string & temp);

        Autor(Endereco* endereco, string nome);
};

#endif // !AUTOR_H