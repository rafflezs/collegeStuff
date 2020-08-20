#include "aluno.h"

Curso* Aluno::getCurso(){
	return this->curso;
}

void Aluno::setCurso(Curso* temp){
	this->curso = temp;
}

string Aluno::getMatricula(){
	return this->matricula;
}

void Aluno::setMatricula(const string & temp){
	this->matricula = temp;
}

Aluno::Aluno(Endereco* end) : Pessoa(end){

}
