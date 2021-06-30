//
//  Player.cpp
//  Final Project
//
//  Created by Avinda De Silva on 11/14/18.
//

#include "Player.hpp"
#include <algorithm>

ofVec2f Player::getPlayerPosition() {
    return player_position;
}

/**
 * Depending on the direction that is being traveled, the angle will determine what position the car will go to. Additional it has the ability to accelerate and deaccelerate the car depending on the key that is pressed.
 */
void Player::movePlayer(double dt) {
    double resultedAccel;
    resultedAccel = acceleration - deacceleration;
    if (!can_move) {
        return;
    } else if (is_left_pressed && (is_up_pressed || is_down_pressed) && abs(resultedAccel) > 0.01) {
        if (resultedAccel > 0) {
            angle -= (dt);
            acceleration += (0.3 * dt);
        } else {
            angle += (dt);
            deacceleration += (0.3 * dt);
        }
    } else if (is_right_pressed && (is_up_pressed || is_down_pressed) && abs(resultedAccel) > 0.01) {
        if (resultedAccel > 0) {
            angle += (dt);
            acceleration += (0.3 * dt);
        } else {
            angle -= (dt);
            deacceleration += (0.3 * dt);
        }
    } else if (is_up_pressed) {
        acceleration += (0.5 * dt);
        deacceleration = 0;
    } else if (is_down_pressed) {
        deacceleration += (0.8 * dt);
        acceleration = 0;
    } else if (!is_inside_field) {
        double tempAccel = resultedAccel;
        acceleration = 0;
        deacceleration = 0;
    } else {
        if (resultedAccel > 0) {
            acceleration = resultedAccel;
        }
        deacceleration /= 1.3;
    }
    if (resultedAccel > 0) {
        player_velocity.x = sin(angle) * (resultedAccel);
        player_velocity.y = cos(angle) * (resultedAccel);
    } else if (resultedAccel < 0) {
        double newAngle;
        player_velocity.x = sin(angle) * resultedAccel;
        player_velocity.y = cos(angle) * resultedAccel;
    }
}

Player::Player(double x, double y) : angle(0.0),   score(0) {
    player_position.set(x, y);
    player_velocity.set(0.0, 0.0);
    acceleration = 0.0;
    collision_box.set(player_position.x - 9, player_position.y - 18, 18, 36);
    is_inside_field = true;
    safePosition.set(player_position);
    can_move = true;
}

/**
 * Changes the positioning of the car using different forces. Allows it to simulate more like a car.
 */
void Player::update(double dt) {
    double drag = 0.97;
    movePlayer(dt);
    if (!is_inside_field) {
        ofVec2f tempVelocity = player_velocity;
        player_velocity = tempVelocity * -0.02;
        player_position.set(safePosition);
    } else {
        safePosition.set(player_position);
        player_position.x += player_velocity.x;
        player_position.y -= player_velocity.y;
        player_velocity.x *= drag;
        player_velocity.y *= drag;
    }
}

void Player::reset(double x, double y) {
    angle = 0.0;
    acceleration = 0.0;
    deacceleration = 0.0;
    player_velocity.set(0, 0);
    player_position.set(x, y);
    collision_box.set(player_position.x - 9, player_position.y - 18, 18, 36);
    score = 0;
    safePosition.set(player_position);
}

void Player::increaseScore(int num) {
    score+= num;
}

int Player::getScore() {
    return score;
}




