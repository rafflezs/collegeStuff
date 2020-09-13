#ifndef _ENDERECO_H
#define _ENDERECO_H

#include <string>

class Endereco {
	private:
		std::string cep;
		std::string bairro;
		std::string rua;
		int numero;
		std::string complemento;
	public:
		std::string getCep();
		void setCep(const std::string & input);

		std::string getBairro();
		void setBairro(const std::string& input);

		int getNum();
		void setNum(const int& input);

		std::string getRua();
		void setRua(const std::string& input);

		std::string getComp();
		void setComp(const std::string& input);

		void atualizar();
};

#endif