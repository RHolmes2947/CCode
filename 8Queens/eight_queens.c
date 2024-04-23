#include "eight_queens.h"
#include <stdio.h>


/* Function to print the chess board */
void print_board(char board[N][N]) {
    int i, j;
    printf("+---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n+---+---+---+---+---+---+---+---+\n");
    }
}

/* Function to check if a Queen is safe to place at the given position */
bool is_safe(char board[N][N], int row, int col) {
    int i, j;
    /* Check if there's any Queen in the same row */
    for (i = 0; i < N; i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    /* Check if there's any Queen in the same column */
    for (i = 0; i < N; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    /* Check the diagonals */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 'Q' && (i + j == row + col || i - j == row - col)) {
                return false;
            }
        }
    }

    return true;
}

/* Recursive function to solve the Eight Queens Puzzle */
bool solve_queens(char board[N][N], int col) {
    int row;
    if (col == N) {
        return true;
    }

    for (row = 0; row < N; row++) {
        if (is_safe(board, row, col)) {
            board[row][col] = 'Q';
            if (solve_queens(board, col + 1)) {
                return true;
            }
            board[row][col] = ' '; /* Backtrack */
        }
    }

    return false;
}
