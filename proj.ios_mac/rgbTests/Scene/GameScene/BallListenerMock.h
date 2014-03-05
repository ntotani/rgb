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
public:
    bool called;
    float lastX;
    float lastY;
    virtual void onBallMove(float x, float y);
    virtual void onBallDelete();
};

#endif /* defined(__rgb__BallListenerMock__) */
