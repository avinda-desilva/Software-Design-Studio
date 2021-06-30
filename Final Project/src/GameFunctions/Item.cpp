//
//  Item.cpp
//  Final Project
//
//  Created by Avinda De Silva on 12/7/18.
//

#include "Item.hpp"
#include <cmath>


Item::Item(double x, double y) {
    position.x = x;
    position.y = y;
    collision_box.set(position.x, position.y, 8.5, 8);
}

ofVec2f Item::getPosition() {
    return position;
}

/**
 * Chooses a random point that is found on the circle and is drawn at that location.
 */
ofVec2f Item::changeLocation(int radius) {
    position.set(ofGetWindowWidth() / 2.0, ofGetWindowHeight() / 2.0);
    ofVec2f drawPosition;
    drawPosition.x = rand() % radius;
    drawPosition.y = rand() % (int) pow((pow(radius, 2) - pow(drawPosition.x, 2)), 0.5);
    if ((rand() % 100) > 50) {
        position -= drawPosition;
    } else {
        position += drawPosition;
    }
    collision_box.setPosition(position.x, position.y);
    return position;
}


