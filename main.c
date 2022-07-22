#include <stdio.h>
#include <stdlib.h>
#include "array.util.h"

int main (){
    int tam = 0;
    int *array = 0;
    array = allocateArray(array, tam);
    /*for(int i = 0; i < 10; i++){
        array[i] = i;
    }*/

    scanf("%d", &tam);
    //readArray(array, tam);
    //printf("teste\n");
    for(int i = 0; i < tam; i++){
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < tam; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    //printArray(array, tam);
    shellSort(array, tam);
    printf("Vetor ordenado::\n");
    printArray(array, tam);
    destructArray(array);
    return 0;
}
