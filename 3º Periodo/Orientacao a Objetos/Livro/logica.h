#ifndef _LOGICA_H
#define _LOGICA_H

#include <iostream>

#include "livro.h"
#include "pessoa.h"

using namespace std;


class Logica{
    private:
        vector <Livro*> livros;
        vector <Autor*> autores;
        int menu();
    public:
        void start();
        Autor* criaAutor(string temp);
        Livro* criaLiv(Autor* aut);
        vector<Capitulo*> criaCap();
    };

#endif // !_LOGICA_H