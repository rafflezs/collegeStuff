#ifndef _PESSOA_H
#define _PESSOA_H

#include "abPessoa.h"
#include "Endereco.h"
#include "Pedido.h"

class Pessoa  : public abPessoa{
	private:
		std::string nome;//
		Endereco* endereco;
		int cpf;//
		int rg;//

	public:

		Pedido* comprar();

		double atualizarDivida(int val1);
		
		int getCpf();
		void setCpf(const int & input);

		int getRg();
		void setRg(const int& input);

		std::string getNome();
		void setNome(const std::string &);
};

#endif // !_PESSOA_H
