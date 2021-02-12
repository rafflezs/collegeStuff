#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	char car;
	int freq;
	struct no *prox, *esq, *dir;
}No;

//###### Operações com a lista

void inserir_ordenado(No **C, char car, int freq){
	No *novo;
	novo = (No *)malloc(sizeof(struct no));
	novo->car = car;
	novo->freq = freq;
	novo->prox = NULL;
	novo->esq = NULL;
	novo->dir = NULL;

	if (*C == NULL)
		*C = novo;
	else{
		No *p, *q=NULL;
		for (p=*C; p!=NULL; p=p->prox){
			if (freq <= p->freq)
				break;
			q=p;
		}
		if (q==NULL){ //inserção no início
			novo->prox = p;
			*C = novo;
			return;
		}
		//inserção no fim ou meio
		q->prox = novo;
		novo->prox = p;
	}
}

void mostrar_lista(No **C){
	if (*C == NULL)
		printf("LIsta vazia.\n");
	else{
		No *p;
		for (p=*C; p!=NULL; p=p->prox){
			printf("%c %i |", p->car, p->freq);
		}
		printf("\n");
	}
}

//###### Fim das operações com lista


void inicializar_frequencia(int freq[]){
	int i;
	for (i=0; i<256; i++){
		freq[i]=0;
	}
}

void mostrar_frequencia(int freq[]){
	int i;
	for (i=0; i<256; i++){
		if (freq[i]!=0)
			printf("[%i - %c]=%i\n", i, i, freq[i]);
	}
}

void contagem_frequencia(char str[], int freq[]){
	int i;
	for (i=0; str[i]!='\0'; i++){
		freq[str[i]]++;
	}
}

void adicionar_freq_na_lista(int freq[], No **C){
	int i;
	for (i=0; i<256; i++){
		if (freq[i]!=0){
			inserir_ordenado(C, i, freq[i]);
			//printf("inserindo %i - %i\n", i, freq[i]);
			//getchar();
		}
	}
}

int main(){
	char str[] = "teste de mesa";
	int freq[256];
	No *C=NULL;

	inicializar_frequencia(freq);
	contagem_frequencia(str, freq);
	mostrar_frequencia(freq);

	adicionar_freq_na_lista(freq, &C);
	mostrar_lista(&C);

}