//
//  SimpleEnemy.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/21.
//
//

#include "SimpleEnemy.h"

SimpleEnemy::SimpleEnemy(){
    x       = 100;
    y       = 100;
    w       = 50;
    h       = 50;
    
    hitNum  = 0;
    color   = ofColor(255, 200, 170);
}

SimpleEnemy::SimpleEnemy(float _x, float _y, float _w, float _h){
    x       = _x;
    y       = _y;
    w       = _w;
    h       = _h;
    
    hitNum  = 0;
    color   = ofColor(255, 200, 170);
}

void SimpleEnemy::update(){
    
}

void SimpleEnemy::draw(){
    ofSetColor(color);
    ofRect(x - w/2, y - h/2, w, h);
}

void SimpleEnemy::reactShotHit(){
    hitNum++;
    w++;
    cout << "HIT !! : " << hitNum << "\n";
}