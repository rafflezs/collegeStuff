#ifndef _LOGICA_H
#define _lOGICA_H

#include "../Classes/laser.h"
#include "../Classes/matricial.h"

#include <vector>
#include <typeinfo>

class Logica {

private:
	std::vector <Matricial*> listaMat;
	std::vector <Laser*> listaLaser;
public:
	void iniciar();
	int menu();

	void* cria();
	void adciona(void*);

	void exibeTodos();
    void* exibeUnico(void*);


};

#endif // !_LOGICA_H
