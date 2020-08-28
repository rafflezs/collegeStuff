#ifndef _LOGICA_H
#define _LOGICA_H
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "../Classes/funcionario.h"
#include "../Classes/empresario.h"

class Logica {
	private:
		vector <Funcionario*> funcLista;
		vector <Empresario*> empreLista;
	public:
		int menu();
		void iniciar();

		Funcionario* criarFunc();
		Empresario* criarEmpre();
		
		string pesquisar();

		Funcionario* searchFunc();
		Empresario* searchEmpre();

		void alterar_pessoa(Funcionario* func);
		void alterar_pessoa(Empresario* emp);
		
		bool remover_posicao_vector();

		void add(Funcionario* func);
		void add(Empresario* empre);

		void print();
		void printAll();


};

#endif // !_LOGICA_H


