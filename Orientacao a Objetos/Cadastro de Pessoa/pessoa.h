#ifndef _PESSOA_H
#define _PESSOA_H

#include "endereco.h"
#include <string>
#include <iostream>

using namespace std;

class Pessoa{
    private:
        Endereco* endereco;

        string nome;
        string telefone;
        string cpf;
    public:

        string getNome();
        void setNome(const string &);

        string getTelefone();
        void setTelefone(const string &);

        string getCpf();
        void setCpf(const string &);

        Endereco* getEndereco();
        void setEndereco(Endereco*);

        Pessoa(Endereco* endereco);
        Pessoa(Endereco* endereco, string nome);

        ~Pessoa();

        void print();
};

#endif // !_PESSOA_H