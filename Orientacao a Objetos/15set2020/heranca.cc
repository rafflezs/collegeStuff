#include <iostream>
#include <string>

class Pessoa{
   public:
      void viver(){
         std::cout << "Eu acordo às 7h" << std::endl;
      };
};

class Estudante : public Pessoa{
   public:
      void viver(){
         Pessoa::viver();
         std::cout << "Eu procrastino até as 22h e durmo" << std::endl;
      };
};

int main(){
   Estudante a;
   a.viver(); //output : Eu acordo às 7h
              //         Eu procrastino até as 22h e durmo
}