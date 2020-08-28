#ifndef _EMPRESARIO_H
#define _EMPRESARIO_H

#include "pessoa.h"

class Empresario : public Pessoa{
	private:
		float investimentoInicial;
	public:
		Empresario(const Endereco &);

		float getInvestimento();
		void setInvestimento(const float&);
};

#endif // !_EMPRESARIO_H
