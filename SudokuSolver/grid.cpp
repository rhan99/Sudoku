#include <fstream>
#include <iostream>
#include "grid.hpp"

using namespace std;

/**
 * @brief Loads the Sudoku board
 *
 * Takes the file and inputs the numbers into the 2-D array. If there
 * is no number, input a 0. Also, copy this initial grid into another grid
 * which will be used in the future to check if an undo move is acted upon
 * a number loaded from the original file.
 *
 * @param filename, the name of the file as a string
 *
 * @return none
 */
void Grid::loadBoard(string filename) {
    string line;
    int i = 0;

    ifstream file(filename);
    while (getline(file, line)) {
        for (int j = 0; j < 9; j++) {
            if (line[j] == ' ') {
                grid[i][j] = 0;
            }
            else {
                grid[i][j] = line[j] - '0'; // convert character to integer
            }
        }
        i++;
    }
    file.close();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            gridOriginal[i][j] = grid[i][j]; // copy grid into gridOriginal
        }
    }
}

/**
 * @brief Checks if the Sudoku board is complete
 *
 * Goes through the array of integers and makes sure there is a non-zero
 * number in each spot.
 *
 * @param none
 *
 * @return true/false, depending on whether the board is full or not
 */
bool Grid::isComplete() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Checks the validity of a move
 *
 * Checks to see if the user move is valid by seeing if that digit
 * exists elsewhere in the row, column, or 3x3 box
 *
 * @param x, the row
 * @param y, the column
 * @param val, the value to be inserted at the specified row and column
 *
 * @return true/false, depending on whether the move is valid or not
 */
bool Grid::checkValid(int x, int y, int val) {
    int row = x - 1;
    int col = y - 1;
    int digit = val;
    int rowSection = 0, colSection = 0;

    if (row < 0 || row > 8 || col < 0 || col > 8 || digit < 1 || digit > 9) {
        return false;
    }

    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == digit) {
            return false;
        }
        if (grid[i][col] == digit) {
            return false;
        }
    }

    if (row == 0 || row == 1 || row == 2) {
        rowSection = 0;
    }
    else if (row == 3 || row == 4 || row == 5) {
        rowSection = 3;
    }
    else {
        rowSection = 6;
    }

    if (col == 0 || col == 1 || col == 2) {
        colSection = 0;
    }
    else if (col == 3 || col == 4 || col == 5) {
        colSection = 3;
    }
    else {
        colSection = 6;
    }

    // Check to see if number exists in the 3x3 box
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[rowSection][colSection] == digit) {
                return false;
            }
            colSection++;
        }
        colSection -= 3;
        rowSection++;
    }
    return true;
}

/**
 * @brief Makes the move on the Sudoku board
 *
 * If a move is valid, makes the move on the board. Else, prints an error.
 *
 * @param x, the row
 * @param y, the column
 * @param val, the value to be inserted at the specified row and column
 *
 * @return none
 */
void Grid::writeNum(int x, int y, int val) {
    int row = x - 1;
    int col = y - 1;
    int digit = val;

    if (checkValid(x, y, val) == true) {
        grid[row][col] = digit;
    }
}

/**
 * @brief Undo a move
 *
 * Checks to see if a move can be undone. If so, undo the move. If not,
 * print an error message.
 *
 * @param x, the row
 * @param y, the column
 *
 * @return none
 */
void Grid::undoNum(int x, int y) {
    if (gridOriginal[x - 1][y - 1] == 0) {
        grid[x - 1][y - 1] = 0;
    }
}

/**
 * @brief Prints the Sudoku board
 *
 * Adds lines in between 3x3 boxes and around the whole board to print
 * to the terminal.
 *
 * @param none
 *
 * @return none
 */
void Grid::printGrid() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            cout << "-------------------------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                cout << "| ";
            }
            if (grid[i][j] == 0) {
                cout << "  ";
            }
            else {
                cout << grid[i][j] << " ";
            }
        }
        cout << "| " << endl;
    }
    cout << "-------------------------" << endl;
}
