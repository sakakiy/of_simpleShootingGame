//
//  EnemyMng.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/26.
//
//

#ifndef __simpleShootingGame__EnemyMng__
#define __simpleShootingGame__EnemyMng__

#include <stdio.h>
#include "AbstEnemy.h"
#include "SimpleEnemy.h"
#include "StatusViewer.h"

#define ENEMY_NUM 27

class EnemyMng{
    
private:
    int             enemyNum;
    AbstEnemy       * enemies[ENEMY_NUM];
    int             liveEnemyCount;
    bool            flagAllDestroy;
    
    
public:
    EnemyMng();
    void            init();
    void            update();
    void            draw();
    void            setSttViewer(StatusViewer *s);
    int             getEnemyNum(){return enemyNum;}
    AbstEnemy       * getEnemy(int i){return enemies[i];}
    bool            isAllDestroy(){ return flagAllDestroy;}
    
};

#endif /* defined(__simpleShootingGame__EnemyMng__) */
