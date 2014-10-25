//
//  AbstObj.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/19.
//
//

#ifndef __simpleShootingGame__AbstObj__
#define __simpleShootingGame__AbstObj__

#include <stdio.h>
#include <ofMain.h>

class AbstObj{
protected:
    float x, y, w, h;
    float vx, vy;
    ofColor color;
    
public:
    virtual void    update() = 0; // 純粋仮想関数
    virtual void    draw() = 0;
    float           getX(){return x;}
    float           getY(){return y;}
    // float           getCenterX(){return x+w/2;}
    // float           getCenterY(){return y+h/2;}
    float           getW(){return w;}
    float           getH(){return h;}
    
};

#endif /* defined(__simpleShootingGame__AbstObj__) */
