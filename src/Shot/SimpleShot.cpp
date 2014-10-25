//
//  SimpleShot.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/20.
//
//

#include "SimpleShot.h"

SimpleShot::SimpleShot(){
    bulletIndex     = 0;
    shotInterval    = 5; // このフレーム数間を開ける
    shotTime        = 0;
}

void SimpleShot::update(){
    for(int i=0; i<bulletMaxNum; i++){
        bullet[i].update();
    }
}

void SimpleShot::draw(){
    for(int i=0; i<bulletMaxNum; i++){
        bullet[i].draw();
    }
}

void SimpleShot::shot(float _x, float _y){
    if(ofGetFrameNum() - shotTime > shotInterval){
        // 弾が撃てる状態なら撃つ
        if(bullet[bulletIndex].shot(_x, _y)){
        bulletIndex = (bulletIndex + 1) % bulletMaxNum;
        shotTime = ofGetFrameNum();
        }
    }
}

void SimpleShot::initShot(){
    for(int i=0; i<bulletMaxNum; i++){
        bullet[i].initShot();
    }
}

// 敵とのヒット判定
void SimpleShot::checkCollisionEnemy(AbstEnemy * enemy){
    float diffX, diffY, sumRadius;
    for(int i=0; i<bulletMaxNum; i++){
        diffX = bullet[i].getX() - enemy->getX();
        diffY = bullet[i].getY() - enemy->getY();
        sumRadius = bullet[i].getW()/2 + enemy->getW()/2;
        
        // ヒットした時の処理
        if(pow(sumRadius, 2) > pow(diffX, 2) + pow(diffY, 2)){
            bullet[i].initShot();
            enemy->reactShotHit();
            cout << "SIMPLE HIT : " << i << "\n";
        }
    }
}