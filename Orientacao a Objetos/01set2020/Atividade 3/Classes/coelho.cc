#include "coelho.h"

void Coelho::setCenouras(const int & input){
    this->cenourasPorDia = input;
};

void Coelho::setPeloLongo(const bool & input){
    this->peloLongo = input;
};

int Coelho::getCenouras(){
    return this->cenourasPorDia;
};

bool Coelho::hasPeloLongo(){
    return this->peloLongo;
};
