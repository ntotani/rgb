//
//  IFieldListener.h
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#ifndef rgb_IFieldListener_h
#define rgb_IFieldListener_h

#include "BallModel.h"

class IFieldListener {
public:
    virtual void onBallCreate(BallModel* ball) = 0;
    virtual void onRestTimeUpdate(float percent) = 0;
    virtual void onScore(int score) = 0;
};

#endif
