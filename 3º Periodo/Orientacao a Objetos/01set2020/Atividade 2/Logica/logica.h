#ifndef _LOGICA_H
#define _LOGICA_H

#include "../Classes/lancha.h"
#include "../Classes/aviao.h"
#include "../Classes/carro.h"

#include <iostream>

#include <vector>
#include <typeinfo>

class Logica {

private:
	vector <Carro*> listaCarro;
	vector <Aviao*> listaAviao;
    vector <Lancha*> listaLancha;
public:
	void iniciar();
	int menu();

	void* cria();
	void adciona(void*);

	void exibeTodos();
    void* exibeUnico(void*);

};

#endif // !_LOGICA_H
