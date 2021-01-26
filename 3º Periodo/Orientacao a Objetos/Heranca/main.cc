#include "Filho.h"
#include <iostream>

int main(){

    Filho* filho = new Filho("Paulo");

    std::cout << filho->getNome() << " ";
    std::cout << filho->getSobrenome() << std::endl;

    
}