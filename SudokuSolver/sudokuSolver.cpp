#include <iostream>
#include <string>
#include "grid.hpp"

using namespace std;

bool solveSudoku(Grid sudokuGrid);
string checkHoles(int grid[9][9]);

/**
 * @brief Solves the Sudoku game using backtracking.
 *
 * In this main function, the Sudoku file is loaded and printed. After there
 * board has been solved, a congradulatory message is printed.
 */
int main(int argc, char ** argv) {
    Grid sudokuGrid;

    sudokuGrid.loadBoard("testFileHard.in");
    sudokuGrid.printGrid();

    if (solveSudoku(sudokuGrid)) {
        cout << "Sudoku solved!" << endl;
    }

    return 0;
}

/**
 * @brief Solves the Sudoku board
 *
 * Essentially, the algorithm goes through the elements in the array
 * and looks for empty spaces. Then it guesses a number that is not in the
 * same row, column, or 3x3 box. Using recursion, the algorithm then finds
 * the next empty hole and repeats. If there comes a point where the board
 * is impossible to solve, the algorithm backtracks and goes again. I chose
 * this algorithm because I utilized a similar algorithm in a CS 11 C Track lab.
 *
 * The worst case runtime for this algorithm is O(n^(n^2))
 *
 * @param sudokuGrid, an object of the Grid Class
 *
 * @return true/false, depending on whether the board is solved or not
 */
bool solveSudoku(Grid sudokuGrid) {
    int row, col;
    string hole = checkHoles(sudokuGrid.grid);
    if (hole == "") {
        return true;
    }
    row = hole[0] - '0';
    col = hole[1] - '0';
    row++;
    col++;

    for (int i = 1; i <= 9; i++) {
        if (sudokuGrid.checkValid(row, col, i)) {
            sudokuGrid.writeNum(row, col, i);
            if (solveSudoku(sudokuGrid)) {
                if (sudokuGrid.isComplete()) {
                    sudokuGrid.printGrid();
                }
                return true;
            }
            sudokuGrid.undoNum(row, col);
        }
    }
    return false;
}

/**
 * @brief Checks if the Sudoku board has empty spaces
 *
 * Goes through the array of integers and finds empty spaces. Then,
 * the row and column are casted into strings and concatenated because
 * I needed a way to return both row and column and not just one.
 *
 * @param grid, the 9x9 array
 *
 * @return a string which can either be two concatenated numbers
 * or an empty string
 */
string checkHoles(int grid[9][9]) {
    string a, b;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                a = to_string(i);
                b = to_string(j);
                return a + b;
            }
        }
    }
    return "";
}
