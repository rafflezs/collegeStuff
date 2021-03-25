#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
	int dado;
	struct no *esq, *dir; 
}No;

No * obter_maior(No **R){

	if (*R==NULL) return NULL;
    if ((*R)->dir == NULL && (*R)->esq == NULL) return (*R); 

    No* esq = NULL, *dir = NULL;
    if((*R)->dir != NULL) dir = obter_maior(&(*R)->dir);
    if((*R)->esq != NULL) esq = obter_maior(&(*R)->esq);

    if(dir == NULL){
        if(esq->dado > (*R)->dado) return esq;
        else return *R;
    }

    if(esq == NULL){
        if(dir->dado > (*R)->dado) return dir;
        else return *R;
    }

    if(esq->dado > (*R)->dado && esq->dado > dir->dado) return esq;
    if(dir->dado > (*R)->dado && dir->dado > esq->dado) return dir;
    if((*R)->dado > esq->dado && (*R)->dado > dir->dado) return *R;
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
		if (rand() % 2){
			// ir para direita
			inserir( &(*R)->dir, valor);
		}else{
			// ir para esquerda
			inserir( &(*R)->esq, valor);
		}
	}
}

void pre_ordem(No **R){
	// visite a raiz, esq, dir
	if (*R!=NULL){
		printf("%i\n", (*R)->dado);
		pre_ordem(&(*R)->esq);
		pre_ordem(&(*R)->dir);
	}
}

int main(){

    srand( (unsigned)time(NULL) );
    No* R = NULL;

    inserir(&R,rand() % 11);
    inserir(&R,rand() % 11);
    inserir(&R,rand() % 11);
    inserir(&R,rand() % 11);
    inserir(&R,rand() % 11);
    inserir(&R,rand() % 11);
    inserir(&R,rand() % 11);

    pre_ordem(&R);

    No* mais_maior = obter_maior(&R);
    printf("%i\n", mais_maior->dado);
    return 0;

}