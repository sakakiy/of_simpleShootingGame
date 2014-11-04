//
//  GameScene.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/11/03.
//
//

#include "GameScene.h"

GameScene::GameScene(AbstScene **s){
    scene = s;
    
    setup();
}

void GameScene::setup(){
    attacker    = new Attacker(ofGetWidth()/2, 900, 20, 20);
    shot        = new SimpleShot();
    
    attacker->setShot(shot);
    
    enemyMng.init();
    
    colMng = CollisionMng();
    colMng.setAttacker(attacker);
    colMng.setShot(shot);
    colMng.setEnemyMng(&enemyMng);
    
    sttViewer.init();
    
    enemyMng.setSttViewer(&sttViewer);
    
    // ゲームの状態を準備状態に変更
    status = s_ready;
    waitFrameCount  = ofGetFrameNum();
}


void GameScene::update(){
    if(ofGetKeyPressed('c')){
        *scene = new StartScene(scene);
    }
    
    if(status == s_ready){
        if(ofGetFrameNum() - waitFrameCount > 120){
            status = s_playing;
        }
    }else if(status == s_playing){
        // 衝突判定
        colMng.update();
        
        // ショットや自機の動作更新
        shot->update();
        attacker->update();
        enemyMng.update();
        
        sttViewer.update();
        
        // キーボード入力によるショット変更
        changeShot();
        if(ofGetKeyPressed('n')){
            status = s_end;
        }
    } else if(status == s_end){
        if(ofGetKeyPressed('p')){
            *scene = new StartScene(scene);
        }
    }
}


void GameScene::changeShot(){
    if(ofGetKeyPressed('s')){
        shot = new SimpleShot();
        attacker->setShot(shot);
        colMng.setShot(shot);
        // cout << "CHANGE : SIMPLE SHOT\n";
    } else if(ofGetKeyPressed('d')){
        shot = new DoubleShot();
        attacker->setShot(shot);
        colMng.setShot(shot);
        // cout << "CHANGE : DOUBLE SHOT\n";
    }
}

void GameScene::draw(){
    shot->draw();
    attacker->draw();
    enemyMng.draw();
    sttViewer.draw();
    

    if(status == s_ready){
        ofSetColor(120, 130, 255, 100);
        ofRect(30, 30, ofGetWindowWidth() - 60, ofGetWindowHeight() - 60);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Ready?", ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    } else if(status == s_end){
        ofSetColor(120, 130, 255, 100);
        ofRect(30, 30, ofGetWindowWidth() - 60, ofGetWindowHeight() - 60);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("end..", ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    }
}

void GameScene::changeScene(){
    
}

