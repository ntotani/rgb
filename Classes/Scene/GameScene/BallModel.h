//
//  BallModel.h
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#ifndef __rgb__BallModel__
#define __rgb__BallModel__

enum BallColor {
    RED, GREEN, BLUE,
};

class BallModel {
    BallColor color;
    float x;
    float y;
    float dx;
    float dy;
public:
    BallModel(BallColor color, float x, float y, float dx, float dy);
    BallColor getColor();
    float getX();
    float getY();
    float getDx();
    float getDy();
    void update();
};

#endif /* defined(__rgb__BallModel__) */
