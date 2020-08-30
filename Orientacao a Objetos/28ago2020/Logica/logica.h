#ifndef _LOGICA_H
#define _LOGICA_H
#include <iostream>
#include <cstdlib>
#include <typeinfo>

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

        void add(void* obj);
        void* cria();

        string consultar();
        void* pesquisar(const string & RG);

        void exibeUnico(void* obj);

        void exibeTodos(); 

        void altera(void* obj);

        bool removeElemento(const string & RG);

        Endereco* criaEndereco();
        vector <Email*> criaEmails();
        Telefone* criaTelefone();

};

#endif // !_LOGICA_H


