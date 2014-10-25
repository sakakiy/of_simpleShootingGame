//
//  SimpleEnemy.cpp
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/21.
//
//

#include "SimpleEnemy.h"

SimpleEnemy::SimpleEnemy(){
    x       = 100;
    y       = 100;
    w       = 50;
    h       = 50;
    
    init();
}

SimpleEnemy::SimpleEnemy(float _x, float _y, float _w, float _h){
    x       = _x;
    y       = _y;
    w       = _w;
    h       = _h;
    
    init();
}

void SimpleEnemy::init(){
    // 生存ステータス
    status  = e_live;
    
    hitNum  = 0;
    color   = ofColor(255, 200, 170);
}

void SimpleEnemy::update(){
    
}

void SimpleEnemy::draw(){
    
    // 生存ステータスなら描画
    if(status == e_live){
        ofSetColor(color);
        ofRect(x - w/2, y - h/2, w, h);
    } else if(status == e_dying) {
        color   = ofColor(255, 255, 70);
        ofSetColor(color);
        ofRect(x - w/2, y - h/2, w, h);
    }
}

void SimpleEnemy::reactShotHit(){
    hitNum++;
    w++;
    cout << "HIT !! : " << hitNum << "\n";
    if(hitNum == 2){
        status = e_dying;
    } else if(3 <= hitNum) {
        dead();
    }
}

// 死亡処理
void SimpleEnemy::dead(){
    status  = e_dead;
    x       = -100;
    y       = -100;
    init();
}