#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to print the elements of the array
void print_array(int** arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

