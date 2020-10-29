#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct fila{
	No *ini, *fim;
}Fila;

Fila * criar_fila(){
	Fila* nova = (Fila*) malloc(sizeof(Fila));
    nova->ini = nova->fim = NULL;

    return nova;
}

int * primeiro(Fila *f){
	if (f == NULL){
		printf("Tentativa de usar a fila sem antes criar a estrutura.\n");
		exit(0);
	}

	if (f->ini == NULL)
		return NULL;

	return &f->ini->dado;
}

// Inserir no fim de uma llse com descritor
int enfileirar(Fila *f, int vlr){
	if (f == NULL){
		printf("Tentativa de usar a fila sem antes criar a estrutura.\n");
		exit(0);
	}

	No *novo;
	novo = (No*) malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = vlr;
	novo->prox = NULL;

	if (f->ini == NULL){
		f->ini = novo;
		f->fim = novo;
	}else{
		f->fim->prox = novo;
		f->fim = novo;
	}	

	return 1;
}

// Remover no início de uma llse com descritor
int desenfileirar(Fila *f){
	if (f == NULL){
		printf("Tentativa de usar a fila sem antes criar a estrutura.\n");
		exit(0);
	}

	if (f->ini == NULL)
		return 0;
	
	No *p;
	p = f->ini;
	f->ini = p->prox;	
	free(p);
	if (f->ini == NULL)
		f->fim = NULL;

	return 1;
}

void remover_fila(Fila **fila){
	
    No * temp = NULL, * aux = (*fila)->ini;

    for(; aux != NULL;){
        temp = aux;
        aux = aux->prox;
        free(temp);

    }

    free((*fila));

}

int tamanho_da_fila(Fila *fila){
	int tam = 0;

    for(No* aux = fila->ini; aux != NULL; aux = aux->prox){
        tam++;
    }

    return tam;
}

void mostrar_fila(Fila *f){
	if (f == NULL){
		printf("Tentativa mostrar a fila sem antes criar a estrutura.\n");
		exit(0);
	}

	if (f->ini == NULL)
		printf("Lista vazia.\n");
	else{
		No *p;
		for (p=f->ini; p!=NULL; p=p->prox){
			printf("%i\n", p->dado);
		}
	}
}

int main(){

    Fila* fila = criar_fila();
    
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 40);

    mostrar_fila(fila);

    printf("Tamanho da lista: %i\n", tamanho_da_fila(fila));

    remover_fila(&fila);

    mostrar_fila(fila);

    return 0;

}