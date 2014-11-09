//
//  ChargeShot.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/29.
//
//

#include "ChargeShot.h"


ChargeShot::ChargeShot(){
    init();
    initShot();
}

void ChargeShot::init(){
    x   = 0;
    y   = 0;
    vx  = 0;
    vy  = 0;
    
    color = ofColor(255, 240, 240);
    
    chargingFlag    = false;
    energyMax       = 200;
    chargeLevel     = 0;        // 攻撃力
    chargeEnergy    = 0;
}

void ChargeShot::update(){
    
    if(status == s_charge){
        
        if(chargingFlag){
            if(chargeEnergy <= energyMax){
                chargeEnergy+=2;
                chargeLevel = chargeEnergy/20;
                radius      = chargeEnergy;
            }
        } else {
            status  = s_shot;
            vy      = -8;
        }
        
        chargingFlag = false;
    }
    if(status == s_shot){
        y += vy;
        
        if(y < 0){
            status  = s_ready;
            initShot();
        }
    }
    
}

void ChargeShot::draw(){
    ofSetColor(color);
    ofEllipse(x, y, radius, radius);
}

void ChargeShot::startCharge(){
    status      = s_charge;
    chargeLevel = 0;
    cout << "\ncharge started.\n";
}

void ChargeShot::shot(float x, float y){
    chargingFlag    = true;
    if(status == s_ready){
        startCharge();
    } else if(status == s_charge){
        this->x = x;
        this->y = y;
    } else if(status == s_shot){
        status == s_charge;
        initShot();
        startCharge();
    }
}

void ChargeShot::initShot(){
    status          = s_ready;
    vy              = 0;
    x               = 0;
    y               = -100;
    radius          = 0;
    
    chargeEnergy    = 0;
}

void ChargeShot::checkCollisionEnemy(AbstEnemy *enemy){
    if(status == s_shot && enemy->isHitable()){
        float diffX, diffY, sumRadius;

            diffX = x - enemy->getX();
            diffY = y - enemy->getY();
            sumRadius = radius/2 + enemy->getW()/2;
            
            // ヒットした時の処理
            if(pow(sumRadius, 2) > pow(diffX, 2) + pow(diffY, 2)){

                int enemyHitPoint = enemy->reactShotHit(chargeLevel);
                if(enemyHitPoint >= 0){
                    initShot();
                } else {
                    // オーバーキルならマイナスになっている敵の体力分減らす
                    chargeLevel = -enemyHitPoint;
                }
            }

    }
}