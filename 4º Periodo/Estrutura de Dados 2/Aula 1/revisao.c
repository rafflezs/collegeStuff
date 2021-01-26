#include <stdio.h>

void quest3();
void quest4();
unsigned long long int fibonacci(int termo);
unsigned long long int fatorial(int valor);
void recursaoRecursaoRecursaoRecursaoRecursao(int n);

int main(){

    int n;
    scanf("%i", &n);
    recursaoRecursaoRecursaoRecursaoRecursao(n);

    return 0;

}

void quest3(){

    int a = 3, b = 4, *p1, *p2, **p_duplo;

    //A p_duplo recebe endereco de p1
    p_duplo = &p1;
    printf("p_duplo = %p", &p1);

    //B p1 recebe endereco de p2
    p1 = &a;
    printf("p1 = %p\n", &a);

    //C p2 recebe endereco de b
    p2 = &b;
    printf("p2 = %p\n", &b);

    //D **p_duplo = 12
    **p_duplo = *p1 * *p2;
    printf("**p_duplo = %i\n", (*p1 * *p2));

    //E *p_duplo recebe valor de p2 == 4 
    *p_duplo = p2;
    printf("*p_duplo = %p\n", p2);

    //F*p_duplo = 16    -> 4 + 12
    **p_duplo = *p1 + **p_duplo;
    printf("**p_duplo = %i\n", (*p1 + **p_duplo));

    printf("a = %i\nb = %i\n", a, b);

}

void quest4(){

    int a = 6, b = 7, *ptr, **ptr_duplo;

    //duplo recebe o endereço de prt
    ptr_duplo = &ptr;

    //ptr recebe o endereço de a
    ptr = &a;

    //**duplo = b(7) + *ptr(6) == 13, logo a = 13
    **ptr_duplo = b + *ptr;

    //ptr recebe o endereço de b
    ptr = &b;

    //**ptr_duplo (b) = a(13) + *ptr(b(7)) * **ptr+duplo (b(7)) == **ptr_duplo = 63 ou b =63
    **ptr_duplo = a + *ptr * **ptr_duplo;

    printf("a = %i \t b = %i\n", a, b);

}

unsigned long long int fibonacci(int termo){

    if(termo <= 2){
        return 1;
    }else{
        return fibonacci(termo - 2) + fibonacci(termo - 1);
    }
    
}

unsigned long long int fatorial(int valor){

    if(valor <= 1){
        return 1;
    }else{
        return valor * fatorial(valor-1);
    }

}

void recursaoRecursaoRecursaoRecursaoRecursao(int n){

    if(n == 0){
        printf("%i\n", n);
    }else{
        //printf("%i\n",n); //Decrescente
        recursaoRecursaoRecursaoRecursaoRecursao(n-1);
        printf("%i\n",n); //Crescente
    }

}