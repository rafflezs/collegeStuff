#include <stdio.h>
#include <stdlib.h>

#define TAM 9

// OPERAÇÕES PARA LISTA ENCADEADA

typedef struct no{
	int dado;
	struct no *prox;
}No;

int buscar_lista(No **C, int vlr){
	No *p;
	for (p=*C; p!=NULL; p=p->prox){
		if (p->dado == vlr)
			return 1;
	}
	return 0;
}

int inserir_inicio(No **C, int vlr){
	No *novo;

	novo = (No *)malloc(sizeof(No));
	if (novo == NULL){
		return 0;
	}

	novo->dado = vlr;
	novo->prox = NULL;

	novo->prox = *C;
	*C = novo;	
	
	return 1;	
}

int remover_por_valor(No **C, int vlr){
	if (*C == NULL)
		return 0;

	No *p, *q;
	for(q=NULL, p=*C; p!=NULL; p=p->prox){
		if (p->dado == vlr)
			break;
		q=p;
	}
	
	if (q == NULL) {	//remoção no início
		*C = p->prox;
		free(p);
		return 1;
	}

	if (p == NULL){	//elemento não encontrado
		return 0;
	}

	//remoção no meio ou no fim
	q->prox = p->prox;
	free(p);
	return 1;
}

void mostrar_lista(No **C){
	No *p;
	if (*C == NULL)
		printf("NULL");
	for (p=*C; p!=NULL ; p=p->prox){
		printf("%i ", p->dado);
	}
	printf("\n");
}


// OPERAÇÕES PARA TABELA HASH

void iniciar_tabela(No *T[]){
	int i;
	for (i=0; i<TAM; i++){
		T[i] = NULL;
	}
}

void mostrar_tabela(No *T[]){
	int i;
	for (i=0; i<TAM; i++){
		printf("[%i] ", i);
		mostrar_lista(&T[i]);
	}	
}

int hash(int chave){
	return chave % TAM;
}

int inserir_chave(No *T[], int chave){
	return inserir_inicio(&T[hash(chave)], chave);
}

int remover_chave(No *T[], int chave){
	return remover_por_valor(&T[hash(chave)],chave);
}

int buscar_chave(No *T[], int chave){
	return buscar_lista(&T[hash(chave)],chave);
}

int menu(){
	int opc;
	system("clear");

	printf("[1] - inserir\n");
	printf("[2] - remover\n");
	printf("[3] - buscar\n");
	printf("[4] - mostrar tabela\n");

	printf("Opção: ");
	scanf("%i", &opc);
	return opc;
}

int main(){
	int opc, chave;
	No *tabela[TAM];
	iniciar_tabela(tabela);

	inserir_chave(tabela, 5);
	inserir_chave(tabela, 28);
	inserir_chave(tabela, 19);
	inserir_chave(tabela, 15);
	inserir_chave(tabela, 20);
	inserir_chave(tabela, 33);

	while(opc = menu()){
		switch(opc){
			case 1:
				printf("chave: ");
				scanf("%i", &chave);
				if (inserir_chave(tabela, chave))
					printf("chave %i inserida.\n", chave);
				else
					printf("Não há espaço para a chave %i.\n", chave);
			break;

			case 2:
				printf("chave: ");
				scanf("%i", &chave);
				if (remover_chave(tabela, chave))
					printf("chave %i removida.\n", chave);
				else
					printf("chave %i não encontrada.\n", chave);
			break;

			case 3:
				printf("chave: ");
				scanf("%i", &chave);
				if (buscar_chave(tabela, chave))
					printf("chave %i encontrada.\n", chave);
				else
					printf("chave %i não encontrada.\n", chave);
			break;

			case 4:
				mostrar_tabela(tabela);
			break;

			default:
				printf("Opção inválida.\n");
		}
		getchar();
		getchar();
	}
}


