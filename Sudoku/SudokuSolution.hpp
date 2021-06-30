//
//  SudokuSolution.hpp
//  Sudoku
//
//  Created by Avinda De Silva on 10/17/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#ifndef SudokuSolution_hpp
#define SudokuSolution_hpp

#include <stdio.h>
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid. Size will be NxN
#define N 9
#include <iostream>

class SudokuSolver {
    std::string sudokuBoard;
    const int rowSize = 9;
    const int colSize = 9;
    const int allDigits = 9;
    bool canBeWritten[3] = {false, false, false};
public:
    int board[9][9];
    SudokuSolver() {
        sudokuBoard = "noname";
    }
    void createBoard(SudokuSolver &p);
    friend std::ostream &operator << (std::ostream &output, SudokuSolver &p);
    friend std::istream &operator >> (std::istream &input, SudokuSolver &p);
    
    // Checks whether it will be legal to assign num to the given row, col
    bool isSafe(int grid[N][N], int row, int col, int num);
    
    /* Takes a partially filled-in grid and attempts to assign values to
     all unassigned locations in such a way to meet the requirements
     for Sudoku solution (non-duplication across rows, columns, and boxes) */
    bool SolveSudoku(int grid[N][N]);
    
    /* Searches the grid to find an entry that is still unassigned. If
     found, the reference parameters row, col will be set the location
     that is unassigned, and true is returned. If no unassigned entries
     remain, false is returned. */
    bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
    
    /* Returns a boolean which indicates whether an assigned entry
     in the specified row matches the given number. */
    bool UsedInRow(int grid[N][N], int row, int num);
    
    /* Returns a boolean which indicates whether an assigned entry
     in the specified column matches the given number. */
    bool UsedInCol(int grid[N][N], int col, int num);
    
    /* Returns a boolean which indicates whether an assigned entry
     within the specified 3x3 box matches the given number. */
    bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
    
    bool containedInRow(int row, int num);
    bool containedInColumn(int col, int num);
    bool containedInSquare(int startRow, int startCol, int num);
    bool containsNumber(int row, int col, int num);
    bool hasNoValue(int &row, int &col);
    bool solver();
    
    
    
};

/* A utility function to print grid  */

#endif /* SudokuSolution_hpp */
