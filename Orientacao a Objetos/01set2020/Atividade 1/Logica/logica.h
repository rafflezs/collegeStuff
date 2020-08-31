#ifndef _LOGICA_H
#define _lOGICA_H

#include "../Classes/laser.h"
#include "../Classes/matricial.h"

#include <vector>

class Logica {

private:
	std::vector <Matricial*> listaMat;
	std::vector <Laser*> listaLaser;
public:
	void iniciar();
	int menu();

	void* cria();
	void adciona(void*);

	void exibe();
};

#endif // !_LOGICA_H
