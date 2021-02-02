#include <stdio.h>

int main(){


    int array[18] = {50,18,49,58,20,1,3,2,5,55,10,9,606,900,805,201,21,102};
    int i,j;
    int aux, min;

    for (i = 0; i < 17; i++){

        min = i;

        for(j = i + 1; j < 18; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        if (array[i] != array[min]) {
            aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }

    for (i = 0; i < 18; i ++){
        printf("%d ", array[i]);
    }

}