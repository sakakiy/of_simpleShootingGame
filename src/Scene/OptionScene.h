//
//  OptionScene.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/11/03.
//
//

#ifndef __simpleShootingGame__OptionScene__
#define __simpleShootingGame__OptionScene__

#include <stdio.h>
#include "Scene.h"

class OptionScene : public AbstScene{
private:
    
public:
    OptionScene(AbstScene **);
    void setup();
    void update();
    void draw();
    void changeScene();
};

#endif /* defined(__simpleShootingGame__OptionScene__) */
