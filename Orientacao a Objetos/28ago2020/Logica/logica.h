#ifndef _LOGICA_H
#define _LOGICA_H
#include <iostream>
#include <cstdlib>

#include "../Classes/funcionario.h"
#include "../Classes/empresario.h"

using namespace std; 

class Logica {
	private:
		vector <Funcionario*> funcLista;
		vector <Empresario*> empreLista;
	public:
		int menu();
        void iniciar();

        void add(Funcionario*);
        void add(Empresario*);
        void* cria();

        Endereco* criaEndereco();
        vector <Email*> criaEmails();
        Telefone* criaTelefone();

};

#endif // !_LOGICA_H


