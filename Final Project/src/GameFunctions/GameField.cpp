//
//  GameField.cpp
//  Final Project
//
//  Created by Avinda De Silva on 11/14/18.
//

#include "GameField.hpp"

void GameField::increaseRadius(int num) {
    radius+= num;
}

int GameField::getRadius() {
    return radius;
}

GameField::GameField(double x, double y) : radius(100) {
    field_position.x = x;
    field_position.y = y;
}

ofVec2f GameField::getPosition() {
    return field_position;
}
