#pragma once
#include "grid.hpp"
using namespace std;

/**
 * @brief Game Class hpp file
 *
 * The Game Class uses the grid class to run a game of Sudoku through the
 * terminal. The purpose of this class is to include functions
 * which can start the game, receive user moves from the terminal, and
 * end the game.
 */
class Game
{
private:
    Grid sudokuGrid;
public:
    Game() {};
    ~Game() {};
    void getMove();
    void run(string filename);
};
