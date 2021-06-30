//
//  GameField.hpp
//  Final Project
//
//  Created by Avinda De Silva on 11/14/18.
//

#ifndef GameField_hpp
#define GameField_hpp

#include <stdio.h>
#include "ofMain.h"

class GameField
{
private:
    ofVec2f field_position;
    int radius;
public:
    GameField(double x, double y);
    void increaseRadius(int num);
    int getRadius();
    ofVec2f getPosition();
    
};

#endif /* GameField_hpp */
