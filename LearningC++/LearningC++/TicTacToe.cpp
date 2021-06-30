//
//  TicTacToe.cpp
//  LearningC++
//
//  Created by Avinda De Silva on 10/8/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#include "TicTacToe.hpp"
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
void createBoard(std::string currentBoard) {
    if (currentBoard.size() == 9) {
        int index = 0;
        for (int i = 0; i < columnSize; i++) {
            for (int j = 0; j < rowSize; j++) {
                char player = currentBoard[index];
                board[i][j] = (tolower(player));
                std::cout << player;
                index++;
            }
            std::cout << std::endl;
        }
    }
}

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

enum Evaluation evaluateBoard(std::string currentBoard) {
    createBoard(currentBoard);
    if (currentBoard.size() != 9) {
        return InvalidInput;
    } else if (!(legalNumOfMoves(currentBoard))) {
        return UnreachableState;
    } else if (isWinner('x')) {
        return Xwins;
    } else if (isWinner('o')) {
        return Owins;
    } else {
        return NoWinner;
    }
}


