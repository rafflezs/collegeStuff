#include "aviao.h"

void Aviao::setNumTurbinas(const int & input){
    this->numTurbinas = input;
};

void Aviao::setPrefixo(const string & input){
    this->prefixo = input;
};

int Aviao::getNumTurbinas(){
    return this->numTurbinas;
};

string Aviao::getPrefixo(){
    return this->prefixo;
};
