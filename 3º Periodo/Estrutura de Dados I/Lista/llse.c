#include "llse.h"

//Declaration of each list node, used to store data-bits of the said list
struct node{
    
    int value; //Could be any type of value, but the exercise implies the use of Integer data
    struct node* next;

};

struct list{
    Node* header; //First node of the list is declared here
};

List* startList(){

    List* newList;
    newList = (List*) malloc(sizeof(List));

    newList->header = NULL;

    return newList;

}

int insertStart(List* myList, int value){

    if(myList == NULL){
        return 0;
    }

    Node* newHeader;
    newHeader = (Node*) malloc(sizeof(Node));
    if(newHeader == NULL){
        return 0;
    }

    newHeader->value = value;
    newHeader->next = NULL;

    if(myList->header == NULL){
        myList->header = newHeader;
        return 1;
    }else{
        newHeader->next = myList->header;
        myList->header = newHeader;
        return 1;
    }
}

int removeStart(List* myList){

    if(myList->header == NULL){
        return 0;
    }

    Node* temp = myList->header->next;
    free(myList->header);
    myList->header = temp;

    return 1;

}

int insertEnd(List* myList, int value){

    if(myList == NULL){
        return 0;
    }

    Node* newHeader;
    newHeader = (Node*) malloc(sizeof(Node));
    if(newHeader == NULL){
        return 0;
    }

    newHeader->value = value;
    newHeader->next = NULL;

    if(myList->header == NULL){
        myList->header = newHeader;
        return 1;
    }else{
        Node* iterator;
        for(iterator = myList->header; iterator->next != NULL; iterator = iterator->next);
        iterator->next = newHeader;
        myList->header = iterator;
        return 1;
    }
}

int removeEnd(Node** listHeader){

    if(listHeader == NULL){
        return 0;
    }

    Node* temp, *ite;

    temp = NULL;

    for(ite = *listHeader; ite->next != NULL; ite = ite->next){
        temp = ite;
    }
    free(ite);

    if(temp == NULL){
        *listHeader = NULL;
    }else{
        temp->next = NULL;
    }

    return 1;

}

int removeList(List* myList){

    if(myList == NULL){
        return 0;
    }

    myList->header = NULL;
    
    return 1;

}

void showList(List* myList){

    if(myList->header == NULL){
        printf("Empty list\n");
    }else{
        int i = 0;
        Node* iterator;
        for(iterator = myList->header; iterator != NULL; iterator = iterator->next){
            printf("[%d] = %d || ", i, iterator->value);
            i++;
        }
        printf("\n");
    }

}

int hasValue(List* myList, int value){
    
    if(myList->header == NULL){
        printf("Empty list\n");
        return 0;
    }else{
        Node* iterator;
        for(iterator = myList->header; iterator != NULL; iterator = iterator->next){
            if(iterator->value == value){
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

int menu(){

    int op;

    printf("Enter an input corresponding to the desired operation:\n");
    printf("1 - Insert Start\n");
    printf("2 - Insert Last\n");
    printf("3 - Remove Start\n");
    printf("4 - Remove Last\n");
    printf("5 - Delete list\n");
    printf("6 - Print list\n");
    printf("7 - Search for specific value\n");
    printf("0 - To quit\n");
    printf("\nYour input: ");
    scanf("%d",&op);
    return op;
}

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
            if(removeEnd(&myList->header)){
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