#include <iostream>
#include <string>

class Funcionario{
    public:
       ~Funcionario();
       virtual void trabalhar() = 0;
       float salario;
};

class Administrador : public Funcionario{
    public:
        void trabalhar(){ std::cout << "Eu sonego imposto e recebo R$" << salario << " por isso" << std::endl; };
};

int main(){

    Funcionario* a = new Administrador();
    a->salario = 1200;
    a->trabalhar();

}
