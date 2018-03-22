#include <iostream>
#include "game.hpp"

using namespace std;

/**
 * @brief Creates and runs the Sudoku game
 */
int main(int argc, char ** argv) {
    Game sudokuGame;
    sudokuGame.run("testFileEasy.in");
    return 0;
}
