#ifndef _PESSOA_H
#define _PESSOA_H

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Pessoa{

    private:
        string nome;
        string numContribuinte;
        int idade;
    public:
        void setNome(const string &);
        void setNumContribuinte(const string &);
        void setIdade(const int &);

        string getNome();
        string getNumContribuinte();
        int getIdade();

};

#endif