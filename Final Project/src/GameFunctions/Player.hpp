//
//  Player.hpp
//  Final Project
//
//  Created by Avinda De Silva on 11/14/18.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "ofMain.h"

class Player
{
private:
    double acceleration;
    double deacceleration;
    ofVec2f player_position;
    ofVec2f player_velocity;
    int score;
    ofVec2f safePosition;
public:
    bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed, is_inside_field, can_move;
    ofRectangle collision_box;
    double angle;
    Player(double x, double y);
    ofVec2f getPlayerPosition();
    void movePlayer(double dt);
    void update(double dt);
    void increaseScore(int num);
    int getScore();
    void reset(double x, double y);
};

#endif /* Player_hpp */
