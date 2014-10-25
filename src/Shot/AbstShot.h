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
    
public:
    
    virtual void    shot(float x, float y) = 0;    // 弾丸を発射する
    virtual void    initShot() = 0;                // 弾丸を初期化する
    virtual void    checkCollisionEnemy(AbstEnemy*) = 0;
};

#endif /* defined(__simpleShootingGame__AbstShot__) */
