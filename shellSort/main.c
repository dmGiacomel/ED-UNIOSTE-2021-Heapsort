#include <stdio.h>
#include <stdlib.h>
#include "array.util.h"

int main (){
    int tam = 0;
    int *array = 0;

    scanf("%d", &tam);
    array = allocateArray(array, tam);

    readArray(array, tam);

    printf("Vetor desordenado: \n");
    printArray(array, tam);

    shellSort(array, tam);

    printf("Vetor ordenado::\n");
    printArray(array, tam);
    
    destructArray(array);
    return 0;
}
