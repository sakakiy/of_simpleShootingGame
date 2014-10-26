//
//  EnemyMng.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/26.
//
//

#include "EnemyMng.h"

EnemyMng::EnemyMng(){
    enemyNum = 0;
    enemyMax = 10;
}

void EnemyMng::update(){
    for(int i=0; i<enemyNum; i++){
        enemies[i]->update();
    }
}


void EnemyMng::draw(){
    for(int i=0; i<enemyNum; i++){
        enemies[i]->draw();
    }

}


bool EnemyMng::addEnemy(AbstEnemy* en){
    if(enemyMax <= enemyNum){
        return false;
    }
    
    enemies[enemyNum] = en;
    enemyNum++;
    
    return true;
}