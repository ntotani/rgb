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
    float wid;
    float hei;
    float dx;
    float dy;
    std::vector<IBallListener*> listeners;
public:
    BallModel(BallColor color, float x, float y, float wid, float hei, float dx, float dy);
    BallColor getColor();
    float getX();
    float getY();
    float getWid();
    float getHei();
    float getDx();
    float getDy();
    void addListener(IBallListener* listener);
    void update(float tick);
    void deleteFromField();
    bool intersect(float x, float y);
};

#endif /* defined(__rgb__BallModel__) */
