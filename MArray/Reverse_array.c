#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reverse_array(int** arr, int size) {
    int total = size * size; // Calculate the total number of elements in the 2D array

    // Reverse the elements of the array using a two-pointer approach
    for(int i = 0; i < total / 2; i++) {
        int row1 = i / size; // Calculate the row index of the current element
        int col1 = i % size; // Calculate the column index of the current element
        int row2 = (total - i - 1) / size; // Calculate the row index of the corresponding element from the end
        int col2 = (total - i - 1) % size; // Calculate the column index of the corresponding element from the end

        // Swap the current element with the corresponding element from the end
        int temp = arr[row1][col1];
        arr[row1][col1] = arr[row2][col2];
        arr[row2][col2] = temp;
    }
}