#include <stdio.h>
#include <stdlib.h>

int solidez(int [], int, int);
int calc(int A[], int p, int q, int r, int* y_1, int* y_2);
int max(int,int,int);

int main(){

    static int tam = 10000;

    static int A[10000] ={};

    printf("Solidez de A = %i\n", solidez(A,0,tam-1));

}

int solidez(int A[], int p, int r){

    if(r == p){
        return A[p];
    }

    int q = (p + r)/2;
    int x_1 = solidez(A, p, q);
    int x_2 = solidez(A, q+1, r);
    int y_1, y_2;
    calc(A,p,q,r,&y_1,&y_2);
    return max(x_1, y_1+y_2, x_2);

}

int calc(int A[], int p, int q, int r, int* y_1, int* y_2){
    int s;
    *y_1 = s = A[q];
    for(int i = q-1; i >= p; i--){
        s = s + A[i];
        if(s > *y_1)  *y_1 = s;
    }

    *y_2 = s = A[q+1];
    for(int j = q + 2; j <= r; j++){
        s = s + A[j];
        if(s > *y_2) *y_2 = s;
    }
}

int max(int A, int B, int C){
  if (A >= B && A >= C) return A; 
  if (B >= A && B >= C) return B; 
  if (C >= A && C >= B) return C;
}
