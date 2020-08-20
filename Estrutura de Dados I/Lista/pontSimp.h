#ifndef PONTSIMP_H
#define PONTSIMP_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

Lista* cria_lista();
Lista* inserir_inicio(Lista* myList, int value);
Lista* inserir_fim(Lista* myList, int value);
Lista* remover_fim(Lista* myList);
Lista* remover_inicio(Lista* myList);
int mostrar_lista(Lista* myList);
int buscar(Lista* myList, int value);
int start();
int menu();


#endif // PONTSIMP_H
