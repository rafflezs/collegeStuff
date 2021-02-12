#include <stdio.h>
#include <stdlib.h>

//Converter o código para ler a string do arquivo

void frequencia(char input[], int vet_ocur[]);

int main(){

    char input[] = {"Teste de mesa"};
    int vet_ocur[256];

    frequencia(input, vet_ocur);

}

void frequencia(char input[], int vet_ocur[]){

    for(int i = 0; input[i] < 256; i++){
        vet_ocur[i] = 0;
    }

    for(int i = 0; input[i] != '\0'; i++){
        vet_ocur[input[i]]++;
    }

    for(int i = 0; input[i] < 256; i++){
        printf("%i : %c == %i", i, i, vet_ocur[i]);
    }

}