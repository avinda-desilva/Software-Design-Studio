//
//  Evaluate.cpp
//  TicTacToe
//
//  Created by Avinda De Silva on 10/8/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#include "Evaluate.hpp"
#include <array>

char board[3][3];
int rowSize = 3;
int columnSize = 3;
int boardLength = 9;

/**
 *This method takes the board as a string and creates a 3 by 3 array
 */
void createBoard(std::string currentBoard) {
    if (currentBoard.size() == boardLength) {
        int index = 0;
        for (int i = 0; i < columnSize; i++) {
            for (int j = 0; j < rowSize; j++) {
                char player = currentBoard[index];
                board[i][j] = (tolower(player));
                index++;
                std::cout << player;
            }
            std::cout << std::endl;
        }
    }
}

/**
 *This method checks to see if there are legal number of 'x' and 'o'
 *played and returns true if it is legal.
 */
bool legalNumOfMoves(std::string currentBoard) {
    int xCounter = 0;
    int oCounter = 0;
    for (int i = 0; i < currentBoard.size(); i++) {
        if (currentBoard[i] == 'x' || currentBoard[i] == 'X') {
            xCounter++;
        } else if (currentBoard[i] == 'o' || currentBoard[i] == 'O') {
            oCounter++;
        }
    }
    if (oCounter > xCounter) {
        return false;
    } else if ((xCounter - oCounter) >= 2) {
        return false;
    } else {
        return true;
    }
}

/**
 *This method checks if the board played has a winner.
 *If it has a winner, it will return true.
 */
bool isWinner(char player) {
    bool isWinner = false;
    for (int i = 0; i < columnSize; i++) {
        //Checks if it is a row win
        if ((player == board[i][0]) && (board[i][0] == board[i][1])
            && (board[i][1] == board[i][2])) {
            isWinner = true;
            //Checks if it is a column win
        } else if ((player == board[0][i]) && (board[0][i] == board[1][i])
                   && (board[1][i] == board[2][i])) {
            isWinner = true;
            //Checks if it is a diagonal win
        } else if ((player == board[0][0]) && (board[0][0] == board[1][1])
                   && (board[1][1] == board[2][2])) {
            isWinner = true;
            //Checks if it is a diagonal win
        } else if ((player == board[0][2]) && (board[0][2] == board[1][1])
                   && (board[1][1] == board[2][0])) {
            isWinner = true;
        }
    }
    return isWinner;
}

/**
 *Main method that takes the string Board. It returns the evaluation
 *of the board played.
 */
enum Evaluation evaluateBoard(std::string currentBoard) {
    createBoard(currentBoard);
    if (currentBoard.size() != boardLength) {
        return InvalidInput;
    } else if (!(legalNumOfMoves(currentBoard))) {
        return UnreachableState;
    } else if (isWinner('x') && isWinner('o')) {
        return UnreachableState;
    } else if (isWinner('x')) {
        return Xwins;
    } else if (isWinner('o')) {
        return Owins;
    } else {
        return NoWinner;
    }
}

