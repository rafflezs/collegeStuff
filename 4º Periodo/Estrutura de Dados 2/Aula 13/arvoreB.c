#include <stdio.h>
#include <stdlib.h>

#define GRAU 4

typedef struct no{
    struct no *filhos[GRAU+1];
    int qtd_chaves;
    int chaves[GRAU];
}No;

No* criar_no();
void inserir(No** raiz, int valor);
void pre_ordem(No** raiz);
void pre_ordem_nivel(No** raiz, int nivel);
void mostrar_no(No** raiz, int nivel);

int main(){

    No* bTree = NULL;

    inserir(&bTree, 10);
    pre_ordem(&bTree);

}

No* criar_no(){

    No* temp = (No*) malloc( sizeof( No ) );
    temp->qtd_chaves = 0;
    for(int i = 0; i < GRAU+1; i++){
        temp->filhos[i] = NULL;
    }

    return temp;
}

void inserir(No** raiz, int valor){
    if(*raiz == NULL){
        *raiz = criar_no();
        (*raiz)->chaves[0] = valor;
        (*raiz)->qtd_chaves++;
        return;
    }
    if((*raiz)->filhos[0] == NULL){

    }else{
        
    }
}

void pre_ordem(No** raiz){
    pre_ordem_nivel(raiz, 0);
}

void pre_ordem_nivel(No** raiz, int nivel){
    if(*raiz != NULL){
        mostrar_no(raiz, nivel);
        for(int i = 0; i < GRAU+1; i++) pre_ordem_nivel(&(*raiz)->filhos[i], nivel+1);
    }
}

void mostrar_no(No** raiz, int nivel){
    int i;
    printf("Nivel : %i - Qtd[%i]\n", nivel, (*raiz)->qtd_chaves);
    for( i = 0; i < GRAU+1; i++) printf("Chave : %i\n", (*raiz)->chaves[i]);
}