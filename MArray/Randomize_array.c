#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomize the elements of the array
void randomize_array(int** arr, int size) {
    srand(time(0));
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            // Generate a random number between 1 and 99 and assigns it to the element
            arr[i][j] = (rand() % 99) + 1;
}