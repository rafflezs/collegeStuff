#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABLE 50
#define REG_TAM 10000

typedef struct registro{
    
    struct registro* prox;

    int idade;
    /*
    **Segundo a legislação, um nome pode ter 20 caracteres
    **Considerando os espaços nos nomes, temos 36 caracteres
    */
    char nome[36];
    char cidade[36];
    char sexo; //O sexo é representado como 'F' e 'M'
}Registro;

void criar_tabela( Registro *tabela[] );
int hash( int chave );
int inserir( Registro* tabela[], Registro* reg );
int inserir_inicio(Registro **tabela, Registro* reg);
int remover( Registro* tabela[], Registro* reg );
int remover_por_valor(Registro **C, Registro* reg);
int busca( Registro* tabela[], Registro* reg );
int buscar_lista(Registro **C, Registro* reg);


void mostrar_lista(Registro **C){
	Registro *p;
	if (*C == NULL)
		printf("NULL");
	for (p=*C; p!=NULL ; p=p->prox){
		printf("Nome: %s\n", p->nome);
		printf("Idade: %i\n", p->idade);
		printf("Sexo: %c\n", p->sexo);
		printf("Cidade: %s\n", p->cidade);
	}
	printf("\n");
}

void mostrar_tabela(Registro *T[]){
	int i;
	for (i=0; i<TAM_TABLE; i++){
		printf("[%i] ", i);
		mostrar_lista(&T[i]);
	}	
}

int main(){

    //Questão A:
    /*
    * Assumindo para casos extremos, a escolha da chave idade é a melhor opção
    * pois em uma situação onde a idade dos registros vai de 1 .. 10.000 sem repetições
    * todos os registros seriam inseridos em indexes diferentes (dada uma função hash adequada)
    * logo, a busca seria O(1).
    */

    //Questão B
    /*
    * A escolha de sexo (assumindo que o valor de sexo é binário F ou M) seria horrível para o
    * programa, pois teriamos apenas 2 indexes para armazenar os registrados.
    * Em um caso onde metade dos registros são M e metade são F, cada index teria 5.000 listas
    * e a busca seria afetada.
    */

    //Questão C
    /*
    * Como foi dito, a escolha de idade em um caso extremo pode alcançar O(1) em sua busca.
    * Podemos fazer uma analise comparando Nome (usando a primeira letra do nome) e idade.
    * Assumindo que ao usar nome teriamos 26 indexes (26 letras), teriamos em média 385 registros
    * em um index em um caso especifico (10.000 registros / 26 indexes).
    * Assumindo agora que as idades podem variam entre 10 até 60 anos, temos 50 indexes, possibilitando
    * 200 registros por index em um caso especifico (10.000 registros / 50 indexes ).
    */

    //Funcoes de busca e remocao testadas e funcionais
    //Funcao de insercao com problemas

    Registro* tabela[TAM_TABLE];
    criar_tabela(tabela);

    for(int i = 0; i < 3; i++){

        mostrar_tabela(tabela);
        printf("\n\n");
    }

    Registro* temp = (Registro*) malloc(sizeof(Registro));
    temp->idade = 10;
    strcpy(temp->nome, "Maria" );
    
    if(busca(tabela, temp)) printf("O registro esta presente\n");
    else                    printf("Não tem registros\n");
    
    remover(tabela, temp);

    mostrar_tabela(tabela);

}

void criar_tabela( Registro *tabela[] ){
    for(int i = 0; i < TAM_TABLE; i++) tabela[i] = NULL;
}

int hash( int chave ){
    return chave % TAM_TABLE;
}

int inserir( Registro* tabela[], Registro* reg ){
    //insere os dados do registro e passa a idade como chave
	return inserir_inicio(&tabela[ hash( reg->idade ) ], reg);
}

int inserir_inicio(Registro **tabela, Registro* reg){
	reg->prox = *tabela;
	*tabela = reg;	
	return 1;	
}

int busca( Registro* tabela[], Registro* reg ){
    return buscar_lista(&tabela[hash(reg->idade)],reg);
}

int buscar_lista(Registro **C, Registro* reg){
	Registro *p;
	for (p=*C; p!=NULL; p=p->prox){
		if (p->nome == reg->nome)
			return 1;
	}
	return 0;
}

int remover( Registro* tabela[], Registro* reg ){
	return remover_por_valor(&tabela[hash(reg->idade)],reg);
}

int remover_por_valor(Registro **C, Registro* reg){
	if (*C == NULL)
		return 0;
    
	Registro *p, *q;
	for(q=NULL, p=*C; p!=NULL; p=p->prox){
		if (p->nome == reg->nome) break;
		q=p;
	}
	
	if (q == NULL) {
		*C = p->prox;
		free(p);
		return 1;
	}
    
	if (p == NULL) return 0;
    
	q->prox = p->prox;
	free(p);
	return 1;
}