/*
Sudoku Solver
V1.0
*/
#include <stdio.h>
#define BOARD_SIZE 9

void display_matrix(int matrix_width, int matrix_height, int matrix[matrix_width][matrix_height]) {
    for (int row = 0; row < matrix_height; row++) {
        for (int column = 0; column < matrix_width; column++) {
            printf(" %d ", matrix[row][column]);
        }
        printf("\n");
    }
}

int is_valid(int number, int row, int column, int board_width, int board_height, int board[board_width][board_height]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == number) return 0; // Check if number is valid in row
        if (board[i][column] == number) return 0; // Check if number is valid in column
    }

    // Calulate the position of the top left corner of the mini-box encompassing current number
    int topr = row - row % 3;
    int topc = column - column % 3;

    // Check if number is valid in mini-box
    for (int i = topr; i < topr + 3; i++) {
        for (int x = topc; x < topc + 3; x++) {
            if (board[i][x] == number) return 0;
        }
    }

    return 1;
}

// Recursive solving function
int su_eval(int board_width, int board_height, int board[board_width][board_height]) {
    // Iterate over board
    for (int row = 0; row < board_width; row++) {
        for (int column = 0; column < board_height; column++) {
            // If value is empty
            if (board[row][column] == 0) {
                // Try each number from 1-9
                for (int number = 1; number <= BOARD_SIZE; number++) {
                    if (is_valid(number, row, column, BOARD_SIZE, BOARD_SIZE, board)) {
                        board[row][column] = number;

                        // If number is valid and doesn't interrupt others, return true
                        if (su_eval(BOARD_SIZE, BOARD_SIZE, board)) {
                            return 1;
                        }
                        // Otherwise, empty the block and re-loop
                        else {
                            board[row][column] = 0;
                        }
                    } 
                }
            return 0;
            }
        }
    }
    return 1;
}

int main(){
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    }; // 9x9 board expressed through matrix

    // Initializing values in board
    printf("Please input the starting values of the Sudoku challenge\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int column = 0; column < BOARD_SIZE; column++) {
            int chosen = 0;

            printf("For row: %d, column %d\n", row + 1, column + 1);
            scanf("%d", &chosen);
            board[row][column] = chosen;
            display_matrix(BOARD_SIZE, BOARD_SIZE, board);
        }
    }

    // Solve challenge
    int solved = su_eval(BOARD_SIZE, BOARD_SIZE, board);
    if (solved) {
        printf("Solved: \n");
        display_matrix(BOARD_SIZE, BOARD_SIZE, board);
    } else {
        printf("Unsolveable.");
    }

    return 1;
}