//
//  CollisionMng.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/22.
//
//

#include "CollisionMng.h"

CollisionMng::CollisionMng(){

}

void CollisionMng::update(){
    checkShotEnemy();
    checkAttackerEnemy();
}

void CollisionMng::checkShotEnemy(){
    /*
    if(shot != NULL && enemy != NULL){
        shot->checkCollisionEnemy(enemy);
    }
     */
    
    if(shot != NULL && enemyMng != NULL){
        int num = enemyMng->getEnemyNum();
        for(int i=0; i<num; i++){
            shot->checkCollisionEnemy(enemyMng->getEnemy(i));
        }
    }
}

void CollisionMng::checkAttackerEnemy(){
    
}


void CollisionMng::setAttacker(Attacker * atc){
    attacker = atc;
}

void CollisionMng::setShot(AbstShot * s){
    shot = s;
}

void CollisionMng::setEnemyMng(EnemyMng * e){
    enemyMng = e;
}

/*
void CollisionMng::setEnemy(SimpleEnemy * e){
    enemy = e;
}
 */
