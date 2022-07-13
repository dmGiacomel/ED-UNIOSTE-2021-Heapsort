#include <stdio.h>
#include <stdlib.h>
#include "array.util.h"

int main (){
    int *array;
    array = allocateArray(array, 10);
    for(int i = 0; i < 10; i++){
        array[i] = i;
    }
    printf("teste\n");
    printArray(array, 10);
    destructArray(array);
    return 0;
}
