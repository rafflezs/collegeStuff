#include <stdio.h>

int soma_par(int* vet, int tam){
    
    if(tam == 1){
        if(vet[tam-1] % 2 == 0){
            return vet[tam-1];
        }else{
            return 0;
        }
    }

    if(vet[tam-1] % 2 == 0){
        return vet[tam-1] + soma_par(vet, tam-1);
    }else{
        return 0 + soma_par(vet, tam-1);
    }

}

int soma_vetor(int* vet, int tam){
    if(tam == 1)
           return *vet;
     
    return vet[tam-1] + soma_vetor(vet, tam-1) ;    
}

int maior(int* vet, int tam){
    int aux;

    if(tam == 1){
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

    if(val == 0)
        return 0;

    int aux = val % 10;
    if(x == aux){
        return seq(val/10, x) + 1;
    }

    return seq(val/10,x);

}

int mdc(int a, int b){

    if(b == 0)
        return a;
    
    return mdc(b, a % b);

}

void print_matriz(int mat[3][3], int lin, int col){
    
    printf("%i\n", mat[col-1][lin-1]);
    if(lin == 1){
        if(col == 1){
            return;
        }
    }
    
    if(col == 1){
        col = 3;
        return print_matriz(mat, lin-1, col);
    }
    return print_matriz(mat,lin,col-1);
}

void scan_matriz(int mat[3][3], int lin, int col){
    
    scanf("%i\n", &mat[col-1][lin-1]);
    if(lin == 1){
        if(col == 1){
            return;
        }
    }
    
    if(col == 1){
        col = 3;
        return scan_matriz(mat, lin-1, col);
    }
    return scan_matriz(mat,lin,col-1);
}

int soma_matriz(int mat[3][3], int lin, int col){
    
    if(lin == 1 && col == 1){
        return mat[0][0];
    }
    
    if(col == 1){
        return mat[lin-1][col-1] + soma_matriz(mat, lin-1, 3);
    }
    return mat[lin-1][col-1] + soma_matriz(mat,lin,col-1);
}

void troca_index(int* vet, int id1, int id2){

    int aux = vet[id1];
    vet[id1] = vet[id2];
    vet[id2] = aux;
    
    return;
}

int inverte_vetor(int* vet, int pos_inicial ,int tam){

    if(pos_inicial < tam-1){
        troca_index(vet,pos_inicial,tam-1);
        return inverte_vetor(vet,pos_inicial+1,tam-1);
    }
}

void print_vetor(int vet[], int tam){
    if(tam <= 1){
           printf(" %i ", vet[0]);
           return;
    }

    print_vetor(vet, tam-1);
    printf("| %i ", vet[tam-1]);
}


int main(){

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    inverte_vetor(arr,0,10);

    printf("\n\n");

    print_vetor(arr,10);

    return 0;
}