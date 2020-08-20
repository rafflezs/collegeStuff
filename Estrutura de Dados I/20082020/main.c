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
    
    
    

    return 0;
}
