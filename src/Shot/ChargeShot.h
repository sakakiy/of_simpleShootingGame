//
//  ChargeShot.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/29.
//
//

#ifndef __simpleShootingGame__ChargeShot__
#define __simpleShootingGame__ChargeShot__

#include <stdio.h>
#include "AbstShot.h"

class ChargeShot : public AbstShot{
    
private:
    enum Status{
        s_ready,
        s_charge,
        s_shot,
    };
    
    Status  status;
    int     chargeEnergy;
    int     energyMax;
    int     chargeLevel;
    
    float   x, y, vx, vy;
    float   radius;
    ofColor color;
    
    bool    chargingFlag;
    
public:
    
    ChargeShot();
    
    void    init();
    void    update();
    void    draw();
    
    void    startCharge();
    void    shot(float, float);
    void    initShot();
    void    checkCollisionEnemy(AbstEnemy *);
    
};

#endif /* defined(__simpleShootingGame__ChargeShot__) */
