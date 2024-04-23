#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to sort the array
void sort_array(int** arr, int size) {
    int total = size * size; // Calculate the total number of elements in the 2D array

    // Perform bubble sort algorithm on the array
    for(int i = 0; i < total - 1; i++) {
        for(int j = 0; j < total - i - 1; j++) {
            int row1 = j / size; // Calculate the row index of the current element
            int col1 = j % size; // Calculate the column index of the current element
            int row2 = (j + 1) / size; // Calculate the row index of the next element
            int col2 = (j + 1) % size; // Calculate the column index of the next element

            // Compare the current element with the next element and swap them if necessary
            if(arr[row1][col1] > arr[row2][col2]) {
                int temp = arr[row1][col1];
                arr[row1][col1] = arr[row2][col2];
                arr[row2][col2] = temp;
            }
        }
    }
}