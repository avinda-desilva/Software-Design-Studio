#include "ofApp.h"
#include <cmath>
#include <vector>


const double_t kMaxTime = 5000.0;
const double_t kMaxColor = 255.0;
const uint32_t kHighScores = 10;

//--------------------------------------------------------------
void ofApp::setup(){
    int offset = 30;
    game_state = IN_GAME;
    myFont.load("digital-7 (mono italic).ttf", 25);
    gameMusic.load("gameMusic.mp3");
    gameMusic.setVolume(0.5);
    gameMusic.play();
    playerIcon.load("carImage.png");
    playerIcon.setAnchorPercent(.5f, .5f);
    starIcon.load("star.png");
    starItem = Item(ofGetWindowWidth() / 2.0, ofGetWindowHeight() / 2.0);
    starItem.changeLocation(game_field.getRadius() - offset);
    backgroundImage.load("backgroundImage.jpg");
    backgroundImage.resize(ofGetWindowWidth(), ofGetWindowHeight());
    gameOverScreen.load("GameOver.jpg");
    gameOverScreen.resize(ofGetWindowWidth(), ofGetWindowHeight());
    begTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
/**
 * This functions gets the collision box position of the player and updates as the car moves.
 */
void ofApp::getCollision() {
    ofRotateZRad(game_player.angle);
    game_player.collision_box.setPosition(game_player.getPlayerPosition().x - 9, game_player.getPlayerPosition().y - 18);
}

/**
 * This function checks the score of the player and will create an obstacle at a random location.
 */
void ofApp::updateObstacles() {
    int offset = 50;
    if (game_player.getScore() % 5 == 0) {
        obstacle = Obstacle(game_field.getRadius() - offset);
        if (obstacle.collision_box.intersects(game_player.collision_box)) {
            obstacle.changeLocation(game_field.getRadius() - offset);
        }
        obstacles.push_back(obstacle);
    } else if (obstacles.size() > 1) {
        for (uint32_t i = 0; i < obstacles.size() - 1; i++) {
            if (obstacles[i].collision_box.intersects(obstacles[i + 1].collision_box)) {
                obstacles[i + 1].changeLocation(game_field.getRadius() - offset);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    int offset = 30;
    actualTime = ofGetElapsedTimeMillis();
    dt = ofGetLastFrameTime();
    game_player.update(dt);
    getCollision();
    ofDrawRectangle(game_player.collision_box);
    ofSetRectMode(OF_RECTMODE_CORNER);
    if (game_player.collision_box.intersects(starItem.collision_box)) {
        begTime = ofGetElapsedTimeMillis();
        game_player.increaseScore(1);
        game_field.increaseRadius(10);
        starItem.changeLocation((game_field.getRadius() - offset));
        updateObstacles();
    } else if (!isInsideField()) {
        game_player.is_inside_field = false;
    } else {
        for (u_int32_t i = 0; i < obstacles.size(); i++) {
            if (game_player.collision_box.intersects(obstacles[i].collision_box)) {
                game_player.is_inside_field = false;
            } else if (starItem.collision_box.intersects(obstacles[i].collision_box)) {
                starItem.changeLocation(game_field.getRadius() - offset);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::reset() {
    game_state = IN_GAME;
    game_player.reset(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    game_field = GameField(ofGetWindowWidth() / 2, (ofGetWindowHeight() / 2));
    starItem.changeLocation(game_field.getRadius() - 30);
    begTime = ofGetElapsedTimeMillis();
    obstacles.clear();
}

//--------------------------------------------------------------
void ofApp::drawTimerBar() {
    int offset = 100;
    double maxColor = 255;
    float timeElapsed = actualTime - begTime;
    if (timeElapsed > kMaxTime) {
        game_state = GAME_OVER;
        game_player.can_move = false;
    } else {
        game_state = IN_GAME;
        game_player.can_move = true;
        float timerBar = ofMap(timeElapsed, 0.0, kMaxTime, 1.0, 0.0, true);
        myFont.drawString(std::to_string((5000 - timeElapsed) / 1000).substr(0, 3), ofGetWindowWidth() / 2 - 40, 100);
        ofPushMatrix();
        if (timerBar >= 0.5) {
            ofSetColor(maxColor - (maxColor * ((timerBar - 0.5) * 2)), maxColor, 0);
        } else {
            ofSetColor(maxColor, maxColor * (timerBar + timerBar), 0);
        }
        ofDrawRectRounded(offset, offset, ((ofGetWindowWidth() - (2 * offset)) * timerBar), 30, 5);
        ofPopMatrix();
    }
    ofSetColor(kMaxColor, kMaxColor, kMaxColor);
}

/**
 * Draws the window while the game is being played
 */
void ofApp::drawInGame() {
    backgroundImage.draw(0, 0);
    ofSetColor(94, 249, 120); //Light green color
    ofDrawCircle(game_field.getPosition().x, game_field.getPosition().y, game_field.getRadius());
    
    for (u_int32_t i = 0; i < obstacles.size(); i++) {
        ofSetColor(0, 0, 0);
        ofDrawRectangle(obstacles[i].collision_box);
    }
    std::ostringstream points;
    ofSetColor(kMaxColor, kMaxColor, kMaxColor);
    points << "Points: ";
    points << game_player.getScore();
    myFont.drawString(points.str(), 50, 100);
    drawPlayerIcon();
    drawStarIcon();
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (game_state == IN_GAME) {
        game_state = IN_GAME;
        drawInGame();
    } else if (game_state == GAME_OVER) {
        drawGameOver();
    }
    drawTimerBar();
}

//--------------------------------------------------------------
void ofApp::drawPlayerIcon() {
    ofSetColor(kMaxColor, kMaxColor, kMaxColor);
    playerIcon.resize(18, 36);
    ofPushMatrix();
    ofTranslate(game_player.getPlayerPosition().x, game_player.getPlayerPosition().y);
    ofRotate(ofRadToDeg(game_player.angle));
    playerIcon.setAnchorPercent(0.5, 0.5);
    playerIcon.draw(0,0);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawStarIcon() {
    starIcon.draw(starItem.collision_box.x, starItem.collision_box.y, 15.744, 15);
}

//--------------------------------------------------------------
void ofApp::drawGameOver() {
    gameOverScreen.draw(0, 0);
    drawHighScores();
}

//--------------------------------------------------------------
void ofApp::drawHighScores() {
    std::string high_score;
    int scoreCounter = 1;
    ofSetColor(255, 255, 255);
    file.open("highScores.txt", ofFile::ReadOnly);
    std::ostringstream high_score_message;
    string loseMessage = "You Lost! Final Score: " + std::to_string(game_player.getScore()) + '\n' + '\n' + "Press R to play again!";
    high_score_message << loseMessage << '\n' << '\n' << "-------High-Scores--------" << '\n';
    while (scoreCounter <= kHighScores) {
        getline(file, high_score);
        high_score_message << scoreCounter << ". " << high_score << '\n' << '\n';
        scoreCounter++;
    }
    myFont.drawString(high_score_message.str(), 50, 125);
}

//--------------------------------------------------------------
void ofApp::getCurrentScore() {
    file.open("scores.txt", ofFile::Append);
    file << game_player.getScore() << '\n';
}

//--------------------------------------------------------------
/**
 * Takes scores from file and reads them into a vector.
 */
void ofApp::findHighScores() {
    highScores.clear();
    getCurrentScore();
    std::string score;
    int value;
    file.open("scores.txt", ofFile::ReadOnly);
    while (file.good()) {
        std::getline(file, score);
        value = atoi(score.c_str());
        highScores.push_back(value);
    }
    orderScores();
}

//--------------------------------------------------------------
/**
 * Orders the top 10 scores that have been recorded and reads them into a file.
 */
void ofApp::orderScores() {
    file.open("highScores.txt", ofFile::WriteOnly, ofFile::trunc);
    std::sort(highScores.rbegin(), highScores.rend());
    if (highScores.size() == 1) {
        file << highScores[0];
        return;
    } else if (highScores.size() <= kHighScores) {
        for (uint32_t i = 0; i < highScores.size(); i++) {
            file << highScores[i] << '\n';
        }
    } else {
        for (uint32_t i = 0; i < kHighScores; i++) {
            file << highScores[i] << '\n';
        }
    }
}

//--------------------------------------------------------------
/**
 * Checks to see if each corner of the player collision box is within the radius.
 */
bool ofApp::isInsideField() {
    if (game_field.getPosition().distance(game_player.collision_box.getTopLeft()) > game_field.getRadius()) {
        return false;
    } else if (game_field.getPosition().distance(game_player.collision_box.getTopRight()) > game_field.getRadius()) {
        return false;
    } else if (game_field.getPosition().distance(game_player.collision_box.getBottomLeft()) > game_field.getRadius()) {
        return false;
    } else if (game_field.getPosition().distance(game_player.collision_box.getBottomRight()) > game_field.getRadius()) {
        return false;
    } else {
        game_player.is_inside_field = true;
        return true;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    int upper_key = toupper(key);
    if (upper_key == 'W') {
        game_player.is_up_pressed = true;
    } else if (upper_key == 'A') {
        game_player.is_left_pressed = true;
    } else if (upper_key == 'S') {
        game_player.is_down_pressed = true;
    } else if (upper_key == 'D') {
        game_player.is_right_pressed = true;
    } else if (upper_key == 'R' && game_state == GAME_OVER) {
        findHighScores();
        reset();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    int upper_key = toupper(key);
    
    if (upper_key == 'W') {
        game_player.is_up_pressed = false;
    } else if (upper_key == 'A') {
        game_player.is_left_pressed = false;
    } else if (upper_key == 'S') {
        game_player.is_down_pressed = false;
    } else if (upper_key == 'D') {
        game_player.is_right_pressed = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}

