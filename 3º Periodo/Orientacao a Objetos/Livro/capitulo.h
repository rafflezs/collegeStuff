#ifndef _CAPITULO_H
#define _CAPITULO_H

#include <iostream>
#include <string>

using namespace std;

class Capitulo{
    private:
        int codigo;
        string titulo;
        int ano;
    public:

        int getAno();
        void setAno(const int & temp);

        string getTitulo();
        void setTitulo(const string & temp);

        int getCodigo();
        void setCodigo(const int & temp);

        void print();
    };

#endif // !_CAPITULO_H