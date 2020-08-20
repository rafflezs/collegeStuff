#include "pilha.h"

int main(){

	Stack* myStack = createStack();
	int opcao, valor;
	
	while(opcao = menu()){
		switch(opcao){

			case 1:
				printf("valor: ");
				scanf("%i", &valor);
				if(push(myStack, valor)){
					printf("Operação realizada com sucesso!\n");
				}else{
					printf("Operação mal-sucedida");
				}
			break;

			case 2:
				if(pop(myStack)){
					printf("Operação realizada com sucesso!\n");
				}else{
					printf("Operação mal-sucedida");
				}
			break;

			case 3:
				printf("O valor do topo da lista é %d\n", top(myStack));
			break;

			case 4:
				if(!isEmpty(myStack)){
					printf("A lista NÃO está vazia\n");
				}else{
					printf("Lista vazia\n");
				}
			break;

			case 5:
				if(removeStack(myStack)){
					printf("Lista destruida\n");
				}else{
					printf("Deu ruim pai\n");
				}
			break;
			case 6:{
				print(myStack);
			}break;
			default:
				printf("opção inválida.\n");
		}
		getchar();
		getchar();
	}


	
}