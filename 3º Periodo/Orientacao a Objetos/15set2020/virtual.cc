#include <iostream>

class Base{
   public:
      void fooVirtual(){ std::cout << "Esse não é um método virtual";};
      virtual void fooVirtualPuro() = 0; //Essa função não tem definição lógica
                                 //portanto deve ser reimplementada na deriv
};

class Derivada : public Base{
   public:
      void fooVirtualPuro(){ std::cout << "Essa função é um método vitual puro" << std::endl; };
};

int main(){
    Derivada a;
    a.fooVirtualPuro();
}
