#include "pontSimp.h"

struct lista{
    int value;
    struct lista *prox;
};


Lista* cria_lista(){
    
    Lista* myList = (Lista*) malloc (sizeof(Lista));

    myList = NULL;

    return myList;
}

Lista* inserir_inicio(Lista* myList, int value){
	Lista* new = (Lista*) malloc (sizeof(Lista));
    new->value = value;

    new->prox = myList;
    myList = new;

    return myList;
}

Lista* inserir_fim(Lista* myList, int value){

    if(myList == NULL){
        return myList;
    }

	Lista* new = (Lista*)malloc(sizeof(Lista));

    for(new = myList; new != NULL; new = new->prox);



    return myList;
}

Lista* remover_fim(Lista* myList){
    Lista* temp;
	Lista* new = (Lista*)malloc(sizeof(Lista));
    
    new = myList;
    temp = new;

    for(; temp != NULL; temp = temp->prox);

    free(temp);

    myList->prox = temp;

    return myList;
}

Lista* remover_inicio(Lista* myList){
    if(myList == NULL){
        return myList;
    }

    Lista* new = (Lista*) malloc (sizeof(Lista));
    new = myList;

    myList = myList->prox;
    free(new);

    return myList;
}

int mostrar_lista(Lista* myList){

    if(myList == NULL){
        return 0;
    }

    Lista* temp = (Lista*) malloc (sizeof(Lista));
    int cont = 0;

    for(temp = myList; temp != NULL; temp = temp->prox){
        printf("%d = [%d]\n", cont, temp->value);
        cont++;
    }

    return 1;
}

int buscar(Lista* myList, int value){

    if(myList == NULL){
        return 0;
    }

    Lista* temp = (Lista*) malloc (sizeof(Lista));

    for(temp = myList; temp != NULL; temp = temp->prox){
        if(temp->value == value){
            return 1;
        }
    }

    return 0;

}

int menu(){
	int opc;

	system("clear");

	printf("[0] - Sair\n");
	printf("[1] - Inserir no início\n");
	printf("[2] - Inserir no fim\n");
	printf("[3] - Remover no início\n");
	printf("[4] - Remover no fim\n");
	printf("[5] - Mostrar lista\n");
	printf("[6] - Buscar por value\n");

	printf("Opção: ");
	scanf("%i", &opc);

	return opc;
}
