#include <stdio.h>

int soma(int n);
int pot(int exp, int n);
int fat(int n);
int primo(int n);
int div(int n, int i);
float serie(int n);

int main(){

    for(int n = 1; n < 10; n++){
        printf("%f\n", serie(n));
    } 

    return 0;
}

int soma(int n){

    if(n == 0)
        return 0;
    
    return n = n + soma(n-1);
}

int pot(int exp, int n){

    if(exp == 0){
        return 1;
    }

    return n * pot(exp-1, n);

}

int fat(int n){

    if(n == 0){
        return 1;
    }

    return n * fat(n-1);

}

int primo(int n){

    if(n <= 1){
        return 0;
    }

    return div(n, n-1);

}

int div(int n, int i){

    if(i <= 2){
        return 1;
    }

    if(n % i == 0){
        return 0;
    }

    return div(n, i-1);

}

float serie(int n){

    if(n == 1){
        return 1.0;
    }

    return ((1.0/n) + serie(n-1));

}