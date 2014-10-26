//
//  CollisionMng.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/22.
//
//

#ifndef __simpleShootingGame__CollisionMng__
#define __simpleShootingGame__CollisionMng__

#include <stdio.h>
#include "ofMain.h"
#include "Attacker.h"
#include "AbstShot.h"
#include "EnemyMng.h"
#include "SimpleEnemy.h"


class CollisionMng{
private:
    Attacker        * attacker;
    AbstShot        * shot;
    // SimpleEnemy*    enemy;
    EnemyMng        * enemyMng;
    
public:
    CollisionMng();
    void update();
    void checkAttackerEnemy();  // 自機と敵の衝突判定
    void checkShotEnemy();      // 自弾と敵の衝突判定
    void setAttacker(Attacker*);
    void setShot(AbstShot*);
    // void setEnemy(SimpleEnemy*);
    void setEnemyMng(EnemyMng*);

};

#endif /* defined(__simpleShootingGame__CollisionMng__) */
