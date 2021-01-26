#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int dado;
    struct no* ant, * prox;

}No;

typedef struct descritor{
    
    int qtdCampos;
    int maiorValor;
    struct no* cabeca;
    struct no* noQueVaiNoFinalDaLista; //Eu não sei o antônimo de cabeça/cabeçalho

}Descritor;

void inserir(Descritor* d, int dado);
void removerFim(Descritor* d);
void exibeLista(Descritor* d);

int main(){

    Descritor* d = (Descritor*) malloc (sizeof(Descritor));
    d->cabeca = NULL;
    d->noQueVaiNoFinalDaLista = NULL;
    d->qtdCampos = 0;

    inserir(d, 190);

    exibeLista(d);

    removerFim(d);

    exibeLista(d);

    return 0;

}

void inserir(Descritor* d, int dado){

    No* temp = (No*) malloc (sizeof (No));
    temp->dado = dado;
    temp->prox = NULL;
    temp->ant = NULL;

    if(d->cabeca == NULL){
        d->cabeca = temp;
        d->noQueVaiNoFinalDaLista = temp;
    }else{
        temp->prox = d->cabeca;
        d->cabeca->ant = temp;
        d->cabeca = temp;
    }

    d->qtdCampos++;
    if(dado >= d->maiorValor){
        d->maiorValor = dado;
    }

}

void removerFim(Descritor* d){

    if(d->cabeca == NULL){
        return;
    }

    d->qtdCampos--;

    if(d->cabeca == d->noQueVaiNoFinalDaLista){
        free(d->cabeca);
        d->cabeca = NULL;
        d->noQueVaiNoFinalDaLista = NULL;
        d->maiorValor = 0;
        return;
    }

    d->noQueVaiNoFinalDaLista = d->noQueVaiNoFinalDaLista->ant;
    //Se o no a ser deletado conter o dado de maior valor da lista
    if(d->noQueVaiNoFinalDaLista->prox->dado == d->maiorValor){
        //Percorre a lista para achar o maior valor caso
        d->maiorValor = 0;
        for(No* temp = d->cabeca; temp->prox != NULL; temp = temp->prox){
            if(temp->dado > d->maiorValor){
                d->maiorValor = temp->dado;
            }
        } 
    }

    free(d->noQueVaiNoFinalDaLista->prox);
    d->noQueVaiNoFinalDaLista->prox = NULL;

}

void exibeLista(Descritor* d){

    for(No* temp = d->cabeca; temp != NULL; temp = temp->prox){
        printf("| %i |", temp->dado);
    }

    printf("\nTamanho da lista: %i\nMaior valor: %i\n", d->qtdCampos, d->maiorValor);

}