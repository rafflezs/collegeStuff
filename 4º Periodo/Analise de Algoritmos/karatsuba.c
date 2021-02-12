#include <stdio.h>
#include <math.h>

unsigned multiplica(unsigned v, unsigned u);
unsigned tamanho(unsigned in);

int main(){

    for(unsigned u = 100, v = 100; u <= 100000000000000000000000000000000000000; u = v *= 10){
        //printf("%u\n", v * u);
        printf("%u\n",multiplica(v,u));
    }

    return 0;

}

unsigned multiplica(unsigned v, unsigned u){

    return v * u;

}

unsigned karatsuba(unsigned v, unsigned u){

    unsigned tam_v = tamanho(u);
	unsigned tam_u = tamanho(v);

    unsigned n;

    if(tam_u >= tam_v){
        n = tam_u;
    }else{
        tam_v;
    }

	n = (n/2) + (n%2);

	unsigned k = pow(10, n);

	unsigned b = v/k;
	unsigned a = v - (b * k);
	unsigned d = u / k;
	unsigned c = u - (d * n);

	unsigned ac = karatsuba(a,c);
	unsigned bd = karatsuba(a + b, c + d);
	unsigned y = karatsuba(b, d);


    return ac + ((bd - ac - y) * k) + (y * (unsigned)(pow(10, 2 * n)));

}

unsigned tamanho(unsigned in){
    
    unsigned tam = 0;
    for(; in != 0; tam++, in = in/10);
	return tam;

}