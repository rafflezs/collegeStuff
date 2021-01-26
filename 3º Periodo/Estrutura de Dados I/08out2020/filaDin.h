#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no* prox;
} No;

typedef struct desc{
    No* inicio;
    No* fim;
} Desc;

void mostrar(Desc* d);
int enfileirar(Desc* D, int val);
int desenfileirar();
int* primeiro(Desc* d);