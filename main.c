#include <stdio.h>
#include <stdlib.h>
#include "array.util.h"

int main (){
    int tam = 5;
    int *array = NULL;
    array = allocateArray(array, tam);
    /*for(int i = 0; i < 10; i++){
        array[i] = i;
    }*/

    readArray(array, tam);
    //printf("teste\n");
    printArray(array, tam);
    shellSort(array, tam);
    printf("Vetor ordenado::\n");
    printArray(array, tam);
    destructArray(array);
    return 0;
}
