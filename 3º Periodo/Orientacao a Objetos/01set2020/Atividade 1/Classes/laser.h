#ifndef _LASER_H
#define _LASER_H

#include "impressora.h"

class Laser : public Impressora {

    private:
    	float capacidadeToner;
    	bool frenteVerso;
    
    public:
    	void setCapacidadeToner(const float&);
    	int getCapacidadeToner();
    
    	void setFrenteVerso(const bool&);
    	bool isFrenteVerso();
};

#endif