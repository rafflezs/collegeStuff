#ifndef _LOGICA_H
#define _LOGICA_H

#include "../Classes/administrador.h"
#include "../Classes/operario.h"
#include "../Classes/vendedor.h"
#include "../Classes/fornecedor.h"
#include "../Classes/cliente.h"

class Logica{

    private:

        vector <Pessoa*> pessoaLista;

        vector <Empregado*> empreLista;

        vector <Administrador*> admLista;
        vector <Operario*> opLista;
        vector <Vendedor*> vendLista;

        vector <Fornecedor*> forLista;
        vector <Cliente*> clienteLista;
    public:
		int menu();
        void iniciar();

        void add(void* obj);
        void* cria();

        void* consultar();

        void exibeUnico(void* obj);

        void exibeTodos(); 

        void altera(void* obj);

        bool removeElemento();

};

#endif