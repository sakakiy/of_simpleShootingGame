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
    
    /*
    cout << "FONT LOAD before\n";
    
    font.loadFont("Arial.ttf", 20, false);
    cout << "FONT LOAD after\n";
     
     */
}

void StatusViewer::addScore(int s){
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
    ofDrawBitmapString(ss.str(), scoreX, scoreY);
    // font.drawString(ss.str(), scoreX, scoreY);
    //font.drawString("HELLO.", scoreX, scoreY);

}