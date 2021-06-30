//
//  SudokuSolverTest.cpp
//  Sudoku
//
//  Created by Avinda De Silva on 10/17/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "SudokuSolver.hpp"

TEST_CASE("Checks to see that it can solve this puzzle as well as pretty print it") {
    Sudoku puzzle;
    puzzle.sudokuBoard = "3 4 1 9 88 96  25 2 59  63 42 361 9  93  8   1 847 3 698  567 3  1 4   9 46  3 8 ";
    puzzle.createBoard(puzzle);
    std::cout << puzzle;
    REQUIRE(puzzle.solver() == true);
    std::cout << puzzle;
}

TEST_CASE("Checks to see that this puzzle cannot be solved because there are duplicates") {
    Sudoku puzzle;
    puzzle.sudokuBoard = "..9.7...5..21..9..1...28....7...5..1..851.....5....3.......3..68........21.....87";
    puzzle.createBoard(puzzle);
    std::cout << puzzle;
    REQUIRE(puzzle.solver() == false);
    std::cout << puzzle;
}

TEST_CASE("Checks to see that this puzzle cannot be solved because there is a square that cannot be solved") {
    Sudoku puzzle;
    puzzle.sudokuBoard = "..9.287..8.6..4..5..3.....46.........2.71345.........23.....5..9..4..8.7..125.3..";
    puzzle.createBoard(puzzle);
    std::cout << puzzle;
    REQUIRE(puzzle.solver() == false);
    std::cout << puzzle;
}

TEST_CASE("Checks to see that this puzzle cannot be solved because the string length is invalid") {
    Sudoku puzzle;
    puzzle.sudokuBoard = "..";
    puzzle.createBoard(puzzle);
    std::ostringstream puzzlePrint;
    puzzlePrint << puzzle;
    REQUIRE(puzzlePrint.str() == "This puzzle is invalid");
    std::cout << puzzle;
}

TEST_CASE("Invalid puzzle that could have multiple solutions") {
    Sudoku puzzle;
    puzzle.sudokuBoard = ".................................................................................";
    puzzle.createBoard(puzzle);
    std::ostringstream puzzlePrint;
    puzzlePrint << puzzle;
    REQUIRE(puzzlePrint.str() == "This puzzle is invalid");
    REQUIRE(puzzle.solver() == false);
    std::cout << puzzle;
}

TEST_CASE("Invalid puzzle because there is only one digit") {
    Sudoku puzzle;
    puzzle.sudokuBoard = "........................................1........................................";
    puzzle.createBoard(puzzle);
    std::ostringstream puzzlePrint;
    puzzlePrint << puzzle;
    REQUIRE(puzzlePrint.str() == "This puzzle is invalid");
    REQUIRE(puzzle.solver() == false);
    std::cout << puzzle;
}

TEST_CASE("This puzzle is solvable but has multiple solutions") {
    Sudoku puzzle;
    puzzle.sudokuBoard = "..3.....6...98..2.9426..7..45...6............1.9.5.47.....25.4.6...785...........";
    puzzle.createBoard(puzzle);
    std::ostringstream puzzlePrint;
    puzzlePrint << puzzle;
    REQUIRE(puzzle.solver() == true);
    std::cout << puzzle;
}






