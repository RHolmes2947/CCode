#include <stdio.h>
#include "eight_queens.h"


int main() {
    char chess_board[N][N];

    /* Initialize the board with empty spaces */
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            chess_board[i][j] = ' ';
        }
    }

    if (solve_queens(chess_board, 0)) {
        printf("Solution found:\n");
        print_board(chess_board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
