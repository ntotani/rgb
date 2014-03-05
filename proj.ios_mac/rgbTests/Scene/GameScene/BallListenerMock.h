//
//  BallListenerMock.h
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#ifndef __rgb__BallListenerMock__
#define __rgb__BallListenerMock__

#include "IBallListener.h"

class BallListenerMock : public IBallListener {
    bool called;
    float lastX;
    float lastY;
public:
    virtual void onBallMove(float x, float y);
    bool isCalled();
    float getX();
    float getY();
};

#endif /* defined(__rgb__BallListenerMock__) */
