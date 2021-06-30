//
//  Evaluate.hpp
//  TicTacToe
//
//  Created by Avinda De Silva on 10/8/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#ifndef Evaluate_hpp
#define Evaluate_hpp

#include <stdio.h>
#include <iostream>
enum Evaluation {InvalidInput , UnreachableState, Xwins, Owins, NoWinner};

void createBoard(std::string currentBoard);

bool legalNumOfMoves(std::string currentBoard);

bool isWinner(char player);

enum Evaluation evaluateBoard(std::string currentBoard);

#endif /* Evaluate_hpp */
