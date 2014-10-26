//
//  DoubleShot.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/21.
//
//

#ifndef __simpleShootingGame__DoubleShot__
#define __simpleShootingGame__DoubleShot__

#include <stdio.h>
#include "AbstShot.h"
#include "SimpleBullet.h"

class DoubleShot : public AbstShot{
private:
    static const int bulletMaxNum = 10;   // 弾丸の最大数
    SimpleBullet bullet[bulletMaxNum];
    int bulletIndex;        // 射出する弾丸の番号
    int shotInterval;       // 射出のインターバル（F 数）
    int shotTime;           // 射出したフレーム
    
public:
    DoubleShot();
    void update();
    void draw();
    void shot(float _x, float _y);
    void initShot();
    void checkCollisionEnemy(AbstEnemy* );    // 敵とのヒット判定

};

#endif /* defined(__simpleShootingGame__DoubleShot__) */
