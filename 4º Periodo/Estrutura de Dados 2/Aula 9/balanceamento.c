#include "/home/rafflezs/Documentos/Faculdade/4º Periodo/Estrutura de Dados 2/Aula 6/arvore.c"

//Balanceamento Raiz-Filho : ++ = RSD -> (10)->5->2 <-> 2<-(5)->5

//Balanceamento Raiz-Filho : -- = RSE -> (10)->20->30 <-> 10<-(20)-> 30

//Balanceamento Raiz-Filho : +- = RDE -> (10)->15->12 <-> 
//                                RSD(15) e RSE(10) <-> 10<-(12)->15

//Balanceamento Raiz-Filho : -+ = RDD -> (10)->5->7 <-> 5<-(7)->10
//                                RSE(5) e RSD(7)

void rse(No** R){

    No* aux;

    aux = *R;
    *R = aux->dir;
    (*R)->esq = aux;
    aux->dir = NULL;

}

void rsd(No** R){

}

void rde(No** R){

}

void rdd(No** R){

}

void balanceamento(No** R){

    int tipo_bala;

	printf("[1] - RSE\n\n");
	printf("[2] - RSD\n\n");
	printf("[3] - RDE\n\n");
	printf("[4] - RDD\n\n");

    scanf("%i", &tipo_bala);

    switch (tipo_bala)
    {
    case 1:
        rse(R);
        break;
    case 2:
        rsd(R);
        break;
    case 3:
        rde(R);
        break;
    case 4:
        rdd(R);
        break;
    
    default:
        printf("Balanceamento Inválido\n\n");
        break;
    }

}

int main(){
	No *R = NULL;
	int opc, valor;
	No *aux;

	while(opc = menu()){
		switch(opc){
			case 1:
				printf("valor: ");
				scanf("%i", &valor);
				inserir(&R, valor);
				printf("%i inserido.\n", valor);
				break;
			case 2:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					pre_ordem(&R);
				break;
			case 3:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					em_ordem(&R);
				break;
			case 4:
				if (R==NULL)
					printf("árvore vazia\n");
				else
					pos_ordem(&R);
				break;
			case 5:
				printf("A quantidade de elementos é: %i\n", qtd_elementos(&R));
				break;
			case 6:
				aux = maior_elemento(&R);
				if (aux == NULL)
					printf("Arvore vazia.\n");
				else
					printf("O maior elemento é: %i\n", aux->dado);
				break;
			case 8:
				if (remover_maior_rec(&R))
					printf("Elemento removido.\n");
				else
					printf("Árvore vazia. Não é possível remover.\n");
				break;
			case 9:
				printf("valor: ");
				scanf("%i", &valor);

				if (remover_elemento_qualquer(&R, valor))
					printf("Elemento %i removido.\n", valor);
				else
					printf("Não é possível remover o elemento %i.\n", valor);
				break;
			case 10:
				if (R == NULL)
					printf("Árvore vazia.\n");
				else
					mostrar_folhas(&R);
				break;
            case 11:
                if(R == NULL)
                    printf("Arvore vazia\n");
                else
                    balanceamento(&R);
                break;
			default:
				printf("Opção inválida.\n");
		}
		getchar();
		getchar();
	}
}
