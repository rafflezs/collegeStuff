#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no* esq;
    struct no* dir;
    int valor;
}No;

No* criarArvore();

void preOrdemRec(No** raiz);
void emOrdemRec(No** raiz);
void posOrdemRec(No** raiz);

void preOrdemIt(No** raiz);
void emOrdemIt(No** raiz);
void posOrdemIt(No** raiz);

void inserir(No** raiz, int valor);

int main(){

    No* raiz = NULL;

    //usa ponteiro duplo - nesse caso inserir é do tipo void/int
    //inserir(&raiz, valor);

    //não usa ponteiro duplo - nesse caso inserir é do tipo No
    //raiz = (raiz, valor);

    inserir(&raiz, 5);
    inserir(&raiz, 10);
    inserir(&raiz, 15);
    inserir(&raiz, 1);
    inserir(&raiz, 2);

    printf("\nPre Ordem\n");
    preOrdemRec(&raiz);
    printf("\nEm Ordem\n");
    emOrdemRec(&raiz);
    printf("\nPos Ordem\n");
    posOrdemRec(&raiz);

    return 0;
}

/* No* criarArvore(){

    No* raiz = (No*) malloc( sizeof( struct no ) );
    raiz = NULL;
    return raiz;
} */

void preOrdemRec(No** raiz){

    if(*raiz != NULL){
        printf("%i\n", (*raiz)->valor);
        preOrdemRec(&(*raiz)->esq);
        preOrdemRec(&(*raiz)->dir);
    }
}

void emOrdemRec(No** raiz){

    if(*raiz != NULL){
        emOrdemRec(&(*raiz)->esq);
        printf("%i\n", (*raiz)->valor);
        emOrdemRec(&(*raiz)->dir);
    }
}

void posOrdemRec(No** raiz){

    if(*raiz != NULL){
        posOrdemRec(&(*raiz)->esq);
        posOrdemRec(&(*raiz)->dir);
        printf("%i\n", (*raiz)->valor);
    }
}

void preOrdemIt(No** raiz){

    for(;;){

    }

}

void inserir(No** raiz, int valor){

    if(*raiz == NULL){
        
        No* temp = (No*) malloc( sizeof( struct no ) );
        temp->valor = valor;
        temp->esq = temp->dir = NULL;

        *raiz = temp;
    }else{
        if(valor > (*raiz)->valor){
            inserir( &(*raiz)->dir, valor);
        }else{
            inserir( &(*raiz)->esq, valor);
        }
    }

}

