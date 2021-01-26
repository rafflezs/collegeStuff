#include "pilha.h"

struct stack{
    Stack* next;
	int val;
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
    Stack* myStack = (Stack*) malloc (sizeof(Stack));

    myStack = NULL;

    return myStack;
}

int push(Stack** myStack, int val){
	Stack* new = (Stack*) malloc (sizeof(Stack));
    new->val = val;

    new->next = (*myStack);
    (*myStack) = new;

    return 1;
}

int pop(Stack** myStack){
    if(*myStack == NULL){
        return 0;
    }

    (*myStack) = (*myStack)->next;

    return 1;
}

int top(Stack** myStack){
    if(*myStack == NULL){
        return 0;
    }

	return (*myStack)->val;
}

int isEmpty(Stack** myStack){
    if(*myStack == NULL){
        return 1;
    }

	return 0;
}

int removeStack(Stack** myStack){

	for(Stack* a = (*myStack); a->next != NULL; a = a->next){
		free(a);
	}

}

void print(Stack** myStack){

	for(Stack* a = (*myStack); a->next != NULL; a = a->next){
		printf("%d ", a->val);
	}
}