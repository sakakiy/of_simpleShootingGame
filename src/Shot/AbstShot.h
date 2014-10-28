//
//  AbstShot.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/20.
//
//

#ifndef __simpleShootingGame__AbstShot__
#define __simpleShootingGame__AbstShot__

#include <stdio.h>
#include "AbstObj.h"
#include "AbstEnemy.h"

class AbstShot : public AbstObj{
    
protected:
    int             damage;                         // ショットのダメージ
public:
    
    virtual void    shot(float x, float y) = 0;     // ショットを発射する
    virtual void    initShot() = 0;                 // ショットを初期化する
    virtual void    checkCollisionEnemy(AbstEnemy*) = 0;
};

#endif /* defined(__simpleShootingGame__AbstShot__) */
