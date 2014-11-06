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
    for(int i=0; i<enemyNum; i++){
        enemies[i] = new SimpleEnemy(ofRandom(1.0) * ofGetWidth(), -150 - 50 * i, 40, 40);
        liveEnemyCount++;
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
