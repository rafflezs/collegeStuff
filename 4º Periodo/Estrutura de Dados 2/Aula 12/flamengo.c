#include<stdio.h>
#include<stdlib.h>

typedef enum{
	VERMELHO,
	PRETO
}COR;

typedef struct no{
	struct no *esq, *dir, *pai;
	COR cor;
	int dado;
}No;

void correcao(No **raiz){
	while((*raiz)->pai != NULL){
		if((*raiz)->pai->cor == PRETO) return;
	}

	if ((*raiz)->pai == NULL){
		(*raiz)->cor = PRETO;
	}
}

void inserir(No **raiz, int valor){
	if (*raiz == NULL){
		// inserir os códigos de alocação
		No *novo;
		novo = (No *)malloc(sizeof(struct no));
		novo->dado = valor;
		novo->esq = novo->dir = novo->pai = NULL;
		novo->cor = VERMELHO;

		*raiz = novo;
	}else{
		if (valor > (*raiz)->dado){
			// ir para direita
			inserir( &(*raiz)->dir, valor);
			(*raiz)->dir->pai = *raiz; 
			
		}else{
			// ir para esquerda
			inserir( &(*raiz)->esq, valor);
			(*raiz)->esq->pai = *raiz;

		}
	}
}

void rse(No **raiz){
	No *temp;

	temp = *raiz;
	*raiz = temp->dir;
	temp->dir = (*raiz)->esq;
	(*raiz)->esq = temp;

	//atualização do campo de pai
	(*raiz)->pai = temp->pai;
	temp->pai = *raiz;
	if (temp->dir != NULL)
		temp->dir->pai = temp;	
}

void rsd(No **raiz){
	No *temp;

	printf("rsd(%i)\n", (*raiz)->dado);

	temp = *raiz;
	*raiz = temp->esq;
	temp->esq = (*raiz)->dir;
	(*raiz)->dir = temp;

	//atualização do campo de pai
	//(*raiz)->pai = temp->pai;
	//temp->pai = *raiz;
	//if (temp->esq != NULL)
	//	temp->esq->pai = temp;	
}

void pre_ordem(No **raiz){
	// visite a raiz, esq, dir
	if (*raiz!=NULL){
		if ((*raiz)->pai == NULL)
			if ((*raiz)->cor == VERMELHO)
				printf("%p (Vermelho) [pai: NULL]\n", (*raiz)->dado);
			else
				printf("%p (Preto) [pai: NULL]\n", (*raiz)->dado);
		else
			if ((*raiz)->cor == VERMELHO)
				printf("%i (Vermelho) [pai: %i]\n", (*raiz)->dado, (*raiz)->pai->dado);
			else
				printf("%i (Preto) [pai: %i]\n", (*raiz)->dado, (*raiz)->pai->dado);
		pre_ordem(&(*raiz)->esq);
		pre_ordem(&(*raiz)->dir);
	}
}

void em_ordem(No **raiz){
	// esq, visite a raiz, dir
	if (*raiz!=NULL){
		em_ordem(&(*raiz)->esq);
		printf("%i\n", (*raiz)->dado);
		em_ordem(&(*raiz)->dir);
	}
}

