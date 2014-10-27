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
#include "StatusViewer.h"

enum E_Status{
    e_live,
    e_dying,
    e_dead
};

class AbstEnemy : public AbstObj{
private:
    
protected:
    enum E_Status   status;             // 敵の状態
    int             score;              // 敵を倒した時に自機に入るスコア
    StatusViewer    * sttViewer;
   
public:
    virtual void    reactShotHit() = 0; // 自機の弾にあたった時の反応
    virtual void    dead() = 0;         // 死亡処理
    virtual bool    isHitable() = 0;    // 当たり判定処理をする状態かどうか
    void            setSttViewer(StatusViewer *s){sttViewer = s;};
    
};


#endif /* defined(__simpleShootingGame__AbstEnemy__) */
