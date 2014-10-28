//
//  EnemyMng.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/26.
//
//

#include "EnemyMng.h"

EnemyMng::EnemyMng(){
    enemyNum = 5;
   
}

void EnemyMng::init(){
    for(int i=0; i<enemyNum; i++){
        enemies[i] = new SimpleEnemy(ofRandom(1.0) * ofGetWidth(), 100 + ofRandom(1.0) * 50, 30, 30);
    }
}

void EnemyMng::setSttViewer(StatusViewer *s){
    for(int i=0; i<enemyNum; i++){
        enemies[i]->setSttViewer(s);
    }
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

/*
 bool EnemyMng::addEnemy(AbstEnemy* en){
 if(enemyMax <= enemyNum){
 return false;
 }
 
 enemies[enemyNum] = en;
 enemyNum++;
 
 return true;
 }
 */