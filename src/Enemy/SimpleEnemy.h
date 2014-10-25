//
//  SimpleEnemy.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/21.
//
//

#ifndef __simpleShootingGame__SimpleEnemy__
#define __simpleShootingGame__SimpleEnemy__

#include <stdio.h>
#include "AbstEnemy.h"

class SimpleEnemy : public AbstEnemy{
private:
    // values
    int hitNum;             // 弾のヒット数
    // funcitons
    void init();
    
public:
    SimpleEnemy();
    SimpleEnemy(float _x, float _y, float _w, float _h);
    void update();
    void draw();
    void reactShotHit();    // 自弾がヒットした時のリアクション
    void dead();            // 体力がなくなって死ぬときの処理
};

#endif /* defined(__simpleShootingGame__SimpleEnemy__) */
