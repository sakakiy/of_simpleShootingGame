//
//  AbstScene.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/11/03.
//
//

#ifndef __simpleShootingGame__AbstScene__
#define __simpleShootingGame__AbstScene__

#include <stdio.h>
#include <ofMain.h>

class AbstScene{
private:
    
public:
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void changeScene() = 0;
};

#endif /* defined(__simpleShootingGame__AbstScene__) */
