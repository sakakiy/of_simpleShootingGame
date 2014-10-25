//
//  SimpleBullet.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/21.
//
//

#ifndef __simpleShootingGame__SimpleBullet__
#define __simpleShootingGame__SimpleBullet__

#include <stdio.h>
#include "AbstObj.h"

class SimpleBullet : public AbstObj{
private:
    // value
    bool    shotable;
    int     shotVy;
    
    // function
    void    init();

    
protected:
    
public:
    SimpleBullet();
    SimpleBullet(float x, float y, float w, float h);
    void    update();
    void    draw();
    bool    shot(float x, float y);
    void    initShot();
    bool    isShotable(){return shotable;}
};

#endif /* defined(__simpleShootingGame__SimpleBullet__) */
