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
}


void GameScene::update(){
    if(ofGetKeyPressed('c')){
        *scene = new StartScene(scene);
    }
    // 衝突判定
    colMng.update();
    
    // ショットや自機の動作更新
    shot->update();
    attacker->update();
    enemyMng.update();
    
    sttViewer.update();
    
    // キーボード入力によるショット変更
    changeShot();
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
}

void GameScene::changeScene(){
    
}

