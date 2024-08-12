#include <bits/stdc++.h>
using namespace std;
bool isPossible(char value, int row, int col, vector<vector<char>> &board)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == value)
            return false;
    }

    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == value)
            return false;
    }

    int boxRow = row - row % 3, boxCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[boxRow + i][boxCol + j] == value)
                return false;
        }
    }

    return true;
}
bool solver(int index, int n, vector<pair<int, int>> &emptyCells, vector<vector<char>> &board)
{

    // base case | all empty cells are filled
    if (index == n)
    {
        return true;
    }

    // try each possible solution for each cell
    for (int i = 1; i <= 9; i++)
    {

        // get current cell address
        int row = emptyCells[index].first, col = emptyCells[index].second;

        // check is possible to fill current value or not
        if (isPossible(i + '0', row, col, board))
        {

            // assign current value at current empty cell
            board[row][col] = (i + '0');

            // try for next empty cell
            bool isSolution = solver(index + 1, n, emptyCells, board);
            // solution is found
            if (isSolution)
                return true;

            // backtrack from here
            board[row][col] = '.';
        }
    }

    return false;
}
void solveSudoku(vector<vector<char>> &A)
{
    // for storing empty cells
    vector<vector<char>> board = A;
    vector<pair<int, int>> emptyCells;

    // store empty cells
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                emptyCells.push_back({i, j});
            }
        }
    }

    int n = emptyCells.size();

    solver(0, n, emptyCells, board);
    A = board;
};