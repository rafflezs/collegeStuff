#include "pilha.h"

struct stack{
    int array[10];
    int pos;
};


int menu(){
	int opc;

	system("clear");

	printf("[0] - Sair\n");
	printf("[1] - Empilhar (POP)\n");
	printf("[2] - Desempilhar (POP)\n");
	printf("[3] - Retorna valor do topo (TOP)\n");
	printf("[4] - Retorna se a pilha está vazia (IsEmpty)\n");
	printf("[5] - Destruir pilha\n");
	printf("[6] - Mostra pilha\n");

	printf("Opção: ");
	scanf("%i", &opc);

	return opc;
}

Stack* createStack(){
	Stack* myStack = (Stack*) malloc(sizeof(Stack));
	myStack->pos = 0;
	return myStack;
}

int push(Stack* myStack, int val){
	myStack->array[myStack->pos] = val;
	myStack->pos++;
}

int pop(Stack* myStack){
	if(myStack == NULL){
		return 0;
	}
	
	myStack->pos--;

	return 1;
}

int top(Stack* myStack){
	if(myStack == NULL){
		return -1;
	}
	return myStack->array[myStack->pos-1];
}

int isEmpty(Stack* myStack){
	if(myStack == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

int removeStack(Stack* myStack){
	if(myStack == NULL){
		return 0;
	}
	
	for(int i = 0; i < myStack->pos; i++){
		myStack->array[i] = 0;
	}
	myStack->pos = 0;

	free(myStack);

	return 1;
}

void print(Stack* myStack){

	for(int i = 0; i < myStack->pos; i++){
		printf("%d ", myStack->array[i]);
	}
	printf("\n");
}