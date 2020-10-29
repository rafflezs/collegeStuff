#include <stdio.h>
#include <stdlib.h>
#define TAM 4

typedef struct fila{
	int vet[TAM];
	int ini, fim;
}Fila;

Fila * criar_fila(){
	Fila* nova = (Fila*) malloc(sizeof(Fila));
    nova->ini = nova->fim = 0;

    return nova;
}

int * primeiro(Fila *f){
	if (f == NULL){
		printf("Tentativa de usar a fila sem antes criar a estrutura.\n");
		exit(0);
	}
	
	if (f->ini == f->fim){
		return NULL;
	}

	return &f->vet[f->ini];
}

int enfileirar(Fila *f, int valor){
	if (f == NULL){
		printf("Tentativa de usar a fila sem antes criar a estrutura.\n");
		exit(0);
	}

	//Teste p/ verificar se a fila está cheia
	if (f->ini == (f->fim+1)%TAM)
		return 0;
	
	f->vet[f->fim] = valor;
	f->fim = (f->fim+1)%TAM;
	return 1;
}

int desenfileirar(Fila *f){
	if (f == NULL){
		printf("Tentativa de usar a fila sem antes criar a estrutura.\n");
		exit(0);
	}

	if (f->ini == f->fim){
		return 0;
	}

	f->ini = (f->ini+1)%TAM;
	return 1;
}

void limpar_fila(Fila *fila){
    for(int i = fila->fim-1; i == 0; i--){
        fila->vet[i] = 0;
    }

    fila->fim = 0;
}

int tamanho_da_fila(Fila *fila){
	return fila->fim;
}

void mostrar_fila(Fila *f){
	if (f == NULL){
		printf("Tentativa mostrar a fila sem antes criar a estrutura.\n");
		exit(0);
	}

	int i;
	if (f->ini == f->fim)
		printf("Fila vazia.\n");

	for (i=f->ini; i!=f->fim; i=(i+1)%TAM){
		printf("%i\n", f->vet[i]);
	}
}

int main(){

    Fila* fila = criar_fila();

    mostrar_fila(fila);

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);

    printf("Tamanho fila: %i\n", tamanho_da_fila(fila));
    mostrar_fila(fila);

    limpar_fila(fila);

    mostrar_fila(fila);

    printf("\n%i\n", fila->vet[fila->fim-1]);

    return 0;
}