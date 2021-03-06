//
//  SimpleShot.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/20.
//
//

#ifndef __simpleShootingGame__SimpleShot__
#define __simpleShootingGame__SimpleShot__

#include <stdio.h>
#include "AbstShot.h"
#include "SimpleBullet.h"
#include "AbstEnemy.h"

class SimpleShot : public AbstShot{
private:
    static const int bulletMaxNum = 20;   // 弾丸の最大数
    SimpleBullet    bullet[bulletMaxNum];
    int             bulletIndex;        // 射出する弾丸の番号
    int             shotInterval;       // 射出のインターバル（F数）
    int             shotTime;           // 射出したフレーム
    
public:
    SimpleShot();
    void            update();
    void            draw();
    void            shot(float _x, float _y);
    void            initShot();
    void            checkCollisionEnemy(AbstEnemy* );    // 敵とのヒット判定
};

#endif /* defined(__simpleShootingGame__SimpleShot__) */
