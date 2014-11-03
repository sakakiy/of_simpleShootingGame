//
//  OptionScene.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/11/03.
//
//

#include "OptionScene.h"

OptionScene::OptionScene(AbstScene **s){
    scene = s;
    setup();
}

void OptionScene::setup(){
    
}


void OptionScene::update(){
    if(ofGetKeyPressed('c')){
        changeScene();
    }
}


void OptionScene::draw(){
    ofSetColor(70, 160, 100);
    ofRect(30, 30, ofGetWindowWidth() - 60, ofGetWindowHeight() - 60);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("OptionScene\n[c] -> return.", ofGetWindowWidth()/2, ofGetWindowHeight()/2);
}

void OptionScene::changeScene(){
    *scene = new StartScene(scene);
}
