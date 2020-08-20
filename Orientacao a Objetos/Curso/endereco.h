#ifndef _ENDERECO_H
#define _ENDERECO_H

#include <string>

using namespace std;

class Endereco{
	private:
		string rua;
		string logradouro;
		string cep;
		string bairro;
		string cidade;
	public:
		string getRua();
		void setRua(const string & temp);

		string getCep();
		void setCep(const string & temp);

		string getLogradouro();
		void setLogradouro(const string & temp);

		string getBairro();
		void setBairro(const string & temp);

		string getCidade();
		void setCidade(const string & temp);
};

#endif