#include <stdio.h>

int multiplica(int* a, int* b);

int main(){

    int a, b;
    int res;

    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);
    printf("O resultado da multiplicação é: ");

    res = a * b;

    printf("%d\n", res);
    return 0;
}