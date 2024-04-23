#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int rows, cols;

    // Get the dimensions of the array from the user
    // if the dementions are not equal or if the values are
    // 0 or below an error message will be printed
    do {
        printf("Enter the row size of the 2D array:\n");
        scanf("%d", &rows);

        printf("Enter the column size of the 2D array:\n");
        scanf("%d", &cols);

        if(rows != cols) {
            printf("Array must be a square matrix. Please try again.\n");
        }

        if(rows <= 0 || cols <= 0) {
            printf("Array dimensions must be positive and not zero. Please try again.\n");
        }
    } while(rows != cols || rows <= 0 || cols <= 0);

    int size = rows;

    // Allocate memory for the array
    int** arr = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
        arr[i] = (int *)malloc(size * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter %d numbers (space separated):\n", size*size);
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            scanf("%d", &arr[i][j]);

    // Perform operations on the array based on user's choice
    while(1) {
        printf("Choose an operation:\n(0) : exit\n(1) : reverse array\n(2) : randomize array\n(3) : sort array\n(4) : print array\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 0:
                return 0;
            case 1:
                reverse_array(arr, size);
                break;
            case 2:
                randomize_array(arr, size);
                break;
            case 3:
                sort_array(arr, size);
                break;
            case 4:
                print_array(arr, size);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }
    }
    return 0;
}
