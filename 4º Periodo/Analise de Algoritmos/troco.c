#include <stdio.h>

int main(){
    int moedas[5] = {1,5,10,25,50};
    int valor = 74;
    int index = 5;
    while (valor != 0 )
    {
        if(valor - moedas[index] >= 0){
            printf("Valor: %i | Moeda de Troco: %i\n", valor, moedas[index]);
            valor = valor - moedas[index];
        }else{
            index--;
        }
    }
    printf("%i\n", valor);
}