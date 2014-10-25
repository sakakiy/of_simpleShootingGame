//
//  Attacker.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/19.
//
//

#include "Attacker.h"

Attacker::Attacker(float _x, float _y, float _w, float _h){
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    color = ofColor(200, 255, 200);
    
    vx = 5;
    vy = 5;
}

void Attacker::update(){
    // LEFT
    if(ofGetKeyPressed(356)){
        x -= vx;
    }
    // UP
    if(ofGetKeyPressed(357)){
        y -= vy;
    }
    // RIGHT
    if(ofGetKeyPressed(358)){
        x += vx;
    }
    // DOWN
    if(ofGetKeyPressed(359)){
        y += vy;
    }
    
    
    // ショットを撃ちだす
    if(ofGetKeyPressed(' ')){
        shot->shot(x, y);
    }
}

void Attacker::draw(){
    ofSetColor(color);
    ofRect(x - w/2, y - h/2, w, h);
}

