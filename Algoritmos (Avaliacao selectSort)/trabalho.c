#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int ArraySize(char nome[50]);
void ArrayGet(int *cod, float *tot, char nome[50]);
void Sort(int *cod, float *tot, int t);
int ArraySave(int *cod, float *tot, char arqsave[50]);
 
int main(){

    char nome[50], arqsave[50];

    printf("\033[01;30mDigite o nome do arquivo de origem: ");
    scanf("%s", nome);
    printf("\n\033[01;30mDigite o nome do arquivo final: ");
    scanf("%s", arqsave);
    int t = ArraySize(nome);
    
    int cod[t];
    float tot[t];

    ArrayGet(cod, tot, nome);
    Sort(cod, tot,  t);
    ArraySave(cod, tot, arqsave);
 
    printf("\n\n\033[22;35m-----------------Agradecimentos do grupo ao Emanuel pela ajuda na correção do código! <3-----------------------\n\n");

    return 0;    
}
 
int ArraySize(char nome[50]){
    int tamanho = 0;
    char c[100];
    FILE *file = fopen(nome,"r+");
 
    if (file == NULL){
        printf("\033[22;31mErro ao abrir o arquivo.\n");
        return -1;
    }
    
    while (fscanf(file, "\n%[^\n]", c) != EOF){
        tamanho++;
    }
 
    fclose(file);
    
    return tamanho;
}
 
void ArrayGet(int *cod, float *tot, char nome[50]){
    
    int t = ArraySize(nome);

    int i = 0;

    char produto[100];
    int qtd[t];
    float valor[t];
    FILE *file = fopen(nome, "r+");
 
    printf("\033[22;34mLendo arquivo e extraindo informações!\n");

    while(fscanf(file,"\n%d",&cod[i])  != EOF){
        fscanf(file,";%[^;]", produto);
        fscanf(file,";%d", &qtd[i]);
        fscanf(file,";%f", &valor[i]);
        tot[i] = valor[i] * qtd[i]; 
        i++;
    }
    fclose(file);
 
}
 
void Sort(int *cod, float *tot, int t){
  
    int i,j;
    int aux, min;
    float aux_t;

    printf("\033[22;31mRealizando operação de selection sort\n");

    for (i = 0; i < (t-1); i++){
        min = i;

        for(j = i + 1; j < t; j++){
            if (tot[j] < tot[min]){
                min = j;
            }
        }
        if (tot[i] != tot[min]) {
            aux_t = tot[i];
            tot[i] = tot[min];
            tot[min] = aux_t;

            aux = cod[i];
            cod[i] = cod[min];
            cod[min] = aux;                
        }
    }

}
 
int ArraySave(int *cod, float *tot, char arqsave[50]){
 
    FILE *fileS = fopen(arqsave, "w+");
 
    int i;
 
    printf("\033[22;31mSalvando arquivo\n");

    for(i = 0; i <= 99; i++){
        fprintf(fileS, "%d;", cod[i]);
        fprintf(fileS, "%.2f", tot[i]);
            if (i != 99){
                fprintf(fileS, "\n");
            }
    }
 
    fclose(fileS);
 
    return 1;
}
