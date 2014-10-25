//
//  AbstEnemy.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/24.
//
//

#ifndef __simpleShootingGame__AbstEnemy__
#define __simpleShootingGame__AbstEnemy__

#include <stdio.h>
#include "AbstObj.h"

class AbstEnemy : public AbstObj{
private:
    
public:
    virtual void reactShotHit() = 0;  // 自機の弾にあたった時の反応
};


#endif /* defined(__simpleShootingGame__AbstEnemy__) */
