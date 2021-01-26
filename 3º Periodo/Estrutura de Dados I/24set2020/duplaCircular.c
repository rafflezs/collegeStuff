#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct No* prox;
    struct No* ant;
}No;

typedef struct lista{
    struct No* cabeca;
}Lista;

typedef struct descritor{
    int qtdPos;
    struct No* inicio;
    struct No* fim;
}Descritor;

Lista* criarLista(){
    
    Lista* novaLista = (Lista*) malloc(sizeof(Lista));

    if(novaLista == NULL){
        return NULL;
    }

    No* novo = (No*) malloc(sizeof(No));
    novo->ant = NULL;
    novo->prox = NULL;

    novaLista->cabeca = novo;

    return novaLista;
}

int inserirIncio(Lista* novaLista, int valor){

    if(novaLista == NULL){
        printf("Operação Inválida.\n");
        exit(0);
    }

    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    if(novaLista->cabeca == NULL){
        novaLista->cabeca = novo;
        return 1;
    }else{
        novo->prox = novaLista->cabeca;
        novaLista->cabeca = novo;
        return 1;
    }

    return 0;
}

int inserirFim(Lista* novaLista, int valor){

    if(novaLista == NULL){
        printf("Operação Inválida.\n");
        exit(0);
    }

    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    if(novaLista->cabeca == NULL){
        novaLista->cabeca = novo;
        return 1;
    }else{
        novo->prox = novaLista->cabeca;
        novaLista->cabeca = novo;
        return 1;
    }

    return 0;
}

void mostrarLista(Lista* novaLista){

    if(novaLista == NULL){
        printf("Operação Inválida.\n");
        exit(0);
    }

    No* temp;

    for(temp = novaLista->cabeca; temp->prox != NULL; temp = temp->prox){
        printf("Valor: %d\n", temp->valor);
    }

}

int main(){

    Lista* lista1 = criarLista();

    inserirIncio(lista1, 10);
    inserirIncio(lista1, 20);
    inserirIncio(lista1, 30);
    inserirIncio(lista1, 40);
    inserirIncio(lista1, 50);

    mostrarLista(lista1);

    return 0;
}