//
//  Obstacle.cpp
//  Final Project
//
//  Created by Avinda De Silva on 12/12/18.
//

#include "Obstacle.hpp"
#include <cmath>


Obstacle::Obstacle(int radius) {
    changeLocation(radius);
}

ofVec2f Obstacle::getPosition() {
    return position;
}

/**
 * Chooses a random point that is found on the circle and is drawn at that location.
 */
ofVec2f Obstacle::changeLocation(int radius) {
    position.set(ofGetWindowWidth() / 2.0, ofGetWindowHeight() / 2.0);
    ofVec2f drawPosition;
    drawPosition.x = rand() % radius;
    drawPosition.y = rand() % (int) pow((pow(radius, 2) - pow(drawPosition.x, 2)), 0.5);
    if ((rand() % 100) > 50) {
        position -= drawPosition;
    } else {
        position += drawPosition;
    }
    collision_box.set(position.x, position.y, rand() % 20 + 50, rand() % 20 + 50);
}

