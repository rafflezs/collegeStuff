#ifndef _MATRICIAL_H
#define _MATRICIAL_H

#include "impressora.h"

class Matricial : public Impressora {

	private:
		int numAgulhas;
		bool imprimeVias;

	public:
		void setNumAgulhas(const int&);
		int getNumAgulhas();

		void setImprimeVias(const bool&);
		bool doesImprimeVias();
};

#endif