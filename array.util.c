#include "array.util.h"
#include <stdio.h>
#include <stdlib.h>

int* allocateArray(int *array, long long int size){
    array = (int*)malloc(size * sizeof(int));
    return array;
}

void destructArray(int *array){
    free(array);
}

void printArray(int *array, long long int size){
    if(size == 0){
        printf("[]");
    }else{
        printf("[");
        for (long long int i = 0; i < size - 1; i++){
            printf("%d, ", array[i]);
        }
        printf("%d", array[size - 1]);
        printf("]");
    }
    printf("\n");
}
