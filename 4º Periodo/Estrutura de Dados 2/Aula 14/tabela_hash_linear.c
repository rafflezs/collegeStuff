#include <stdio.h>
#include <stdlib.h>

#define TAM 9

typedef struct tabela{
	int chave;
	int ocupado;
}Tabela;

// OPERAÇÕES PARA TABELA HASH

void iniciar_tabela(Tabela T[]){
	int i;
	for (i=0; i<TAM; i++){
		T[i].ocupado = 0;
	}
}

void mostrar_tabela(Tabela T[]){
	int i;
	for (i=0; i<TAM; i++){
		if (T[i].ocupado)
			printf("[%i] %i\n", i, T[i].chave);
		else
			printf("[%i] vazio.\n", i);
	}	
}

int hash(int chave){
	return chave % TAM;
}

int inserir_chave(Tabela T[], int chave){
	// contruir a função
}

int remover_chave(Tabela T[], int chave){
	// construir a função
}

int buscar_chave(Tabela T[], int chave){
	// construir a função
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
	Tabela tabela[TAM];
	iniciar_tabela(tabela);

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


