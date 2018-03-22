#pragma once
using namespace std;

/**
 * @brief Grid Class hpp file
 *
 * The Grid Class is essentially the sudoku board represented by a 2-D
 * array of integers. The purpose of this class is to include functions
 * which can add, remove, and show the numbers on the Soduku board.
 */
class Grid
{
private:
    int gridOriginal[9][9];

public:
    Grid() {};
    ~Grid() {};
    int grid[9][9];
    void loadBoard(string filename);
    void printGrid();
    bool isComplete();
    bool checkValid(int x, int y, int val);
    void writeNum(int x, int y, int val);
    void undoNum(int x, int y);
};
