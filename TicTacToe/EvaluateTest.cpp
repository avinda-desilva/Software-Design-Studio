//
//  main.cpp
//  TicTacToe
//
//  Created by Avinda De Silva on 10/5/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Evaluate.hpp"

TEST_CASE("Creates a new board") {
    std::string board = "xooxoxoxo";
    createBoard(board);
}

TEST_CASE("Checks to see if the special case is unreachable") {
    std::string  board = "xooxoxoxo";
    REQUIRE(evaluateBoard(board) == UnreachableState);
}

TEST_CASE("Checks all X Win Cases") {
    std::string board = "xxxooxoxo";
    REQUIRE(evaluateBoard(board) == Xwins);
    board = "ooxxxxoxo";
    REQUIRE(evaluateBoard(board) == Xwins);
    board = "oxoooxxxx";
    REQUIRE(evaluateBoard(board) == Xwins);
    board = "xxoxoxxoo";
    REQUIRE(evaluateBoard(board) == Xwins);
    board = "xxooxxoxo";
    REQUIRE(evaluateBoard(board) == Xwins);
    board = "oxxxoxoox";
    REQUIRE(evaluateBoard(board) == Xwins);
    board = "oxxoxoxox";
    REQUIRE(evaluateBoard(board) == Xwins);
    board = "xxooxoxox";
    REQUIRE(evaluateBoard(board) == Xwins);
}

TEST_CASE("Checks all O Win Cases") {
    std::string board = "oooxoxxx_";
    REQUIRE(evaluateBoard(board) == Owins);
    board = "xoxoooxx_";
    REQUIRE(evaluateBoard(board) == Owins);
    board = "xoxxx_ooo";
    REQUIRE(evaluateBoard(board) == Owins);
    board = "ox_ooxoxx";
    REQUIRE(evaluateBoard(board) == Owins);
    board = "xo_ooxxox";
    REQUIRE(evaluateBoard(board) == Owins);
    board = "x_ooxoxxo";
    REQUIRE(evaluateBoard(board) == Owins);
    board = "ox_xox_xo";
    REQUIRE(evaluateBoard(board) == Owins);
    board = "_xoxoxox_";
    REQUIRE(evaluateBoard(board) == Owins);
}

TEST_CASE("Checks if all uppercase letters will still evaluate properly") {
    std::string board = "XXXXOOOOX";
    REQUIRE(evaluateBoard(board) == Xwins);
}

TEST_CASE("Checks if all lowercase letters will still evaluate properly") {
    std::string board = "ooooooooo";
    REQUIRE(evaluateBoard(board) == UnreachableState);
}

TEST_CASE("Checks if random characters will not compute") {
    std::string board = ".........";
    REQUIRE(evaluateBoard(board) == NoWinner);
    board = "abcdefghi";
    REQUIRE(evaluateBoard(board) == NoWinner);
}

TEST_CASE("Checks if no input will not compute") {
    std::string board = "";
    REQUIRE(evaluateBoard(board) == InvalidInput);
}

TEST_CASE("Evaluates game and will compute as unfinished game") {
    std::string board = "x.xoo....";
    REQUIRE(evaluateBoard(board) == NoWinner);
}

TEST_CASE("Evaluates tie game and prints no winner") {
    std::string board = "XoxOXxOXo";
    REQUIRE(evaluateBoard(board) == NoWinner);
}

TEST_CASE("Evaluate a completed game with an incompleted board") {
    std::string board = "xxxoo1234";
    REQUIRE(evaluateBoard(board) == Xwins);
}

TEST_CASE("Evaluate a illegal win with an incompleted board") {
    std::string board = "xxxo.....";
    REQUIRE(evaluateBoard(board) == UnreachableState);
}

TEST_CASE("Evaluates board with different characters") {
    std::string board = "01x34o67x";
    REQUIRE(evaluateBoard(board) == NoWinner);
}

TEST_CASE("Evaluates long string and invalid board") {
    std::string board = "supercalifragilisticexpealidocious";
    REQUIRE(evaluateBoard(board) == InvalidInput);
}

TEST_CASE("Evaluates illegal wins as an Unreachable state") {
    std::string board = "xxxooxxox";
    REQUIRE(evaluateBoard(board) == UnreachableState);
    board = "oooxoxoxo";
    REQUIRE(evaluateBoard(board) == UnreachableState);
}

TEST_CASE("Ignores whitespace before or after the board") {
    std::string board = "       XXOOXOXOO";
    REQUIRE(evaluateBoard(board) == InvalidInput);
}

TEST_CASE("Evaluates this special case as an Unreachable state") {
    std::string board = "oooxx....";
    REQUIRE(evaluateBoard(board) == UnreachableState);
}

TEST_CASE("Evaluates that player x will always win before player o") {
    std::string board = "oooxxx...";
    REQUIRE(evaluateBoard(board) == UnreachableState);
}

