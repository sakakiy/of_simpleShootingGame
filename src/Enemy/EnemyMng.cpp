//
//  EnemyMng.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/26.
//
//

#include "EnemyMng.h"

EnemyMng::EnemyMng(){
    enemyNum = ENEMY_NUM;
    flagAllDestroy  = false;
}

void EnemyMng::init(){
    liveEnemyCount = enemyNum;
    
    float enemyX        = 0;
    float size          = 40;
    float windowWidth   = ofGetWindowWidth();
    
    for(int i=0; i<enemyNum; i++){
        if(i % 3 == 0) enemyX = ofRandom(0.1, 0.9) * windowWidth;

        enemies[i] = new SimpleEnemy(enemyX, -150 - (size + 20) * i, size, size);
        enemies[i]->setSpeed(0, 3);
    }

}

void EnemyMng::setSttViewer(StatusViewer *s){
    for(int i=0; i<enemyNum; i++){
        enemies[i]->setSttViewer(s);
    }
}

void EnemyMng::update(){
    int tmpCount = liveEnemyCount;
    for(int i=0; i<enemyNum; i++){
        enemies[i]->update();
        if(!enemies[i]->isHitable()){
            tmpCount--;
        }
    }
    if(tmpCount <= 0){
        flagAllDestroy = true;
    }
}


void EnemyMng::draw(){
    for(int i=0; i<enemyNum; i++){
        enemies[i]->draw();
    }
    
}
