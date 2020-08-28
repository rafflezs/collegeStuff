#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

//Operações de menu

//Operações de pilha
typedef struct no{
    int dado;
    struct no *proximo;
}No;

struct pilha{
    struct no *elemento_topo;
};

Pilha* criar_pilha(){
    Pilha* nova_pilha;
    nova_pilha = (Pilha*) malloc(sizeof(Pilha));
    if(nova_pilha == NULL)
    {
        return NULL;
    }
    nova_pilha->elemento_topo = NULL;
    return nova_pilha;
}

void remover_todos(Pilha* pilha){
    if(pilha == NULL)
    {
        printf("Operacao invalida.\n");
        exit(0);
    }

    while(desempilhar(pilha) == 1);
}

int empilhar(Pilha* pilha, int valor){
    if(pilha == NULL)
    {
        printf("Operacao invalida.\n");
        exit(0);
    }

    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL)
    {
        return 0;
    }
    novo->dado = valor;
    novo->proximo = NULL;

    if(pilha->elemento_topo == NULL)
    {
        pilha->elemento_topo = novo;
    }else
    {
        novo->proximo = pilha->elemento_topo;
        pilha->elemento_topo = novo;
    }
    
    return 1;
}

int desempilhar(Pilha* pilha){
    if(pilha == NULL)
    {
        printf("Operacao invalida.\n");
        exit(0);
    }

    if(pilha->elemento_topo == NULL)
    {
        return 0;
    }

    No* temporario = pilha->elemento_topo;
    pilha->elemento_topo = temporario->proximo;
    free(temporario);

    return 1;
}

int topo(Pilha* pilha){
    if(pilha == NULL)
    {
        printf("Operacao invalida.\n");
        exit(0);
    }

    if(pilha == NULL)
    {
        exit(0);
    }

    return pilha->elemento_topo->dado;
}

int pilha_vazia(Pilha* pilha){
    if(pilha == NULL)
    {
        printf("Operacao invalida.\n");
        exit(0);
    }

    if(pilha->elemento_topo == NULL)
    {
        return 1;
    }

    return 0;
}

//Função de debug - evitar usar
void mostrar_pilha(Pilha* pilha){
    if(pilha == NULL)
    {
        printf("Operacao invalida.\n");
        exit(0);
    }

    for(No* temporario = pilha->elemento_topo; temporario != NULL; temporario = temporario->proximo)
    {
        printf("%d\n", temporario->dado);
    }
}