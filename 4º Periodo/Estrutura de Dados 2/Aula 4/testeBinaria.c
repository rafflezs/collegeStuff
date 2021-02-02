#include "testeBinaria.h"

struct arvBinaria
{
    int valor;
    No* subDir;
    No* subEsq;
};

struct no
{
    No* anterior; //Não tenho certeza se isso é aplicado
    ArvBinaria* subArvore;
};

ArvBinaria* alocaArvore(){

    ArvBinaria* temp = (ArvBinaria*) malloc( sizeof( ArvBinaria ));
    return temp;

}

int inserir(ArvBinaria* arv, int valor){

    if(arv->subDir == NULL && arv->subEsq == NULL){
        arv->valor = valor;
        return 1;
    }

    if(valor <= arv->valor){
        inserir(arv->subEsq->subArvore, valor);
        return 1;
    }else if(valor > arv->valor){
        inserir(arv->subDir->subArvore, valor);
        return 1;
    }

    return 0;

}

int main(){

    ArvBinaria* arv = alocaArvore();

    inserir(arv, 10);
    inserir(arv, 1);
    inserir(arv, 20);


    printf("%i\n", arv->valor);
    printf("%i\n", arv->subDir->subArvore->valor);
    printf("%i\n", arv->subEsq->subArvore->valor);

    return 0;
}