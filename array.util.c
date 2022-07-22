#include "array.util.h"
#include <stdio.h>
#include <stdlib.h>

int* allocateArray(int *array, int size){
    array = (int*)malloc(size * sizeof(int));
    return array;
}

void destructArray(int *array){
    free(array);
}

void printArray(int *array, int size){
    if(size == 0){
        printf("[]");
    }else{
        printf("[");
        for (int i = 0; i < size - 1; i++){
            printf("%d, ", array[i]);
        }
        printf("%d", array[size - 1]);
        printf("]");
    }
    printf("\n");
}

void shellSort(int *a, int n)
{
    int i, j;
    int h = 1;
    int x;

    // sequencia para h, sendo n > 1
    while(h < n){
        h = (h * 3) + 1;
        printf("h = %d\n", h);
    }

    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            x = a[i];
            j = i;
            while (a[j - h] > x)
            {
                a[j] = a[j - h];
                j -= h;
                if (j < h)
                    goto L999;
            }
            L999: a[j] = x;
        }
    } while (h != 1);  
}

void readArray(int *array, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
        printf("leu o elemento\n");
    }
}