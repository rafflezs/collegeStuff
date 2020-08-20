#include "ls.h"

void startList(int* list){

    for(int i = 0; i < MAX_TAM; i++){
        list[i] = 0;
    }

}

int insertStart(int* list, int value){

    if(list[0] == 0){
        list[0] = value;
        return 1;
    }

    for(int i = 1; i < MAX_TAM; i++){
        list[i] = list[i-1]; 
    }
    list[0] = value;

    return 0;
}

int removeStart(int* list){

    if(list[0] == 0){
        return 0;
    }

    for(int i = 0; i < MAX_TAM - 1; i++){
        list[i] = list[i+1]; 
    }
    
    return 1;
}

int insertEnd(int* list, int value){

    if(list[0] == 0){
        list[0] = value;
        return 1;
    }

    for(int i = 0; i < MAX_TAM; i++){
        if(list[i] == 0){
            list[i] = value;
            return 1;
        } 
    }
}

int removeEnd(int* list){
    
    if(list[0] == 0){
        return 0;
    }

    for(int i = 0; i < MAX_TAM; i++){
        if(i == MAX_TAM - 1){
            list[MAX_TAM - 1] = 0; 
        }
        if(list[i] == 0){
            list[i] = 0;
            return 1;
    }
    
}

int removeList(int* list){

    if(list[0] == 0){
        return 0;
    }

    for(int i = 0; i < MAX_TAM; i++){
        list[i] = 0;
    }

}

void showList(int* list){

    if(list[0] == 0){
        return 0;
    }

    for(int i = 0; i < MAX_TAM - 1; i++){
        if(list[i] != 0){
            printf(" | %d |", list[i]);
        }
    }
    printf("\n");
}

int hasValue(int* list, int value){
    
    if(list[0] == 0){
        return 0;
    }

    for(int i = 0; i < MAX_TAM - 1; i++){
        if(list[i] == value){
            return 1;
        }
    }
    return 0;
}