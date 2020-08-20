#ifndef _PESSOA_H
#define _PESSOA_H

#include "telefone.h"
#include "endereco.h"

#include <string>
#include <vector>

using namespace std;

class Pessoa{
	private:
		Endereco* endereco;
		string nome;
		string rg;
		string cpf;
		string dataNasc;
		vector <Telefone*> telefones;
				
	public:

		string getNome();
		void setNome(const string & temp);

		string getRg();
		void setRg(const string & temp);

		string getCpf();
		void setCpf(const string & temp);

		string getDataNasc();
		void setDataNasc(const string & temp);

		vector <Telefone*> getTelefone();
		void setTelefone(Telefone* telefone);

		Pessoa(Endereco* endereco);
};

#endif

