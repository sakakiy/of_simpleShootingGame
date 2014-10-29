//
//  Attacker.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/19.
//
//

#ifndef __simpleShootingGame__Attacker__
#define __simpleShootingGame__Attacker__

#include <stdio.h>
#include "AbstObj.h"
#include "AbstShot.h"

class Attacker : public AbstObj{
private:
    AbstShot* shot;
    
public:
    Attacker();
    Attacker(float x, float y, float w, float h);
    void setShot(AbstShot* s){shot = s;}
    void update();
    void draw();
};

#endif /* defined(__simpleShootingGame__Attacker__) */
