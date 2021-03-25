#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define GRAU 4

typedef struct no {
	int qtd_chaves;
	int chaves[GRAU];
	struct no *filhos[GRAU+1];
}No;

No * criar_no(){
	int i;
	No *novo = (No *)malloc(sizeof(No));
	for (i=0; i<GRAU+1; i++){
		novo->filhos[i] = NULL;
	}
	novo->qtd_chaves = 0;

	return novo;
}

void par(No **R, int nivel){
	int i;
	for(i=0; i<(*R)->qtd_chaves; i++){
		if((*R)->chaves[i] % 2 == 0) printf("%i ", (*R)->chaves[i]);
	}
	printf("\n");
}

void pre_ordem_par(No **R, int nivel){
	if (*R!=NULL){
		int i;
		par(R, nivel);
		for (i=0; i<GRAU+1; i++){
			pre_ordem_par(&(*R)->filhos[i], nivel+1);
		}
	}
}

void mostrar_par(No **R){
	pre_ordem_par(R, 0);
}

void inserir_mais_um(No **R, int vlr){
	int i;
	for(i=(*R)->qtd_chaves-1; i>=0; i--){
		if (vlr > (*R)->chaves[i])
			break;
		(*R)->chaves[i+1] = (*R)->chaves[i];
		(*R)->filhos[i+2] = (*R)->filhos[i+1];
	}

	(*R)->chaves[i+1] = vlr;
	(*R)->qtd_chaves++;
}

No ** obterFilhoDescida(No **R, int vlr){
	int i;

	for (i=0; i<(*R)->qtd_chaves; i++){
		if (vlr < (*R)->chaves[i]){
			break;
		}
	}
	return &(*R)->filhos[i];
}

No * criar_irmao(No **R){
	No *irmao;
	int i, j;

	irmao = criar_no();

	for (i=ceil(GRAU/2.0), j=0; i<GRAU; i++, j++){
		irmao->qtd_chaves++;
		(*R)->qtd_chaves--;
		irmao->chaves[j] = (*R)->chaves[i];
		irmao->filhos[j] = (*R)->filhos[i];
		(*R)->filhos[i] = NULL;
	}
	irmao->filhos[j] = (*R)->filhos[i];
	(*R)->filhos[i] = NULL;

	(*R)->qtd_chaves--; // chave do elemento promovido
	return irmao;	
}

void divide_no_interno(No **R, No **filho){
	No *irmao;

	irmao = criar_irmao(filho);
	
	inserir_mais_um(R, (*filho)->chaves[(int) ceil(GRAU/2.0) -1 ]);
	filho++;
	*filho = irmao;	
}

void inserir(No **R, int vlr){
	if (*R == NULL){
		*R = criar_no();
		(*R)->chaves[0] = vlr;
		(*R)->qtd_chaves++;
		return;
	}

	if ((*R)->filhos[0] == NULL){ // Nó folha
		inserir_mais_um(R, vlr);
	}else{
		// identificar a ramificação p/ descer na árvore
		No **filho;
		filho = obterFilhoDescida(R, vlr);
		inserir(filho, vlr);

		if ((*filho)->qtd_chaves >= GRAU){
			divide_no_interno(R, filho);
		}
	}	
}


void divide_no_raiz(No **R){
	No *irmao;

	irmao = criar_irmao(R);

	//Criar nó raiz
	No *novo = criar_no();
	novo->chaves[0] = (*R)->chaves[(int) ceil(GRAU/2.0) -1 ];
	novo->qtd_chaves++;
	novo->filhos[0] = *R;
	novo->filhos[1] = irmao;

	*R = novo;
}

void inserir_B(No **R, int valor ){

	inserir(R, valor);
	if ((*R)->qtd_chaves >= GRAU) divide_no_raiz(R);

}


int main(){

	No *R=NULL;

    //Elementos testes em ordem: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
    //A resposta devera ser: 4, 8,   2,   6,    10, 12,   14

    int valoresTestes[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    for(int index = 0; index < sizeof(valoresTestes) / sizeof( int ); index++) inserir_B((&R), valoresTestes[index]);
    mostrar_par((&R));
}
