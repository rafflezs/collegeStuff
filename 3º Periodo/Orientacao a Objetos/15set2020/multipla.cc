#include <iostream>
#include <string>

class VeiculoTerrestre{
   public:
      int numPortas;
      int numRodas;
      int velTerra;
};

class VeiculoAquatico{
   public:
      bool afunda;
      bool motorAvapor;
      int velAgua; 
};

class veiculoAnfibio : public VeiculoTerrestre, public VeiculoAquatico{
   public:
      std::string combuistivel;
      void transformar();
};

int main(){

   VeiculoTerrestre carro;
   VeiculoAquatico barco;
   veiculoAnfibio Schwimmwagen;

    barco.afunda = true;
    carro.numPortas = 4;
    Schwimmwagen.afunda = barco.afunda;
    Schwimmwagen.numPortas = carro.numPortas;

}
