#include <stdio.h>

int main(){

    int i = 0, cont = 0;
    
    for (i = 10; i <= 99; i++){
        if ((1 % 1 == 0) || (i % 2 == 0) || (i % 3 == 0)){
            cont++;
        }
    }

    printf("%d \n", cont);

    return 0;
}