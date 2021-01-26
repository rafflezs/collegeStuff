#ifndef _ALUNO_H
#define _ALUNO_H

#include "pessoa.h"
#include "curso.h"

#include <string>

using namespace std;

class Aluno : public Pessoa{
	private:
		Curso* curso;
		string matricula;
	public:
		Curso* getCurso();
		void setCurso(Curso* temp);

		string getMatricula();
		void setMatricula(const string & temp);
		Aluno(Endereco* end);
};

#endif