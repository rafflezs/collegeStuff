#ifndef _TELEFONE_H
#define _TELEFONE_H

#include <string>

using namespace std;

class Telefone{
	private:
		int ddd;
		string numero;
	public:
		int getDDD();
		void setDDD(const int & temp);

		string getNumero();
		void setNumero(const string & temp);
};

#endif