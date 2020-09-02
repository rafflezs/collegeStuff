#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Animal{

    private:
        string raca;
        string cor;
        double preco;
        string nascimento;

    public:
        void setRaca(const string & input);
        void setCor(const string & input);
        void setNasc(const string & input);
        void setPreco(const float & input);

        string getRaca();
        string getCor();
        string getNasc();
        float getPreco();
};

#endif