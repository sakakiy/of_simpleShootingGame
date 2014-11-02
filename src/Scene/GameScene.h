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
#include "AbstScene.h"

class GameScene : public AbstScene{
private:
    
public:
    void setup();
    void update();
    void draw();
    void changeScene();
};

#endif /* defined(__simpleShootingGame__GameScene__) */
