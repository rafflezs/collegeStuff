#ifndef _COELHO_H
#define _COELHO_H

#include "animal.h"

class Coelho : public Animal{

    private:
        int cenourasPorDia;
        bool peloLongo;
    public:
        void setCenouras(const int & input);
        void setPeloLongo(const bool & input);

        int getCenouras();
        bool hasPeloLongo();

};

#endif