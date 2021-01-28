#include <stdio.h>

int soma_par(int* vet, int tam){
    
    if(tam == 0){
        if(vet[tam] % 2 == 0){
            return vet[tam];
        }else{
            return 0;
        }
    }

    if(vet[tam] % 2 == 0){
        return vet[tam] + soma_par(vet, tam-1);
    }else{
        return 0 + soma_par(vet, tam-1);
    }

}

int soma_vetor(int* vet, int tam){
    if(tam == 0)
           return *vet;
     
    return vet[tam] + soma_vetor(vet, tam-1) ;    
}

int maior(int* vet, int tam){
    int aux;

    if(tam == 0){
        aux = vet[0];
    }else{
        aux = maior(vet, tam-1);
        if(aux < vet[tam-1]){
            aux = vet[tam-1];
        }
    }
    
    return aux;
}

int seq(int val, int x){

    if(val == 0){
        if(x == val){
            return 1;
        }else{
            return 0;
        }
    }

    int aux = val % 10;
    if(x == aux){
        return seq(val/10, x) + 1;
    }

    return 0;

}

int mdc(int a, int b){

    if(b == 0)
        return a;
    
    return mdc(b, a % b);

}

void print_matriz(int mat[3][3], int lin, int col){
    
    printf("%i\n", mat[0][col]);
    
    if(lin == 0){
        if(col == 0)
            print_matriz(mat, lin, col);
        else
            print_matriz(mat, lin, col-1);
    }

    if(col == 0){
        print_matriz(mat, lin-1, col);
    }

    print_matriz(mat, lin, col-1);
    
}

int main(){

    int vet[3][3] = {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        };

    print_matriz(vet, 2, 2);

    return 0;
}