//
//  SudokuSolver.cpp
//  Sudoku
//
//  Created by Avinda De Silva on 10/15/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#include "SudokuSolver.hpp"
#include <iostream>
#include <array>
#include <string>
const uint32_t kRowSize = 9;
const unsigned int kColSize = 9;
const unsigned int kAllDigits = 9;
const unsigned int kBoxSize = 3;
const unsigned int kNumOfPlayableSpaces = 81;
const unsigned int kNoValue = 0;

/*
 * Overloads the operator "<<" which pretty prints out the current sudoku board
 */
std::ostream &operator << (std::ostream &output, Sudoku &p) {
    int index = 0;
    if ((p.sudokuBoard.length() != kNumOfPlayableSpaces) || (p.digitCounter < 17)) {
        output << "This puzzle is invalid";
        return output;
    } else {
        for (int row = 0; row < kRowSize; row++) {
            if (row % kBoxSize == 0) {
                output << "------------" << std::endl;
            }
            for (int col = 0; col < kColSize; col++) {
                if (col % kBoxSize == 0) {
                    output << "|";
                }
                output << p.board[row][col];
                index++;
            }
            output << std::endl;
            
        }
        return output;
    }
}

/*
 * Overloads the operator ">>" which allows the user to enter a line as a sudoku string
 */
std::istream &operator >> (std::istream &input, Sudoku &p) {
    std::getline (input, p.sudokuBoard);
    return input;
}

/*
 * Creates a 9 by 9 integer board from the given sudokuBoard string
 */
void Sudoku::createBoard(Sudoku &p) {
    int index = 0;
    for (int row = 0; row < kRowSize; row++) {
        for (int col = 0; col < kColSize; col++) {
            if (!(isdigit(p.sudokuBoard[index]))) {
                p.board[row][col] = kNoValue;
            } else {
                p.board[row][col] = (int) (p.sudokuBoard[index] - '0');
                p.digitCounter++;
            }
            index++;
        }
    }
}

/*
 * Checks if the number being checked has already been placed in the row.
 * Returns true if the number is already in row
 */
bool Sudoku::containedInRow(int &row, int num) {
    for (int col = 0; col < kColSize; col++) {
        if (Sudoku::board[row][col] == num) {
            return true;
        }
    }
    return false;
}

/*
 * Checks if the number being checked has already been placed in the column.
 * Returns true if the number is already in column
 */
bool Sudoku::containedInColumn(int &col, int num) {
    for (int row = 0; row < kRowSize; row++) {
        if (Sudoku::board[row][col] == num) {
            return true;
        }
    }
    return false;
}

/*
 * Checks if the number being checked has already been placed in the 3 by 3 square.
 * Returns true if the number is already in the square
 */
bool Sudoku::containedInSquare(int &startRow, int &startCol, int num) {
    for (int row = 0; row < kBoxSize; row++) {
        for (int col = 0; col < kBoxSize; col++) {
            if (Sudoku::board[startRow + row][startCol + col] == num) {
                return true;
            }
        }
    }
    return false;
}

/*
 * Checks if the current spot is empty and returns true if it is
 */
bool Sudoku::hasNoValue(int &row, int &col) {
    for (row = 0; row < kRowSize; row++) {
        for (col = 0; col < kColSize; col++) {
            if (board[row][col] == kNoValue) {
                return true;
            }
        }
    }
    return false;
}

//Code below is based off: https://www.geeksforgeeks.org/sudoku-backtracking-7/
/*
 * Recursive algorithim that continues to check if the number can be put in a certain spot and will complete the board. If it can be solved it will return true.
 */
bool Sudoku::solver() {
    int row, col;
    if (!(hasNoValue(row, col))) {
        return true;
    } else if (Sudoku::digitCounter < 17) {
        return false;
    }
    int startRow = (row - (row % kBoxSize));
    int startCol = (col - (col % kBoxSize));
    for (int num = 1; num <= kAllDigits; num++) {
        if (Sudoku::containedInRow(row, num) == false && Sudoku::containedInColumn(col, num) == false
            && Sudoku::containedInSquare(startRow, startCol, num) == false) {
            
            Sudoku::board[row][col] = num;
            if (Sudoku::solver()) {
                return true;
            }
            
            Sudoku::board[row][col] = kNoValue;
        }
    }
    return false;
}
