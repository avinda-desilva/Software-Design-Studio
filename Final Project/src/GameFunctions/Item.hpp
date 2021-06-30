//
//  Item.hpp
//  Final Project
//
//  Created by Avinda De Silva on 12/7/18.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include "ofMain.h"

class Item
{
private:
    ofVec2f position;
public:
    ofRectangle collision_box;
    Item(double x, double y);
    ofVec2f getPosition();
    ofVec2f changeLocation(int radius);
};

#endif /* Item_hpp */
