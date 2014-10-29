//
//  SimpleBullet.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/21.
//
//

#include "SimpleBullet.h"

SimpleBullet::SimpleBullet(){
    x       = -100;
    y       = -100;
    w       = 10;
    h       = 10;
    
    init();
}

SimpleBullet::SimpleBullet(float _x, float _y, float _w, float _h){
    x       = _x;
    y       = _y;
    w       = _w;
    h       = _h;
    
    init();
}

// クラス内の初期化処理
void SimpleBullet::init(){
    vx          = 0;
    vy          = 0;
    shotVy      = -20;
    
    shotable    = true;
    color       = ofColor(244, 244, 100);
}

void SimpleBullet::update(){
    x += vx;
    y += vy;
    
    // フレームアウトしたら初期位置に戻す
    if(vx != 0 || vy != 0){
        if(y < -30){
            initShot();
        }
    }
}

void SimpleBullet::draw(){
    ofSetColor(color);
    ofRect(x, y, w, h);
}

// ショットが撃てる状態なら撃つ
bool SimpleBullet::shot(float _x, float _y){
    if(shotable){
        x   = _x - w/2;
        y   = _y;
        vy  = shotVy;
        shotable = false;
        return true;
        // cout << "BULLET : " << vy << "\n";
    } else {
        return false;
    }
}

// ショットを撃てる状態に初期化する
void SimpleBullet::initShot(){
    x           = -100;
    y           = -100;
    vx          = 0;
    vy          = 0;
    shotable    = true;
}