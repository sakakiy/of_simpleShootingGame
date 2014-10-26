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

class EnemyMng{
    
private:
    int         enemyNum;
    int         enemyMax;
    AbstEnemy*  enemies[10];
    
public :
    EnemyMng();
    bool        addEnemy(AbstEnemy* );
    void        update();
    void        draw();
    int         getEnemyNum(){return enemyNum;}
    AbstEnemy   * getEnemy(int i){return enemies[i];}
    
};

#endif /* defined(__simpleShootingGame__EnemyMng__) */
