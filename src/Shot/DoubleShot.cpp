//
//  DoubleShot.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/21.
//
//

#include "DoubleShot.h"

DoubleShot::DoubleShot(){
    bulletIndex     = 0;
    shotInterval    = 10; // このフレーム数間を開ける
    shotTime        = 0;
}

void DoubleShot::update(){
    for(int i=0; i<bulletMaxNum; i++){
        bullet[i].update();
    }
}

void DoubleShot::draw(){
    for(int i=0; i<bulletMaxNum; i++){
        bullet[i].draw();
    }
}

void DoubleShot::shot(float _x, float _y){
    if(ofGetFrameNum() - shotTime > shotInterval){
        // 弾が撃てる状態なら撃つ
        // 2つの弾を並行に撃つ
        if(bullet[bulletIndex].shot(_x + 10, _y)){
            bulletIndex = (bulletIndex + 1) % bulletMaxNum;
            bullet[bulletIndex].shot(_x - 10, _y);
            bulletIndex = (bulletIndex + 1) % bulletMaxNum;
            shotTime = ofGetFrameNum();
        }
    }
}

void DoubleShot::initShot(){
    for(int i=0; i<bulletMaxNum; i++){
        bullet[i].initShot();
    }
}

// 敵とのヒット判定
void DoubleShot::checkCollisionEnemy(AbstEnemy * enemy){
    if(enemy->isHitable()) {
        float diffX, diffY, sumRadius;
        for(int i=0; i<bulletMaxNum; i++){
            diffX = bullet[i].getX() - enemy->getX();
            diffY = bullet[i].getY() - enemy->getY();
            sumRadius = bullet[i].getW()/2 + enemy->getW()/2;
            
            if(pow(sumRadius, 2) > pow(diffX, 2) + pow(diffY, 2)){
                bullet[i].initShot();
                enemy->reactShotHit();
                cout << "DOUBLE HIT : " << i << "\n";
            }
        }
    }
}