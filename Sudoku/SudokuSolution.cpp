//
//  SudokuSolution.cpp
//  Sudoku
//
//  Created by Avinda De Silva on 10/17/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#include "SudokuSolution.hpp"

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid. Size will be NxN
#define N 9

/* Takes a partially filled-in grid and attempts to assign values to
 all unassigned locations in such a way to meet the requirements
 for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SudokuSolver::SolveSudoku(int board[N][N]) {
    int row, col;
    
    // If there is no unassigned location, we are done
    if (!FindUnassignedLocation(board, row, col))
        return true; // success!
    
    // consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        // if looks promising
        if (isSafe(board, row, col, num))
        {
            // make tentative assignment
            board[row][col] = num;
            
            // return, if success, yay!
            if (SolveSudoku(board))
                return true;
            
            // failure, unmake & try again
            board[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
 found, the reference parameters row, col will be set the location
 that is unassigned, and true is returned. If no unassigned entries
 remain, false is returned. */
bool SudokuSolver::FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

/* Returns a boolean which indicates whether an assigned entry
 in the specified row matches the given number. */
bool SudokuSolver::UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether an assigned entry
 in the specified column matches the given number. */
bool SudokuSolver::UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether an assigned entry
 within the specified 3x3 box matches the given number. */
bool SudokuSolver::UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
 num to the given row,col location. */
bool SudokuSolver::isSafe(int grid[N][N], int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
     current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
    !UsedInCol(grid, col, num) &&
    !UsedInBox(grid, row - row%3 , col - col%3, num);
}

std::ostream &operator << (std::ostream &output, SudokuSolver &p) {
    int index = 0;
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            output << "------------" << std::endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                output << "|";
            }
            output << p.board[i][j];
            index++;
        }
        output << std::endl;
        
    }
    return output;
}
void SudokuSolver::createBoard(SudokuSolver &p) {
    int index = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!(isdigit(p.sudokuBoard[index]))) {
                p.board[i][j] = '0';
            } else {
                p.board[i][j] = (int) p.sudokuBoard[index];
            }
            index++;
        }
    }
}

std::istream &operator >> (std::istream &input, SudokuSolver &p) {
    std::getline (input, p.sudokuBoard);
    return input;
}
