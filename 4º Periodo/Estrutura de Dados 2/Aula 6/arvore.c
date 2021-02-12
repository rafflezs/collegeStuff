#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	struct no *esq, *dir;
	int dado;
}No;

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

void pre_ordem(No **R){
	// visite a raiz, esq, dir
	if (*R!=NULL){
		printf("%i\n", (*R)->dado);
		pre_ordem(&(*R)->esq);
		pre_ordem(&(*R)->dir);
	}
}

void em_ordem(No **R){
	// esq, visite a raiz, dir
	if (*R!=NULL){
		em_ordem(&(*R)->esq);
		printf("%i\n", (*R)->dado);
		em_ordem(&(*R)->dir);
	}
}

void pos_ordem(No **R){
	// esq, dir, visite a raiz
	if (*R!=NULL){
		pos_ordem(&(*R)->esq);
		pos_ordem(&(*R)->dir);
		printf("%i\n", (*R)->dado);
	}
}

int menu(){
	int opc;

	system("clear");

	printf("[0] - Sair\n");
	printf("[1] - inserir\n");
	printf("[2] - Pré-ordem\n");
	printf("[3] - Em-ordem\n");
	printf("[4] - Pós-ordem\n");
	printf("[5] - Quantidade de elementos\n");
	printf("[6] - Maior elemento\n");
	printf("[8] - Remover o maior elemento\n");
	printf("[9] - Remover um elemento qualquer\n");
	printf("[10] - Mostrar folhas\n");
	printf("[11] - Balanceamento\n\n");


	printf("Escolha uma opção: ");
	scanf("%i", &opc);
	return opc;
}

int qtd_elementos(No **R){
	if (*R == NULL)
		return 0;
	
	return 	1 + 
				qtd_elementos(&(*R)->esq) + 
				qtd_elementos(&(*R)->dir);
}

int * maior_elemento_rec(No **R){
	if (*R == NULL)
		return NULL;

	if ((*R)->dir == NULL)
		return &(*R)->dado;

	return maior_elemento_rec(&(*R)->dir);
}

No * maior_elemento(No **R){
	if (*R == NULL)
		return NULL;

	No *p;
	for (p=*R; p->dir != NULL; p=p->dir);
	return p;
}

int remover_maior_rec(No **R){
	if (*R == NULL)
		return 0;
	if ((*R)->dir == NULL){
		No *aux;
		aux = *R;
		*R = aux->esq; // *R = (*R)->esq
		free(aux);
		return 1;
	}
	return remover_maior_rec(&(*R)->dir);
}

int remover_maior(No **R){
	if (*R == NULL)
		return 0;

	No *p, *q = NULL;
	for (p=*R; p->dir != NULL; p=p->dir){
		q = p;
	}

	if (q == NULL)
		*R = p->esq;
	else
		q->dir = p->esq;
	
	free(p);

	return 1;
}

int remover_elemento_qualquer(No **R, int vlr){
	if (*R == NULL)
		return 0;

	if ((*R)->dado == vlr){
		
		if ((*R)->esq == NULL){ 	//caso 1
			No *aux = *R;
			*R = aux->dir;
			free(aux);
			return 1;
		}
		if ((*R)->dir == NULL){ 	//caso 2
			No *aux = *R;
			*R = aux->esq;
			free(aux);
			return 1;
		}
		//caso 3
		(*R)->dado = * maior_elemento_rec(&(*R)->esq);		
		return remover_elemento_qualquer(&(*R)->esq, (*R)->dado);

	}else{
		if (vlr > (*R)->dado){
			return remover_elemento_qualquer(&(*R)->dir, vlr);
		}else{
			return remover_elemento_qualquer(&(*R)->esq, vlr);
		}
	}
}

void mostrar_folhas(No **R){
	if (*R!=NULL){
		if ((*R)->esq == NULL && (*R)->dir == NULL)
			printf("%i\n", (*R)->dado);
		mostrar_folhas(&(*R)->esq);
		mostrar_folhas(&(*R)->dir);
	}
}
