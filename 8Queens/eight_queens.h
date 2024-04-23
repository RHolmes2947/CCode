#ifndef EIGHT_QUEENS_H
#define EIGHT_QUEENS_H

#include <stdbool.h>

#define N 8

void print_board(char board[N][N]);
bool is_safe(char board[N][N], int row, int col);
bool solve_queens(char board[N][N], int col);

#endif /* EIGHT_QUEENS_H */
