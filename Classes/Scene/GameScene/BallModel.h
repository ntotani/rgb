//
//  BallModel.h
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#ifndef __rgb__BallModel__
#define __rgb__BallModel__

#include <vector>
#include "IBallListener.h"

enum BallColor {
    RED, GREEN, BLUE,
};

class BallModel {
    BallColor color;
    float x;
    float y;
    float dx;
    float dy;
    std::vector<IBallListener*> listeners;
public:
    BallModel(BallColor color, float x, float y, float dx, float dy);
    BallColor getColor();
    float getX();
    float getY();
    float getDx();
    float getDy();
    void addListener(IBallListener* listener);
    void update(float tick);
};

#endif /* defined(__rgb__BallModel__) */
