#ifndef _LOGICA_H
#define _LOGICA_H

#include "../Classes/gato.h"
#include "../Classes/cachorro.h"
#include "../Classes/coelho.h"

#include <iostream>

#include <vector>
#include <typeinfo>

class Logica {

private:
	vector <Coelho*> listaCoelho;
	vector <Cachorro*> listaCachorro;
    vector <Gato*> listaGato;
public:
	void iniciar();
	int menu();

	void* cria();
	void adciona(void*);

	void exibeTodos();
    void* exibeUnico(void*);

};

#endif // !_LOGICA_H
