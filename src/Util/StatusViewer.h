//
//  StatusViewer.h
//  simpleShootingGame
//
//  Created by 榊原吉伸 on 2014/10/26.
//
//

#ifndef __simpleShootingGame__StatusViewer__
#define __simpleShootingGame__StatusViewer__

#include <stdio.h>
#include "ofMain.h"

class StatusViewer{
private:
    int             currentScore, drawScore;
    float           scoreX, scoreY, scoreSize, scoreV;
    ofTrueTypeFont  font; // 文字表示のためのフォントインスタンス
    
public:
    StatusViewer();
    void            addScore(int);
    void            init();
    void            update();
    void            draw();
};

#endif /* defined(__simpleShootingGame__StatusViewer__) */
