#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,j;
    char nome[50];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);

    printf("\nDigite a quantidade de valores desejados: ");
    scanf("%d", &j);

    FILE *file = fopen(nome, "w+");



    for(i = 1; i <= j; i++){

        int valor = random() % 1000 + 1;
        int valor2 = random() % 100;
        int qtd = random() % 100 + 1;

        fprintf(file, "%d;",i);
        fprintf(file, "Produto%d;",i);
        fprintf(file, "%d;",qtd);
        fprintf(file, "%d.%d",valor, valor2);

            if (i != j){
                fprintf(file,"\n");
            }
    }

    return 0;

}