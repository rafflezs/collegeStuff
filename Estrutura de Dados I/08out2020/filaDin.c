#include "filaDin.h"

void mostrar(Desc* d){
    for(No* temp = d->inicio; temp != NULL; temp = temp->prox){
        printf("%d ||", temp->dado);
    }
    printf("\n");
}

int enfileirar(Desc* d, int val){
    No* novo = (No*) malloc(sizeof(No));

    if(novo == NULL){
        return 0;
    }

    novo->dado = val;
    novo->prox = NULL;

    if(d->inicio == NULL){
        d->inicio = novo;
        d->fim = novo;
    }else{
        d->fim->prox = novo;
        d->fim = novo;
    }

    return 1;
}

int desenfileirar(Desc* d, int val){
    if(d->inicio == NULL){
        return 0;
    }
    
    No* novo = (No*) malloc(sizeof(No));
    novo = d->inicio;    
    d->inicio = d->inicio->prox;
    free(novo);

    if(d->inicio == NULL){
        d->fim = NULL;
    }

    return 1;

}

int* primeiro(Desc* d){
    if(d->inicio == NULL){
        return NULL;
    }

    return &d->inicio->dado;
}