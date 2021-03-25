#include <stdio.h>
#include <stdlib.h>

int solidez(int [], int, int);

int main(){


    int A[] = {20, -30, 15,-10, 30, -20, -30, 30};
    static int tam = sizeof(A)/sizeof(int);

    printf("Solidez de A = %i\n", solidez(A,0,tam-1));

}

int solidez(int A[], int p, int r){

    int x = A[r];
    for(int q = r; q >= p; q--){
        int s = 0;
        for(int j = q+1; j <= r; j++){
            s = s + A[j];
            if(s > x){
                x = s;
            }
        }
    }

    return x;

}
