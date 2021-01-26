#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int dado;
    struct no* prox;

}No;

typedef struct descritor{
    
    int qtdCampos;
    int maiorValor;
    struct no* cabeca;
    struct no* noQueVaiNoFinalDaLista; //Eu não sei o antônimo de cabeça/cabeçalho

}Descritor;

void inserirFim(Descritor* d, int dado);
void exibeLista(Descritor* d);
int main(){

    Descritor* d = (Descritor*) malloc (sizeof(Descritor));
    d->cabeca = NULL;
    d->noQueVaiNoFinalDaLista = NULL;
    d->qtdCampos = 0;

    inserirFim(d, 30);
    inserirFim(d, 10);
    inserirFim(d, 40);

    exibeLista(d);

    return 0;

}

void inserirFim(Descritor* d, int dado){

    No* aux;
    No* temp = (No*) malloc (sizeof (No));
    temp->dado = dado;
    temp->prox = NULL;

    if(d->cabeca == NULL){
        d->cabeca = temp;
        d->noQueVaiNoFinalDaLista = temp;
    }else{
        aux = d->cabeca;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = temp;
    }

    d->qtdCampos++;
    if(dado >= d->maiorValor){
        d->maiorValor = dado;
    }

}

void exibeLista(Descritor* d){

    for(No* temp = d->cabeca; temp != NULL; temp = temp->prox){
        printf("| %i |", temp->dado);
    }

    printf("\nTamanho da lista: %i\nMaior valor: %i\n", d->qtdCampos, d->maiorValor);

}