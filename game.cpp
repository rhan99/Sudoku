#include <iostream>
#include <cstdlib>
#include <string.h>
#include "game.hpp"

using namespace std;

/**
 * @brief Gets the user's move from the terminal
 *
 * Checks to see if the user move is valid. If not, print an error message.
 * If yes, use the grid class to execute the move
 *
 * @param none
 *
 * @return none
 */
void Game::getMove() {
    string move;
    int x, y, val;

    cout << "Please enter a move: " << endl;
    getline (cin, move);

    if (move == "q") {
        exit(0);
    }
    else if (move[0] == 'd') {
        x = move[2] - '0';
        y = move[4] - '0';
        val = move[6] - '0';
        sudokuGrid.writeNum(x, y, val);
    }
    else if (move[0] == 'u') {
        x = move[2] - '0';
        y = move[4] - '0';
        sudokuGrid.undoNum(x, y);
    }
    else {
        cout << "Illegal move!" << endl;
    }
}

/**
 * @brief Runs the Sudoku game
 *
 * Loads the Sudoku board on the terminal, and receives moves / prints board
 * as long as the board is not full
 *
 * @param filename, the name of the file as a string
 *
 * @return none
 */
void Game::run(string filename) {
    sudokuGrid.loadBoard(filename);

    while(sudokuGrid.isComplete() == false) {
        sudokuGrid.printGrid();
        Game::getMove();
    }
    cout << "Solved!" << endl;
}
