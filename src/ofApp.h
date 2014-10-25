#pragma once

#include "ofMain.h"

#include "Attacker.h"
#include "AbstShot.h"
#include "SimpleShot.h"
#include "DoubleShot.h"
#include "AbstEnemy.h"
#include "SimpleEnemy.h"

#include "CollisionMng.h"

class ofApp : public ofBaseApp{
    
private:
    Attacker* attacker;
    AbstShot* shot;
    SimpleEnemy* enemy;
    CollisionMng colMng;
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // self function
    void changeShot();
    
};