void pos_ordem(No **raiz){
	// esq, dir, visite a raiz
	if (*raiz!=NULL){
		pos_ordem(&(*raiz)->esq);
		pos_ordem(&(*raiz)->dir);
		printf("%i\n", (*raiz)->dado);
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

int qtd_elementos(No **raiz){
	if (*raiz == NULL)
		return 0;
	
	return 	1 + 
				qtd_elementos(&(*raiz)->esq) + 
				qtd_elementos(&(*raiz)->dir);
}

int * maior_elemento_rec(No **raiz){
	if (*raiz == NULL)
		return NULL;

	if ((*raiz)->dir == NULL)
		return &(*raiz)->dado;

	return maior_elemento_rec(&(*raiz)->dir);
}

No * maior_elemento(No **raiz){
	if (*raiz == NULL)
		return NULL;

	No *p;
	for (p=*raiz; p->dir != NULL; p=p->dir);
	return p;
}

int remover_maior_rec(No **raiz){
	if (*raiz == NULL)
		return 0;
	if ((*raiz)->dir == NULL){
		No *temp;
		temp = *raiz;
		*raiz = temp->esq; // *raiz = (*raiz)->esq
		if (*raiz != NULL){
				temp->esq->pai = temp->pai;  
			}
		free(temp);
		return 1;
	}
	return remover_maior_rec(&(*raiz)->dir);
}

int remover_maior(No **raiz){
	if (*raiz == NULL)
		return 0;

	No *p, *q = NULL;
	for (p=*raiz; p->dir != NULL; p=p->dir){
		q = p;
	}

	if (q == NULL)
		*raiz = p->esq;
	else
		q->dir = p->esq;
	
	free(p);

	return 1;
}

int remover_elemento_qualquer(No **raiz, int vlr){
	if (*raiz == NULL)
		return 0;

	if ((*raiz)->dado == vlr){
		
		if ((*raiz)->esq == NULL){ 	//caso 1
			No *temp = *raiz;
			*raiz = temp->dir;
			if (*raiz != NULL){
				temp->dir->pai = temp->pai;  
			}
			free(temp);
			return 1;
		}
		if ((*raiz)->dir == NULL){ 	//caso 2
			No *temp = *raiz;
			*raiz = temp->esq;
			if (*raiz != NULL){
				temp->esq->pai = temp->pai;  
			}
			free(temp);
			return 1;
		}
		//caso 3
		(*raiz)->dado = * maior_elemento_rec(&(*raiz)->esq);		
		return remover_elemento_qualquer(&(*raiz)->esq, (*raiz)->dado);

	}else{
		if (vlr > (*raiz)->dado){
			return remover_elemento_qualquer(&(*raiz)->dir, vlr);
		}else{
			return remover_elemento_qualquer(&(*raiz)->esq, vlr);
		}
	}
}

void mostrar_folhas(No **raiz){
	if (*raiz!=NULL){
		if ((*raiz)->esq == NULL && (*raiz)->dir == NULL)
			printf("%i\n", (*raiz)->dado);
		mostrar_folhas(&(*raiz)->esq);
		mostrar_folhas(&(*raiz)->dir);
	}
}

int main(){
	No *raiz = NULL;
	int opc, valor;
	No *temp;

	inserir(&raiz, 10);
	correcao(&raiz);
	

	pre_ordem(&raiz);

	inserir(&raiz, 20);
	correcao(&raiz);

	printf("---\n");
	pre_ordem(&raiz);

	exit(0);

/* 	while(opc = menu()){
		switch(opc){
			case 1:
				printf("valor: ");
				scanf("%i", &valor);
				inserir(&raiz, valor);
				printf("%i inserido.\n", valor);
				break;
			case 2:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					pre_ordem(&raiz);
				break;
			case 3:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					em_ordem(&raiz);
				break;
			case 4:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					pos_ordem(&raiz);
				break;
			case 5:
				printf("A quantidade de elementos é: %i\n", qtd_elementos(&raiz));
				break;
			case 6:
				temp = maior_elemento(&raiz);
				if (temp == NULL)
					printf("Arvore vazia.\n");
				else
					printf("O maior elemento é: %i\n", temp->dado);
				break;
			case 8:
				if (remover_maior_rec(&raiz))
					printf("Elemento removido.\n");
				else
					printf("Árvore vazia. Não é possível remover.\n");
				break;
			case 9:
				printf("valor: ");
				scanf("%i", &valor);

				if (remover_elemento_qualquer(&raiz, valor))
					printf("Elemento %i removido.\n", valor);
				else
					printf("Não é possível remover o elemento %i.\n", valor);
				break;
			case 10:
				if (R == NULL)
					printf("Árvore vazia.\n");
				else
					mostrar_folhas(&raiz);
				break;
			default:
				printf("Opção inválida.\n");
		}
		getchar();
		getchar();
	} */
}