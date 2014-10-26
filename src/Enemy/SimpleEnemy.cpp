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
    status      = e_live;
    
    hitNum      = 0;
    color       = ofColor(255, 200, 170);
    colorAlfa   = 255;
}

void SimpleEnemy::update(){
    if(status == e_dying){
        dying();
    }
}

void SimpleEnemy::draw(){
    
    // 生存ステータスなら描画
    if(status == e_live){
        ofSetColor(color);
        ofRect(x - w/2, y - h/2, w, h);
    } else if(status == e_dying) {
        // color   = ofColor(255, 255, 70);
        ofSetColor(color);
        ofRect(x - w/2, y - h/2, w, h);
    }
}

void SimpleEnemy::reactShotHit(){
    hitNum++;
    
    cout << "HIT !! : " << hitNum << "\n";
    if(2 < hitNum){
        status = e_dying;
    }

}

void SimpleEnemy::dying(){
    w -= 1;
    h -= 1;
    
    colorAlfa-=15;
    if( colorAlfa < 0){
        colorAlfa = 0;
    }
    color = ofColor(255, 255, 70, colorAlfa);
    
    if(w < 0){
        w = 0;
    }
    if(h < 0){
        h = 0;
    }
    
    if(colorAlfa == 0){
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

// 当たり判定をするかどうか
bool SimpleEnemy::isHitable(){
    // live なら当たり判定を行える
    if(status == e_live){
        return true;
    } else {
        return false;
    }

}