#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand( (unsigned)time(NULL) );

    int n = 100;
    printf("%i", rand() % 100);
    for(int i = 1; i < n; i++){
        int a = rand() % 200;
        printf(", %i", a - 100);
    }

}