#ifndef _LIVRO_H
#define _LIVRO_H

#include "capitulo.h"
#include "autor.h"
#include "editora.h"

#include <vector>

class Livro{
    private:
        vector<Capitulo*> capitulos;
    public:
        Livro(vector<Capitulo*> capitulos, Editora* editora,Autor* autor);
};

#endif // !_LIVRO_H