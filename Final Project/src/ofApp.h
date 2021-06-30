#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "GameField.hpp"
#include "Item.hpp"
#include "Obstacle.hpp"
#include "ofxGui.h"
#include <vector>

typedef enum {
    IN_GAME,
    GAME_OVER,
    HIGHSCORE
} GameState;

class ofApp : public ofBaseApp{
    
public:
    ofFile file;
    std::vector<int> highScores;
    std::vector<Obstacle> obstacles;
    Obstacle obstacle = Obstacle(100);
    GameState game_state;
    ofTrueTypeFont myFont;
    ofPath travelPath;
    ofSoundPlayer gameMusic;
    ofImage playerIcon;
    ofImage starIcon;
    ofImage backgroundImage;
    ofImage gameOverScreen;
    Player game_player = Player(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    GameField game_field = GameField(ofGetWindowWidth() / 2, (ofGetWindowHeight() / 2));
    Item starItem = Item(ofGetWindowWidth() / 2.0, ofGetWindowHeight() / 2.0);
    uint64_t begTime;
    uint64_t actualTime;
    bool timerEnd;
    
    double dt;
    void setup();
    void update();
    void draw();
    void reset();
    void updateObstacles();
    void keyPressed(int key);
    void keyReleased(int key);
    void drawPlayerIcon();
    void drawStarIcon();
    void drawGameOver();
    void drawHighScores();
    void drawTimerBar();
    void drawInGame();
    bool isInsideField();
    void getCollision();
    void drawGameField();
    void getCurrentScore();
    void findHighScores();
    void orderScores();
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
};
