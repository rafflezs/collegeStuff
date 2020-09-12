#ifndef _PESSOA_H
#define _PESSOA_H

#include "Endereco.h"

class Pessoa {
	protected:
		std::string nome;
		double atualizarDivida(int, int);

	private:
		Endereco* endereco;
		int cpf;
		int atualizarDivida(int);

	public:
		Pessoa();
		int getCpf();
		void setCpf(const int & input);

		int rg;
		int getRg();
		void setRg(const int& input);

		std::string getNome();
		void setNome(const std::string &);

		void atualizarDivida();
};

#endif // !_PESSOA_H
