//
//  SudokuSolver.hpp
//  Sudoku
//
//  Created by Avinda De Silva on 10/15/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#ifndef SudokuSolver_hpp
#define SudokuSolver_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <array>

class Sudoku{
public:
    std::string sudokuBoard;
    int board[9][9];
    int digitCounter = 0;
    Sudoku() {
        sudokuBoard = "noname";
    }
    void createBoard(Sudoku &p);
    friend std::ostream &operator << (std::ostream &output, Sudoku &p);
    friend std::istream &operator >> (std::istream &input, Sudoku &p);
    bool containedInRow(int &row, int num) const;
    bool containedInColumn(int &col, int num);
    bool containedInSquare(int &startRow, int &startCol, int num);
    bool containsNumber(int &row, int &col, int num);
    bool hasNoValue(int &row, int &col);
    bool solver();
    
   
    
};

/*
 std::string main() {
 Sudoku currentBoard;
 std::cin >> currentBoard;
 currentBoard.createBoard(currentBoard);
 std::cout << currentBoard;
 if (currentBoard.solver() == true) {
 std::cout << currentBoard;
 return "Can be solved!";
 } else {
 return "This puzzle is unsolvable";
 }
 }
 
 
 */
#endif /* SudokuSolver_hpp */
