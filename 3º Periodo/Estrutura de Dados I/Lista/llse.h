#ifndef _LLSE_H
#define _LLSE_H

//Include section for important stuff
#include<stdio.h>
#include<stdlib.h>

//ADT declaration > Simple Linked List using dynamic allocation
typedef struct list List;
typedef struct node Node;

List* startList();

int insertStart(List* myList, int value);
int removeStart(List* myList);

int insertEnd(List* myList, int value);
int removeEnd(Node** listHeader);

int removeList(List* myList);

void showList(List* myList);

int hasValue(List* myList, int value);

#endif