#include <iostream>

class SerVivo{
   public:
      ~SerVivo();
      virtual void viver() = 0;
};

class Estudante{
   public:
      ~Estudante();
      virtual void estudar() = 0;      
};

class Crianca : public SerVivo, public Estudante {
   public:
      void viver() { std::cout << "Eu vivo pra comer reboco e brincar com  besouros" << std::endl; };
      void estudar() { std::cout << "Eu vou pra escola para comer massinha e cola" << std::endl; };      
};

class Adulto : public SerVivo, public Estudante {
   public:
      void viver() { std::cout << "Eu vivo ansioso e com medo de não conseguir pagar minhas contas" << std::endl; };
      void estudar() { std::cout << "Eu pago um absurdo para fazer faculdade e reprovo mesmo assim" << std::endl; };      
};

int main(){

   Crianca *a = new Crianca();
   Adulto *b = new Adulto();

   a->viver();
   a->estudar();

   b->viver();
   b->estudar();

}
