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
	printf("[10] - Mostrar folhas\n\n");
	printf("Escolha uma opção: ");
	scanf("%i", &opc);
	return opc;
}

int qtd_elementos(No **R){
	if (*R == NULL)
		return 0;
	
	return 	1 + qtd_elementos(&(*R)->esq) + qtd_elementos(&(*R)->dir);
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

void rse(No **R){
	No *aux;
	
	aux = *R;
	*R = aux->dir;
	aux->dir = (*R)->esq;
	(*R)->esq = aux;
}

void rsd(No** R){
	No* aux;
	
	aux = *R;
	*R = aux->esq;
	aux->esq = (*R)->dir;
	(*R)->dir = aux;
}

void rde(No** R){
	rsd(&(*R)->dir);
	rse(R);
}

void rdd(No** R){
	rse(&(*R)->esq);
	rsd(R);
}

int fator_balanceamento(No** R){
	if(*R == NULL)
		return 0;
	return altura_no(&(*R)->esq) - altura_no(&(*R)->dir);
}

int altura_no(No** R){
	if(*R == NULL)
		return -1;
	if( altura_no(&(*R)->esq) > altura_no(&(*R)->dir) )
		return altura_no(&(*R)->esq) + 1;
	return altura_no(&(*R)->dir) + 1;
}

void correcao(No** R){
	if(*R == NULL)
		return;
	int balanceamento  = fator_balanceamento(R);
	if(balanceamento > 1){
		if(fator_balanceamento((*R)->esq) >= 0){
			rsd(R);
		}else{
			rdd(R);
		}
	}
	if(balanceamento < -1 ){
		if(fator_balanceamento((*R)->dir) <= 0){
			rse(R);
		}else{
			rde(R);
		}
	}
}

int main(){
	No *R = NULL;
	int opc, valor;
	No *aux;
	
	inserir(&R, 10);
	inserir(&R, 15);
	inserir(&R, 20);
	inserir(&R, 30);
	pre_ordem(&R);
	
	rse(&(R->dir));
	printf("Pós rse.\n");
	pre_ordem(&R);
	/*
	while(opc = menu()){
		switch(opc){
			case 1:
				printf("valor: ");
				scanf("%i", &valor);
				inserir(&R, valor);
				printf("%i inserido.\n", valor);
				break;
			case 2:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					pre_ordem(&R);
				break;
			case 3:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					em_ordem(&R);
				break;
			case 4:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					pos_ordem(&R);
				break;
			case 5:
				printf("A quantidade de elementos é: %i\n", qtd_elementos(&R));
				break;
			case 6:
				aux = maior_elemento(&R);
				if (aux == NULL)
					printf("Arvore vazia.\n");
				else
					printf("O maior elemento é: %i\n", aux->dado);
				break;
			case 8:
				if (remover_maior_rec(&R))
					printf("Elemento removido.\n");
				else
					printf("Árvore vazia. Não é possível remover.\n");
				break;
			case 9:
				printf("valor: ");
				scanf("%i", &valor);
		
				if (remover_elemento_qualquer(&R, valor))
					printf("Elemento %i removido.\n", valor);
				else
					printf("Não é possível remover o elemento %i.\n", valor);
				break;
			case 10:
				if (R == NULL)
					printf("Árvore vazia.\n");
				else
					mostrar_folhas(&R);
				break;
			default:
				printf("Opção inválida.\n");
		}
		getchar();
		getchar();
	}
	*/
}