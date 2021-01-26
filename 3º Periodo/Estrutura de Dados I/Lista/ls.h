#ifndef _LS_H
#define _LS_H

#define MAX_TAM 10

    int list[MAX_TAM]; //Array list with size = 100. 
                       //It is possible to use dynamic allocation too, but I'm in a rush right now

#include<stdio.h>
#include<stdlib.h>

void startList(int* list);

int insertStart(int* list, int value);
int removeStart(int* list);

int insertEnd(int* list, int value);
int removeEnd(int* list);

int removeList(int* list);

void showList(int* list);

int hasValue(int* list, int value);

#endif