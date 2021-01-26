#ifndef _CURSO_H
#define _CURSO_H

#include <string.h>
#include <iostream>

using namespace std;

class Curso{

	private:
		string nome;
		string contProg;
		float valor;
		int cargaHoraria;
	public:
		string getNome();
		void setNome(const string & temp);

		string getContProg();
		void setContProg(const string & temp);

		float getValor();
		void setValor(const float & temp);

		int getCargaHoraria();
		void setCargaHoraria(const int & temp);
};

#endif