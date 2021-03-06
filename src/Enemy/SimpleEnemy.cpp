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
    
    vx          = 0;        // 敵の速度
    vy          = 2;        // 敵の速度
    
    status      = e_live;   // 生存ステータス
    
    hitPoint    = 2;        // 敵の体力
    score       = 250;      // 敵を倒した時に取得するスコア
    
    color       = ofColor(255, 200, 170);
    colorAlfa   = 255;

    hitFrame    = 0;        // 毎フレーム被弾しないように、あたった時のフレームを記憶しておく
    reactFrame  = 3;        // ショットがあたって色が変わっているフレーム
}

void SimpleEnemy::update(){
    if(status == e_dying){
        dying();
    }
    
    y+=vy;
    
    // ショットにあたった時の色の変化と元に戻る
    if(hitFrame != 0 && ofGetFrameNum() - hitFrame > reactFrame){
        hitFrame    = 0;
        color       = ofColor(255, 200, 170);
    }
}

void SimpleEnemy::draw(){
    
    // dead ステータス以外なら描画
    if(status != e_dead){
        ofSetColor(color);
        ofRect(x - w/2, y - h/2, w, h);
    }
}

int SimpleEnemy::reactShotHit(int damage){
    hitPoint-=damage;                       // ダメージを受ける
    hitFrame    = ofGetFrameNum();          // ヒットしたフレーム記憶
    color       = ofColor(255, 255, 70);    // ヒット中の色
    y-=5;       // ノックバック
    
    // cout << "HIT !! : " << hitNum << "\n";
    status = e_dying;
    sttViewer->addScore(score);
    
    // ヒットポイントを返す
    return hitPoint;
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
    x       = 100;
    y       = -100;
    // init();
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