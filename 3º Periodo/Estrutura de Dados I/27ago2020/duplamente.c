#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *ant, *prox;
}No;

void inserir_inicio(No** lista, int dado){
    No* novo;

    novo = (No*) malloc(sizeof(No));
    novo->ant = novo->prox = NULL;
    novo->dado = dado;

    if(*lista == NULL){
        *lista = novo;
    }else{
        novo->prox = *lista;
        (*lista)->ant = novo;
        *lista = novo;
    }
}

void mostrar(No **lista){
    No* p;

    if(*lista == NULL){
        printf("Lista vazia\n");
    }else{
        for(p = *lista; p != NULL; p = p->prox)
            printf("%i\n", p->dado);
    }
}

int main(){

    No* A;
    
    

    return 0;
}