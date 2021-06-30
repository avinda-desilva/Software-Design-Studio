#pragma once
#include <ctime>
#include <cstdlib>
#include <utility>
#include <vector>

#include "ofMain.h"
#include "snake.h"
#include "SnakeFood.h"

namespace snakelinkedlist {
    
    // Enum to represent the current state of the game
    enum GameState {
        IN_PROGRESS = 0,
        PAUSED,
        HIGHSCORE_PAUSED,
        FINISHED
    };
    
    class snakeGame : public ofBaseApp {
    private:
        ofFile file;
        ofSoundPlayer sound;
        int speedMultiplier;

        std::vector<int> highScores;
        GameState current_state_ = IN_PROGRESS; // The current state of the game, used to determine possible actions
        Snake game_snake_; // The object that represents the user controlled snake
        SnakeFood game_food_; // The object that represents the food pellet the user is attempting to eat with the snake
        
        bool should_update_ = true;     // A flag boolean used in the update() function. Due to the frame dependent animation we've
        // written, and the relatively low framerate, a bug exists where users can prefire direction
        // changes faster than a frame update. Our solution is to force a call to update on direction
        // changes and then not update on the next frame to prevent the snake from skipping across the screen.
        
        
        // Private helper methods to render various aspects of the game on screen.
        void drawFood();
        void drawSnake();
        void drawGameOver();
        void drawGamePaused();
        void drawHighScores();
        void getCurrentScore();           // Saves current game score into "scores.txt" after the snake is dead
        void findHighScores();           // Takes all the scores from "scores.txt" and puts all the
                                        // values into a vector
        void orderScores();            // Sorts all the values in the vector and saves the top 10 in "highscores.txt"
        void playEatSound(); 
        
        // Resets the game objects to their original state.
        void reset();
        
    public:
        // Function used for one time setup
        void setup();
        
        // Main event loop functions called on every frame
        void update();
        void draw();
        
        // Event driven functions, called on appropriate user action
        void keyPressed(int key);
        void keyReleased(int key);
        void windowResized(int w, int h);
    };
} // namespace snakelinkedlist
