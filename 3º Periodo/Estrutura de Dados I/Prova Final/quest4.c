#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
}No;

void insere(No** lista, int dado);
int tamLista(No** lista);

int main(){

    No* lista = NULL;

    //Lista de tam = 4
    insere(&lista, 10);
    insere(&lista, 1220);
    insere(&lista, 410);
    insere(&lista, 0);

    printf("O tamanho da lista é: %i\n", tamLista(&lista));

    return 0;
}

void insere(No** lista, int dado){

    No* temp = (No*) malloc (sizeof (No));

    if(temp == NULL){
        exit(0);
    }

    temp->dado = dado;
    temp->prox = NULL;

    if(*lista == NULL){
        *lista = temp;
        temp->prox = temp;
    }else{
        No* aux = *lista;
        while(aux->prox != *lista){
            aux = aux->prox;
        }
        aux->prox = temp;
        temp->prox = *lista;
    }

}

int tamLista(No** lista){

    if (*lista == NULL){
		printf("Lista vazia.\n");
		return 0;
	}

    int tam = 0;
	No *aux;
	for (aux = *lista; aux->prox != *lista; aux = aux->prox){
		tam++;
	}
	return tam+1;
}