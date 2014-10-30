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
    chargeLevel     = 0;
}

void ChargeShot::update(){
    
    if(status == s_charge){
        
        if(chargingFlag){
            if(chargeEnergy <= energyMax){
                chargeEnergy++;
                chargeLevel = chargeEnergy/30;
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
}

void ChargeShot::shot(float x, float y){
    chargingFlag    = true;
    if(status == s_charge){
        this->x = x;
        this->y = y;
    }else if(status == s_ready){
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
    if(enemy->isHitable()){
        float diffX, diffY, sumRadius;

            diffX = x - enemy->getX();
            diffY = y - enemy->getY();
            sumRadius = radius/2 + enemy->getW()/2;
            
            // ヒットした時の処理
            if(pow(sumRadius, 2) > pow(diffX, 2) + pow(diffY, 2)){

                // TODO
                // たくさん溜めたら貫通させる。
                // initShot() ではなく、enemy の体力を取得して chargeShot の威力から引く。
                // update で chargeShot の威力を監視して、0 以下になったら initShot();する
                initShot();
                enemy->reactShotHit(chargeLevel);
            }

    }
}