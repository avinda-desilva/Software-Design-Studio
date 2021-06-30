//
//  main.cpp
//  LearningC++
//
//  Created by Avinda De Silva on 10/6/18.
//  Copyright © 2018 Avinda De Silva. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <array>
#include "Bananas.hpp"
#include "catch.hpp"

int square(int x) {
    return x * x;
}

enum evaluation { InvalidInput , UnreachableState, Xwins, Owins, NoWinner};

void print_fct() {
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    
    for (auto elem : v) {
        std::cout <<elem<< "\n";
    }
}
         
void print_square() {
    int x = 3;
    std::cout << "The square of " <<x<< " is " <<square(x) << "\n";
}

double cube(double num) {
    return pow(num, 3);
}


