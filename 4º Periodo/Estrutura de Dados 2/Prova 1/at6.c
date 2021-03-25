#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *esq, *dir;
}No;

int existe_n(No **R, int n){

    if( *R == NULL) return 0;
    else if((*R)->dado == n) return 1;
    else if((*R)->dado > n) { return existe_n(&(*R)->esq, n); }
    else if((*R)->dado <= n) { return existe_n(&(*R)->dir, n); }
}

//Trecho de código copiado do AVA
void inserir(No **R, int valor){
	if (*R == NULL){
		// inserir os códigos de alocação
		No *novo;
		novo = (No *)malloc(sizeof(struct no));
		novo->dado = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		
		*R = novo;
	}else{
		//fazer comparação p/ definir se vamos p/ esq ou dir
		if (valor > (*R)->dado){
			// ir para direita
			inserir( &(*R)->dir, valor);
		}else{
			// ir para esquerda
			inserir( &(*R)->esq, valor);
		}
	}
}



int main(){

    No* R = NULL;

    inserir(&R,10);
    inserir(&R,20);
    inserir(&R,30);
    inserir(&R,40);
    inserir(&R,5);
    inserir(&R,4);
    inserir(&R,3);

    if(existe_n(&R,0)) printf("N : %i existe\n", 0);
    else printf("N : %i NÃO existe\n", 0);

    return 0;

}