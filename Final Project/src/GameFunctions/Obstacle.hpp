//
//  Obstacle.hpp
//  Final Project
//
//  Created by Avinda De Silva on 12/12/18.
//

#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <stdio.h>
#include "ofMain.h"

class Obstacle
{
private:
    ofVec2f position;
public:
    ofRectangle collision_box;
    Obstacle(int radius);
    ofVec2f getPosition();
    ofVec2f changeLocation(int radius);
};


#endif /* Obstacle_hpp */
