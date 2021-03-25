#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no* dir, * esq;
    int valor;
}No;

void inserir(No** R, int valor){
    if(*R == NULL){
        No* temp = (No*) malloc( sizeof( No ) );
        temp->valor = valor;
        temp->dir = temp->esq = NULL;
        R = temp;
    }else{
        if(valor > (*R)->valor){
            inserir(&(*R)->dir, valor);
        }else{
            inserir(&(*R)->esq, valor);
        }
        correcao(R);
    }
}

void correcao(No** R){

}