#include "llse.h"

int main(){

    List* myList = NULL;

    myList = startList();

    int op;

    do{
        op = menu();

        switch (op){
        case 1:{
            int value;
            printf("Insert a value to the list: ");
            scanf("%d", &value);
            if(insertStart(myList, value)){
                printf("Succeful operation\n");
            }else{
                printf("Operation didn't work\n");
            }
        }break;
        case 2:{
            int value;
            printf("Insert a value to the list: ");
            scanf("%d", &value);
            if(insertEnd(myList, value)){
                printf("Succeful operation\n");
            }else{
                printf("Operation didn't work\n");
            }
        }break;
        case 3:{
            if(removeStart(myList)){
                printf("Succeful operation\n");
            }else{
                printf("Operation didn't work. List is already empty!\n");
            }
        }break;
        case 4:{
            if(removeEnd(myList->header)){
                printf("Succeful operation\n");
            }else{
                printf("Operation didn't work. List is already empty!\n");
            }
        }break;
        case 5:{
            if(removeList(myList)){
                printf("Succeful operation\n");
            }else{
                printf("Operation didn't work. List is already empty!\n");
            }        }break;
        case 6:{
            showList(myList);
        }break;
        case 7:{
            int value;
            printf("Insert a value to search: ");
            scanf("%d", &value);
            if(hasValue(myList, value)){
                printf("Value found\n");
            }else{
                printf("Value not found!\n");
            }
        }break;
        case 0:{
            printf("Program is now finishing\n");
        }break;
        
        default:
            printf("Invalid input");
            break;
        }

    } while (op != 0);
    
    

    return 0;
}