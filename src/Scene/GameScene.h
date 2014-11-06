//
//  GameScene.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/11/03.
//
//

#ifndef __simpleShootingGame__GameScene__
#define __simpleShootingGame__GameScene__

#include <stdio.h>
#include "Scene.h"

#include "Attacker.h"
#include "AbstShot.h"
#include "SimpleShot.h"
#include "DoubleShot.h"
#include "ChargeShot.h"

#include "EnemyMng.h"
#include "AbstEnemy.h"
#include "SimpleEnemy.h"

#include "CollisionMng.h"
#include "StatusViewer.h"

class GameScene : public AbstScene{
private:
    enum Status{
        s_ready,
        s_playing,
        s_end,
        s_pause
    } status;
    Attacker*       attacker;
    AbstShot*       shot;
    EnemyMng        enemyMng;
    CollisionMng    colMng;
    StatusViewer    sttViewer;
    
    int             waitFrameCount;
    void            judgeGameStatus();
    
public:
    GameScene(AbstScene **);
    void setup();
    void update();
    void draw();
    void changeScene();
    
    void changeShot();
};

#endif /* defined(__simpleShootingGame__GameScene__) */
