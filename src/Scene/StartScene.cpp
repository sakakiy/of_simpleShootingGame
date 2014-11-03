//
//  StartScene.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/11/03.
//
//

#include "StartScene.h"

StartScene::StartScene(AbstScene ** s){
    scene = s;
    
    setup();
}

void StartScene::setup(){
    
}


void StartScene::update(){
    if(ofGetKeyPressed('g')){
        *scene = new GameScene(scene);
    } else if(ofGetKeyPressed('o')){
        *scene = new OptionScene(scene);
    }
}


void StartScene::draw(){
    ofSetColor(200, 100, 100);
    ofRect(30, 30, ofGetWindowWidth() - 60, ofGetWindowHeight() - 60);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("StartScene\n[g] -> game start.\n[o] -> option.", ofGetWindowWidth()/2, ofGetWindowHeight()/2);
}

void StartScene::changeScene(){

}

