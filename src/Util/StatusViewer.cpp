//
//  StatusViewer.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/26.
//
//

#include "StatusViewer.h"

StatusViewer::StatusViewer(){
    cout << "status viewer constructor\n";
}


void StatusViewer::init(){
    currentScore    = 0;
    drawScore       = 0;
    scoreV          = 10;
    scoreX          = 10;
    scoreY          = 100;
    scoreSize       = 30;
    
    font.loadFont("verdana.ttf", 30, false);
}

void StatusViewer::addScore(int s){
    cout << "add score called.\n";
    currentScore += s;
}

void StatusViewer::update(){
    if(currentScore != drawScore){
        drawScore += scoreV;
    }
}


void StatusViewer::draw(){
    stringstream ss;
    ss << drawScore;
    ofSetColor(0, 55, 0);
    font.drawString(ss.str(), scoreX, scoreY);
}