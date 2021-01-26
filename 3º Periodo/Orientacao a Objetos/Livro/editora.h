#ifndef _EDITORA_H
#define _EDITORA_H

#include <string>

#include "endereco.h"

using namespace std;

class Editora{
    private:
        string nome;
    public:
        Editora(Endereco* endereco);
        string getNome();
        void setNome(const string & temp);
        
    };

#endif // !_EDITORA_H