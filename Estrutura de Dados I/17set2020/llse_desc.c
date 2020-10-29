#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct desc{
	No *ini, *fim;
}Desc;

void inserir_ini_llse_desc(Desc *D, int vlr){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	novo->dado = vlr;
	novo->prox = NULL;

	if (D->ini == NULL){
		D->ini = novo;
		D->fim = novo;
	}else{
		novo->prox = D->ini;
		D->ini = novo;
	}
}

void mostrar_llse_desc(Desc *D){
	if (D->ini == NULL)
		printf("Lista vazia.\n");
	else{
		No *p;
		for (p=D->ini; p!=NULL; p=p->prox){
			printf("%i\n", p->dado);
		}
	}
}

int main(){
	Desc D;
	D.ini = NULL;	// inicialização
	D.fim = NULL;

	inserir_ini_llse_desc(&D, 10);
	inserir_ini_llse_desc(&D, 20);
	inserir_ini_llse_desc(&D, 30);

	mostrar_llse_desc(&D);

}


