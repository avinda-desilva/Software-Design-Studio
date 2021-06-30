//
//  Sudoku.hpp
//  Sudoku
//
//  Created by Avinda De Silva on 10/16/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#ifndef Sudoku_hpp
#define Sudoku_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <array>

class OldSudoku{
    std::string sudokuBoard;
    bool canBeWritten[3] = {false, false, false};
public:
    int board[9][9];
    OldSudoku() {
        sudokuBoard = "noname";
    }
    void createBoard(OldSudoku &p);
    friend std::ostream &operator << (std::ostream &output, OldSudoku &p);
    friend std::istream &operator >> (std::istream &input, OldSudoku &p);
    bool containedInRow(int &row, int num);
    bool containedInColumn(int &col, int num);
    bool containedInSquare(int &startRow, int &startCol, int num);
    bool containsNumber(int &row, int &col, int num);
    bool hasNoValue(int &row, int &col);
    bool solver();

    
    
};

#endif /* Sudoku_hpp */
