#include "pilha.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    Pilha* pilha1 = criar_pilha();

    //Checa se a pilha foi criada corretamente
    if(pilha1 == NULL)
    {
        printf("Memoria insuficiente. Operacao mal-sucedida.\n");
    }else
    {
        printf("Operacao valida.\n");
    }
    
    empilhar(pilha1, 10);
    //mostrar_pilha(pilha1);
    empilhar(pilha1, 20);
    //mostrar_pilha(pilha1);
    empilhar(pilha1, 30);
    //mostrar_pilha(pilha1);

    printf("%i\n" ,topo(pilha1));

    remover_todos(pilha1);

    printf("%i\n" ,topo(pilha1));

    return 0;
}
