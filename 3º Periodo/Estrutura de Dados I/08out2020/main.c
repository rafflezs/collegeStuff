#include "filaDin.h"

int main(){
    
    Desc* d = (Desc*) malloc(sizeof(Desc));
    
    enfileirar(d, 10);
    enfileirar(d, 20);
    enfileirar(d, 30);
    enfileirar(d, 40);

    mostrar(d);

    primeiro(d) != NULL ? printf("%d", *primeiro(d)) : printf("Lista Vazia");

    desenfileirar(d);
    desenfileirar(d);
    desenfileirar(d);
    desenfileirar(d);

    mostrar(d);
    

    return 0;
}